# How to Send/Log Events

## Send events using Firmware API



If you need to log an Event when the sensor detects temperature over a certain threshold:

1. Create a new Event named `High temperature` with code `high_temp`
2. Use the `Blynk.logEvent(event_code)` firmware API command to trigger new event

```cpp
if (temperature > 35)
{
   Blynk.logEvent("high_temp");
}
```

When this code worked, an Event will be logged and the system will act accordingly to the Event setup (render on timeline, send notifications, etc.)



### Custom Event Description

You can change the description of the event when it's rendered on the timeline in Blynk.Console and in Blynk.Apps.&#x20;

```cpp
if (temperature > 35)
{
  Blynk.logEvent("event_code", String("High TemperatureDetected! Tº: ") + temp);
}
```

{% hint style="warning" %}
Make sure you enabled [Timeline recording](events-general-setting.md#show-event-on-the-timeline) in the Event Settings to see the result in the apps
{% endhint %}



## Send events using HTTPS API

To log an event use this request

```
`/external/api/logEvent?token={AuthToken}&code={event_code}
```

```
`/external/api/logEvent?token={token}&code={event_code}&description={event_description}
```

```
/external/api/logEvent?token={device_token}&code={event_code}&description={event_desciption}
```

`description` is an optional parameter where you can attach additional information to be rendered on the Timeline along with the event.

For example:

```
https://my.server.com/external/api/logEvent?token=Q9qdlGahPuFuCfncrT35QutT7s3HjYFy&code=high_temp
```
