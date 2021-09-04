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

  void Control(int in4, int in3, int pwmB, int in1, int in2, int pwmA, int dl)//controlRobot
  {
    digitalWrite(IN1,in1);  digitalWrite(IN3,in3);
    digitalWrite(IN2,in2);  digitalWrite(IN4,in4);
    analogWrite(PWMA,pwmA); analogWrite(PWMB,pwmB);
    delay(dl);
  }

  void Motor(char d1,int ml,char dr,int mr,int t)
  {
    if      (dl=="F")
    in1=1;in2=0;
    else if (d1=="B")
    in1=0;in2=1;
    else    ()
    in1=0;in2=0;
    
  }
  }
  void delayS()
  {
    Control(0,0,0,0,0,0,100);
  }
  void Stop()
  {
    Control(0,0,0,0,0,0,100);
    while(true);
  }

  void TracklinePID()
  {
    readSensor();
    Serial.print(s1);Serial.print(":");
    Serial.print(s2);Serial.print(":");
    Serial.print(s3);Serial.print(":");
    Serial.print(s4);Serial.print(":");
    Serial.print(s5);Serial.println(":");
    
    if      (s1==1 && s2==0 && s3==0 && s4==0 && s5==0)
    {Control(1,0,125+adj,1,0,150-adj,100);}
    
    else if (s1==1 && s2==1 && s3==0 && s4==0 && s5==0)
    {Control(1,0,125+adj,1,0,150-adj,100);}

    else if (s1==0 && s2==1 && s3==0 && s4==0 && s5==0)
    {Control(1,0,130+adj,1,0,150-adj,100);}

    else if (s1==0 && s2==1 && s3==1 && s4==0 && s5==0)
    {Control(1,0,130+adj,1,0,150-adj,100);}
    
    else if (s1==0 && s2==1 && s3==1 && s4==0 && s5==0)
    {Control(1,0,130+adj,1,0,150-adj,100);}
    
    else if (s1==0 && s2==0 && s3==1 && s4==0 && s5==0)
    {Control(1,0,150+adj,1,0,150-adj,100);}
    
    else if (s1==0 && s2==0 && s3==1 && s4==1 && s5==0)
    {Control(1,0,130+adj,1,0,150-adj,100);}
    
    else if (s1==0 && s2==1 && s3==0 && s4==1 && s5==0)
    {Control(1,0,130+adj,1,0,150-adj,100);}
    
    else if (s1==0 && s2==0 && s3==0 && s4==1 && s5==1)
    {Control(0,1,125+adj,1,0,150-adj,100);}
    
    else if (s1==0 && s2==0 && s3==0 && s4==0 && s5==1)
    {Control(0,1,125+adj,1,0,150-adj,100);}
    
     else
    {Stop();}
  }
  
  }

  
  void Trackline_L(int line)
  {
  int count=0;
  while(count<line){
    TracklinePID();
    if (s3==1 && s2==1)
    {
      while(s3==1 && s2==1){
      Motor('F','F',10);
      readSensor();
      
    }
    count++;
    }  
  }
  }
  
  void Trackline_R(int line)
  {
  int count=0;
  while(count<line){
    TracklinePID();
    if (s3==1 && s4==1)
    {
      while(s3==1 && s4==1){
      Motor('F','F',10);
      readSensor();
      
    }
    count++;
    }  
  }
  Motor('S','S',10);
  }
  ///
  void turnRight(){
  Motor('F','F',100);
  readSensor();
  while ( s3==0 ){
    Motor('F','B',10);
    readSensor();
  }
  Motor('S','S',10);
  }
  ///
  void turnLeft(){
  Motor('F','F',100);
  readSensor();
  while ( s3==0 ){
    Motor('B','F',10);
    readSensor();
  }
  Motor('S','S',10);
  }
void loop() 
{
  TracklinePID();
   
}
  

  
