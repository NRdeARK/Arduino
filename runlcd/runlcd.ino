//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int x;
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{                     // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  
  
}


void loop()
{
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("                Nataphan Rakvidhyasatra");
  lcd.setCursor(0,1);
  lcd.print("                6103102110043          ");

  for (x=0;x<38;x++){
  lcd.scrollDisplayLeft();
  delay(400);}
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("                Sirawit Silprasert");
  lcd.setCursor(0,1);
  lcd.print("                6103102110111     ");

  for (x=0;x<33;x++){
  lcd.scrollDisplayLeft();
  delay(400);}
}
