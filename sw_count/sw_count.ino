#define sw1 4
#define sw2 13
int count=0;
void setup() {
  Serial.begin(9600);
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  

}
void add(){
  if (digitalRead(sw1)==0){
    delay(50);
    if (digitalRead(sw1)==0){
      if(count==99){count=-1;}
        count++;
        Serial.print("count up : ");
        Serial.println(count);
  }
  while(digitalRead(sw1)==0){}
}
}
void sub(){
  if (digitalRead(sw2)==0){
    delay(50);
    if (digitalRead(sw2)==0){
      if(count==0){count=100;}
        count--;
        Serial.print("count down : ");
        Serial.println(count);
  }
  while(digitalRead(sw2)==0){}
}
}

void loop() {
  sub();
  add();
}
