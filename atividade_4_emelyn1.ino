// C++ code
//
#define trigger 10
#define echo 9

#define green 3
#define blue 5
#define red 6

float duration, distance;
void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
 
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
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance < 30){ //cor vermelha
    digitalWrite(red, HIGH );
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    
  }else if(distance >=30 && distance<120){//cor laranja
     analogWrite(red, 255);
     analogWrite(green, 140);
     analogWrite(blue, 0);
  
  }else if(distance >=120 && distance<200){//cor amarela
     analogWrite(red, 255);
     analogWrite(green, 255);
     analogWrite(blue, 0);
  
  }else if(distance >=200 && distance<300){//cor verde
     digitalWrite(red, LOW);
     digitalWrite(green, HIGH);
     digitalWrite(blue, LOW);
  
  }else if(distance >=300){//cor azul
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  
  }else{//o led não acenderá
  	digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }



  
 
}