# Overview
In this tutorial, we will guide you on how to connect the Seeed Wio Terminal to the Blynk platform and send temperature and humidity data collected from a DHT11 sensor. The Blynk platform allows you to create amazing IoT projects with just a few lines of code, and the Wio Terminal is an all-in-one microcontroller that features multiple connectivity options and a 2.4" LCD screen.

# Toolchain
- Blynk App (Android/iOS)
- Arduino IDE
- Blynk Library
- Seeed Wio Terminal
- DHT11 Sensor
- Jumper wires

# Components Used in This Project
1. Seeed Wio Terminal: A versatile microcontroller with a 2.4" LCD screen, integrated Wi-Fi, Bluetooth, and Grove connectors.
2. DHT11 Sensor: A low-cost digital temperature and humidity sensor.
3. Jumper Wires: To connect the DHT11 sensor to the Wio Terminal.

# Step-by-Step Guide

## 1. Install and Set Up the Blynk App
  a. Download and install the Blynk app on your smartphone (available for both Android and iOS).
  b. Create an account and sign in.
  c. Create a new project, select "Wio Terminal" as your device, and choose the connection type (Wi-Fi).
  d. Add two Value Display widgets to display temperature and humidity, and configure them to use virtual pins V5 and V6, respectively.
  e. Note down the Auth Token sent to your registered email.

## 2. Install Arduino IDE and Libraries
  a. Download and install the Arduino IDE from the official website (https://www.arduino.cc/en/software).
  b. Install the "Seeed SAMD Boards" package through the Boards Manager.
  c. Install the "Blynk" and "DHT sensor library by Adafruit" libraries through the Library Manager.

## 3. Wiring
  a. Connect the DHT11 sensor to the Wio Terminal using jumper wires:
     - DHT11 VCC to Wio Terminal 3.3V
     - DHT11 GND to Wio Terminal GND
     - DHT11 Data to Wio Terminal D2

## 4. Upload the Code
  a. Open Arduino IDE and create a new sketch.
  b. Replace the default code with the following:

```cpp
/* Fill in information from Blynk Device Info here */
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"
//#define BLYNK_AUTH_TOKEN            "YourAuthToken"

#include <rpcWiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleWioTerminal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensorData() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();

  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
```

# Troubleshooting

If you encounter any issues during this project, refer to the following troubleshooting tips:

1. **Wio Terminal not connecting to Wi-Fi or Blynk**: Ensure that the Auth Token, Wi-Fi SSID, and Wi-Fi password are entered correctly in the code.

2. **Temperature and humidity values not displayed or incorrect**: Check the wiring between the DHT11 sensor and the Wio Terminal. Make sure the connections are secure and that the correct pins are used.

3. **Blynk app not showing correct values or project is offline**: Ensure that the virtual pins in the app match the ones in the code (V5 for temperature and V6 for humidity). If the issue persists, check your internet connection and make sure the Wio Terminal is connected to Wi-Fi.

4. **Code compilation or upload errors**: Verify that the correct board ("Seeed Wio Terminal") and port are selected in the Arduino IDE. Also, make sure that the required libraries ("Blynk" and "DHT sensor library by Adafruit") are installed.

5. **Sensor readings appear unstable or fluctuating**: The DHT11 sensor may require some time to stabilize after powering on. If the readings continue to fluctuate, consider adding a delay in the code or using a moving average to smooth out the data.

By addressing these common issues, you should be able to resolve most problems encountered during the project. If you still face difficulties, consider referring to the official documentation for the Seeed Wio Terminal, Blynk platform, and DHT11 sensor for further assistance.
