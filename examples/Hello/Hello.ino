/*
  Hello.ino

  Demonstrates how to use U8g2_for_TFT_eSPI library.

  U8g2_for_TFT_eSPI:
    - Use U8g2 fonts with TFT_eSPI
    - Supports UTF-8 in print statement
    - 90, 180 and 270 degree text direction
  
  List of all U8g2 fonts:    https://github.com/olikraus/u8g2/wiki/fntlistall

  TFT_eSPI library:          https://github.com/Bodmer/TFT_eSPI
  U8g2_for_TFT_eSPI library: https://github.com/Bodmer/U8g2_for_TFT_eSPI

*/
#include "SPI.h"
#include "TFT_eSPI.h"
#include "U8g2_for_TFT_eSPI.h"

TFT_eSPI tft = TFT_eSPI();   // tft instance
U8g2_for_TFT_eSPI u8f;       // U8g2 font instance

void setup() {
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  u8f.begin(tft);                     // connect u8g2 procedures to TFT_eSPI
}

unsigned long x = 0;

void loop() {
  u8f.setFontMode(0);                 // use u8g2 none transparent mode
  u8f.setFontDirection(0);            // left to right (this is default)
  u8f.setForegroundColor(TFT_WHITE);  // apply color

  u8f.setFont(u8g2_font_helvR14_tf);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8f.setCursor(0,20);                // start writing at this position
  u8f.print("Hello World");
  u8f.setCursor(0,40);                // start writing at this position
  u8f.print("Umlaut ÄÖÜ");            // UTF-8 string with german umlaut chars

  u8f.setFont(u8g2_font_inb63_mn);    // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8f.setFontMode(0);                 // use u8g2 none transparent mode

  while (1) {
    u8f.setCursor(0,110);             // start writing at this position
    u8f.print(x);                     // numerical value
    x++;
    delay(250);
  }
} 
