# Digital & Analog pins control

Blynk library can perform basic pin IO \(input-output\) operations out-of-the-box:

```text
digitalRead
digitalWrite
analogRead
analogWrite (PWM or Analog signal depending on the platform)
```

No need to write code for simple things like LED, Relay control and analog sensors. Just choose a corresponding Pin in Blynk app and control it directly with no additional code

### Virtual pins control <a id="blynk-firmware-virtual-pins-control"></a>

Virtual Pins is a way to exchange any data between your hardware and Blynk app. Think about Virtual Pins as channels for sending any data. Make sure you differentiate Virtual Pins from physical GPIO pins on your hardware. Virtual Pins have no physical representation.

Virtual Pins are commonly used to interface with other libraries \(Servo, LCD and others\) and implement custom logic. The device can send data to the App using `Blynk.virtualWrite(pin, value)` and receive data from the App using `BLYNK_WRITE(vPIN)`. Read below

**Virtual Pin data types**

All Virtual Pin values are always sent as Strings and there are no practical limits on the data that can be sent.  
However, there are certian limitations on the hardware side when dealing with numbers. For example, the integer on Arduino is 16-bit, allowing range -32768 to 32767.

To interpret incoming data as Integers, Floats, Doubles and Strings use:

```text
param.asInt();
param.asFloat();
param.asDouble();
param.asStr();
```

You can also get the RAW data from the param buffer:

```text
param.getBuffer()
param.getLength()
```

#### Blynk.virtualWrite\(vPin, value\) <a id="blynk-firmware-virtual-pins-control-blynkvirtualwritevpin-value"></a>

**NOTE: Use BlynkTimer when you use this command to send data. Otherwise your hardware will be disconnected from the server**

Send data in various formats to Virtual Pins.

```text
// Send string
Blynk.virtualWrite(pin, "abc");

// Send integer
Blynk.virtualWrite(pin, 123);

// Send float
Blynk.virtualWrite(pin, 12.34);

// Send multiple values as an array
Blynk.virtualWrite(pin, "hello", 123, 12.34);

// Send RAW data
Blynk.virtualWriteBinary(pin, buffer, length);
```

Calling `virtualWrite` attempts to send the value to the network immediately.

**Note:** For virtual pins with numbers &gt; 127, the `V128` syntax is not available.  
Please use plain virtual pin number, for example:

```text
Blynk.virtualWrite(128, "abc");
```

