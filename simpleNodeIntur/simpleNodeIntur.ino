#define led1 D0
#define led2 D1
#define led3 D2
#define led4 D3
#define led5 D4
#define led6 D5
#define sw1 D6
#define sw2 D7
int Status = 1,timex=0;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sw1), blink1, FALLING);
  attachInterrupt(digitalPinToInterrupt(sw2), blink2, FALLING);
}
int led(int a, int b, int c, int d, int e, int f) {
  digitalWrite(led1, a);
  digitalWrite(led2, b);
  digitalWrite(led3, c);
  digitalWrite(led4, d);
  digitalWrite(led5, e);
  digitalWrite(led6, f);
}
ICACHE_RAM_ATTR void blink1() {
  if(timex+100>millis()){Serial.print("A");}else{
//    if (Status < 6) {

      Status++;
      timex=millis();
        while(timex+100>millis())
        {
          Serial.print(".");
          } 
      Serial.print("A");
      timex=millis();
}
}
ICACHE_RAM_ATTR void blink2() {
  if(timex+100>millis()){Serial.print("A");}else{
//    if (Status > 0) {
      Status--;
      timex=millis();
        while(timex+100>millis())
        {
          Serial.print(".");
          }
      
      while(sw2==0){}
      Serial.print("B");
      timex=millis();
}
}

void loop() {
  Serial.println(Status);
  if (Status>6){Status=6;}
  if (Status<0){Status=0;}
  if (Status == 0) {
    led(0, 0, 0, 0, 0, 0);
  }
  else if (Status == 1) {
    led(1, 0, 0, 0, 0, 0);
  }
  else if (Status == 2) {
    led(1, 1, 0, 0, 0, 0);
  }
  else if (Status == 3) {
    led(1, 1, 1, 0, 0, 0);
  }
  else if (Status == 4) {
    led(1, 1, 1, 1, 0, 0);
  }
  else if (Status == 5) {
    led(1, 1, 1, 1, 1, 0);
  }
  else {
    led(1, 1, 1, 1, 1, 1);
  }
  delay(10);
}
