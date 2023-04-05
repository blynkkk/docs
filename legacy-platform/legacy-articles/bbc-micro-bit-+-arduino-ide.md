# BBC micro:bit + Arduino IDE

{% hint style="warning" %}
This documentation is for the LEGACY version of Blynk platform which is no longer supported and will be shut down.&#x20;

You can sign up for the current version of Blynk platform [here](http://blynk.cloud/dashboard/register).

The new mobile apps can be downloaded from [App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868) and [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk\&hl=en\&gl=US).

The actual Blynk documentation is [here](https://docs.blynk.io/).
{% endhint %}

In March 2016, BBC started delivering a **micro:bit** to every 11-year-old kid in Britain, as part of the BBC Make it Digital initiative. They should have provided nearly 1 million of devices for free.\
BBC micro:bit is quite a nice piece of hardware: small, low-power, embedded device with inputs, outputs, and a processor. It includes a variety of sensors, 25 LED lights, two programmable buttons, and Bluetooth, with power provided either through an external battery pack or an attached USB device.\
It can be used with JavaScript, Python, or Scratch programming languages and is perfect for education in engineering and electronics.\
![](https://downloads.intercomcdn.com/i/o/63020503/78dfd6fe3afcb66922ded8bd/microbit-hardware.png)

But you can get bored with the functionality of the board itself.\
What if you could easily build an iOS/Android app to interact with your micro:bit?\
Blynk does just that! Here is how to use it with Arduino IDE. The whole tutorial should not take more than 30 minutes.\


### Install required software <a href="#install-required-software" id="install-required-software"></a>

1. Download and install the latest [**Arduino IDE**](https://www.arduino.cc/en/Main/Software)**.**
2. Install  **Nordic nRF5 support package** for Arduino. Follow [instructions here](https://github.com/sandeepmistry/arduino-nRF5#installing).
3. Install **BLEPeripheral** library.\
   You can use **Arduino Library Manager** or [install manually](https://github.com/sandeepmistry/arduino-BLEPeripheral).
4. Install the latest **Blynk libraries**. [Our instructions](https://github.com/blynkkk/blynk-library/releases/latest).
5. Install **Blynk** app on your smartphone, and create an account (if you don't have one).\


### Configure your Arduino IDE and Micro:Bit <a href="#configure-your-arduino-ide-and-microbit" id="configure-your-arduino-ide-and-microbit"></a>

In Arduino IDE:

1. Select **Tools -> Board -> BBC micro:bit**
2. Select **Tools -> SoftDevice -> S110 \***
3. Select **Tools -> Programmer -> CMSIS-DAP**
4. Connect your Micro:Bit
5. Select: **Tools -> nRF5 Flash SoftDevice** (read and accept the license)

\*Blynk device works as a Peripheral. So you may select any compatible **SoftDevice:**\
S110 is for Peripheral\
S120 is for Central only\
S130 is for Central + Peripheral\
S132 is for Nordic nRF52-based boards,  Central + Peripheral

### Upload your first sketch! <a href="#upload-your-first-sketch" id="upload-your-first-sketch"></a>

Using Blynk smartphone app, create a **New Project**.\
Select **BBC Micro:bit** device, **BLE** connection type.![](https://downloads.intercomcdn.com/i/o/63020504/2ebd400e0685a1a8bec47105/Screenshot\_2017-05-18-16-27-01-357\_cc.blynk.png)

A new **Auth Token** for this device will land in your email box.\
\
Open our example for micro:bit in Arduino IDE:\
**File > Examples > Blynk > Boards\_Bluetooth > BBC\_MicroBit**

Inside of the sketch, replace "YourAuthToken" with the token you have received:![](https://downloads.intercomcdn.com/i/o/63020506/24657339e9c7a99608a119fd/CaptureIDE.PNG)

That's it! **Click "Upload" button.**\
\
In your project, add **BLE widget** and tap on it to open **BLE Settings**.

1. Click "Connect BLE device" button.
2. Select "Blynk" device.
3. Blynk App should report that the device is connected.

### Make something useful ;) <a href="#make-something-useful" id="make-something-useful"></a>

![](https://downloads.intercomcdn.com/i/o/63020508/4fc09b6d5ab9fb1e9bcb8812/xdossmmf.jpg)

#### Reading Analog Sensor <a href="#reading-analog-sensor" id="reading-analog-sensor"></a>

In Blynk App, add a **Value Display widget** and attach it to **Analog Pin 1.**\
After you run the project, you should see the value of analog sensor.\


#### Reading Button Status <a href="#reading-button-status" id="reading-button-status"></a>

Add these lines on the top of `setup` function, and upload it to the board.

```
  // Configure on-board buttons
  pinMode(PIN_BUTTON_A, INPUT_PULLUP);
  pinMode(PIN_BUTTON_B, INPUT_PULLUP);
```

Add a **Value Display widget** and attach it to **Digital Pin 5.**\
This is the pin of Button A, for Button B use pin 11 (see the pin map).\
**Run** your project to see the button status.\


#### Switching some LEDs on and off  <a href="#switching-some-leds-on-and-off" id="switching-some-leds-on-and-off"></a>

For this, you will have to add more code to your sketch. Add this above your loop and setup functions (not inside of them):&#x20;

```
#define LED_ROW2 27
#define LED_COL3 10

BLYNK_WRITE(V0)
{
  pinMode(LED_ROW2, OUTPUT);
  pinMode(LED_COL3, OUTPUT);
  if (param.asInt() == 1)        /* When button widget is "ON" */
  {
    digitalWrite(LED_ROW2, 1);
    digitalWrite(LED_COL3, 0);
  }
  else
  {
    digitalWrite(LED_ROW2, 0);
    digitalWrite(LED_COL3, 0);
  }
}
```

Why do we need to use 2 pins to drive a single LED? That's a legitimate question!\
Actually, this trick allows us to control all 25 LEDs by toggling just 12 GPIO pins in total.\
Read more about [how micro:bit display works](https://lancaster-university.github.io/microbit-docs/ubit/display/).

Now add a **Button widget (select mode: Switch)**, assign it to **Virtual Pin 0.**\
**Run** the project, and try clicking the Button widget.\
The middle LED should light up.![](https://downloads.intercomcdn.com/i/o/63020510/90e3eff07c251fa327adbe81/Screenshot\_2017-05-18-23-50-58-786\_cc.blynk.png)

### What next? <a href="#what-next" id="what-next"></a>

Read about [**Virtual Pins**](http://help.blynk.cc/blynk-basics/what-is-virtual-pins) concept and unleash full power of Blynk.\
Blynk supports huge amount of board types. [Check if your favourite is on the list!](https://github.com/blynkkk/blynkkk.github.io/blob/master/SupportedHardware.md)\
Our library is Open Source Software. [Give](https://github.com/blynkkk/blynk-library/blob/master/README.md) us a star on GitHub.

### Challenges <a href="#challenges" id="challenges"></a>

While micro:bit is working quite well in this mode, there are no default drivers currently available. For example, no convenient functions to work with the on-board LED array.\
However (with some efforts) these drivers can be ported to Arduino IDE:\
[https://github.com/lancaster-university/microbit-dal/](https://github.com/lancaster-university/microbit-dal/)\
The pin mapping for Arduino IDE core can be found [here](https://github.com/sandeepmistry/arduino-nRF5/blob/master/variants/BBCmicrobit/variant.cpp).\
And [here](http://www.iot-programmer.com/index.php/books/27-micro-bit-iot-in-c/chapters-micro-bit-iot-in-c/1-getting-started-with-c-c-on-the-micro-bit) is some advanced information on low-level C/C++ programming on micro:bit.&#x20;
