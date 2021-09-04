float analogSensor;
float voltvalue;
int a;
float d;
  void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
//////////////////////
void value(int b){
  if(1000<b)
  {d=5;}
  else if(15<b)
  {d=b/200.00;}
  else
  {d=0;}
}
  void loop()
{
  //input
  analogSensor=analogRead(A0);
  a=map(analogSensor,1000.00,10.00,0.00,5.00);
  value(analogSensor);
  voltvalue =  d;
  //serial
  Serial.print(d);
  Serial.print("Analog = ");
  Serial.print(analogSensor);
  Serial.print("  ");
  Serial.print("Voltage = ");
  Serial.println(voltvalue);
  delay(100);
}
