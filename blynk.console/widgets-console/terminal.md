# Terminal

{% hint style="warning" %}
_**Note:**_ please remember that web and mobile app widgets are set up separately in the Web Dashboard and Mobile App Dashboard sections correspondingly. They can still use the same datastreams to access the same data (Map widget is an exception – a different codebase is used for Map on mobile and web).
{% endhint %}

Terminal widget works like the usual system terminal. This widget displays datastream text in a multi-line window, and optionally provides a text input area which allows sending any string to your hardware. Options allow a new line character to be added to each datastream change in value, scrolling, and the text and background color of the display and input area.

![](../../.gitbook/assets/terminal-widget-newsletter.png)

### Settings

![](<../../.gitbook/assets/terminal-widget-settings-documentation (1).png>)

**Title** - This is the label shown at the top of the widget. The default is the name assigned to the datastream.

**Datastream** - Select or create a datastream of data type **string**.

**Add new line** - Enable to have each change to the datastream prefaced with a new line character. When disabled, all new text will be concatenated directly after the last.

**Auto scroll** - Automatically scrolls the text display in the output window vertically to show the latest at the bottom. Useful only when ‘Add new line’ is enabled.

**Show input** - When disabled, hides the text input field.

**SCREEN COLOR** - Sets the background color of the output (display) and input areas.

**TEXT COLOR** - Sets the color of the text displayed in the output and input areas.\


Note that a horizontal scroll bar below the output display becomes visible when the text in the current line exceeds the width of the output display.\


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
