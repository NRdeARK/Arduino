#define led1 10
#define led2 9
#define led3 8
#define led4 7
#define led5 6
#define led6 5
int y,i=0,x;
int A=0;
int B=0;
int C=0;
int D=0;
int E=0;
int F=0;

void setup() {

  Serial.begin(9600);
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);

}
void ledcon1(int a,int b,int c,int d,int e,int f){
    digitalWrite(led1,a);
    digitalWrite(led2,b);
    digitalWrite(led3,c);
    digitalWrite(led4,d);
    digitalWrite(led5,e);
    digitalWrite(led6,f);
}
void ledconX(int a,int b){
    digitalWrite(a,b);
    
}
void ledcon2(int x){
  y=x%7;
      if (y==0){
    ledcon1(0,0,0,0,0,0);
    delay(100);
    }
      else if(y==1){
    ledcon1(1,0,0,0,0,0);
    delay(100);
    }
      else if(y==2){
    ledcon1(1,1,0,0,0,0);
    delay(100);
    }
      else if(y==3){
    ledcon1(1,1,1,0,0,0);
    delay(100);
    }
      else if(y==4){
    ledcon1(1,1,1,1,0,0);
    delay(100);
    }
      else if(y==5){
    ledcon1(1,1,1,1,1,0);
    delay(100);
    }
      else if(y==6){
    ledcon1(1,1,1,1,1,1);
    delay(100);
  }
}


void loop() {
  String stringledcon;
  while(true){
  stringledcon="";
  while(stringledcon==""){
  stringledcon = Serial.readString();
}
 if(stringledcon.toInt() && 7>stringledcon.toInt()>0 ){
 int ledcon = stringledcon.toInt();
 if(ledcon==1)
 {
Serial.print("led:");
 Serial.print(ledcon);
  if(A==1){
    ledconX(10,0);
    Serial.print(" OFF");
 Serial.println();
 A=0;  
  }
  else{
    ledconX(10,1);
    Serial.print(" ON");
 Serial.println();
 A=1;
 }
 
  }
  ////////////////////////
  if(ledcon==2)
 {
Serial.print("led:");
 Serial.print(ledcon);
 if(B==1){
    ledconX(9,0);
    Serial.print(" OFF");
 Serial.println();B=0;
  }
  else{
    ledconX(9,1);
    Serial.print(" ON");
 Serial.println();}B=1;
  
  }
  /////////////////////////////
  if(ledcon==3)
 {
Serial.print("led:");
 Serial.print(ledcon);
  if(C==1){
    ledconX(8,0);
    Serial.print(" OFF");
 Serial.println();C=0;  
  }
  else{
    ledconX(8,1);
    Serial.print(" ON");
 Serial.println();C=1;}
  }
  ///////////////
  if(ledcon==4)
 {
Serial.print("led:");
 Serial.print(ledcon);
  if(D==1){
    ledconX(7,0);
    Serial.print(" OFF");
 Serial.println();D=0;  
  }
  else{
    ledconX(7,1);
    Serial.print(" ON");
 Serial.println();D=1;}
  }
  ///////////////////
  if(ledcon==5)
 {
Serial.print("led:");
 Serial.print(ledcon);
 if(E==1){
    ledconX(6,0);
    Serial.print(" OFF");
 Serial.println();E=0;  
  }
  else{
    ledconX(6,1);
    Serial.print(" ON");
 Serial.println();E=1;}
  
  }
 /////////////////////
  if(ledcon==6)
 {
Serial.print("led:");
 Serial.print(ledcon);
 if(F==1){
    ledconX(5,0);
    Serial.print(" OFF");
 Serial.println();F=0;  
  }
  else{
    ledconX(5,1);
    Serial.print(" ON");
 Serial.println();F=1;}  
  }
  }
 else{
 Serial.println("EROR");
 }
  }
}
