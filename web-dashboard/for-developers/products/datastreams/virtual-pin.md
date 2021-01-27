---
description: >-
  This datastream is a way to exchange any data between your hardware, Blynk.360
  and Blynk.App. Think about Virtual Pins as channels for sending any data.
  Virtual Pins have no physical representation.
---

# Virtual Pin

Please make sure you differentiate Virtual Pins from physical GPIO pins on your hardware. 

Virtual Pins are commonly used to interface with other libraries \(Servo, LCD and others\) and implement custom logic. The Device can send data to Blynk.360 and/or Blynk.App using `Blynk.virtualWrite(pin, value)` and receive data from the Blynk.360 and/or Blynk.App using `BLYNK_WRITE(vPIN)`. 

![](../../../../.gitbook/assets/vpin_ds.png)

