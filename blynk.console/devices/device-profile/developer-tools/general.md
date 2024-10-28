---
description: General tab of the developer tools screen
---

# General

<figure><img src="../../../../.gitbook/assets/developer-tools-general (1).png" alt=""><figcaption><p>Developer tools | General</p></figcaption></figure>

### Quick access panel

Contains important device attributes, such as status, last seen online, auth token, and template ID, as well as quick buttons to edit dashboard, download reports, create webhooks, or reboot device.

Click on auth token or template ID to copy.

### Vitals

{% hint style="info" %}
This feature is available in the PRO and higher plans.
{% endhint %}

The Vitals section provides real-time monitoring metrics and insights into the device's performance. It is divided into several key areas:

#### **Status Indicator**

Displays the current status of the device (e.g., `Online` with a green dot indicating active status).

#### **Online For**

Shows the duration the device has been online (e.g., `1h, 25min(s)`).

#### **Ping**

Displays the current ping in milliseconds (e.g., `124` ms), which indicates the network latency. Click on the icon to refresh.

#### **Sent/Received**

* **Sent:** Shows the amount of data sent by the device (e.g., `2,211` packets, `333 B` bytes).
* **Received:** Shows the amount of data received by the device (e.g., `221` packets, `22 B` bytes).

#### **Disconnections Today**

Indicates the number of disconnections that occurred today (e.g., `12`). This data considers [Connection Lifecycle](../../../../concepts/connection-lifecycle-management/) settings and excludes disconnections caused by Blynk.Cloud server restarts.

#### **Disconnections Chart**

Provides a visual representation of disconnections over the month, with larger dots indicating higher frequencies. Also shows the average count of disconnections daily within the month.\


### Hardware Info

#### **Board Type**

Indicates the type of board used (e.g., ESP32).

#### **IP Information**

* IP Country
* IP Latitude/Longitude

#### **Heartbeat Interval**

Displays the interval in seconds for [heartbeat ](../../../../concepts/connection-lifecycle-management/disconnections-and-heartbeat.md#heartbeat)signals (e.g., 10 seconds).\


### Firmware Info

#### **Firmware Version**

Displays the current firmware version installed on the device.

#### **Last Build**

Shows the timestamp of the last build.

#### **SSL Status**

Indicates whether SSL is enabled or disabled (e.g., Disabled).

#### **Blynk Library Version**

Shows the version of the Blynk library in use.

#### **Firmware Configuration**

* Template ID (e.g., `TMPL03hIx7TL`)
* Template Name (e.g., `Quickstart Template 333`)
* Auth Token (partially obscured for security reasons)

Click to copy the code.

#### **OTA Update Button**

Allows you to initiate an Over-The-Air (OTA) update for your firmware on this device.
