//// i dont think think works because of the metal enclosure
//
//void halleffect(){
//
//  //**********************************************************************************************************************************************DRAWING
//  ttgo->tft->setFreeFont(&FreeMono9pt7b); //setting font, see Free_Fonts.h for the fonts
//  ttgo->tft->setTextColor(TFT_GREEN, TFT_BLACK); //setting text color, background color
//
//  ttgo->tft->setTextDatum(MC_DATUM); //text is referenced by middle center
//  
//  ttgo->tft->fillScreen(TFT_BLACK);
//
//  
//
//  drawHome(TFT_GREEN, &FreeMono9pt7b, MC_DATUM);
//  //**********************************************************************************************************************************************DRAWING
//
//  delay (500);
//  
//  button = 0; //resetting everything from previous states
//  x = -1;
//  y = -1;
//
//
// 
//
//  while (1){
//
//    drawHome(TFT_BLUE, &FreeMono12pt7b, MC_DATUM);
//
//    ttgo->tft->drawString(String(hallRead()), 120, 120, GFXFF);
//
//    ttgo->tft->fillScreen(TFT_BLACK);
//    
//    ttgo->getTouch(x,y); //write touch coordinates to x and y variables (which were declared globally)
//
//    
//    if (touchHome (x, y)){
//      button = 4;
//      break;
//    }
//    
//  }
//  
//  if (button == 4){
//    mainMenu1();
//  }
//  
//}
