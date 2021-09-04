void setup() {
  Serial.begin(9600);
}

void loop() {
  int num = 0;
  int numx = 0;
  int numi = 0;
  int a = analogRead(A0);

  if (a > 500) {
    num += 1;
  }
  int b = analogRead(A1);
  if (b > 500) {
    num += 2;
  }
  int c = analogRead(A2);
  if (c > 500) {
    num += 4;
  }
  int d = analogRead(A3);
  if (d > 500) {
    num += 8;
  }
  int e = analogRead(A4);
  if (e > 500) {
    num += 16;
  }
  int f = analogRead(A7);
  if (f > 500) {
    numx += 10;
  }
  int g = analogRead(A6);
  if (g > 500) {
    numx += 20;
  }
  numi = num - numx;
  Serial.println(numi);
  if (numi >= 8)
  {
    numi-=8;
    analogWrite(2,1000);
  }
  else{
    analogWrite(2,0);
    }
  if (numi >= 4)
  {
    numi-=4;
    analogWrite(3,1000);
  }
  else{
    analogWrite(3,0);
    }
  if (numi >= 2)
  {
    numi-=2;
    analogWrite(4,1000);
  }
  else{
    analogWrite(4,0);
    }
  if (numi >= 1)
  {
    numi-=1;
    analogWrite(5,1000);
  }
  else{
    analogWrite(5,0);
    }
}
