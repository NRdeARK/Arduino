#include "DHT.h"

#define DHTPIN D2
#define DHTTYPE DHT22

#define BLYNK_PRINT Serial

#include <TridentTD_LineNotify.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define SSID        "Kraed"
#define PASSWORD    "blackmuffin"
#define LINE_TOKEN  "WfDWt1J3eRZ0kUMeGPXbpOIQCKWpK5h8nwHlmfmArik"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "cDYE_dDZhc05WANbzDfP6_uw5TCP9P4J";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Kraed";
char pass[] = "blackmuffin";
char token[] = "WfDWt1J3eRZ0kUMeGPXbpOIQCKWpK5h8nwHlmfmArik";
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

BLYNK_WRITE(V3) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    LINE.notify("ON");
    Serial.println("ON");
    digitalWrite(D0, LOW);
  }
  else {
    LINE.notify("OFF");
    Serial.println("OFF");
    digitalWrite(D0, HIGH);
  }
}

void setup()
{
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());  
  LINE.setToken(LINE_TOKEN);
  
  // Debug console
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
  LINE.setToken(token);
  pinMode(D0, OUTPUT);
  timer.setInterval(1000L, sendSensor);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
float h, t;
void sendSensor() {
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, t);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
}
unsigned long lastRead;
void loop()
{
  Blynk.run();
  timer.run();
  if (t > 27) {
    digitalWrite(D0, LOW);
  }
  else {
    digitalWrite(D0, HIGH);
  }
}
