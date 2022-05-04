const int buttonPin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (digitalRead(buttonPin) == HIGH){
  Serial.println(buttonPin);
 }else{
  Serial.println(0);
 }
}
