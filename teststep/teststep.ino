int steps[4][4]=
{{1,0,0,0},
 {0,1,0,0},
 {0,0,1,0},
 {0,0,0,1}};
void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {
  for(int i=0;i<4;i++){
    digitalWrite(8,steps[i][0]);
    digitalWrite(9,steps[i][1]);
    digitalWrite(10,steps[i][2]);
    digitalWrite(11,steps[i][3]);
    delay(10);
  }

}
