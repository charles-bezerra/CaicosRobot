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

  		static int contador;
  	public:
  		void direita();
  		void esquerda();
  		void emfrente();
};
void Motor::emfrente(){
  	analogWrite( pinEnable01, 255);
  	analogWrite( pinEnable02, 255);

	digitalWrite( pinInput01, HIGH);
  	digitalWrite( pinInput02, LOW);

  	digitalWrite( pinInput03, HIGH);
  	digitalWrite( pinInput04, LOW);
  	delay(100);
}
void Motor::esquerda(){
  	analogWrite( pinEnable01, 255);
  	analogWrite( pinEnable02, 255);

	digitalWrite( pinInput01, LOW);
  	digitalWrite( pinInput02, HIGH);

  	digitalWrite( pinInput03, HIGH);
  	digitalWrite( pinInput04, LOW);
  	delay(100);
}
void Motor::direita(){
	analogWrite( pinEnable01, 255);
  	analogWrite( pinEnable02, 255);

	digitalWrite( pinInput01, HIGH);
  	digitalWrite( pinInput02, LOW);

  	digitalWrite( pinInput03, LOW);
  	digitalWrite( pinInput04, HIGH);
  	delay(100);
}


class SensorsDist{
	private:
  		const int pinSensor0 = 0;
  		const int pinSensor1 = 1;
  		const int pinSensor2 = 2;
  	public:

};


void setup()
{
  pinMode( 3, OUTPUT);
  pinMode( 4, OUTPUT);
  pinMode( 7, OUTPUT);

  pinMode( 9, OUTPUT);
  pinMode( 12, OUTPUT);
  pinMode( 13, OUTPUT);
}

Motor newMotor;

void loop()
{
	newMotor.emfrente();
}
