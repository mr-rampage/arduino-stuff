#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

#define BUSY A0

DFRobotDFPlayerMini myDFPlayer;

void setup()
{
  Serial1.begin(9600);

  myDFPlayer.begin(Serial1);
  
  myDFPlayer.volume(15);  //Set volume value. From 0 to 30

  myDFPlayer.play(1);

  attachInterrupt(BUSY, isr, RISING);
}

void loop() {
}

void isr() {
  myDFPlayer.next();
}

