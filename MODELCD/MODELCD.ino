///////////UHT
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 2 
#define DHTTYPE    DHT22
DHT dht(DHTPIN, DHTTYPE);
///////////LCD
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int x;
LiquidCrystal_I2C lcd(0x27,16,2);
///////////LDR
int O=0;
int T=0;
int L=0;
float R=0;
int X=0;
///////////TIME SW
#define sw1 10
int mode=1;
unsigned long Time,second,minute,hour;

void setup() {

///////////UHT
dht.begin();
O=analogRead(A0);
//////////LCD
lcd.init();
lcd.backlight();
//////////LDR

}
void Smode(){
  if (digitalRead(sw1)==0){
    delay(10);
    if (digitalRead(sw1)==0){
      if(mode==1){mode=2;}
      else if(mode==2){mode=3;}
      else if(mode==3){mode=1;}
  }
   while(digitalRead(sw1)==0){
      showTime();
      if(mode==1){mode1();}
      if(mode==2){mode2();}
      if(mode==3){mode3();}
    }
  }
  showTime();
  if(mode==1){mode1();}
  if(mode==2){mode2();}
  if(mode==3){mode3();}
  delay(500);
  lcd.print("               ");
}

void showTime(){
  
  Time=millis();
  second=(Time/1000)%60;
  minute=((Time/1000)%3600)/60;
  hour=Time/3600000;
  lcd.setCursor(0,0);
  lcd.print("    ");
  lcd.print(hour);
  lcd.print(":");
  if (minute<10){lcd.print("0");}
  lcd.print(minute);
  lcd.print(":");
  if (second<10){lcd.print("0");}
  lcd.print(second);
}
void mode1(){
  float t = dht.readTemperature();
  lcd.setCursor(0,1);
  lcd.print("TEMP : ");
  lcd.print(t);
  lcd.print("°C");
}
void mode2(){
  float h = dht.readHumidity();
  lcd.setCursor(0,1);
  lcd.print("HUMID : ");
  lcd.print(h);
  lcd.print("%");
}

void mode3(){
  lcd.setCursor(0,1);
  lcd.print("BRIGHTNESS:");
  O=analogRead(A0);
  L=map(O,0,1023,0,255);
  R=(L-140.00)/105.00;
  X=R*100;
  if (X>=100){
    X=100;
  }
  if(X<=0){
    X=0;
}
lcd.print(X);
  lcd.print("%");
}

void loop() {
  Smode();

}
