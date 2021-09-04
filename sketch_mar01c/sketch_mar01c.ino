#define led1 D0
#define led2Pin D1
#define led3Pin D2
#define led4Pin D3
#define led5Pin D4
#define led6Pin D5
#define sw1 D6
#define sw2 D7

int x=0;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2Pin,OUTPUT);
  pinMode(led3Pin,OUTPUT);
  pinMode(led4Pin,OUTPUT);
  pinMode(led5Pin,OUTPUT);
  pinMode(led6Pin,OUTPUT);
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
 Serial.begin(9600);
 attachInterrupt(digitalPinToInterrupt(sw1),Trigger1,FALLING);
 attachInterrupt(digitalPinToInterrupt(sw2),Trigger2,FALLING);
}

ICACHE_RAM_ATTR void Trigger1(){
  Serial.println("A");
  x++;
}

ICACHE_RAM_ATTR void Trigger2(){
  Serial.println("B");
   x--;
}

void loop() {
 Serial.println(x);
 if(x==1){
    digitalWrite(led1,1);
    digitalWrite(led2Pin,0);
    digitalWrite(led3Pin,0);
    digitalWrite(led4Pin,0);
    digitalWrite(led5Pin,0);
    digitalWrite(led6Pin,0);}
  else if(x==2){
   digitalWrite(led1,1);
    digitalWrite(led2Pin,1);
    digitalWrite(led3Pin,0);
    digitalWrite(led4Pin,0);
    digitalWrite(led5Pin,0);
    digitalWrite(led6Pin,0);}
  else if(x==3){
    digitalWrite(led1,1);
    digitalWrite(led2Pin,1);
    digitalWrite(led3Pin,1);
    digitalWrite(led4Pin,0);
    digitalWrite(led5Pin,0);
    digitalWrite(led6Pin,0);}
  else if(x==4){
    digitalWrite(led1,1);
    digitalWrite(led2Pin,1);
    digitalWrite(led3Pin,1);
    digitalWrite(led4Pin,1);
    digitalWrite(led5Pin,0);
    digitalWrite(led6Pin,0);}
  else if(x==5){
    digitalWrite(led1,1);
    digitalWrite(led2Pin,1);
    digitalWrite(led3Pin,1);
    digitalWrite(led4Pin,1);
    digitalWrite(led5Pin,1);
    digitalWrite(led6Pin,0);}
  else if(x==6){
    digitalWrite(led1,1);
    digitalWrite(led2Pin,1);
    digitalWrite(led3Pin,1);
    digitalWrite(led4Pin,1);
    digitalWrite(led5Pin,1);
    digitalWrite(led6Pin,1);}
  else{
    digitalWrite(led1,0);
    digitalWrite(led2Pin,0);
    digitalWrite(led3Pin,0);
    digitalWrite(led4Pin,0);
    digitalWrite(led5Pin,0);
    digitalWrite(led6Pin,0);
    x=0;
  }


}
