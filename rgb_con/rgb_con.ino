#define R 11
#define G 10
#define B 9
String red,green,blue,a,b,c;

void setup()
{
  Serial.begin(9600);
  pinMode(R , OUTPUT);
  pinMode(G , OUTPUT);
  pinMode(B , OUTPUT);
}

void loop()
{
  
  if (Serial.available()>0){
    Serial.println("1");
    a=Serial.readStringUntil('&');
    b=Serial.readStringUntil('&');
    c=Serial.readString();

///////////////////////////////
    
  red=a.substring(0,a.indexOf('&'));
  green=b.substring(0,b.indexOf('&'));
  blue=c;
    
///////////////////////////////
  Serial.print("red : ");    Serial.println(red);
  Serial.print("green : ");   Serial.println(green);
  Serial.print("blue : ");    Serial.println(blue);

  analogWrite(R,red.toInt());
  analogWrite(G,green.toInt());
  analogWrite(B,blue.toInt());
  }
  

  }
