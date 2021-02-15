#include <Adafruit_NeoPixel.h>
#include "frames.h"
Adafruit_NeoPixel strip(64, 6);
int colors [2][3]{
  {0, 0, 0},
  {0, 0, 255},
};
int whichFrame = 0;
void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(20);

}

void loop() {
  
  for(int i = 0; i < strip.numPixels(); i++){
    int pixAddress = i;
    int whichColor = animation[whichFrame][i];
    int red = colors[whichColor][0];
    int green = colors[whichColor][1];
    int blue = colors[whichColor][2];
    if(pixAddress != -1){
      strip.setPixelColor(pixAddress, red, green, blue);
    }
  }
  strip.show();
  delay(500);
  whichFrame = (whichFrame +1) % 5;

}
