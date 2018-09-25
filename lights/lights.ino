#include <Adafruit_NeoPixel.h>

#define PIN 9
#define NUMPIXELS      5

#define RED_PIN A1
#define GREEN_PIN A2
#define BLUE_PIN A3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN,  NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(RED_PIN, INPUT);
  pinMode(GREEN_PIN, INPUT);
  pinMode(BLUE_PIN, INPUT);
  
  strip.begin();
  strip.show();
}

void loop() {
  updateStrip(getColor());
  strip.show();
  delay(500);
  debugRGB();
  delay(200);
}

void debugRGB() {
  debugPin(RED_PIN);
  debugPin(GREEN_PIN);
  debugPin(BLUE_PIN);  
}

void debugPin(int pin) {
  Serial.print("Pin ");
  Serial.print(pin);
  Serial.print(" with reading ");
  Serial.println(getColorValue(pin));
}

int getColorValue(int pin) {
  delay(100);
  return analogRead(pin) >> 2;
}

uint32_t getColor() {
  return strip.Color(getColorValue(RED_PIN), getColorValue(GREEN_PIN), getColorValue(BLUE_PIN));
}

void updateStrip(uint32_t stripColor) {
  for(int i=0;i<NUMPIXELS;i++){
    strip.setPixelColor(i, stripColor);
  }
}

