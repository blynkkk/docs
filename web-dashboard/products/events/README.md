---
description: >-
  Events tell the current status of the device on the List of Devices, Device
  Page itself, and also shows the history of states change in the Timeline
  section.
---

# Events

Let’s look at a typical use case: read temperature from DHT sensor and send push notification when the temperature is over a certain limit:

```text
  float t = dht.readTemperature();
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

