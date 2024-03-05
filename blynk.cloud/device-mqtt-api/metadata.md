# Metadata MQTT API

## Set metadata value

Publish topic **meta/`NAME`**, payload: value in plain text (i.e. `123`, `hello` or `3.1415926`)

- `NAME` - the metadata name

> [!IMPORTANT]
> Currently, the Device can only set fields of specific types:
> `Text`, `Number`

## Request metadata value from Blynk

Subscribe to topic: **downlink/meta/`NAME`** (or to a widcard topic like **downlink/meta/#**)

- `NAME` - the metadata name

Publish topic **get/meta**, payload: metadata names separated by comma (i.e. `Ceiling Height,Room Volume`)

> [!IMPORTANT]
> Currently, the Device can only request fields of specific types:
> `Text`, `Number`

