const byte R = 11;
const byte G = 10;
const byte B = 9;

const byte sw1 = 2;
const byte sw2 = 3;
float analogSensor;
int voltvalue;
int a,colour=11;
float d;
bool mode=1;
//volatile byte state = LOW;
int count=0;


void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(A0,INPUT);
  attachInterrupt(digitalPinToInterrupt(sw1), blink1, FALLING);
  attachInterrupt(digitalPinToInterrupt(sw2), blink2, FALLING);
}



void loop() {
  if(mode==1){
  a=analogRead(A0)/1027.00*255;
  analogWrite(colour,a);
  Serial.println(colour);
  }
}

void blink1() {
  delay(50);
  noInterrupts();
  if(digitalRead(sw1)==0){
    if (colour==R){
      colour=G;
  }
  else if (colour==G){
      colour=B;
  }
  else if (colour==B){
      colour=R;
  }
  }
  //while(digitalRead(sw1)==0){}
  interrupts();
 }


void blink2() {
  delay(50);
  noInterrupts();
  if (digitalRead(sw2)==0){  
    mode= !mode;
  }
  //while(digitalRead(sw2)==0){}
  interrupts();
}

  
