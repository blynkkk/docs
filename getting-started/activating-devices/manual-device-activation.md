# Manual Device Activation

Manual device creation can be used with any device supported by Blynk no matter which type of connection they use.

Such workflow is mostly used during prototyping or for devices that don't require end-user activation.

Let's guide you on how to do it!

## Preparing your sketch

1. Install the latest version of Blynk Library to the IDE you use
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
2. If you don't have a  Device Templates -&gt; [Create New Template](../template-quick-setup/#create-a-template) or open an existing one
3. Copy the contents of this section and paste them to your sketch

![Template ID](https://user-images.githubusercontent.com/72824404/119491140-4234c300-bd66-11eb-80f4-324f2d06bfa0.png)

### Getting Auth Token

When the Template is ready, go to Search -&gt; Devices - **Create New Device**

![](https://user-images.githubusercontent.com/72824404/119494118-9db48000-bd69-11eb-952c-297c0b7627f8.png)

Choose a Template and give your new device a name

![](https://user-images.githubusercontent.com/72824404/119496316-0c92d880-bd6c-11eb-9276-9ce033ef38c2.png)

After the device was created, you will get the notification with TemplateID and AuthToken. Also, this info is always available in Device View -&gt; Device Info

![AuthToken](https://user-images.githubusercontent.com/72824404/119501175-4adec680-bd71-11eb-804f-75438981169a.png)

Now you have all the information you need to update your sketch:

```cpp
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLbu8•••••"
#define BLYNK_DEVICE_NAME "My First Device 01"
#include <BlynkSimpleEsp32.h>
char auth[] = "••••••••••••••VoFvaUOH2U_sI";
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

Upload the sketch to your device and open Serial Monitor. Wait until you see something like this:

```bash
Blynk v.X.X.X
Your IP is 192.168.0.11
Connecting to...
Ready (ping: 40ms)
```

### 

### Congrats! Your device is now online!

