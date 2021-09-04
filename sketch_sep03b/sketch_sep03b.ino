const int buttonPin1 = 10;
const int buttonPin2 = 11;
const int buttonPin3 = 12;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
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
int ledState1 = LOW;
int ledState2 = LOW;
int ledState3 = LOW;
bool checkLed1 = 0;
bool checkLed2 = 0;
bool checkLed3 = 0;
bool checkButton1 = true;
bool checkButton2 = true;
bool checkButton3 = true;
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
  Serial.print(reading2);
  Serial.print(" : ");
  Serial.println(lastButtonState2);
  if(checkButton1 == false && reading1 == lastButtonState1) checkButton1 = true; 
  if(checkButton2 == false && reading2 != lastButtonState2) checkButton2 = true;      
  if(checkButton3 == false && reading3 != lastButtonState3) checkButton3 = true;  
  if (reading1 != lastButtonState1 && checkButton1 == true && checkLed1 == 0)
  {
    checkLed1 = 1;
    ledState1 = 1;
    lastDebounceTime1 = millis();
    checkButton1 = false; 
  }
  if (reading2 == lastButtonState2)
  {
    checkLed2 = 1;
    ledState2 = 1;
    lastDebounceTime2 = millis();
    checkButton2 = false; 
  }
  if (reading3 == lastButtonState3 && checkButton3 == true && checkLed3 == 0 && checkLed1 == 0)
  {
    checkLed3 = 1;
    ledState3 = 1;
    lastDebounceTime3 = millis();
    checkButton3 = false; 
  }
  
  if(checkLed1 == 1)
  {
    if ((millis() - lastDebounceTime1) > 3000)
    {
      ledState1 = 0;
      checkLed1 = 0;
    }
    if(reading1 != lastButtonState1 && checkButton1 == true)
    {
      ledState1 = 0;
      checkLed1 = 0;
      checkButton1 = false; 
    }
  }
  if(checkLed2 == 1)
  {
    if((millis() - lastDebounceTime3) > 2000)
    {
      ledState2 = 0;
      checkLed2 = 0;
    }
    if((millis() - lastDebounceTime3) > 1500) ledState2 = 0;
    else if((millis() - lastDebounceTime3) > 1000) ledState2 = 1;
    else if((millis() - lastDebounceTime3) > 500) ledState2 = 0;
    
  }
  if(checkLed3 == 1)
  {
    if ((millis() - lastDebounceTime3) > 3000)
    {
      ledState3 = 0;
      checkLed3 = 0;
    }
    if(reading3 == lastButtonState3 && checkButton3 == true)
    {
      ledState3 = 0;
      checkLed3 = 0;
      checkButton3 = false; 
    }
  }
  
  digitalWrite(led1, ledState1);
  digitalWrite(led2, ledState2);
  digitalWrite(led3, ledState3);

}

Message @Monk7void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
