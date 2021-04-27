

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int redled=9;
int greenled=6;
int blueled=8;

int value=A0;
int red;
int blue;
int green;

int redvalue;
int greenvalue;
int bluevalue;

int redout=8;
int greenout=9;
int blueout=10;
String a;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(blueled,OUTPUT);

  pinMode(value,INPUT);
  pinMode(redout,OUTPUT);
  pinMode(greenout,OUTPUT);
  pinMode(blueout,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  
  lcd.setCursor(0,1);
  
  lcd.setCursor(0,0);
  if(Serial.available())
  {
    a = Serial.readString();
    Serial.println(a);
 
}
  for (int j = 0; j<=1; j++) {
    for (int i = 0; i<4; i++) {
      digitalWrite(redled,HIGH);
      delay(40);
      red=analogRead(value);
      delay(10);

    
      digitalWrite(redled,LOW);
      digitalWrite(greenled,HIGH);
      delay(40);
      green=analogRead(value);
      delay(10);

      digitalWrite(greenled,LOW);
    
      digitalWrite(blueled,HIGH);
      delay(40);
      blue=analogRead(value);
      delay(10);

      digitalWrite(blueled,LOW);
  }
      lcd.print("R=");
      lcd.print(int(red*0.4180327869));
      lcd.print(" ");

      lcd.print("G=");  
      lcd.print(int(green*0.41803)); 
      lcd.print(" ");

      lcd.print("B=");
      lcd.println(int(blue*0.4180327869));
}



delay(10000);
  
  
}
