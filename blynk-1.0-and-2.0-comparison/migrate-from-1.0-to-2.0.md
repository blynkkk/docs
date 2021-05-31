# Migrating to new Blynk

## Hardware migration

If you're using **Blynk library**, your code should be compatible with the new cloud. Some minor changes will be needed:

* Update Blynk library to the latest version \(v1.0+\)
* Add `BLYNK_TEMPLATE_ID` and `BLYNK_DEVICE_NAME` on top of your firmware
* Replace `Blynk.notify`, `Blynk.email`, `Blynk.tweet`, `Blynk.sms` with `Blynk.logEvent`
* Consider using **Blynk.Edgent** in your firmware for dynamic wifi credentials provisioning

## Account and projects migration

You will need to [create a new account](https://blynk.cloud/) and re-create new device templates.

