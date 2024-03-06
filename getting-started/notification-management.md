---
description: How to set up notifications for a single device or for a selection of devices.
---

# Notifications (Alerts)

Notifications/Alerts is a crucial part of any IoT solution. Blynk offers extensive set of features to send and receive in-app (push), email, and SMS notifications from devices.

There are three main approaches you can take:

1. End-users can set up Notifications using [Automations](../concepts/automations/) (if allowed so by their role and set of permissions). Once Automation is set up, Blynk.Cloud monitors the data and sends notification to the specified recipients when the condition is met.&#x20;
2. Device-driven notifications
3. [Content events](../blynk.console/templates/events/custom-events/events-content-events.md)

## Use Automations To Send Notifications From Blynk.Cloud (no code)

This is the easiest way of sending notifications triggered by user-defined conditions .You don't even need to write any code on the hardware, Blynk.Apps and Blynk.Console offer a simple user interface to set it up. Blynk.Cloud will do all the rest.

Read more about setting up automations here:

{% content-ref url="../concepts/automations/" %}
[automations](../concepts/automations/)
{% endcontent-ref %}

## Send Notifications From Hardware

Very often notifications and alerts are an integral part of an IoT product and has to be triggered by the device itself. Blynk offers a way to pre-configure and inegrate alerts into the device logic.&#x20;

Such Notifications are part of Events functionality. You would need to configure an [Event](../blynk.console/templates/events/) first

{% hint style="info" %}
Note: notifications are parts of [Events](../blynk.console/templates/events/). Before moving forward:

1. Make sure your template has Event configured
2. Make sure that [Notifications are enabled](../blynk.console/templates/events/events-notification-settings/) for this Event
{% endhint %}

{% content-ref url="../blynk.console/templates/events/custom-events/events--how-to-log-events.md" %}
[events--how-to-log-events.md](../blynk.console/templates/events/custom-events/events--how-to-log-events.md)
{% endcontent-ref %}

## Setting notifications for multiple devices

1. Go to [Devices](../blynk.console/devices/)&#x20;
2. Select multiple devices (1)
3. Hover over the **Actions menu \[...]** (2)
4. Click **Notification Settings** (3)

<figure><img src="../.gitbook/assets/5-notifications 1.png" alt=""><figcaption></figcaption></figure>

In the opened drawer select the desired events to edit (4) -> **Edit Settings** (5)

<figure><img src="../.gitbook/assets/6-notifications 1.png" alt=""><figcaption></figcaption></figure>

{% hint style="warning" %}
If the list of events is empty or you don't see the **Edit Settings** button, make sure that [Notifications are enabled](../blynk.console/templates/events/events-notification-settings/) for this Event in the Device Template
{% endhint %}

<figure><img src="../.gitbook/assets/7-notifications-settings window 1.png" alt=""><figcaption></figcaption></figure>

In the modal window turn on the desired channels (Email, Push, or SMS), _select the recipients_. If the recipient is not on the list you can search by typing the name or the email.

If you need to deliver notifications to all members of current organization, choose **All members** in the dropdown.

Press **Apply** and you'll see the event status and channels updated

<figure><img src="../.gitbook/assets/8-notifications-update status 1.png" alt=""><figcaption></figcaption></figure>
