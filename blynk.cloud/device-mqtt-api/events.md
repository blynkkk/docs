# Events

## Publish Event

Publish topic **event/`EVENTCODE`**, payload: description in plain text

* `EVENTCODE` - the Event Code, as set in Event Settings

{% hint style="info" %}
To publish an event with the default description from event settings, just send an empty payload
{% endhint %}

```bash
mosquitto_pub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'event/temp_is_high' -n
mosquitto_pub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'event/measurement_error' -m 'Failed to measure temperature'
```
