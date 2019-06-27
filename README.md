# BOSS_DR-55_MIDI
## MIDI control of Boss DR-55 drum machine with Arduino Pro Mini 
![Picture](http://www.polynominal.com/site/studio/gear/drum/boss-dr55/boss-dr-55.jpg)
### This modification replaces the digital section of the DR-55 with an Atmel Atmega328 in Arduino Pro Mini form factor. 
![Picture](https://www.arduino.cc/en/uploads/Main/ProMiniFront.jpg)
The IC's removed are IC1, the Toshiba TC5501P-1 static RAM IC, IC2 a MC14520B dual BCD counter, and IC3, a CD4011 quad NAND gate ICICwith am Atmel Atmega 328 in Arduino Pro Miini form factor.


Becasue this project will run on 6 AA batteries, power saving is an issue. One step twoards this is to remove the current-limiting resistor to the power LED on the Pro Mini. This will disconnect the LED from ground, and save around 20mA of power.

The Arduino Pro Mini is running at 8mHz, with a 3.3V regulator on board. This saves a bit more power compared to the 16mHz/5V version.

It is important to note that this current version of firmware only triggers the DR-55 sounds via MIDI, and DOES NOT yet implement patter record/playback. This is planned for future releases.

In addtion to the Arduino Pro Mini, you will needa 3.3V-powereed MDI IN circuit, and a piezo buzzer, like this:
![picture](https://www.robomart.com/image/cache/catalog/RM3079/rm3079-500x500.jpg)
