#define sw1 10
#define sw2 11
int count=0,num0,num1;
int num[] = { 0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10 };
int digit[]={ 0xFE, 0xFD };
void setup() {
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  DDRD = 0xFF;
  DDRB = 0x03;
  
}
 void numseg(){
  if (digitalRead(sw2)==0){
    delay(10);
    if (digitalRead(sw2)==0){
      if(count==0){count=100;}
        count--;
         num0=count%10;
  num1=count/10;
  PORTD=num[num0];
  PORTB=digit[0];
  delay(10);
  PORTD=num[num1];
  PORTB=digit[1];
  delay(10);
  }
   while(digitalRead(sw2)==0){
    num1=count/10;
  PORTD=num[num0];
  PORTB=digit[0];
  delay(10);
  PORTD=num[num1];
  PORTB=digit[1];
  delay(10);
    }
  }
   if (digitalRead(sw1)==0){
    delay(10);
    if (digitalRead(sw1)==0){
      if(count==99){count=-1;}
        count++;
         num0=count%10;
  num1=count/10;
  PORTD=num[num0];
  PORTB=digit[0];
  delay(10);
  PORTD=num[num1];
  PORTB=digit[1];
  delay(10);
  }
   while(digitalRead(sw1)==0){
    num1=count/10;
  PORTD=num[num0];
  PORTB=digit[0];
  delay(10);
  PORTD=num[num1];
  PORTB=digit[1];
  delay(10);
    }
  }
 num1=count/10;
  PORTD=num[num0];
  PORTB=digit[0];
  delay(10);
  PORTD=num[num1];
  PORTB=digit[1];
  delay(10);
}

void loop() {

  numseg();
  
}
