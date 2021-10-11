# Bluetooth (2.0 SPP, 4.0 LE)



Bluetooth 4.0 (Smart, Low-Energy) modules are supported on both iOS and Android.\
Bluetooth 2.0 (Classic, Serial Port Profile) modules are supported **only on Android**.

#### Getting started <a href="getting-started" id="getting-started"></a>

1. When adding new hardware project, select **Bluetooth** or **BLE** connection method
2. Add "**BLE**" (for BTLE) or "**Bluetooth**" (for SPP) widget
3. In widget settings, click **Connect** button. It should say "connected"
4. Run your project

#### Limitations <a href="limitations" id="limitations"></a>

* Home-screen widgets are not usable for Bluetooth projects
* Some widgets are not working with Bluetooth:\
  RTC (will be enabled later), History Graph, Bridge, Eventor, WebHook, Twitter, Notification, Email

#### Troubleshooting <a href="troubleshooting" id="troubleshooting"></a>

If "BLE" or "Bluetooth" widgets are not shown, it means your smartphone doesn't support it (be sure to enable Bluetooth and Location Services).

If it doesn't get connected:

* Restart your phone and retry
* Try using original examples of your hardware/library providers - maybe the problem is in hardware/wiring
