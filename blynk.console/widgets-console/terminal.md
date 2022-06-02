# Terminal

Terminal widget works like the usual system terminal. The widget is showing real-time data from your hardware through a **string** datastream. Allows sending any string to your hardware.\


![](../../.gitbook/assets/terminal-widget-newsletter.png)

### Settings

![](<../../.gitbook/assets/terminal-widget-settings-documentation (1).png>)

#### Datastream

Only **String** datastream can be used here.

#### Input hint

Textual hint for the input field

#### Auto scroll

Enable/disable automatic scrolling to the bottom when new values are coming

#### Show input

Show/hide input field in the terminal widget

#### Colors

You can set screen and text colors too

### How to send data from a device

Terminal shows any string messages your hardware has sent to Blynk Cloud recently. For example, you can send logs from virtual pin V1 :

```
Blynk.virtualWrite(V1, "Log 1"); // send first log
Blynk.virtualWrite(V1, "Log 2"); // send second
```

Don't put `Blynk.virtualWrite()` into the `void loop()` as it can cause a flood of messages and your hardware will be disconnected from the server for spam. Send such updates only when necessary.

### Get data using Blynk library

For terminal you can use regular Blynk virtual pin operations:

```
//to get the value from the terminal text input
BLYNK_WRITE(V1) {
   String string = param.asStr();
}

//to send the value to terminal
//max length for the 1 terminal message is 255 chars
Blynk.virtualWrite(V1, value)
```

### Send data using HTTP API

Please check this article [https://docs.blynk.io/en/blynk.cloud/update-datastream-value](https://docs.blynk.io/en/blynk.cloud/update-datastream-value)
