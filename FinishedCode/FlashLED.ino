// init pins
uint8_t* port = &PORTH;
const uint8_t LEDPin1 = 6;
const uint8_t LEDPin2 = 10;

void setup() {
  // put your setup code here, to run once:
  // pinMode(LEDPin1, OUTPUT);
  DDRH |= 1 << LEDPin1;
  pinMode(LEDPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read, modify, write example
  *port |= 1 << LEDPin1;
  delay(100);
  *port &= ~(1 << LEDPin1);

  // digital write example
  digitalWrite(LEDPin2, HIGH);
  delay(100);
  digitalWrite(LEDPin2, LOW);

}
