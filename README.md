# BOSS_DR-55_MIDI
## MIDI control of Boss DR-55 drum machine with Arduino Pro Mini 
![Picture](http://www.polynominal.com/site/studio/gear/drum/boss-dr55/boss-dr-55.jpg)
### This modification replaces IC1, a Toshiba TC5501P-1 static RAM IC, with am Atmel Atmega 328 in Arduino Pro Miini form factor.
![Picture](https://www.arduino.cc/en/uploads/Main/ProMiniFront.jpg)

Becasue this project will run on 6 AA batteries, power saving is an issue. One step twoards this is to remove the current-limiting resistor to the power LED on the Pro Mini. This will disconnect the LED from ground, and save around 20mA of power.

The Arduino Pro Mini is running at 8mHz, with a 3.3V regulator on board. This saves a bit more power compared to the 16mHz/5V version.

It is important to note that this current version of firmware only triggers the DR-55 sounds via MIDI, and DOES NOT yet implement patter record/playback. This is planned for future releases,. 
