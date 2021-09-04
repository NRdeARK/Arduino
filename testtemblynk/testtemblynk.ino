#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "fV0WD8ixAST0gTQK9k9V4FbZzLBDhx1k";
char ssid[] = "Kraed";
char pass[] = "blackmuffin";
BlynkTimer timer; 

#include "DHT.h"
DHT dht;
void setup()
{
  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  dht.setup(2); // data pin 2
  timer.setInterval(1000L, myTimerEvent);
}

void myTimerEvent()
{
  float humidity = dht.getHumidity();
  Blynk.virtualWrite(V5,humidity);
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity(); // ดึงค่าความชื้น
  float temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);
  Blynk.run();
  timer.run(); // running timer every second
}
