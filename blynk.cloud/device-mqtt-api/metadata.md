# Metadata MQTT API

> [!IMPORTANT]
> Currently, metadata API works with fields of type `Text` and `Number` only.

## Set metadata value

Publish topic **meta/`NAME`**, payload: value in plain text (i.e. `123`, `hello` or `3.1415926`)

- `NAME` - the metadata name

## Request metadata value from Blynk

Subscribe to topic: **downlink/meta/`NAME`**

- `NAME` - the metadata name

> [!TIP]
> Usually, you'll want to subscribe to a widcard topic like **downlink/#**.

Publish topic **get/meta**, payload: metadata names separated by comma (i.e. `Ceiling Height,Room Volume`)
