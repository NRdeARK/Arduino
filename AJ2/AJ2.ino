  #define IN1 13
  #define IN2 12
  #define IN3 9
  #define IN4 8
  #define PWMA 11
  #define PWMB 10
  #define SL 7
  #define SC 6
  #define SR 5
  int sl,sr,sc; 
 void setup() 
  {
  pinMode(SL,INPUT);  pinMode(IN1,OUTPUT);
  pinMode(SR,INPUT);  pinMode(IN2,OUTPUT);
  pinMode(SC,INPUT);  pinMode(IN3,OUTPUT);
                      pinMode(IN4,OUTPUT);
  }

  void Motor(char d1,char d2,int t)
  {
  if      (d1=="F"){digitalWrite(IN1,1);digitalWrite(IN2,0);}
  else if (d1=="B"){digitalWrite(IN1,0);digitalWrite(IN2,1);}
  else             {digitalWrite(IN1,0);digitalWrite(IN2,0);}
  ///
  if      (d2=="F"){digitalWrite(IN3,1);digitalWrite(IN4,0);}
  else if (d2=="B"){digitalWrite(IN3,0);digitalWrite(IN4,1);}
  else             {digitalWrite(IN3,0);digitalWrite(IN4,0);}
  digitalWrite(PWMA,150)  ;digitalWrite(PWMB,150);
  delay(t);
  }

  void Readsensor()
  {
  sl=digitalRead(SL); if (sl==1){sl=0;}else{s1=1;}
  sr=digitalRead(SR); if (sr==1){sr=0;}else{sr=1;}
  sc=digitalRead(SC); if (sc==1){sc=0;}else{sr=1;} 
  }

  void Trackline()
  {
  Readsensor();
  if      (sl==0 && sr==0){Motor('F','F',10);}
  else if (sl==1 && sr==0){Motor('S','F',10);}
  else if (sl==0 && sr==1){Motor('F','S',10);}
  else    {motor(S,S,10);}
  }

  void Trackline_L(int line)
  {
  int count=0;
  while(count<line){
    Trackline();
    if (SC==1&&SR==1)
    {
      while(SC==1 && SR==1){
      Motor('F','F',10);
      Readsensor();
      
    }
    count++;
    }  
  }
  }
  void Trackline_L()
  {
  int count=0;
  while(count<line){
    Trackline();
    if (SC==1&&SL==1)
    {
      while(SC==1 && SL==1){
      Motor('F','F',10);
      Readsensor();
      
    }
    count++;
    }  
  }
  Motor('S','S',10);
  }
  ///
  void Trackline_R(int line)
  {
  int count=0;
  while(count<line){
    Trackline();
    if (SC==1&&SR==1)
    {
      while(SC==1 && SR==1){
      Motor('F','F',10);
      Readsensor();
      
    }
    count++;
    }  
  }
  Motor('S','S',10);
  }
  ///
  void turnRight(){
  Motor('F','F',100);
  Readsensor();
  while ( SC==0 ){
    Motor('F','B',10);
    Readsensor();
  }
  Motor('S','S',10);
  }
  ///
  void turnLeft(){
  Motor('F','F',100);
  Readsensor();
  while ( SC==0 ){
    Motor('B','F',10);
    Readsensor();
  }
  Motor('S','S',10);
  }
void loop() 
{
  Motor('S','S',10);
}
