void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
 
}

void loop() {
  digitalWrite(4,LOW);
  digitalWrite(2,HIGH);
  delay(100);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  delay(100);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(100);
}
