# OTA

## OTA package notification

To indicate it's current software/firmware version, the device publishes [`Firmware and Device Info`](authentication.md#firmware-and-device-info) message. The server then evaluates whether an update is necessary and, if so, publishes a message on the **downlink/ota/json** topic:

```json
{
    "url": "https://blynk.cloud/static/file.tar.gz?token=jOuWQWu_bOANvBPzz4LllPDMk7sYAAQMa",
    "size": 20082,
    "type": "TMPLabcd1234",
    "ver": "0.5.0",
    "build": "Mar 05 2024 18:29:27"
}
```

{% hint style="info" %}
This message can also be delivered at any time during the device operation, i.e. when Blynk.Air shipment is created or when the `Preferred Time` condition is met.
{% endhint %}

The device must verify whether the update is feasible and then download the OTA package using `HTTP`/`HTTPS`. Additionally, the HTTP Response Headers provide valuable information:

* `x-sha256` - Base64-encoded SHA256 digest of the OTA package
* `x-md5`- HEX-encoded MD5 digest of the OTA package
* `x-fw-type` - The firmware type
* `x-fw-ver` - The firmware version string
* `x-fw-build` - The firmware build time

{% hint style="info" %}
`type`, `ver`, `build` fields are available only if Blynk.Cloud can extract this information (stored as a binary info tag) from the uploaded OTA package file.
{% endhint %}

After installing the update, the device re-connects to Blynk.Cloud and publishes the updated [`Firmware and Device Info`](authentication.md#firmware-and-device-info) message.

```bash
mosquitto_sub -h blynk.cloud -p 8883 -u device -P '{DEVICE_TOKEN}' -t 'downlink/ota/json'
```

## Blynk binary info tag

The Blynk Cloud identifies the firmware binary by looking for a special tag embedded in it. The firmware tag contains some metadata in the form of key-value pairs. This is how one can include such a tag in the C code:

```C
#define BLYNK_PARAM_KV(k, v)    k "\0" v "\0"

volatile const char firmwareTag[] = "blnkinf\0"
    BLYNK_PARAM_KV("mcu"    , BLYNK_FIRMWARE_VERSION)       // Primary MCU: firmware version
    BLYNK_PARAM_KV("fw-type", BLYNK_FIRMWARE_TYPE)          // Firmware type (usually same as Template ID)
    BLYNK_PARAM_KV("build"  , __DATE__ " " __TIME__)        // Firmware build date and time
    BLYNK_PARAM_KV("blynk"  , BLYNK_RPC_LIB_VERSION)        // Version of the NCP driver library
    "\0";
```

> [!IMPORTANT]
> If your OTA process involves encrypting, compressing, re-packaging (or altering the raw firmware binary in any other way), you should add the equivalent tag to your final OTA package. Blynk provides a [`blynk_tag.py extract`](https://github.com/Blynk-Technologies/Blynk-NCP-Example-Arduino/blob/main/tools/blynk_tag.py) tool to automate this process.

### Alternative OTA package generation procedure

If for some reason you cannot embed the binary tag as suggested above, here is the alternative approach:

1. Move definitions of `BLYNK_FIRMWARE_VERSION`, `BLYNK_FIRMWARE_TYPE`, `BLYNK_RPC_LIB_VERSION` to your build system
2. Instead of using the `__DATE__`, `__TIME__` directly, add new definition of `BLYNK_FIRMWARE_BUILD_TIME` to your build system. It should follow the `Nov 16 2023 20:35:55` format
3. Ensure that exactly the same info is passed to [`Firmware and Device Info`](authentication.md#firmware-and-device-info) message
4. On your build system level, use [`blynk_tag.py create`](https://github.com/Blynk-Technologies/Blynk-NCP-Example-Arduino/blob/main/tools/blynk_tag.py) tool to create a tag that you can embed into your OTA package
