#define PIR A0

volatile byte count;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  count = 0;

  attachInterrupt(PIR, movementDetected, RISING);
}

void loop() {
  for (byte i = 0; i < count; i++) {
    notify();
  }

  delay(1000);
}

void movementDetected() {
  count++;
}

void notify() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}

