# Authentication

## Blynk.Cloud MQTT Endpoints

* Broker: **`blynk.cloud`**
* TCP port: **`1883`**
* Secure SSL/TLS port: **`8883`**
* Secure WebSocket ports: **`443`, `9443`** (path must be **`/mqtt`**)

The broker will accept connections from `MQTT 3.1.1` and `MQTT 5` clients.

Please explore our [**sample projects**](https://github.com/Blynk-Technologies/Blynk-MQTT-Samples) for detailed examples.

{% hint style="info" %}
Due to **GeoDNS** configuration, the client **MUST** handle the [redirect message](authentication.md#server-redirect) to ensure proper operation under all network conditions.

Alternatively, the client can **connect to the regional server direcly** (in which case the redirection will not be needed):

* [fra1.blynk.cloud](https://fra1.blynk.cloud/) – Frankfurt
* [lon1.blynk.cloud](https://lon1.blynk.cloud/) – London
* [ny3.blynk.cloud](https://ny3.blynk.cloud/) – New York
* [sgp1.blynk.cloud](https://sgp1.blynk.cloud/) – Singapore
* [blr1.blynk.cloud](https://blr1.blynk.cloud/) – Bangalore

The server region can be found in the right bottom corner of the web interface.
{% endhint %}

## Authentication

MQTT client configuration:

* ClientID: `""` (or any UTF-8 encoded string, up to **64 characters** long)
* Username: `"device"`
* Password: `BLYNK_AUTH_TOKEN` (see [Device info](https://bit.ly/BlynkSimpleAuth))
* Keepalive: `45 seconds` (recommended)
* Clean Session: `True`

{% hint style="info" %}
For the initial MQTT API release, only **clean sessions** are supported. In particular, the client will not receive any undelivered QoS 1 messages that were queued for it while it was disconnected. The Blynk team is working on `Persistent Session` support.
{% endhint %}

The client should handle the Connect Return code appropriately; if you receive a `0x04 Connection Refused` response, it indicates a problem with your credentials.

## Subscribing to topics

Upon establishing a clean connection, the client should subscribe to downlink messages; otherwise, it will not receive any incoming messages.

It is standard practice to subscribe to all messages under this topic using a wildcard, such as `downlink/#`.

**OTA (Over-The-Air) Update**, **Server Redirect**, and **Server Diagnostic** messages represent notable exceptions. These messages can still be published and received by the client even if it has not subscribed to them. These messages are always published with QoS 0.

## Server Redirect

Blynk.Cloud uses GeoDNS to direct clients to the geographically closest server, which helps in **reducing latency, improving connection speed, and ensuring data reliability**.

Immediately after connection, the broker will decide if redirection is needed and publish `downlink/redirect` topic with a new endpoint in `URI` format (i.e. `mqtts://ny3.blynk.cloud:8883` or `wss://fra1.blynk.cloud:443/mqtt`).

Supported protocol prefixes are: `mqtt`, `mqtts`, `ws`, `wss`.

## Firmware and Device Info

On every clean connection, the device should publish a message to `info/mcu` topic:

```json
{
    "tmpl": "TMPLabcd1234",
    "ver": "0.1.2",
    "build": "Jan 19 2024 12:25:30",
    "type": "TMPLabcd1234",
    "rxbuff": 1024
}
```

* `tmpl` - Blynk Template ID (`BLYNK_TEMPLATE_ID`)
* `ver` - actual software/firmware version of the device
* `build` - actual software/firmware build time
* `type` - the type of firmware upgrade packages that the device accepts (in most cases, it matches `Blynk Template ID`)
* `rxbuff` - the MQTT rx buffer of the device in bytes (this limits the size of messages that the broker can send)

{% hint style="warning" %}
Sending info message is optional for the most simplistic use cases, however when using **Blynk.Air** (Managed OTA firmware updates) or **Blynk.Inject** (Dynamic Auth Token and network credentials provisioning), the client **MUST** send the info message to operate properly.
{% endhint %}

## Test connection

You can check connection using an [**online playground page**](https://bit.ly/Blynk-MQTT-Playground).

Also, you can connect using `mosquitto-clients`:

```sh
export BLYNK_AUTH_TOKEN="••••••••••••••••••••••••"

# Subscribe to all downlink messgaes
mosquitto_sub -L "mqtts://device:$BLYNK_AUTH_TOKEN@blynk.cloud/downlink/#" -F "%t: %p"

# Publish some data
mosquitto_pub -L "mqtts://device:$BLYNK_AUTH_TOKEN@blynk.cloud/ds/Temperature" -m "21.3"
```

{% hint style="info" %}
In most cases, you need to subscribe and publish messages using a single MQTT connection. It's not possible using `mosquitto_sub`/`mosquitto_pub`, but trivial when using MQTT API libraries. Please see [our examples](https://github.com/Blynk-Technologies/Blynk-MQTT-Samples).
{% endhint %}

## Limitations

* Only **clean sessions** are supported at the moment.
* Blynk.Cloud currently disallows **simultaneous connection** of multiple MQTT clients using **the same auth token**.
* The Device API client is restricted to subscribing only to sub-topics within `downlink/`. Only multi-level (`#`) wildcard at the end of the topic filter is supported, Blynk does not support single-level (`+`) wildcard at the moment.
* All MQTT messages are limited to **`1024` bytes** (including variable header and payload). This only affects the public MQTT service, the limit is adjustible for **White Label** or **Enterprise** customers.
* Ignoring or skipping the redirect may lead to an inability to exchange data with the server, resulting in the device being displayed as `Offline`.
