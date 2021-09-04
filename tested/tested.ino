
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int A = 0, B = 0, C = 0, D = 0,E = 0, F = 0;
  int timex = millis();int i = millis();
  while (i < (timex + 5000)) {
//    Serial.print("A4: ");
//    Serial.println(analogRead(A8));
//    Serial.print("A3: ");
//    Serial.println(analogRead(A9));
//    Serial.print("A2: ");
//    Serial.println(analogRead(A10));
//    Serial.print("A1: ");
//    Serial.println(analogRead(A11));
Serial.println(timex);
    i = millis();

    if (analogRead(A1) >= 1000) {
      A++;
    }
    if (analogRead(A2) >= 1000) {
      B++;
    }
    if (analogRead(A3) >= 1000) {
      C++;
    }
    if (analogRead(A4) >= 1000) {
      D++;
    }
    if (analogRead(A5) >= 1000) {
      E++;
    }
    if (analogRead(A6) >= 1000) {
      F++;
    }
    delay(1);
    if (A >= 100) {
    digitalWrite(2,1);
    Serial.print("A1 ON ");
    }else{digitalWrite(2,0);}
    if (B >= 100) {
    Serial.print("A2 ON ");
    digitalWrite(3,1);
    }else{digitalWrite(3,0);}
    if (C >= 100) {
    Serial.print("A3 ON ");
    digitalWrite(4,1);
    }else{digitalWrite(4,0);}
    if (D >= 100) {
    Serial.print("A4 ON ");
    digitalWrite(5,1);
    }else{digitalWrite(5,0);}
    if (E >= 100) {
    Serial.print("A5 ON ");
    digitalWrite(6,1);
    }else{digitalWrite(6,0);}
    if (F >= 100) {
    Serial.print("A6 ON ");
    digitalWrite(7,1);
    }else{digitalWrite(7,0);}
  }

}
