# Manual Device Activation

Manual device creation can be used with any device supported by Blynk no matter which type of connection they use.

Such workflow is mostly used during prototyping or for devices that don't require end-user activation.

Follow the steps 1-4 below:

<details>

<summary>Step 1: Perparing your sketch</summary>

1. Install the latest version of Blynk Library to the IDE you use
2. After that, you should see Blynk folder under the **File > Examples**
3. Select the example for the hardware you use. We will use the one for ESP32

```cpp
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID      "TMPL••••••••"
#define BLYNK_TEMPLATE_NAME    "Test"
#define BLYNK_AUTH_TOKEN       "••••••••••••••••••••••••"

#include <BlynkSimpleEsp32.h>

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, "wifi-ssid", "wifi-pass");
}

void loop()
{
  Blynk.run();
}
```

Pay attention to these 4 lines: you would need to fill them.

```cpp
#define BLYNK_TEMPLATE_ID      "TMPL••••••••"
#define BLYNK_TEMPLATE_NAME    "Test"
#define BLYNK_AUTH_TOKEN       "••••••••••••••••••••••••"
...
Blynk.begin(BLYNK_AUTH_TOKEN, "wifi-ssid", "wifi-pass");
```

</details>

<details>

<summary>Step 2: Getting Template ID</summary>

#### Template ID and Device Name

1. Log in to your [Blynk.Console](https://blynk.cloud/) developer account
2. If you don't have a Device Templates -> [Create New Template](../template-quick-setup/#create-a-template) or open an existing one
3. Copy the contents of this section and paste them to your sketch

<img src="https://user-images.githubusercontent.com/72824404/119491140-4234c300-bd66-11eb-80f4-324f2d06bfa0.png" alt="Template ID" data-size="original">

</details>

<details>

<summary>Step 3: Getting Auth Token</summary>

#### Getting Auth Token

When the Template is ready, go to Search -> Devices - **Create New Device**

<img src="https://user-images.githubusercontent.com/72824404/119494118-9db48000-bd69-11eb-952c-297c0b7627f8.png" alt="" data-size="original">

Choose a Template and give your new device a name

<img src="https://user-images.githubusercontent.com/72824404/119496316-0c92d880-bd6c-11eb-9276-9ce033ef38c2.png" alt="" data-size="original">

After the device was created, you will get the notification with TemplateID and AuthToken. Also, this info is always available in Device View -> Device Info

<img src="../../.gitbook/assets/image (2) (1).png" alt="" data-size="original">

Now you have all the information you need to update your sketch:

</details>

<details>

<summary>Step 4: Updating sketch with Template ID and AuthToken</summary>

Add `TEMPLATE_ID` and `AuthToken` to your sketch:

<pre class="language-cpp"><code class="lang-cpp">#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID      "TMPL••••••••"
#define BLYNK_TEMPLATE_NAME    "My First Device"
#define BLYNK_AUTH_TOKEN       "••••••••••••••••••••••••"

#include &#x3C;BlynkSimpleEsp32.h>

<strong>void setup()
</strong>{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, "your-wifi-ssid", "your-wifi-pass");
}

void loop()
{
  Blynk.run();
}
</code></pre>

Upload the sketch to your device and open Serial Monitor. Wait until you see something like this:

```bash
Blynk v.X.X.X
Your IP is 192.168.0.11
Connecting to...
Ready (ping: 40ms)
```

#### Congrats! Your device should be now online!

</details>
