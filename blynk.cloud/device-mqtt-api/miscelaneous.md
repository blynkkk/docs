# Miscelaneous MQTT API

> [!TIP]
> Usually, you'll want to subscribe to a widcard topic like **downlink/#**.

## Reboot Device

Reboot can be triggered using `Device Menu -> Reboot`.

You will get a message on **downlink/reboot** topic, with an empty payload

## Ping Device

This feature is activated using `Device Menu -> Ping`.

The server will send the MQTT-level `PINGREQ` and wait for `PINGRESP`.

## Last Will and Testament

Upon connection, the client can specifiy the Last Will message along with the topic to which it should be published.
If the client loses connection **without sending a proper disconnect message**, the broker will publish this pre-determined Last Will message.

