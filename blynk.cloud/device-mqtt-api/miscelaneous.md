# Miscelaneous

{% hint style="success" %}
Usually, you'll want to subscribe to a widcard topic like **downlink/#**.
{% endhint %}

## Reboot Device

Reboot can be triggered using `Device Menu -> Reboot`.

You will get a message on **downlink/reboot** topic, with an empty payload.

```bash
mosquitto_sub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'downlink/reboot'
```

## Ping Device

This feature is activated using `Device Menu -> Ping`.

The server publishes **downlink/ping** topic, with `QOS 1` and an empty payload. Subsequently, the client should automatically respond with an MQTT `PUBACK` packet, in accordance with the MQTT standard.

```bash
mosquitto_sub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'downlink/ping'
```

## Reconfigure Device

This feature is activated using a `Device -> Info Icon -> Three dots -> Reconfigure` button in the mobile application (see the [Mobile App Device Actions menu section](../../blynk.apps/overview.md#device-actions-menu)).

The server publishes the downlink/reconfigure topic with an empty payload. Subsequently, the device should enter the Wi-Fi configuration stage, by broadcasting a Wi-Fi Access Point and asking the user to enter the new Wi-Fi network credentials.

```bash
mosquitto_sub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'downlink/reconfigure'
```

## Last Will and Testament

Upon connection, the client can specifiy the Last Will message along with the topic to which it should be published. If the client loses connection **without sending a proper MQTT `DISCONNECT` message**, the broker will publish this pre-determined Last Will message.

## Server Diagnostics

The server has the capability to publish messages under the **downlink/diag** topic under certain circumstances, typically when it detects potentially problematic behavior from the client. These diagnostic messages are designed to be observed and addressed by developers.

```bash
mosquitto_sub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'downlink/diag'
```
