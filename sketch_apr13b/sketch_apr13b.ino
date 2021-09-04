void setup() {
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  int a=analogRead(A0);
  
if(a>500){
//  Serial.println("ON");
  analogWrite(3,1000);
}else{
//  Serial.println("OFF");
  analogWrite(3,0);
  }
  int b=analogRead(A1);
if(b>500){
//  Serial.println("ON");
  analogWrite(5,1000);
}else{
//  Serial.println("OFF");
  analogWrite(5,0);
}
int c=analogRead(A2);
if(c>500){
  Serial.println("ON");
  analogWrite(6,1000);
}else{
  Serial.println("OFF");
  analogWrite(6,0);
}
//Serial.println(c);
}
