# Template Quick Setup

A **Device Template** is a set of configurations inherited by devices of a similar type.

![](<../../.gitbook/assets/blynk-template-device-relationship (2).png>)

Think about smart home switches. They all perform a similar function and it's safe to assume that they should have the same data model, GPIOs, firmware code, etc. You can create a SmartSwitch template and then create multiple SmartHome switches from it.

## Tutorial Overview

While Device Template has a lot of settings, in this tutorial, we focus only on the most important settings to get your devices up and running quickly. By the end of this tutorial, you should have a working device that will:

* Send random values to the web and mobile dashboard in given intervals
* Receive user input from the web or mobile dashboard UI elements

{% hint style="info" %}
You would need a development board (e.g. Node MCU, Arduino). A list of supported boards can be found [here](../../blynk.edgent/supported-boards.md).
{% endhint %}

Full documentation on all of the Template settings can be found [here](../../blynk.console/templates/working-with-templates.md).

## **1. Enable Developer Mode**

Before moving further, make sure that you have **Developer Mode** enabled:

1. In the Blynk app or in Blynk.Console
2. Navigate to **My Profile** → **User profile** in the left menu
3. Check that the **Developer Mode** switch is set to ON

{% hint style="warning" %}
Currently, **only one developer is allowed per Organization** to avoid sync issues. This limit can be changed later.
{% endhint %}

## 2. Edit/Create Template

Open the Templates section in the left menu and click **+ New Template** button**.** If you already have a template - click to open it and press **Edit** button.

![](../../.gitbook/assets/open-templates.gif)

## 3. **Basic** Settings

Give your new template a name, specify the hardware and connectivity you will be using.

{% hint style="info" %}
If you can't find your hardware in the list choose **Other**
{% endhint %}

![New template modal](https://user-images.githubusercontent.com/72790181/119468187-e1e65700-bd4e-11eb-8cfd-7c6fffda7b09.png)

## 4. Find **Template ID**

A new Template is now created. On the screen below notice **Template ID** and **Firmware Configuration** sections. You will need these details later in your sketch.

![Template editing](https://user-images.githubusercontent.com/72790181/119468206-e6127480-bd4e-11eb-974a-d50402fbee52.png)

## 5. **Set Up Mobile Dashboard**

1. Open [Blynk.Apps](../../blynk.apps/overview.md)
2. Log In to your account
3. Switch to [Developer Mode](../../concepts/developer-mode.md)
4. Find a template you just created on the web and tap on it.

## Configure your board:

1. Open Dynamic Provisioning Template: - [ESP8266 ](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent\_ESP8266)- [ESP32 ](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent\_ESP32)- [MKR1000 ](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent\_MKR1000)- [MKR1010](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Edgent/Edgent\_MKR1010)&#x20;
2. Specify [TMPLID](https://docs.blynk.io/en/blynk.console/templates/info/template-ids), [SSID WiFi](../../blynk.console/templates/info/hotspot-prefix.md) and Board Name in the [sketch](../activating-devices/)
3. Upload this code to your board

### Congratulations, you have configured your device and it is ready to use!

Now all that remains is to [add your test board using Blynk.Apps](../../blynk.apps/device-management/add-new-device.md), make sure it works as you expect, and integrate your code.
