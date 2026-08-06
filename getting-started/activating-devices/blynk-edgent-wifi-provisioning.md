---
description: >-
  Sending WiFi credentials and the Auth Token to your device. This feature is
  also known as "Dynamic Provisioning" and "WiFi Manager"
---

# Dynamic Provisioning

## WiFi provisioning

Remember going to a coffee shop and asking for the name and password for their WiFi network to connect your smartphone or laptop to? Familiar situation, right?

Now imagine your ESP32 or other hardware wants to connect to the Internet. It would also need the wifi network name and password. Good news, Blynk can do it for you.

A complete WiFi provisioning solution from Blynk includes both a firmware code and a mobile app UI to guide you through the WiFi setup. It's called **Blynk.Inject**

{% hint style="info" %}
Currently, WiFi provisioning with Blynk.Inject works on:

* **Arduino:** ESP32 series, ESP8266, Seeed WIO Terminal
* **Particle Gen 3 devices:** Muon, Argon, Boron, Photon 2, Tracker, P2, BSOM, MSOM
* **MicroPython:** ESP32 series, Raspberry Pi Pico W
* **Blynk.NCP:** ESP32 series
{% endhint %}

### **How WiFi provisioning works**

You can skip this part as this is something you don't have to think about because Blynk does everything for you. But it might be helpful to understand how it works under the hood.

1. In the beginning, your hardware will act as an Access Point (AP) — unless it's a BLE-assisted device, in which case it advertises over Bluetooth instead of broadcasting a WiFi network. Either way, your device becomes discoverable with a name similar to `Blynk Device-1234`
2. Your smartphone will connect to this AP with the Blynk app (or from smartphone settings) and they will start communicating directly with each other
3. Blynk app will ask you for the name (SSID) and password of the WiFi network you would like to connect this device to
4. WiFi information (SSID and password) will be sent to the device
5. Also, Blynk app will request an Auth Token from the server and then send it to the device
6. Your device will store all of these items in Flash/EEPROM memory
7. After that, the device will automatically reboot. The AP mode will be turned off.
8. The device will use the WiFi credentials you provided to connect to your home or office WiFi network
9. After the successful authentication, the device is added to your account and is ready to use
10. If you later need to connect this device to a different network, WiFi credentials can be changed using Blynk app, by resetting the device with a physical button (you would need to plan it into your electrical circuit design)

Now let's make it work for your devices.

{% hint style="warning" %}
To enhance the end-user experience it's highly recommended that you plan certain components into device's electrical design. **Especially if you are working on a commercial product!**

1. Plan a physical button which will allow resetting the device to its default settings. E.g.: Holding this button for N seconds will erase the AuthToken and WiFi credentials.
2. Plan an LED to indicate different statuses of device (AP, connected, etc.). It can be RGB or one-color LED.

You can find references to handling reset and statuses indication in Blynk.Edgent examples
{% endhint %}

### Real-time feedback during provisioning (BLE)

Devices that keep a Bluetooth connection to the phone alive throughout provisioning (instead of only a Wi-Fi AP link) let the Blynk app show the device's _actual_ state and error codes live, rather than guessing after the connection drops. This is what powers the live error recovery and precise error reporting described in [Add New Device → Error Handling](../../blynk.apps/device-management/add-new-device.md#error-handling), and it's also what shows up in [Provisioning Sessions](../../blynk.console/developers/debugging/provisioning-sessions.md) as a full step-by-step timeline.

{% hint style="success" %}
BLE-assisted provisioning is supported by the basic Blynk.Edgent examples found in the [Blynk.Edgent overview](../../blynk.edgent/overview.md) — exact support depends on your hardware type.
{% endhint %}

### Setting up your sketch to enable WiFi Provisioning

1. Install Blynk Library in Arduino IDE (or download [the latest release](https://github.com/blynkkk/blynk-library/releases/latest) as a .zip file and install the library as a zip file)
2. Open [Arduino IDE](https://www.arduino.cc/en/software)
3. After that, you should see Blynk folder under the **File > Examples**
4. Select **Blynk.Edgent > Edgent\_ESP32**

{% hint style="warning" %}
In the sketch variables `BLYNK_TEMPLATE_ID` and `BLYNK_TEMPLATE_NAME` are empty. They must be filled in with the values from your template. Read below on where to find them.
{% endhint %}

1. Log in to your [Blynk.Console](https://blynk.cloud/) developer account
2. Go to Developer Zone -> My Templates -> Create New Template or open an existing template
3. Copy the Firmware Configuration code lines
4. Go back to your sketch and replace the configuration lines with what you copied.

<figure><img src="../../.gitbook/assets/prepare-code (1).gif" alt=""><figcaption></figcaption></figure>

{% hint style="warning" %}
The Template Name is the name that you provide when you create the template, and the Edgent sketch then adds additional characters that are derived from the Chip ID of the device to form the SSID name which is used when the app connects to the device.

The template name + Chip ID should not exceed 32 characters for the provisioning process to complete successfully. You can edit the template name if the resulting SSID name proved too long.
{% endhint %}

Press the **Upload** button to flash the code to your device. If the upload process went successfully you should see the output in the serial monitor.

Now your device is ready to be activated using Blynk app.

### Activating the device using Blynk app

Tap **Add New Device** in the app and follow the on-screen instructions — the app will guide you through preparing the device, finding it, connecting it to your Wi-Fi network, and (if your template uses it) a short device profiling step.

{% content-ref url="../../blynk.apps/device-management/add-new-device.md" %}
[add-new-device.md](../../blynk.apps/device-management/add-new-device.md)
{% endcontent-ref %}

Here is an example of how it works in the app:

{% embed url="https://www.youtube.com/watch?v=bXPEEmsEtPM" %}

For debugging and troubleshooting check the serial monitor output. There you will see how the provisioning process is happening on the device. If you hit an error while testing, Developer Mode shows a **Reason** and **Session ID** on the error screen — look that session up in [Provisioning Sessions](../../blynk.console/developers/debugging/provisioning-sessions.md) for a full step-by-step timeline. When troubleshooting a report from an end customer (who won't see these fields), search by their email or the approximate time of the attempt instead.

### Re-provisioning new WiFi credentials

If you’re having problems provisioning a device, or you’ve accidentally entered the wrong WiFi credentials, then press and hold the physical button (the one defined in Settings.h for your board type) for 10 seconds. This will clear the stored credentials and the LED will start flashing quickly and allow you to either repeat the provisioning process, or if the device has already been created in the app you can re-provision it.

To re-provision an existing device, tap on the device in the app, then tap the three dots in the top right-hand corner of the app screen. This will bring up the device information screen.

Tap on the three dots in the top right-hand corner once more, and this will pop up a dialog that allows you to “Reconfigure”, “Erase all device data” or “Delete Device”.

Choose “Reconfigure” and this will take you back into the provisioning process described in the earlier section.

If the wrong SSID was selected and/or the password was entered before then take care to enter the correct information rather than using the credentials stored in the app.

### Troubleshooting

If the LED on the board isn’t doing anything, then ensure that the LED and switch are defined correctly and that you don’t have any peripherals also using the LED or Switch pins.\
\
If the LED is pulsing slowly then the board thinks it’s already provisioned. Follow the instructions in the _“_[_Re-provisioning new WiFi credentials_](blynk-edgent-wifi-provisioning.md#re-provisioning-new-wifi-credentials)_”_ section.\
\
If the LED is flashing quickly, but the device doesn’t show up in the app when you tap the “Ready” button in the app then check the following:

* The Template name isn’t too long (see the restrictions for BLYNK\_TEMPLATE\_NAME above)
* The template ID and template name in the sketch are EXACTLY as they appear in the web console
* The app is signed in to the same user account as the web console, or
* The user has permission to provision new devices.

#### ESP32/ESP8266-specific issues

If you cannot configure the device, and the log displays `AP IP: 0.0.0.0` , please ensure you're using the latest stable Arduino Core version (i.e., not an outdated, beta, or rc version).

In some rare cases it could be a hardware issue of a specific module, so if you have any issues please also try using a new (unused) module.
