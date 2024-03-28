# Metadata MQTT API

## Set metadata value

Publish topic **meta/`NAME`**, payload: value in plain text (i.e. `123`, `hello` or `3.1415926`)

- `NAME` - the metadata name

The device can set the value of such field types:

- System fields
  - `Hotspot Name`
  - `Time Zone` - no validation of input!
- Custom fields
  - `Text`
  - `Number`
  - `Table`
  - `IMEI`
  - `ICCID`

## Request metadata value from Blynk

Subscribe to topic: **downlink/meta/`NAME`** (or to a widcard topic like **downlink/meta/#**)

- `NAME` - the metadata name

Publish topic **get/meta**, payload: metadata names separated by comma (i.e. `Ceiling Height,Room Volume`)

The device can request the value of such field types:

- System fields
  - `Device Name`
  - `Device Owner` (owner's email)
  - `Hotspot Name`
  - `Location` - doesn't work
  - `Time Zone`
- Custom fields
  - `Text`
  - `Number`
  - `Contact`
  - `Switch`
  - `Device Reference` - works but not insightful (returns Device ID)
  - `List`
  - `Table`
  - `IMEI`
  - `ICCID`

