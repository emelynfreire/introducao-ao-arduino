// C++ code
//
#define LED_VERMELHO 13
#define LED_VERDE 12
#define LED_AMARELO 11



void setup()
{
    pinMode(LED_VERMELHO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AMARELO, OUTPUT);

}

void loop()
{
  digitalWrite(LED_VERMELHO, HIGH);
  delay(10000); // Wait for 10000 millisecond(s)
  digitalWrite(LED_VERMELHO, LOW);
  
  
  digitalWrite(LED_VERDE, HIGH);
  delay(10000); // Wait for 10000 millisecond(s)
  digitalWrite(LED_VERDE, LOW);
 
  
  digitalWrite(LED_AMARELO, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(LED_AMARELO, LOW);
 
}