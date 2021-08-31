#define r1 12
#define r2 11
#define r3 10
void chalie(int a,int b,int c);
void setup() 
{
//  pinMode(r1,OUTPUT);
//  digitalWrite(r1,1);
//  pinMode(r2,OUTPUT);
//  digitalWrite(r2,0);
//  pinMode(r3,INPUT);
  //chalie(2,1,3);//led1
  //chalie(1,2,3);//led2
  //chalie(3,2,1);//led3
  //chalie(2,3,1);//led4
  //chalie(3,1,2);//led4
  //chalie(1,3,2);//led6
  //chalie(2,1,3);
  
}

void loop() 
{
  led(1);
  delay(500);
  led(2);
  delay(500);
  led(3);
  delay(500);
  led(4);
  delay(500);
  led(5);
  delay(500);
  led(6);
  delay(500);
  led(5);
  delay(500);
  led(4);
  delay(500);
  led(3);
  delay(500);
  led(2);
  delay(500);

}
void led(int led)
{
  if (led==0)
  {
    pinMode(r1,OUTPUT);
    pinMode(r2,OUTPUT);
    pinMode(r3,OUTPUT);
    digitalWrite(r1,0);
    digitalWrite(r2,0);
    digitalWrite(r3,0);
  }
  if (led==1)
  {
    chalie(2,1,3);//led1
  }
  if (led==2)
  {
  chalie(1,2,3);//led2
  }
  if (led==3)
  {
  chalie(3,2,1);//led3
  }
  if (led==4)
  {
  chalie(2,3,1);//led4
  }
  if (led==5)
  {
  chalie(3,1,2);//led4
  }
  if (led==6)
  {
    chalie(1,3,2);//led6
  }
}
void chalie(int a,int b ,int c)
{
  if (c==1)
  {
    pinMode(r1,INPUT);
  }
  if (c==2)
  {
    pinMode(r2,INPUT);
  }
  if (c==3)
  {
    pinMode(r3,INPUT);
  }
  if (a==1)
  {
    pinMode(r1,OUTPUT);
    digitalWrite(r1,1);
  }
  if (a==2)
  {
    pinMode(r2,OUTPUT);
    digitalWrite(r2,1);
  }
  if (a==3)
  {
    pinMode(r3,OUTPUT);
    digitalWrite(r3,1);
  }
  if (b==1)
  {
    pinMode(r1,OUTPUT);
    digitalWrite(r1,0);
  }
  if (b==2)
  {
    pinMode(r2,OUTPUT);
    digitalWrite(r2,0);
  }
  if (b==3)
  {
    pinMode(r3,OUTPUT);
    digitalWrite(r3,0);
  }

}
