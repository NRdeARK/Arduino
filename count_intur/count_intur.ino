const byte ledPin = 11;
const byte sw1 = 2;
const byte sw2 = 3;
//volatile byte state = LOW;
int count=0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  attachInterrupt(digitalPinToInterrupt(sw1), blink1, FALLING);
  attachInterrupt(digitalPinToInterrupt(sw2), blink2, FALLING);
}

void loop() {
  analogWrite(ledPin,255);
  delay(2000);
  analogWrite(ledPin,0);
  delay(2000);
  
}

void blink1() {
  delay(50);
  noInterrupts();
  if(digitalRead(sw1)==0){
    if (digitalRead(sw1)==0){
      if(count==99){count=-1;}
        count++;
        Serial.print("count up : ");
        Serial.println(count);
  }
  //while(digitalRead(sw1)==0){}
  interrupts();
 }
}

void blink2() {
  delay(50);
  noInterrupts();
  if (digitalRead(sw2)==0){  
    if (digitalRead(sw2)==0){
      if(count==0){count=100;}
        count--;
        Serial.print("count down : ");
        Serial.println(count);
  }
  //while(digitalRead(sw2)==0){}
  interrupts();
}
}
  
