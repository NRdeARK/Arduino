  #define IN1 11
  #define IN2 10
  #define IN3 9
  #define IN4 8
  #define PWMA 12
  #define PWMB 13
void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

}
void Control(int in1, int in2, int pwmA, int in3, int in4, int pwmB, int dl)//controlRobot
  {
    digitalWrite(IN1,in1);  digitalWrite(IN3,in3);
    digitalWrite(IN2,in2);  digitalWrite(IN4,in4);
    analogWrite(PWMA,pwmA); analogWrite(PWMB,pwmB);
    delay(dl);
  }

void loop() {
  Control(1,0,130,0,1,150,10000);
  Control(0,0,0,0,0,0,1000);
  delay(10000);
  

}
