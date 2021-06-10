# How to Trigger Events

If you need to create an Event when the sensor detects temperature which is over a certain threshold:

1. Create a new Event named `High temperature` with code `high_temp` 

2. Use the `Blynk.logEvent(event_code)` firmware API command to trigger new event occurrence 

A simple example could look like:

```cpp
if (temperature > 35)
{
   Blynk.logEvent("high_temp");
}
```

You can add extra information to the description of the event. If you endabled Timeline recording, description will be shown there

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

