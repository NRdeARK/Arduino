#include <Keypad.h>
int Mode = 1, form, A = 0, B = 0, i = 0, ans;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int x;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {4, 5, 3, 2};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String input_A;
String input_B;


void setup() {
  Serial.begin(9600);
  //  lcd.init();
  //  lcd.backlight();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    if (key == '1') {
      if (Mode == 1) {
        A += 1 * pow(10, i); Serial.print(A);

      }
      else if (Mode == 2) {
        B += 1 * pow(10, i); Serial.print(B);
      }
      i++;
    }
    if (key == '2') {
      if (Mode == 1) {
        A += 2 * pow(10, i); Serial.print(A);

      }
      else if (Mode == 2) {
        B += 2 * pow(10, i); Serial.print(B);
      }
      i++;
    }
    if (key == '3') {
      if (Mode == 1) {
        A += 3 * pow(10, i); Serial.print(A);
      }
      else if (Mode == 2) {
        B += 3 * pow(10, i); Serial.print(B);
      }
      i++;
    }
    if (key == '4') {
      if (Mode == 1) {
        A += 4 * pow(10, i); Serial.print(A);
      }
      else if (Mode == 2) {
        B += 4 * pow(10, i); Serial.print(B);
      }
      i++;
    }    if (key == '5') {
      if (Mode == 1) {
        A += 5 * pow(10, i); Serial.print(A);
      }
      else if (Mode == 2) {
        B += 5 * pow(10, i); Serial.print(B);
      }
      i++;
    }
    if (key == '6') {
      if (Mode == 1) {
        A += 6 * pow(10, i); Serial.print(A);
      }
      else if (Mode == 2) {
        B += 6 * pow(10, i); Serial.print(B);
      }
      i++;
    }
    if (key == '7') {
      if (Mode == 1) {
        A += 7 * pow(10, i); Serial.print(A);
      }
      else if (Mode == 2) {
        B += 7 * pow(10, i); Serial.print(B);
      }
      i++;
    }
    if (key == '8') {
      if (Mode == 1) {
        A += 8 * pow(10, i); Serial.print(A);
      }
      else if (Mode == 2) {
        B += 8 * pow(10, i); Serial.print(B);
      }
      i++;
    }
    if (key == '9') {
      if (Mode == 1) {
        A += 9 * pow(10, i); Serial.print(A);
      }
      else if (Mode == 2) {
        B += 9 * pow(10, i); Serial.print(B);
      }
      i++;
    }
    if (key == '0') {
      if (Mode == 1) {
        A += 0 ; Serial.print(A);
      }
      else if (Mode == 2) {
        B += 0 ; Serial.print(B);
      }
      i++;
    }
    if (key == 'A')//=
    {
      if (Mode == 1)
      {
        form = 1;
        Mode = 2;
        i = 0;
      }
    }

    if (key == 'B')//=
    {
      if (Mode == 1)
      {
        form = 2;
        Mode = 2;
        i = 0;
      }
    }
    if (key == 'C')//=
    {
      if (Mode == 1)
      {
        form = 3;
        Mode = 2;
        i = 0;
      }
    }
    if (key == 'D')//=
    {
      if (Mode == 1)
      {
        form = 4;
        Mode = 2;
        i = 0;
      }
    }
    if (key == '#')//=
    {
      if (form == 1) {
        ans = A + B;
      }
      if (form == 2) {
        ans = A - B;
      }
      if (form == 3) {
        ans = A * B;
      }
      if (form == 4) {
        ans = A / B;
      }
      Serial.println(ans);
    }
    if (key == '*')
    {
      A ;
      B ;
      ans = 0;
      i = 0;
      Mode = 1;
    }
    Serial.println();
  }
  //  lcd.setCursor(0, 0);
  //  lcd.print("               ");
  //  if (A>=0){
  //    Serial.print(A);
  //  }else if (Mode==2){
  //    Serial.print(A);
  //    }

  //  if(form==1){Serial.print(" + ");}
  //  if(form==2){Serial.print(" - ");}
  //  if(form==3){Serial.print(" * ");}
  //  if(form==4){Serial.print(" / ");}
  //    if (B>=0){
  //    Serial.print(B);
}

//  lcd.setCursor(1, 0);
//  Serial.println(ans);
//  lcd.print("               ");
//}
