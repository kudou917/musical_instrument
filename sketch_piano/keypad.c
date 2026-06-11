/*
  The code use an Adafruit Keypad and display keypress events via the Serial Monitor. 
  It initializes the keypad with a 4x4 layout, where each key is represented by a 
  specific character. It continuously checks for keypad events (key press or release) 
  and prints the corresponding key and event status to the Serial Monitor.

  Board: Arduino Uno R4 
  Component:  Keypad
  Library: https://github.com/adafruit/Adafruit_Keypad (Adafruit Keypad by Adafruit)
*/

// Include the Adafruit_Keypad library
#define TONE_USE_INT
#define TONE_PITCH 440
#include <TonePitch.h>
#include "Adafruit_Keypad.h"
#define BUZZ_PIN 13 //ブザーのピン
// Define the number of rows and columns for the keypad
const byte ROWS = 4;
const byte COLS = 4;

// Define the characters mapped to each button on the 4x4 keypad
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// Define the Arduino pins connected to the row pinouts of the keypad
byte rowPins[ROWS] = { 2, 3, 4, 5 };
// Define the Arduino pins connected to the column pinouts of the keypad
byte colPins[COLS] = { 8, 9, 10, 11 };

// Initialize a custom keypad instance
Adafruit_Keypad myKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Setup function
void setup() {
  // Initialize Serial communication at 9600 baud rate
  Serial.begin(9600);
  // Initialize the custom keypad
  myKeypad.begin();
}

// Main loop function
void loop() {
  // Update the state of keys
  myKeypad.tick();

  // Check if there are new keypad events
  while (myKeypad.available()) {
    // Read the keypad event
    keypadEvent e = myKeypad.read();
    // Print the key that triggered the event
    Serial.println((char)e.bit.KEY);
    // Print the type of event: pressed or released


    if (e.bit.EVENT == KEY_JUST_RELEASED){ 
      noTone(BUZZ_PIN);
    }
    else{
      if ((char)e.bit.KEY == '1' ) buzzSound(NOTE_C4);
      else if ((char)e.bit.KEY == '2') buzzSound(NOTE_CS4);
      else if ((char)e.bit.KEY == '3') buzzSound(NOTE_D4);
      else if ((char)e.bit.KEY == 'A') buzzSound(NOTE_DS4);
      else if ((char)e.bit.KEY == '4') buzzSound(NOTE_E4);
      else if ((char)e.bit.KEY == '5') buzzSound(NOTE_F4);
      else if ((char)e.bit.KEY == '6') buzzSound(NOTE_FS4);
      else if ((char)e.bit.KEY == 'B') buzzSound(NOTE_G4);
      else if ((char)e.bit.KEY == '7') buzzSound(NOTE_GS4);
      else if ((char)e.bit.KEY == '8') buzzSound(NOTE_A4);
      else if ((char)e.bit.KEY == '9') buzzSound(NOTE_AS4);
      else if ((char)e.bit.KEY == 'C') buzzSound(NOTE_B4);
    }


  }

  delay(10);
}

void buzzSound(int frequency){
  tone(BUZZ_PIN, frequency);  //音を鳴らす
  delay(50);
}