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
Maximum allowed length of the description is 300 chars.

Messages with description that exceeds 300 cahrs limit will be discarded.
{% endhint %}

## Resolve Events from the device

```cpp
Blynk.resolveEvent("event_code");      // Resolve the latest reported event with the given code

Blynk.resolveAllEvents("event_code");  // Resolves last 10 reported events with the given code
```

{% hint style="info" %}
You're allowed to call resolve/resolveAll command only once every 15 minutes.
{% endhint %}
