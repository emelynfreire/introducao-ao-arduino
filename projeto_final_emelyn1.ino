//PINO LDR de entrada
#define ldr A2

//PINOS LEDs
#define led_verde 7
#define led_vermelho 4

//PINOS TRIGGER SENSOR
#define trigger 9
#define echo 6

//pinos controle motor 1
#define m1_enable 3 
#define m1_entrada1 2
#define m1_entrada2 5

//pinos controle motor 2
#define m2_enable 10 
#define m2_entrada1 8
#define m2_entrada2 11

//variaveis pra trabalhar com o sensor de movimento
float duration, distance;

//Variavel pra trabalhar com o sensor de luminosidade
int entrada;

void setup(){
      
  	  Serial.begin(9600);//inicializando comunicação serial
      
  	  //saidas leds
      pinMode(led_verde, OUTPUT);
      pinMode(led_vermelho, OUTPUT);

      //entrada e saidas sensor
      pinMode(trigger, OUTPUT);//pino de saida
      pinMode(echo, INPUT);//recebe o sinal de volta


      //saida dos motores
      pinMode(m1_entrada1, OUTPUT);//SAIDA
      pinMode(m1_entrada2, OUTPUT);//SAIDA
      pinMode(m2_entrada1, OUTPUT);//SAIDA
      pinMode(m2_entrada2, OUTPUT);//SAIDA
  
}

void loop(){
  
  /*Lógica 1 - O robô só deverá funcionar se houver um certo o
  
  nível de luminosidade (definido pelos desenvolvedores) 
  no ambiente. Se estiver escuro, o robô deverá ficar parado.*/
  
  entrada = analogRead(ldr);
  
  Serial.print("Luminosidade: ");
  Serial.println(entrada);
  
  
  //liga o robo quando há limite de luminosidade
  if(entrada<500){
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = (duration*0.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
    /*lógica 2 - O robô andará em linha reta 
  (os dois motores andando no mesmo sentido) 
  se a distância para algum objeto for maior ou igual a 30 cm */
  					//andar em linha reta e ligar led verde
                      if(distance >= 30){
                        
                        digitalWrite(led_verde,HIGH);
                        digitalWrite(led_vermelho,LOW);

                        digitalWrite(m1_enable,HIGH);
                        digitalWrite(m2_enable,HIGH);

                        digitalWrite(m1_entrada1,LOW);
                        digitalWrite(m1_entrada2,HIGH);
                        digitalWrite(m2_entrada1,LOW);
                        digitalWrite(m2_entrada2,HIGH);
                        
                        


                            }else{ //led vermelho
                            digitalWrite(led_verde,LOW);
                            digitalWrite(led_vermelho,HIGH);
                            
                        	/* 1) Primeiramente pare os motores (para que não haja 
                            colisão entre o robô e o objeto/parede);*/ 
                            parar_motor();
                            delay(1000);
                            /*2) Dê ré (gire os dois motores no sentido contrário 
                            ao original) por 4s;*/
        				    digitalWrite(m1_entrada1,HIGH);
                        	digitalWrite(m1_entrada2,LOW);
                        	digitalWrite(m2_entrada1,HIGH);
                       		digitalWrite(m2_entrada2,LOW);
                            delay(4000);

                            //3) Pare novamente;
                            parar_motor();
                            delay(1000);

                            /*4) Gire para a direita ou para a esquerda por 3s 
                            (a escolha do lado será de vocês);*/
                            
                            digitalWrite(m1_entrada1,LOW);
                            digitalWrite(m1_entrada2,HIGH);
                            digitalWrite(m2_entrada1,HIGH);
                            digitalWrite(m2_entrada2,HIGH);
                            delay(3000);


                            /*5) Volte a andar em linha reta.*/
                     
              				digitalWrite(m1_entrada1,LOW);
                            digitalWrite(m1_entrada2,HIGH);
                            digitalWrite(m2_entrada1,LOW);
                            digitalWrite(m2_entrada2,HIGH);
                        	delay(3000);

                          }
    
  
  //para robo se não ha o limite de luminosidade
  }else{
  	parar_motor();
     digitalWrite(led_verde,LOW);
  	digitalWrite(led_vermelho,LOW);
  }//FIM IF LUMINOSIDADE
  
}//FIM SETUP

void parar_motor(){
 
  digitalWrite(m1_enable,HIGH);
  digitalWrite(m2_enable,HIGH);
  digitalWrite(m1_entrada1,LOW);
  digitalWrite(m1_entrada2,LOW);
  digitalWrite(m2_entrada1,LOW);
  digitalWrite(m2_entrada2,LOW);
    

}

