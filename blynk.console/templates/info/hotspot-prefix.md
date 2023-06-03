# Hotspot Prefix

It's used as SSID when the device works as WiFi access point during the Provision  .\
Use this field to give a name to the future access point.\
\
Follow these steps to set:

* select the Product, open Info tab and copy it's Hotspot Prefix;
* in Arduino IDE Sketch find a string that contains "#define CONFIG_DEVICE_PREFIX", change "Our Product" by pasting Hotspot Prefix from the previous step;

Max length - 200 characters. Only letters, digits and space are allowed.

