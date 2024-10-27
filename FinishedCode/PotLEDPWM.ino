int potPin = A0;     // analog input pin A0
int ledPin = 9;      // digital output pin 9
int PWM = 0;  // current brightness of the LED
int time = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  // set the LED pin as output
}

void loop() {
  int potVal = analogRead(potPin);            // read the potentiometer value (0-1023)
  PWM = map(potVal, 0, 1023, 0, 900);  // map the potentiometer value to 0-900

  // PWM
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(PWM);
  // delay(PWM);
  digitalWrite(ledPin, LOW);
  delayMicroseconds(1000 - PWM);
  // delay(1000 - PWM);
  
}





