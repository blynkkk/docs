# Metadata

## Set metadata value

Publish topic **meta/`NAME`**, payload: value in plain text (i.e. `123`, `hello` or `3.1415926`)

* `NAME` - the metadata name

The device can set the value of such field types:

* System fields
  * `Hotspot Name`
  * `Time Zone` - no validation of input!
* Custom fields
  * `Text`
  * `Number`
  * `Table`
  * `IMEI`
  * `ICCID`

```bash
mosquitto_pub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'meta/Serial Number' -m '12345'
```

## Subscribe to metadata updates

Subscribe to topic: **downlink/meta/`NAME`** (or to a wildcard topic like **downlink/meta/#**)

* `NAME` - the metadata name

```bash
mosquitto_sub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'downlink/meta/Device Name'
```

## Request metadata value from Blynk

Subscribe to topic: **downlink/meta/`NAME`** (or to a widcard topic like **downlink/meta/#**)

* `NAME` - the metadata name

Publish topic **get/meta**, payload: metadata names separated by comma (i.e. `Ceiling Height,Room Volume`)

```bash
mosquitto_pub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'get/meta' -m 'Serial Number,Time Zone'
```

## Supported Metadata types

The device can request the value of such field types:

* System fields
  * `Device Name`
  * `Device Owner` (owner's email)
  * `Hotspot Name`
  * `Location`
  * `Time Zone`
* Custom fields
  * `Text`
  * `Number`
  * `Contact`
  * `Switch`
  * `Device Reference` - works but not insightful (returns Device ID)
  * `List`
  * `Table`
  * `IMEI`
  * `ICCID`
  * `Email`
  * `Image`
  * `Device EUI`
  * `Join EUI`
  * `Application Key`&#x20;
  * `Blues Device`
  * `Myriota Terminal ID`
  * `TheThingsNetwork Device ID`
  * `Thing Name`&#x20;

