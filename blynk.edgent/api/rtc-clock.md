# RTC clock

Blynk can provide your device with time data, like an RTC.

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





