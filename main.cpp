#include "includes.hpp"
#include "tasks.cpp"
#include "webgui.cpp"

void setup() {
    Serial.begin(115200);
    
  //GP.BUILD_BEGIN();
  //GP.BUILD_END();
    strip.begin();
    strip.show();
    strip.setBrightness(50);
    strip.fill(0x008000, 0, 10);
    strip.show();
    pinMode(HERCON, INPUT);
    pinMode(SOUND, OUTPUT);
    pinMode(SENSOR, INPUT);
    xTaskCreate(vibrationTask, "Vibration Task", 1024, NULL, 1, NULL);
    xTaskCreate(soundTask, "Sound Task", 1024, NULL, 1, NULL);
    xTaskCreate(herconTask, "Hercon Task", 1024, NULL, 1, NULL);
    xTaskCreate(setupAPTask, "WiFi Task", 4096, NULL, 1, NULL);
}

void loop() {
}


