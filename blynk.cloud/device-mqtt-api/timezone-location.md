# Device Timezone/Location MQTT API

{% hint style="success" %}
Usually, you'll want to subscribe to a widcard topic like **downlink/#**.
{% endhint %}

## Request the Device Time and Timezone from Blynk

Publish topic **get/utc/all/json**, payload: empty

You will get a message on **downlink/utc/all/json** topic, with JSON-encoded payload:

```json
{
    "tz_name": "America/Goose_Bay",
    "tz_rule": "AST4ADT,M3.2.0,M11.1.0",
    "tz_offset": -240,
    "dst_offset": 0,
    "time": 1709326077759,
    "iso8601": "2024-03-01T16:47:57-04:00"
}
```

- `tz_name`: The time zone name. It typically follows the "Area/Location" format used by the IANA Time Zone Database.
- `tz_rule`: Rules for Daylight Saving Time (DST) changes, following the POSIX TZ format.
- `tz_offset`: The time offset from UTC in minutes for the standard time (not accounting for daylight saving time).
- `dst_offset`: An additional offset in minutes applied during Daylight Saving Time. If DST is not in effect, this would be 0.
- `time`: The current time as a UNIX timestamp in milliseconds.
- `iso8601`: The current time formatted according to the ISO 8601 standard, which combines date and time into a single string, appended with the time zone offset from UTC.

{% hint style="info" %}
All values, except for time (which is in UTC), are dependent on the device location.
Blynk.Cloud determines the device's timezone based on the available location information, in the following order:
1. The [Location](../../blynk.console/locations/locations.md) assigned to device
2. Device [Timezone Metadata](../../blynk.console/templates/metadata/README.md#basic-metadata-types)
3. Device [Organization Timezone](../../blynk.console/settings/organization-settings/general.md)
4. If none of the above is configured, `UTC` time is used
{% endhint %}

## Request an approximate device location

Publish topic **get/loc/all**, payload: empty

You will get a message on **downlink/loc/all** topic, with Lat Lon GPS coordinates separaed by comma.

{% hint style="info" %}
The actual coordinates value depends on multiple factors, i.e:
1. The [Location](../../blynk.console/locations/locations.md) assigned to device
2. Network address of device
{% endhint %}
