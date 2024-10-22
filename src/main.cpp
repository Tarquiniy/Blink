#include "includes.hpp"
#include "tasks.cpp"
#include "sensor.cpp"
#include "webgui.cpp"
#include "sound.cpp"
#include "restart.cpp"





void setup() {
  Serial.begin(115200);
  pinMode(SENSOR, INPUT_PULLUP);
  pinMode(HERCON, INPUT_PULLUP);
  strip.show();
  strip.setBrightness(50);
  strip.fill(0x008000, 0, 10);
  strip.show();
  pinMode(HERCON, INPUT);
  pinMode(SOUND, OUTPUT);
  pinMode(SENSOR, INPUT);
  xTaskCreate(vibrationTask, "Vibration Task", 10000, NULL, 1, NULL);
  xTaskCreate(soundTask, "Sound Task", 10000, NULL, 1, NULL);
  //xTaskCreate(herconTask, "Hercon Task", 10000, NULL, 2, NULL);
  xTaskCreate(setupAPTask, "WiFi Task", 10000, NULL, 1, NULL);
  //xTaskCreate(taskFunction, "TaskFunction", 2048, NULL, 2, NULL);

}

void loop() {
  portal.tick();
  
}