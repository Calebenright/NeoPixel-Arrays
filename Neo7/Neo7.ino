#include <Adafruit_NeoPixel.h>
#include "frames.h"
Adafruit_NeoPixel strip(64, 6);
int colors[2][3]{
  {255, 50, 50},
  {0, 0, 255},
};
int whichFrame = 0;
int pixAddress;
int switchVal = 1;
void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(20);
}

void loop() {
  for(int i = 0; i < strip.numPixels(); i++){
    if (i%4 == 0){
      switchVal = (switchVal + 1) % 2;
    }
    if (switchVal == 0){
      pixAddress =  i*2;
    } else {
      pixAddress =  i*2+1;
    }
    int whichColor = 0;
    int red = colors[whichColor][0];
    int green = colors[whichColor][1];
    int blue = colors[whichColor][2];
      if(pixAddress != -1){
       strip.setPixelColor(pixAddress, red, green, blue);
      }
    }
  
  strip.show();
//  whichFrame = (whichFrame +1) % 2;
}