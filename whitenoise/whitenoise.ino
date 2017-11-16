#include <Arduino.h>
#include "TF.h"
#include "Audio.h"
void setup() {
  Serial.begin(115200);
  Serial.print("whitenoise radio");
  pinMode(3, OUTPUT);
  if(!SD.begin()) {
    Serial.println("SD setup error");
    while(1);
  }
  Audio.begin(AUDIO_SD);
  Audio.setVolume(27);
  if(Audio) {
    Audio.playFile("\\whitenoise.mp3");
    digitalWrite(3, HIGH);
  }
}
void loop() {
  Serial.println("loop");
  if (Audio.getStatus() == AudioPlay) {
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    delay(1000);
  }

  if (Audio.getStatus() == AudioStop) {
    Audio.playFile("\\whitenoise.mp3");
    for (int i=0; i<20; i++) {
      digitalWrite(3, HIGH);
      delay(250);
    }
  }
}
