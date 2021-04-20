# Prepare Your Code

A code example for ESP32/ ESP 8266 / Arduiono

{% tabs %}
{% tab title="ESP32" %}
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
{% endtab %}

{% tab title="ESP8266" %}
Add a code for ESP8266
{% endtab %}

{% tab title="Arduino \(or any other supported hardware\)" %}
Instructions and code for Static Token
{% endtab %}

{% tab title="Any Raspberry Pi" %}
JS code \(can be added later\)
{% endtab %}
{% endtabs %}

