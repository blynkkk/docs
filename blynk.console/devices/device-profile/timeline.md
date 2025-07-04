---
description: >-
  This drawer shows a timeline of all device events, helping users monitor
  activity, identify issues, and collaborate with their team.
---

# Notifications & Events

> **Note:** This feature must be configured in the device template before use.
>
> 👉 [Learn more about setting up events in templates](https://docs.blynk.io/en/blynk.console/templates/events)

<figure><img src="../../../.gitbook/assets/device-timeline (1).png" alt=""><figcaption></figcaption></figure>

***

### Event Types

There are 5 types of events:

* **Critical** – Used for the most important events, such as system faults or critical errors.
* **Warning** – Alerts for important but less severe issues like filter replacements or anomalies.
* **Info** – Non-urgent informational messages, such as status updates.
* **Content** – Promotional or upselling messages, e.g., time to replace a battery.
* **User Note** – Manually added notes by users. Enterprise Plan users can also attach images.

***

### Filter and Search <a href="#filter-and-search" id="filter-and-search"></a>

By default, the timeline shows All events, sorted from the latest to earliest.

You can narrow down your view using:

#### **Filters**

* **Event Types & States** – Select one of 7 filters: Critical, Warning, Info, Content, User Note, Archived, Resolved. Each filter displays a counter badge showing the total number of events inside.
* **Time Range**:
  * 1 Day
  * 1 Week
  * 1 Month
  * Custom Range – Select a start and end date using the date picker.

#### **Search**

Use the Search field to look for events by:

* Name
* Short description
* Comments (including text inside a comment)

***

### How Are Events Logged?

Events can appear on the timeline via the following methods:

* Device-generated, using:
  * [Firmware API](https://docs.blynk.io/en/blynk-library-firmware-api/log-event)
  * [HTTP API](https://docs.blynk.io/en/blynk.cloud/device-https-api/trigger-events-api)
  * [MQTT API](https://docs.blynk.io/en/blynk.cloud-mqtt-api/device-mqtt-api/events)
* Log Event action type in user-created automations _(Only available in Web Console)_
* Manual entry, using the Add Note button

***

### Event Actions <a href="#event-actions" id="event-actions"></a>

Users with Edit Timeline permission can perform the following actions on events:

#### Comment

Leave a comment under an event — for example, to describe the resolution taken. Enterprise Plan users can also attach images in comments.

#### Resolve

Only available for Critical and Warning event types. Mark the event as resolved and add a resolution note. Resolved events move to the Resolved filter.

#### **Archive**

If enabled in[ event settings](https://docs.blynk.io/en/blynk.console/templates/events/custom-events/events-general-setting), users can archive an event to hide it from the main timeline. Archived events are still available via the Archived filter. Users can also unarchive an event to bring it back to the timeline.

***

### Notification Settings

By default, users receive notifications based on how the event was configured in the device’s template. However, users can customize these settings (if allowed) for specific events.

To access Notification Settings:

* Click the Notification Settings icon in the top-right corner of the Notifications & Events drawer.
* Or use the Device Actions menu on the device’s main page.

[👉 Learn more about Notification Settings](../notifications-settings.md)

