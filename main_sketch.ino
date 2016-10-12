#include <Servo.h>

Servo rightServo;
Servo leftServo;
long distance;
long time_in;

void setup() {
  Serial.begin(9600);
  rightServo.attach(2);
  leftServo.attach(3);

  pinMode(9, OUTPUT);
  pinMode(8, INPUT);
  
  rightServo.write(90);
  leftServo.write(90);
}

void loop() {

  digitalWrite(9, LOW);
  delayMicroseconds(5);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);

  time_in = pulseIn(8, HIGH);
  distance = int(0.017 * time_in); //Transform to cm
  Serial.println("Distance ");
  Serial.println(distance);
  Serial.println("cm");

  if(distance > 50){
    turn();
  } else {
    push();
  }
  delay(1000);
}

void turn(){
  rightServo.write(180);
  leftServo.write(180);
}

void push(){
  rightServo.write(0);
  leftServo.write(180);
}
