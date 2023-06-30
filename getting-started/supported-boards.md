# Supported Hardware

There are different ways to get your devices connected to the Blynk Cloud:

* **Blynk library**\
  An easy to use and portable C++ library, pre-configured to work with **hundreds of development boards**.\
  The library implements a streaming connection protocol (i.e. the device stays always connected to the cloud), that allows for a **low latency, bi-directional** communication. For an easy start use [Quickstart flow](what-do-i-need-to-blynk/) and make sure to explore [Blynk Library documentation](broken-reference) afterwards.
* **Blynk.Edgent**\
  Blynk.Edgent is a packaged solution that allows developers to easily connect their devices to the platform and take advantage of all its advanced features without the need for extensive coding. It includes:
  * Blynk library API
  * **Blynk.Inject** (dynamic device credentials provisioning)
  * **Blynk.Air** (firmware OTA updates)
  *   A simple UX/interaction example:

      * Device state indication using an RGB LED
      * Device configuration reset using a button

      If your hardware supports Blynk.Edgent, **we recommend using** [**this flow**](../blynk.edgent/overview.md) at all times.
* **Blynk.NCP**\
  Blynk offers a software stack for a variety of `Network Co-Processors`. NCP is a dedicated connectivity chip/module that **off-loads the Blynk.Cloud connectivity (WiFi, Ethernet, Cellular)** from the main device MCU. The main MCU runs a lightweight client library that communicates to the NCP over `UART` or `SPI`. It enables blazing fast and high quality integration, and is perfect for retrofitting scenarios. If you're interested in using **Blynk.NCP** for commercial applications, please [contact Blynk](https://blynk.io/contact-us-business).
* **HTTP(s) API**\
  A standard communication protocol that can be used by any Internet-connected device.\
  The device connects to the cloud occasionally to transfer the data.\
  Sending timestamped data in batches is also possible, which is particularly useful for **Cellular devices**. You can find more guidance in [HTTP(s) API documentation](broken-reference).

## Hardware supported by `Blynk.Edgent`

As part of Blynk.Edgent the following features are fully supported:\
**Dynamic Tokens (WiFi provisioning)**. Read more about WiFi provisioning here:

{% content-ref url="activating-devices/blynk-edgent-wifi-provisioning.md" %}
[blynk-edgent-wifi-provisioning.md](activating-devices/blynk-edgent-wifi-provisioning.md)
{% endcontent-ref %}

**Blynk.Air (OTA)**. Read about it here:

{% content-ref url="../blynk.edgent/updating-devices-firmwares-ota.md" %}
[updating-devices-firmwares-ota.md](../blynk.edgent/updating-devices-firmwares-ota.md)
{% endcontent-ref %}

| Board                 | Provisioning | Secure connection | Blynk.Air (OTA) |
| --------------------- | ------------ | ----------------- | --------------- |
| ESP32                 | ✅            | ✅                | ✅               |
| ESP8266               | ✅            | ✅                | ✅               |
| Seeed Wio Terminal    | ✅            | ✅                | ✅               |
| TI CC3220             | ✅            | ✅                | ✅               |


### Dual-MCU Boards supported by `Blynk.NCP`

Board                            | OTA for MCU | OTA for NCP   | Connectivity | Provisioning
:--                              | :---        | :---          | :---         | :---
[UNO R4 WiFi][1]                 | `⏳ RA4M1`  | `✅ ESP32s3`   | WiFi 2.4     | ✅ BLE
[Portenta C33][2]                | `⏳ RA6M5`  | `✅ ESP32c3`   | WiFi 2.4     | ✅ BLE
[Nano RP2040 Connect][3]         | `✅ RP2040` | `❌ NINA_W102` | WiFi 2.4     | ✅ BLE
[Nano 33 IoT][4]                 | `✅ SAMD21` | `❌ NINA_W102` | WiFi 2.4     | ✅ BLE
[MKR WiFi 1010][5]               | `✅ SAMD21` | `❌ NINA_W102` | WiFi 2.4     | ✅ BLE
[T-PicoC3][6]                    | `✅ RP2040` | `✅ ESP32c3`   | WiFi 2.4     | ✅ BLE
[RPi Pico][7] + [ESP8266][8]     | `✅ RP2040` | `✅ ESP8266`   | WiFi 2.4     | ✅ WiFiAP


[1]: https://store-usa.arduino.cc/products/uno-r4-wifi
[2]: https://store-usa.arduino.cc/products/portenta-c33
[3]: https://store-usa.arduino.cc/products/arduino-nano-rp2040-connect
[4]: https://store-usa.arduino.cc/products/arduino-nano-33-iot
[5]: https://store-usa.arduino.cc/products/arduino-mkr-wifi-1010
[6]: https://www.lilygo.cc/products/lilygo%C2%AE-t-picoc3-esp32-c3-rp2040-1-14-inch-lcd-st7789v
[7]: https://www.raspberrypi.com/products/raspberry-pi-pico
[8]: https://www.waveshare.com/pico-esp8266.htm


### Connectivity Modules supported by `Blynk.NCP`

Connectivity module              | Firmware file               | Chipset         | Connectivity | Provisioning | Interaction
:--                              | :---                        | :---            | :---         | :---         | :---
[ESP32-MINI-1][10]               | [link][generic_esp32_4M]    | `ESP32`         | WiFi 2.4     | BLE          |
[ESP32-C3-MINI-1][10]            | [link][generic_esp32c3_4M]  | `ESP32-C3`      | WiFi 2.4     | BLE          |
[ESP32-S3-MINI-1-N8][10]         | [link][generic_esp32s3_8M]  | `ESP32-S3`      | WiFi 2.4     | BLE          |
[ESP-WROOM-32 4MB][10]<br>(no PSRAM)   | [link][generic_esp32_4M] | `ESP32`      | WiFi 2.4     | BLE          |
[U-blox NINA-W106][26]           | [link][generic_esp32_4M]    | `ESP32`         | WiFi 2.4     | BLE          |
[Adafruit AirLift][20]           | [link][generic_esp32_4M]    | `ESP32`         | WiFi 2.4     | BLE          | RGB LED
[Macchina SuperB][21]            | [link][generic_esp32_4M]    | `ESP32`         | WiFi 2.4     | BLE          | Green LED
[TTGO T-Internet-POE][22]        | [link][lilygo_poe]          | `ESP32+LAN8720` | WiFi 2.4, Ethernet POE | BLE    |
[Seeed WT32-ETH01][23]           | [link][wt32_eth01]          | `ESP32+LAN8720` | WiFi 2.4, Ethernet     | BLE    |
[Witty Cloud][24]                | [link][generic_esp8266_4M]  | `ESP8266`       | WiFi 2.4     | WiFiAP       | RGB LED, User Button
[DFRobot WiFi Bee][25]           | [link][generic_esp8266_4M]  | `ESP8266`       | WiFi 2.4     | WiFiAP       | User Button
ESP-07S, ESP-12F                 | [link][generic_esp8266_4M]  | `ESP8266`       | WiFi 2.4     | WiFiAP       |

[10]: https://www.espressif.com/en/products/modules

[20]: https://www.adafruit.com/product/4201
[21]: https://www.macchina.cc/catalog/m2-accessories/superb
[22]: https://www.lilygo.cc/products/t-internet-poe
[23]: https://www.seeedstudio.com/Ethernet-module-based-on-ESP32-series-WT32-ETH01-p-4736.html
[24]: https://protosupplies.com/product/esp8266-witty-cloud-esp-12f-wifi-module/
[25]: https://www.dfrobot.com/product-1279.html
[26]: https://www.u-blox.com/en/product/nina-w10-series-open-cpu

[generic_esp8266_4M]: https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP_generic_esp8266_4M.flash.bin
[generic_esp32_4M]: https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP_generic_esp32_4M.flash.bin
[generic_esp32c3_4M]: https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP_generic_esp32c3_4M.flash.bin
[generic_esp32s3_8M]: https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP_generic_esp32s3_8M.flash.bin
[lilygo_poe]: https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP_lilygo_poe.flash.bin
[wt32_eth01]: https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP_wt32_eth01.flash.bin


### Hardware that works with Blynk library or HTTPs API (using Static Tokens)

{% hint style="info" %}
This is the easiest way to migrate from legacy Blynk projects. Just add `BLYNK_TEMPLATE_ID` and `BLYNK_TEMPLATE_NAME` at the top of your firmware (prior to any includes), update your auth token and that's it. Read more about [project migration](../troubleshooting/blynk-1.0-and-2.0-comparison/migrate-from-1.0-to-2.0.md).
{% endhint %}

Read about static tokens here:

{% content-ref url="activating-devices/blynk-edgent-static-authtoken.md" %}
[blynk-edgent-static-authtoken.md](activating-devices/blynk-edgent-static-authtoken.md)
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
* [Boron](../hardware-guides/particle.md)
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

### Made by Community <a href="#supported-hardware-made-by-community" id="supported-hardware-made-by-community"></a>

* [Node-RED](https://github.com/gablau/node-red-contrib-blynk-iot) (can be used as bridge to HTTP, TCP, UDP, MQTT, XMPP, IRC, OSC…)

### Troubleshooting

Here is a list of [known library issues](https://github.com/blynkkk/blynk-library/issues?q=is%3Aissue+label%3A%22for+reference%22+).

### Need support for any other hardware?

If you are looking for commercial use of Blynk with hardware from Nordic Semiconductor, Silicon Labs, NXP Semiconductors or other manufacturers, [let's talk about integration options](https://blynk.io/contact-us-business).
