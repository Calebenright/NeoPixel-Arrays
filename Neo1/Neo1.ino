#include <Adafruit_NeoPixel.h>
#include "frames.h"
Adafruit_NeoPixel strip(64, 6);
int colors [4][3]{
  {255, 255, 255},
  {0, 0, 255},
  {0, 255, 0},
  {255, 0, 0},
};
int whichFrame = 0;
void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(30);

}

void loop() {
  
  for(int i = 0; i < strip.numPixels(); i++){
    int pixAddress = pixelMap[i];
    if(pixAddress != -1){
      strip.setPixelColor(pixAddress, 255, 255, 255);
    }
  }
  strip.show();
  delay(500);

}
