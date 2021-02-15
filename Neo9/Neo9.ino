#include <Adafruit_NeoPixel.h>
#include "frames.h"
Adafruit_NeoPixel strip(64, 6);
void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(20);
}

void loop() {
 for(uint16_t c=0; c<256; c++) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+c) & 255));
    }
    strip.show();
    delay(10);
  }
}
// copied from dicumentation
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
