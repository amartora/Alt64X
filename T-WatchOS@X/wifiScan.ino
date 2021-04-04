//#include "WiFi.h"

String bullet [50]; 

void wifiScanOne (String bullet [50], int g);

void wifiScanTwo (String bullet [50], int g);

void wifiScanThree (String bullet [50], int g);

void wifiScanFour (String bullet [50], int g);

void wifiScanFive (String bullet [50], int g);

void wifiScanSix (String bullet [50], int g);

void wifiScanSeven (String bullet [50], int g);

void wifiScanEight (String bullet [50], int g);

void wifiScanNine (String bullet [50], int g);

void wifiScanTen (String bullet [50], int g);



void wifiScan (){

//WiFi.mode(WIFI_STA); //seems like I have to make sure all SPI functions happen after my WiFi stuff, or else ESP crashes
  WiFi.disconnect();
  delay(100);

//  WiFi.mode(WIFI_STA);
//  WiFi.disconnect();
//  delay(100);



  button = 0; //resetting everything from previous states
  x = -1;
  y = -1;

 

  
  
  ttgo->tft->fillScreen(TFT_BLACK);
  drawHome(TFT_RED, &FreeMono12pt7b, MC_DATUM);

  ttgo->tft->drawString("SCAN", 120, 120, GFXFF);
  
  delay (500);
  
  while (1){

    ttgo->getTouch(x,y); //write touch coordinates to x and y variables (which were declared globally)


    if ((70 <= x) && (x <= 170) && (70 <= y) && (y < 170)){
        button = 1;
        ttgo->tft->fillScreen(TFT_BLACK);
        ttgo->tft->drawString("SCANNING...", 120, 120, GFXFF);
        break;
    }
    
    else if (touchHome (x, y)){
        button = 4;
        break;
    }
  }


  if (button == 4){
      mainMenu1();
  }
  
  else if (button == 1){
    
    

    int n = WiFi.scanNetworks();

    for (int i = 0; i < 50; ++i) {//------------------------------------initial print of reults to an array of strings

      int number = i + 1;
        
      if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN){
        bullet [i] = String(number) + ": " + WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ")*";
        delay(10);
      }
      else{
        bullet [i] = String(number) + ": " + WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ")";
        delay(10);
      }
       
    }//------------------------------------initial print of reults to an array of strings

    ttgo->tft->fillScreen(TFT_BLACK);
    
    drawHome(65520, &FreeMono9pt7b, ML_DATUM);
    
    //ttgo->tft->setCursor(0, 40);

    if (n == 0) {
      ttgo->tft->setTextDatum(MC_DATUM);
      ttgo->tft->drawString("no networks found", 120, 120, GFXFF);
    }
//--------------------------------------------------------------------------------------------------------------------------focus here if networks are found
    else{
      int g = 50;
      firstpage:

        g = 5;
        if(n <= 5){
          g = n;
        }
        wifiScanOne(bullet, g);
        if(n > 5){//draw down arrow if there are more than 5
          drawDownArrow(&FreeMono9pt7b, ML_DATUM);
        }
        delay(500);
  
        while(1){
          ttgo->getTouch(x,y);
          if (touchDownArrow(x, y) && (n > 5)){//if down arrow is pressed
            button = 2;
            break;
          }
          else if (touchHome (x, y)){ //if home button is clicked
            goto exitapp;
          }
        }
        if (button == 2){
          secondpage:

            
            g = 10;
            if(n <= 10){
              g = n;
            }
            wifiScanTwo(bullet, g);
            if(n > 10){//draw down arrow if there are more than 10
              drawDownArrow(&FreeMono9pt7b, ML_DATUM);
            }
            delay(500);
            while(1){
              
              ttgo->getTouch(x,y);
              if (touchDownArrow(x, y) && (n > 10)){//if down arrow is pressed
                goto thirdpage;
              }
              else if (touchUpArrow(x, y)){//if up arrow is clicked
                goto firstpage;
                break;
              }
              else if (touchHome (x, y)){ //if home button is clicked
                goto exitapp;
              }
            }
        }
        else if (button == 3){
          thirdpage:
            g = 15;
            if(n <= 15){
              g = n;
            }
            wifiScanThree(bullet, g);
            if(n > 15){//draw down arrow if there are more than 15
              drawDownArrow(&FreeMono9pt7b, ML_DATUM);
            }
            delay(500);
            while(1){
              ttgo->getTouch(x,y);
              if (touchDownArrow(x, y) && (n > 15)){//if down arrow is pressed
                goto fourthpage;
              }
              else if (touchUpArrow(x, y)){//if up arrow is clicked
                goto secondpage;
                break;
              }
              else if (touchHome (x, y)){ //if home button is clicked
                goto exitapp;
              }
            }
        }
        else if (button == 4){
          fourthpage:
            g = 20;
            if(n <= 20){
              g = n;
            }
            wifiScanFour(bullet, g);
            if(n > 20){//draw down arrow if there are more than 20
              drawDownArrow(&FreeMono9pt7b, ML_DATUM);
            }
            delay(500);
            while(1){
              ttgo->getTouch(x,y);
              if (touchDownArrow(x, y) && (n > 20)){//if down arrow is pressed
                goto fifthpage;
              }
              else if (touchUpArrow(x, y)){//if up arrow is clicked
                goto thirdpage;
                break;
              }
              else if (touchHome (x, y)){ //if home button is clicked
                goto exitapp;
              }
            }
        }
        else if (button == 5){
          fifthpage:
            g = 25;
            if(n <= 25){
              g = n;
            }
            wifiScanFive(bullet, g);
            if(n > 25){//draw down arrow if there are more than 25
              drawDownArrow(&FreeMono9pt7b, ML_DATUM);
            }
            delay(500);
            while(1){
              ttgo->getTouch(x,y);
              if (touchDownArrow(x, y) && (n > 25)){//if down arrow is pressed
                goto sixthpage;
              }
              else if (touchUpArrow(x, y)){//if up arrow is clicked
                goto fourthpage;
                break;
              }
              else if (touchHome (x, y)){ //if home button is clicked
                goto exitapp;
              }
            }
        }
        else if (button == 6){
          sixthpage:
            g = 30;
            if(n <= 30){
              g = n;
            }
            wifiScanSix(bullet, g);
            if(n > 30){//draw down arrow if there are more than 30
              drawDownArrow(&FreeMono9pt7b, ML_DATUM);
            }
            delay(500);
            while(1){
              ttgo->getTouch(x,y);
              if (touchDownArrow(x, y) && (n > 30)){//if down arrow is pressed
                goto seventhpage;
              }
              else if (touchUpArrow(x, y)){//if up arrow is clicked
                goto fifthpage;
                break;
              }
              else if (touchHome (x, y)){ //if home button is clicked
                goto exitapp;
              }
            }
        }
        else if (button == 7){
          seventhpage:
            g = 35;
            if(n <= 35){
              g = n;
            }
            wifiScanSeven(bullet, g);
            if(n > 35){//draw down arrow if there are more than 35
              drawDownArrow(&FreeMono9pt7b, ML_DATUM);
            }
            delay(500);
            while(1){
              ttgo->getTouch(x,y);
              if (touchDownArrow(x, y) && (n > 35)){//if down arrow is pressed
                goto eighthpage;
              }
              else if (touchUpArrow(x, y)){//if up arrow is clicked
                goto sixthpage;
                break;
              }
              else if (touchHome (x, y)){ //if home button is clicked
                goto exitapp;
              }
            }
        }
        else if (button == 8){
          eighthpage:
            g = 40;
            if(n <= 40){
              g = n;
            }
            wifiScanEight(bullet, g);
            if(n > 40){//draw down arrow if there are more than 40
              drawDownArrow(&FreeMono9pt7b, ML_DATUM);
            }
            delay(500);
            while(1){
              ttgo->getTouch(x,y);
              if (touchDownArrow(x, y) && (n > 40)){//if down arrow is pressed
                goto ninthpage;
              }
              else if (touchUpArrow(x, y)){//if up arrow is clicked
                goto seventhpage;
                break;
              }
              else if (touchHome (x, y)){ //if home button is clicked
                goto exitapp;
              }
            }
        }
        else if (button == 9){
         ninthpage:
            g = 45;
            if(n <= 45){
              g = n;
            }
            wifiScanNine(bullet, g);
            if(n > 45){//draw down arrow if there are more than 45
              drawDownArrow(&FreeMono9pt7b, ML_DATUM);
            }
            delay(500);
            while(1){
              ttgo->getTouch(x,y);
              if (touchDownArrow(x, y) && (n > 45)){//if down arrow is pressed
                goto tenthpage;
              }
              else if (touchUpArrow(x, y)){//if up arrow is clicked
                goto eighthpage;
                break;
              }
              else if (touchHome (x, y)){ //if home button is clicked
                goto exitapp;
              }
            }
        }
        else if (button == 10){
         tenthpage:
            g = 50;
              if(n <= 50){
                g = n;
            }
            wifiScanTen(bullet, g);
            
            while(1){
              ttgo->getTouch(x,y);
           
              if (touchUpArrow(x, y)){//if up arrow is clicked
                goto ninthpage;
                break;
              }
              else if (touchHome (x, y)){ //if home button is clicked
                goto exitapp;
              }
            }
        }
    
    
    }
//--------------------------------------------------------------------------------------------------------------------------focus here if networks are found
  
 
  }
       
        
  exitapp:
    button = 0; 
   
        
      

     
  


  
}
