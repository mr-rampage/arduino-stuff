#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_FXOS8700.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_FXOS8700 accelmag = Adafruit_FXOS8700(0x8700A, 0x8700B);

LiquidCrystal lcd(6, 5, 9, 10, 11, 12);

void setup() {
  initializeAccelerometer();
  initializeDisplay();
}

void loop() {
  sensors_event_t aevent, mevent;
  accelmag.getEvent(&aevent, &mevent);
  displayAcceleration(aevent);
  delay(1000);
}

void initializeAccelerometer() {
  if(!accelmag.begin(ACCEL_RANGE_4G))
  {
    while(1);
  }  
}

void initializeDisplay() {
  lcd.begin(16, 2);  
}

void displayAcceleration(sensors_event_t aevent) {
  lcd.clear();
  lcd.print(aevent.acceleration.x);
  lcd.print(",");
  lcd.print(aevent.acceleration.y);
  lcd.print(",");
  lcd.print(aevent.acceleration.z);  
}

