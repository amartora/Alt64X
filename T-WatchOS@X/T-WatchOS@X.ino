#include "config.h"
#include "Free_Fonts.h"
#include "WiFi.h"

void touchHome();
void bootScreen();
void  mainMenu1();

TTGOClass *ttgo;


unsigned long drawTime = 0;

int16_t x = -1;
int16_t y = -1;

int button = 0;

void setup() {

  WiFi.mode(WIFI_STA);
  delay(1000);
  //Serial.begin (115200);
  
  ttgo = TTGOClass::getWatch();
  ttgo->begin();
  ttgo->openBL();//turn on backlight
  ttgo->lvgl_begin();
  
  ttgo->bl->adjust(50);
  
  bootScreen();
  
  }
  
  void loop() {
  
    mainMenu1();
    
  }
