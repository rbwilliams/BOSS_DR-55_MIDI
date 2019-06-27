# BOSS_DR-55_MIDI
## MIDI control of Boss DR-55 drum machine with Arduino Pro Mini 
![Picture](http://www.polynominal.com/site/studio/gear/drum/boss-dr55/boss-dr-55.jpg)
### This modification replaces IC1, a Toshiba TC5501P-1 static RAM IC, with am Atmel Atmega 328 in Arduino Pro Miini form factor.
![Picture](https://www.arduino.cc/en/uploads/Main/ProMiniFront.jpg)
Becasue this project will run on 6 AA batteries, power saving is an issue. One step twoards this is to remove the current-limiting resistor to the power LED on the Pro Mini. This will disconnect the LED from ground, and save around 20mA of power.
