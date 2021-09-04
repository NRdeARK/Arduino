#define ledB D0
#define ledR D1
#define ledG D2
#define sw1 D6
#define sw2 D7
float analogSensor;
float voltvalue;
int Mode=0,clr=0;
int r,g,b;
float d;
  void setup()
{
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sw1), blink1, FALLING);
  attachInterrupt(digitalPinToInterrupt(sw2), blink2, FALLING);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
ICACHE_RAM_ATTR void blink1(){
  Serial.println("ON");
  if(Mode==1){Mode=0;}
  clr++;
  }

ICACHE_RAM_ATTR void blink2(){
  Serial.println("OFF");
  if(Mode==0){Mode=1;}
  }
int rgbval(){
  Serial.println(map(analogRead(A0),0,1023,0,255));
  return map(analogRead(A0),0,1023,0,255);
}
  void loop()
{
  if(Mode==0){
    if(clr%3==0)       {
      analogWrite(ledR,rgbval());}
    else if(clr%3==1)  {
      analogWrite(ledG,rgbval());}
    else               {
      analogWrite(ledB,rgbval());}
    }
}
