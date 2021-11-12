// C++ code
//
byte botaoA = 9;
byte botaoB = 10;

#define enable 3 
#define entrada1 2
#define entrada2 7

boolean estadoBotao1,estadoBotao2;


void setup()
{
  pinMode(botaoA, INPUT);//entrada
  pinMode(botaoB, INPUT);//entrada
  pinMode(entrada1, OUTPUT);//SAIDA
  pinMode(entrada2, OUTPUT);//SAIDA
 
}

void loop(){
  estadoBotao1 = digitalRead(botaoA);//lendo o que está escrito no botão, entrada
  estadoBotao2 = digitalRead(botaoB);//lendo o que está escrito no botão, entrada

  
  if(estadoBotao1==HIGH){
    digitalWrite(enable,HIGH);
    digitalWrite(entrada1,LOW);
    digitalWrite(entrada2,HIGH);
    delay(3000);
    
    //PARAR MOTOR
    parar_motor();
    
  }else if(estadoBotao2==HIGH){
    digitalWrite(enable,HIGH);
    digitalWrite(entrada1,HIGH);
    digitalWrite(entrada2,LOW);
    delay(3000);
    
    //PARAR MOTOR
    parar_motor();

  }else{
  	parar_motor();
  }
  
}


void parar_motor(){
	digitalWrite(entrada1,LOW);
    digitalWrite(entrada2,LOW);

}

