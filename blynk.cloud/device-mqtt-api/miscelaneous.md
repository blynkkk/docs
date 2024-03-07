# Miscelaneous MQTT API

{% hint style="success" %}
Usually, you'll want to subscribe to a widcard topic like **downlink/#**.
{% endhint %}

## Reboot Device

Reboot can be triggered using `Device Menu -> Reboot`.

You will get a message on **downlink/reboot** topic, with an empty payload

## Ping Device

This feature is activated using `Device Menu -> Ping`.

The server will publish **downlink/ping** topic, with an empty payload.
In response, the clinet should publish **pong** topic, with an empty payload.

{% hint style="warning" %}
Ignoring or skipping the ping message will result in warnings displayed in the web dashboard, when this function is used.
{% endhint %}

## Last Will and Testament

Upon connection, the client can specifiy the Last Will message along with the topic to which it should be published.
If the client loses connection **without sending a proper MQTT `DISCONNECT` message**, the broker will publish this pre-determined Last Will message.

## Server Diagnostics

The server has the capability to publish messages under the **downlink/diag** topic under certain circumstances,
typically when it detects potentially problematic behavior from the client.
These diagnostic messages are designed to be observed and addressed by developers.

