  #define CLP 31
  #define S5  22
  #define S4  7
  #define S3  6
  #define S2  5
  #define S1  55
  int s1,s2,s3,s4,s5,clp;
  
void setup() {
  pinMode(S1,INPUT);  
  pinMode(S2,INPUT);  
  pinMode(S3,INPUT);  
  pinMode(S4,INPUT);  
  pinMode(S5,INPUT);
  pinMode(CLP,INPUT);
  Serial.begin(9600);
}
void readsen() {
  s1=digitalRead(S1);
  s2=digitalRead(S2);
  s3=digitalRead(S3);
  s4=digitalRead(S4);
  s5=digitalRead(S5);
  clp=digitalRead(CLP);
  
  // 0 to 1
  if(s1 == 1) {s1 = 0;} else {s1 = 1;}
  if(s2 == 1) {s2 = 0;} else {s2 = 1;}
  if(s3 == 1) {s3 = 0;} else {s3 = 1;}
  if(s4 == 1) {s4 = 0;} else {s4 = 1;}
  if(s5 == 1) {s5 = 0;} else {s5 = 1;} 

  Serial.print(s1);
  Serial.print(":");
  Serial.print(s2);
  Serial.print(":");
  Serial.print(s3);
  Serial.print(":");
  Serial.print(s4);
  Serial.print(":");
  Serial.print(s5);
  Serial.print(":");
  Serial.println(clp);

  delay(10);
}
void loop() {
  readsen();
}
