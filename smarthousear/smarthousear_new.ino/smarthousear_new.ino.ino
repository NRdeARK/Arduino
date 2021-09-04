#include <ArduinoCloudProviderExamples.h>

#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9
#define DoorIN 2
RFID rfid(SS_PIN, RST_PIN);
//////////////////////////
#include <Servo.h>
Servo myservo;
//////////////////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int x;
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

// Setup variables:
int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  pinMode(DoorIN, INPUT);
  attachInterrupt(0, OPEN, RISING );

  myservo.attach(6);
  myservo.write(0);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  delay(1000);
}

void OPEN()
{
  Serial.println("Intur");
  myservo.write(90);
}


void loop()
{

  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      if (rfid.serNum[0] != serNum0
          && rfid.serNum[1] != serNum1
          && rfid.serNum[2] != serNum2
          && rfid.serNum[3] != serNum3
          && rfid.serNum[4] != serNum4
         ) {
        /* With a new cardnumber, show it. */
        Serial.println(" ");
        Serial.println("Card found");
        serNum0 = rfid.serNum[0];
        serNum1 = rfid.serNum[1];
        serNum2 = rfid.serNum[2];
        serNum3 = rfid.serNum[3];
        serNum4 = rfid.serNum[4];

        //Serial.println(" ");
        Serial.println("Cardnumber:");
        Serial.print("Dec: ");
        Serial.print(rfid.serNum[0], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[1], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[2], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[3], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[4], DEC);
        Serial.println(" ");
        if (
          serNum0 == 217 &&
          serNum1 == 206 &&
          serNum2 == 14  &&
          serNum3 == 127 &&
          serNum4 == 102 ) {
          myservo.write(90);
          lcd.clear();
          Serial.println("ACCESS GRANTED  ");
          lcd.setCursor(0, 0);
          lcd.print("ACCESS GRANTED  ");
          lcd.setCursor(0, 1);
          lcd.print("Nataphan Rakvid.");

        }
        else {
          if (digitalRead(2) == 1) {
            myservo.write(90);
            lcd.setCursor(0, 0);
            lcd.println("ACCESS GRANTED");
            lcd.setCursor(0, 1);
            lcd.print("ONLINE CON.");
          }
          else {
            lcd.clear();
            Serial.println("ACCESS DENIED");
            lcd.setCursor(0, 0);
            lcd.print("ACCESS DENIED");
            lcd.setCursor(0, 1);
            lcd.print("UNKNOW");
            myservo.write(0);
          }
        }
      } else {
        if (
          serNum0 == 217 &&
          serNum1 == 206 &&
          serNum2 == 14  &&
          serNum3 == 127 &&
          serNum4 == 102 ) {
          myservo.write(90);
          Serial.print(".");
          lcd.setCursor(0, 0);
          lcd.println("ACCESS GRANTED  ");
          lcd.setCursor(0, 1);
          lcd.print("Nataphan Rakvid.");
        }
        else {
          if (digitalRead(2) == 1) {
            myservo.write(90);
            lcd.setCursor(0, 0);
            lcd.println("ACCESS GRANTED  ");
            lcd.setCursor(0, 1);
            lcd.print("ONLINE CON.");
          }
          else {
            myservo.write(0);
            Serial.println("ACCESS DENIED");
            lcd.setCursor(0, 0);
            lcd.print("ACCESS DENIED");
            lcd.setCursor(0, 1);
            lcd.print("UNKNOW");
          }
          Serial.print(".");
        }
      }
    }
    else {
      if (digitalRead(2) == 1) {
        myservo.write(90);
        lcd.setCursor(0, 0);
        lcd.println("ACCESS GRANTED  ");
        lcd.setCursor(0, 1);
        lcd.print("ONLINE CON.");
      }
      else {
        myservo.write(0);
        //        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("                ");
        lcd.setCursor(0, 1);
        lcd.print("                ");
      }
    }
  }
  else {
    if (digitalRead(2) == 1) {
      myservo.write(90);
      lcd.setCursor(0, 0);
      lcd.println("ACCESS GRANTED  ");
      lcd.setCursor(0, 1);
      lcd.print("ONLINE CON.");
    }
    else {
      myservo.write(0);
      //      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
  }


  rfid.halt();
}
