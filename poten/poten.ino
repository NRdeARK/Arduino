int num[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };
int Button1 = 10;
int Button2 = 9;
unsigned long CurrentTime;
unsigned long PreviousTime = 0;
int count;
void setup()
{
 //Serial.begin(9600);
 DDRD = 0xFF;// set pins 0 - 7 to be OUTPUT
// pinMode(Button1, INPUT_PULLUP);
// pinMode(Button2, INPUT_PULLUP); 
}

void loop()
{
 // int Bt1 = digitalRead(Button1);
 PORTD = ~num[0];
 // Serial.println(digitalRead(Button1));
// if(Bt1 == 0);
//  {
//      PORTD = ~num[7];
//  }
 
}
//int num[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };
//
//void setup() {
//
//  DDRD = 0xFF;
//
//  PORTD = ~num[9];
//
//}
//void loop()
//{}
