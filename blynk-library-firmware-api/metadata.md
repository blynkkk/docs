---
description: Send and
---

# Metadata

[Metadata](../blynk.console/templates/metadata.md) is a `key:value` set of data applied to every device using the same template. Unlinke Datastreams, this data stays mostly unchanged, however, if you need to read/write it, here is how to do it:&#x20;

### Get device Metadata

Device can request value of its own metadata from the cloud using the key (name) of Metadata.

{% hint style="info" %}
Double check that you have a Metadata field with a correct name configured in the Device Template.
{% endhint %}

First you need to send a request to Blynk.Cloud

```cpp
BLYNK_CONNECTED() {
  // Send requests for different metadata
  Blynk.sendInternal("meta", "get", "Serial Number");
  Blynk.sendInternal("meta", "get", "Device Model");
}
```

Then, parse the data stored in `InternalPinMETA`, which is a system pin to store metadata values.

```cpp
BLYNK_WRITE(InternalPinMETA) {
    String field = param[0].asStr();
    if (field == "Serial Number") {
        String value = param[1].asStr();
        // Do something with Metadata value
    } else if (field == "Device Model") {
        String value = param[1].asStr();
        // Do something with Metadata value
    }
}
```

### Write device metadata

Device can update the value of the metadata using metadata key (name).&#x20;

For example, if your devices stores Serial Number and Device Model internally, you can write this values to corresponding metadata fields. &#x20;

```cpp
sn_value = "123456789"       //imaginary serial number
model_value = "RX-1-2789"    // imaginary device model name

Blynk.sendInternal("meta", "set", "Serial Number", sn_value);
Blynk.sendInternal("meta", "set", "Device Model", model_value);
```
