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
  

  Serial.begin(9600);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  
  pinMode(SEN_L,INPUT);
  pinMode(SEN_R,INPUT);
  
 
}

void robot(int in1, int in2, int in3, int in4, int pwma, int pwmb,int dl)
{
  digitalWrite(IN1,in1);
  digitalWrite(IN2,in2);
  analogWrite(PWMA,pwma);
  
  digitalWrite(IN3,in3);
  digitalWrite(IN4,in4);
  analogWrite(PWMB,pwmb);
  delay(dl);
}
void readsen()
{
  int SL = digitalRead(7);
  int SR = digitalRead(6);
  Serial.println("1");
  
}

void robot1(){
  readsen();
  Serial.println(SL);
  Serial.println(SR);
  
  
  
  if (SL==1 && SR==1)
  {
    robot(1,0,0,1,180,210,1000);
    Serial.println("forward");
  }
  else if(SL==0 && SR==1)
  {
    robot(1,0,1,0,180,210,1000);
    Serial.println("right");
  }
  else if(SL==1 && SR==0)
  {
    robot(0,1,0,1,180,210,1000);
    Serial.println("left");
  }
  else 
  {
    robot(0,0,0,0,180,210,1000);
    Serial.println("stop");
  }
  delay(100);  
}
void loop()
{  
void robot1();
}
