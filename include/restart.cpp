#include "defines.h"
#include "includes.hpp"



void herconTask(void *pvParameters) {
    while (true) {
        if (digitalRead(HERCON) == 1) {
            udp.begin(localUdpPort);
            Serial.printf("UDP запущен на порту %dn", localUdpPort);
            noTone(SOUND); 
            vibrationDetected = false; 
            strip.fill(0x008000, 0, 10);
            strip.show();
            String message = String(vibrationCount);
            udp.beginPacket("255.255.255.255", localUdpPort);
            udp.print(message);
            udp.endPacket();
            Serial.printf("Отправлено: %sn", message.c_str());
            int packetSize = udp.parsePacket();
        if (packetSize) {
            int n = udp.read(incomingPacket, 255);
            incomingPacket[n] = 0;
            Serial.printf("Получено: %sn", incomingPacket);
        }
        }
        vTaskDelay(10 / portTICK_PERIOD_MS); 
   }
}