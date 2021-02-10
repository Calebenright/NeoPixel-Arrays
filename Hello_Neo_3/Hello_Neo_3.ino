#include <Adafruit_NeoPixel.h>
#include "frames.h"
Adafruit_NeoPixel strip(64, 6);
int colors [4][3]{
  {0, 0, 0},
  {0, 0, 255},
  {0, 255, 0},
  {255, 0, 0},
};
int whichFrame = 0;
void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(50);

}

void loop() {
  
  for(int i = 0; i < strip.numPixels(); i++){
    int pixAddress = pixelMap[i];
    int whichColor = [whichFrame][i];
    int red = color[whichColor][0];
    int green = color[whichColor][1];
    int blue = color[whichColor][2];
    if(pixAddress != -1){
      strip.setPixelColor(pixAddress, red, green, blue);
    }
  }
  strip.show();
  delay(500);
  whichFrame = (whichFrame +1) % 2

}
