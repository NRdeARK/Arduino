#define encodeA 2
#define encodeB 3


int motorpos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(encodeA, INPUT);
  pinMode(encodeB, INPUT);
  attachInterrupt(0, Clock, CHANGE);
  attachInterrupt(1, CountC, CHANGE);
  
}

void loop() {
  
void Clock() {
  //  Serial.print("clock");
  if (digitalRead(encodeA) == 1) {
    if (digitalRead(encodeB) == 0) {
      motorpos++;
    }
    else {
      motorpos--;
    }
  }
  else {
    if (digitalRead(encodeB) == 1) {
      motorpos++;
    }
    else {
      motorpos--;
    }
  }

  //  time1=millis();
  //  while(millis()>(time1+1000)){}

}

void CountC() {
  //  Serial.print("counter clock");
  if (digitalRead(encodeB) == 1) {
    if (digitalRead(encodeA) == 1) {
      motorpos++;
    }
    else {
      motorpos--;
    }
  }
  else {
    if (digitalRead(encodeA) == 0) {
      motorpos++;
    }
    else {
      motorpos--;
    }
  }
  //  Serial.println(motorpos);
  //   time1=millis();
  //  while(millis()>(time1+1000)){}
}
