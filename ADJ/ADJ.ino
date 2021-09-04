
  #define IN1 13
  #define IN2 12
  #define IN3 9
  #define IN4 8
  #define PWMA 10
  #define PWMB 11
  #define S5 7
  #define S4 6
  #define S3 5
  #define S2 4
  #define S1 3
  int mid=150,adj=0;
  int s1,s2,s3,s4,s5;

  void setup() 
  {
  pinMode(S1,INPUT);  pinMode(IN1,OUTPUT);
  pinMode(S2,INPUT);  pinMode(IN2,OUTPUT);
  pinMode(S3,INPUT);  pinMode(IN3,OUTPUT);
  pinMode(S4,INPUT);  pinMode(IN4,OUTPUT);
  pinMode(S5,INPUT);
  }
  /////
  void readSensor()//readSensor
  {
  s1=digitalRead(S1);
  s2=digitalRead(S2);
  s3=digitalRead(S3);
  s4=digitalRead(S4);
  s5=digitalRead(S5);
  // 0 to 1
  if(s1 == 1) {s1 = 0;} else {s1 = 1;}
  if(s2 == 1) {s2 = 0;} else {s2 = 1;}
  if(s3 == 1) {s3 = 0;} else {s3 = 1;}
  if(s4 == 1) {s4 = 0;} else {s4 = 1;}
  if(s5 == 1) {s5 = 0;} else {s5 = 1;}  
  }
  /////
  void Control(int in1, int in2, int pwmA, int in3, int in4, int pwmB, int dl)//controlRobot
  {
    digitalWrite(IN1,in1);  digitalWrite(IN3,in3);
    digitalWrite(IN2,in2);  digitalWrite(IN4,in4);
    analogWrite(PWMA,pwmA); analogWrite(PWMB,pwmB);
    delay(dl);
  }
  /////
  void Forward(int T)
  {
    Control(1,0,mid+adj,1,0,mid-adj,T);
  }
  /////
  void Right(int T)
  {
    Control(1,0,mid+adj,0,1,mid-adj,T);
  }
  /////
  void Left(int T)
  {
    Control(0,1,mid+adj,1,0,mid-adj,T);
  }
  /////
  void Stop()
  {
    Control(0,0,0,0,0,0,100);
    while(true);
  }
  /////
  void TracklinesPID()
  {
    readSensor();
    if      (s3==1)
    {Control(1,0,mid+adj,1,0,mid-adj,100);}
    else if (s2==1)
    {Control(1,0,145+adj,1,0,155-adj,100);}
    else if (s4==1)
    {Control(1,0,155+adj,1,0,145-adj,100);}
    else if (s5==1)
    {Control(1,0,140+adj,1,0,160-adj,100);}
    else if (s1==1)
    {Control(1,0,160+adj,1,0,140-adj,100);}
    else
    {Stop();}
  }
  /////
  
  
  
  
  
  
  
  
  void loop ()
  {
   Forward(1000);
   Stop();
  }
