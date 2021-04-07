# Static AuthToken

Static AuthToken is used when you are working with hardware that doesn't support Blynk.Edgent WiFi provisioning. For example when you are using Ethernet shield, or work with hardware that connects to the Internet over cellular \(3G, LTE, etc\) network.

### Preparing your sketch

1. Download [the latest release of Blynk.Edgent](https://github.com/blynkkk/blynk-library/releases/tag/v1.0.0-beta.3) as a **Source code .zip** file
2. Open [Arduino IDE](https://www.arduino.cc/en/guide/windows)
3. In Arduino IDE menu go to Sketch - &gt; Include Library 
4. Select Add .ZIP library

![](https://lh3.googleusercontent.com/i3hKUqAHHOLARrcHd0QaKKhVXjs2BAzFFgonSnaA2JyLWwO5aj7yM8Z0K7QwTpW_sU17pJTyBAx0hLjHPOGceIjdCJhUjYdjukK0sjQTE0EX_xBV3UPpjzWHVvPqhkB2neYdVhkm)

5. Select the downloaded .zip archive. Press **Choose** to continue.  
6. After that, you should see Blynk folder under the **File &gt; Examples**  
![](https://lh3.googleusercontent.com/WfHrWEDwJZ-mzHNcy1UVE1nwHDCAODrMkVehACEgsZYc4pS54L4o99Qel706TSEYPqUqNayc8Ur8pM6DCECYFH1hivgwC2O-KHSZgANz4yTkVV99JR-N4-8B2NDCoZXm3GlXm7eD)  
7. Select the example for the hardware you use. We will use the one for Arduino UNO + Ethernet shield

```cpp
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using blynk.cloud) */
#define BLYNK_TEMPLATE_ID             ""
#define BLYNK_DEVICE_NAME             ""

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

char auth[] = "YourAuthToken";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);
}

void loop()
{
  Blynk.run();
}
```

Pay attention to these 3 lines: you would need to fill them. 

```cpp
...
#define BLYNK_TEMPLATE_ID             ""
#define BLYNK_DEVICE_NAME             ""
...
char auth[] = "YourAuthToken";
...
```

### 

### Getting Template ID and Auth Token for device

#### Template ID and Device Name

1. Log in to your [Blynk.360](https://blynk.cloud/) developer account
2. If you don't have a  Device Templates -&gt; [Create New Template](../building-a-commercial-product-a-z.md#create-a-template) or open existing one
3. Copy the contents of this section and paste them to your sketch

![](../../.gitbook/assets/image%20%2820%29.png)

#### 

#### 

#### Getting Auth Token

When the Template is ready, go to Search -&gt; Devices - **Create new device**

![](../../.gitbook/assets/image%20%2819%29.png)

1. Choose a Template and give your new device a name

![](../../.gitbook/assets/image%20%2818%29.png)



1. After device was created, open its dashboard, go to Device Info tab. There you will find a field: Auth Token.

![](../../.gitbook/assets/image%20%2817%29.png)

Now you have all the information you need to update your sketch:

```cpp
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using blynk.cloud) */
#define BLYNK_TEMPLATE_ID "TMPLbu8YYym5"
#define BLYNK_DEVICE_NAME "My First Device"

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

char auth[] = "•••••••-•••••••-VoFvaUOH2U_sI";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);
}

void loop()
{
  Blynk.run();
}
```

1. Upload the sketch to your device
2. Open Serial Monitor. Wait until you see something like this:

```bash
Blynk v.X.X.X
Your IP is 192.168.0.11
Connecting...
Blynk connected!
```

