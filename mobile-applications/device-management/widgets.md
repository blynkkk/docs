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

Works in push or switch modes. Allows to send any number value on button click and button release events. E.g.: push is used for doorbell, switch is used for room light. If it's in switch mode then latest state that was set on device or Blynk.360 dashboard will be applied and viewed. 

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

### RGB Light Control

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

### Gauge

### Radial Gauge

Enhanced Gauge

LCD

SuperChart

Terminal

Video Streaming

Level H

Level V

Image Gallery

Gradient Ramp

Icon

## Interface

Tabs

Menu

Map

Text Input

Numeric Input

Segmented Switch

Icon Segmented Switch

Text

## Other

Music Player

WebPage Button

WebPage Image Button

Alias Name

