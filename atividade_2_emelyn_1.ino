// C++ code
//
#define botao 10 //LED NO PINO PWM 10
#define led 9 //LED NO PINO PWM 9
boolean estadoBotao;

void setup()
{
  pinMode(botao, INPUT);//entrada
  pinMode(led, OUTPUT);//saida
}

void loop()
{
  
  estadoBotao = digitalRead(botao);//lendo o que está escrito no botão, entrada


  if(estadoBotao==HIGH){
  		for(int i=0;i<5;i++){
  			analogWrite(led,255);
  			delay(1000);
        	analogWrite(led,0);
        	delay(1000);
        }
  }else{
       		analogWrite(led,0);
        }
  
}
