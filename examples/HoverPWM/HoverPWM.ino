#include <IFMSMotor.h>

PwmHover* hover;

void setup() {
  // put your setup code here, to run once:
  hover = new PwmHover(3, 7, 6, 5, 8, 9);
  hover->setSpeed(130);
}

void loop() {
  for(int i=0; i<=255; i++){
    hover->setSpeed(i);
    hover->avancar();
    delay(10);
  }
  delay(500);
  for(int i=255; i>=0; i--){
    hover->setSpeed(i);
    hover->avancar();
    delay(10);
  }
  delay(500);

  for(int i=0; i<=255; i++){
    hover->setSpeed(i);
    hover->recuar();
    delay(10);
  }
  delay(500);
  for(int i=255; i>=0; i--){
    hover->setSpeed(i);
    hover->recuar();
    delay(10);
  }
  delay(500);
}
