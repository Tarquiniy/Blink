#include "includes.hpp"
volatile bool vibrationDetected = false;
volatile int vibrationCount = 0;
unsigned int localUdpPort = 4917;          // Порт для приема данных
char incomingPacket[255];  

WiFiUDP udp;
TaskHandle_t taskHandle;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);

void vibrationTask(void *pvParameters) {
    while (true) {
            
        
        int sensorValue = digitalRead(SENSOR);
        if (sensorValue == true) {             
                vibrationDetected = true;
                vibrationCount++;
             String message = String(vibrationCount);

      // Отправка сообщения всем платам (широковещательная рассылка)
      udp.begin(localUdpPort);
        Serial.printf("UDP запущен на порту %dn", localUdpPort);

      udp.beginPacket("255.255.255.255", localUdpPort);
              vTaskDelay(10 / portTICK_PERIOD_MS); 
      udp.print(message);
      udp.endPacket();

      Serial.printf("Отправлено: %sn", message.c_str());
        }

       int packetSize = udp.parsePacket();
  if (packetSize) {
    int n = udp.read(incomingPacket, 255);
            vTaskDelay(10 / portTICK_PERIOD_MS); 
    incomingPacket[n] = 0;
    Serial.printf("Получено: %sn", incomingPacket);
                vibrationDetected = true;
                vibrationCount++;

  }

        vTaskDelay(10 / portTICK_PERIOD_MS); 
    }
}