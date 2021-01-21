---
description: needs updates
---

# Getting Started With Hardware

### Getting Started With Hardware <a id="getting-started-getting-started-with-hardware"></a>

#### How To Use an Example Sketch <a id="getting-started-getting-started-with-hardware-how-to-use-an-example-sketch"></a>

You should by now have the Blynk 2.0 Library installed on your computer. If not - [click here](https://docs.blynk.cc/#downloads-blynk-library).  
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

