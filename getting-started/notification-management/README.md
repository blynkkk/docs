---
description: How to set up notifications for a single device or for a selection of devices.
---

# Send Notifications (Alerts)

Getting notifications when certain event happens is a crucial part of any IoT solution. Blynk offers a simple way to set up these events and manage notifications.



On a high level, there are 2 ways to send notifications:

1. Use Automations to send notifications from Blynk.Cloud (no code)
2. Send notifications from hardware

{% content-ref url="use-automations-to-send-notifications-no-code.md" %}
[use-automations-to-send-notifications-no-code.md](use-automations-to-send-notifications-no-code.md)
{% endcontent-ref %}



{% hint style="info" %}
Note: notifications work as part of [Events](../../blynk.console/templates/events/). Before moving forward:

1. Make sure your template has at least one Event configured
2. Make sure that [Notifications are enabled](../../blynk.console/templates/events/custom-events/events-notification-settings.md) for this Event
{% endhint %}

## Setting notifications for multiple devices

1. Open [Search](../../blynk.console/search-data.md)
2. Go to [Devices](../../blynk.console/devices/) filters
3. Select multiple devices (1)
4. Hover over the **Actions menu \[...]** (2)
5. Click **Notification Settings** (3)

![](https://user-images.githubusercontent.com/72824404/119673690-3ae3e700-be44-11eb-86e0-147f6a22b977.png)

In the opened drawer select the desired events to edit (4) -> **Edit Settings** (5)

![](https://user-images.githubusercontent.com/72824404/119675163-79c66c80-be45-11eb-93d1-71f02150a0b0.png)

{% hint style="warning" %}
If the list of events is empty or you don't see the **Edit Settings** button, make sure that [Notifications are enabled](../../blynk.console/templates/events/custom-events/events-notification-settings.md) for this Event in the Device Template
{% endhint %}

![](https://user-images.githubusercontent.com/72824404/119676364-797aa100-be46-11eb-98e6-c8a4a16ae06e.png)

In the modal window turn on the desired channels (Email, Push, or SMS), _select the recipients_. If the recipient is not on the list you can search by typing the name or the email.

If you need to deliver notifications to all members of current organization, choose **All members** in the dropdown.

Press **Apply** and you'll see the event status and channels updated

![](https://user-images.githubusercontent.com/72824404/119677034-0887b900-be47-11eb-8a2d-638bcc35c38f.png)
