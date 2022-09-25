
#include "Tests.h"

void setup() {
  Serial.begin(9600);
  while (!Serial)
  {
    /* code */
  }

  mapTest();
  vectorTest();
  // angleTest();
}

void loop() {
  // put your main code here, to run repeatedly:
}