#include <SoftwareSerial.h>
SoftwareSerial Node(D2,D3); // RX | TX
int led;
void setup()
{
  Serial.begin(9600);
  Node.begin(9600);
  pinMode(A0,INPUT);
}
void loop() {
  led=analogRead(A0);
  Node.print(led);
  Node.print("&");
  Serial.print("LED:");
  Serial.println(led);
  delay(100);
}
