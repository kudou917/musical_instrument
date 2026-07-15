#define TONE_USE_INT
#define TONE_PITCH 440
#include <TonePitch.h>
#include <Adafruit_LPS35HW.h>

Adafruit_LPS35HW lps35hw = Adafruit_LPS35HW();

// For SPI mode, we need a CS pin
#define LPS_CS 10
// For software-SPI mode we need SCK/MOSI/MISO pins
#define LPS_SCK 13
#define LPS_MISO 12
#define LPS_MOSI 11
#define OC_PIN 3
const int SENSOR_PIN = A0;
const int BUZZ_PIN = 8;
void setup() {
  Serial.begin(115200);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(OC_PIN, INPUT);
  while (!Serial) { delay(1); }

  Serial.println("Adafruit LPS35HW Test");

  //if (!lps35hw.begin_I2C()) {
  // if (!lps35hw.begin_SPI(LPS_CS)) {
  if (!lps35hw.begin_SPI(LPS_CS, LPS_SCK, LPS_MISO, LPS_MOSI)) {
    Serial.println("Couldn't find LPS35HW chip");
    while (1)
      ;
  }
  Serial.println("Found LPS35HW chip");
}

void loop() {
  int press = lps35hw.readPressure();
  int value = analogRead(SENSOR_PIN);
  int bottonstate = digitalRead(OC_PIN);
  Serial.print(press);
  Serial.println("hpa");
  Serial.println(value);
  Serial.println(bottonstate);
  if (1020 < press) {
    if (bottonstate == HIGH) {
      if ((value >= 0) && (95 >= value)) {
        buzzSound(NOTE_AS5);
      } else if ((value >= 970) && (1024 >= value)) {
        buzzSound(NOTE_A5);
      } else if ((value >= 850) && (890 >= value)) {
        buzzSound(NOTE_GS5);
      } else if ((value >= 700) && (750 >= value)) {
        buzzSound(NOTE_G5);
      } else if ((value >= 625) && (650 >= value)) {
        buzzSound(NOTE_F5);
      } else if ((value >= 540) && (580 >= value)) {
        buzzSound(NOTE_FS5);
      } else if ((value >= 460) && (525 >= value)) {
        buzzSound(NOTE_DS5);
      } else if ((value >= 400) && (450 >= value)) {
        buzzSound(NOTE_E5);
      } else if ((value >= 340) && (380 >= value)) {
        buzzSound(NOTE_D5);
      } else if ((value >= 290) && (335 >= value)) {
        buzzSound(NOTE_C5);
      } else if ((value >= 230) && (280 >= value)) {
        buzzSound(NOTE_CS5);
      } else if ((value >= 180) && (200 >= value)) {
        buzzSound(NOTE_AS4);
      } else if ((value >= 110) && (165 >= value)) {
        buzzSound(NOTE_B4);
      } else {             // 何も押されてない時
        noTone(BUZZ_PIN);  // 消音
      }
      delay(100);
      }
    else {
      if ((value >= 0) && (95 >= value)) {
        buzzSound(NOTE_AS4);
      } else if ((value >= 970) && (1024 >= value)) {
        buzzSound(NOTE_A4);
      } else if ((value >= 850) && (890 >= value)) {
        buzzSound(NOTE_GS4);
      } else if ((value >= 725) && (750 >= value)) {
        buzzSound(NOTE_G4);
      } else if ((value >= 625) && (650 >= value)) {
        buzzSound(NOTE_F4);
      } else if ((value >= 540) && (580 >= value)) {
        buzzSound(NOTE_FS4);
      } else if ((value >= 460) && (525 >= value)) {
        buzzSound(NOTE_DS4);
      } else if ((value >= 400) && (450 >= value)) {
        buzzSound(NOTE_E4);
      } else if ((value >= 340) && (380 >= value)) {
        buzzSound(NOTE_D4);
      } else if ((value >= 290) && (335 >= value)) {
        buzzSound(NOTE_C4);
      } else if ((value >= 230) && (280 >= value)) {
        buzzSound(NOTE_CS4);
      } else if ((value >= 180) && (200 >= value)) {
        buzzSound(NOTE_AS3);
      } else if ((value >= 110) && (165 >= value)) {
        buzzSound(NOTE_B3);
      } else {             // 何も押されてない時
        noTone(BUZZ_PIN);  // 消音
      }
      delay(100);
    }
  } else {
    noTone(BUZZ_PIN);
  }
}

void buzzSound(int frequency) {
  tone(BUZZ_PIN, frequency);  // 音を鳴らす
  delay(50);
}
