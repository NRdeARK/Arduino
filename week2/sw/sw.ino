#define inG 10
#define inY 11
#define inR 12
#define outG 6
#define outY 7
#define outR 8

int redstat, greenstat, yellowstat;
class sw
{
  public:
    int in, out, timesw, debounce;
    bool state = 0, laststate = 0, lim = 1;
    sw(int input, int output)
    {
      in = input;
      out = output;
      timesw = 0;
    }
    //~sw();
    int updatesw();
    void setlim(int para);
};
void sw::setlim(int para)
{
  lim = para;
}

int sw::updatesw()
{
  state = digitalRead(in);
  if (state == 1 && lim == 1)
  {
    if ( millis() > timesw + 10)
    {
      laststate = !laststate;
      digitalWrite(out, laststate);
      timesw = millis();
      Serial.println("UPDATE");
    }
    else
    {
      timesw = millis();
    }
  }
  else
  {
    if (laststate == 1 && millis() > timesw + 3000)
    {
      laststate = 0;
      digitalWrite(out, laststate);
      timesw = millis();
      Serial.println("OFF");
    }
  }
  return laststate;
}



sw green(inG, outG);
sw yellow(inY, outY);
sw red(inR, outR);

void setup() {
  pinMode(inG, INPUT_PULLUP);
  pinMode(inY, INPUT);
  pinMode(inR, INPUT);
  pinMode(outG, OUTPUT);
  pinMode(outY, OUTPUT);
  pinMode(outR, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int redstat = red.updatesw();

  if (redstat == 1)
  {
    Serial.println("A");
    green.setlim(0);
    yellow.setlim(0);
    int greenstat = green.updatesw();
    int yellowstat = yellow.updatesw();
  }
  else if (greenstat == 1)
  {
    Serial.println("B");
    green.setlim(1);
    yellow.setlim(0);
    int greenstat = green.updatesw();
    int yellowstat = yellow.updatesw();
  }
  else
  {
    Serial.println("C");
    green.setlim(1);
    yellow.setlim(1);
    int greenstat = green.updatesw();
    int yellowstat = yellow.updatesw();
  }
}
