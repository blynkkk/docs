This tutorial will guide you through the process of connecting a Wroom ESP32 to Blynk and sending a random stress level of an astronaut. We will generate a random number to simulate the stress level and send it to the Blynk app.

# Table of Contents

- [Overview](#overview)
- [Toolchain](#toolchain)
- [Components Used in This Project](#components-used-in-this-project)
- [Step-by-Step Guide](#step-by-step-guide)
- [Troubleshooting](#troubleshooting)

# Overview

In this project, we will use the Wroom ESP32 microcontroller to generate random stress levels of an astronaut and send this data to the Blynk app. Blynk is a platform that allows you to create IoT applications with ease. We will connect the Wroom ESP32 to Blynk and visualize the stress levels on the app.

# Toolchain

- Arduino IDE: [Download and install the Arduino IDE](https://www.arduino.cc/en/software)
- Blynk library for Arduino: [Download the Blynk library](https://github.com/blynkkk/blynk-library/releases)
- Blynk app: [Download for Android](https://play.google.com/store/apps/details?id=cc.blynk) or [Download for iOS](https://apps.apple.com/us/app/blynk-iot-for-arduino-esp32/id808760481)

# Components Used in This Project

- Wroom ESP32 development board
- Micro-USB cable
- Smartphone with Blynk app installed

# Step-by-Step Guide

## 1. Setting up the Blynk app

1. Install and open the Blynk app on your smartphone.
2. Create a new account or log in with an existing one.
3. Press the "+" button to create a new project.
4. Name your project (e.g., "Astronaut Stress Monitor") and select the ESP32 Dev Board as the device. Set the connection type to Wi-Fi.
5. You will receive an Auth Token via email. Save this token as it will be used later in the Arduino code.

## 2. Configuring the Arduino IDE

1. Open the Arduino IDE.
2. Go to `File` > `Preferences`.
3. In the "Additional Boards Manager URLs" field, add the following URL: `https://dl.espressif.com/dl/package_esp32_index.json`
4. Click "OK" to save your changes.
5. Go to `Tools` > `Board` > `Boards Manager`.
6. Search for "ESP32" and install the "esp32" package by Espressif Systems.
7. Restart the Arduino IDE.

## 3. Installing the Blynk library

1. Download the Blynk library as a ZIP file from the [GitHub repository](https://github.com/blynkkk/blynk-library/releases).
2. In the Arduino IDE, go to `Sketch` > `Include Library` > `Add .ZIP Library`.
3. Select the downloaded Blynk library ZIP file and click "Open" to install it.

## 4. Uploading the code

1. In the Arduino IDE, go to `File` > `Examples` > `Blynk` > `Boards_WiFi` > `ESP32_WiFi`.
2. Replace the placeholders with your Wi-Fi credentials and Auth Token received via email:

```cpp
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_SERVER "fra.blynk-qa.com"

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <BlynkSimpleEsp32_SSL.h>

BlynkTimer timer;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";
int alertStatus = 0;

void myTimerEvent()
{
  int value = random(0, 100);
  alertStatus = map(value, 0, 100, 0, 2);
  Blynk.virtualWrite(V2, value);

  switch (alertStatus)
  {
  case 0:
    Blynk.setProperty(V0, "url", "https://raw.githubusercontent.com/blynkkk/docs/main/unused/astronaut.json");
    break;

  case 1:
    Blynk.setProperty(V0, "url", "https://raw.githubusercontent.com/blynkkk/docs/main/unused/orangealert.json");
    break;

  case 2:
    Blynk.setProperty(V0, "url", "https://raw.githubusercontent.com/blynkkk/docs/main/unused/redalert.json");
    break;

  default:
    Blynk.setProperty(V0, "url", "https://raw.githubusercontent.com/blynkkk/docs/main/unused/astronaut.json");
    break;
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, BLYNK_SERVER);
  timer.setInterval(10000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
}
```

5. Select your ESP32 board from `Tools` > `Board` and the appropriate COM port from `Tools` > `Port`.
6. Press the "Upload" button to compile and upload the code to your ESP32.

## 5. Configuring the Blynk app

1. Open the Blynk app and go to your "Astronaut Stress Monitor" project.
2. Tap the "+" button and add a "Gauge" widget.
3. Tap the gauge widget to configure it. Set the input pin to `V1`, and adjust the min and max values according to your desired stress level range (e.g., 0 to 100).
4. Press the "Play" button to run your project. You should now see the gauge widget displaying the random stress level of an astronaut.

## Troubleshooting

1. **No data displayed on the Blynk app:** Make sure the ESP32 is connected to the same Wi-Fi network as your smartphone. Double-check the Auth Token in the Arduino code and ensure it matches the one received via email.
2. **Cannot upload the code to the ESP32:** Ensure the correct board and COM port are selected in the Arduino IDE. Check your USB cable and try a different one if necessary.
3. **Random stress level values are not changing:** Verify that the `sendStressLevel()` function is being called regularly by the timer in the `setup()` function.

## Additional Tips and Enhancements

1. **Adding a battery and enclosure:** To make your project portable, consider using a battery to power the ESP32 and housing the components in a 3D-printed or custom enclosure.
2. **Visualizing historical data:** To store and visualize historical stress level data, add the "SuperChart" widget in the Blynk app. Configure it to use the same `V1` virtual pin as the gauge widget.
3. **Notifications:** Use the "Notification" widget in the Blynk app to send alerts when the stress level exceeds a certain threshold.
4. **Multiple astronauts:** If you want to monitor the stress levels of multiple astronauts, you can use additional ESP32 devices with unique Auth Tokens. In the Blynk app, add more gauge widgets and configure them with the corresponding Auth Tokens and virtual pins.

## Conclusion

Congratulations! You have successfully connected a Wroom ESP32 to Blynk and sent the stress level of an astronaut as a random number. By following this tutorial, you have gained experience working with the ESP32, Blynk app, and IoT applications. You can now expand on this project to incorporate real sensors or monitor additional parameters.
