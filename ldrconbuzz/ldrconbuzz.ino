int ldr = A0;
int ldrVal,freq;
const int buzzer = 9;
int MAX=300, MIN=120;
void setup()
{
  Serial.begin(9600);

  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  ldrVal = analogRead(ldr);
  Serial.println("LDR Sensor :");
  Serial.println(ldrVal);
  freq=120+ldr*(1880/MAX-MIN);
  Serial.println("Frequency :");
  Serial.println(freq);
  tone(buzzer, freq);     // Send 1KHz sound signal...
  delay(1000);            // ...for 1 sec
  noTone(buzzer);         // Stop sound...
  delay(1000);            // ...for 1sec

}
