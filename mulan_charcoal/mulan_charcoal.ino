/*
   Pour Tea w servo
   Stretch goal: led progressively blinks faster
   and then stay on for the rest

   // for (int thisPin = 2; thisPin < 8; thisPin++)
*/

// CONSTANTS
const int charcoalSWITCHPIN = 5;
const int redLED = 6;


// VARIABLES
int charcoalValue;
//unsigned long timer;
unsigned long faster = 0;
int ledState = LOW;
int ledstayOn = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(charcoalSWITCHPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //  timer = millis();
  charcoalValue = digitalRead(charcoalSWITCHPIN);
  if (charcoalValue == HIGH || ledstayOn == 1) {
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
}
