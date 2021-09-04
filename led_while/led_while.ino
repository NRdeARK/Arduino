#define led1 10
#define led2 9
#define led3 8
#define led4 7
#define led5 6
#define led6 5
int y,i=10;
void setup() {
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);

}
void ledcon1(int a,int b,int c,int d,int e,int f){
    digitalWrite(led1,a);
    digitalWrite(led2,b);
    digitalWrite(led3,c);
    digitalWrite(led4,d);
    digitalWrite(led5,e);
    digitalWrite(led6,f);
}
//void ledcon2(int x){
//  y=x%7;
//    if (y==0){
//      ledcon1(0,0,0,0,0,0);
//      delay(100);
//    }
//      else if(y==1){
//    ledcon1(1,0,0,0,0,0);
//    delay(100);
//    }
//      else if(y==2){
//    ledcon1(1,1,0,0,0,0);
//    delay(100);
//    }
//      else if(y==3){
//    ledcon1(1,1,1,0,0,0);
//    delay(100);
//    }
//      else if(y==4){
//    ledcon1(1,1,1,1,0,0);
//    delay(100);
//    }
//      else if(y==5){
//    ledcon1(1,1,1,1,1,0);
//    delay(100);
//    }
//      else if(y==6){
//    ledcon1(1,1,1,1,1,1);
//    delay(100);
//  }
//}

void loop() {
  while(true){
    while(i>4){
     digitalWrite(i,1);
     delay(100);
     
     i--;
    }
    digitalWrite(10,0);
    digitalWrite(9,0);
    digitalWrite(8,0);
    digitalWrite(7,0);
    digitalWrite(6,0);
    digitalWrite(5,0);
    delay(1000);
    i=10;
   
  }

}
