---
description: How to log an event using firmware API
---

# Log Event

## Get an Event code

1. Go to Device Template -> Events
2. Find the Event Code. Edit it if needed
3. Copy it to use in the firmware code below:

## Log Events from the device

Use `Blynk.logEvent` command to log events to the Blynk cloud.

```cpp
Blynk.logEvent("event_code");

// Also, you can add a custom description:
Blynk.logEvent("event_code", String("Temperature above threshold: ") + temp);
```

{% hint style="info" %}
The maximum allowed length of the description is 300 chars.

Messages with description that exceeds the 300 chars limit will be discarded.
{% endhint %}
