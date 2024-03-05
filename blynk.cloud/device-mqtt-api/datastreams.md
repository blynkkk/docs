# Datastreams MQTT API

Blynk.Cloud MQTT API uses Names to reference Datastreams.

> [!WARNING]
> Changing datastream names in the template settings can make your existing devices misbehave.
> If this happens, you can either revert your changes or update your device firmware Over the Air
> to conform to the new datastream structure.

## Send data to Blynk

Publish topic **ds/`DATASTREAM`**, payload: value in plain text (i.e. `123`, `hello` or `3.1415926`)

- `DATASTREAM` - the datastream name

> [!NOTE]
> For multivalue (array-like) values, the individual items in the payload are separated using a `0x00` byte, i.e: `First\u0000Second\u0000Third`.
> The separator is a `NUL` character, that is also represented as `\u0000` in Unicode.

## Get data updates from Blynk

Subscribe to topic: **downlink/ds/`DATASTREAM`**

- `DATASTREAM` - the datastream name

> [!TIP]
> Usually, you'll want to subscribe to a widcard topic like **downlink/#** or **downlink/ds/#**.

## Request the latest value from Blynk

Publish topic **get/ds**, payload: datastream names separated by comma (i.e. `Brightness,Color`)

## Request current values for all datastreams

Publish topic **get/ds/all**, payload: empty

> [!IMPORTANT]
> For this to work, open `Datastream settings` and enable `Advanced Settings -> Sync with latest server value`.
