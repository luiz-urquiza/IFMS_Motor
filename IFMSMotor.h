#ifndef _IFMSMotor_h
#define _IFMSMotor_h

struct Motor{
  int in1;
  int in2;

  void setup(int pin1, int pin2){
    in1 = pin1;
    in2 = pin2;

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }

  void forward(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }

  void backward(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }

  void stop(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
};

/*
struct PwmMotor{
    int in1;
    int in2;
    int pwm;
    int speed;

    void setup(int pinPwm, int pin1, int pin2, int speedValue){
        in1 = pin1;
        in2 = pin2;
        pwm = pinPwm;
        speed = (speedValue < 0)? 0: (speedValue > 255)? 255: speedValue;

        pinMode(in1, OUTPUT);
        pinMode(in2, OUTPUT);

        analogWrite(pwm, 0);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
    }

    void setup(int pinPwm, int pin1, int pin2){
        setup(pin1, pin2, pinPwm, 255);
    }

    void forward(){
        analogWrite(pwm, speed);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    }

    void backward(){
        analogWrite(pwm, speed);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    }
    
    void stop(){
        analogWrite(pwm, 0);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
    }

};
*/

class Hover{

    public:
        Hover(int motorA_in1, int motorA_in2);
        Hover(int motorA_in1, int motorA_in2, int motorB_in1, int motorB_in2);
        void avancar();
        void recuar();
        void girarA();
        void girarB();
        void parar();

    private:
        Motor motorA;
        Motor motorB;
};

class PwmMotor{
	public:
		PwmMotor(int pinPwm, int pin1, int pin2);
		void forward();
		void backward();
		void stop();
		void setSpeed(int sp);
	private:
		int in1;
		int in2;
		int pwm;
		int speed;
};

class PwmHover{
    public:
        PwmHover(int pwmEsq, int motorEsq_in1, int motorEsq_in2, int pwmDir, int motorDir_in1, int motorDir_in2);
        void setSpeed(int speed);
        void avancar();
        void recuar();
        void girarDir();
        void girarEsq();
        void parar();        

    private:
        PwmMotor *motorEsq;
        PwmMotor *motorDir;
};


#endif;