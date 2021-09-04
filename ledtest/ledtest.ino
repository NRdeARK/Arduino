#define R 6
#define G 5
#define B 3
void setup() {
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
 int i;
      for(i=1;i<255;i++)   
  {
    analogWrite(R,i);
    delay(10);
  }
  //2
  for(i=1;i<255;i++)   
  {
    analogWrite(G,i);
    delay(10);
  }
  //3
   for(i=255;i>0;i--)   
  {
    analogWrite(R,i);
    delay(10);
  }
  //4
   for(i=1;i<256;i++)   
  {
    analogWrite(B,i);
    delay(10);
  }
  //5
   for(i=255;i>0;i--)   
  {
    analogWrite(G,i);
    delay(10);
  }
  //6
   for(i=1;i<256;i++)   
  {
    analogWrite(R,i);
    delay(10);
  }
  //7
   for(i=1;i<256;i++)   
  {
    analogWrite(G,i);
    delay(10);
  }
  //8
}
