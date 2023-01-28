# Supported Boards

## Hardware that **supports Dynamic Tokens (WiFi provisioning)**

Read more about WiFi provisioning here:

{% content-ref url="../getting-started/activating-devices/blynk-edgent-wifi-provisioning.md" %}
[blynk-edgent-wifi-provisioning.md](../getting-started/activating-devices/blynk-edgent-wifi-provisioning.md)
{% endcontent-ref %}



| Board                 | Provisioning | Secure connection | Blynk.Air (OTA) |
| --------------------- | ------------ | ----------------- | --------------- |
| ESP32                 | ✅            | ✅                 | ✅               |
| ESP8266               | ✅            | ✅                 | ✅               |
| Arduino MKR WiFi 1010 | ✅            | ✅                 | ✅               |
| Arduino Nano 33 IoT   | ✅            | ✅                 | ✅               |
| Arduino MKR1000       | ✅            | ✅                 | ✅ (partial)     |
| Seeed Wio Terminal    | ✅            | ✅                 | ✅               |
| TI CC3220             | ✅            | ✅                 | ✅               |



## Hardware that can work with Static Tokens

{% hint style="info" %}
This is the easiest way to migrate from legacy Blynk projects. Just add `BLYNK_TEMPLATE_ID` and `BLYNK_TEMPLATE_NAME` at the top of your firmware (prior to any includes), update your auth token and that's it. Read more about [project migration](../blynk-1.0-and-2.0-comparison/migrate-from-1.0-to-2.0.md).
{% endhint %}

Read about static tokens here:



{% content-ref url="../getting-started/activating-devices/blynk-edgent-static-authtoken.md" %}
[blynk-edgent-static-authtoken.md](../getting-started/activating-devices/blynk-edgent-static-authtoken.md)
{% endcontent-ref %}

**Arduino** ([https://github.com/blynkkk/blynk-library](https://github.com/blynkkk/blynk-library))

* Arduino MKR WiFi 1010
* Arduino MKR GSM 1400
* Arduino MKR NB 1500
* Arduino Uno, Duemilanove
* Arduino Nano, Mini, Pro Mini, Pro Micro, Due, Mega
* Arduino 101 (Intel Curie)
* Arduino MKR1000
* Arduino Zero
* Arduino Yún (onboard WiFi and Ethernet, via Bridge)
* Arduino.org UNO WiFi
* Arduino MKR VIDOR 4000 (use the example for MKR WiFi 1010)
* Arduino UNO WiFi Rev.2 (use the example for MKR WiFi 1010)

**Arduino-like**

* Blynk Board
* ESP8266 (Generic, NodeMCU, Witty Cloud, Huzzah, WeMos D1, Seeed Wio Link, etc.)
* ESP32
* Nordic nRF51/nRF52 - based boards
* Teensy 3.2/3.1
* Blue Pill (STM32F103C)
* Realtek RTL8710 / Ameba via [RTLduino](https://github.com/pvvx/RtlDuino)
* DFRobot Bluno
* RedBear Duo
* RedBearLab Blend Micro
* The AirBoard (BLE-Link, RN-XV)
* Feather M0 WiFi
* Intel Edison
* Intel Galileo
* Fishino Guppy, Uno, Mega
* TinyCircuits TinyDuino (CC3000)
* Microduino/mCookie Core, Core+, CoreUSB
* Wicked WildFire V2, V3, V4
* Digistump Oak
* chipKIT Uno32
* Alorium XLR8 (FPGA)
* LinkIt ONE

**Energia**

* Texas Instruments
  * CC3220SF-LaunchXL
  * CC3200-LaunchXL
  * Tiva C Connected LaunchPad
  * Stellaris LM4F120 LaunchPad
  * MSP430F5529 + CC3100
  * LaunchPad MSP432
* RedBearLab (CC3200, WiFi Mini)

**Particle** [https://github.com/vshymanskyy/blynk-library-spark](https://github.com/vshymanskyy/blynk-library-spark))

* Core
* Photon
* Electron
* RPi
* SparkFun RedBoard

**ARM mbed** ([https://developer.mbed.org/users/vshymanskyy/code/Blynk/](https://developer.mbed.org/users/vshymanskyy/code/Blynk/))

* Seeed Tiny BLE
* RedBearLab BLE Nano
* BBC micro:bit

**JavaScript** (Node.js, Espruino, Browsers) ([https://www.npmjs.com/package/blynk-library](https://www.npmjs.com/package/blynk-library))

* Regular PC with Linux / Windows / OS X
* Raspberry Pi (Banana Pi, Orange Pi, …)
* BeagleBone Black
* Onion Omega
* Onion Omega 2
* Intel Galileo
* Intel Edison
* Intel Joule
* LeMaker Guitar
* LeMaker Banana Pro
* Samsung ARTIK 5
* PandaBoard, CubieBoard, pcDuino, Tessel 2
* VoCore, VoCore2 (OpenWRT + [Espruino package](https://github.com/vshymanskyy/OpenWRT-Espruino-packages))
* Espruino Pico
* …

**Python** ([https://github.com/vshymanskyy/blynk-library-python](https://github.com/vshymanskyy/blynk-library-python))

* MicroPython
* Python 2
* Python 3

**Lua** ([https://github.com/blezek/blynk-esp](https://github.com/blezek/blynk-esp))

* NodeMCU

### Arduino connection types <a href="#supported-hardware-arduino-connection-types" id="supported-hardware-arduino-connection-types"></a>

* USB (Serial), connected to your laptop or desktop
* **Ethernet**
  * Arduino MKR ETH
  * Arduino Ethernet Shield (W5100)
  * Arduino Ethernet Shield 2 (W5500)
  * SeeedStudio Ethernet Shield V2.0 (W5200)
  * ENC28J60-based modules
* **WiFi**
  * ESP8266 as WiFi modem (running original firmware)
  * Arduino WiFi 101 Shield
  * Arduino WiFi Shield
  * WIZnet WizFi310
  * Adafruit CC3000 WiFi Breakout / Shield
  * RN-XV WiFly
* **Cellular (GSM/3G/LTE)**
  * SIMCom SIM800 series (SIM800A, SIM800C, SIM800L, SIM800H, SIM808, SIM868)
  * SIMCom SIM900 series (SIM900A, SIM900D, SIM908, SIM968)
  * A6/A7
  * M590
  * BG96
  * GPRSbee
  * Microduino GSM
  * Adafruit FONA (Mini Cellular GSM Breakout)
  * Adafruit FONA 800/808 Shield

{% hint style="info" %}
Traffic optimization is usually required for cellular connections. Using realtime streaming protocols like Blynk or MQTT has benefits of interactive device updates, but it also requires device to stay "always connected", which significantly increases the traffic. Blynk recommends using [HTTPS (batch) API](../blynk.cloud/https-api-overview.md) for reporting telemetry and fetching `DataStream` values periodically in such scenarios. It will also help saving the battery.
{% endhint %}

### Made by Community <a href="#supported-hardware-made-by-community" id="supported-hardware-made-by-community"></a>

* [Marvell® EZ-Connect™ MW300/MW302](https://github.com/vshymanskyy/blynk-library-ez-connect)
* [WIZnet-W5500-EVB](http://instructables.com/id/WIZnet-W5500-EVB-and-Blynk-App-communication)
* [LabVIEW](https://github.com/juncaofish/NI-LabVIEWInterfaceforBlynk)
* [Node-RED](https://github.com/gablau/node-red-contrib-blynk-iot) (can be used as bridge to HTTP, TCP, UDP, MQTT, XMPP, IRC, OSC…)

### Problematic Boards <a href="#supported-hardware-problematic-boards" id="supported-hardware-problematic-boards"></a>

These boards are not supported and do not work out of the box: - [Arduino Tian](http://www.arduino.org/products/boards/arduino-tian)

Here is a list of [**known library issues**](https://github.com/blynkkk/blynk-library/issues?q=is%3Aissue+label%3A%22for+reference%22+)
