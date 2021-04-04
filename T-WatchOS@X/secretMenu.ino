void secretMenu(){

  //**********************************************************************************************************************************************DRAWING OUT MENU

  ttgo->tft->setFreeFont(&FreeMono9pt7b); //setting font, see Free_Fonts.h for the fonts
  ttgo->tft->setTextColor(TFT_RED, TFT_BLACK); //setting text color, background color

  ttgo->tft->setTextDatum(ML_DATUM); //text is referenced by middle left
  
  ttgo->tft->fillScreen(TFT_BLACK);

  ttgo->tft->drawString("> placeholder", 20, 74, GFXFF); //text, xpos, ypos, and font size (here since were are using Free_Fonts, put GFXFF
  ttgo->tft->drawString("> placeholder", 20, 120, GFXFF);
  ttgo->tft->drawString("> placeholder", 20, 167, GFXFF);


  ttgo->tft->setTextDatum(MC_DATUM); //text is referenced by middle center

  
  //drawUpArrow(&FreeMono9pt7b, ML_DATUM);

  drawHome(TFT_RED, &FreeMono9pt7b, ML_DATUM);
 //**********************************************************************************************************************************************DRAWING OUT MENU

  button = 0; //resetting everything from previous states
  x = -1;
  y = -1;

  delay (500);

  WiFi.mode(WIFI_AP);
  delay(1000);

  while (1) {
  
    ttgo->getTouch(x,y); //write touch coordinates to x and y variables (which were declared globally)
    
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
    else if (touchHome (x, y)){ //if home button is clicked
      button = 5;
      break;
    }
  }

  if (button == 1){
    placeholder();
  }
  else if (button == 2){
    placeholder();
  }
  else if (button == 3){
    placeholder();
  }
  else if (button == 4){
    mainMenu1();
  }
  else if (button == 5){
    mainMenu1();
  }
    
}
