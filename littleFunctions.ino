void drawHome(uint16_t lastColor, const GFXfont* lastFont, uint16_t lastDatum){

  ttgo->tft->setTextDatum(MC_DATUM);//text is referenced by middle center
  ttgo->tft->setFreeFont(&FreeMono12pt7b);
  ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);
  ttgo->tft->drawString("@X", 15, 15, GFXFF);

  ttgo->tft->setTextDatum(lastDatum);
  ttgo->tft->setFreeFont(lastFont);
  ttgo->tft->setTextColor(lastColor, TFT_BLACK);

}

void drawDownArrow(const GFXfont* lastFont, uint16_t lastDatum){
  
  ttgo->tft->setFreeFont(&FreeMono9pt7b); 
  ttgo->tft->setTextDatum(MC_DATUM); 
  
  ttgo->tft->drawString("v", 120, 210, GFXFF);

  ttgo->tft->setTextDatum(lastDatum);
  ttgo->tft->setFreeFont(lastFont);

}

void drawUpArrow(const GFXfont* lastFont, uint16_t lastDatum){
  
  ttgo->tft->setFreeFont(&FreeMono9pt7b); 
  ttgo->tft->setTextDatum(MC_DATUM); 
  
  ttgo->tft->drawString("^", 120, 30, GFXFF);

  ttgo->tft->setTextDatum(lastDatum);
  ttgo->tft->setFreeFont(lastFont);

}



bool touchHome (int x, int y){
  if ((0 <= x) && (x <= 69) && (0 <= y) && (y < 69)){
    return true;
  }
  else{
    return false;
  }
}



bool touchDownArrow (int x, int y){
  if ((70 <= x) && (x <= 170) && (190 <= y) && (y <= 240)){
    return true;
  }
  else{
    return false;
  }
}



bool touchUpArrow (int x, int y){
  if ((70 <= x) && (x <= 170) && (0 <= y) && (y <= 50)){
    return true;
  }
  else{
    return false;
  }
}

bool touchTopOption (int x, int y){
  if ((10 <= x) && (x <= 230) && (50 <= y) && (y < 97)){
    return true;
  }
  else{
    return false;
  }
}

bool touchMiddleOption (int x, int y){
  if ((10 <= x) && (x <= 230) && (97 <= y ) && (y < 143)){
    return true;
  }
  else{
    return false;
  }
}

bool touchBottomOption (int x, int y){
  if ((10 <= x) && (x <= 230) && (143 <= y) && (y < 190)){
    return true;
  }
  else{
    return false;
  }
}

void bootScreen(){
  int colorVal = 0;
  ttgo->tft->setFreeFont(&FreeMono9pt7b);
  //to use a straight uint16_t as a color, choose the color as an RGB 565 value from https://chrishewett.com/blog/true-rgb565-colour-picker/, then convert that hex to decimal (should then be a 5 digit number from 0000 to 65535), and enter it as uint16_t(DECIMAL) 
  ttgo->tft->setCursor(0,12);
  for (int f = 1; f < 138; ++f){
    colorVal = f * (65535/137);
    ttgo->tft->setTextColor(uint16_t(colorVal), TFT_BLACK); 
    ttgo->tft->print("@X");
  }

  
  ttgo->tft->setTextDatum(MC_DATUM);//text is referenced by middle center
  ttgo->tft->setFreeFont(&FreeMonoBold24pt7b);
  ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);
  ttgo->tft->drawString("@X", 120, 120, GFXFF);

  delay (500);
  
}
