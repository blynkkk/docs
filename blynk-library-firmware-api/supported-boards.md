# Supported Boards

There are different ways to get your devices connected to the Blynk Cloud:

* **Blynk Library**\
  An easy to use and portable C++ library, pre-configured to work with **hundreds of development boards**.\
  The library implements a streaming connection protocol (i.e. the device stays always connected to the cloud), that allows for a **low latency, bi-directional** communication.
* **HTTP(s) API**\
  A standard communication protocol that can be used by any Internet-connected device.\
  The device connects to the cloud occasionally to transfer the data.\
  Sending timestamped data in batches is also possible, which is particularly useful for **Cellular devices**.
* **Blynk.Edgent**\
  A packaged solution that includes:
  * Blynk library API
  * **Blynk.Inject** (dynamic device credentials provisioning)
  * **Blynk.Air** (firmware OTA updates)
  * A simple UX/interaction example:
    * Device state indication using an RGB LED
    * Device configuration reset using a button
* **Blynk.NCP**\
  Blynk offers a software stack for a variety of `Network Co-Processors`. NCP is a dedicated connectivity chip/module that **off-loads the Blynk.Cloud connectivity (WiFi, Ethernet, Cellular)** from the main device MCU. The main MCU runs a lightweight client library and communicates to the NCP over `UART` or `SPI`. It enables blazing fast and high quality integration, and is perfect for retrofitting scenarios. If you're interested in using **Blynk.NCP** for commercial applications, please [contact Blynk](https://blynk.io/en/contact-us-business).

## Hardware supported by `Blynk.Edgent`

As part of Blynk.Edgent the following features are fully supported:\
**Dynamic Tokens (WiFi provisioning)**. Read more about WiFi provisioning here:

{% content-ref url="../getting-started/activating-devices/blynk-edgent-wifi-provisioning.md" %}
[blynk-edgent-wifi-provisioning.md](../getting-started/activating-devices/blynk-edgent-wifi-provisioning.md)
{% endcontent-ref %}

**Blynk.Air (OTA)**. Read about it here:

{% content-ref url="../blynk.edgent/updating-devices-firmwares-ota.md" %}
[updating-devices-firmwares-ota.md](../blynk.edgent/updating-devices-firmwares-ota.md)
{% endcontent-ref %}

| Board                 | Provisioning | Secure connection | Blynk.Air (OTA) |
| --------------------- | ------------ | ----------------- | --------------- |
| ESP32                 | ✅            | ✅                 | ✅               |
| ESP8266               | ✅            | ✅                 | ✅               |
| Arduino MKR WiFi 1010 | ✅            | ✅                 | ✅               |
| Arduino Nano 33 IoT   | ✅            | ✅                 | ✅               |
| Seeed Wio Terminal    | ✅            | ✅                 | ✅               |
| TI CC3220             | ✅            | ✅                 | ✅               |

##

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
* Teensy
* Blue Pill (STM32F103C)
* Realtek RTL8710 / Ameba via [RTLduino](https://github.com/pvvx/RtlDuino)
* Feather M0 WiFi
* TinyCircuits TinyDuino (CC3000)
* Microduino/mCookie Core, Core+, CoreUSB
* Wicked WildFire V2, V3, V4
* chipKIT Uno32
* Alorium XLR8 (FPGA)
* LinkIt ONE

**Particle** [https://github.com/vshymanskyy/blynk-library-spark](https://github.com/vshymanskyy/blynk-library-spark))

* Core
* Photon
* Electron
* Argon
* Boron
* Photon 2

**JavaScript** (Node.js, Espruino, Browsers) ([https://www.npmjs.com/package/blynk-library](https://www.npmjs.com/package/blynk-library))

* Regular PC with Linux / Windows / OS X
* Raspberry Pi (Banana Pi, Orange Pi, …)
* BeagleBone Black
* Onion Omega 2
* VoCore, VoCore2 (OpenWRT + [Espruino package](https://github.com/vshymanskyy/OpenWRT-Espruino-packages))
* Espruino Pico
* …

**Python** ([https://github.com/vshymanskyy/blynk-library-python](https://github.com/vshymanskyy/blynk-library-python))

* Regular PC with Linux / Windows / OS X
* Raspberry Pi (Banana Pi, Orange Pi, …)
* BeagleBone Black
* Onion Omega 2
* MicroPython
* …

### Arduino connection types <a href="#supported-hardware-arduino-connection-types" id="supported-hardware-arduino-connection-types"></a>

* USB (Serial), connected to your laptop or desktop
* **Ethernet**
  * Arduino MKR ETH
  * Arduino Ethernet Shield (W5100)
  * Arduino Ethernet Shield 2 (W5500)
  * ENC28J60-based modules
* **WiFi**
  * ESP8266 as WiFi modem (running original AT firmware)
  * Arduino WiFi 101 Shield
  * Arduino WiFi Shield
  * WIZnet WizFi310
* **Cellular (GSM/3G/LTE)**
  * SIMCom SIM800 series (SIM800A, SIM800C, SIM800L, SIM800H, SIM808, SIM868)
  * SIMCom SIM7600 series
  * BG96
  * GPRSbee
  * Adafruit FONA (Mini Cellular GSM Breakout)

{% hint style="info" %}
Traffic optimization is usually required for cellular connections. Using realtime streaming protocols like Blynk or MQTT has benefits of interactive device updates, but it also requires device to stay "always connected", which significantly increases the traffic. Blynk recommends using [HTTPS (batch) API](../blynk.cloud/https-api-overview.md) for reporting telemetry and fetching `DataStream` values periodically in such scenarios. It will also help saving the battery.
{% endhint %}

### &#x20;<a href="#supported-hardware-made-by-community" id="supported-hardware-made-by-community"></a>

### Made by Community <a href="#supported-hardware-made-by-community" id="supported-hardware-made-by-community"></a>

* [Node-RED](https://github.com/gablau/node-red-contrib-blynk-iot) (can be used as bridge to HTTP, TCP, UDP, MQTT, XMPP, IRC, OSC…)

###

### Troubleshooting

Here is a list of [**known library issues**](https://github.com/blynkkk/blynk-library/issues?q=is%3Aissue+label%3A%22for+reference%22+)
