// ----------------------------------------------------------------------------
// AT42QT1070.h
//
// Author:
// Edison Grauman
// ----------------------------------------------------------------------------

#ifndef AT42QT1070_H
#define AT42QT1070_H

#include <Arduino.h>
#include <Wire.h>

class AT42QT1070 {

public:
  AT42QT1070();

  void begin();
  uint8_t getChipID();
  uint8_t getFirmwareVersion();
  bool isTouched();
  uint8_t getKeyStatus();
  uint8_t getTouchedKeys();

private:
  uint8_t read(uint8_t reg_addr);
  void write(uint8_t reg_addr, uint8_t data);
  uint16_t readTwoRegisters(uint8_t start_reg_addr);
};

#endif
