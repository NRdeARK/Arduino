const int buttonPin1 = 12;
const int buttonPin2 = 11;
const int buttonPin3 = 10;
const int led1 = 8;
const int led2 = 7;
const int led3 = 6;
int buttonstate1 = 0;
int buttonstate2 = 0;
int buttonstate3 = 0;
int lastButtonState1 = LOW;
int lastButtonState2 = LOW;
int lastButtonState3 = LOW;
long lastDebounceTime1 = 0;
long lastDebounceTime2 = 0;
long lastDebounceTime3 = 0;
long lastDebounceTime = 0;
long debounceDelay1 = 50;
long debounceDelay2 = 50;
long debounceDelay3 = 50;
int ledState1 = LOW;
int ledState2 = LOW;
int ledState3 = LOW;


void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT_PULLUP);

}

void loop() {
  int reading1 = digitalRead(buttonPin1);
  int reading2 = digitalRead(buttonPin2);
  int reading3 = digitalRead(buttonPin3);

  //แดง
  if (reading1 != lastButtonState1) {
    lastDebounceTime1 = millis();
  }
  if ((millis() - lastDebounceTime1) > debounceDelay1) {
    if (reading1 != buttonstate1) {
      buttonstate1 = reading1;
      Serial.println(buttonstate1);
        ledState1 = !ledState1;
    }
    if (buttonstate1 == LOW && (millis() - lastDebounceTime1) > 3000  ) {
      ledState1 = 0;
    }
  }


  //เหลือง
  
   if (reading2 != lastButtonState2) {
    lastDebounceTime2 = millis();
  }
 
  if (ledState1 == 1 || ledState3 == 1) {
    if (buttonstate2 == HIGH && (millis() - lastDebounceTime3) > 2000 ) {
      ledState2 = 0;

    }
    
  }else{
    Serial.println(buttonstate2);
    if ((millis() - lastDebounceTime2) > debounceDelay2) {
    if (reading2 == buttonstate2) {
      buttonstate2 =! reading2;
      
    }
     if (buttonstate2 == HIGH && (millis() - lastDebounceTime2) <50 ) {
      ledState2 = 0;
    }
  else if (buttonstate2 == HIGH && (millis() - lastDebounceTime2) <1000 ) {
      ledState2 = 1;
    }
  else if (buttonstate2 == HIGH && (millis() - lastDebounceTime2) <1500 ) {
      ledState2 = 0;
    }
  else if (buttonstate2 == HIGH && (millis() - lastDebounceTime2) <=2000  ) {
      ledState2 = 1;
    }
    
  else if (buttonstate2 == HIGH && (millis() - lastDebounceTime2) >2000  ) {
      ledState2 = 0;
  }}
  }

  //เขียว
  if (ledState1 == 1) {
    if (buttonstate3 == HIGH && (millis() - lastDebounceTime3) > 3000 ) {
      ledState3 = 0;
    }
  }
  else if (reading3 != lastButtonState3) {
    lastDebounceTime3 = millis();
  }
  if ((millis() - lastDebounceTime3) > debounceDelay3 && ledState1 == 0) {
    if (reading3 != buttonstate3) {
      buttonstate3 = reading3;
      if (buttonstate3 == LOW) {
        ledState3 = !ledState3;
      }
    }
    if (buttonstate3 == HIGH && (millis() - lastDebounceTime3) > 3000 ) {
      ledState3 = 0;
    }
  }


  digitalWrite(led1, ledState1);
  digitalWrite(led2, ledState2);
  digitalWrite(led3, ledState3);

  lastButtonState1 = reading1;
  lastButtonState2 = reading2;
  lastButtonState3 = reading3;
}
