#define led1 D0
#define led2 D1
#define led3 D2
#define led4 D3
#define led5 D4
#define led6 D5
int Status = 0;
bool state1 = 0, state2 = 0, state3 = 0, state4 = 0, state5 = 0, state6 = 0;
String c;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}
int led(int a, int b, int c, int d, int e, int f) {
  digitalWrite(led1, a);
  digitalWrite(led2, b);
  digitalWrite(led3, c);
  digitalWrite(led4, d);
  digitalWrite(led5, e);
}


void loop() {
  if (Serial.available() > 0) {
    c = Serial.readString();
    if (c.toInt() < 7 && c.toInt() > -1) {
      if (c == "1") {
        Serial.print("led" + c + ":");
        state1 = !state1;
        if (state1 == 1) {
          Serial.println("ON");
        }
        else {
          Serial.println("OFF");
        }
        digitalWrite(led1, state1);
      }
      else if (c == "2") {
        Serial.print("led" + c + ":");
        state2 = !state2;
        if (state2 == 1) {
          Serial.println("ON");
        }
        else {
          Serial.println("OFF");
        }
        digitalWrite(led2, state2);
      }
      else if (c == "3") {
        Serial.print("led" + c + ":");
        state3 = !state3;
        if (state3 == 1) {
          Serial.println("ON");
        }
        else {
          Serial.println("OFF");
        }
        digitalWrite(led3, state3);
      }
      else if (c == "4") {
        Serial.print("led" + c + ":");
        state4 = !state4;
        if (state4 == 1) {
          Serial.println("ON");
        }
        else {
          Serial.println("OFF");
        }
        digitalWrite(led4, state4);
      }
      else if (c == "5") {
        Serial.print("led" + c + ":");
        state5 = !state5;
        if (state5 == 1) {
          Serial.println("ON");
        }
        else {
          Serial.println("OFF");
        }
        digitalWrite(led5, state5);
      }
      else if (c == "6") {
        Serial.print("led" + c + ":");
        state6 = !state6;
        if (state6 == 1) {
          Serial.println("ON");
        }
        else {
          Serial.println("OFF");
        }
        digitalWrite(led6, state6);
      }
      else {
        Serial.println("ERROR");
      }
    }
    else {
      Serial.println("ERROR");}
    }
  }
