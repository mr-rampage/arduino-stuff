#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_FXOS8700.h>
#include <Mouse.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_FXOS8700 accelmag = Adafruit_FXOS8700(0x8700A, 0x8700B);
sensors_event_t aevent;

void setup(void)
{
  Mouse.begin();
}

void loop(void)
{
  accelmag.getEvent(&aevent);
  Mouse.move((int)aevent.acceleration.y, (int)aevent.acceleration.x, 0);
}
