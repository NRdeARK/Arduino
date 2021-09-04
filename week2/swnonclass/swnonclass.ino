#define s1 12
#define s2 11
#define s3 10
#define o1 8
#define o2 7
#define o3 6
int a, b, c;
long timea = 0, timeb = 0, timec = 0;
bool prea = 0, preb = 0, prec = 0;
long timex;
void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT_PULLUP);
  pinMode(o1, OUTPUT);
  pinMode(o2, OUTPUT);
  pinMode(o3, OUTPUT);
}

void loop()
{
  a = digitalRead(s1);
  if (a == 1 && millis() > timea + 50)
  {
    prea = !prea;
    digitalWrite(o1, prea);
    timea = millis();
  }
  else if (a == 1)
  {
    timea = millis();
  }
  else if (prea == 1 && millis() > timea + 3000)
  {
    prea = 0;
    digitalWrite(o1, 0);
  }
  b = digitalRead(s2);
  if (prea == 1 || prec == 1)
  {
    if (preb == 1 && millis() > timeb + 2000)
    {
      preb = 0;
      digitalWrite(o2, 0);
    }
    else if (preb == 1)
    {
      if ((millis() - timex) % 1000 > 500)
      {
        digitalWrite(o2, 1);
      }
      else
      {
        digitalWrite(o2, 0);
      }
    }
  }
  else if (b == 0 && millis() > timeb + 50)
  {
    preb = 1;
    digitalWrite(o2, 0);
    timeb = millis();
    timex = millis();
  }
  else if (b == 0)
  {
    if ((millis() - timex) % 1000 > 500)
    {
      digitalWrite(o2, 1);
    }
    else
    {
      digitalWrite(o2, 0);
    }
    timeb = millis();
  }
  else if (preb == 1 && millis() > timeb + 2000)
  {
    preb = 0;
    digitalWrite(o2, 0);
  }
  else if (preb == 1)
  {
    if ((millis() - timex) % 1000 > 500)
    {
      digitalWrite(o2, 1);
    }
    else
    {
      digitalWrite(o2, 0);
    }
  }
  c = digitalRead(s3);
  if (prea == 1)
  {
    if (prec == 1 && millis() > timec + 3000)
    {
      prec = 0;
      digitalWrite(o3, 0);
    }
  }
  else if (c == 0 && millis() > timec + 50)
  {
    prec = !prec;
    digitalWrite(o3, prec);
    timec = millis();
  }
  else if (c == 0)
  {
    timec = millis();
  }
  else if (prec == 1 && millis() > timec + 3000)
  {
    prec = 0;
    digitalWrite(o3, 0);
  }
}
