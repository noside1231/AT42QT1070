// ----------------------------------------------------------------------------
// AT42QT1070.cpp
//
// Author:
// Edison Grauman
// ----------------------------------------------------------------------------

#include "AT42QT1070.h"

#define I2C_ADDR 0x1B
#define THRESHOLD 20

AT42QT1070::AT42QT1070() {
}

void AT42QT1070::begin() {
  // Serial.println(F("Starting AT42QT1070"));
  Wire.begin();
}

uint8_t AT42QT1070::getChipID() {
  return read(0);
}

uint8_t AT42QT1070::getFirmwareVersion() {
  return read(1);
}

bool AT42QT1070::isTouched() {
  return read(2) & 1;
}

//Key Status returns single key index bit of first touched only
uint8_t AT42QT1070::getKeyStatus() {
  return read(3);
}

uint8_t AT42QT1070::getTouchedKeys() {
  if (!isTouched()) {
    return 0;
  }

  uint8_t key_status = 0;
  for (int i = 0; i < 7; i++) {
    if (((readTwoRegisters((2 * i) + 4)) - readTwoRegisters((2 * i) + 18)) > THRESHOLD) {
      key_status = key_status | 1 << i;
    }
  }
  return key_status;
}

uint16_t AT42QT1070::readTwoRegisters(uint8_t start_reg_addr) {
  return (read(start_reg_addr) << 8) | read(start_reg_addr);
}

uint8_t AT42QT1070::read(uint8_t reg_addr) {
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(reg_addr);
  Wire.endTransmission();
  Wire.requestFrom(I2C_ADDR, 1);
  return Wire.read();
}

void AT42QT1070::write(uint8_t reg_addr, uint8_t data) {
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(reg_addr);
  Wire.write(data);
  Wire.endTransmission();
}
