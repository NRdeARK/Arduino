#define led1 10
#define led2 9
#define led3 8
#define led4 7
#define led5 6
#define led6 5
int t=1;
void setup() {
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);

}
void ledcon(int a,int b,int c,int d,int e,int f){
    digitalWrite(led1,a);
    digitalWrite(led2,b);
    digitalWrite(led3,c);
    digitalWrite(led4,d);
    digitalWrite(led5,e);
    digitalWrite(led6,f);
}

void loop() {
  if(t%7==0){
    ledcon(0,0,0,0,0,0);
    t++;
    delay(100);
  }
  else if(t%7==1){
    ledcon(1,0,0,0,0,0);
    t++;
    delay(100);
  }
  else if(t%7==2){
    ledcon(1,1,0,0,0,0);
    t++;
    delay(100);
  }
  else if(t%7==3){
    ledcon(1,1,1,0,0,0);
    t++;
    delay(100);
  }
  else if(t%7==4){
    ledcon(1,1,1,1,0,0);
    t++;
    delay(100);
  }
  else if(t%7==5){
    ledcon(1,1,1,1,1,0);
    t++;
    delay(100);
  }
  else if(t%7==6){
    ledcon(1,1,1,1,1,1);
    t++;
    delay(100);
  }

}
