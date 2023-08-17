# Hotspot Prefix

It's used as part of SSID when the device works as WiFi access point or Bluetooth peripheral during the provisioning process. By default, the device uses the "Blynk" prefix.

**Attention!** Only modify this setting if you're using a branded Blynk App.

Follow these steps to set:

* select the Product, open Info tab and copy it's Hotspot Prefix;
* in your firmware, define `CONFIG_DEVICE_PREFIX` to use the same Hotspot Prefix from the previous step;

Max length - 20 characters. Only letters, digits and spaces are allowed.
