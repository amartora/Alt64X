void wifiScan();
void pictures();
void powerFunc();
void mainMenu2();
void secretMenu();
void stream();

int sleeptimer = 10000;

//i need to start putting these "prototypes" up here for some reason
void mainMenu1(){


  //**********************************************************************************************************************************************DRAWING OUT MENU

  ttgo->tft->setFreeFont(&FreeMono9pt7b); //setting font, see Free_Fonts.h for the fonts
  ttgo->tft->setTextColor(TFT_GREEN, TFT_BLACK); //setting text color, background color
  ttgo->tft->setTextDatum(ML_DATUM); //text is referenced by middle left
  ttgo->tft->fillScreen(TFT_BLACK);
  ttgo->tft->drawString("> scan Wi-Fi", 20, 74, GFXFF); //text, xpos, ypos, and font size (here since were are using Free_Fonts, put GFXFF
  ttgo->tft->drawString("> pictures", 20, 120, GFXFF);
  ttgo->tft->drawString("> power data", 20, 167, GFXFF);
  drawDownArrow(&FreeMono9pt7b, ML_DATUM);
  drawHome(TFT_GREEN, &FreeMono9pt7b, MC_DATUM);
 //**********************************************************************************************************************************************DRAWING OUT MENU
  int counter = 0;
  button = 0; //resetting everything from previous states
  x = -1;
  y = -1;

  delay (1000);

  while (1) {
    x = -1;
    y = -1;
    counter++;

    if(counter > sleeptimer){
    
    ttgo->powerOff();

    ttgo->power->setPowerOutPut(AXP202_LDO3, false);
    ttgo->power->setPowerOutPut(AXP202_LDO4, false);
    ttgo->power->setPowerOutPut(AXP202_LDO2, false);
    ttgo->power->setPowerOutPut(AXP202_EXTEN, false);
    ttgo->power->setPowerOutPut(AXP202_DCDC2, false);

    esp_sleep_enable_ext1_wakeup(GPIO_SEL_38, ESP_EXT1_WAKEUP_ALL_LOW);

    esp_deep_sleep_start();
    
  }
  
    ttgo->getTouch(x,y); //write touch coordinates to x and y variables (which were declared globally)
    
    if(x>=0 || y>=0){
      counter = 0;
    }


    
    if (touchTopOption (x, y)){
      button = 1;
      break;
    }
    else if (touchMiddleOption (x, y)){
      button = 2;
      break;
    }
     else if (touchBottomOption (x, y)){
      button = 3;
      break;
    }
     else if (touchDownArrow(x, y)){//if down arrow is pressed
      button = 4;
      break;
    }
    else if ((200 <= x) && (x <= 240) && (0 <= y) && (y < 40)){//if secret button is pressed
      button = 5;
      break;
    }
  }

  if (button == 1){
    wifiScan();
  }
  else if (button == 2){
    pictures();
  }
  else if (button == 3){
    powerFunc();
  }
  else if (button == 4){
    mainMenu2();
  }
  else if (button == 5){
    secretMenu();
  }

  
}
