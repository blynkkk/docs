# Over-The-Air Firmware Updates (OTA)

OTA firmware updates are delivered using HTTP/HTTPS protocol.<br>

When new shipment is created in **Blynk.Air** it determines if device needs to be upgraded, then sends an upgrade URL to your devices.

You can get the OTA request by listening to the OTA internal pin:

```cpp
BLYNK_WRITE(InternalPinOTA) {
  String url = param.asString();
  Blynk.disconnect();
  // Procceed to download and apply the upgrade
}
```

The device may decide to wait for some time before downloading/applying the update. For example, there when important operations are in progress and the should not be interrupted by the update.

After device applies an update, it usually reboots with the new firmware, connects to the server, which in turn recognizes the new firmware version. This is considered to be a **successful OTA upgrade**.

Some devices may struggle to download the update (i.e. due to bad connectivity). Such devices will be marked as "**reached download limit**".

In some cases, your firmware may decide to rollback the upgrade. In this case, just reboot your device with the previous version. Server will recognize this pattern (i.e. `Old -> New -> Old` transition) and mark it as a **Rollback** in the logs.
