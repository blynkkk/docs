---
hidden: true
---

# Bluetooth (2.0 SPP, 4.0 LE)

{% hint style="warning" %}
This documentation is for the LEGACY version of Blynk platform which is no longer supported and will be shut down.&#x20;

You can sign up for the current version of Blynk platform [here](http://blynk.cloud/dashboard/register).

The new mobile apps can be downloaded from [App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868) and [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk\&hl=en\&gl=US).

The actual Blynk documentation is [here](https://docs.blynk.io/).
{% endhint %}



Bluetooth 4.0 (Smart, Low-Energy) modules are supported on both iOS and Android.\
Bluetooth 2.0 (Classic, Serial Port Profile) modules are supported **only on Android**.

#### Getting started <a href="#getting-started" id="getting-started"></a>

1. When adding new hardware project, select **Bluetooth** or **BLE** connection method
2. Add "**BLE**" (for BTLE) or "**Bluetooth**" (for SPP) widget
3. In widget settings, click **Connect** button. It should say "connected"
4. Run your project

#### Troubleshooting <a href="#troubleshooting" id="troubleshooting"></a>

If "BLE" or "Bluetooth" widgets are not shown, it means your smartphone doesn't support it (be sure to enable Bluetooth and Location Services).

If it doesn't get connected:

* Restart your phone and retry
* Try using original examples of your hardware/library providers - maybe the problem is in hardware/wiring
