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
  int s1,s2,s3,s4,s5,clp;
  ///echoR
  #define pingPinR  24
  #define inPinR    22
  long durationR, cmR;
  ///echoL
  #define pingPinL  28
  #define inPinL    26
  long durationL, cmL;
  
void setup() {
  ///controlmotor
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  ///sensor
  pinMode(S1,INPUT);  
  pinMode(S2,INPUT);  
  pinMode(S3,INPUT);  
  pinMode(S4,INPUT);  
  pinMode(S5,INPUT);
  pinMode(CLP,INPUT);
  ///echoR
  pinMode(pingPinR, OUTPUT);
  pinMode(inPinR, INPUT);
  ///echoL
  pinMode(pingPinL, OUTPUT);
  pinMode(inPinL, INPUT);
  ///
  Serial.begin(9600);

}
///motor
void control(int in4, int in3, int pwmA, int in2, int in1, int pwmB, int dl)//controlRobot
  {
    digitalWrite(IN1,in1);  digitalWrite(IN3,in3);
    digitalWrite(IN2,in2);  digitalWrite(IN4,in4);
    analogWrite(PWMA,pwmA); analogWrite(PWMB,pwmB);
    delay(dl);
  }
///sensor
void readsen() {
  s1=digitalRead(S1);
  s2=digitalRead(S2);
  s3=digitalRead(S3);
  s4=digitalRead(S4);
  s5=digitalRead(S5);
  clp=digitalRead(CLP);
  
  // 0 to 1
  if(s1 == 1) {s1 = 0;} else {s1 = 1;}
  if(s2 == 1) {s2 = 0;} else {s2 = 1;}
  if(s3 == 1) {s3 = 0;} else {s3 = 1;}
  if(s4 == 1) {s4 = 0;} else {s4 = 1;}
  if(s5 == 1) {s5 = 0;} else {s5 = 1;} 

  delay(10);
}
///echoR
void echoR()
{
digitalWrite(pingPinR, LOW);
delayMicroseconds(2);
digitalWrite(pingPinR, HIGH);
delayMicroseconds(5);
digitalWrite(pingPinR, LOW);
durationR = pulseIn(inPinR, HIGH);
cmR = (durationR)/29/2;
delay(100);
}
void echoL()
{
digitalWrite(pingPinL, LOW);
delayMicroseconds(2);
digitalWrite(pingPinL, HIGH);
delayMicroseconds(5);
digitalWrite(pingPinL, LOW);
durationL = pulseIn(inPinL, HIGH);
cmL = (durationL)/29/2;
delay(100);
}
void wallR()
{
  readsen();
  while(clp==0)
  {
    readsen();
    control(1,0,150,1,0,150,10);
  }
  ///?????????1
  control(0,1,250,0,1,250,25);
  ///???????????????????????????
  control(1,0,250,0,1,250,600);
  ///?????????2
  control(0,1,250,0,1,250,300);
  ///??????????????????????????????
  control(0,1,250,1,0,250,25);
}

void wallL()
{
  readsen();
  while(clp==0)
  {
    readsen();
    control(1,0,250,1,0,250,10);
  }
  ///?????????1
  control(0,1,250,0,1,250,25);
  ///??????????????????????????????
  control(0,1,250,1,0,250,600);
  ///?????????2
  control(0,1,250,0,1,250,300);
  ///???????????????????????????
  control(1,0,250,0,1,250,25);
}

void triRoad()
{
  ///?????????1
  control(0,1,250,0,1,250,300);
  ///?????????1
  control(1,0,250,1,0,250,800);
  ///?????????1
  control(1,0,250,0,1,250,500);
  ///?????????2
  control(0,1,250,0,1,250,200);
  
  
  ///?????????2
  control(1,0,250,1,0,250,800);
  ///????????????1
  control(0,1,250,1,0,250,500);
  ///?????????3
  control(0,1,250,0,1,250,300);
  ///?????????3
  control(1,0,250,1,0,250,800);
  
}
void loop() 
{
  wallR();
  wallR();
  wallR();
  wallL();
  wallL();
  wallR();
  wallL();
  wallL();
  wallL();
  triRoad();
  wallR();
  wallL();
  wallR();
  wallR();
  wallR();
  wallL();
  
   


  control(0,0,150,0,0,150,100);
  while(true){}
}
