/*

  Boxed_Text.ino

  Demonstrates how to draw a box around text.

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
  u8f.begin(tft);                     // connect u8g2 procedures to TFT_eSPI
}

void loop() {  
  const char s[] = "TFT_eSPI";
  /* width and height of the text */
  int16_t height;
  int16_t width;
  /* desired position of the text */
  int16_t x = 4;
  int16_t y = 25;
  tft.fillScreen(TFT_BLACK);          // clear the graphics buffer  
  u8f.setFont(u8g2_font_helvB14_tf);  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8f.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8f.setFontDirection(0);            // left to right (this is default)
  u8f.setForegroundColor(TFT_WHITE);  // apply color
  u8f.setCursor(x, y);                // start writing at this position
  u8f.print(s);
  /* calculate the size of the box into which the text will fit */
  height = u8f.getFontAscent() - u8f.getFontDescent();
  width = u8f.getUTF8Width(s);
  /* draw the box around the text with a margin*/
  tft.drawRect(x-2, y-u8f.getFontAscent()-2, width+4, height+4, TFT_RED);
  while(1) delay(2000);
}
