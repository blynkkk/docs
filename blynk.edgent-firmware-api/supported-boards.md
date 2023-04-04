# Blynk.Edgent overview

## What is Blynk.Edgent

Blynk.Edgent is a packaged solution that allows developers to easily connect their devices to the platform and take advantage of all its advanced features without the need for extensive coding. It includes:

* Blynk library API (Secure connection and data exchange)
* **Blynk.Inject** (dynamic device credentials provisioning over WiFi Access Point or BLE,)
* **Blynk.Air** (OTA firmware updates)
* A simple UX/interaction example:
  * Device state indication using an RGB LED
  * Device configuration reset using a button

This level of integration and ease of use can save significant time and effort spent on developing IOT essentials and help focus on the embedded firmware application building your connected product more quickly.

It is supported by devices that are pre-configured to work seamlessly with the Blynk IoT platform.

### Hardware supported by `Blynk.Edgent`

| ESP32     | Arduino MKR WiFi 1010 |
| --------- | --------------------- |
| ESP8266   | Arduino Nano 33 IoT   |
| TI CC3220 | Seeed Wio Terminal    |

### How to connect a device with Blynk.Edgent

1. Create a blank Template in [Blynk.Console](https://blynk.cloud/). To do it, open the _Templates_ section in the left menu and click + _New Template_ button. Assign a name and select hardware and connectivity, you can further customize the template and build the dashboards later.
2. Open [PlatformIO IDE](../blynk-library-firmware-api/installation/install-blynk-library-for-platformio.org.md) (recommended) or [Arduino IDE](../blynk-library-firmware-api/installation/install-blynk-library-in-arduino-ide.md) and install Blynk Library.
3. Open Blynk.Edgent example for your device and your IDE using the links provided in the table below or in your IDE. For Arduino: File -> Examples -> Blynk -> Blynk.Edgent and select your board.\


| Board                 | Example for PlatformIO IDE                                                                  | Example for Arduino IDE                                                                                  |
| --------------------- | ------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------- |
| ESP32                 | [Link](https://github.com/blynkkk/edgent-examples-pio/tree/main/PIO\_Edgent\_ESP32)         | [Link](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent\_ESP32)         |
| ESP8266               | [Link](https://github.com/blynkkk/edgent-examples-pio/tree/main/PIO\_Edgent\_ESP8266)       | [Link](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent\_ESP8266)       |
| Arduino MKR WiFi 1010 | [Link](https://github.com/blynkkk/edgent-examples-pio/tree/main/PIO\_Edgent\_ESP8266)       | [Link](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent\_MKR1010)       |
| Arduino Nano 33 IoT   | [Link](https://github.com/blynkkk/edgent-examples-pio/tree/main/PIO\_Edgent\_ESP8266)       | [Link](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent\_MKR1010)       |
| Seeed Wio Terminal    | [Link](https://github.com/blynkkk/edgent-examples-pio/tree/main/PIO\_Edgent\_Wio\_Terminal) | [Link](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent\_Wio\_Terminal) |
| TI CC3220             | [Contact sales](https://blynk.io/contact-us-business) for commercial implementation         | [Contact sales](https://blynk.io/contact-us-business) for commercial implementation                      |

4. Uncomment these two lines and replace the placeholders with your Template ID and Template name.

```
//#define BLYNK_TEMPLATE_ID           “TMPxxxxxx”
//#define BLYNK_TEMPLATE_NAME         “TemplateName”
```

You can get them in Blynk.Console by going to _Templates_, selecting your newly created template and finding the _FIRMWARE CONFIGURATION_ in the _Info_ tab.

<figure><img src="https://lh4.googleusercontent.com/oi-ZayczWEDkvpRNCfr_YR5CVpoF-6XCI6BhKcjvpioKv81eX2Ey-2tEEBSmeox3KK131pTOUX-lChYpgaMJEH3EItY5ccFrDEPICp1_Uwvc8aolFUc4pcQO4IT8WSjw7o-PNoVIloYW_K7F0zr9DUU" alt=""><figcaption></figcaption></figure>

5. Compile and upload to your device
6. Connect your device in Blynk.App. To do it open the _MENU_ icon in the upper right corner. Tap on + _Add New Device_. Select _Connect to Wi-Fi_ option. The app will scan the WiFi networks around you and offer to connect to your device. You will see the template name you’ve chosen in step 1. Once the connection is established, the Blynk app will guide you through the provisioning process.
7. Bingo! Your device is online and connected to Blynk.Cloud. You can now continue prototyping, adding custom functionality according to your needs, and building your [mobile](../blynk.apps/constructor.md) and [web](../blynk.console/templates/dashboard/) dashboards. Your device is fully set up to get all further firmware updates [over the air](../getting-started/updating-devices-firmwares-ota.md).
