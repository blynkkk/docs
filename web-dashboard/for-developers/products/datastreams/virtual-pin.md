# Virtual Pin

Virtual Pins is a way to exchange any data between your hardware and Blynk app. Think about Virtual Pins as channels for sending any data. Make sure you differentiate Virtual Pins from physical GPIO pins on your hardware. Virtual Pins have no physical representation.

Virtual Pins are commonly used to interface with other libraries \(Servo, LCD and others\) and implement custom logic. The device can send data to the App using `Blynk.virtualWrite(pin, value)` and receive data from the App using `BLYNK_WRITE(vPIN)`. Read below

