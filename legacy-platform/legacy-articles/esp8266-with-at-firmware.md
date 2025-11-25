# ESP8266 with AT firmware

{% hint style="warning" %}
This documentation is for the LEGACY version of Blynk platform which is no longer supported and will be shut down.&#x20;

You can sign up for the current version of Blynk platform [here](http://blynk.cloud/dashboard/register).

The new mobile apps can be downloaded from [App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868) and [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk\&hl=en\&gl=US).

The actual Blynk documentation is [here](https://docs.blynk.io/).
{% endhint %}

ESP8266 WiFi module (or shield) with default AT firmware can be used to connect your hardware to Blynk.

### ESP8266 Shields <a href="#esp8266-shields" id="esp8266-shields"></a>

These come in different shapes and colors, but basically you can use simple ESP01 module like this:\
![](https://s3.amazonaws.com/uploads.intercomcdn.com/i/o/20403619/89af7398dd485c00c1235a9e/upload_8700179421741362625)

If you have an Arduino Shield with ESP8266 (like doit.com ESP13 Shield), you don't need to do this wiring - that is already done for you!

#### ☝️ This connection type is very tricky to start with. As a MUCH easier option, we recommend to start with  [ESP8266 as a standalone platform](http://help.blynk.cc/blynkkk-blynk-library/esp8266-standalone) (Blynk can run directly on ESP8266 chip). <a href="#this-connection-type-is-very-tricky-to-start-with-as-a-much-easier-option-we-recommend-to-start-with" id="this-connection-type-is-very-tricky-to-start-with-as-a-much-easier-option-we-recommend-to-start-with"></a>

### &#x20; <a href="#h_2bbb223880" id="h_2bbb223880"></a>

#### ☝️ This method does not work with [this](http://www.arduino.org/products/boards/arduino-uno-wifi?gclid=CjwKEAjwytLKBRCX547gve7EsE4SJAD3IZV6jA96xZ-U5ED2VI6ARlTxVJRe1k1iDOUNggAoyCbL1hoCQ2Pw_wcB) Arduino UNO WIFI board (at least until Arduino provides proper TCP libraries). <a href="#this-method-does-not-work-with-this-arduino-uno-wifi-board-at-least-until-arduino-provides-proper-tc" id="this-method-does-not-work-with-this-arduino-uno-wifi-board-at-least-until-arduino-provides-proper-tc"></a>

### --- <a href="#undefined" id="undefined"></a>

First of all, it is recommended to buy a USB-UART TTL converter, capable to supply 1A @ 3.3V. This will help you in lots of different cases, not only for ESP8266. For ESP8266, it will be needed for initial configuration and testing, AT firmware upgrade, etc.

☝️ If you run ESP8266-standalone example on your ESP8266 module, it overwrites AT firmware of the module, so it won't work as modem. Make sure your ESP is flashed with AT firmware (you can find stable firmware [here](http://www.electrodragon.com/w/File:At_firmware_bin1.54.zip), flash it to 0x00000 using [this guide](http://cityos.io/tutorial/1935/How-to-put-AT-firmware-in-Esp8266) for example).

For this connection, Blynk uses ESP8266\_Lib.h library, which you get automatically when you [install Blynk libraries](https://github.com/blynkkk/blynk-library/releases/latest).<br>

### Getting Started <a href="#getting-started" id="getting-started"></a>

1. Check that your ESP8266 module is powered correctly and turned on
2. Ensure a stable serial connection to ESP8266
3. Use your USB-UART TTL converter, or [this sketch](https://github.com/blynkkk/blynk-library/tree/master/tests/SerialXconnect/SerialXconnect.ino) to access AT command console
4. Update your ESP to the latest firmware, if needed (AT v1.1.0.0 is recommended)
5. Remember which Software Serial pins (or Hardware Serial#) and baud rate work for your module.
6. Use **Blynk -> Boards\_WiFi ->** [**ESP8266\_Shield**](https://github.com/blynkkk/blynk-library/tree/master/examples/Boards_WiFi/ESP8266_Shield/ESP8266_Shield.ino) example with the same Serial configuration.
7. In Blynk App, select the Board type of your main board, to which ESP8266 is connected (Uno, Mega, etc)

#### Software Serial <a href="#software-serial" id="software-serial"></a>

When using Software Serial - you have to switch ESP8266 to baud rate 9600.\
&#x20;Send this AT command to ESP8266:

```
AT+UART_DEF=9600,8,1,0,0
```

or, for some versions:

```
AT+CIOBAUD=9600
```

It should reply `OK`.

### Troubleshooting <a href="#troubleshooting" id="troubleshooting"></a>

* Failing to read the comments in the sketch and amending it accordingly for the specific hardware.
* Powering ESP8266 from 3v3 pin on `Arduino UNO/Nano/Mega` most likely won't work.
* Use a separate 3.3V source, that can provide up to 1A, like AMS1117.
* Baud rate of ESP8266 should match with Arduino Serial baud rate. Or TX/RX pins could be swapped by mistake.
* **Ensure Arduino can communicate with ESP8266 with AT commands.**
* Using `Software Serial` is less stable than `Hardware Serial`.
* Try using boards with a dedicated hardware Serial pins, like `Leonardo, Mega, Teensy`, etc.
* Trying to run a sketch with Serial Monitor open in shield mode.
* Weak WiFi signal.
* Poor circuit construction.

If you constantly get **"ESP is not responding"** - please be patient and try looking for available solutions on our community forum.

Some useful recommendations about writing Blynk sketches can be found here: [http://community.blynk.cc/t/solved-disconnect-cmd-skipped-etc-issues-my-advice/5362](http://community.blynk.cc/t/solved-disconnect-cmd-skipped-etc-issues-my-advice/5362)

Blynk was tested with following AT firmware versions:

```
AT version:0.22.0.0(Mar 20 2015 10:04:26)
SDK version:1.0.0

AT version:0.23.0.0(Apr 24 2015 21:11:01)
SDK version:1.0.1

AT version:0.25.0.0(Jun 12 2015 20:26:28)
SDK version:1.1.2

AT version:0.40.0.0(Aug  8 2015 14:45:58)
SDK version:1.3.0
Ai-Thinker Technology Co.,Ltd.
Build:1.3.0.2 Sep 11 2015 11:48:04

AT version:0.60.0.0(Feb  2 2016 18:43:31)
SDK version:1.5.2(80914727)

AT version:1.0.0.0(Apr 16 2016 13:02:45)
SDK version:1.5.3(aec24ac9)

AT version:1.1.0.0(May 11 2016 18:09:56)
SDK version:1.5.4(baaeaebb)
```

#### ☝️  While it seems to work with all of these versions, we observed that the AT version 1.1.0.0 works best. <a href="#while-it-seems-to-work-with-all-of-these-versions-we-observed-that-the-at-version-1100-works-best" id="while-it-seems-to-work-with-all-of-these-versions-we-observed-that-the-at-version-1100-works-best"></a>
