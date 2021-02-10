#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(64, 6);
int colors [4][3]{
  {255, 0, 255},
  {0, 0, 255},
  {0, 255, 0},
  {255, 0, 0},
};

int fav = 0;

void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(50);

}

void loop() {
  for(int i = 0; i < strip.numPixels(); i++){
    int red = colors[fav][0];
    int green = colors[fav][1];
    int blue = colors[fav][2];
    strip.setPixelColor(i, red, green, blue);
  }
  strip.show();
  fav = (fav + 1) % 4;
  delay(300);
}
