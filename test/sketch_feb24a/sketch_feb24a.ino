String a,b;
float c,d;
void setup()
{
  Serial.begin(115200);
Serial.println("***Energy Calculation Program***");
Serial.print ("Power = ");
while(Serial.available()==0){}
if(Serial.available()>0){
    a=Serial.readString();
}
Serial.print(a);
Serial.println("Watt");

Serial.print ("Time = ");
while(Serial.available()==0){}
if(Serial.available()>0){
    b=Serial.readString();
}
Serial.print(b);
Serial.println("Hour");
c=a.toInt();
d=b.toInt();
Serial.print("Energy 1 day = ");
Serial.print(c*d/1000);
Serial.print("unit : ");
Serial.print(c*d/1000*5);
Serial.print("Energy 1 month = ");
Serial.print(c*d/1000*30);
Serial.print("unit : ");
Serial.print(c*d/1000*5*30);
Serial.print("Energy 1 year = ");
Serial.print(c*d/1000);
Serial.print("unit : ");
Serial.print(c*d/1000*5*30*12);

}

void loop()
{
}
