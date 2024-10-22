#include "includes.hpp"
#include "defines.h"

void setToneAndColor(int toneFreq, int toneTime, uint32_t color) {
    tone(SOUND, toneFreq, toneTime);
    strip.fill(color, 0, 10);
    strip.show();
}

void soundTask(void *pvParameters) {
    while (true) {
        if (vibrationDetected) {
            if (vibrationCount == 0.2 * valNum) {
                setToneAndColor(1500,200, 0x339900);
                Serial.print("led1");}}
                if (vibrationDetected) {
                if (vibrationCount == 0.4 * valNum) {
                    setToneAndColor(1000,200, 0xCCCC00);
                    Serial.print("led2");}}
                    if (vibrationDetected) {
                    if (vibrationCount == 0.6 * valNum) {
                        setToneAndColor(500,200, 0xFF6600);
                        Serial.print("led3");}}
                        if (vibrationDetected) {
                        if (vibrationCount == 0.8 * valNum) {
                            setToneAndColor(250,200, 0xFF3300);
                            Serial.print("led4");}}
                            if (vibrationDetected) {
                            if (vibrationCount == valNum) {
                                setToneAndColor(125,200, 0xFF0000);
                                Serial.print("led5");
                                vibrationCount = 0; }
                            }
        vibrationDetected = false; 
        vTaskDelay(10 / portTICK_PERIOD_MS); 
    }
}
