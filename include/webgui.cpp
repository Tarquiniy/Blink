#include "includes.hpp"
#include "defines.h"


#define ssid "ESP32-Access-Point1"
#define password  "123456789"
GyverPortal portal;
int valNum;


void build() {
  GP.BUILD_BEGIN();
  GP.THEME(GP_DARK);
  GP.BUTTON("beep", "BEEP");
  GP.BUTTON("restart", "Restart");
  GP.BUTTON("vibro", "Vibro");
  GP.NUMBER("num", "number", valNum); GP.BREAK();
  GP.BUTTON("ok", "OK");
  GP.BUTTON("server", "Режим сервера");
  GP.BUTTON("client", "Режим клиента");
  GP.BUILD_END();
}

void action() {
    if (portal.click("beep")){
      tone(SOUND, 1000, 200);
       strip.fill(0xFF0000, 0, 10);
                strip.show();
       Serial.println("Button click");
       vTaskDelay(100 / portTICK_PERIOD_MS); 
    }
    if (portal.click("restart")) {
            noTone(SOUND); 
            vibrationDetected = false; 
            strip.fill(0x008000, 0, 10);
            strip.show();
            vTaskDelay(100 / portTICK_PERIOD_MS); 
        }
    if (portal.click("vibro")) {
            vibrationCount++;
            vibrationDetected = true;
            vTaskDelay(1000 / portTICK_PERIOD_MS); 
        }
    if (portal.clickInt("num", valNum)) {
      Serial.print("Number: ");
      Serial.println(valNum);
      vTaskDelay(1000 / portTICK_PERIOD_MS); 
    }
    if (portal.click("client")){
      WiFi.begin("ESP32-Access-Point", "123456789"); // Подключение к Wi-Fi
    while (WiFi.status() != WL_CONNECTED) {
      vTaskDelay(1000/ portTICK_PERIOD_MS);
      Serial.println("Подключение к Wi-Fi...");
    }
    Serial.println("Подключено к Wi-Fi");
    }
        vTaskDelay(10 / portTICK_PERIOD_MS); 
    }



void setupAPTask(void *pvParameters) {
WiFi.mode(WIFI_AP);
WiFi.softAP(ssid, password);
portal.attachBuild(build);
portal.attach(action);
portal.log.start(30);
portal.start();
Serial.print("Точка доступа создана");
  while (true) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}


