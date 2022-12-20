# Custom Sounds and Critical Notifications

It is possible to customize sounds for notifications coming from Blynk. There are three main push notification channels:

* In-app push notifications from a device triggered by [events](../custom-events/events-general-setting.md) configured in the Blynk.Console.&#x20;
* Notifications triggered by Automations&#x20;
* Other such as [content events](../custom-events/events-content-events.md).&#x20;

Each channel can be configured to turn on/off all notifications or use custom sounds, and device event notifications can be configured as critical alerts in some cases.&#x20;

### Device Event Notifications

For a notification to be considered an alert and become eligible for sound customization, a corresponding setting must be turned on in the Notifications tab of the event settings on the [Blynk.Console](https://blynk.cloud/).  Go to Templates -> Template -> Edit -> Events Tab, select an event and then the ‘Notifications’ tab. Enable the option ‘Deliver push notification as alerts’ and then configure the sound settings in Blynk apps.

<img src="../../../../.gitbook/assets/image.png" alt="" data-size="original">

<figure><img src="../../../../.gitbook/assets/image (2).png" alt=""><figcaption></figcaption></figure>

On the ‘General’ tab, enable the option ‘Send event to Notifications tab’ if you want the event to be visible in the app notifications tab.

<figure><img src="../../../../.gitbook/assets/image (1).png" alt=""><figcaption></figcaption></figure>

#### For iOS:

Go to Main menu -> Settings -> Notifications and sounds -> Devices. From this menu you can enable/disable notifications from device events or select a custom sound for it.

#### For Android:

Access notifications by choosing Profile -> Settings -> Notifications and sounds -> CRITICAL NOTIFICATIONS.  From here you may turn on/off Critical Notifications, and when enabled, choose the notification sound. &#x20;

### Critical notifications

#### iOS

Clients using [BUSINESS plan](https://blynk.io/pricing/business-plan) can cause critical alerts to be recognized by iOS, resulting in delivery with maximum sound, ignoring the phone’s mute and Do Not Disturb settings.

{% hint style="warning" %}
App approval to use this feature is required by Apple.
{% endhint %}

#### Android

On Android Critical notifications were created to bypass the iOS / Android app Do Not Disturb setting and to enable custom sounds for different triggers. (By default when Do Not Disturb is enabled for Android, notifications and sounds are suppressed).&#x20;

![](https://lh4.googleusercontent.com/mpVqM6HCmq\_pNHXu\_kVBy3x4fogK6z4EcTmneJQDFSXbjyAO8eQs8E-DtJmdqbTDdYZTAFNelAt93rbMP7IhN0xEpfDoefPs1nNt0rKuHkNPDwLgjY-Yv69\_3Ge5849YkpA-fNEHHUi9HXgPkwUSqf7lD0kI-IvSSr7M1h49M\_ZioKA9MxISzHn-q6LdUw)    ![](https://lh6.googleusercontent.com/QlshOhaAvFfokgobt8PzwvdxnMmIWIJDTE3NJAM-nn317q4xDdat7FWcAQEVv7xmum2mjnZp9e2Z4MUsl\_5ib5LYgHkuIwSLFzr8ELDN\_IRBlNkpb5NcYwkXZjZ8Tar3mKtHRl4sW9F-CRyKAMK-9UCJza6mtHASJts3SASMbR7sjRm-a5A8Rlrq7FqXdQ)

To turn on/off the ‘Ignore Background Restrictions’ option, causing Blynk to run in the background in an attempt to push notifications despite the phone’s do not disturb settings.

{% hint style="warning" %}
For some devices Android ‘Do Not Disturb’ may still prevent receipt of notifications.&#x20;
{% endhint %}

### Notifications customization by device

On Android notification settings may also be configured for each Blynk device. Select a device, and then tap on the More info icon, tap on the More info icon again, then within the ‘Actions’ page, select ‘Notification Settings’.  From here you have extensive control over the notification settings for the device, including the notification sound.

An additional setting ‘Override Do Not Disturb’ can be found by expanding the ‘Advanced’ menu. After enabling this setting, a window will appear asking for permission to always run the app in the background.

![](https://lh4.googleusercontent.com/UlvJN22bwAdjDz78ECtZz0mRF-mk0hTOp8rSo8vghpX40CulhunmV\_79lNyATEudfqR0Tk-j6S\_4BpBbGfVfLjN4vPgbLf5aRc-xCGebIQHV6dw02IC-FQGP7qoO-k0gI1bXymGlG69A7pQ\_b55HbGfUrGGYvi0UqPAP5onR8dVq3f-8mxSTHlIsruEoig)



### Customize Notifications from Automations

The detailed notification setting options for each automation are accessible from the Blynk.App and vary depending on the platform.&#x20;

#### For iOS:

Go to Main menu -> Settings -> Notifications and sounds -> Automations. From this menu you can enable/disable notifications from Automations or select a custom sound for it.

#### For Android:

Go to Automations tab, select an automation, and then choose ‘Notification Settings’.

| ![](https://lh3.googleusercontent.com/TUtmfIlLfuWJAU3ofNzZqMMfJXP2WzUjUhghhvUMiaDHpY4ciZXraNYfxiFlSKHgvrKNInZavwGzPa8L86EMZcJQSwEVczKnBo5iIYxKboOPenABzJwJOBJtC\_BQ0GYb2s7v9M06rL5-ybcpPGgF2JEstnWWUpIpQa9HNx2h4hUptduxjbY9kg4saPe9OQ) | ![](https://lh5.googleusercontent.com/Qy-vyLljcpRWigkCtZ8o7fAgpyMd8sV\_P\_3Gy1vtLcVQ9vh8sY\_BuzJ5kePyKRHxXf4VSUa6suJ3QYM5MKyuXm9s82lp1X-c2L1iQoUktYiy9SIXg4RE27um6PxSHhlON-etdqzszRcHU5sQtODllnSAYK5y7eV\_SPcKqkc0nv7EDHP\_nzusLwGbC7nTHQ) |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
