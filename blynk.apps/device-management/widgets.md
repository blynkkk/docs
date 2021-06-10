---
description: >-
  Widgets are interface modules. Each of them performs a specific input/output
  function when communicating with the hardware.
---

# Widgets

There are 4 types of Widgets:

* **Controllers** - used to send commands that control your hardware
* **Displays** - used for data visualization from sensors and other sources;
* **Interface** - widgets to perform certain GUI functions;
* **Other** - widgets that don't belong to any category;

## Controllers

### Button

Works in push or switch modes. Allows to send any number value on button click and button release events. E.g.: push is used for doorbell, switch is used for room light. If it's in switch mode then latest state that was set on device or Blynk.Console dashboard will be applied and viewed.

Tap the button to apply the action.

### Styled Button

Same as Button but has additional style settings, such as: separate button and background colors for ON and OFF labeles, button styles and edges shape.

Tap the button to apply the action.

### Icon Button

Same as Button with an option to set Icons to be dispayed accordingly to current state. Separate icon and background color settings are supported for ON and OFF states.

Tap the button to apply the action.

### Image Button

Same as Button with an option to add interactivity effect by providing multiple links to different images with different states.

Tap the button to apply the action.

### Slider

It's similar to potentiometer. Allows to send values between MIN and MAX.

Move the handle to change the value.

### Vertical Slider

Same as Slider. The only difference is it's vertical.

Move the handle to change the value.

### Step Slider

Slider with additional step control by buttons taps.

Tap + or - buttons to change the value with high precision \(value amount per step is set by Product owner\) or move the handle.

### Vertical Step Slider

Same as Step Slider. The only difference is it's vertical.

Tap + or - buttons to change the value with high precision \(value amount per step is set by Product owner\) or move the handle.

### Joystick

Control servo movements in 4 directions by moving the knob in two axis.

### zeRGBa

zeRGBa is usual RGB controller \(color picker\).

Move the scope throught the zeRGBa to pick a color.

### RGB Light Control

Color  
Button  
Brightness  
Animation Speed

### Step H

Step control is like 2 buttons assigned to 1 pin. One button increments your value by desired step and another one decrements it. It is very useful for use cases where you need to change your values very precisely and you can't achieve this precision with slider widget. Buttons orientation is horizontal.

Tap + or - button to change the value.

### Step V

Step control is like 2 buttons assigned to 1 pin. One button increments your value by desired step and another one decrements it. It is very useful for use cases where you need to change your values very precisely and you can't achieve this precision with slider widget. Buttons orientation is vertical.

Tap + or - button to change the value.

### Slope Control

### Switch

Simple switch that handles binary states.

Tap the handle to change the state.

### Level Slider

This widget combines functions of Level display and Slider simultaneously.

Tap or swipe level area to set new value.

### Level Slider with Switch

Same as Level Slider with additional Switch option \(the same or different Datastream can be assigned\)

Tap or swipe level area to set new value.

## Displays

### Value Display

Displays incoming data from your sensors or Virtual Pins.

### Labeled Value

It is an enhanced version of 'Value Display'

### LED

A simple LED for indication.

### Gauge

A great visual way to display incoming numeric values.

### Radial Gauge

### Enhanced Gauge

### LCD

This is a regular 16x2 LCD display made in our secret facility in China.

### SuperChart

SuperChart is used to visualise live and historical data. It can view sensor data, for binary event logging and more.

**Interactions:**

* **Switch between time ranges and Live mode** Tap time ranges at the bottom of the widget to change time ranges
* **Tap Legend Elements** to show or hide datastreams
* **Tap'n'hold to view timestamp and corresponding values**
* **Quick swipe from left to right to reveal previous data** Then you can then scroll data back and forward within the given time range.
* **Full Screen Mode** Press this button to open Full Screen view in landscape orientation.

Simply rotate the phone back to portrait mode. Chart should rotate automagically. In full screen view you will see X \(time\) and multiple Y scales. Full Screen Mode can be disabled from widget Settings.

* **Menu Button** Menu button will open additional functions:
  * Export to CSV
  * Erase Data on the server

### Terminal

Displays data from your hardware. Allows to send any string to your hardware. Terminal always stores last 25 messages your hardware had send to Blynk Cloud.

```text
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

### Video Streaming

Simple widget that allows you to view any live or video stream. Widget supports RTSP \(RP, SDP\), HTTP/S progressive streaming, HTTP/S live streaming.

You can stop/start video stream with click on widget.

### Level H

### Level V

### Image Gallery

### Gradient Ramp

### Icon

## Interface

### Tabs

The only purpose of Tabs widget is to extend project space.

### Menu

Menu widget allows you to send command to your hardware based on selection you made on UI.

### Map

This is very useful widget in case you have multiple devices and you want track their values on map.

### Text Input

Text Input displays and let's you directly alter a string value.

### Numeric Input

Numeric Input displays and let's you directly alter a number value. Similar to the Step widget, it has incrementing and decrementing buttons for quicker values changes.

### Segmented Switch

Segmented Switch widget allows you to send command to your hardware based on selection you made on UI.

### Icon Segmented Switch

### Text

## Other

### Music Player

Simple UI element with 3 buttons - simulates music player interface. Every button sends it's own command to hardware : `play`, `stop`, `prev`, `next`.

### WebPage Button

### WebPage Image Button

### Alias Name

