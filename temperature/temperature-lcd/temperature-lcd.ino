#include <LiquidCrystal.h>

LiquidCrystal lcd(6, 5, 9, 10, 11, 12);

byte degree[8] = {
  B01000, B10100, B01000, B00000,
  B00000, B00000, B00000, B00000,
};

const int sensorPin = A0;

void setup() {
  lcd.createChar(0, degree);
  lcd.begin(16, 2);
}

void loop() {
  float temperature = getTemperature(sensorPin);

  lcd.clear();
  displayTemperature(lcd, temperature);
  lcd.setCursor(0, 1);
  displayUptime(lcd, getUptimeInMinutes());
  delay(1000);
}

float getVoltageOnPin(int pin) {
  int reading = analogRead(pin);
  float voltage = (reading * 3.3) / 1024.0;
  return voltage;  
}

float getTemperature(int pin) {
  return (getVoltageOnPin(pin) - 0.5) * 100;
}

int getUptimeInMinutes() {
  return ((millis()/1000)/60);
}

void displayTemperature(LiquidCrystal lcd, float temperature) {
  float roundedTemperature = round(temperature);

  lcd.print("Currently ");
  lcd.print(roundedTemperature, 0);
  lcd.write(byte(0));
  lcd.print("C");
}

void displayUptime(LiquidCrystal lcd, int uptime) {
  lcd.print("Uptime ");
  lcd.print(uptime);
  lcd.print(" mins");
}

