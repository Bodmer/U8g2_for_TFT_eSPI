/*

  Unicode.ino

  Demonstrates how to connect U8g2 fonts to TFT_eSPI library.

  U8g2_for_TFT_eSPI:
    - Use U8g2 fonts with TFT_eSPI
    - Supports UTF-8 in print statement
    - 90, 180 and 270 degree text direction
  
  List of all U8g2 fonts:    https://github.com/olikraus/u8g2/wiki/fntlistall

  TFT_eSPI library:          https://github.com/Bodmer/TFT_eSPI
  U8g2_for_TFT_eSPI library: https://github.com/Bodmer/U8g2_for_TFT_eSPI

*/
#include <SPI.h>
#include <TFT_eSPI.h>
#include <U8g2_for_TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();   // tft instance
U8g2_for_TFT_eSPI u8f;       // U8g2 font instance

void setup() {
  tft.begin();
  u8f.begin(tft);                     // connect u8g2 procedures to TFT_eSPI
}

void loop() {  
  tft.fillScreen(TFT_BLACK);          // clear the graphics buffer  

  u8f.setFontDirection(0);            // left to right (this is default)
  u8f.setForegroundColor(TFT_WHITE);  // apply color

  u8f.setFont(u8g2_font_siji_t_6x10); // icon font
  u8f.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8f.drawGlyph( 0, 10, 0x0e200);     // Power Supply
  u8f.drawGlyph(12, 10, 0x0e201);     // Charging
  u8f.drawGlyph(24, 10, 0x0e10a);     // Right Arrow
  u8f.drawGlyph(36, 10, 0x0e24b);     // full Battery

  u8f.setFont(u8g2_font_7x13_te);     // extended font
  u8f.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8f.setCursor(0,40);                // start writing at this position
  u8f.print("<Ȧǀʘ>");                 // UTF-8 string: "<" 550 448 664 ">"

  while(1) delay(2000);
} 

