// include the library code:
#include <LiquidCrystal.h>
#include <avr/sleep.h>
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(6, 5, 9, 10, 11, 12);


#define PIR_IRQ  1
#define ALARM    A0
#define PIR      2

volatile byte MOTION_COUNT = 0;
volatile int CURRENT_READING = LOW;
volatile int PREVIOUS_READING = LOW;

void setup() {
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Detection count");
  lcd.setCursor(0, 1);
  lcd.print(MOTION_COUNT);

  pinMode(ALARM, OUTPUT);
  pinMode(PIR, INPUT);
}
 
void loop() {
 goToSleep();
 delay(10000);
}

void motion_detect() {
  lcd.setCursor(0, 1);
  lcd.print(++MOTION_COUNT);

  digitalWrite(ALARM, HIGH);
}

void reset() {
  digitalWrite(ALARM, LOW);
}

void isr() {
  if (digitalRead(PIR) == HIGH) {
    motion_detect();
  } else {
    reset();
  }
}

void goToSleep() {  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  attachInterrupt(PIR_IRQ, isr, CHANGE);

  sleep_mode();
  sleep_disable();

  detachInterrupt(PIR_IRQ);
}

