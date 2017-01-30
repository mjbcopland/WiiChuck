#pragma once

#include <stdint.h>
#include <Button.h>

class WiiChuck {
private:
  // The nunchuck reports 6 bytes of data
  // See http://wiibrew.org/wiki/Wiimote/Extension_Controllers/Nunchuck#Data_Format
  static uint8_t data[6];

  class NunchuckButton : public BaseButton {
  public:
    NunchuckButton(const uint8_t mask)
        : BaseButton(0), mask(mask) {}

    inline bool read() const {return !(WiiChuck::data[5] & mask);}

  private:
    const uint8_t mask;
  };

public:
  static const uint8_t I2C_ADDR = 0x52;

  static void begin();
  static void update();

  static inline uint8_t analogX() {return data[0];}
  static inline uint8_t analogY() {return data[1];}

  static inline uint16_t accelX() {return (data[2] << 2) | ((data[5] >> 2) & 0x03);}
  static inline uint16_t accelY() {return (data[3] << 2) | ((data[5] >> 4) & 0x03);}
  static inline uint16_t accelZ() {return (data[4] << 2) | ((data[5] >> 6) & 0x03);}

  static NunchuckButton cButton, zButton;
};

extern WiiChuck Nunchuck;
