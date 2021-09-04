String led,a;
#include <SoftwareSerial.h>
SoftwareSerial Ardu(9,10); // RX | TX
void setup()
{
  Serial.begin(9600);
  Ardu.begin(9600);
  pinMode(6,INPUT);
}
void loop() {
if (Ardu.available()>0){
  
    Serial.println("1");
    a=Ardu.readStringUntil('&');

///////////////////////////////
    
  led=a.substring(0,a.indexOf('&'));
    
///////////////////////////////
  Serial.print("led : ");    
  Serial.println(led);    
  analogWrite(6,map(led.toInt(),2,1000,0,255));
  Serial.println(map(led.toInt(),2,1000,0,255));
  }
}
