//#include <Servo.h>
#include <Ultrasonic.h>


////////////// Classe que controla a Garra ///////////////////
/*
class ControllerGarra
{
    public:
        Servo servo00, servo01, servo02, servo03; //Criando um objeto para cada servo
        void power();
        void Run(int x, int option);
};
void ControllerGarra::power(){
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    servo00.attach(5);   //Definindo o pino de controle do respectivo servo
    servo01.attach(6);   //Definindo o pino de controle do respectivo servo
    servo02.attach(10);  //Definindo o pino de controle do respectivo servo
    servo03.attach(11);  //Definindo o pino de controle do respectivo servo
}
void ControllerGarra::Run(int value, int option){
    switch(option){
        case 0:
            servo00.write(value);
            delay(15);
            break;
        case 1:
            servo01.write(value);
            delay(15);
            break;
        case 2:
            servo02.write(value);
            delay(15);
            break;        
        case 3:
            servo03.write(value);
            delay(15);
            break;                   
    }
}
*/

////////////// Classe que controla o Motor ///////////////////
class Motor{
	private:
  		//Motor 01
  		const int pinEnable01 = 3;
  		const int pinInput01 = 4;
  		const int pinInput02 = 7;
  		//Motor 02
  		const int pinEnable02 = 9;
  		const int pinInput03 = 12;
  		const int pinInput04 = 13;
  		int velocidade = 110;
      int delay_90 = 600;

  		static int contador;
  public:
  		void power();
      void right();
      void right_90();
  		void left();
      void left_90();
  		void infront();
      void stopMotors();
      void contornar();

};
void Motor::power(){
      // Pinos do motor 1
      pinMode( 3, OUTPUT);
      pinMode( 4, OUTPUT);
      pinMode( 7, OUTPUT);
      // Pinos do motor 2
      pinMode( 9, OUTPUT);
      pinMode( 12, OUTPUT);
      pinMode( 13, OUTPUT);
}
void Motor::infront(){
	   digitalWrite( pinInput01, LOW);
  	 digitalWrite( pinInput02, HIGH);

  	 digitalWrite( pinInput03, LOW);
  	 digitalWrite( pinInput04, HIGH);

     analogWrite( pinEnable02, velocidade);
     analogWrite( pinEnable01, velocidade);
}
void Motor::right(){
	   digitalWrite( pinInput01, LOW);
  	 digitalWrite( pinInput02, HIGH);
     
     digitalWrite( pinInput03, LOW);
     digitalWrite( pinInput04, LOW);

     analogWrite( pinEnable01, velocidade);
     analogWrite( pinEnable02, 0);
}
void Motor::right_90(){
     
     digitalWrite( pinInput01, HIGH);
     digitalWrite( pinInput02, LOW);

     digitalWrite( pinInput03, HIGH);
     digitalWrite( pinInput04, LOW);

     analogWrite( pinEnable02, velocidade);
     analogWrite( pinEnable01, velocidade);

     delay(150);

     
     analogWrite( pinEnable01, velocidade);
     analogWrite( pinEnable02, 0);

     digitalWrite( pinInput01, LOW);
     digitalWrite( pinInput02, HIGH);

     digitalWrite( pinInput03, LOW);
     digitalWrite( pinInput04, LOW);

       delay(delay_90);

     analogWrite( pinEnable01, 0);
     analogWrite( pinEnable02, 0);

     
     digitalWrite( pinInput01, LOW);
     digitalWrite( pinInput02, LOW);

     digitalWrite( pinInput03, LOW);
     digitalWrite( pinInput04, LOW);
}
void Motor::left(){
	   analogWrite( pinEnable01, 0);
  	 analogWrite( pinEnable02, velocidade);
     
     digitalWrite( pinInput01, LOW);
     digitalWrite( pinInput02, LOW);
     
  	 digitalWrite( pinInput03, LOW);
  	 digitalWrite( pinInput04, HIGH);
}
void Motor::left_90(){
  
    digitalWrite( pinInput01, HIGH);
     digitalWrite( pinInput02, LOW);

     digitalWrite( pinInput03, HIGH);
     digitalWrite( pinInput04, LOW);

     analogWrite( pinEnable02, velocidade);
     analogWrite( pinEnable01, velocidade);

     delay(150);
      
     analogWrite( pinEnable01, 0);
     analogWrite( pinEnable02, velocidade);

     digitalWrite( pinInput01, LOW);
     digitalWrite( pinInput02, LOW);

     digitalWrite( pinInput03, LOW);
     digitalWrite( pinInput04, HIGH);


     delay(delay_90);

     analogWrite( pinEnable01, 0);
     analogWrite( pinEnable02, 0);

     
     digitalWrite( pinInput01, LOW);
     digitalWrite( pinInput02, LOW);

     digitalWrite( pinInput03, LOW);
     digitalWrite( pinInput04, LOW);
}
void Motor::stopMotors(){
     analogWrite( pinEnable01, 0);
     analogWrite( pinEnable02, 0);
     digitalWrite( pinInput03, LOW);
     digitalWrite( pinInput04, LOW);
     digitalWrite( pinInput01, LOW);
     digitalWrite( pinInput02, LOW);
}
void Motor::contornar(){
     analogWrite( pinEnable01, velocidade);
     analogWrite( pinEnable02, velocidade);
     digitalWrite( pinInput01, LOW);
     digitalWrite( pinInput02, HIGH);
     digitalWrite( pinInput03, HIGH);
     digitalWrite( pinInput04, LOW);

     delay(550);
     
     stopMotors();
     delay(100);
     
     infront();
     delay(500);
     stopMotors();
     delay(100);
          
     analogWrite( pinEnable01, velocidade);
     analogWrite( pinEnable02, velocidade);
     digitalWrite( pinInput01, HIGH);
     digitalWrite( pinInput02, LOW);
     digitalWrite( pinInput03, LOW);
     digitalWrite( pinInput04, HIGH);

     delay(550);
     stopMotors();
     delay(100);
     
     infront();
     delay(1200);
     
     
     stopMotors();
     delay(100);
    
     analogWrite( pinEnable01, velocidade);
     analogWrite( pinEnable02, velocidade);
     digitalWrite( pinInput01, HIGH);
     digitalWrite( pinInput02, LOW);
     digitalWrite( pinInput03, LOW);
     digitalWrite( pinInput04, HIGH);

     delay(620);
     
     
     stopMotors();
     delay(100);
     
     infront();
     delay(150);
          
  }

class Line{
  private:
      //Sensor 1
      const int pin1 = A0;
      //Sensor2
      const int pin2 = A1;
      //Sensor3
      const int pin3 = A2;
      //Sensor4
      const int pin4 = A3;
  public:
      void power();
      int see(int pin);
};
void Line::power(){
     pinMode(A0, INPUT);
     pinMode(A1, INPUT);
     pinMode(A2, INPUT);
     pinMode(A3, INPUT);
}
int Line::see(int pin){
     return digitalRead(pin);
}

////////////////////// Classe que controla o Sensor ultrasônico/////////////////////////

#define pinoTring 2
#define pinoEcho 8

Ultrasonic ultra(pinoTring, pinoEcho);
int distanceOfObject;

//ControllerGarra myGarra;
Motor myMotor;
Line myLine;

void setup(){
    myLine.power();  //Configura os pinos como entrada digital dos sensores de linha
    //myGarra.power(); //Configura os pinos de saida dos servos
    myMotor.power(); //Configura os pinos de saida dos motores
    Serial.begin(9600);
}
void loop(){
    distanceOfObject = ultra.Ranging(CM); // Obtendo a distencia do sensor ultrasônico
    Serial.println(distanceOfObject);
    if(distanceOfObject <= 9){ // A distancia máxima para realizar a manobra de contornar um objeto é 10cm 
        myMotor.contornar();
        // Contornar obstaculo
    }else{
      
          if(myLine.see(A0) == 1 && myLine.see(A1) == 1 && myLine.see(A2) == 0 && myLine.see(A3) == 1){
              myMotor.left();
            }
          else if(myLine.see(A0) == 1 && myLine.see(A1) == 0 && myLine.see(A2) == 1 && myLine.see(A3) == 1){
              myMotor.right();
            }
          else if(myLine.see(A0) == 1 && myLine.see(A1) == 1 && myLine.see(A2) == 1 && myLine.see(A3) == 1){
              myMotor.infront();          
          }else if(myLine.see(A0) == 1 && myLine.see(A1) == 1 && myLine.see(A2) == 0 && myLine.see(A3) == 0){
              myMotor.stopMotors();
              delay(100);
              myMotor.left_90();
          }else if(myLine.see(A0) == 0 && myLine.see(A1) == 0 && myLine.see(A2) == 1 && myLine.see(A3) == 1){
              myMotor.stopMotors();
              delay(100);
              myMotor.right_90();
          }else if(myLine.see(A0) == 0 && myLine.see(A1) == 1 && myLine.see(A2) == 1 && myLine.see(A3) == 1){
              myMotor.right();
              delay(100); 
          }else if(myLine.see(A0) == 1 && myLine.see(A1) == 1 && myLine.see(A2) == 1 && myLine.see(A3) == 0){
              myMotor.left();
              delay(100);          
          }else if(myLine.see(A0) == 1 && myLine.see(A1) == 1 && myLine.see(A2) == 1 && myLine.see(A3) == 1){
              myMotor.infront();
          }else if(myLine.see(A0) == 1 && myLine.see(A1) == 0 && myLine.see(A2) == 0 && myLine.see(A3) == 1){
              myMotor.infront();
          }else if(myLine.see(A0) == 0 && myLine.see(A1) == 0 && myLine.see(A2) == 0 && myLine.see(A3) == 1){
              myMotor.stopMotors();
              delay(100);
              myMotor.right_90();
          }else if(myLine.see(A0) == 1 && myLine.see(A1) == 0 && myLine.see(A2) == 0 && myLine.see(A3) == 0){
              myMotor.stopMotors();
              delay(100);
              myMotor.left_90();
          }else if(myLine.see(A0) == 0 && myLine.see(A1) == 0 && myLine.see(A2) == 0 && myLine.see(A3) == 0){
              myMotor.right();
              delay(100); 
          }else{
              myMotor.stopMotors();
          }
          
    }
}
