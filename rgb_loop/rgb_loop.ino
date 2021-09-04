#define R 11
#define G 10
#define B 9
String red,green,blue,a,b,c;
int i;
void setup()
{
  Serial.begin(9600);
  pinMode(R , OUTPUT);
  pinMode(G , OUTPUT);
  pinMode(B , OUTPUT);
}
void loop()
{
  //1
  for(i=1;i<256;i++)   
  {
    analogWrite(R,i);
    delay(10);
  }
  //2
  for(i=1;i<256;i++)   
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
   for(i=255;i>0;i--)   
  {
    analogWrite(R,i);
    analogWrite(G,i);
    analogWrite(B,i);
    delay(10);
  }

  
}
