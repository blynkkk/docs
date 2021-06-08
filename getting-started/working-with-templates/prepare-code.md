# Prepare Your Code

A code example for ESP32/ ESP8266 / Arduino boards

{% tabs %}
{% tab title="ESP32 or ESP8266" %}
## 3 simple steps to configure your code:

1. [Install Blynk library](http://help.blynk.cc/en/articles/512105-how-to-install-blynk-library-for-arduino-ide)
2. Specify [Template ID and Template Name](https://github.com/blynkkk/docs/tree/7a3c08cef5784864e5581561ccda90b394717039/getting-started/working-with-templates/getting-started/working-with-templates/prepare-code.md) in your firmware
3. Upload this sketch into your test board

**Final step:** [Provision your board via Dynamic Provisioning flow](https://docs.blynk.io/en/getting-started/activating-devices#3-add-device) and add it to your account using Blynk app

Example of a code with **basic functions** that you can use for your test product:

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

int randomValue;  //This variable stores random values
int buttonStatus  //This variable stores the button click

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  timer.setInterval(1000L, myTimerEvent);  //This code sets Timer that will start every second myTimerEvent() function
}

void loop() {
  BlynkEdgent.run();
}

void myTimerEvent() //Timer will run this function every second
{
  randomValue = random(20,30);  //Generate random values and store them in the appropriate variable
  Serial.println(String("Value: ") + randomValue);   //The generated random value will be printed to Serial Monitor output
  Blynk.virtualWrite(V0, randomValue);  //Send the generated value to blynk.cloud
}

BLYNK_WRITE(V1) //This function reads the status of Button. It will start every time you click this Button.
{
  int buttonStatus = param.asInt(); //Reading the current state and saving it to the corresponding variable
  Serial.println(String("Button Status: ") + buttonStatus); //The current Button status will be printed to Serial Monitor output
  if (buttonStatus == 1){ //Button click handling
    Blynk.virtualWrite(V0, 70); //Reaction of the system to the click of Button
  }
}

```
{% endtab %}

{% tab title="Arduino \(static provision\)" %}
{% hint style="info" %}
Instructions and code for Static AuthToken is used when you are working with hardware that doesn't support Blynk.Edgent WiFi provisioning. For example when you are using Ethernet shield, or work with hardware that connects to the Internet over cellular \(3G, LTE, etc\) network.
{% endhint %}

1. Download [the latest release of Blynk.Edgent](https://github.com/blynkkk/blynk-library/releases/tag/v1.0.0-beta.3) as a **Source code .zip** file
2. Open [Arduino IDE](https://www.arduino.cc/en/guide/windows)
3. In Arduino IDE menu go to Sketch - &gt; **Include Library** 
4. Select Add **.ZIP library**

![](https://lh3.googleusercontent.com/i3hKUqAHHOLARrcHd0QaKKhVXjs2BAzFFgonSnaA2JyLWwO5aj7yM8Z0K7QwTpW_sU17pJTyBAx0hLjHPOGceIjdCJhUjYdjukK0sjQTE0EX_xBV3UPpjzWHVvPqhkB2neYdVhkm)

1. Select the downloaded .zip archive. Press **Choose** to continue.  
2. After that, you should see Blynk folder under the **File &gt; Examples**  

   ![](https://lh3.googleusercontent.com/WfHrWEDwJZ-mzHNcy1UVE1nwHDCAODrMkVehACEgsZYc4pS54L4o99Qel706TSEYPqUqNayc8Ur8pM6DCECYFH1hivgwC2O-KHSZgANz4yTkVV99JR-N4-8B2NDCoZXm3GlXm7eD)  

3. Select the example for the hardware you use. We will use the one for Arduino UNO + Ethernet shield

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

### Getting Template ID and Auth Token for device

#### Template ID and Device Name

1. Log in to your [Blynk.Console](https://blynk.cloud/) developer account
2. If you don't have a  Device Templates -&gt; [Create New Template](./#create-a-template) or open an existing one
3. Copy the contents of this section and paste them to your sketch

![](../../.gitbook/assets/image%20%2820%29.png)

#### Getting Auth Token

When the Template is ready, go to Search -&gt; Devices - **Create new device**

![](../../.gitbook/assets/image%20%2819%29.png)

1. Choose a Template and give your new device a name

![](../../.gitbook/assets/image%20%2818%29.png)

1. After the device was created, open its dashboard, go to the Device Info tab. There you will find a field: Auth Token.

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
{% endtab %}
{% endtabs %}

