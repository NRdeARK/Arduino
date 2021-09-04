#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);

#include <Servo.h>
Servo myservo;

// Setup variables:


void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  myservo.attach(2);
}

void loop()
{

  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      if (   rfid.serNum[0] == 198
          && rfid.serNum[1] == 216
          && rfid.serNum[2] == 88
          && rfid.serNum[3] == 30
          && rfid.serNum[4] == 88
         ) {
        /* With a new cardnumber, show it. */
        Serial.println("Card found");
        myservo.write(180); // สั่งให้ Servo หมุนไปองศาที่ 90
        delay(4000);
        myservo.write(0);
      } else {
        /* If we have the same ID, just write a dot. */
        Serial.println("Card not found");
      }
    }
  }

  rfid.halt();
}
