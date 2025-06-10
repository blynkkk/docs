# Blynk.NCP overview

### What is Blynk.NCP

Blynk.NCP is a software solution that off-loads connectivity to a **Network Co-Processor (NCP)**, while your application logic resides on the **Primary MCU**. This implies a [dual-Microcontroller Unit (MCU)](https://docs.google.com/presentation/d/1aP2sQWB0J9EWj8Y1h5qeyfm2aFwaNSUKnCE-k7zxVnk/present) architecture.

### When to use Blynk.NCP

Using Blynk.NCP is recommended if one of these is true:

* You're building a new IoT product with specific requirements for the Primary MCU, so you're adding a separate connectivity module
* You are using Blynk for retrofitting your existing products
* You have included an AT command-based module, but you struggle to make it work right or to achieve your product goals
* You have one of the [supported dual-MCU](overview.md#connect-a-supported-dual-mcu-board-using-blynk.ncp) boards and want connect it to Blynk

### Why use Blynk.NCP

Blynk.NCP allows to immediately have access to Blynk’s advanced features - such as device provisioning, OTA firmware updates and others - using the hardware of your choice, which reduces integration efforts, time to market, and improves reliability of your products.

#### Features available with Blynk.NCP:

* **Blynk.Inject**: connect your devices easily using Android App, iOS App or Web Dashboard
  * `BLE`-assisted device provisioning for the best end-user experience
  * `WiFiAP`-based provisioning for devices without BLE support
* **Network Manager**:&#x20;
  * WiFi (up to 16 saved networks), Ethernet, Cellular (depending on the hardware)
  * Advanced network connection troubleshooting
* Secure **Blynk.Cloud** connection that provides simple API for:
  * Data transfer with Virtual Pins, reporting Events, and accessing Metadata
  * `Time`, `Timezone` and `Location`, with an ability to track local time when the device is offline, including DST transitions
* **Blynk.Air** - Automatic Over The Air firmware updates using Web Dashboard
  * Both NCP and the Primary MCU firmware updates
  * Direct firmware upgrade using iOS/Android App, before device activation

#### Additional services that can be provided by the Blynk.NCP:

* NCP-assisted [**fail-safe OTA updates**](updating-devices-firmwares-ota.md#ncp-assisted-fail-safe-ota-updates)
* Connectivity-related **device state indication** - requires a monochrome/RGB/addressable LED attached to the NCP
* **User button** (also used for configuration reset) - requires a momentary push button attached to the NCP
* **Factory testing** and provisioning

Blynk team is now working on a range of complementary features that will be available with Blynk.NCP, persistent automation scenarios, non-volatile storage for [Preferences](https://github.com/vshymanskyy/Preferences) library, and generic UDP/TCP/TLS socket API being among them.

### How to connect any board to Blynk with Blynk.NCP

To enable a seamless connection and advanced Blynk’s functionality, add one of the [supported connectivity modules](supported-connectivity-modules.md) to your hardware as a Network Co-Processor. We’ve prepared an [example](https://github.com/blynkkk/BlynkNcpExample/blob/main/docs/BuildYourOwn.md) that includes firmware and will help you set up the communication between your hardware and Blynk with minimal effort.

#### Connect a supported dual-MCU board using Blynk.NCP

If you are using one of the following dual-MCU boards: UNO R4 WiFi, Portenta C33, Nano RP2040 Connect, Nano 33 IoT, MKR WiFi 1010, T-PicoC3, or RPi Pico + ESP8266, you can use this [Blynk.NCP example for Arduino](https://github.com/Blynk-Technologies/Blynk-NCP-Example-Arduino) to set up communication with the platform within minutes.  
We also offer a [Zephyr example](https://github.com/Blynk-Technologies/Blynk-NCP-Example-Zephyr) for multiple boards and use cases.


#### If you're interested in using **Blynk.NCP** for commercial applications, please [contact Blynk](https://blynk.io/contact-us-business).
