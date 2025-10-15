#include "IFMSMotor.h";

Hover hover(4, 5, 10, 11);

void setup() {
}

void loop() {
  hover.avancar();
  delay(2000);

  hover.parar();
  delay(500);

  hover.recuar();
  delay(2000);

  hover.parar();
  delay(500);
}
