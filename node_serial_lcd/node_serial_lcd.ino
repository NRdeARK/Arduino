#include <SoftwareSerial.h>
SoftwareSerial Node(D7, D8); // RX | TX
int led;
String a, b, c, tem, humid;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  Node.begin(9600);
  lcd.begin();
  lcd.backlight();
}
void loop() {
  if (Node.available() > 0) {

    Serial.println("1");
    a = Node.readStringUntil('&');
    b = Node.readStringUntil('&');


    ///////////////////////////////

    tem = a.substring(0, a.indexOf('&'));
    humid = b.substring(0, b.indexOf('&'));



    ///////////////////////////////
    Serial.print(tem );
    Serial.print(humid );
    lcd.setCursor(0, 0);
    lcd.print(tem);
    lcd.print("C");
    lcd.print("               ");
    lcd.setCursor(1, 0);
    lcd.print(humid);
    lcd.print("%");
    lcd.print("               ");
  }
}
