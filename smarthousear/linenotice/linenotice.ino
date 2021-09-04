22#define BLYNK_PRINT Serial

#define light D8
#define data1 D7
#define data2 D6
#define intur D5

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "fV0WD8ixAST0gTQK9k9V4FbZzLBDhx1k";
char ssid[] = "Kraed";
char pass[] = "blackmuffin";
BlynkTimer timer;

#include "DHT.h"
DHT dht;
float humidity   ;// ดึงค่าความชื้น
float temperature; // ดึงค่าอุณหภูมิ

int state = 0;
void setup()
{

  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  dht.setup(2); // data pin d4

  timer.setInterval(1000L, myTimerEvent);
  pinMode(D2, OUTPUT);
  
  pinMode(intur, OUTPUT);
  pinMode(data1, OUTPUT);
  pinMode(data2, OUTPUT);
  pinMode(light, OUTPUT);
}
BLYNK_WRITE(V1)
{
  int pinData = param.asInt();
  digitalWrite(D2, pinData);
}
void myTimerEvent()
{
  if (humidity == humidity && temperature == temperature)
  {
    Blynk.virtualWrite(V5, humidity);
    Blynk.virtualWrite(V6, temperature);
  }
}
BLYNK_WRITE(V2) {
  switch (param.asInt())
  {
    case 1: { // Item 1
      digitalWrite(intur,1);
      digitalWrite(data1,0);
      digitalWrite(data2,0);
      digitalWrite(intur,0);
        break;
      }
    case 2: { // Item 2
      digitalWrite(intur,1);
      digitalWrite(data1,1);
      digitalWrite(data2,0);
      digitalWrite(intur,0);
        break;
      }
    case 3: { // Item 2
      digitalWrite(intur,1);
      digitalWrite(data1,0);
      digitalWrite(data2,1);
      digitalWrite(intur,0);
        break;
      }
    case 4: { // Item 2
      digitalWrite(intur,1);
      digitalWrite(data1,1);
      digitalWrite(data2,1);
      digitalWrite(intur,0);
        break;
      }
  }
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());
  humidity = dht.getHumidity(); // ดึงค่าความชื้น
  temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);
  Blynk.run();
  if (analogRead(A0)<50){digitalWrite(light,1);}else{digitalWrite(light,0);}
  timer.run(); // running timer every second

}
