#include "DHT.h"
DHT dht;
float humidity   ;// ดึงค่าความชื้น
float temperature; // ดึงค่าอุณหภูมิ
#include <SoftwareSerial.h>
SoftwareSerial blue(9,10); // RX | TX
bool state1=0,state2=0;
void setup()
{
  Serial.begin(9600);
  blue.begin(9600);
  dht.setup(3); // data pin d4
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop() {
  if (blue.available() > 0) {
    String a=blue.readString();
    Serial.println(a);
    if(a=="A"){
      Serial.println("A");
      Serial.println("ONA");
      state1=1;
    }
    if(a=="B"){
      Serial.println("B");
      Serial.println("OFFA");
      state1=0;
    }
    if(a=="E"){
      Serial.println("E");
      Serial.println("ONB");
      state2=1;
    }
    if(a=="F"){
      Serial.println("F");
      Serial.println("OFFB");
      state2=0;
    }
  }
  delay(dht.getMinimumSamplingPeriod());
  humidity = dht.getHumidity(); // ดึงค่าความชื้น
  temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ
  Serial.print("TEMP : ");
  Serial.print(temperature);
  Serial.println("°C");
  Serial.print("HUMID : ");
  Serial.print(humidity);
  Serial.println("%");
  
  if (humidity == humidity && temperature == temperature)
  {
  blue.print(temperature);
  blue.print("&");
  blue.print(humidity);
  blue.print("&");
  delay(9000);
  }
  digitalWrite(4,state1);
  digitalWrite(5,state2);
}
