#include "IFMSMotor.h";

Motor motorA, motorB;


void setup() {
  motorA.setup(4, 5);
  motorB.setup(10, 11);
}

void loop() {
  motorA.backward();
  motorB.backward();
  delay(2000);

  motorA.stop();
  motorB.stop();
  delay(500);

  motorA.forward();
  motorB.forward();
  delay(2000);
  
  motorA.stop();
  motorB.stop();
  delay(500);
}
