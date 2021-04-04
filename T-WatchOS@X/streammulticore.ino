//recieves video stream from related my LilyGo T-Camera code

#include "config.h"
#include <WiFi.h>
#include <WiFiUdp.h>

WiFiUDP UDPTestServer;

TaskHandle_t Task1;
TaskHandle_t Task2;

unsigned int UDPPort = 1337;

byte packetBuffer[1442];

//uint16_t cattedPacket[721];

void stream(){
 
  x = -1;
  y = -1;
  
  Serial.begin(115200);

  const char* ssid     = "";
  const char* password = "";

  ttgo->tft->fillScreen(TFT_BLACK);
  drawHome(TFT_RED, &FreeMono12pt7b, MC_DATUM);
  ttgo->tft->drawString("CONNECTING...", 120, 120, GFXFF);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

    ttgo->getTouch(x,y);
    if (touchHome(x, y)){
      ttgo->tft->fillScreen(TFT_BLACK);
      ESP.restart();
    }
    
  }

  Serial.println("WiFi connected"); 
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  ttgo->tft->fillScreen(TFT_BLACK);
  drawHome(TFT_RED, &FreeMono12pt7b, MC_DATUM);
  ttgo->tft->drawString("NO FEED", 120, 120, GFXFF);

  UDPTestServer.begin(UDPPort);

  ttgo->tft->setSwapBytes(true);
  
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 0 */                  
  delay(500); 

  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  delay(500); 

    for(;;){
      
    }
}

void Task1code( void * pvParameters ){
  
  uint16_t cattedPacket[721];
  int16_t localX = -1;
  int16_t localY = -1;
  
  for(;;){
    ttgo->getTouch(localX, localY);
    delay(1);
    if (touchHome(localX, localY)){
      ttgo->tft->fillScreen(TFT_BLACK);
      ESP.restart();
    }
   

     for (int j = 0; j < 721; ++j){
        
        cattedPacket[j] = packetBuffer[0+(2*j)] << 8 | packetBuffer[1+(2*j)];
        
      }
    
    ttgo->tft->pushImage(-1, ((cattedPacket[0]-1)*3)+32, 240, 3, cattedPacket);
    
  }
  
  

}

void Task2code( void * pvParameters ){

  uint16_t finalRowGroup[720];
  //byte packetBuffer[1442];
  
  for(;;){

//    ttgo->getTouch(x,y);
//    if (touchHome(x, y)){
//      ttgo->tft->fillScreen(TFT_BLACK);
//      ESP.restart();
   // }
    delay(1);
    //int cb = UDPTestServer.parsePacket();
      if (UDPTestServer.parsePacket()) {
        
        UDPTestServer.read(packetBuffer, 1442);

      //for (int j = 0; j < 721; ++j){
        
       // cattedPacket[j] = packetBuffer[0+(2*j)] << 8 | packetBuffer[1+(2*j)];
        
     // }
    }  
  }
}
