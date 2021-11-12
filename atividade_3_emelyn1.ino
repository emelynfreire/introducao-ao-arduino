#define led 10
#define buzzer 9
#define ldr A2

int entrada;
byte saida;
  
void setup()
{
  Serial.begin(9600);//inicializando comunicação serial
  
  pinMode(led, OUTPUT);
}

void loop()
{
  entrada = analogRead(ldr);
  
  saida = map(entrada,0,1023,0,255);
  
  Serial.println(saida);
  
  
  if(saida>150){
    analogWrite(led, saida);
    tone(buzzer,20);
    delay(1000);
  
  
  }else{
    analogWrite(led, saida);
    noTone(buzzer);
    delay(1000);
  }
}