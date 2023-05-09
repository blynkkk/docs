---
description: >-
  The widget property is a widget attribute like color, labels, min/max, ...,
  and others that could be dynamically changed from the hardware or HTTPS API.
---

# Widget Properties

## Single Datastream

You can change the widget property assigned to a single datastream from the hardware side.\
For example, you can change the color of an LED widget assigned to Virtua Pin 0:

```
//change LED color
Blynk.setProperty(V0, "color", "#D3435C");

//change LED label
Blynk.setProperty(V0, "label", "My New Widget Label");

//change MENU labels
Blynk.setProperty(V0, "labels", "Menu Item 1", "Menu Item 2", "Menu Item 3");
```

[Set Property for single value field](https://github.com/blynkkk/blynk-library/blob/master/examples/More/SetProperty/SetProperty\_SingleValue/SetProperty\_SingleValue.ino)

[Set Property for multi value field](https://github.com/blynkkk/blynk-library/blob/master/examples/More/SetProperty/SetProperty\_MultiValue/SetProperty\_MultiValue.ino)

**NOTE :** Changing these parameters work **only** for widgets attached to Virtual pins (analog/digital pins won't work).

`color`, `label`, `isDisabled`, `isHidden` widget properties are supported for all widgets:

`label` is a string for the label of all widgets.

`color` is a string in [HEX](http://www.w3schools.com/html/html\_colors.asp) format (in the form: #RRGGBB, where RR (red), GG (green), and BB (blue) are hexadecimal values between 00 and FF). For example:

```
#define BLYNK_GREEN     "#23C48E"
#define BLYNK_BLUE      "#04C0F8"
#define BLYNK_YELLOW    "#ED9D00"
#define BLYNK_RED       "#D3435C"
#define BLYNK_DARK_BLUE "#5F7CD8"
```

On the firmware side, widget objects also support `setLabel()` and `setColor()` functions.

Widget-specific properties:

**Button**

`onLabel` / `offLabel` is a string for ON/OFF label of a button;

**Styled Button**

`onLabel` / `offLabel` is a string for ON/OFF label of a button;

`onColor` / `offColor` is a string in HEX format for ON/OFF colors of the button;

`onBackColor` / `offBackColor` is a string in HEX format for ON/OFF colors of the button background.

**Music Player**

`isOnPlay` is boolean accepts true/false.

```
Blynk.setProperty(V0, "isOnPlay", "true");
```

**Menu**

`labels` is a list of strings for Menu widget selections;

```
Blynk.setProperty(V0, "labels", "label 1", "label 2", "label 3");
```

**Video Streaming**

```cpp
Blynk.setProperty(V1, "url", "http://my_new_video_url");
```

**Step**

```cpp
Blynk.setProperty(V1, "step", 10);
```

**Image**

```cpp
Blynk.setProperty(V1, "opacity", 50); // 0-100%
```

```cpp
Blynk.setProperty(V1, "scale", 30); // 0-100%
```

```cpp
Blynk.setProperty(V1, "rotation", 10); //0-360 degrees
```

also, you can fully replace the list of images from the hardware:

```cpp
Blynk.setProperty(V1, "urls", "https://image1.jpg", "https://image2.jpg");
```

or you can change the individual image by its index:

```cpp
Blynk.setProperty(V1, "url", 1, "https://image1.jpg");
```

**Alarm and Sound**

```cpp
Blynk.setProperty(V1, "isMuted", "true");
```

You can also change widget properties via [HTTP API](https://docs.blynk.io/en/blynk.cloud/https-api-overview).

## Multiple Datastreams

In addition to the above commands, you can also change the multiple datastream properties with one command. For example, let's assume, you want to disable multiple widgets with a single command:

```
Blynk.setProperty(V0, V1, V2, "isDisabled", "true");
```

The above command would be an alternative to the batch of single datastream commands:

```
Blynk.setProperty(V0, "isDisabled", "true");
Blynk.setProperty(V1, "isDisabled", "true");
Blynk.setProperty(V2, "isDisabled", "true");
```
