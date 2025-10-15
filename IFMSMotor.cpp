#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #if defined(__AVR__)
    #include <avr/io.h>
  #endif
  #include "WProgram.h"
#endif

#include "IFMSMotor.h"

Hover::Hover(int motorA_in1, int motorA_in2){
    Hover::motorA.setup(motorA_in1, motorA_in2);
}

Hover::Hover(int motorA_in1, int motorA_in2, int motorB_in1, int motorB_in2){
    Hover::motorA.setup(motorA_in1, motorA_in2);
    Hover::motorB.setup(motorB_in1, motorB_in2);
}

void Hover::avancar(){
    Hover::motorA.forward();
    Hover::motorB.forward();
}

void Hover::recuar(){
    Hover::motorA.backward();
    Hover::motorB.backward();
}

void Hover::girarA(){
    Hover::motorA.forward();
    Hover::motorB.backward();
}

void Hover::girarB(){
    Hover::motorA.backward();
    Hover::motorB.forward();
}

void Hover::parar(){
    Hover::motorA.stop();
    Hover::motorB.stop();
}

/**
 *	Classe PwmMotor
 *
**/
PwmMotor::PwmMotor(int pinPwm, int pin1, int pin2){
	pwm = pinPwm;
	in1 = pin1;
	in2 = pin2;
	speed = 0;
	
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	
	stop();
}

void PwmMotor::forward(){
    analogWrite(pwm, speed);
    digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
}

void PwmMotor::backward(){
    analogWrite(pwm, speed);
    digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
}

void PwmMotor::stop(){
    analogWrite(pwm, 0);
    digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

void PwmMotor::setSpeed(int sp){
    speed = (sp > 255)? 255: sp;
	speed = (sp < 0)? 0: sp;
}

/**
 *	Classe PwmHover
 *
**/
PwmHover::PwmHover(int pwmEsq, int motorEsq_in1, int motorEsq_in2, int pwmDir, int motorDir_in1, int motorDir_in2){
    PwmHover::motorEsq = new PwmMotor(pwmEsq, motorEsq_in1, motorEsq_in2);
    PwmHover::motorDir = new PwmMotor(pwmDir, motorDir_in1, motorDir_in2);
}

void PwmHover::setSpeed(int speed){
    PwmHover::motorEsq->setSpeed(speed);
    PwmHover::motorDir->setSpeed(speed);
}

void PwmHover::avancar(){
    PwmHover::motorEsq->forward();
    PwmHover::motorDir->forward();
}

void PwmHover::recuar(){
    PwmHover::motorEsq->backward();
    PwmHover::motorDir->backward();
}

void PwmHover::girarEsq(){
    PwmHover::motorEsq->backward();
    PwmHover::motorDir->forward();
}

void PwmHover::girarDir(){
    PwmHover::motorEsq->forward();
    PwmHover::motorDir->backward();
}

void PwmHover::parar(){
    PwmHover::motorEsq->stop();
    PwmHover::motorDir->stop();
}
