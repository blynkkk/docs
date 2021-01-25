# Virtual Pins

Virtual Pins is a way to exchange any data between your hardware and Blynk app. Think about Virtual Pins as channels for sending any data. Make sure you differentiate Virtual Pins from physical GPIO pins on your hardware. Virtual Pins have no physical representation.

Virtual Pins are commonly used to interface with other libraries \(Servo, LCD and others\) and implement custom logic. The device can send data to the App using `Blynk.virtualWrite(pin, value)` and receive data from the App using `BLYNK_WRITE(vPIN)`. Read below

### Virtual Pin data types

All Virtual Pin values are always sent as Strings and there are no practical limits on the data that can be sent.  
However, there are certian limitations on the hardware side when dealing with numbers. For example, the integer on Arduino is 16-bit, allowing range -32768 to 32767.

To interpret incoming data as Integers, Floats, Doubles and Strings use:

```cpp
param.asInt();
param.asFloat();
param.asDouble();
param.asStr();
```

You can also get the RAW data from the param buffer:

```cpp
param.getBuffer()
param.getLength()
```

## Blynk.virtualWrite\(vPin, value\)

**NOTE: Use BlynkTimer when you use this command to send data. Otherwise your hardware will be disconnected from the server**

Send data in various formats to Virtual Pins.

```cpp
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

```cpp
Blynk.virtualWrite(128, "abc");
```

## BLYNK\_WRITE\(vPIN\)

`BLYNK_WRITE` is a function called every time device gets an update of Virtual Pin value from the server \(or app\):

To read the received data use:

```cpp
BLYNK_WRITE(V0)
{   
  int value = param.asInt(); // Get value as integer

  // The param can contain multiple values, in such case:
  int x = param[0].asInt();
  int y = param[1].asInt();
}
```

**`BLYNK_WRITE` can't be used inside of any loop or function. It's a standalone function.**

**Note:** For virtual pins with numbers &gt; 127, please use `BLYNK_WRITE_DEFAULT()` API

## BLYNK\_READ\(vPIN\)

`BLYNK_READ` is function called when device is requested to send it's current value of Virtual Pin to the server. Normally, this function should contain `Blynk.virtualWrite` call\(s\).

```cpp
BLYNK_READ(V0)
{
  Blynk.virtualWrite(V0, newValue);
}
```

**Note:** For virtual pins with numbers &gt; 127, please use `BLYNK_READ_DEFAULT()` API

## BLYNK\_WRITE\_DEFAULT\(\)

Redefines the handler for all pins that are not covered by custom `BLYNK_WRITE` functions.

```cpp
BLYNK_WRITE_DEFAULT()
{
  int pin = request.pin;      // Which exactly pin is handled?
  int value = param.asInt();  // Use param as usual.
}
```

## BLYNK\_READ\_DEFAULT\(\)

Redefines the handler for all pins that are not covered by custom `BLYNK_READ` functions.

```cpp
BLYNK_READ_DEFAULT()
{
  int pin = request.pin;      // Which exactly pin is handled?
  Blynk.virtualWrite(pin, newValue);
}
```

## Blynk.syncAll\(\)

Requests all stored on the server latest values for all widgets. All analog/digital/virtual pin values and states will be set to the latest stored value. Every virtual pin will generate BLYNK\_WRITE\(\) event.

```cpp
BLYNK_CONNECTED() {
    Blynk.syncAll();
}
```

## Blynk.syncVirtual\(vPin\)

This command updates individual Virtual Pin to the latest stored value on the server. When it's used, a corresponding `BLYNK_WRITE` handler is called.

```cpp
Blynk.syncVirtual(V0);
```

To update multiple pins, use:

```text
Blynk.syncVirtual(V0, V1, V6, V9, V16);
```

## Blynk.setProperty\(vPin, "property", value\)

This command allows [changing widget properties](https://github.com/blynkkk/docs/tree/b7e1f17dc099ba9cebae3461a13ca2fe69b767a8/blynk.edgent/api/blynkfirmware.md#blynk-main-operations-change-widget-properties)

