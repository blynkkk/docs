# Blynk.Air MQTT API

## OTA package notification

To indicate it's current software/firmware version, the device publishes [`Firmware and Device Info`](authentication.md#firmware-and-device-info) message.
The server then evaluates whether an update is necessary and, if so, publishes a message on the **downlink/ota/json** topic:

```json
{
    "url":"https://blynk.cloud/static/file.tar.gz?token=jOuWQWu_bOANvBPzz4LllPDMk7sYAAQMa",
    "size":2082,
    "type":"TMPL87mTr-1PZ",
    "ver":"0.5.0",
    "build":"Mar 05 2024 18:29:27"
}
```

> [!IMPORTANT]
> This message can also be delivered at any time during the device operation, i.e. when Blynk.Air shipment is created
> or when the `Preferred Time` condition is met.

The device must verify whether the update is feasible and then download the OTA package using `HTTP`/`HTTPS`.
Additionally, the HTTP Response Headers provide valuable information:

- `x-sha256` - Base64-encoded SHA256 digest of the OTA package
- `x-md5`- HEX-encoded MD5 digest of the OTA package
- `x-fw-type` - The firmware type
- `x-fw-ver` - The firmware version string
- `x-fw-build` - The firmware build time

> [!NOTE]
> `type`, `ver`, `build` fields are available only if Blynk.Cloud can extract this information (stored as a binary info tag) from the uploaded OTA package file.

After installing the update, the device re-connects to Blynk.Cloud and publishes the updated [`Firmware and Device Info`](authentication.md#firmware-and-device-info) message.
