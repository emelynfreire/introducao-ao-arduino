#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);//respeitando a ordem
#define trigger 9
#define echo 10

float duration, distance;

void setup(){
  
  pinMode(trigger, OUTPUT);//pino de saida
  pinMode(echo, INPUT);//recebe o sinal de volta
  Serial.begin(9600);//comunicação serial pra ficar lendo
  
}

void loop()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = (duration*0.0343)/2;
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Distancia:");
  lcd.setCursor(1,1);
  lcd.print(distance) + lcd.print("cm");
  
  
}