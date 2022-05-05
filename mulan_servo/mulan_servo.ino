#include <Servo.h>
/*
   Pour Tea w servo
   Stretch goal: increment pouring
*/
// CONSTANTS
const int teaSWITCHPIN = 7;
const int teaSERVOPIN = 8;

// VARIABLES
int teaValue;
int staySpinned = 0;
Servo teaServo;

void setup() {
  // put your setup code here, to run once:
  teaServo.attach(teaSERVOPIN);
  teaServo.write(0);
  pinMode(teaSWITCHPIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  teaValue = digitalRead(teaSWITCHPIN);
  if (teaValue == HIGH || staySpinned == 1) {
    teaServo.write(180);
  } else {
    teaServo.write(0);
  }
}
