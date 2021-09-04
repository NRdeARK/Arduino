///motor
  #define IN1 34
  #define IN2 36
  #define IN3 38
  #define IN4 40
  #define PWMA 32
  #define PWMB 42
  ///sensor
  #define CLP 31
  #define S5  33
  #define S4  35
  #define S3  37
  #define S2  39
  #define S1  41
  int mid=150,adj=0;
  int s1,s2,s3,s4,s5;
  
void setup() 
{
  Serial.begin(9600);
  pinMode(S1,INPUT);  pinMode(IN1,OUTPUT);
  pinMode(S2,INPUT);  pinMode(IN2,OUTPUT);
  pinMode(S3,INPUT);  pinMode(IN3,OUTPUT);
  pinMode(S4,INPUT);  pinMode(IN4,OUTPUT);
  pinMode(S5,INPUT);
}
void readSensor()//readSensor
  {
  s1=digitalRead(S1);
  s2=digitalRead(S2);
  s3=digitalRead(S3);
  s4=digitalRead(S4);
  s5=digitalRead(S5);
  // 0 to 1
  if(s1 == 1) s1 = 0; else s1 = 1;
  if(s2 == 1) s2 = 0; else s2 = 1;
  if(s3 == 1) s3 = 0; else s3 = 1;
  if(s4 == 1) s4 = 0; else s4 = 1;
  if(s5 == 1) s5 = 0; else s5 = 1; 
   
  }

  void control(int in2, int in1, int pwmA, int in4, int in3, int pwmB, int dl)//controlRobot
  {
    digitalWrite(IN1,in1);  digitalWrite(IN3,in3);
    digitalWrite(IN2,in2);  digitalWrite(IN4,in4);
    analogWrite(PWMA,pwmA); analogWrite(PWMB,pwmB);
    delay(dl);
  }
  void trackline ()
  {
    if(s2==0 && s4==0)
    {
      control(1,0,150,1,0,150,500);
    }
    else if(s2==1 && s4==0)
    {
      control(1,0,150,0,1,150,500);
    }
    else if(s2==0 && s4==1)
    {
      control(0,1,150,1,0,150,500);
    }
    else 
    {
      control(1,0,150,1,0,150,500);
    }
  }



void loop() {
  control(0,1,150,0,1,150,100);
  while(s2==1 && s3==1 && s4==1)
  {control(1,0,250,0,1,250,500);
  }
}
