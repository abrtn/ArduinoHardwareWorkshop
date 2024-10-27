#include <Servo.h>

Servo rulerServo;

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;
float pos = 45;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  rulerServo.write(pos);
  rulerServo.attach(11);
  Serial.begin(9600);
}

void loop() {

}





