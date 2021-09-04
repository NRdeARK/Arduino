const int pingPin = 24;
int inPin = 22;
void setup() {
Serial.begin(9600);
}
void loop()
{
long duration, cm;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingPin, LOW);
pinMode(inPin, INPUT);
duration = pulseIn(inPin, HIGH);
cm = (duration)/29/2;
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(100);
}
