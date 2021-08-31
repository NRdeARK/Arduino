
void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4,1);
  delay(500);
  digitalWrite(5,1);
  delay(500);
  digitalWrite(6,1);
  delay(500);
  digitalWrite(7,1);
  delay(500);
  digitalWrite(7,0);
  digitalWrite(6,0);
  digitalWrite(5,0);
  digitalWrite(4,0);
  delay(500);
  
}
