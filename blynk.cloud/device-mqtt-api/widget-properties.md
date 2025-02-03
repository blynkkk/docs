# Widget Properties

## Set Widget Property

Publish topic **ds/`DATASTREAM`/prop/`PROPERTY`**, payload: value in plain text (i.e. `123`, `hello`)

* `DATASTREAM` - the datastream name
* `PROPERTY` - the [property name](../../blynk.edgent-firmware-api/widget-properties.md)

{% hint style="info" %}
For multivalue (array-like) values, the individual items in the payload are separated using a `0x00` byte, i.e: `First\u0000Second\u0000Third`. The separator is a `NUL` character, that is also represented as `\u0000` in Unicode.
{% endhint %}

```bash
mosquitto_pub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'ds/Temperature/prop/color' -m 'red'
```

## Erase Widget Property

Publish topic **ds/`DATASTREAM`/prop/`PROPERTY`/erase**, payload: empty

* `DATASTREAM` - the datastream name
* `PROPERTY` - the property name

```bash
mosquitto_pub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'ds/Temperature/prop/color/erase' -n
```
