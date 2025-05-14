# Gradient Ramp

### Overview

The Gradient Widget provides intuitive data visualization through a sloped bar with a smooth color gradient. It’s designed to represent values on a continuous scale, helping users interpret trends, thresholds, and performance metrics at a glance.

Common use cases include displaying:

* Signal strength
* Temperature levels
* Battery status

***

### Settings

| Setting             | Description                                                           |
| ------------------- | --------------------------------------------------------------------- |
| Title               | Optional. Set a custom name for the widget.                           |
| Datastream          | Choose the datastream to visualize.                                   |
| Override Min/Max    | Optionally override the datastream’s default min/max value limits.    |
| Gauge Shape         | <p>Choose visual style:<br>• Solid<br>• Ascending<br>• Descending</p> |
| Show Min/Max Values | Toggle display of the min/max values on the widget.                   |
| Show Value          | Toggle display of the current value.                                  |
| Show Bottom Label   | Show or hide the label below the widget.                              |
| Ramp Color          | Choose a solid color or gradient appearance.                          |

<figure><img src="../../.gitbook/assets/gradient-ramp 2.png" alt=""><figcaption><p>Gradient Ramp</p></figcaption></figure>

### Limits

* Bottom Label: Maximum 100 characters

***

### Controlling Widget from Hardware

You can update widget properties programmatically using:

```
Blynk.setProperty(vPin, "widgetProperty", "propertyValue");
```

Where:

* vPin — Virtual pin assigned to the widget
* widgetProperty — Property you want to change
* propertyValue — New value for that property

{% hint style="danger" %}
Warning: Avoid placing Blynk.setProperty() in the loop() function — this may flood the server and disconnect your device. Use timers or event-based updates instead.
{% endhint %}

#### Supported Properties

You can change the following properties from hardware or via the HTTP API:

* label
* isHidden
* isDisabled\


**Example (hardware):**

```
Blynk.setProperty(V1, "isHidden", "true");
```

**Example (HTTP API):**

```
https://{server_address}/external/api/update/property?token={your_32_char_token}&pin=V1&isHidden=true
```
