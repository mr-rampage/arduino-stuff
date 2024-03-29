/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int pirValue = LOW;
int pirPin = A0;

int alarmDelay = 0;
int alarmState = 0;

int timer1_counter;
 
//uncomment this line if using a Common Anode LED
// #define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(pirPin, INPUT);

  cli(); // stop interrupts
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // set compare match register for 0.25 Hz increments
  OCR1A = 62499; // = 16000000 / (1024 * 0.25) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (0 << CS11) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); // allow interrupts
}

ISR(TIMER1_COMPA_vect)        // interrupt service routine 
{
  alarmState = ++alarmState % 3;
}
 
void loop()
{

  if (alarmState == 0) {
    setColor(0, 255, 0);
  } else if (alarmState == 1) {
    setColor(80, 0, 80);
  } else {
    pirValue = digitalRead(pirPin);
  
    if (pirValue == HIGH) {
      setColor(255, 0, 0);  // red
    } else {
      setColor(80, 0, 80);
    }
  }

  delay(1000);
}
 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}                                                                                                                                                                                                                                                                                                                                                                                       
