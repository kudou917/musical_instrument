#define TONE_USE_INT
#define TONE_PITCH 440
#include <TonePitch.h>

const int SENSOR_PIN = A0;
const int BUZZ_PIN = 8;
void setup() {
    Serial.begin(115200);
    pinMode(BUZZ_PIN,OUTPUT);
    pinMode(SENSOR_PIN,INPUT);
}

void loop() {
    int value = analogRead(SENSOR_PIN);

    Serial.println(value);
  if ((value >= 1000) && (1024 >= value)){
    buzzSound(NOTE_DS4);
  }
  else if ((value >= 840) && (900 >= value)){
    buzzSound(NOTE_E4);
  }
   else if ((value >= 720) && (760 >= value)){
    buzzSound(NOTE_D4);
  }
   else if ((value >= 600) && (670 >= value)){
    buzzSound(NOTE_C4);
  }
   else if ((value >= 500) && (530 >= value)){
    buzzSound(NOTE_CS4);
  }
   else if ((value >= 400) && (430 >= value)){
    buzzSound(NOTE_AS3);
  }
    else if ((value >= 300) && (330 >= value)){
    buzzSound(NOTE_B3);
  }
  else{   //何も押されてない時
    noTone(BUZZ_PIN);   //消音
  }
    delay(100);
}

void buzzSound(int frequency){
  tone(BUZZ_PIN, frequency);  //音を鳴らす
  delay(50);
}