---
description: How to log an event using firmware API
---

# Log Event

## Get an Event code

1. Go to Device Template -&gt; Events
2. Find Event Code. Edit it if needed
3. Copy it to use in the firmware code below:

## Log Events from device

Use `Blynk.logEvent` command to log events to the Blynk cloud.

```cpp
Blynk.logEvent("event_code");

// Also, you can add a custom description:
Blynk.logEvent("event_code", String("Temperature above threshold: ") + temp);
```

