#include <Servo.h>

Servo rulerServo;

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;
float targetDist = 10; // cm
float Kp = 1;
float error;
float pos = 45;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  rulerServo.write(pos);
  rulerServo.attach(11);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  
  error = distance - targetDist;
  pos += error*Kp;
  if(pos > 160){
    pos = 160;
  } else if(pos < 20){
    pos = 20;
  }
  rulerServo.write(pos);

  Serial.print("Error: ");
  Serial.println(error);
  delay(1000);

  if(abs(error) < 0.3){
    Serial.print("Terminated. Final Error: ");
    Serial.println(error);
    delay(100);
    exit(0);
  }

}






