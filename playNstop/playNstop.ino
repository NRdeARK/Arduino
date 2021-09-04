#define LED1 10
#define LED2 9
#define LED3 8
#define LED4 7
#define LED5 6
#define LED6 5
int x = 10;
int a = 0;
void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}
void dub() {
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
}


void RtoL() {
  String stringledcon;
  while (true) {
      stringledcon = Serial.readString();
      if(stringledcon.toInt()==1||stringledcon.toInt()==0){
      Serial.print(stringledcon);
      if (stringledcon == 1 && a == 0) {
        digitalWrite(5, 1);
        delay(100);
        a=1;
      }
      else if(stringledcon == 1 && a == 1) {
          digitalWrite(5, 1);
          digitalWrite(6, 1);
          delay(100);
          a=2;
        }
      else if(stringledcon == 1 && a == 2) {
          digitalWrite(5, 1);
          digitalWrite(6, 1);
          digitalWrite(7, 1);
          delay(100);
          a=3;
        }
      else if(stringledcon == 1 && a == 3) {
          digitalWrite(5, 1);
          digitalWrite(6, 1);
          digitalWrite(7, 1);
          digitalWrite(8, 1);
          delay(100);
          a=4;
        }
      else if(stringledcon == 1 && a == 4) {
          digitalWrite(5, 1);
          digitalWrite(6, 1);
          digitalWrite(7, 1);
          digitalWrite(8, 1);
          digitalWrite(9, 1);
          delay(100);
          a=5;
        }
      else if(stringledcon == 1 && a == 5) {
          digitalWrite(5, 1);
          digitalWrite(6, 1);
          digitalWrite(7, 1);
          digitalWrite(8, 1);
          digitalWrite(9, 1);
          digitalWrite(10, 1);
          delay(100);
          a=6;
        }
      else if(stringledcon == 1 && a == 6) {
          dub();
          delay(100);
          a = 0;
        }
        else if(stringledcon == 0) {
        while(Serial.readString()!=1){
        }
        }
//         else if(stringledcon == 3) {
//        a=0;
//        break;
//         }
          
      else {Serial.println("ERROR");
       break;}
        }
              
    }
}
  
void LtoR() {
  String stringledcon;
  while (true) {
      stringledcon = Serial.readString();
      if(stringledcon.toInt()==1||stringledcon.toInt()==0){
      if (stringledcon == 1 && a == 0) {
        digitalWrite(10,1);
        delay(100);
        a=1;
      }
      else if(stringledcon == 1 && a == 1) {
          digitalWrite(10,1);
  digitalWrite(9,1);
          delay(100);
          a=2;
        }
      else if(stringledcon == 1 && a == 2) {
          digitalWrite(10,1);
  digitalWrite(9,1);
  digitalWrite(8,1);
          delay(100);
          a=3;
        }
      else if(stringledcon == 1 && a == 3) {
           digitalWrite(10,1);
  digitalWrite(9,1);
  digitalWrite(8,1);
  digitalWrite(7,1);
          delay(100);
          a=4;
        }
      else if(stringledcon == 1 && a == 4) {
          digitalWrite(10,1);
  digitalWrite(9,1);
  digitalWrite(8,1);
  digitalWrite(7,1);
  digitalWrite(6,1);
          delay(100);
          a=5;
        }
      else if(stringledcon == 1 && a == 5) {
          digitalWrite(10,1);
  digitalWrite(9,1);
  digitalWrite(8,1);
  digitalWrite(7,1);
  digitalWrite(6,1);
  digitalWrite(5,1);
          delay(100);
          a=6;
        }
      else if(stringledcon == 1 && a == 6) {
          dub();
          delay(100);
          a = 0;
        }
        else if(stringledcon == 0) {
        while(Serial.readString()!=1){
        }
        }
//         else if(stringledcon == 3) {
//        a=0;
//        break;
//         }
          
      else {Serial.println("ERROR");
       break;}
        }
              
    }
}
void StoC() {
  String stringledcon;
  while (true) {
      stringledcon = Serial.readString();
      if(stringledcon.toInt()==1||stringledcon.toInt()==0){
      if (stringledcon == 1 && a == 0) {
        digitalWrite(10,1);
        delay(100);
        a=1;
      }
      else if(stringledcon == 1 && a == 1) {
          digitalWrite(10,1);
  digitalWrite(5,1);
          delay(100);
          a=2;
        }
      else if(stringledcon == 1 && a == 2) {
          digitalWrite(10,1);
  digitalWrite(5,1);
  digitalWrite(9,1);
          delay(100);
          a=3;
        }
      else if(stringledcon == 1 && a == 3) {
           digitalWrite(10,1);
  digitalWrite(5,1);
  digitalWrite(9,1);
  digitalWrite(6,1);
          delay(100);
          a=4;
        }
      else if(stringledcon == 1 && a == 4) {
          digitalWrite(10,1);
  digitalWrite(5,1);
  digitalWrite(9,1);
  digitalWrite(6,1);
  digitalWrite(8,1);
          delay(100);
          a=5;
        }
      else if(stringledcon == 1 && a == 5) {
          digitalWrite(10,1);
  digitalWrite(5,1);
  digitalWrite(9,1);
  digitalWrite(6,1);
  digitalWrite(8,1);
  digitalWrite(7,1);
          delay(100);
          a=6;
        }
      else if(stringledcon == 1 && a == 6) {
          dub();
          delay(100);
          a = 0;
        }
        else if(stringledcon == 0) {
        while(Serial.readString()!=1)
        {}
        }
//        else if(stringledcon == 3) {
//        a=0;
//        break;
//        }
          
      else {Serial.println("ERROR");
       break;}
        }
              
    }
}
void selec(){
  String stringledcon1;
  while(true){
  stringledcon1="";
  while(stringledcon1==""){
  stringledcon1 = Serial.readString();
}
 if(stringledcon1.toInt() && 7>stringledcon1.toInt()>0 ){
 int ledcon = stringledcon1.toInt();

 if(ledcon==1){
  Serial.println("LtR");
  LtoR();
  Serial.println("exit");
 }
 else if(ledcon==2){
  Serial.println("RtL");
  RtoL();
  Serial.println("exit");
 }
 else if(ledcon==3){
  Serial.println("StC");
  StoC();
  Serial.println("exit");
 }
 else{
  Serial.println(" Error");
 }
}
}
}
void loop() {
selec();
  

}
