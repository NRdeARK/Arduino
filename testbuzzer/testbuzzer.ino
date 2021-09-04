int buttonPin = 4;
int led = 3;
int buzzer = 2;
int buttonState = 0;
int I = 0;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (I != buttonState ) {
    I = buttonState;
    if (buttonState == HIGH) {
      digitalWrite(led, HIGH);
      digitalWrite(buzzer, LOW);
      Serial.println("Power On");
    }
    else {
      digitalWrite(led, LOW);
      digitalWrite(buzzer, HIGH);
      Serial.println("Power Off");
    }
  }
}
