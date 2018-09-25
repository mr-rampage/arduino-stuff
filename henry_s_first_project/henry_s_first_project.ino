int LIGHT_PIN = A0;

void setup() {
  pinMode(LIGHT_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LIGHT_PIN, HIGH);
}
