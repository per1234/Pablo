/*
 * Handles the OLED display objects
 */

#include "Arduino.h"
#include "Pablo.h"

// See Fonts available here:
// https://github.com/olikraus/u8g2/wiki/fntlistall 

void Pablo::setupDisplay(){

  OLEDScreen = new U8G2_SSD1306_128X64_NONAME_F_HW_I2C(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

  // Initialise the OLED display
  OLEDScreen -> begin();

  OLEDScreen -> clearBuffer();

  OLEDScreen -> setFont(u8g2_font_fub25_tr);
  OLEDScreen -> drawStr(18,35,"Pablo");
  OLEDScreen -> setFont(u8g2_font_etl14thai_t);
  OLEDScreen -> drawStr(35,55,"Hello :)");

  OLEDScreen -> sendBuffer();

  delay(1000);

}

/*
 *
 *  SCREEN HANDLING
 *
 */
char buf[20];
void Pablo::report() {

  OLEDScreen -> clearBuffer();

  OLEDScreen -> setFont(u8g2_font_6x12_tr);

  OLEDScreen -> drawStr(36,10,"< speed >");
  OLEDScreen -> drawStr(38,28,"  dist  ");
  OLEDScreen -> drawStr(39,38,"/      \\");
  
  OLEDScreen -> setFont(u8g2_font_profont10_mf);
  OLEDScreen -> drawStr(50,38,"+");
  sprintf (buf, "%d", rotary_increment);
  OLEDScreen -> drawStr(55,38, buf );

  OLEDScreen -> setFont(u8g2_font_profont22_mn);
  
  sprintf (buf, "%d", setting_right_wheel_distance);
  OLEDScreen -> drawStr(66, 60, buf) ;
  sprintf (buf, "%d", setting_right_wheel_speed);
  OLEDScreen -> drawStr(103, 17, buf) ;
  sprintf (buf, "%d", setting_left_wheel_speed);
  OLEDScreen -> drawStr(3, 17, buf) ;
  sprintf (buf, "%d", setting_left_wheel_distance);
  OLEDScreen  -> drawStr(3, 60, buf) ;

  // mat working on mouse over for 1 encoder
  if (rotaryMode == 0) {
    OLEDScreen  -> drawFrame(64, 43, 63, 20);

  } else if (rotaryMode == 1) {
    OLEDScreen  -> drawFrame(100,0, 28, 20);

  } else if (rotaryMode == 2) {
    OLEDScreen  -> drawFrame(0,0,28,20);

  } else if (rotaryMode == 3) {
    OLEDScreen  -> drawFrame(0, 43 , 63, 20);
  }

  OLEDScreen -> sendBuffer();
}

void Pablo::message(String text) {

  OLEDScreen -> clearBuffer();
  OLEDScreen -> setFont(u8g2_font_profont12_mf);
  text.toCharArray(buf, 20);
  OLEDScreen -> drawStr(20,30, buf); //this copies some text to the screens memory
  OLEDScreen -> sendBuffer();

}

void Pablo::messageLarge(String text) {
 
  OLEDScreen -> clearBuffer();
  OLEDScreen -> setFont(u8g2_font_fub25_tr);
  text.toCharArray(buf, 20);
  OLEDScreen -> drawStr(10, 40, buf); //this copies some text to the screens memory
  OLEDScreen -> sendBuffer();

}

void Pablo::message(int text) {

  OLEDScreen -> clearBuffer();
  OLEDScreen -> setFont(u8g2_font_profont12_mf);
  sprintf (buf, "%d", text);
  OLEDScreen -> drawStr(30,30, buf); //this copies some text to the screens memory
  OLEDScreen -> sendBuffer();

}

void Pablo::displayStartMessage() {
  displayCountDown(3);
  delay(1000);
  displayCountDown(2);
  delay(1000);
  displayCountDown(1);
  delay(1000);

  /*
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(4);
  OLEDScreen.setCursor(40, 20);
  OLEDScreen.print(":)"); //this copies some text to the screens memory

  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(0, 0);
  OLEDScreen.print(setting_left_wheel_speed); //this copies some text to the screens memory
  OLEDScreen.setCursor(110, 0);
  OLEDScreen.print(setting_right_wheel_speed); //this copies some text to the screens memory

  OLEDScreen.setCursor(0, 50);
  OLEDScreen.print(setting_left_wheel_distance); //this copies some text to the screens memory

  OLEDScreen.setCursor(110, 50);
  OLEDScreen.print(setting_right_wheel_distance); //this copies some text to the screens memory

  OLEDScreen.display();
  */
}

void Pablo::displayCountDown(int count) {
  /*
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(2);
  OLEDScreen.setCursor(10 , 5);
  OLEDScreen.print("STEP BACK");

  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(10 , 40);
  OLEDScreen.print("Starting in: "); //this copies some text to the screens memory

  OLEDScreen.setTextSize(4);
  OLEDScreen.setCursor(94 , 30);
  OLEDScreen.print(count); //this copies some text to the screens memory
  OLEDScreen.display();
  */
}

