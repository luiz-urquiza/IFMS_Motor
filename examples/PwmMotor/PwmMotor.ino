#include <IFMSMotor.h>

PwmMotor motorDir;
PwmMotor motorEsq;

void setup() {
  motorDir.setup(3, 8, 9, 150);
  motorEsq.setup(5, 7, 6, 150);
}

void loop() {
  motorDir.forward();
  motorEsq.forward();
  delay(2000);

  motorDir.stop();
  motorEsq.stop();
  delay(500);

  motorDir.backward();
  motorEsq.backward();
  delay(2000);

  motorDir.stop();
  motorEsq.stop();
  delay(500);
}
