//#include "includes.hpp"

//volatile bool vibrationDetected = false;
//volatile int vibrationCount = 0;
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);

//void vibrationTask(void *pvParameters) {
//    while (true) {
//        int sensorValue = digitalRead(SENSOR);
//        if (sensorValue == true) { 
//            vibrationCount++;
//            vibrationDetected = true;
//            vTaskDelay(100 / portTICK_PERIOD_MS); 
//        }
//        vTaskDelay(10 / portTICK_PERIOD_MS); 
//    }
//}

//void soundTask(void *pvParameters) {
//    while (true) {
//        if (vibrationDetected) {
//            if (vibrationCount >= 5) { 
//                tone(SOUND, 1000); 
//                strip.fill(0xFF0000, 0, 10);
//                strip.show();
//                vibrationCount = 0;
//            }
//            vibrationDetected = false;
//        }
//        vTaskDelay(10 / portTICK_PERIOD_MS); 
//    }
//}

//void herconTask(void *pvParameters) {
//    while (true) {
//        if (digitalRead(HERCON) == 0) {
//            noTone(SOUND); 
//            vibrationDetected = false; 
//            strip.fill(0x008000, 0, 10);
//            strip.show();
//        }
//        vTaskDelay(10 / portTICK_PERIOD_MS); 
//   }
//}


//#define ssid "ESP32-Access-Point"
//#define password  "123456789"
//GyverPortal portal;

//void build() {
//  GP.BUILD_BEGIN();
//  GP.THEME(GP_DARK);
//  GP.BUTTON("beep", "BEEP");
//  GP.BUTTON("restart", "Restart");
//  GP.BUTTON("vibro", "Vibro");
//  GP.BUILD_END();
//}

//void action() {
//    if (portal.click("beep")){
//      tone(SOUND, 1000, 200);
//       strip.fill(0xFF0000, 0, 10);
//                strip.show();
//       Serial.println("Button click");
//    }
//    if (portal.click("restart")) {
//            noTone(SOUND); 
//            vibrationDetected = false; 
//            strip.fill(0x008000, 0, 10);
//            strip.show();
//        }
//    if (portal.click("vibro")) {
//            vibrationCount++;
//            vibrationDetected = true;
//            vTaskDelay(100 / portTICK_PERIOD_MS); 
//        }
//        vTaskDelay(10 / portTICK_PERIOD_MS); 
//    }



//void setupAPTask(void *pvParameters) {
//WiFi.mode(WIFI_AP);
//WiFi.softAP(ssid, password);
//portal.attachBuild(build);
//portal.attach(action);
//portal.log.start(30);
//portal.start();
  
//  while (true) {
//    vTaskDelay(1000 / portTICK_PERIOD_MS);
//  }
//}