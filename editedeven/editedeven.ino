#define IN1 8
#define IN2 9
#define IN3 13
#define IN4 12
#define PWMA 10
#define PWMB 11
#define SL2 A1
#define SL A2
#define SC A3
#define SR A4
#define SR2 A5
int sL2 = 0, sL = 0, sC = 0, sR = 0, sR2 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);  pinMode(IN2, OUTPUT);  pinMode(IN3, OUTPUT);  pinMode(IN4, OUTPUT);
  pinMode(SL, INPUT);    pinMode(SC, INPUT);    pinMode(SR, INPUT);

}
void loop() {
  Motor("F",200,"F",200,1000);
  trackLine2(200,200,1);
  Motor("S",0,"S",0,0);
  while (true);
}
void Motor(char mL, int pwmL, char mR, int pwmR, int dL) {
  if (mL == 'F') {
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  }
  else if (mL == 'B') {
    digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  }
  else if (mL == 'S') {
    digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW);
  }
  else {
    digitalWrite(IN1, HIGH); digitalWrite(IN2, HIGH);
  }
  ///////////////////////////////////////////////
  if (mR == 'F') {
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  }
  else if (mR == 'B') {
    digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
  }
  else if (mR == 'S') {
    digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW);
  }
  else {
    digitalWrite(IN3, HIGH); digitalWrite(IN4, HIGH);
  }
  analogWrite(PWMA, pwmL);
  analogWrite(PWMB, pwmR);
  delay(dL);
}
void readSensor() {
  sL2 = digitalRead(SL2);
  sL = digitalRead(SL);
  sC = digitalRead(SC);
  sR = digitalRead(SR);
  sR2 = digitalRead(SR2);
  if (sL2 == 0) sL2 = 1; else sL2 = 0;
  if (sL == 0) sL = 1; else sL = 0;
  if (sC == 0) sC = 1; else sC = 0;
  if (sR == 0) sR = 1; else sR = 0;
  if (sR2 == 0) sR2 = 1; else sR2 = 0;
}
void trackLine1(int sl, int sr) {  /////////// วิ่งตามเส้นแบบไม่หยุด
  readSensor();
  if (sL == 0 && sR == 0) {
    Motor('F', sl, 'F', sr, 5);
  }
  else if (sL == 1 && sR == 0) {
    Motor('S', sl, 'F', sr, 5);
  }
  else if (sL == 0 && sR == 1) {
    Motor('F', sl, 'S', sr, 5);
  }
  else {
    Motor('F', sl, 'F', sr, 5);
  }
}

////// วิ่งตามเส้นแบบนับเส้นตัด 2 ด้าน ////////
void trackLine2(int sl, int sr, int line) {
  int count = 0;
  while (count < line) {
    ///////////////////////////
    trackLine1(sl, sr);
    ////////////////////////
    Motor("S",0,"S",0,5);
    readSensor();
    if (sL2 == 1 && sR2 == 1) {
      Motor("S",0,"S",0,5);
      readSensor();
      while (sL2 == 1 && sR2 == 1) {
        Motor('F', sl, 'F', sr, 5);
        Motor("S",0,"S",0,5);
        readSensor();
      }
      count++;
    }
  }
  Motor('S', sl, 'S', sr, 10);
}

/////////// วิ่งตามเส้นแบบนับเส้นตัดด้านซ้าย ///////////////////
void trackLine_L(int sl, int sr, int line) {
  int count = 0;
  while (count < line) {
    ///////////////////////////
    trackLine1(sl, sr);
    ////////////////////////
    readSensor();
    if (sL2 == 1 && sL == 1) {
      readSensor();
      while (sL2 == 1 && sL == 1) {
        Motor('F', sl, 'F', sr, 10);
        readSensor();
      }
      count++;
    }
  }
  Motor('S', sl, 'S', sr, 10);
}

/////// วิ่งตามเส้นแบบนับเส้นตัดด้านขวา ////////
void trackLine_R(int sl, int sr, int line) {
  int count = 0;
  while (count < line) {
    ///////////////////////////
    trackLine1(sl, sr);
    ////////////////////////
    readSensor();
    if (sR == 1 && sR2 == 1) {
      readSensor();
      while (sR == 1 && sR2 == 1) {
        Motor('F', sl, 'F', sr, 10);
        readSensor();
      }
      count++;
    }
  }
  Motor('S', sl, 'S', sr, 10);
}
///////////////////เลี้ยวซ้ายแบบ Delay///////////////////
void turnLeft_DL(int sl, int sr, int dL) {
  Motor('B', sl, 'F', sr, dL);
  Motor('S', sl, 'S', sr, 10);
}

///////////////////เลี้ยวขวาแบบ Delay///////////////////
void turnRight_DL(int sl, int sr, int dL) {
  Motor('F', sl, 'B', sr, dL);
  Motor('S', sl, 'S', sr, 10);
}

///////////////////เลี้ยวซ้ายแบบใช้ Sensor แบบ 3 แยก///////////////////
void turnLeft(int sl, int sr) {
  Motor('F', sl, 'F', sr, 300);
  readSensor();
  while (sC == 0) {
    Motor('B', sl, 'F', sr, 10);
    readSensor();
  }
  Motor('S', sl, 'S', sr, 10);
}

///////////////////เลี้ยวซ้ายแบบใช้ Sensor แบบ 4 แยก///////////////////
void turnLeft_cut(int sl, int sr) {
  Motor('F', sl, 'F', sr, 300);
  Motor('B', sl, 'F', sr, 300);
  readSensor();
  while (sC == 0) {
    Motor('B', sl, 'F', sr, 10);
    readSensor();
  }
  Motor('S', sl, 'S', sr, 10);
}

///////////////////เลี้ยวขวาแบบใช้ Sensor แบบ 3 แยก///////////////////
void turnRight(int sl, int sr) {
  Motor('F', sl, 'F', sr, 300);
  readSensor();
  while (sC == 0) {
    Motor('F', sl, 'B', sr, 10);
    readSensor();
  }
  Motor('S', sl, 'S', sr, 10);
}

///////////////////เลี้ยวขวาแบบใช้ Sensor แบบ 4 แยก///////////////////
void turnRight_cut(int sl, int sr) {
  Motor('F', sl, 'F', sr, 300);
  Motor('F', sl, 'B', sr, 300);
  readSensor();
  while (sC == 0) {
    Motor('F', sl, 'B', sr, 10);
    readSensor();
  }
  Motor('S', sl, 'S', sr, 10);
}
