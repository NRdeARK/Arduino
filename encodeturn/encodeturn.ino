#define encodeA 2
#define encodeB 3
#define sw1 4
int steps[4][4] =
{ {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};
int motorpos = 0;
int Mode = 0;
void setup() {
  Serial.begin(9600);
  pinMode(encodeA, INPUT);
  pinMode(encodeB, INPUT);
  attachInterrupt(0, Clock, CHANGE);
  attachInterrupt(1, CountC, CHANGE);
  pinMode(sw1, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  while (Mode == 0) {
    Serial.println(motorpos);
    if (digitalRead(sw1) == 0) {
      delay(50);
      if (digitalRead(sw1) == 0) {
        Serial.println("click");
        Mode++;
      }
      while (digitalRead(sw1) == 0) {}
    }
  }
  while (Mode == 1) {
    if (motorpos > 0) {
      Serial.print("++++");
      for (int i = motorpos * 68/10; i > 0; i--) {
        Serial.println(i);
        for (int a = 0; a < 4; a++) {
          digitalWrite(8, steps[a][0]);
          digitalWrite(9, steps[a][1]);
          digitalWrite(10, steps[a][2]);
          digitalWrite(11, steps[a][3]);
          delay(10);
        }
      }
      motorpos = 0;
      Serial.println(motorpos);
      Mode = 0;
    }


    else if (motorpos < 0) {
      Serial.print("----");
      for (int i = motorpos * 7; i < 0; i++) {
        Serial.println(i);
        for (int a = 0; a < 4; a++) {
          digitalWrite(8, steps[a][3]);
          digitalWrite(9, steps[a][2]);
          digitalWrite(10, steps[a][1]);
          digitalWrite(11, steps[a][0]);
          delay(10);
        }
      }
      motorpos = 0;
      Serial.println(motorpos);
      Mode = 0;
    }
    else {
      Mode = 0;
    }
  }
}

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
}
