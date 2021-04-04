#include "lvgl/lvgl.h" //image-displaying library

LV_IMG_DECLARE(dog);

LV_IMG_DECLARE(buddy);

void pictures(){

  
  
  lv_obj_t *img1 = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(img1, &dog);
  lv_obj_align(img1, NULL, LV_ALIGN_CENTER, 0, 0);
  
  delay(500);
  x = -1;
  y = -1;
  
  lv_task_handler();//I believe this pushes all the lvgl stuff to the display, you could also put this in the while loop below
  
  while (1){
    
    ttgo->getTouch(x,y);
    if (touchHome(x, y)){
      ttgo->tft->fillScreen(TFT_BLACK);
      break;
    }
    if ((200 <= x) && (x <= 240) && (0 <= y) && (y <= 240)){
      lv_obj_t *img2 = lv_img_create(lv_scr_act(), NULL);
      lv_img_set_src(img2, &buddy);
      lv_obj_align(img2, NULL, LV_ALIGN_CENTER, 0, 0);
      lv_task_handler();
    }
 }
 
}
