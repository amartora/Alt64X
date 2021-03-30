AXP20X_Class *power;

void powerFunc(){

    x = -1;
    y = -1;

    power = ttgo->power;

    // ADC monitoring must be enabled to use the AXP202 monitoring function
    power->adc1Enable(AXP202_VBUS_VOL_ADC1 | AXP202_VBUS_CUR_ADC1 | AXP202_BATT_CUR_ADC1 | AXP202_BATT_VOL_ADC1, true);

    ttgo->tft->setFreeFont(&FreeMono9pt7b);
    ttgo->tft->setTextColor(TFT_GREEN, TFT_BLACK);

    drawHome(TFT_GREEN, &FreeMono9pt7b, ML_DATUM);

    delay (500);


  while(1){

      ttgo->tft->fillScreen(TFT_BLACK);
      drawHome(TFT_GREEN, &FreeMono9pt7b, ML_DATUM);
      ttgo->tft->setCursor(0, 50);
  
      ttgo->tft->print("VBUS: ");
      // You can use isVBUSPlug to check whether the USB connection is normal
      if (power->isVBUSPlug()) {
          ttgo->tft->println("CONNECTED");
  
          // Get USB voltage
          ttgo->tft->print("VBUS V:");
          ttgo->tft->print(power->getVbusVoltage());
          ttgo->tft->println(" mV");
  
          // Get USB current
          ttgo->tft->print("VBUS I: ");
          ttgo->tft->print(power->getVbusCurrent());
          ttgo->tft->println(" mA");
  
      } else {
  
          ttgo->tft->setTextColor(TFT_RED, TFT_BLACK);
          ttgo->tft->println("DISCONNECTED");
          ttgo->tft->setTextColor(TFT_GREEN, TFT_BLACK);
      }
  
      ttgo->tft->println();
  
      ttgo->tft->print("BATTERY: ");
      // You can use isBatteryConnect() to check whether the battery is connected properly
      if (power->isBatteryConnect()) {
          ttgo->tft->println("CONNECTED");
  
          // Get battery voltage
          ttgo->tft->print("BAT V:");
          ttgo->tft->print(power->getBattVoltage());
          ttgo->tft->println(" mV");
  
          // To display the charging status, you must first discharge the battery,
          // and it is impossible to read the full charge when it is fully charged
          if (power->isChargeing()) {
              ttgo->tft->print("Charge:");
              ttgo->tft->print(power->getBattChargeCurrent());
              ttgo->tft->println(" mA");
          } else {
              // Show current consumption
              ttgo->tft->print("Discharge:");
              ttgo->tft->print(power->getBattDischargeCurrent());
              ttgo->tft->println(" mA");
              ttgo->tft->print("Per: ");
              ttgo->tft->print(power->getBattPercentage());
              ttgo->tft->println(" %");
  
          }
      } else {
          ttgo->tft->setTextColor(TFT_RED, TFT_BLACK);
          ttgo->tft->println("DISCONNECTED");
          ttgo->tft->setTextColor(TFT_GREEN, TFT_BLACK);
      }
      //delay(1000);
    for(int c = 0; c < 1000; ++c){
      delay(1);
      ttgo->getTouch(x,y);
      if(touchHome(x,y)){
        goto exitPower;
      }
    }
    
  }
  exitPower:
  button = 0;
}
