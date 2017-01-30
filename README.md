# WiiChuck

### **This library is dependent on [Button].**

## Usage

### `Nunchuk.begin()`

Initialises the Nunchuk over I²C.

### `Nunchuk.update()`

Reads and updates the state of the Nunchuk.

### `Nunchuk.analogX()`, `Nunchuk.analogY()`

Returns the corresponding analogue stick position as an 8-bit unsigned integer.

### `Nunchuk.accelX()`, `Nunchuk.accelY()`, `Nunchuk.accelZ()`

Returns the corresponding accelerometer axis as a 10-bit unsigned integer.

### `Nunchuk.cButton`, `Nunchuk.zButton`

Button objects for the C and Z buttons respectively. See [Button].



[Button]:https://github.com/mjbcopland/Button
