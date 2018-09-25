/*
Adafruit Arduino - Lesson 10. Simple Sounds
*/

int speakerPin = A0;
int photocellPin = A1;
void setup()
{
}

void loop()
{
  int reading = analogRead(photocellPin);
  Serial.println(reading);
  int pitch = reading / 4;
  tone(speakerPin, pitch);
  delay(250);
}
