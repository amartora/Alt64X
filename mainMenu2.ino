void calculator();

void mainMenu2(){

  //**********************************************************************************************************************************************DRAWING OUT MENU

  ttgo->tft->setFreeFont(&FreeMono9pt7b); //setting font, see Free_Fonts.h for the fonts
  ttgo->tft->setTextColor(TFT_GREEN, TFT_BLACK); //setting text color, background color

  ttgo->tft->setTextDatum(ML_DATUM); //text is referenced by middle left
  
  ttgo->tft->fillScreen(TFT_BLACK);

  ttgo->tft->drawString("> reboot", 20, 74, GFXFF); //text, xpos, ypos, and font size (here since were are using Free_Fonts, put GFXFF
  ttgo->tft->drawString("> calculator", 20, 120, GFXFF);
  ttgo->tft->drawString("> stream", 20, 167, GFXFF);


  ttgo->tft->setTextDatum(MC_DATUM); //text is referenced by middle center

  
  drawUpArrow(&FreeMono9pt7b, ML_DATUM);

  drawHome(TFT_GREEN, &FreeMono9pt7b, ML_DATUM);
 //**********************************************************************************************************************************************DRAWING OUT MENU
  int counter = 0;
  button = 0; //resetting everything from previous states
  x = -1;
  y = -1;

  delay (500);

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
     else if (touchUpArrow(x, y)){//if up arrow is clicked
      button = 4;
      break;
    }
    else if (touchHome (x, y)){ //if home button is clicked
      button = 5;
      break;
    }
  }

  if (button == 1){
    x = -1;
    y = -1;
    ttgo->tft->fillScreen(TFT_BLACK);
    drawHome(TFT_RED, &FreeMono12pt7b, MC_DATUM);
    ttgo->tft->drawString("REBOOT", 120, 120, GFXFF);
    delay(500);
    while(1){
      ttgo->getTouch(x, y);
      if ((70 <= x) && (x <= 170) && (70 <= y) && (y < 170)){
        ttgo->tft->fillScreen(TFT_BLACK);
        ESP.restart();
      }
      else if (touchHome(x,y)){
        button = 4;
        break;
      }
    }
  }
  else if (button == 2){
    ttgo->tft->fillScreen(TFT_BLACK);
    calculator();
  }
  else if (button == 3){
    streammulticore();
  }
  else if (button == 4){
    mainMenu1();
  }
  else if (button == 5){
    mainMenu1();
  }
    
}
