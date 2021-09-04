  #define IN1 13
  #define IN2 12
  #define IN3 9
  #define IN4 8
  #define PWMA 11
  #define PWMB 10
  #define SEN_L 7
  #define SEN_R 6
  int SL=0 ;
  int SR=0 ;
void setup() {
  pinMode(SEN_L,INPUT);
  pinMode(SEN_R,INPUT); 
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT); 
}
void loop(){
  robot1();
}
void robot(int in1, int in2, int pwmA, int in3, int in4, int pwmB,int dl)
{
  digitalWrite(IN1,in3);
  digitalWrite(IN2,in4);
  analogWrite(PWMA,pwmB); 
  digitalWrite(IN3,in1);
  digitalWrite(IN4,in2);
  analogWrite(PWMB,pwmA);
  delay(dl);
}
void readsen()
{
  SL = digitalRead(SEN_L);
  SR = digitalRead(SEN_R);
}
void robot1(){
  readsen(); 
  if (SL==1 && SR==1)
  {
    robot(0,1,200,1,0,200,10);
  }
  else if(SL==0 && SR==1)
  {
    robot(0,0,200,1,0,200,10);
  }
  else if(SL==1 && SR==0)
  {
    robot(0,1,200,0,0,200,10);
  }
  else 
  {
    robot(0,0,0,0,0,0,10);
    //while(true);
  }
}
