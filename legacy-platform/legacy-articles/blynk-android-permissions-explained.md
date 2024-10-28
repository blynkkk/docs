---
hidden: true
---

# Blynk Android permissions explained

{% hint style="warning" %}
This documentation is for the LEGACY version of Blynk platform which is no longer supported and will be shut down.&#x20;

You can sign up for the current version of Blynk platform [here](http://blynk.cloud/dashboard/register).

The new mobile apps can be downloaded from [App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868) and [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk\&hl=en\&gl=US).

The actual Blynk documentation is [here](https://docs.blynk.io/).
{% endhint %}

**Camera**

Required to be able to access the camera device

Blynk app needs camera permission for being able to scan QR codes, that are used for project’s sharing or cloning. On devices with Android 6.0 and later this permission would be disabled by default - Blynk app will ask you to grant this permission if it would be needed.

**Location**

Allows an app to access precise and/or approximate location

App needs this permission only for GPS Stream and GPS Trigger widgets. Also on devices with Android 6.0 and later this permission is needed for Wi-Fi or BLE/Bluetooth devices scan due to privacy protection - detailed explanation could be found [here](https://developer.android.com/about/versions/marshmallow/android-6.0-changes.html#behavior-hardware-id).

On devices with Android 6.0 and later this permission would be disabled by default - Blynk app will ask you to grant this permission if you will add this widgets.&#x20;

**Storage**

Allows an application to read from external storage or to write to it

App needs this permission for an access to ringtone files for the Notification widget. Write permission is needed only for devices with Android 5.1 or earlier. On devices with Android 6.0 and later this permission would be disabled by default - Blynk app will ask you to grant this permission if you will try to setup custom notification’s ringtone.

Other app permissions

**Receive data from Internet / Have full network access / View network connections**

Application works via Internet connection to the Blynk cloud or any other user defined server, or via local network connection to a local Blynk server.

**Pair with Bluetooth device / Access Bluetooth settings**

App needs this permission only for Bluetooth Serial and Bluetooth widgets, which enable support to connect to BLE/Bluetooth boards.

**View Wi-Fi connections / Connect and disconnect from Wi-Fi**

App uses this permission for boards provisioning via Wi-Fi.

**Google Play billing service**

This permission is required for in-app purchases support.

**Control vibration**

This permission is used for the vibration on push notifications receive.

**Prevent phone from sleeping**

This permission is used for when "keep screen on” option is enabled for selected projects.\
