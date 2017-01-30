#include <WiiChuck.h>

void setup() {
	Serial.begin(115200);
	Nunchuck.begin();
}

void loop() {
	Nunchuck.update();

  static char buf[80];

  sprintf(buf, "Joystick: (%3d, %3d), Acceleration: (%4d, %4d, %4d), C: %d, Z: %d",
    Nunchuck.analogX(),
    Nunchuck.analogY(),
    Nunchuck.accelX(),
    Nunchuck.accelY(),
    Nunchuck.accelZ(),
    Nunchuck.cButton.isPressed(),
    Nunchuck.zButton.isPressed()
  );

  Serial.println(buf);
}
