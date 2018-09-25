#define PIR 3
#define RELAY 13
#define FIVE_MINUTES 300000

volatile boolean startTimer = false;  
volatile boolean checkTimer = false;
unsigned long idleTime = 0;

void setup() {
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);

  pinMode(PIR, INPUT);
    
  attachInterrupt(digitalPinToInterrupt(PIR), onMotionChanged, CHANGE);
}

void loop() {
  if (startTimer == true) {
    idleTime = millis() + FIVE_MINUTES;
    startTimer = false;
    checkTimer = true;
  }
  
  if (checkTimer == true && millis() >= idleTime) {
    lightOff();
    checkTimer = false;
  }
}

void onMotionChanged() {
  checkTimer = false;

  if (digitalRead(PIR) == HIGH && digitalRead(RELAY) == LOW) {
    lightOn();  
  }

  if (digitalRead(PIR) == LOW && digitalRead(RELAY) == HIGH) {
    startTimer = true;
  }
}

void lightOn() {
  digitalWrite(RELAY, HIGH);
}

void lightOff() {
  digitalWrite(RELAY, LOW);
}
