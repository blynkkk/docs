# Migrating to new Blynk

## Hardware migration

If you're using **Blynk library**, your code should be compatible with the new cloud. Some minor changes will be needed:

* Update Blynk library to the latest version \(v1.0+\)
* Add `BLYNK_TEMPLATE_ID` and `BLYNK_DEVICE_NAME` on top of your firmware, **above any includes**
* Replace `Blynk.notify`, `Blynk.email`, `Blynk.tweet`, `Blynk.sms` with `Blynk.logEvent`. Read [this guide](../blynk.apps/notifications.md) on how to set up Events with notifications
* Adjust indexing for `Image Gallery`, `Menu`,  `Icon`, `Segmented Switch`, `Icon Segmented Switch` widgets. It used to start with 1, but in new Blynk it starts from the `min` value of the associated DataStream
* Consider using **Blynk.Edgent** in your firmware for dynamic WiFi credentials provisioning

If you're using **HTTP API**, you need to update your server and request URLs.

## Account and projects migration

You will need to [create a new account](https://blynk.cloud/) and re-create new device templates.

