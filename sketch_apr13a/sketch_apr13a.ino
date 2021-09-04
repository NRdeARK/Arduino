void setup() {
  Serial.begin(9600);

}

void loop() {
    Serial.print("A1: ");
    Serial.println(analogRead(A1));
    Serial.print("A2: ");
    Serial.println(analogRead(A2));
    Serial.print("A3: ");
    Serial.println(analogRead(A3));
    Serial.print("A4: ");
    Serial.println(analogRead(A4));
    Serial.print("A5: ");
    Serial.println(analogRead(A5));
    Serial.print("A6: ");
    Serial.println(analogRead(A6));
delay(500);
}
