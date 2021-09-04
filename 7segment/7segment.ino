int num[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F , 0x38, 0x3D};
//               g f e d c b a
//  a      L = 0 0 1 1 1 0 0 0 = 0x38
//f    b   G = 0 0 1 1 1 1 0 1 = 0x3D
//   g
//e    c
//  d
#define sw1 12
#define sw2 11
int a, b, lasta=1, lastb=1;
long timea,timeb;
int randNum,count;
bool checkA = false, checkB = false, regame = true;
void setup() {
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  DDRD = 0xFF;
}
void loop()
{
  if (regame)
  {
    randNum = millis() % 10;
    regame = false;
  }
  count = 1;

  while (true)
  {
    a = digitalRead(sw1);
    b = digitalRead(sw2);

    if (a == 0 && millis() > timea + 50)
    {checkA = true;timea=millis();}
    else if(a == 0)
    {timea=millis();}
    if (checkA==true)
    {
      count=(count+1)%10;
      checkA = false;
    }
    if (b == 0 && millis() > timeb + 50)break;
    PORTD = ~num[count];
  }
  if (count > randNum)
  {
    PORTD = ~num[11];
  }
  if (count < randNum)
  {
    PORTD = ~num[10];
  }
  if (count = randNum)
  {
    PORTD = ~num[0];
    regame = true;
  }
  delay(3000);
}
