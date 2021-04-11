/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
#include "pitches.h"
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}
int notes[] = {
  NOTE_B0, NOTE_FS4, NOTE_DS8
};
int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

void marioMelodie(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);

  }
}
void endMelodie() {
      noTone(8);

  // play a note on pin 6 for 200 ms:

      tone(8, 440, 200);

      delay(200);

  // turn off tone function for pin 6:

       noTone(8);

  // play a note on pin 7 for 500 ms:

      tone(8, 494, 500);

       delay(500);

  // turn off tone function for pin 7:

      noTone(8);

  // play a note on pin 8 for 300 ms:

      tone(8, 523, 300);

      delay(300);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A1);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(10);
  if (sensorValue > 1000){
      marioMelodie();
      //tone(8, notes[0], 40);
     //digitalWrite(8, HIGH); 
  }
  else{
    //digitalWrite(8, LOW); 
    tone(8, notes[1], 40);
  }
  if (sensorValue == 0){
      endMelodie();
  }
}
