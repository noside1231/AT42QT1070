#include "AT42QT1070.h"

AT42QT1070 at42qt1070;

void setup() {
  Serial.begin(9600);
  at42qt1070.begin();
  delay(1000);
  Serial.println(at42qt1070.getChipID(), HEX);
}

void loop() {
  Serial.println(at42qt1070.getTouchedKeys(),BIN);
  delay(10);
}
