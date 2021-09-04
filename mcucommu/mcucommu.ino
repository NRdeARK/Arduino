#include <SoftwareSerial.h>


void setup(){
Serial.begin(9600);
Serial1.begin(9600);
delay(2000);
}
void loop()
{
Serial.print("1");
Serial1.println("1");
delay(1000);
}
