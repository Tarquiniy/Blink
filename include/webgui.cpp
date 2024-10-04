#include "includes.hpp"

GyverPortal portal;

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
//void setupAPTask(void *pvParameters);

void build() {
  GP.BUILD_BEGIN();
  GP.THEME(GP_DARK);
  GP.BUTTON("on", "ON");
  GP.BUTTON("off", "OFF");
  GP.BUILD_END();
}


void setupAPTask(void *pvParameters) {
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  Serial.print("Точка доступа запущена. IP адрес: ");
  Serial.println(WiFi.localIP());
  
  // Ждем, пока точка доступа станет активной
  while (WiFi.status() != WL_CONNECTED) {
    vTaskDelay(100 / portTICK_PERIOD_MS);
    Serial.print(".");
  }
  
  // После успешного запуска точки доступа:
  portal.attachBuild(build);
  portal.start();

  while (true) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}