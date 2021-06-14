---
description: Working with time using Blynk API
---

# RTC clock

Blynk can provide your device with current time, like an RTC \(real-time-clock\).

{% hint style="info" %}
Please note that the accuracy of this method is up to several seconds.
{% endhint %}

```text
BLYNK_CONNECTED() {
  // request current device local time
  Blynk.sendInternal("rtc", "sync");
}

BLYNK_WRITE(InternalPinRTC) {
  long t = param.asLong();
  Serial.print("Unix time: ");
  Serial.print(t);
  Serial.println();
}
```





