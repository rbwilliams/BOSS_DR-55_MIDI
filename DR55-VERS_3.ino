const byte NoteOff = 0;
byte NoteOn = 0x90;//NoteOn. B10010000.

// MIDI channels (Port C)
//const byte ch1 = B00000000;//  "ch 1, DR55 position 1 AND MODE Switch in 'PLAY' position"
//const byte ch2 = B00000001;//  "ch 2, DR55 position 2 AND MODE Switch in 'PLAY' position"
//const byte ch3 = B00000010;//  "ch 3, DR55 position 3 AND MODE Switch in 'PLAY' position"
//const byte ch4 = B00000011;//  "ch 4, DR55 position 4 AND MODE Switch in 'PLAY' position"
//const byte ch5 = B00000100;//  "ch 5, DR55 position 5 AND MODE Switch in 'PLAY' position"
//const byte ch6 = B00000101;//  "ch 6, DR55 position 6 AND MODE Switch in 'PLAY' position"
//const byte ch7 = B00000110;//  "ch 7, DR55 position 7 AND MODE Switch in 'PLAY' position"
//const byte ch8 = B00000111;//  "ch 8, DR55 position 8 AND MODE Switch in 'PLAY' position"
//const byte ch9 = B00001000;//  "ch 9, DR55 position 1 AND MODE Switch in 'WRITE' position"
//const byte ch10= B00001001;//  "ch 10, DR55 position 2 AND MODE Switch in 'WRITE' position""
//const byte ch11= B00001010;//  "ch 11, DR55 position 3 AND MODE Switch in 'WRITE' position""
//const byte ch12= B00001011;//  "ch 12, DR55 position 4 AND MODE Switch in 'WRITE' position""
//const byte ch13= B00001100;//  "ch 13, DR55 position 5 AND MODE Switch in 'WRITE' position""
//const byte ch14= B00001101;//  "ch 14, DR55 position 6 AND MODE Switch in 'WRITE' position""
//const byte ch15= B00001110;//  "ch 15, DR55 position 1 AND MODE Switch in 'WRITE' position""
//const byte ch16= B00001111;//  "ch 16, DR55 position 1 AND MODE Switch in 'WRITE' position""

//const byte DSTATE = B00000010;// port D state with RX input, TX as output. Need to XOR with other states.
const byte BDon =   B00000100;// port D
const byte SDon =   B00001000;// port D
const byte RSon =   B00010000;// port D
const byte HHon =   B00100000;// port D
const byte ACon =   B01000000;// port D
const byte POon =   B10000000;// port D
const byte BDnote = 0x18;//note 24, C1
const byte SDnote = 0x1A;//note 26, D1
const byte RSnote = 0x1C;//note 28, E1
const byte HHnote = 0x1D;//note 29, F1
const byte ACnote = 0x1F;//note 31, G1
const byte POnote = 0x21;//note 33, A1
//byte newState;
//unsigned long TimeOn;
unsigned long BDtime;
unsigned long SDtime;
unsigned long RStime;
unsigned long HHtime;
unsigned long ACtime;
unsigned long POtime;
int pulseTime = 15;
//int LEDtime = 50;
//unsigned long LEDonTime;
//byte LEDpin = B00100000;
//byte instr;

byte commandByte;
byte noteByte;
byte velocityByte;
byte MIDIch;

void setup(){
  Serial.begin(31250);
  DDRC = B11000000; //Set PC0-PC6 as inputs for switches and buttons.
  DDRD = B11111110; //Pins PD7-PD1(pins 2-7) as outputs. PD0 (RX) is an input.
};

void loop(){
  if (Serial.available()){
    commandByte = Serial.read();
    noteByte = Serial.read();
    velocityByte = Serial.read();
    if (velocityByte > 0 ){
      MIDIch = PINC; //read the MIDI channel select switches.
      NoteOn = NoteOn & MIDIch; // Combine Note On high nibble with MIDI channel low nibble.
      if (commandByte == NoteOn){ //Read second byte - should be b1001nnnn, where nnnnn
        if (noteByte == BDnote){
          PORTD = PORTD & BDon;
          BDtime = millis();
        }else if (noteByte == SDnote){
          PORTD = PORTD & SDon;
          SDtime = millis();
        }else if (noteByte == RSnote){
          PORTD = PORTD & RSon;
          RStime = millis();
        }else if (noteByte == HHnote){
          PORTD = PORTD & HHon; 
          HHtime = millis();
        }else if (noteByte == ACnote | velocityByte > 64){
          PORTD = PORTD & ACon;
          ACtime = millis();
        }else if (noteByte == POnote){
          PORTD = PORTD & POon;
          POtime = millis();
        };
      };
    };
  };
  if (millis() - BDtime >= pulseTime){
    PORTD = PORTD ^ BDon;
  }else if (millis() - SDtime >= pulseTime){
    PORTD = PORTD ^ SDon;
  }else if (millis() - RStime >= pulseTime){
    PORTD = PORTD ^ RSon;
  }else if (millis() - HHtime >= pulseTime){
    PORTD = PORTD ^ HHon;
  }else if (millis() - ACtime >= pulseTime){
    PORTD = PORTD ^ ACon;
  }else if (millis() - POtime >= pulseTime){
    PORTD = PORTD ^ POon;
  };
};
