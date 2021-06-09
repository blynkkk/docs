# Trigger Event

## Get an Event code

1. Open Device Template
2. Switch to Events tab
3. Hover Code column across from Event name
4. Click "Copy Event Code" hint

## Publish events from device

Use `Blynk.logEvent` function to send events to the cloud.

```cpp
Blynk.logEvent("event_code");

// Also, you can add a custom description:
Blynk.logEvent("event_code", String("Temperature above threshold: ") + temp);
```

