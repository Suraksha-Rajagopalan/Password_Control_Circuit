
#include <LiquidCrystal.h> //Contains the functions required to control lcd display
#include <Keypad.h> //Contains the functions required to control the keypad
#include <EEPROM.h> //EEPROM is a memory whose values are kept when the board is powered off
#define Length 5

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //Here the variable name are the pins of the lcd display, while their assigned values are the connected pins in arduino board.
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

const byte ROWS = 4; //Provides the number of rows in Keypad
const byte COLS = 4;  //Provides the number of columns in Keypad
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {A1, A2, A3, A4}; 

char Data[Length]; 
char Data2[Length];
char Master[Length];
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char key;
byte key_state = 0;
char last_press_key;
byte mode = 0;

int change_password_allow_time = 10000;
long time_old = 0;
bool just_allowed_pass =0;

char FistTimePassword[] = {'2','4','0','4'}; // setup first-time password here


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Check_EEPROM();

  lcd.begin(16, 2);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
}
  
void loop()
{
  key = keypad.getKey(); 
  
  key_state = keypad.getState(); //Provides the sate of the Key. The four states are IDLE, PRESSED, RELEASED and HOLD.

  if(key){
    last_press_key = key; //The current state of the key
    Serial.println(key);
  }

if( mode == 3){
    if(last_press_key == '#' && key_state == 2){   //If after the key # is pressed, it is pressed again for long time, then the mode shits to 1
      mode = 1;  //When the mode is 1, then we can set new password
    }
    if(last_press_key == '*' && key_state == 2){  //If after the key * is pressed, it is pressed again for long time, then the mode shits to 2
      mode = 0;  //When the mode is 0, the system gets locked and we have to enter the password
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("LOCKED");
    digitalWrite(13, LOW); 
    delay(2000);          
    }        
}

  if(mode == 0){
    lcd.setCursor(1,0);
    lcd.print("Enter Password");
  }else if(mode == 1){
    lcd.setCursor(0,0);
    lcd.print("Set New Password");    
  }else if(mode == 2){
    lcd.setCursor(0,0);
    lcd.print("Password Again");      
  }else if(mode == 3){
    lcd.setCursor(4,0);
    lcd.print("UNLOCKED");         
  }


  if (key && key != '#' && mode != 3) //If we want to change the password without unlocking, the system.
  {
    collectKey();
  }

  if(data_count == Length-1) 
  {
    if(mode == 0){
      lcd.clear();
      if(!strcmp(Data, Master)) {
        lcd.setCursor(2, 0);
        lcd.print("WELCOME BACK");
        lcd.setCursor(4, 1);
        lcd.print("TONY!!");
        
        just_allowed_pass = 1;
        time_old = millis();
  
        digitalWrite(13, HIGH);
        
        delay(2000);
        mode = 3;
      }else{
        lcd.setCursor(2, 0);
        lcd.print("INCORRECT !");
        lcd.setCursor(4, 1);
        lcd.print("PASSWORD");
        delay(2000);
      }
      delay(1000);
      lcd.clear();
      clearData(); 
    }else if( mode == 1){
      lcd.clear();
      mode = 2;
      for(int i = 0; i < Length; i = i+1){
      Data2[i] = Data[i];
     }
      clearData(); 
    }else if(mode == 2){  //Settting new password and saving it
      if(!strcmp(Data, Data2)){
        lcd.clear();
        lcd.setCursor(0, 0); 
        lcd.print("New Password is ");  
        lcd.setCursor(4, 1);   
        lcd.print(Data);  
        delay(2000);
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Saving...");
        for(int i =0; i <= 100; i =  i+10){
          lcd.setCursor(4, 1);
          lcd.print(i);
          lcd.setCursor(7, 1);
          lcd.print("%");
          delay(200);
        }
        EEPROM.put(0, Data);
        EEPROM.get(0, Master);
        delay(500);
      }else{
        lcd.clear();
        lcd.setCursor(4, 0); 
        lcd.print("PASSWORD");  
        lcd.setCursor(3, 1);   
        lcd.print("NOT MATCH!");  
        delay(2000);        
      }
      mode = 3;
      clearData();
      lcd.clear();
    }
  }
}

void collectKey(){
  Data[data_count] = key; 
  lcd.setCursor(4+data_count,1); 
  lcd.print("*"); 
  data_count++;   
}

void clearData()
{
  while(data_count !=0)
  {  
    Data[data_count--] = 0; 
  }
}


void Check_EEPROM(){
  EEPROM.get(0, Master);
  if(Master[0] == 0 && Master[1] == 0 && Master[2] == 0 && Master[3] == 0){ // check if EEPROM have store password ?
    Serial.println("No EEPROM PASSWORD FOUND"); // if not found will burn EEPROM a first time password
    EEPROM.put(0, FistTimePassword);
    EEPROM.get(0, Master);
  }
}
