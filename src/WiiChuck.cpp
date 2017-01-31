#include "WiiChuck.h"
#include <Arduino.h>
#include <Wire.h>

void WiiChuck::begin() {
  Wire.begin();

  // We use the "new" method of initialization
  // See http://forum.arduino.cc/index.php?topic=45924#msg333160
  // and http://wiibrew.org/wiki/Wiimote/Extension_Controllers#Identification

  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0xF0);
  Wire.write(0x55);
  Wire.endTransmission();

  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0xFB);
  Wire.write(0x00);
  Wire.endTransmission();

  update();
}

void WiiChuck::update() {
  // send conversion command
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x00);
  Wire.endTransmission();

  // wait for data to be converted
  delay(1);

  // read data
  Wire.readBytes(data, Wire.requestFrom(I2C_ADDR, sizeof(data)));

  // update buttons
  cButton.update();
  zButton.update();
}

// initialise static WiiChuck members
uint8_t WiiChuck::data[6];
WiiChuck::WiiChuckButton WiiChuck::cButton(0x02);
WiiChuck::WiiChuckButton WiiChuck::zButton(0x01);

// initialise WiiChuck object
WiiChuck Nunchuk;
