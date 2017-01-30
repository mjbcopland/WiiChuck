#include <WiiChuck.h>

void setup() {
  Serial.begin(115200);
  Nunchuk.begin();
}

void loop() {
  Nunchuk.update();

  static char buf[80];

  sprintf(buf, "Joystick: (%3d, %3d), Acceleration: (%4d, %4d, %4d), C: %d, Z: %d",
    Nunchuk.analogX(),
    Nunchuk.analogY(),
    Nunchuk.accelX(),
    Nunchuk.accelY(),
    Nunchuk.accelZ(),
    Nunchuk.cButton.isPressed(),
    Nunchuk.zButton.isPressed()
  );

  Serial.println(buf);
}
