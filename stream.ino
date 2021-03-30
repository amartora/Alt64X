//#include "config.h"
//#include <WiFi.h>
//#include <WiFiUdp.h>
//
//void stream(){
//  
//  const char* ssid     = "";
//  const char* password = "";
//
//  WiFiUDP UDPTestServer;
//  
//  unsigned int UDPPort = 1337;
//  const int packetSize = 1442;
//  byte packetBuffer[packetSize];
//
//  uint16_t cattedPacket[721];
//  uint16_t marker;
//
//  delay(500);
//  
//  x = -1;
//  y = -1;
//  
//  ttgo->tft->fillScreen(TFT_BLACK);
//  
//  drawHome(TFT_RED, &FreeMono12pt7b, MC_DATUM);
//
//  Serial.begin(115200);
//
//  Serial.println();
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
//
//  WiFi.begin(ssid, password);
//
//  ttgo->tft->drawString("CONNECTING...", 120, 120, GFXFF);
//  
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//
//     ttgo->getTouch(x,y);
//    if (touchHome(x, y)){
//      ttgo->tft->fillScreen(TFT_BLACK);
//      ESP.restart();
//    }
//    
//  }
//
//  ttgo->tft->fillScreen(TFT_BLACK);
//  drawHome(TFT_RED, &FreeMono12pt7b, MC_DATUM);
//  ttgo->tft->drawString("NO FEED", 120, 120, GFXFF);
//  
//  Serial.println("");
//  Serial.println("WiFi connected"); 
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());
//
//  UDPTestServer.begin(UDPPort);
//
//  ttgo->tft->setSwapBytes(true);
//
//  while(1){
//
//    ttgo->getTouch(x,y);
//    if (touchHome(x, y)){
//      ttgo->tft->fillScreen(TFT_BLACK);
//      ESP.restart();
//    }
//
//    int cb = UDPTestServer.parsePacket();
//    
//    if (cb) {
//    
//      UDPTestServer.read(packetBuffer, packetSize);
//      
//      for (int j = 0; j < 721; ++j){
//      
//        cattedPacket[j] = packetBuffer[0+(2*j)] << 8 | packetBuffer[1+(2*j)]; //concactenating into 16-bit
//        
//      }
//      
//      uint16_t finalRowGroup[720];
//
//      marker = cattedPacket[0];
//
//      for (int h = 0; h < 720; ++h){
//        
//        finalRowGroup[h] = cattedPacket[h+1]; //removing marker integer
//        
//      }
//
//       ttgo->tft->pushImage(0, ((marker-1)*3)+32, 240, 3, finalRowGroup);
//
//      }
//  }
//  
//}
