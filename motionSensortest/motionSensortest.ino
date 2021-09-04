int ledPin= 12;
int inputPin= 3;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
}

void loop(){
  int value= digitalRead(inputPin);

  if (value == HIGH)
  {
    Serial.println(value);
    digitalWrite(ledPin, HIGH);
    delay(1000) ;
  }

  else
  {
    Serial.println(value);
    digitalWrite(ledPin, LOW);
    delay(1000) ;
  }
}
