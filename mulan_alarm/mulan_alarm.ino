/*
   buzzer goes off = alarm
   tried setting bool var that allows alarm to continue
   going off even after palyer has moved from wires (but alarm turns off
   after mulan leaves doors)


   stretch goal: include button
*/

// note durations: 4 = quarter note, 8 = eighth note, etc.:
//int noteDurations[] = {1000, 10000, 1000, 10000, 1000, 10000, 2000, 4000};

// CONSTANTS
//const int NOTE_C4 = 262;
const int alarmSWITCHPIN = 7;
const int doorSWITCHPIN = 8;
//const int cricketSWITCHPIN = 9;
//const int greenLED = 10;
const int buzzer = 12;
int state = 0; //low

// VARIABLES
//int melody[] = {NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0};
int alarmValue;
int doorValue;
//int cricketValue;
bool landed = false;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(alarmSWITCHPIN, INPUT);
  pinMode(doorSWITCHPIN, INPUT);
  //  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  //  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  alarmValue = digitalRead(alarmSWITCHPIN);
  doorValue = digitalRead(doorSWITCHPIN);
  unsigned long currentMillis = millis();

  if (alarmValue == HIGH && doorValue == HIGH) {
    landed = true;
  }
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (state == 0 && landed) {
      state = 1;
    } else {
      state = 0;
    }
  }

  if (landed) {
    if (doorValue == LOW || state == 0) {
      noTone(buzzer);
      landed = false;
    } else {
//        int noteDuration = noteDurations[thisNote];
        //      noTone(buzzer);
        tone(buzzer, 262);
        //      noTone(buzzer);
      }
    }
  }

  //  // cricket
  //  if (cricketValue != HIGH) {
  //    digitalWrite(greenLED, HIGH);
  //  }
