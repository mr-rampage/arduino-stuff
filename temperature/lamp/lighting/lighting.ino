#include <Adafruit_NeoPixel.h>

#define PIN 9

Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, PIN,  NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
  strip.setBrightness(8);
  strip.setPixelColor(0, strip.Color(255, 255, 255));
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:

}
