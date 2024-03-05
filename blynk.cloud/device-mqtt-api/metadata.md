# Metadata MQTT API

## Set metadata value

Publish topic **meta/`NAME`**, payload: value in plain text (i.e. `123`, `hello` or `3.1415926`)

- `NAME` - the metadata name

The device can set the value of such field types:

- `Device EUI`
- `Hotspot Name`
- `ICCID`
- `IMEI`
- `Int`
- `Number`
- `Table`
- `Text`
- `Timezone`

## Request metadata value from Blynk

Subscribe to topic: **downlink/meta/`NAME`** (or to a widcard topic like **downlink/meta/#**)

- `NAME` - the metadata name

Publish topic **get/meta**, payload: metadata names separated by comma (i.e. `Ceiling Height,Room Volume`)

The device can request the value of such field types:

- `Contact`
- `Device EUI`
- `Device Name`
- `Device Owner`
- `Device Reference`
- `Email`
- `Hotspot Name`
- `ICCID`
- `Image`
- `IMEI`
- `Int`
- `List`
- `Location`
- `Number`
- `Switch`
- `Table`
- `Text`
- `Timezone`

