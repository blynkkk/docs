# Widgets (app)

Widgets are pre-designed pieces of Graphic User Interface. Each widget performs a specific input/output function when communicating with your hardware or end-user.

Widgets can be found in the **Widget Box.** There are 4 major types of widgets:

* **Controllers** – UI elements used to send data to hardware. For example: buttons, switches, sliders, joysticks, etc.
* **Displays** – UI elements used to visualize the incoming data. LEDs, Charts,&#x20;
* **Interface Elements** – Special Elements to build user-friendly UI. Example: Tabs, Drop down menus, various inputs, et..
* **Misc** – special widgets that doesn't belong to any category.

Scroll the list and tap on the Widget you need to add it to the Grid.\
Tap the Widget to set it up.

## Controllers

### Button

Works in push or switch modes. Allows to send any number value on button click and button release events. By default\
button uses 0/1 (LOW/HIGH) values. Button sends 1 (HIGH) on press and sends 0 (LOW) on release.

You can change button state from hardware side. For example, turn on button assigned to virtual pin V1 :

```cpp
Blynk.virtualWrite(V1, HIGH);
```

You can change button labels from hardware with :

```
Blynk.setProperty(V1, "onLabel", "ON");
```

```
Blynk.setProperty(V1, "offLabel", "OFF");
```

or change color :

```cpp
//#D3435C - Blynk RED 
Blynk.setProperty(V1, "color", "#D3435C");
```

You can also get button state from server in case your hardware was disconnected with Blynk Sync feature :

```
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
}
```

**Sketch:** [Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

**Sketch:** [Physical Button Interrupt](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)

**Sketch:** [Physical Button Poll](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonPoll/ButtonPoll.ino)

**Sketch:** [Physical Button State Sync](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/SyncPhysicalButton/SyncPhysicalButton.ino)

### Styled Button

Works in push or switch modes. Allows to send any number value on button click and button release events. By default button uses 0/1 (LOW/HIGH) values. Button sends 1 (HIGH) on press and sends 0 (LOW) on release.

You can change button state from hardware side. For example, turn on button assigned to virtual pin V1:

```
Blynk.virtualWrite(V1, HIGH);
```

You can change button labels from hardware with :

```
Blynk.setProperty(V1, "onLabel", "ON");

Blynk.setProperty(V1, "offLabel", "OFF");
```

or change color of the button :

```
Blynk.setProperty(V1, "onColor", "#D3435C");

Blynk.setProperty(V1, "offColor", "#D3435C");
```

or change background color of the button :

```
Blynk.setProperty(V1, "onBackColor", "#D3435C");

Blynk.setProperty(V1, "offBackColor", "#D3435C");
```

You can also get button state from server in case your hardware was disconnected with Blynk Sync feature :

```
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
}
```

**Sketch:** [Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

**Sketch:** [Physical Button Interrupt](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)

**Sketch:** [Physical Button Poll](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonPoll/ButtonPoll.ino)

**Sketch:** [Physical Button State Sync](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/SyncPhysicalButton/SyncPhysicalButton.ino)

### Icon Button

### Image Button

Image widget allows you to display any image within your project. You need to provide http/s url to it. Url should be valid endpoint to the binary data of the image. Url shortener will not work.

Right now image widget supports 2 display options:

* **Fit**: Image will be scaled to fit height or width of the widget size;
* **Fill**: Image will be scaled to fill widget area. Cropping may occur;

You can make image widget interactive by providing multiple links to different images with different states and change displayed image index from your hardware or via Eventor widget.

For example, select the first icon from the list :

```
Blynk.virtualWrite(V1, 1); //image indexing starts from 1
```

You can also change opacity, scale or rotation of the displayed the image :

```
Blynk.setProperty(V1, "opacity", 50); // 0-100%
```

```
Blynk.setProperty(V1, "scale", 30); // 0-100%
```

```
Blynk.setProperty(V1, "rotation", 10); //0-360 degrees
```

also, you can fully replace the list of images from the hardware:

```
Blynk.setProperty(V1, "urls", "https://image1.jpg", "https://image2.jpg");
```

or you can change individual image by it index:

```
Blynk.setProperty(V1, "url", 1, "https://image1.jpg");
```

### Slider

Similar to potentiometer. Allows to send values between MIN and MAX.

You can change slider state from hardware side. For example, set slider value assigned to virtual pin V1 to 55 :

```
Blynk.virtualWrite(V1, 55);
```

You can change slider label from hardware with :

```
Blynk.setProperty(V1, "label", "My Slider Label");
```

or change color :

```
//#D3435C - Blynk RED
Blynk.setProperty(V1, "color", "#D3435C");
```

#### Fraction

Defines how many digits after the point you would like to see when moving slider. When you have "No Fraction" that means slider will send only integer values without decimal point. "1 digit" means that values will look like 1.1, 1.2, ..., 2.0, etc.

#### Send On Release

**Send On Release** is available for most controller widgets and allows you to decrease data traffic on your hardware. For example, when you move slider widget, commands are continuously streamed to the hardware, during a single slider move you can send dozens of commands. There are use-cases where it's needed, however creating such a load may cause hardware reset. We recommend enabling **Send On Release** feature for most of the cases, unless you really need instant feedback. This option is enabled by default.

#### Write interval

Similar to above option. However, allows you to stream values to your hardware within certain interval. For example, setting write interval to 100 ms - means, that while you move slider only 1 value will be send to hardware within 100 ms. This option also used to decrease data traffic on your hardware.

**Sketch:** [Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

### Vertical Slider

Same as Slider. The only difference is it's vertical UI.

### Step Slider

Slider with additional step control by buttons taps.

Tap + or - buttons to change the value with high precision (value amount per step is set by Product owner) or move the handle.

### Vertical Step Slider

Same as Step Slider. The only difference is it's vertical UI.

Tap + or - buttons to change the value with high precision (value amount per step is set by Product owner) or move the handle.

### Joystick

Control servo movements in 4 directions.

**Settings:**

* **SPLIT**: Each of the parameters is sent directly to the Pin on your hardware (e.g D7). You don't need to write any code.

**NOTE:** In this mode you send multiple commands from one widget, which can reduce performance of your hardware.

Example: If you have a Joystick Widget and it's set to D3 and D4, it will send 2 commands over the Internet:

```
digitalWrite(3, x);
digitalWrite(4, y);
```

* **MERGE**: When MERGE mode is selected, you are sending just 1 message, consisting of array of values. But you'll need to parse it on the hardware.

This mode can be used with Virtual Pins only.

Example: Add a Joystick Widget and set it to MERGE mode. Choose Virtual Pin V1

```
BLYNK_WRITE(V1) // Joystick assigned to V1 
{
  // get x 
  int x = param[0].asInt(); 
  // get y
  int y = param[1].asInt();
}
```

* **Rotate on Tilt** When it's ON, Joystick will automatically rotate if you use your smartphone in landscape orientation.
* **Auto-Return** When it's OFF, Joystick handle will not return back to center position. It will stay where you left it.

#### Send On Release

**Send On Release** is available for most controller widgets and allows you to decrease data traffic on your hardware. For example, when you move joystick widget, commands are continuously streamed to the hardware, during a single joystick move you can send dozens of commands. There are use-cases where it's needed, however creating such a load may cause hardware reset. We recommend enabling **Send On Release** feature for most of the cases, unless you really need instant feedback. This option is enabled by default.

#### Write interval

Similar to above option. However, allows you to stream values to your hardware within certain interval. For example, setting write interval to 100 ms - means, that while you move slider only 1 value will be send to hardware within 100 ms. This option also used to decrease data traffic on your hardware.

**Sketch:** [JoystickTwoAxis](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/JoystickTwoAxis/JoystickTwoAxis.ino)

### zeRGBa

zeRGBa is usual RGB controller (color picker).

**Settings:**

* **SPLIT**: Each of the parameters is sent directly to the Pin on your hardware (e.g D7). You don't need to write any code.

**NOTE:** In this mode you send multiple commands from one widget, which can reduce performance of your hardware.

Example: If you have a zeRGBa Widget and it's set to D1, D2, D3 it will send 3 commands over the Internet:

```
digitalWrite(1, r);
digitalWrite(2, g);
digitalWrite(3, b);
```

* **MERGE**: When MERGE mode is selected, you are sending just 1 message, consisting of array of values. But you'll need to parse it on the hardware.

This mode can be used with Virtual Pins only.

Example: Add a zeRGBa Widget and set it to MERGE mode. Choose Virtual Pin V1.

```
BLYNK_WRITE(V1) // zeRGBa assigned to V1 
{
    // get a RED channel value
    int r = param[0].asInt();
    // get a GREEN channel value
    int g = param[1].asInt();
    // get a BLUE channel value
    int b = param[2].asInt();
}
```

* **Send On Release** is available for most controller widgets and allows you to decrease data traffic on your hardware. For example, when you move joystick widget, commands are continuously streamed to the hardware, during a single joystick move you can send dozens of commands. There are use-cases where it's needed, however creating such a load may cause hardware reset. We recommend enabling **Send On Release** feature for most of the cases, unless you really need instant feedback. This option is enabled by default.

#### Write interval

Similar to above option. However, allows you to stream values to your hardware within certain interval. For example, setting write interval to 100 ms - means, that while you move slider only 1 value will be send to hardware within 100 ms. This option also used to decrease data traffic on your hardware.

### RGB Light Control

### Step H

Step control is like 2 buttons assigned to 1 pin. One button increments your value by desired step and another one decrements it. It is very useful for use cases where you need to change your values very precisely and you can't achieve this precision with slider widget.

**Send Step** option allows you to send step to hardware instead of actual value of step widget. **Loop value** option allows you to reset step widget to start value when maximum value is reached.

You can change step state from hardware side. For example :

```
Blynk.virtualWrite(V1, val);
```

You can change step labels from hardware with :

```
Blynk.setProperty(V1, "label", "My Stepper");
```

You can change the step of the step widget from hardware with :

```
Blynk.setProperty(V1, "step", 10);
```

or change color :

```
//#D3435C - Blynk RED 
Blynk.setProperty(V1, "color", "#D3435C");
```

You can also get step control state from server in case your hardware was disconnected with Blynk Sync feature :

```
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
}

BLYNK_WRITE(V1) {
  int stepperValue = param.asInt();
}
```

#### Write interval

Similar to above option. However, allows you to stream values to your hardware within certain interval. For example, setting write interval to 100 ms - means, that while you move slider only 1 value will be send to hardware within 100 ms. This option also used to decrease data traffic on your hardware.

**Sketch:** [Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

### Step V

Step control is like 2 buttons assigned to 1 pin. One button increments your value by desired step and another one decrements it. It is very useful for use cases where you need to change your values very precisely and you can't achieve this precision with slider widget.

**Send Step** option allows you to send step to hardware instead of actual value of step widget. **Loop value** option allows you to reset step widget to start value when maximum value is reached.

You can change step state from hardware side. For example :

```
Blynk.virtualWrite(V1, val);
```

You can change step labels from hardware with :

```
Blynk.setProperty(V1, "label", "My Stepper");
```

You can change the step of the step widget from hardware with :

```
Blynk.setProperty(V1, "step", 10);
```

or change color :

```
//#D3435C - Blynk RED 
Blynk.setProperty(V1, "color", "#D3435C");
```

You can also get step control state from server in case your hardware was disconnected with Blynk Sync feature :

```
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
}

BLYNK_WRITE(V1) {
  int stepperValue = param.asInt();
}
```

#### Write interval

Similar to above option. However, allows you to stream values to your hardware within certain interval. For example, setting write interval to 100 ms - means, that while you move slider only 1 value will be send to hardware within 100 ms. This option also used to decrease data traffic on your hardware.

**Sketch:** [Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

### Slope Control

### Switch

Allows to send any number value on button click and button release events. By default\
button uses 0/1 (LOW/HIGH) values. Button sends 1 (HIGH) on press and sends 0 (LOW) on release.

You can change button state from hardware side. For example, turn on button assigned to virtual pin V1 :

```
Blynk.virtualWrite(V1, HIGH);
```

You can change button labels from hardware with :

```
Blynk.setProperty(V1, "onLabel", "ON");
```

```
Blynk.setProperty(V1, "offLabel", "OFF");
```

or change color :

```
//#D3435C - Blynk RED 
Blynk.setProperty(V1, "color", "#D3435C");
```

You can also get button state from server in case your hardware was disconnected with Blynk Sync feature :

```
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V1);
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
}
```

**Sketch:** [Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

**Sketch:** [Physical Button Interrupt](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)

**Sketch:** [Physical Button Poll](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonPoll/ButtonPoll.ino)

**Sketch:** [Physical Button State Sync](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/SyncPhysicalButton/SyncPhysicalButton.ino)

### Level Slider

This widget combines functions of Level display and Slider simultaneously.

Tap or swipe level area to set the new value.

### Level Slider with Switch

Same as Level Slider with additional Switch option (the same or different Datastream can be assigned)

Tap or swipe level area to set the new value.

## Displays

### Value Display

Displays incoming data from your sensors or Virtual Pins.

To send the data to the value display simply call the next code:

```
Blynk.virtualWrite(V1, val);
```

Every message that hardware sends to server is stored automatically on server.

**Sketch:** [BlynkBlink](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

### Labeled Value

Displays incoming data from your sensors or Virtual Pins. It is a better version of 'Value Display' as it has a formatting string, so you could format incoming value to any string you want.

Update value display from hardware side with code :

```
Blynk.virtualWrite(V1, val);
```

Every message that hardware sends to server is stored automatically on server.

**Formatting options**

Let's assume, your sensor sends number 12.6789 to Blynk application. Next formatting options are supported:

`/pin/` - displays the value without formatting (12.6789)

`/pin./` - displays the value without decimal part (13)

`/pin.#/` - displays the value with 1 decimal digit (12.7)

`/pin.##/` - displays the value with two decimal places (12.68)

**Sketch:** [BlynkBlink](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

### LED

A simple indicator (similar to a LED).

* if value is equal to `min` DataStream setting, indicator is **OFF**
* if value is equal to `max` DataStream setting, indicator is **ON**
* in-between values are used for brightness control (like PWM)

```
// DataStream is configured for range 0..255
// Set brightness of LED to 50%
Blynk.virtualWrite(V1, 127);
```

You can also change LED color with :

```
//#D3435C - Blynk RED 
Blynk.setProperty(V1, "color", "#D3435C");
```

**Sketch:** [LED](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/LED/LED\_Blink/LED\_Blink.ino)

### Gauge

A great visual way to display incoming numeric values.

Update gauge from hardware side with code :

```
Blynk.virtualWrite(V1, val);
```

Every message that hardware sends to server is stored automatically on server.

**Formatting options**

Gauge also has "Label" field which allows use to use formatting. Let's assume, your sensor sends number 12.6789 to Blynk application. Next formatting options are supported:

`/pin/` - displays the value without formatting (12.6789)

`/pin./` - displays the value without decimal part (13)

`/pin.#/` - displays the value with 1 decimal digit (12.7)

`/pin.##/` - displays the value with two decimal places (12.68)

**Other options**

You can also change gauge label from hardware with :

```
Blynk.setProperty(V1, "label", "My Gauge Label");
```

or change color :

```
//#D3435C - Blynk RED
Blynk.setProperty(V1, "color", "#D3435C");
```

**Sketch:** [BlynkBlink](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

### Radial Gauge

### Enhanced Gauge

### LCD

This is a regular 16x2 LCD display made in our secret facility in China.

**Formatting options**

Let's assume, your sensor sends number 12.6789 to Blynk application. Next formatting options supported:

`/pin/` - displays the value without formatting (12.6789)

`/pin./` - displays the value without decimal part (13)

`/pin.#/` - displays the value with 1 decimal digit (12.7)

`/pin.##/` - displays the value with two decimal places (12.68)

**Sketch:** [LCD Simple Mode Pushing](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/LCD/LCD\_SimpleModePushing/LCD\_SimpleModePushing.ino)

**Sketch:** [LCD Simple Mode Reading](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/LCD/LCD\_SimpleModeReading/LCD\_SimpleModeReading.ino)

**Advanced mode**

Advanced mode is for experienced users. Allows you to use special commands to control LCD.

**Commands**

Init LCD variable :

```
WidgetLCD lcd(V1);
```

Send message :

```
lcd.print(x, y, "Your Message");
```

Where `x` is a symbol position (0-15), `y` is a line number (0 or 1),

Clear LCD :

```
lcd.clear();
```

**Sketch:** [LCD Advanced Mode](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/LCD/LCD\_AdvancedMode/LCD\_AdvancedMode.ino)

### SuperChart

SuperChart is used to visualise live and historical data. You can use it for sensor data, for binary event logging and more.

To use SuperChart widget you would need to push the data from the hardware with the desired interval by using timers. [Here is](https://examples.blynk.cc/?board=ESP8266\&shield=ESP8266%20WiFi\&example=GettingStarted%2FPushData) a basic example for data pushing.

**Interactions:**

* **Switch between time ranges and Live mode** Tap time ranges at the bottom of the widget to change time ranges
* **Tap Legend Elements** to show or hide datastreams
* **Tap'n'hold to view timestamp and corresponding values**
* **Quick swipe from left to right to reveal previous data** Then you can then scroll data back and forward within the given time range.
* **Full Screen Mode** Press this button to open Full Screen view in landscape orientation.

Simply rotate the phone back to portrait mode. Chart should rotate automagically. In full screen view you will see X (time) and multiple Y scales. Full Screen Mode can be disabled from widget Settings.

****

**SuperChart Settings:**

* **Chart Title**
* **Title Font Size** You have a choice of 3 font sizes
* **Title Alignment** Choose chart title alignment. This setting also affects Title and Legend position on the Widget.
* **Show x-axis (time)** Select it if you want to show the time label at the bottom of your chart.
* **Time ranges picker** Allows you to select required periods (`15m`, `30m`, `1h`, `3h`, ...) and resolution for your chart. Resolution defines how precise your data is. Right now chart supports 2 types of resolution `standard` and `high`. Resolution also depends on the selected period. For example, `standard` resolution for `1d` means you'll get 24 points per day (1 per hour), with `high` resolution you'll get for `1d` 1440 points per day (1 per minute).
* **Datastreams** Add datastreams (read below how to configure datastreams)

**Datastream Settings**

Widget supports up to 4 Datastreams. Press Datastream Settings Icon to open Datastream Settings.

**Design:** Choose available types of Chart:

* Line
* Area
* Bar
* Binary (anchor LINK to binary)

**Color:** Choose solid colors or gradients

**Source and input:** You can use 3 types of Data source:

**1. Virtual Pin** Choose the desired Device and Virtual Pin to read the data from.

**2. Tags** SuperChart can aggregate data from multiple devices using built-in aggregation functions. For example, if you have 10 Temperature sensors sending temperature with the given period, you can plot average value from 10 sensors on the widget.

To use Tags:

* [**Add Tag**](https://github.com/blynkkk/blynkkk.github.io/blob/master/#blynk-main-operations-control-of-multiple-devices-tags) to every device you want to aggregate data from.
* **Push data to the same Virtual Pin** on every device. (e.g. `Blynk.virtualWrite (V0, temperature);`)
* **Choose Tag as a source** in SuperChart Widget and use the pin where the data is coming to (e.g V0)&#x20;

**Functions available:**

* `SUM` will summarize all incoming values to the specified Virtual Pin across all devices tagged with the chosen tag
* `AVG` will plot average value
* `MED` will find a median value
* `MIN` will plot minimum value
* `MAX` will plot maximum value

**☝️ IMPORTANT: Tags are not working in Live Mode.**

1. [**Device Selector**](https://github.com/blynkkk/blynkkk.github.io/blob/master/#widgets-time-input-device-selector) If you add Device Selector Widget to your project, you can use it as a source for SuperChart. In this case, when you change the device in Device Selector, chart will be updated accordingly

**Y-Axis Settings**\
There are 4 modes of how to scale data along the Y axis

1. _Auto_ Data will be auto-scaled based on min and max values of the given time period. This is nice option to start with.
2. **Min/Max** When this mode is selected, Y scale will be set to the values you choose. For example, if your hardware sends data with values varying from -100 to 100, you can set the chart to this values and data will be rendered correctly.

You may also want to visualize the data within some specific range. Let's say incoming data has values in the range of 0-55, but you would like to see only values in the range 30-50. You can set it up and if values are out of Y scale you configured, chart will be cropped

1. **% of Height** This option allows you to auto-scale incoming data on the widget and position it the way you want. In this mode, you set up the percentage of widget height on the screen, from 0% to 100%.

If you set 0-100%, in fact it's a full auto-scale. No matter in which range the data is coming,\
it will be always scaled to the whole height of the widget.

If you set it to 0-25%, then this chart will only be rendered on 1/4 of the widget height.

This setting is very valuable for **Binary Chart** or for visualizing a few datastreams on the same chart in a different way.

1. _Delta_ While data stays within the given Delta value, chart will be auto-scaled within this range. If delta exceeds the range, chart will be auto-scaled to min/max values of the given period.

**Suffix**\
Here you can specify a suffix that will be shown during the Tap'n'hold.

**Decimals**\
Defines the formatting of the graph value when you Tap'n'hold the graph. Possible options are: #, #.#, #.##, etc.

**Connect Missing Data Points**\
If this switch is ON, then SuperChart will connect all the dots even if there was no data.

If it's set to OFF, then you will see gaps in case there was no data.

**Binary Chart Settings**\
This type of chart is useful to plot binary data, for example when unit was ON or OFF, or when motion was detected or when certain threshold was reached.

You need to specify a **FLIP** point, which is the point where incoming data will be turned into TRUE or FALSE state.

For example, you send the data in the range of `0 to 1023`. If you set `512` as a **FLIP** point, then everything above `512` (excluding 512) will be recorded as `TRUE`, any value below `512` (including 512) will be `FALSE`.

Another example, if you send `0 and 1` and set `0` as a **FLIP** point, then `1` will be `TRUE`, `0` will be `FALSE`

**State Labels:**\
Here you can specify how `TRUE/FALSE` should be shown in Tap'n'Hold mode.

For example, you can set to `TRUE` to "Equipment ON" label, `FALSE` to "Equipment OFF".

### Simple Chart

![](../../.gitbook/assets/simple-chart-widget-newsletter.png)

Simple Chart widget visualizes numerical data that comes from the device plotting a historical graph. It features:

* line, stepped line or bar chart types
* plotting data resolutions: 1 min, 1 hour, or 1 day
* plotting time ranges from 6 hours to 1 year
* auto-scaled or fixed data axis
* highlighted min/max values
* easily reveal individual points via tap-n-hold
* scrollable time axis
* numerous styling settings
* full-screen mode

#### **Widget Settings**

#### **Data**

![](../../.gitbook/assets/simple-chart-widget-data-settings.png)

Select a datastream which has numerical (i.e. of Int or Double) data type and comes from the device. Data that the app sends to the device is not registered. Simple Chart widget shows data from a single datastream. If you need to plot multiple datastreams in a single chart, check the Super Chart widget. By default the chart shows the average value (AVG) for each point on the chart, but you can change aggregation to (SUM) total of the incoming data. The time period covered by each point on the chart is defined by the selected Time Range/Resolution (see below).

#### Chart Style

![](../../.gitbook/assets/simple-chart-widget-style.png)

Choose chart type (Line, Bar, or Step line) and its visual properties, like line width, color or gradient, axes style, etc. Note: when the gradient option is used, its color distribution is based on min/max properties of the selected datastream.

#### Time Ranges / Resolution

![](../../.gitbook/assets/simple-chart-widget-time-ranges.png)

Select up to 7 time ranges you want to be able to switch between in the widget. Each time range button you select specifies its resolution - that is a period of time covered by each single point on a chart. Whenever there are multiple actual data writings coming from the device within the resolution period, that data is aggregated into one point (calculating average or total depending on the selection made in the Data section (see above).

#### Y-Axis Scaling

![](../../.gitbook/assets/simple-chart-widget-y-axis-scaling.png)

There are a number of ways to define the range of values to be shown on a chart. Select option to**:**

* use datastream min/max (available for AVG aggregation, not available for SUM aggregation)
* auto scale the visual range to always fit all the data
* 0-Auto: auto-scale but always start from zero
* define fixed min and max of the visual range
* define delta: chart is auto-scaled, but its range never gets less than the delta set

#### Summary

![](../../.gitbook/assets/simple-chart-widget-value-summary.png)

Turn on Summary to show the average or total of all values presented on the chart in the top right corner. Note: summary style settings also define the style of selected value during tap-n-hold.

#### Other Settings

![](../../.gitbook/assets/simple-chart-widget-settings.png)

* Show or hide a button at the bottom right to go to full-screen mode
* Allow chart scrolling along the time axis. On scrolling, the chart and the summary are updated according to the new time range
* Whether the line chart should connect missing points - that is all available points are connected in a line. Turn it off to visualize points without neighbours

#### How to send data from device to Simple Chart widget

Usually, just make sure that the data coming from the device is numerical. See more details on sending data [here](https://docs.blynk.io/en/getting-started/how-to-display-any-sensor-data-in-blynk-app).

```
float sensorData = readSensor(); 
Blynk.virtualWrite(V5, sensorData);
```

#### Widget Properties

Simple Chart supports standard `isDisabled` and `isHidden` [properties](https://docs.blynk.io/en/blynk.edgent-firmware-api/widget-properties)&#x20;

```
Blynk.setProperty(V0, "isDisabled", "true");
```

### Terminal

Displays data from your hardware. Allows to send any string to your hardware. Terminal always stores last 25 messages your hardware had send to Blynk Cloud.

You can use special commands with this widget:

```
// Print values, like Serial.print
terminal.print();   
// Print values, like Serial.println()
terminal.println();
 // Write a raw data buffer
terminal.write();
// Ensure that data was sent out of device
terminal.flush();
// Erase all values in the terminal
terminal.clear();
```

**Sketch:** [Terminal](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/Terminal/Terminal.ino)

### Video Streaming

Simple widget that allows you to display any live or video stream. Widget supports RTSP (RP, SDP), HTTP/S progressive streaming, HTTP/S live streaming. For more info please follow [official Android documentation](https://developer.android.com/guide/appendix/media-formats.html).

At the moment Blynk doesn't provide streaming servers. So you can either stream directly from camera, use 3-d party services or host streaming server on own server (on raspberry for example).

You can also stop/start video stream with click on widget.

You can also change video url from hardware with :

```
Blynk.setProperty(V1, "url", "http://my_new_video_url");
```

### Level H

### Level V

### Image Gallery

### Gradient Ramp

### Icon

## Interface

### Tabs

The only purpose of Tabs widget is to extend your project space. In order to edit tabs widget - just tap on the selected tab. You can drag widgets between tabs. Only the last tab can be removed: to remove it swipe left on its name in Settings screen.

The maximum number of tabs on iOS is 4 The maximum number of tabs on Android is 10

### Menu

Menu widget allows you to send command to your hardware based on selection you made on UI. Menu sends index of element you selected and not label string. Sending index is starts from 1. It works same way as usual ComboBox element.

Example code:

```
BLYNK_WRITE {
  switch (param.asInt()) {
    case 1: { // Item 1
      Serial.println("Item 1 selected");
      break;
    }
    case 2: { // Item 2
      Serial.println("Item 2 selected");
      break;
    }    
  }
}
```

You can also set Menu items from hardware side with :

```
Blynk.setProperty(V1, "labels", "label 1", "label 2", "label 3");
```

**Sketch:** [Menu](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/Menu/Menu.ino)

### Map

Map widget allows you set points/pins on map from hardware side. This is very useful widget in case you have multiple devices and you want track their values on map.

You can send a point to map with regular virtual write command :

```
Blynk.virtualWrite(V1, pointIndex, lat, lon, "value");
```

We also created a wrapper for you to make usage of map simpler :

You can change button labels from hardware with :

```
WidgetMap myMap(V1);
...
int index = 1;
float lat = 51.5074;
float lon = 0.1278;
myMap.location(index, lat, lon, "value");
```

Using save `index` allows you to override existing point value.

**Sketch:** [Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/Map/Map.ino)

### Text Input

Text Input displays and lets you directly alter a string value. You can limit the maximum number of characters in widget settings.

### Numeric Input

Numeric Input displays and lets you directly alter a number value. Similar to the Step widget, it has incrementing and decrementing buttons for quicker value changes, which you can set up (step, looping) in widget settings.

### Segmented Switch

Segmented Switch widget allows you to send command to your hardware based on selection you made on UI. Segmented Switch sends index of element you selected and not label string. Sending index starts from 1. It works same way as usual ComboBox or Menu element.

Example code:

```
BLYNK_WRITE {
  switch (param.asInt()) {
    case 1: { // Item 1
      Serial.println("Item 1 selected");
      break;
    }
    case 2: { // Item 2
      Serial.println("Item 2 selected");
      break;
    }    
  }
}
```

You can also set Menu items from hardware side with :

```
Blynk.setProperty(V1, "labels", "label 1", "label 2", "label 3");
```

**Sketch:** [Menu](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/Menu/Menu.ino)

### Icon Segmented Switch

### Text

## Other

### Music Player

Simple UI element with 3 buttons - simulates music player interface. Every button sends it's own command to hardware : `play`, `stop`, `prev`, `next`.

You can change widget state within the app from hardware side with next commands:

```
Blynk.virtualWrite(Vx, “play”);
Blynk.virtualWrite(Vx, “stop”);
```

You can also change widget play/stop state with next code (equivalent to above commands) :

`Blynk.setProperty(V1, "isOnPlay", "false");`

**Sketch:** [Music Player](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/Player/Player.ino)

### WebPage Button

### Web Page Image Button

### Alias Name
