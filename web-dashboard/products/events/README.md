# Events

Events are used to track and log important events happening on your devices. Events can also trigger different types of notifications which can be sent over email, delivered as push notifications to user's smartphone, or sent as an SMS.

Examples of an Event: 

1. _You need to log a moment when a temperature reached a certain threshold and send a notification to selected users._
2. _You need to log a total working hours of the device. If it approaches or goes beyond a max value, you would need to notify technical support so that they can replace the device._ 

Events that happened can be viewed on the device dashboard in web and mobile apps in the [Timeline](../../devices/device-profile/timeline.md).

Let’s look at a typical use case: read temperature from DHT sensor and send push notification when the temperature is over a certain limit:

```cpp
  float t = dht.readTemperature();//reading the temperature from the sensor
  
  if (isnan(t)) {
    return;
  }
  if (t > 40) {
    Blynk.logEvent("temp_warning", String("Temperature is too high: ") + t);
  }
```

Once server has received this string it can be viewed in Device Timeline.

## Events: Online, Offline

Online and Offline events are default system events handled by the server.

You can set up your devices to ignore offline state period in `Product` -&gt; `General` - &gt; `Offline Ignore Period`.

User should be logged in to account to get these notifications.

