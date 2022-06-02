#  🛠️ Password_Control_Circuit

<h3>  🔐 Introduction: </h3>
     We have made a password protected lock which asks the user to enter the password, When the users enters the right password, a welcome 
     message is displayed in the screen. If the user enters the wrong password, the lcd displays shows incorrect password.
     If the user wants to change their password, the provision is given only if the right password was entered in the first case.
     
<h3>  🧰 Materials Required </h3>
<body>
     <p>1. <a href="https://www.arduino.cc/" target="_main">Arduino</a></p>   
     <p>2. <a href="https://www.arduino.cc/en/Tutorial/HelloWorld" target="_main">LCD Display</a></p>
     <p>3. <a href="https://support.arduino.cc/hc/en-us/articles/360018922259-What-power-supply-can-I-use-with-my-Arduino-board-" target="_main">Power Supply</a></p>
     <p>4. <a href="https://forum.arduino.cc/index.php?topic=429737.0" target="_main">SPDT (Single Pole Double Throw)</a></p>
     <p>5. <a href="https://forum.arduino.cc/t/when-to-use-resistors-in-a-circuit/660075" target="_main">Resistors</a></p>
     <p>6. <a href="https://tinkercad.zendesk.com/hc/en-us/community/posts/115008013127-Customing-the-light-bulb" target="_main">Light Bulb</a></p>
     <p>7. <a href="https://www.tinkercad.com/things/8iDg0ZuguN8-using-keypad-4x4-with-arduino" target="_main">KeyPad</a></p>
     <p>8. <a href="https://www.tinkercad.com/things/ikgqVfX8j09" target="_main">BJT (npn transistor)</a></p>
     <p>9. <a href="https://forum.arduino.cc/t/how-to-use-a-diode/288804" target="_main">Diode</a></p>
</body>
 
<h3>  ⚡Circuit In Tinkercad </h3>
   
   Click on the Circuit Diagram to view the circuit diagram, made in tinkercad <a href="https://user-images.githubusercontent.com/91787553/170931945-0f2925f6-7e17-42e3-ae71-7eb35281d10d.png" target="_main">Circuit Diagram</a>
   
<h3>  🤔What does the circuit do? </h3>
    The given circuit asks the user a password to enter, when the user enters the password, which is seen as **** in the lcd display. When the user enters the wrong password, a message inncorect password is shown. When the user enters the right password a message "<b>WELCOME BACK TONY!!</b>" is shown in lcd display, and the light bulb starts to glow. After a certain delay a message "<b>UNLOCKED</b>". We can change the password after unlocking only, by pressing # once and long pressing it will give the possibility to change the password. We have to set and retype the password in order to change the password. The reseted password is stored in the EEPROM. In case the EEPROM fails to stors the password, it resets the password to the first password that was setted. The circuit also gives the user to lock the device that is via, pressing * and long pressing the key.

<h3>   ⚡🔌Tinkercad Simulation </h3>
   Here is the link of the simulation of tinkercad circuit
   <a href="https://www.tinkercad.com/things/1mzgyYDNf8q" target="_main">Simulation</a>
   
   
<h3>   🤓EEPROM Library </h3>
The microcontroller on the Arduino and Genuino AVR based board has EEPROM: memory whose values are kept when the board is turned off (like a tiny hard drive). This library enables you to read and write those bytes.

The supported micro-controllers on the various Arduino and Genuino boards have different amounts of EEPROM: 1024 bytes on the ATmega328P, 512 bytes on the ATmega168 and ATmega8, 4 KB (4096 bytes) on the ATmega1280 and ATmega2560. The Arduino and Genuino 101 boards have an emulated EEPROM space of 1024 bytes.

The EEPROM library provides an easy to use interface to interact with the internal non-volatile storage found on AVR based Arduino boards. The library uses a set of native C++ classes which allows for very efficient usage by preventing any unnecessary overhead from being added to a sketch. This library will work on many AVR devices containing an EEPROM, such as ATtiny and ATmega chips.

<h4>Purpose of the library</h4>
The EEPROM library has been rebuilt from the ground up. It has an improved set of basic functionality helping to make entry level use easier. As a consequence of its own design, it includes an advanced API for all the seasoned and tasty programmers out there.

This thread is intended for discussion as well as support. If you have a question on how to use the EEPROM library in your project, fire away. Once the discussion is over, hopefully this thread can become a one stop shop for EEPROM help and various examples. Don’t hold back if you would like to discuss some aspect of the library/documentation, or simply let me know what you think. Also if you create an example sketch you feel highlights a useful feature, or solution to a common problem: post it and it can be linked from this index, or even proposed as an addition to the IDE.

The site reference has just been updated with the basic set of functionality (after writing this article). However this documentation will eventually contain all the reference material from basic to advanced usage. And to allow for the best documentation possible, we can take the time here to improve on it before adding it to the official resource if warranted. Or simply have an in-depth resource here. Once I’m happy with the next sections, I’ll update these posts.

<h3> 📚BIBLIOGRAPHY </h3>
<p><a href="https://forum.arduino.cc/t/official-eeprom-library-support-and-reference/301775/1" target="_main">https://forum.arduino.cc/t/official-eeprom-library-support-and-reference/301775/1</a></p>
<p><a href="https://docs.arduino.cc/learn/built-in-libraries/eeprom" target="_main">https://docs.arduino.cc/learn/built-in-libraries/eeprom</a></p>
<p><a href="https://www.youtube.com/watch?v=-s2QgXVrSXc" target="_main">https://www.youtube.com/watch?v=-s2QgXVrSXc"</a></p>
<p><a href="https://create.arduino.cc/projecthub/diy-hacking/arduino-keyless-door-lock-system-with-keypad-and-lcd-bcad2e" target="_main">https://create.arduino.cc/projecthub/diy-hacking/arduino-keyless-door-lock-system-with-keypad-and-lcd-bcad2e</a></p>
