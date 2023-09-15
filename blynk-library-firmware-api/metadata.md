---
description: Set and receive metadata values
---

# Metadata

[Metadata](../blynk.console/templates/metadata/) is a `key:value` set of data applied to every device using the same template. Unlike Datastreams, this data stays mostly unchanged, however, if you need to read/write it, here is how to do it:&#x20;

### Get device Metadata

The device can request the value of its own metadata from the cloud using the key (name) of Metadata.

{% hint style="info" %}
Double-check that you have a Metadata field with a correct name configured in the Device Template.
{% endhint %}

First, you need to send a request to Blynk.Cloud

```cpp
BLYNK_CONNECTED() {
  // Send requests for different metadata
  Blynk.sendInternal("meta", "get", "Serial Number");
  Blynk.sendInternal("meta", "get", "Device Model");
  
  //"Auth Token" is a reserved metadata name, if you have your own metadata
  //with that name it will override the default implementation
  //which returns device.token field
  //you can't change the value of reserved metadata field, only if you override it
  Blynk.sendInternal("meta", "get", "Auth Token");
}
```

Then, parse the data stored in `InternalPinMETA`, which a system pin to store metadata values.

```cpp
BLYNK_WRITE(InternalPinMETA) {
    String field = param[0].asStr();
    if (field == "Serial Number") {
        String value = param[1].asStr();
        // Do something with Metadata value
    } else if (field == "Device Model") {
        String value = param[1].asStr();
        // Do something with Metadata value
    } else if (field == "Auth Token") {
        String value = param[1].asStr();
        // Do something with Metadata value
    }
}
```

### Write device metadata

The device can update the value of the metadata using the metadata key (name).&#x20;

For example, if your device stores Serial Number and Device Model internally, you can write these values to corresponding metadata fields. &#x20;

```cpp
sn_value = "123456789"       //imaginary serial number
model_value = "RX-1-2789"    // imaginary device model name

Blynk.sendInternal("meta", "set", "Serial Number", sn_value);
Blynk.sendInternal("meta", "set", "Device Model", model_value);
```
