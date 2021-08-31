int a = 11;
int b = 12;
int c = 10;
void setup() 
{
}

void loop() 
{
 //LED 1 a->b
 pinMode(a,OUTPUT);
 pinMode(b,OUTPUT);
 pinMode(c,INPUT);
 digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 delay(500);

 //LED 2 b->a
 pinMode(a,OUTPUT);
 pinMode(b,OUTPUT);
 pinMode(c,INPUT);
 digitalWrite(a,LOW);
 digitalWrite(b,HIGH);
 delay(500);

 //LED 3 b->c
 pinMode(a,INPUT);
 pinMode(b,OUTPUT);
 pinMode(c,OUTPUT);
 digitalWrite(b,HIGH);
 digitalWrite(c,LOW);
 delay(500);

  //LED 4 c-b
 pinMode(a,INPUT);
 pinMode(b,OUTPUT);
 pinMode(c,OUTPUT);
 digitalWrite(b,LOW);
 digitalWrite(c,HIGH);
 delay(500);

//  //LED 5 a->c
// pinMode(a,OUTPUT);
// pinMode(b,INPUT);
// pinMode(c,OUTPUT);
// digitalWrite(a,HIGH);
// digitalWrite(c,LOW);
// delay(100);
//
//  //LED 6 c->a
// pinMode(a,OUTPUT);
// pinMode(b,INPUT);
// pinMode(c,OUTPUT);
// digitalWrite(a,LOW);
// digitalWrite(c,HIGH);
// delay(100);
//
//  //LED 5 a->c
// pinMode(a,OUTPUT);
// pinMode(b,INPUT);
// pinMode(c,OUTPUT);
// digitalWrite(a,HIGH);
// digitalWrite(c,LOW);
// delay(100);
//
//   //LED 4 c-b
// pinMode(a,INPUT);
// pinMode(b,OUTPUT);
// pinMode(c,OUTPUT);
// digitalWrite(c,HIGH);
// digitalWrite(b,LOW);
// delay(100);
//
//  //LED 3 b->c
// pinMode(a,INPUT);
// pinMode(b,OUTPUT);
// pinMode(c,OUTPUT);
// digitalWrite(b,HIGH);
// digitalWrite(c,LOW);
// delay(100);
//
// //LED 2 b->a
// pinMode(a,OUTPUT);
// pinMode(b,OUTPUT);
// pinMode(c,INPUT);
// digitalWrite(a,LOW);
// digitalWrite(b,HIGH);
// delay(100);
 
}
