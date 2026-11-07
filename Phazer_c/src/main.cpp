#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


// put function declarations here:
int myFunction(int, int);


U8G2_SSD1306_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 46, /* reset=*/ 3);

void setup(void) {
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tr);
}


void draw(const char *s)
{
  u8g2.firstPage();
  do {
    u8g2.drawStr(2,15,"Hello World!");    
    u8g2.drawStr(2,30,s);    

    u8g2.drawStr(2, 45, u8x8_u16toa(u8g2.getDisplayWidth(), 5));
    u8g2.drawStr(2, 60, u8x8_u16toa(u8g2.getDisplayHeight(), 5));

    u8g2.drawFrame(0,0,u8g2.getDisplayWidth(),u8g2.getDisplayHeight() );

  } while ( u8g2.nextPage() );
  delay(2000);
}


void loop(void) {

  u8g2.clearDisplay();
  u8g2.setDisplayRotation(U8G2_R0);
  u8g2.setFlipMode(0);
  draw("R0,F0");
  u8g2.clearDisplay();
  u8g2.setFlipMode(1);
  draw("R0,F1");

  u8g2.clearDisplay();
  u8g2.setDisplayRotation(U8G2_R1);
  u8g2.setFlipMode(0);
  draw("R1,F0");
  u8g2.clearDisplay();
  u8g2.setFlipMode(1);
  draw("R1,F1");

  u8g2.clearDisplay();
  u8g2.setDisplayRotation(U8G2_R2);
  u8g2.setFlipMode(0);
  draw("R2,F0");
  u8g2.clearDisplay();
  u8g2.setFlipMode(1);
  draw("R2,F1");

  u8g2.clearDisplay();
  u8g2.setDisplayRotation(U8G2_R3);
  u8g2.setFlipMode(0);
  draw("R3,F0");
  u8g2.clearDisplay();
  u8g2.setFlipMode(1);
  draw("R3,F1");

}