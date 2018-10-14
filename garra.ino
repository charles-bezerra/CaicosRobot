#include <Servo.h>
class ControllerGarra
{
    public:
        Servo servo00, servo01, servo02, servo03; //Criando um objeto para cada servo
        int Converter(int x);
        void Power();
        void Run(int x, int option);
};
void ControllerGarra::Power(){
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    servo00.attach(5);   //Definindo o pino de controle do respectivo servo
    servo01.attach(6);     //Definindo o pino de controle do respectivo servo
    servo02.attach(10);    //Definindo o pino de controle do respectivo servo
    servo03.attach(11); //Definindo o pino de controle do respectivo servo
}
int ControllerGarra::Converter(int x){
    return map(x, 0, 1023, 0, 180);
}
void ControllerGarra::Run(int value, int option){
    int x = Converter(value);
    switch(option){
        case 0:
            servo00.write(x);
            delay(15);
            break;
            
        case 1:
            servo01.write(x);
            delay(15);
            break;
            
        case 2:
            servo02.write(x);
            delay(15);
            break;
        
        case 3:
            servo03.write(x);
            delay(15);
            break;                   
    }
}



ControllerGarra myGarra;
void setup(){
     myGarra.Power(); //Liga os servos
}
void loop() {
     myGarra.Run(1023,0); //(intensidade, servo)
}
