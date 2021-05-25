---
description: Sending WiFi credentials and and Auth Token to your device
---

# WiFi provisioning

Remember going to the coffee shop and asking for a name and password for their WiFi network to connect your smartphone or laptop to? A familiar situation, right?

Now imagine your ESP32 wants to connect to the Internet. It would also need the name and password of your home or office WiFi. Good for you, Blynk can do all the heavy work.

A complete WiFi provisioning solution from Blynk includes both a firmware code and a mobile app UI to guide you through the WiFi set up.

{% hint style="info" %}
Currently, WiFi provisioning only works on ESP32 and ESP8266
{% endhint %}

## **How WiFI provisioning works**

You can skip this part as this is something you don't have to think about because Blynk does everything for you. But it might be helpful to understand how it works under the hood

1. In the beginning, your hardware will act as an Access Point \(AP\). It means that your device will broadcast its own WiFi network with an SSID \(name\) similar to `Blynk-something-1234`;
2. Your smartphone will connect to this AP with the Blynk app \(or from smartphone settings\) and they will start communicating directly with each other;
3. When the connection with the device is established, Blynk app will ask you for the name \(SSID\) and password of the WiFi network you would like to connect this device to;
4. This WiFi information \(SSID and password\) will be sent to the device;
5. Also, Blynk app will request an Auth Token from the server and then send it to the device;
6. Your device will store all of this items in EEPROM;
7. After that, device will automatically reboot. The AP mode will be turned off;
8. Device will use the WiFi credentials you provided to connect to your home or office WiFi network;
9. When connected to WiFI, your device will connect to the Blynk Cloud using the Auth Token from step 5; 
10. After the successful authentication, the device is added to your account and ready to use;
11. If you later need to connect to this device to a different network, WiFi credentials can be changed by using Blynk app or by resetting the device with a physical button \(you would need to plan it into your electrical circuit design\).

Now let's make it work for your devices.

## Setting up your sketch to enable WiFi Provisioning

1. Download [the latest release of Blynk.Edgent](https://github.com/blynkkk/blynk-library/releases/tag/v1.0.0-beta.3) as a **Source code .zip** file
2. Open [Arduino IDE](https://www.arduino.cc/en/guide/windows)
3. In Arduino IDE menu go to Sketch - &gt; Include Library 
4. Select Add .ZIP library

![](https://lh3.googleusercontent.com/i3hKUqAHHOLARrcHd0QaKKhVXjs2BAzFFgonSnaA2JyLWwO5aj7yM8Z0K7QwTpW_sU17pJTyBAx0hLjHPOGceIjdCJhUjYdjukK0sjQTE0EX_xBV3UPpjzWHVvPqhkB2neYdVhkm)

1. Select the downloaded .zip archive. Press Choose to continue.  
2. After that, you should see Blynk folder under the **File &gt; Examples**  

   ![](https://lh3.googleusercontent.com/WfHrWEDwJZ-mzHNcy1UVE1nwHDCAODrMkVehACEgsZYc4pS54L4o99Qel706TSEYPqUqNayc8Ur8pM6DCECYFH1hivgwC2O-KHSZgANz4yTkVV99JR-N4-8B2NDCoZXm3GlXm7eD)  

3. Select **Blynk.Edgent &gt; Edgent\_ESP32**

The sketch will look like this:

```cpp
#define BLYNK_TEMPLATE_ID             ""
#define BLYNK_DEVICE_NAME             ""

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD

#include "BlynkEdgent.h"

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
```

{% hint style="warning" %}
In the sketch variables `BLYNK_TEMPLATE_ID` and `BLYNK_DEVICE_NAME` are empty. They should be replaced with the ones from your template. Read below on where to find them.
{% endhint %}

1. Log in to your [Blynk.360](https://blynk.cloud/) developer account  
2. Go to Templates -&gt; [Create New Template](../working-with-templates/#create-a-template) or open existing template  
3. Copy the Firmare Configuration code lines   

   ![](https://lh6.googleusercontent.com/x2ZHNOv1TA7jPkQtujqBWmn3_mtQr5yxkgZ-0JZF7T7pIndKZHTu0glkkblS3sEd4XV1KAo0ZaljY3dm73AA8aKghwdALd7rKiELWm3v0xjoCJ1Li6wjzsoOP_oCjMBysQ31QBNp)  

4. Go back to your sketch and replace the configuration lines with what you copied.

![](../../.gitbook/assets/apr-07-2021-14-06-30.gif)

1. Press **Upload** button to flash the code to your device. 

If the upload process wend successfully you should see output in the serial monitor.

![](https://lh6.googleusercontent.com/ke-UDlKRqfsgiak0aMEEHVbEU-cAmShbXLAMOS1LEd4_Kd1tktKFw2SajHnWul_b9jT3si85XchMheZlMWy931lPBKUvgw_daFkiYuUVBfVQM9VKePbryxwbD9hvnH4t5lZ2AzFo)

Now your device is ready to be activated using Blynk app.

## Activating device using Blynk app

1. Open Blynk App 
2. Tap Add New Device
3. App will scan the WiFi networks around you and offer to connect to your device. In our example, device name will be:  **Blynk Root Template-FAD8F**
4. Once the connection is established, the Blynk app will guide you through the provisioning process.

A SEQUENCE OF SCREENSHOTS \(OR GIF animation\)

_WiFI credentials -&gt; Waiting -&gt; all Checkmarks checked_

When the process if over, you will be prompted to name the device. At this stage, the device is ready to use.

![Device connected](https://user-images.githubusercontent.com/72790181/119508402-66999b00-bd78-11eb-9343-74a25c9eefbb.png)


For debugging and troubleshooting check the serial monitor output. There you will see how provisioning process is happening on the device.

![](https://lh4.googleusercontent.com/P1WcVsuVbygCW8kSggfYwOKf55a1vVDk4KcCYevGbFPhFXGRI7r5s7_B7z2qKCzfLZudWU0nj6NKPkLMBO1Zodc7X8a54z3M51VLHo65pEfFlP93mCKxgJjaa5maOAKWg6HPZ7zv)

