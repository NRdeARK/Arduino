///motor
  #define IN1 11
  #define IN2 10
  #define IN3 9
  #define IN4 8
  #define PWMA 12
  #define PWMB 13
  ///sensor
  #define SL  7
  #define SC  6
  #define SR  5
  
  int sL = 0, sC = 0, sR = 0;
void setup() {
  
  ///controlmotor
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  ///sensor
  pinMode(SL,INPUT);  
  pinMode(SC,INPUT);  
  pinMode(SR,INPUT);
  
  
}
void control(int in2, int in1, int pwmA, int in3, int in4, int pwmB, int dl)//controlRobot
  {
    digitalWrite(IN1,in1);  digitalWrite(IN3,in3);
    digitalWrite(IN2,in2);  digitalWrite(IN4,in4);
    analogWrite(PWMA,pwmA); analogWrite(PWMB,pwmB);
    delay(dl);
  }
void Motor(char mL, int pwmL, char mR, int pwmR, int dL) {
  if (mL == 'F') {
    digitalWrite(IN4, HIGH); digitalWrite(IN3, LOW);
  }
  else if (mL == 'B') {
    digitalWrite(IN4, LOW);  digitalWrite(IN3, HIGH);
  }
  else if (mL == 'S') {
    digitalWrite(IN4, LOW);  digitalWrite(IN3, LOW);
  }
  else {
    digitalWrite(IN4, HIGH); digitalWrite(IN3, HIGH);
  }
  ///////////////////////////////////////////////
  if (mR == 'B') {
    digitalWrite(IN2, HIGH); digitalWrite(IN1, LOW);
  }
  else if (mR == 'F') {
    digitalWrite(IN2, LOW);  digitalWrite(IN1, HIGH);
  }
  else if (mR == 'S') {
    digitalWrite(IN2, LOW);  digitalWrite(IN1, LOW);
  }
  else {
    digitalWrite(IN2, HIGH); digitalWrite(IN1, HIGH);
  }
  ////////////////////////////////////////////////
  analogWrite(PWMA, pwmL);
  analogWrite(PWMB, pwmR);
  delay(dL);
}  
///sensor
void readSensor() {
  sL = digitalRead(SL);
  sC = digitalRead(SC);
  sR = digitalRead(SR);
  if (sL == 0) sL = 1; else sL = 0;
  if (sC == 0) sC = 1; else sC = 0;
  if (sR == 0) sR = 1; else sR = 0;
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
void trackLine2(int sl, int sr, int line) {
  int count = 0;
  while (count < line) {
    ///////////////////////////
    trackLine1(sl, sr);
    Motor('S', sl, 'S', sr, 3);
    ////////////////////////
    readSensor();
    if (sR == 1) {
      readSensor();
      while ( sR == 1 ) {
        Motor('F', sl, 'F', sr, 5);
        Motor('S', sl, 'S', sr, 10);
        readSensor();
      }
      count++;
    }
  }
  Motor('S', sl, 'S', sr, 10);
}


void trackLine2ex(int sl, int sr, int line) {
  int count = 0;
  while (count < line) {
    ///////////////////////////
    trackLine1(sl, sr);
    Motor('S', sl, 'S', sr, 5);
    ////////////////////////
    readSensor();
    if (sR == 1) {
      readSensor();
      while ( sR == 1 ) {
        Motor('F', sl, 'F', sr, 5);
        Motor('S', sl, 'S', sr, 15);
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
    if ( sL == 1) {
      readSensor();
      while ( sL == 1) {
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
    if (sR == 1 ) {
      readSensor();
      while (sR == 1 ) {
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
    Motor('B', sl, 'F', sr, 3);
    readSensor();
  }
  Motor('S', sl, 'S', sr, 10);
}

///////////////////เลี้ยวซ้ายแบบใช้ Sensor แบบ 4 แยก///////////////////
void turnLeft_cut(int sl, int sr) {
  Motor('F', sl, 'F', sr, 100);
  Motor('B', sl, 'F', sr, 100);
  Motor('S', sl, 'S', sr ,100);
  readSensor();
  while (sR == 0) {
    Motor('B', sl, 'F', sr, 5);
    readSensor();
     Motor('S', sl, 'S', sr, 10);
  }
}

///////////////////เลี้ยวขวาแบบใช้ Sensor แบบ 3 แยก///////////////////
void turnRight(int sl, int sr) {
  Motor('F', sl, 'F', sr, 300);
  readSensor();
  while (sC == 0) {
    Motor('F', sl, 'B', sr, 5);
    Motor('S', sl, 'S', sr, 20);
    readSensor();
  }
  delay(130);
  Motor('S', sl, 'S', sr, 10);
}

///////////////////เลี้ยวขวาแบบใช้ Sensor แบบ 4 แยก///////////////////
void turnRight_cut(int sl, int sr) {
  Motor('F', sl, 'F', sr, 100);
  Motor('F', sl, 'B', sr, 100);
  Motor('S', sl, 'S', sr ,100);
  readSensor();
  while (sC == 0) {
    Motor('F', sl, 'B', sr, 5);
    readSensor();
    Motor('S', sl, 'S', sr ,12);
  }

}
  

void loop() {
  control(0,0,150,0,0,150,1000);
  Motor('F', 130, 'F', 130, 200);
  trackLine2(130, 130, 1); 
  turnRight_cut(150, 150);
  Motor('F', 130, 'F', 130, 100);  
  trackLine2(130, 130, 1);
  turnRight_cut(150, 150);
  Motor('F', 150, 'B', 150, 55);
  trackLine2ex(130, 150, 4);
  turnLeft_cut(150,150);
  
  
  trackLine2(130, 130, 1);
  turnLeft_cut(150,150);
  trackLine2ex(130, 130, 2);
  turnRight_cut(150, 150);
  Motor('F', 130, 'B', 130, 100);
  
  trackLine2ex(130, 130, 2);
  turnRight_cut(150, 150);
  trackLine2(90, 90, 4);
  control(0,0,150,0,0,150,100);
  while (true);
 
}
