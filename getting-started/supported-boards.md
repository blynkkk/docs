---
description: List of hardware and development boards that work with Blynk.
---

# Supported Hardware

## There are four ways to get your devices connected to the Blynk Cloud:

<table data-card-size="large" data-column-title-hidden data-view="cards"><thead><tr><th></th><th></th><th></th><th data-hidden data-card-target data-type="content-ref"></th></tr></thead><tbody><tr><td><p><strong>Blynk Library</strong></p><p><br>An easy to use and portable C++ library, pre-configured to work with <strong>hundreds of development boards</strong>.<br></p><p>The library implements a streaming connection protocol (i.e. the device stays always connected to the cloud), that allows for a <strong>low latency, bi-directional</strong> communication. </p><p></p><p>Try <a href="what-do-i-need-to-blynk/">Quickstart flow</a> and make sure to explore <a href="../blynk-library-firmware-api/configuration.md">Blynk Library documentation</a> afterwards.</p></td><td></td><td></td><td><a href="../blynk-library-firmware-api/configuration.md">configuration.md</a></td></tr><tr><td><p><strong>Blynk.Edgent</strong></p><p><br>Blynk.Edgent is a packaged solution that allows you to easily connect devices to Blynk and take advantage of all its advanced features, including:</p><ul><li>Blynk.Library API</li><li><strong>Blynk.Inject</strong> (dynamic device credentials provisioning)</li><li><strong>Blynk.Air</strong> (firmware OTA updates)</li></ul><p>If your hardware supports Blynk.Edgent, <strong>we recommend using</strong> <a href="../blynk.edgent/overview.md"><strong>this flow</strong></a> at all times.</p></td><td></td><td></td><td><a href="../blynk.edgent/overview.md">overview.md</a></td></tr><tr><td><p><strong>Blynk.NCP</strong><br></p><p>Blynk provides a versatile software stack for Network Co-Processors (NCPs), which are dedicated connectivity chips or modules. </p><p></p><p>NCP handles Blynk.Cloud connectivity (WiFi, Ethernet, Cellular), offloading this task from the main device's MCU. The main MCU operates with a lightweight client library, communicating with the NCP via UART or SPI. This setup offers rapid and high-quality integration, making it ideal for retrofitting scenarios.</p><p></p><p>To get started, check our <a href="../blynk.ncp/overview.md">firmware examples</a> to connect a dual-MCU board or design your own device by incorporating an NCP module.</p></td><td></td><td></td><td><a href="../blynk.ncp/overview.md">overview.md</a></td></tr><tr><td><p><strong>HTTP(s) API</strong></p><p><br>This is a standard communication protocol suitable for any internet-connected device. </p><p></p><p>It allows the device to connect to the cloud periodically to transfer data. Additionally, it supports sending timestamped data in batches, a feature especially beneficial for cellular devices.</p><p></p><p>You can find more guidance in <a href="../blynk.cloud/device-https-api/">HTTP(s) API documentation</a>.</p></td><td></td><td></td><td><a href="../blynk.cloud/device-https-api/">device-https-api</a></td></tr></tbody></table>

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

| Board              | Provisioning | Secure connection | Blynk.Air (OTA) |
| ------------------ | ------------ | ----------------- | --------------- |
| ESP32              | ✅            | ✅                 | ✅               |
| ESP8266            | ✅            | ✅                 | ✅               |
| Seeed Wio Terminal | ✅            | ✅                 | ✅               |
| TI CC3220          | ✅            | ✅                 | ✅               |

### Dual-MCU Boards supported by `Blynk.NCP`

| Board                                                                                                                      | OTA for MCU | OTA for NCP   | Connectivity | Provisioning | NCP File System |
| -------------------------------------------------------------------------------------------------------------------------- | ----------- | ------------- | ------------ | ------------ | --------------- |
| [UNO R4 WiFi](https://store-usa.arduino.cc/products/uno-r4-wifi)                                                           | `⏳ RA4M1`   | `✅ ESP32s3`   | WiFi 2.4     | ✅ BLE        | 4.25 MB         |
| [Portenta C33](https://store-usa.arduino.cc/products/portenta-c33)                                                         | `⏳ RA6M5`   | `✅ ESP32c3`   | WiFi 2.4     | ✅ BLE        | 512 KB          |
| [Nano RP2040 Connect](https://store-usa.arduino.cc/products/arduino-nano-rp2040-connect)                                   | `✅ RP2040`  | `❌ NINA_W102` | WiFi 2.4     | ✅ BLE        | 384 KB          |
| [Nano 33 IoT](https://store-usa.arduino.cc/products/arduino-nano-33-iot)                                                   | `✅ SAMD21`  | `❌ NINA_W102` | WiFi 2.4     | ✅ BLE        | 384 KB          |
| [MKR WiFi 1010](https://store-usa.arduino.cc/products/arduino-mkr-wifi-1010)                                               | `✅ SAMD21`  | `❌ NINA_W102` | WiFi 2.4     | ✅ BLE        | 384 KB          |
| [T-PicoC3](https://www.lilygo.cc/products/lilygo%C2%AE-t-picoc3-esp32-c3-rp2040-1-14-inch-lcd-st7789v)                     | `✅ RP2040`  | `✅ ESP32c3`   | WiFi 2.4     | ✅ BLE        | 512 KB          |
| [RPi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico) + [ESP8266](https://www.waveshare.com/pico-esp8266.htm) | `✅ RP2040`  | `✅ ESP8266`   | WiFi 2.4     | ✅ WiFiAP     | 1000 KB         |

### Connectivity Modules supported by `Blynk.NCP`

| Connectivity module                                                                                          | Firmware file                                                                                                       | Chipset         | Connectivity           | Provisioning | Interaction          |
| ------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------- | --------------- | ---------------------- | ------------ | -------------------- |
| [ESP32-MINI-1](https://www.espressif.com/en/products/modules)                                                | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp32\_4M.flash.bin)   | `ESP32`         | WiFi 2.4               | BLE          |                      |
| [ESP32-C3-MINI-1](https://www.espressif.com/en/products/modules)                                             | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp32c3\_4M.flash.bin) | `ESP32-C3`      | WiFi 2.4               | BLE          |                      |
| [ESP32-S3-MINI-1-N8](https://www.espressif.com/en/products/modules)                                          | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp32s3\_8M.flash.bin) | `ESP32-S3`      | WiFi 2.4               | BLE          |                      |
| <p><a href="https://www.espressif.com/en/products/modules">ESP-WROOM-32 4MB</a><br>(no PSRAM)</p>            | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp32\_4M.flash.bin)   | `ESP32`         | WiFi 2.4               | BLE          |                      |
| [U-blox NINA-W106](https://www.u-blox.com/en/product/nina-w10-series-open-cpu)                               | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp32\_4M.flash.bin)   | `ESP32`         | WiFi 2.4               | BLE          |                      |
| [U-blox NORA-W106](https://www.u-blox.com/en/product/nora-w10-series)                                        | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp32s3\_8M.flash.bin) | `ESP32-S3`      | WiFi 2.4               | BLE          |                      |
| [Adafruit AirLift](https://www.adafruit.com/product/4201)                                                    | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp32\_4M.flash.bin)   | `ESP32`         | WiFi 2.4               | BLE          | RGB LED              |
| [Macchina SuperB](https://www.macchina.cc/catalog/m2-accessories/superb)                                     | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp32\_4M.flash.bin)   | `ESP32`         | WiFi 2.4               | BLE          | Green LED            |
| [TTGO T-Internet-POE](https://www.lilygo.cc/products/t-internet-poe)                                         | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_lilygo\_poe.flash.bin)          | `ESP32+LAN8720` | WiFi 2.4, Ethernet POE | BLE          |                      |
| [Seeed WT32-ETH01](https://www.seeedstudio.com/Ethernet-module-based-on-ESP32-series-WT32-ETH01-p-4736.html) | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_wt32\_eth01.flash.bin)          | `ESP32+LAN8720` | WiFi 2.4, Ethernet     | BLE          |                      |
| [Witty Cloud](https://protosupplies.com/product/esp8266-witty-cloud-esp-12f-wifi-module/)                    | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp8266\_4M.flash.bin) | `ESP8266`       | WiFi 2.4               | WiFiAP       | RGB LED, User Button |
| [DFRobot WiFi Bee](https://www.dfrobot.com/product-1279.html)                                                | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp8266\_4M.flash.bin) | `ESP8266`       | WiFi 2.4               | WiFiAP       | User Button          |
| ESP-07S, ESP-12F                                                                                             | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp8266\_4M.flash.bin) | `ESP8266`       | WiFi 2.4               | WiFiAP       |                      |
| ESP-01, ESP-01S                                                                                              | [link](https://github.com/blynkkk/BlynkNcpDriver/releases/latest/download/BlynkNCP\_generic\_esp8266\_1M.flash.bin) | `ESP8266`       | WiFi 2.4               | WiFiAP       |                      |

### Hardware that works with Blynk library or HTTPs API (using Static Tokens)

{% hint style="info" %}
This is the easiest way to migrate from legacy Blynk projects. Just add `BLYNK_TEMPLATE_ID` and `BLYNK_TEMPLATE_NAME` at the top of your firmware (prior to any includes), update your auth token and that's it. Read more about [project migration](../troubleshooting/blynk-1.0-and-2.0-comparison/migrate-from-1.0-to-2.0.md).
{% endhint %}

Read about static tokens here:

{% content-ref url="activating-devices/blynk-edgent-static-authtoken.md" %}
[blynk-edgent-static-authtoken.md](activating-devices/blynk-edgent-static-authtoken.md)
{% endcontent-ref %}

{% hint style="info" %}
If your board is not listed below, you may still be able to use it with Blynk library. Check out [the generic Arduino Client examples](https://github.com/blynkkk/blynk-library/tree/master/examples/Boards\_ArduinoClient).
{% endhint %}

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
Traffic optimization is usually required for cellular connections. Using realtime streaming protocols like Blynk or MQTT has benefits of interactive device updates, but it also requires device to stay "always connected", which significantly increases the traffic. Blynk recommends using [HTTPS (batch) API](../blynk.cloud/device-https-api/upload-set-of-data-with-timestamps-api.md) for reporting telemetry and fetching `DataStream` values periodically in such scenarios. It will also help saving the battery.
{% endhint %}

### Made by Community <a href="#supported-hardware-made-by-community" id="supported-hardware-made-by-community"></a>

* [Node-RED](https://github.com/gablau/node-red-contrib-blynk-iot) (can be used as bridge to HTTP, TCP, UDP, MQTT, XMPP, IRC, OSC…)

### Troubleshooting

Here is a list of [known library issues](https://github.com/blynkkk/blynk-library/issues?q=is%3Aissue+label%3A%22for+reference%22+).

### Need support for any other hardware?

If you are looking for commercial use of Blynk with hardware from Nordic Semiconductor, Silicon Labs, NXP Semiconductors or other manufacturers, [let's talk about integration options](https://blynk.io/contact-us-business).
