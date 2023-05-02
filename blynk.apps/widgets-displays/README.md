---
description: UI elements used to visualize the incoming data. LEDs, Charts, etc.
---

# Displays

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

This is a regular 16x2 LCD display made in our secret facility in China. It can work in 2 modes :

* Simple
* Advanced

**Simple mode**

In simple mode, your LCD widget performs as a regular widget with Frequency reading.

With Frequency Reading mode you need to select update interval and the application will trigger events with the required timing.\
Your application should be open and running in order to make requests to hardware. You don't need any code for Analog and\
Digital pins in that case. However, for virtual pins you need to use the following code :

```
//triggered from app
BLYNK_READ(V1)
{
  //send to app
  Blynk.virtualWrite(V1, val);
}
```

In Simple mode LCD also supports formatting options.

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

The image gallery widget allows you to display any image within your project. You need to provide http/s url to it. Url should be a valid endpoint to the binary data of the image. The url shortener will not work.

Right now image widget supports 2 display options:

* **Fit**: The image will be scaled to fit the height or width of the widget size;
* **Fill**: The image will be scaled to fill the widget area. Cropping may occur;

You can make an image widget interactive by providing multiple links to different images with different states and change the displayed image index from your hardware.

For example, select the first icon from the list :

```
Blynk.virtualWrite(V1, 0); //image indexing starts from 0
```

You can also change the opacity, scale, or rotation of the displayed image :

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

or you can change the individual image by its index:

```
Blynk.setProperty(V1, "url", 0, "https://image1.jpg");
```

### Gradient Ramp
