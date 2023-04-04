---
description: Working with time using Blynk API
---

# Time (RTC clock)

RTC stands for Real-Time-Clock and is usually a hardware component. However, Blynk offers you a way to get time to use in your embedded applications running on devices.

{% hint style="info" %}
Please note that the accuracy of this method is up to several seconds.
{% endhint %}

To sync your device's time with Blynk cloud, use this command&#x20;

```cpp
Blynk.sendInternal("rtc", "sync"); //request current local time for device
```

For example you can use it right after device has connected to the cloud with `BLYNK_CONNECTED()` command:

```cpp
BLYNK_CONNECTED() {                  //When device is connected to server...
  Blynk.sendInternal("rtc", "sync"); //request current local time for device
}
```

To get the actual value in UNIX time format, you need to check the value of `InternalPinRTC` which is the system pin to store time. Here is how you can do it:

```cpp
BLYNK_WRITE(InternalPinRTC) {   //check the value of InternalPinRTC  
  long t = param.asLong();      //store time in t variable
  Serial.print("Unix time: ");  
  Serial.print(t);              //prints time in UNIX format to Serial Monitor
  Serial.println();
}
```



