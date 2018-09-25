#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <elapsedMillis.h>
#include <Adafruit_SleepyDog.h>

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
elapsedMillis timeElapsed;

#define VOLUME A0

int volumeReading = 0;
const int VOLUME_STEPS = 34;
const long DURATION = 7200000;

void setup()
{
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(30);
  myDFPlayer.enableLoopAll();
}

void loop()
{
  if (timeElapsed > DURATION) {
    myDFPlayer.disableLoopAll();
    Watchdog.sleep();
  } else {
    volumeReading = analogRead(VOLUME);
    myDFPlayer.volume(volumeReading / VOLUME_STEPS);
    delay(1000);
  }
}
