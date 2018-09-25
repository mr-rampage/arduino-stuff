#include <Adafruit_NeoPixel.h>
#include <math.h>

#define LED_DIN A2
#define NUMPIXELS      30
#define BRIGHTNESS_PIN   A0

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LED_DIN,  NEO_GRB + NEO_KHZ800);
int MAX_LIGHT = 1023;
int brightness [2] = {0, 0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  strip.begin();
}

void loop() {
  brightness[1] = getBrightnessReading();

  if (hasBrightnessChanged()) {
    setAllToPlantLovingColor(brightness[1]);
    strip.show();
  }
  
  delay(1000);
  brightness[0] = brightness[1];
}

bool hasBrightnessChanged() {
  return brightness[0] == brightness[1];
}

void setAllToPlantLovingColor(uint16_t brightness) {
  for(int i=0;i<NUMPIXELS;i++){
    setPixelColor(i, 191, 0, 63, brightness);
  }
}

uint16_t getBrightnessReading() {
  int reading = analogRead(BRIGHTNESS_PIN);
  return round((1.0 - (float)reading/(float)MAX_LIGHT) * 255.0);
}

void setPixelColor( uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint16_t brightness) {
   strip.setPixelColor(n, (brightness*r/255) , (brightness*g/255), (brightness*b/255));
}
