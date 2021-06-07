# Static AuthToken

Static AuthToken is used when you are working with hardware that doesn't support Blynk.Edgent WiFi provisioning. For example when you are using Ethernet shield, or work with hardware that connects to the Internet over cellular \(3G, LTE, etc\) network.

## Preparing your sketch

1. Download [the latest release of Blynk.Edgent](https://github.com/blynkkk/blynk-library/releases/tag/v1.0.0-beta.3) as a **Source code .zip** file
2. Open [Arduino IDE](https://www.arduino.cc/en/guide/windows)
3. In Arduino IDE menu go to Sketch - &gt; Include Library 
4. Select Add .ZIP library

![](https://lh3.googleusercontent.com/i3hKUqAHHOLARrcHd0QaKKhVXjs2BAzFFgonSnaA2JyLWwO5aj7yM8Z0K7QwTpW_sU17pJTyBAx0hLjHPOGceIjdCJhUjYdjukK0sjQTE0EX_xBV3UPpjzWHVvPqhkB2neYdVhkm)

1. Select the downloaded .zip archive. Press **Choose** to continue.  
2. After that, you should see Blynk folder under the **File &gt; Examples**
3. Select the example for the hardware you use. We will use the one for Arduino UNO + Ethernet shield

![](https://lh3.googleusercontent.com/WfHrWEDwJZ-mzHNcy1UVE1nwHDCAODrMkVehACEgsZYc4pS54L4o99Qel706TSEYPqUqNayc8Ur8pM6DCECYFH1hivgwC2O-KHSZgANz4yTkVV99JR-N4-8B2NDCoZXm3GlXm7eD)

```cpp
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLXtg6ltzI"
#define BLYNK_DEVICE_NAME "Test"
#include <BlynkSimpleEsp32.h>
char auth[] = "1jIajShg30JO-QQZmlWf1NjdH5FNi2wW";
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, "wifi-ssid", "wifi-pass");
}
void loop()
{
  Blynk.run();
}
```

Pay attention to these 4 lines: you would need to fill them.

```cpp
...
#define BLYNK_TEMPLATE_ID             ""
#define BLYNK_DEVICE_NAME             ""
...
char auth[] = "YourAuthToken";
...
Blynk.begin(auth, "wifi-ssid", "wifi-pass");
```

## Getting Template ID and Auth Token for device

### Template ID and Device Name

1. Log in to your [Blynk.Console](https://blynk.cloud/) developer account
2. If you don't have a  Device Templates -&gt; [Create New Template](../working-with-templates/#create-a-template) or open an existing one
3. Copy the contents of this section and paste them to your sketch

![Template ID](https://user-images.githubusercontent.com/72824404/119491140-4234c300-bd66-11eb-80f4-324f2d06bfa0.png)

### Getting Auth Token

When the Template is ready, go to Search -&gt; Devices - **Create new device**

![](https://user-images.githubusercontent.com/72824404/119494118-9db48000-bd69-11eb-952c-297c0b7627f8.png)

1. Choose a Template and give your new device a name

![](https://user-images.githubusercontent.com/72824404/119496316-0c92d880-bd6c-11eb-9276-9ce033ef38c2.png)

1. After the device was created, open its dashboard, go to the Device Info tab. There you will find a field: Auth Token.

![AuthToken](https://user-images.githubusercontent.com/72824404/119501175-4adec680-bd71-11eb-804f-75438981169a.png)

Now you have all the information you need to update your sketch:

```cpp
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLbu8YYym5"
#define BLYNK_DEVICE_NAME "My First Device 01"
#include <BlynkSimpleEsp32.h>
char auth[] = "•••••••-•••••••-VoFvaUOH2U_sI";
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, "your_wifi-ssid", "your_wifi-pass");
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
Connecting to...
Ready (ping: 40ms)
```

