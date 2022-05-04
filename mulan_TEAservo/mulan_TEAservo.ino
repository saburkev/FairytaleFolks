#include <Servo.h>
/*
   Pour Tea w servo  AND Spin Matchmaker
   Stretch goal: increment pouring
*/
// Tea spilling & Matchmsker spins
// CONSTANTS - for Tea spilling & Matchmsker spins
const int teaSWITCHPIN = 2;
const int teaSERVOPIN = 3;
const int matchmakerSWITCHPIN = 4;
const int matchmakerSERVOPIN = 11;
// VARIABLES - for Tea spilling & Matchmsker spins
int teaValue;
int matchmakerValue;
int teastaySpinned = 0;
int matchstaySpinned = 0;
float count_t;
Servo teaServo;
Servo matchmakerServo;

// Charcoal spilling
// CONSTANTS - charcoal spilt
const int charcoalSWITCHPIN = 5;
const int redLED = 6;
// VARIABLES - charcoal spilt
int charcoalValue;
unsigned long faster = 0;
int ledState = LOW;
int ledstayOn = 0;

// alarm & door
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {1000, 10000, 1000, 10000, 1000, 10000, 2000, 4000};
// CONSTANTS
const int alarmSWITCHPIN = 7;
const int doorSWITCHPIN = 8;
const int buzzer = 12;
int state = 0; // low

// VARIABLES
int alarmValue;
int doorValue;
bool landed = false;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  // Tea spilling & Matchmsker spins
  teaServo.attach(teaSERVOPIN);
  teaServo.write(90);
  matchmakerServo.attach(matchmakerSERVOPIN);
  matchmakerServo.write(0);
  pinMode(teaSWITCHPIN, INPUT);
  pinMode(matchmakerSWITCHPIN, INPUT);
  count_t = 0;

  // charcoal spilt
  pinMode(redLED, OUTPUT);
  pinMode(charcoalSWITCHPIN, INPUT);
  Serial.begin(9600);

  // alarm & door
  pinMode(alarmSWITCHPIN, INPUT);
  pinMode(doorSWITCHPIN, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Tea spilling & Matchmsker spins
  teaValue = digitalRead(teaSWITCHPIN);
  matchmakerValue = digitalRead(matchmakerSWITCHPIN);
  // tea spills if switch is high
  if (teaValue == HIGH || teastaySpinned == 1) {
    //    count_t += 1;
    if (count_t > 56) {
      count_t = 55;
    }
    teaServo.write(35); //35
    teastaySpinned = 1;

  } else {
    teaServo.write(90);
  }
  // matchmaker spins if its switch is high
  if (matchmakerValue == HIGH || matchstaySpinned == 1) {
      matchmakerServo.write(180);
      matchstaySpinned = 1;
  } else {
    matchmakerServo.write(0); // dont spin
  }

  // charcoal spilt
  charcoalValue = digitalRead(charcoalSWITCHPIN);
  if (charcoalValue != HIGH || ledstayOn == 1) {
    ledstayOn = 1;
    faster += 1;
    Serial.println(faster);
    if (faster <= 1000) {
      // blink light
      if (faster % 10 == 0) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
    } else {
      ledState = HIGH;
    }

  } else {
    ledState = LOW;
  }
  digitalWrite(redLED, ledState);

  // alarm & door
  alarmValue = digitalRead(alarmSWITCHPIN);
  doorValue = digitalRead(doorSWITCHPIN);
  unsigned long currentMillis = millis();

  if (alarmValue == HIGH && doorValue == HIGH) {
    landed = true;
  }
  // alarm
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (state == 0 && landed) {
      state = 1;
    } else {
      state = 0;
    }
  }

  if (landed) {
    if (doorValue == LOW){
      landed = false;
    }
    if (doorValue == LOW || state == 0) {
      noTone(buzzer);
    } else {
      tone(buzzer, 262);
    }
  }
}
