/*
AET Mulan Enclosure
Team Name: FairyTale Folks 
Team Members: Schuyler and Kelly
Description: button and servo program
*/

// Servo Code Library
#include<Servo.h>;

// Variables
Servo myServo;
const int buttonPin = 7;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(buttonPin, INPUT)
}

void loop() {
  // put your main code here, to run repeatedly:

}
