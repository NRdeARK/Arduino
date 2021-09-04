#define R 11
#define G 9
#define B 10
#define light 5
const byte sw1 = 2;
bool lightmode=0,change=0;
int i,in1,in2,mode=1;
void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(light, INPUT);
  attachInterrupt(digitalPinToInterrupt(sw1), intur1, RISING);
}
int RGBled(int a, int b, int c) {
  analogWrite(R, a);
  analogWrite(G, b);
  analogWrite(B, c);
}
void flow(){
  for (i = 0; i <= 178; i++) {
    RGBled(0, i, 178);
    delay(10);
  }
  for (i = 0; i <= 178;i++) {
    RGBled(i, 178, 178 - i);
    delay(10);
  }
  for (i = 0; i <= 178; i++) {
    RGBled(178, 178 - i, 0);
    delay(10);
  }
  for (i = 0; i <= 178; i++) {
    RGBled(178-i,0, i);
    delay(10);
  }
}
void intur1() { 
  in1=digitalRead(3);
  in2=digitalRead(4);
  if(in1==0&&in2==0){mode=1;}
  if(in1==1&&in2==0){mode=2;}
  if(in1==0&&in2==1){mode=3;}
  if(in1==1&&in2==1){mode=4;}
  }
void lightdelay(){
  int timex=millis(),i=0;
  while(i<500){
    if(digitalRead(light)==1&&lightmode==0){
      i++;
      delay(1);
      Serial.println(i);
      Serial.println("ON");
      change=1;
    }
    else if(digitalRead(light)==0&&lightmode==1){
      i++;
      delay(1);
      Serial.println(i);
      Serial.println("OFF");
      change=1;
    }
    else{i=5500;}
  }
  Serial.print("CHANGE ");
  if(change==1&&i==500){
  Serial.print(lightmode);
  lightmode=!lightmode;
  Serial.print(" CHANGE TO ");
  Serial.print(lightmode);
  Serial.print("BY ");
  Serial.println(i);
  change=0;
  }
}
void loop() {
//  Serial.println(mode);
  Serial.println(lightmode);
  
  if (mode==1){if(lightmode==1){RGBled(255,255,255);lightdelay();}else{RGBled(0,0,0);lightdelay();}}
  if (mode==2){RGBled(255,40,10);}
  if (mode==3){RGBled(255,255,255);}
  if (mode==4){flow();}
}
