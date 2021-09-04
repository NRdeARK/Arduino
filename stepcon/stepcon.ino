String Direct,Step;
int a=0,c,steps[4][4] =
{ {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop()
{
  
  if (Serial.available()>0){
    Step =Serial.readString();
    Serial.print(Step)
    ;Serial.println("steps");
    int steps2=Step.toInt();
///////////////////////////////
  if (steps2>0) {
      Serial.print(a);
      Serial.print("to");
      Serial.println(steps2+a);
      c=a;
      
        while(steps2>0){
          
          a++;
          digitalWrite(8, steps[c%4][3]);
          digitalWrite(9, steps[c%4][2]);
          digitalWrite(10, steps[c%4][1]);
          digitalWrite(11, steps[c%4][0]);
          delay(10);
          Serial.println(a);
          steps2--;
          c++;
      }
      steps2=0;
      c=0;
    }


    else if (steps2<0) {
      Serial.print(a);
      Serial.print("to");
      Serial.println(steps2+a);
        c=a;
         while(steps2<0){
          
          a--;
          digitalWrite(8, steps[c%4][3]);
          digitalWrite(9, steps[c%4][2]);
          digitalWrite(10, steps[c%4][1]);
          digitalWrite(11, steps[c%4][0]);
          delay(10);
          Serial.println(a);
          steps2++;
          c--;
        
      }
      steps2=0;
      c=0;
    }
  }
}
