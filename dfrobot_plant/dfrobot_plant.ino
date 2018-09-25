#include <Adafruit_NeoPixel.h>
#include <math.h>

#define LED_DIN A2
#define NUMPIXELS      1


Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LED_DIN,  NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  setAllToPlantLovingColor(1023);
  strip.show();

  delay(1000);
}

void setAllToPlantLovingColor(uint16_t brightness) {
  for(int i=0;i<NUMPIXELS;i++){
    setPixelColor(i, 191, 0, 63, brightness);
  }
}

void setPixelColor( uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint16_t brightness) {
   strip.setPixelColor(n, (brightness*r/255) , (brightness*g/255), (brightness*b/255));
}
