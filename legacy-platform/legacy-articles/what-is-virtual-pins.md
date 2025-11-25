---
description: Exchange any data between Blynk app and your hardware
---

# What is Virtual Pins

{% hint style="warning" %}
This documentation is for the LEGACY version of Blynk platform which is no longer supported and will be shut down.&#x20;

You can sign up for the current version of Blynk platform [here](http://blynk.cloud/dashboard/register).

The new mobile apps can be downloaded from [App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868) and [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk\&hl=en\&gl=US).

The actual Blynk documentation is [here](https://docs.blynk.io/).
{% endhint %}

**Virtual Pin** is a concept invented by Blynk Inc. to provide exchange of any data between hardware and Blynk mobile app.&#x20;

Virtual pins are different than  [Digital](https://www.arduino.cc/en/Tutorial/DigitalPins) and [Analog](https://www.arduino.cc/en/Tutorial/AnalogInputPins) Input/Output (I/O) pins. They are **physical pins** on your microcontroller board where you connect sensors and actuators.![](https://uploads.intercomcdn.com/i/o/19844964/1b2212d3c5c061943f6bdeb0/Group+5.png)

**Blynk lets you control any hardware connected to Digital and Analog pins without having to write any additional code.**

For example, if you need to turn On/Off LED connected to Digital pin, you don't have to write any code:&#x20;

1. Just use [BlynkBlink code for your hardware](http://examples.blynk.cc/).&#x20;
2. In the Blynk app - add **Button Widget** and set it to pin **D8**
3. That's it! No additional code is required. Simply press Play in the app.

![](https://uploads.intercomcdn.com/i/o/19845951/6a0d22dfd602a1f118ecba93/Group+3+Copy.png)

That was, easy, right? But what if you need more flexibility?

### Virtual Pins <a href="#virtual-pins" id="virtual-pins"></a>

Virtual pins allow you to interface with any sensor, any library, any actuator.&#x20;

Imagine that there are "virtual" pins that you can use\
![](https://uploads.intercomcdn.com/i/o/19851900/f385072e3b34e023aba74a07/VP.png)

Think about Virtual Pins as a box where you can put any value, and everyone who has access to this box can see this value.

It's a very powerful feature to **display and send any data** from your hardware to Blynk app.&#x20;

**☝️ Remember, that virtual pins have no physical properties.**

There are two fundamental commands you need to know to use Virtual Pins:

### To read data from Blynk app widgets <a href="#to-read-data-from-blynk-app-widgets" id="to-read-data-from-blynk-app-widgets"></a>

Use this block of code:

```
BLYNK_WRITE(V5) // V5 is the number of Virtual Pin  
{
  int pinValue = param.asInt();
}
```

Where `param.asInt()`  is the value from V5.

\
👉 Full article: [**How to control anything with Blynk**](http://help.blynk.cc/getting-started/blynk-basics/how-to-control-anything-with-blynk-app)

### To send data from your hardware to Blynk app <a href="#to-send-data-from-your-hardware-to-blynk-app" id="to-send-data-from-your-hardware-to-blynk-app"></a>

Use this command `Blynk.virtualWrite(V5)` where V5 is the Virtual Pin you are using. &#x20;

⚠️ **WARNING:**\
**Don't place** `Blynk.virtualWrite(V5)` **inside**  `void loop()`&#x20;

– Why?\
– Read [here](http://help.blynk.cc/getting-started/blynk-basics/how-to-display-any-sensor-data-in-blynk-app)  <br>

👉 Full article: [**How to display any sensor data with Blynk**](http://help.blynk.cc/getting-started/blynk-basics/how-to-display-any-sensor-data-in-blynk-app)\
![](https://uploads.intercomcdn.com/i/o/19866955/96eec33e38de6f75c3371861/Sensor+2.png)

**---**\
**If you have questions or something is not working, visit our 👥** [**community**](http://community.blynk.cc/) **page.**

Also, full 📗 documentation is [here](http://docs.blynk.cc/).<br>
