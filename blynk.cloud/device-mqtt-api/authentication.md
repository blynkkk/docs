# MQTT Client Connection and Authentication

## Blynk.Cloud MQTT Endpoints

- Broker:                 **`blynk.cloud`**
- TCP port:               **`1883`**
- Secure SSL/TLS port:    **`8883`**
- Secure WebSocket ports: **`443`, `9443`** (path must be **`/mqtt`**)

The broker will accept connections from `MQTTv3.1.1` and `MQTTv5.0` clients.

## Authentication

MQTT client configuration:

- ClientID: `""`
- Username: `"device"`
- Password: your `BLYNK_AUTH_TOKEN`
- Keepalive: `45 seconds` (recommended)

The client should handle the Connect Return code appropriately; if you receive
a `0x04 Connection Refused` response, it indicates a problem with your credentials.

{% hint style="info" %}
You can get the **Device auth token** in [Device info](../../getting-started/activating-devices/manual-device-activation.md#step-3-getting-auth-token).
{% endhint %}

> [!IMPORTANT]
> Blynk.Cloud currently disallows simultaneous connection of multiple MQTT clients using the same auth token.

Upon connection, the client should subscribe to downlink messages (i.e. `downlink/#` topic).

## Server Redirect

Blynk.Cloud uses GeoDNS to direct clients to the geographically closest server,
which helps in **reducing latency, improving connection speed, and ensuring data reliability**.

Immediately after connection, the broker will decide if redirection is needed
and publish `downlink/redirect` topic with a new endpoint in `host:port` format (i.e. `ny3.blynk.cloud:8883`).

## Firmware and Device Info

On every clean connection, the device should publish a message to `info/mcu` topic:

```json
{
    "tmpl":"TMPLabcd1234",
    "ver":"0.1.2",
    "build":"Jan 19 2024 12:25:30",
    "type":"TMPLabcd1234",
    "rxbuff":1024
}
```

- `tmpl`   - Blynk Template ID (`BLYNK_TEMPLATE_ID`)
- `ver`    - actual software/firmware version of the device
- `build`  - actual software/firmware build time
- `type`   - the type of firmware upgrade packages that the device accepts (in most cases, it matches `Blynk Template ID`)
- `rxbuff` - the MQTT rx buffer of the device in bytes (this limits the size of messages that the broker can send)

While not strictly required, it enables some important functions of Blynk.Cloud, like **Blynk.Air** (Managed OTA firmware updates) and **Blynk.Inject** (Dynamic Auth Token and network credentials provisioning)
