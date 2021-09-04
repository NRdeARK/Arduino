
#include "DHT.h"
DHT dht;
float humidity   ;// ดึงค่าความชื้น
float temperature; // ดึงค่าอุณหภูมิ

#include <SoftwareSerial.h>
SoftwareSerial Ardu(9,10); // RX | TX
void setup()
{
  Serial.begin(9600);
  Ardu.begin(9600);
  pinMode(6,INPUT);
  dht.setup(2); // data pin d4
}
void loop()  
{
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
  Ardu.print(temperature);
  Ardu.print("&");
  Ardu.print(humidity);
  Ardu.print("&");
  }
}
