# Terminal

Terminal widget works like the usual system terminal. The widget is showing real-time data from your hardware through a **string** datastream. Allows sending any string to your hardware.\
[![image](https://user-images.githubusercontent.com/24506752/171181626-7f9ac4a6-78b3-490f-a6a1-7f3eff6bea65.png)](https://user-images.githubusercontent.com/24506752/171181626-7f9ac4a6-78b3-490f-a6a1-7f3eff6bea65.png)

### Datastream

Only **String** datastream can be used here.

### Widget Settings

INPUT HINT — textual hint for the input field\
[![image](https://user-images.githubusercontent.com/24506752/171186147-edd6e5be-5a51-4fc8-b190-b1f751024b44.png)](https://user-images.githubusercontent.com/24506752/171186147-edd6e5be-5a51-4fc8-b190-b1f751024b44.png)

Auto scroll — enable/disable automatic scrolling to the bottom when new values are coming\
[![image](https://user-images.githubusercontent.com/24506752/171186515-23765638-eecb-4699-a519-ba5f9c96a90a.png)](https://user-images.githubusercontent.com/24506752/171186515-23765638-eecb-4699-a519-ba5f9c96a90a.png)

Show input — show/hide input field in the terminal widget\
[![image](https://user-images.githubusercontent.com/24506752/171186925-aa5b2324-f54e-4cff-9294-1743686249a7.png)](https://user-images.githubusercontent.com/24506752/171186925-aa5b2324-f54e-4cff-9294-1743686249a7.png)

You can set screen and text colors too.\
[![image](https://user-images.githubusercontent.com/24506752/171187044-3d8eb566-834c-46ab-ba3a-f06337560a3a.png)](https://user-images.githubusercontent.com/24506752/171187044-3d8eb566-834c-46ab-ba3a-f06337560a3a.png)

### How to send data from a device

Terminal shows any string messages your hardware has sent to Blynk Cloud recently. For example, you can send logs from virtual pin V1 :

```
Blynk.virtualWrite(V1, "Log 1"); // send first log
Blynk.virtualWrite(V1, "Log 2"); // send second
```

Don't put `Blynk.virtualWrite()` into the `void loop()` as it can cause a flood of messages and your hardware will be disconnected from the server for spam. Send such updates only when necessary.

### Get data using Blynk library

You can also get button state from server in case your hardware was disconnected with Blynk Sync feature :

```
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
}

BLYNK_WRITE(V1) {
  String string = param.asStr();
}
```

### Send data using HTTP API

Please check this article [https://docs.blynk.io/en/blynk.cloud/update-datastream-value](https://docs.blynk.io/en/blynk.cloud/update-datastream-value)
