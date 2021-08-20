# Virtual Pins

Blynk can control Digital and Analog I/O Pins on you hardware directly. You don't even need to write code for it. It's great for blinking LEDs, but often it's just not enough...

We designed Virtual Pins to send **any** data from your microcontroller to the Blynk App and back.

Anything you connect to your hardware will be able to talk to Blynk. With Virtual Pins you can send something from the App, process it on microcontroller and then send it back to the smartphone. You can trigger functions, read I2C devices, convert values, control servo and DC motors etc.

Virtual Pins can be used to interface with external libraries \(Servo, LCD and others\) and implement custom functionality.

Hardware may send data to the Widgets over the Virtual Pin like this:

```cpp
Blynk.virtualWrite(pin, "abc");
Blynk.virtualWrite(pin, 123);
Blynk.virtualWrite(pin, 12.34);
Blynk.virtualWrite(pin, "hello", 123, 12.34);
```

For more information about virtual pins, [read this](../../getting-started/using-virtual-pins-to-control-physical-devices.md)

## Send data from app to hardware

You can send any data from Widgets in the app to your hardware.

All Controller Widgets can send data to Virtual Pins on your hardware. For example, code below shows how to get values from the Button Widget in the App

```cpp
BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  int pinData = param.asInt(); 
}
```

When you press a Button, Blynk App sends `1` On the second click - it sends `0`

Full example sketch: [Get Data](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/GetData/GetData.ino#L24)

### Sending array from Widget

Some Widgets \(e.g Joystick, zeRGBa\) have more than one output.

![](https://github.com/blynkkk/docs/tree/a1ea2ed8bc31eba522320f514b900921303d3b07/.gitbook/assets/joystick_merge_mo_de.png)

This output can be written to Virtual Pin as an array of values. On the hardware side - you can get any element of the array \[0,1,2...\] by using:

```cpp
BLYNK_WRITE(V1) // Widget WRITEs to Virtual Pin V1
{   
  int x = param[0].asInt(); // getting first value
  int y = param[1].asInt(); // getting second value
  int z = param[N].asInt(); // getting N value
}
```

**Sketch:** [JoystickTwoAxis](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/JoystickTwoAxis/JoystickTwoAxis.ino)

## Pushing data from hardware

If you need to PUSH sensor or other data from your hardware to Widget, you can write any logic you want. Any command that hardware sends to Blynk Cloud is automatically stored on the server and you get this info either with SuperChart widget or with [HTTP API](http://docs.blynkapi.apiary.io/#reference/0/pin-history-data/get-all-history-data-for-specific-pin).

![](https://github.com/blynkkk/docs/tree/b7e1f17dc099ba9cebae3461a13ca2fe69b767a8/blynk.edgent/.gitbook/assets/frequency_reading_push.png)

We recommend sending data in intervals and avoiding [Flood Error](https://docs.blynk.cc/#troubleshooting-flood-error). You can use timers like [BlynkTimer](https://github.com/blynkkk/docs/tree/b7e1f17dc099ba9cebae3461a13ca2fe69b767a8/blynk.edgent/README.md#blynk-firmware-blynktimer). Please read instructions inside this [example sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/PushData/PushData.ino) for more details.

Here is how it can work:

```cpp
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

char auth[] = "YourAuthToken"; // Put your token here

BlynkTimer timer; // Create a Timer object called "timer"! 

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);

  timer.setInterval(1000L, sendUptime); //  Here you set interval (1sec) and which function to call 
}

void sendUptime()
{
  // This function sends Arduino up time every 1 second to Virtual Pin (V5)
  // In the app, Widget's reading frequency should be set to PUSH
  // You can send anything with any interval using this construction
  // Don't send more that 10 values per second

  Blynk.virtualWrite(V5, millis() / 1000);
}

void loop()
{
  Blynk.run(); // all the Blynk magic happens here
  timer.run(); // BlynkTimer is working...
}
```

**Sketch:** [PushData](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/PushData/PushData.ino#L30)

