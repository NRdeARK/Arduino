#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 13
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(3, OUTPUT);


}

void tonerr() {
  tone(3, 100, 20);
  delay(2000);
  noTone(3);
  delay(2000);
}

void loop() {
  Serial.print("1");
  if (!(rfid.PICC_IsNewCardPresent() || rfid.PICC_ReadCardSerial()))
  {
    Serial.println("2");
    return;
  }
  Serial.print("3");
  Serial.print("PICC type: ");
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));
  
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI && MFRC522::PICC_TYPE_MIFARE_1K && MFRC522::PICC_TYPE_MIFARE_4K ) 
  {
    Serial.println("Your tag is not of type MIFARE Classic.");
    tonerr();
    Serial.print("3");
    return;
  }
  String strID = "";
  Serial.print("str :");
  Serial.print(strID);
  for (byte i = 0; i < 4; i++) {
    Serial.print(i);
    strID += (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
             String(rfid.uid.uidByte[i], HEX) + (i != 3 ? ":" : "");
  }
  strID.toUpperCase();
  Serial.print("Tap card key: ");
  Serial.print(strID);
  //  if (strID.indexOf("70:53:5D:A8")>=0){
  if (strID >= "0") {
    Serial.println("Tag OK!!");
    tonerr();
  }

  //  }
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

}
