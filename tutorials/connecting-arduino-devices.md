---
description: needs updates
---

# Getting Started: Connecting Arduino Devices

### Getting Started With Hardware <a id="getting-started-getting-started-with-hardware"></a>

#### Static Provision

Install the 1.0.0 beta3 library and use the ESP32 WiFi example.

In Blynk.360, add a template that's based on an ESP32 board, then create a device based on that template.  
The Template screen will give you two lines of firmware configuration, copy these and add them at the very beginning of your sketch.  
In the [Device &gt; Device Info ](../web-dashboard/for-developers/search/devices-1/device-view/device-info.md)screen you'll find the Auth Token \(left hand column, half way down\) click on the green square to the right to copy this to the clipboard...  
[![image](https://user-images.githubusercontent.com/35718564/112981316-e62d3400-9152-11eb-86b2-8a85806dd860.png)](https://user-images.githubusercontent.com/35718564/112981316-e62d3400-9152-11eb-86b2-8a85806dd860.png)

and paste it into your sketch.

### How To Use an Example Sketch

You should by now have the Blynk 2 Library installed on your computer. If not - [click here](https://docs.blynk.cc/#downloads-blynk-library).  
Example sketches will help you get your hardware online quickly and major Blynk features.  
Open the example sketch according to the hardware model or shield you are using.

![](https://docs.blynk.cc/images/connection_type_sketch.png)

Let’s take a look at the example sketch for an [Arduino UNO + Ethernet shield](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

```text
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

char auth[] = "YourAuthToken";

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth);  // Here your Arduino connects to the Blynk Cloud.
}

void loop()
{
  Blynk.run(); // All the Blynk Magic happens here...
}
```

#### Auth Token <a id="getting-started-getting-started-with-hardware-auth-token"></a>

In this example sketch, find this line:

```text
char auth[] = "YourAuthToken";
```

This is the [Auth Token](https://docs.blynk.cc/#getting-started-getting-started-with-application-4-auth-token) that you emailed yourself. Please check your email and copy it, then paste it inside the quotation marks.

It should look similar to this:

```text
char auth[] = "f45626c103a94983b469637978b0c78a";
```

Upload the sketch to the board and open Serial Terminal. Wait until you see something like this:

```text
Blynk v.X.X.X
Your IP is 192.168.0.11
Connecting...
Blynk connected!
```

**Congrats! You are all set! Now your hardware is connected to the Blynk Cloud!**

