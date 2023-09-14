---
description: This tutorial will help you with creating Events in Device Templates
---

# Events

Getting Started -> Events



Events are used to track, log, and work with important events that happen on the device.&#x20;

Events are also used for notifications which can be sent over email, delivered as push notifications to user's smartphone, or sent as an SMS.

Events are pre-configured in Blynk.Console and can be triggered with a [Events Firmware API](../blynk-library-firmware-api/log-event.md) from device or using [Events HTTP API](../blynk.cloud/device-https-api/trigger-events-api.md).

_Examples of an Event:_

* _Log a moment when a temperature reached a certain threshold and send a notification to selected users_
* _Track total working hours of the device. If it approaches or goes beyond a max value, you would need to notify technical support so that they can replace the device or provide warranty service_



![Events list in the template](../.gitbook/assets/events.png)



## Types of Events

There are three types of Events in Blynk:&#x20;

* **System Events:** Default Blynk platform events.&#x20;
* **Custom Events:** Events you can create and configure for your needs
* **Content Events:** Informative events that are shown separately in the app

### System Events

You can't delete the system events, but you can configure them.

#### Online/Offline status

This event is used to track when devices goes online and offline.

In some cases you would need to ignore offline state for a certain period of time. For example, if your device is mostly offline (or in deep sleep) and only wakes up every hour to send the data.



#### Firmware Over-The-Air Update status

This is a system event to track firmware update. It can't be configured



### Custom Events

These are Events you can configure based on what your device do. Read these articles to start logging events and sending notifications:&#x20;

* [**Event Settings**](../blynk.console/templates/events/custom-events/events-general-setting.md)
* [**How to send custom events fom hardware using Firmware API and HTTPS API**](../blynk.console/templates/events/custom-events/events--how-to-log-events.md)&#x20;
* [**Content Events**](../blynk.console/templates/events/custom-events/events-content-events.md)



## How to log an event in Blynk

### 1. [Create a Template](template-quick-setup/) or use an existing one

### 2. Create a New Event

Go to Template -> Edit -> Events tab.



![](../.gitbook/assets/default\_events.png)



1. Click **Add New Event**
2. Name the first event with the name Hello
3. Click **Create** (the event will appear in the Events tab list)
4. Repeat the previous step for the second event with the name Error
5. Click **Save** to save and apply the changes made (select Update active device this time)

{% hint style="info" %}
Note that each event has`EVENT_CODE`. This event code will be used in firmware API or HTTPS API
{% endhint %}

![](../.gitbook/assets/2\_new\_events.png)

### Send Events Using Firmware API

1. Create a new Event named `High temperature` with code `high_temp`
2. Use the `Blynk.logEvent(event_code)` firmware API command to trigger new event

```cpp
if (temperature > 35)
{
   Blynk.logEvent("high_temp");
}
```

When this code worked, an Event will be logged and the system will act accordingly to the Event setup (render on timeline, send notifications, etc.)

{% hint style="warning" %}
Avoid logging an event too many times not to hit daily limits. You can use timers or flags to mark the already sent events. Check this [article](how-to-display-any-sensor-data-in-blynk-app.md) on how to avoid spamming the server with events
{% endhint %}



#### Custom Event Description

You can change the description of the event when it's rendered on the timeline in Blynk.Console and in Blynk.Apps. For example, you can include the current data

```cpp
if (temperature > 35)
{
  Blynk.logEvent("event_code", String("High TemperatureDetected! Tº: ") + temp);
}
```

{% hint style="warning" %}
Make sure you enabled [Timeline recording](../blynk.console/templates/events/custom-events/events-general-setting.md#show-event-on-the-timeline) in the Event Settings to see the result in the apps
{% endhint %}



### Send Events Using HTTPS API

To log an event use GET request:&#x20;

```
`/external/api/logEvent?token={AuthToken}&code={event_code}
```



To add custom description to the event, use this GET request

```html
`/external/api/logEvent?token={AuthToken}&code={event_code}&description={event_description}
```



Example:

```
https://blynk.cloud/external/api/logEvent?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&code=firmware_update&description=test
```

##

## 3. Sending Events

You can test the Event creation by sending it from Device using Blynk.Edgent firmware API, or with REST API.

### Use Blynk.logEvent() firmware API

`Blynk.logEvent("event_code", "optional message");`

For this tutorial you would need to use hello as a name. Here is a pseudo code:

```cpp
if (some_condition){
    Blynk.logEvent("hello");
}
```

Optionally, you can send a custom description with the event. This description will be rendered on Device Timeline.

```cpp
if (some_condition){
    Blynk.logEvent("hello", "Hello World,") ;
}
```

### Use HTTP REST API

1. Navigate to the Device
2. Click on its name
3. Open Device Info tab
4. Find Auth Token there and click on the icon to copy it to the clipboard

![Device Info tab](../.gitbook/assets/event\_device\_info.png)

![Auth Token. Click copy pictogram here](../.gitbook/assets/single\_auth\_token.png)

Now make an HTTP request with the tools you use for that. Make sure to change the `YourAuthToken` to the one you copied in the previous step.

You can even use your browser for that. Just put it in the URL field and press Enter.

```http
https://blynk.cloud/external/api/logEvent?token=YourAuthToken&code=hello
```

Repeat the same with `code=error`

```http
https://blynk.cloud/external/api/logEvent?token=YourAuthToken&code=error
```

## 4. Checking if Event was logged.

First of all, check [Device Timeline](../blynk.console/devices/device-profile/timeline.md) by going to Device - > Timeline Tab

![](../.gitbook/assets/events\_on\_timeline.png)

You should see 2 events on the timeline! If you set up notifications, they should have been delivered as well.

## Limitations

* You can send only 100 events per devices per day (Adjustable in Business Plan)
* When the limit is reached you'll see the notification on the UI in the Device Timeline section
* The maximum description length for the event is 300 characters

