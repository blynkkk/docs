# Blynk.Edgent overview

## What is Blynk.Edgent

Blynk.Edgent is a packaged solution that allows developers to easily connect their devices to the platform and take advantage of all its advanced features without the need for extensive coding. It includes:

* Blynk library API (Secure connection and data exchange)
* **Blynk.Inject** (dynamic device credentials provisioning over WiFi Access Point or BLE,)
* **Blynk.Air** (OTA firmware updates)
* A simple UX/interaction example:
  * Device state indication using an RGB LED
  * Device configuration reset using a button

This level of integration and ease of use can save significant time and effort spent on developing IOT essentials and help focus on the embedded firmware application building your connected product more quickly.&#x20;

Although Blynk Library can be used without Blynk.Edgent features, it is recommended to use Blynk.Edgent whenever possible.

### Hardware supported by `Blynk.Edgent`

| ESP32              |
| ------------------ |
| ESP8266            |
| Seeed Wio Terminal |
| TI CC3220          |

### Dual-MCU Boards supported by `Blynk.Edgent` through [`Blynk.NCP`](../blynk.ncp/overview.md)

| Board                       | OTA for MCU | OTA for NCP   | Connectivity | Provisioning | NCP File System |
| --------------------------- | ----------- | ------------- | ------------ | ------------ | --------------- |
| Arduino UNO R4 WiFi         | `⏳ RA4M1`   | `✅ ESP32s3`   | WiFi 2.4     | ✅ BLE        | 4.25 MB         |
| Arduino Portenta C33        | `⏳ RA6M5`   | `✅ ESP32c3`   | WiFi 2.4     | ✅ BLE        | 512 KB          |
| Arduino Nano RP2040 Connect | `✅ RP2040`  | `❌ NINA_W102` | WiFi 2.4     | ✅ BLE        | 384 KB          |
| Arduino Nano 33 IoT         | `✅ SAMD21`  | `❌ NINA_W102` | WiFi 2.4     | ✅ BLE        | 384 KB          |
| Arduino MKR WiFi 1010       | `✅ SAMD21`  | `❌ NINA_W102` | WiFi 2.4     | ✅ BLE        | 384 KB          |
| LILYGO T-PicoC3             | `✅ RP2040`  | `✅ ESP32c3`   | WiFi 2.4     | ✅ BLE        | 512 KB          |
| Raspberry Pi Pico + ESP8266 | `✅ RP2040`  | `✅ ESP8266`   | WiFi 2.4     | ✅ WiFiAP     | 1000 KB         |

### How to connect a device with Blynk.Edgent

1. **Create a blank Template** in [Blynk.Console](https://blynk.cloud/). To do it, go to _Developer Zone_ in the left menu and click + _New Template_ button. Assign a name and select hardware and connectivity, you can further customize the template and build the dashboards later.
2. Open [PlatformIO IDE](../blynk-library-firmware-api/installation/install-blynk-library-for-platformio.org.md) (recommended) or [Arduino IDE](../blynk-library-firmware-api/installation/install-blynk-library-in-arduino-ide.md) and **install** [**Blynk Library**](https://github.com/blynkkk/blynk-library/releases/latest).
3. **Open Blynk.Edgent example** for your device and your IDE using the links provided in the table below or in your IDE. For Arduino: File -> Examples -> Blynk -> Blynk.Edgent and select your board.<br>

| Board                 | Example for PlatformIO IDE                                                               | Example for Arduino IDE                                                                                |
| --------------------- | ---------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------ |
| ESP32                 | [Link](https://github.com/blynkkk/edgent-examples-pio/tree/main/PIO_Edgent_ESP32)        | [Link](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent_ESP32)        |
| ESP8266               | [Link](https://github.com/blynkkk/edgent-examples-pio/tree/main/PIO_Edgent_ESP8266)      | [Link](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent_ESP8266)      |
| Arduino MKR WiFi 1010 | [Link](https://github.com/blynkkk/edgent-examples-pio/tree/main/PIO_Edgent_MKR1010)      | [Link](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent_MKR1010)      |
| Arduino Nano 33 IoT   | [Link](https://github.com/blynkkk/edgent-examples-pio/tree/main/PIO_Edgent_MKR1010)      | [Link](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent_MKR1010)      |
| Seeed Wio Terminal    | [Link](https://github.com/blynkkk/edgent-examples-pio/tree/main/PIO_Edgent_Wio_Terminal) | [Link](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent_Wio_Terminal) |
| TI CC3220             | [Contact sales](https://blynk.io/contact-us-business) for commercial implementation      | [Contact sales](https://blynk.io/contact-us-business) for commercial implementation                    |

4. **Uncomment these two lines and replace the placeholders** with your Template ID and Template name.

```
//#define BLYNK_TEMPLATE_ID           “TMPxxxxxx”
//#define BLYNK_TEMPLATE_NAME         “TemplateName”
```

You can get them in Blynk.Console by going to _Developer Zone_ -> _Templates_, selecting your newly created template and finding the _Firmware configuration_ in the _Home_ tab.

<figure><img src="../.gitbook/assets/27-edgent-overview-templ id 1.png" alt=""><figcaption></figcaption></figure>

5. **Compile and upload to your device**
6. **Connect your device in Blynk.App**. To do it open the _MENU_ icon in the upper right corner. Tap on + _Add New Device_. Select _Find Devices Nearby_ option. The app will scan the WiFi networks around you and offer to connect to your device. You will see the template name you’ve chosen in step 1. Once the connection is established, the Blynk app will guide you through the provisioning process.

Bingo! Your device is online and connected to Blynk.Cloud. You can now continue prototyping, adding custom functionality according to your needs, and building your [mobile](../blynk.apps/constructor.md) and [web](../blynk.console/templates/dashboard/) dashboards. Your device is fully set up to get all further firmware updates [over the air](updating-devices-firmwares-ota.md).
