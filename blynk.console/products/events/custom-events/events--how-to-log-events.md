# How to Log Events

If you need to log an Event when the sensor detects temperature over a certain threshold:

1. Create a new Event named `High temperature` with code `high_temp` 

2. Use the `Blynk.logEvent(event_code)` firmware API command to trigger new event occurrence 

A simple example could look like:

```cpp
if (temperature > 35)
{
   Blynk.logEvent("high_temp");
}
```

When this code worked, an Event will be logged and system will act accordingly to the Event setup \(render on timeline, send notifications, etc.\)

You can add extra information to the description of the event. If you endabled [Timeline recording](https://docs.blynk.io/en/blynk.console/products/events/general#show-event-on-the-timeline), description will be shown there.

```cpp
if (temperature > 35)
{
  Blynk.logEvent("event_code", String("High TemperatureDetected! Tº: ") + temp);
}
```



Trigger an event using HTTPS API: 

```text
/external/api/logEvent?token={device_token}&code={event_code}&description={event_desciption}
```

`description` is an optional parameter where you can attach additional information to be rendered on the Timeline along with the event.

For example:

```text
https://my.server.com/external/api/logEvent?token=Q9qdlGahPuFuCfncrT35QutT7s3HjYFy&code=high_temp
```

