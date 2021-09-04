#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
String no1 = "", no2 = "";
int plus = 0;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'p'},
  {'4', '5', '6', 'e'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {4, 5, 3, 2};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup() {
  Serial.begin(9600);
}
void loop() {
  String key = keypad.getKey();
  if (
    key == "0" ||
    key == "1" ||
    key == "2" ||
    key == "3" ||
    key == "4" ||
    key == "5" ||
    key == "6" ||
    key == "7" ||
    key == "8" ||
    key == "9"
  )
  {
    if (plus == 0) {
      no1 += key;
    }
    else if (plus == 1) {
      no2 += key;
    }
  }
  if(
     key == "p" 
    ){}

}
