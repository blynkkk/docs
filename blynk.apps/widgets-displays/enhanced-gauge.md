# Enhanced Gauge

Displays visually and numerically the latest datastream value, and optionally an arrow that indicates an increasing or decreasing trend, and optionally the value for the trend change. The trend change period is adjustable between 15 min and 1 day.

An indicator on a circle is positioned based on the latest datastream value and proportional to an arc of 270 degrees and the datastream min and max values. The last datastream value is also shown as a number in the center of the display. A filled radial arc of 270 degrees with a fading color from light to dark visually enhances the gauge.

<figure><img src="../../.gitbook/assets/image (19).png" alt=""><figcaption><p>Enhanced Gauge in different modes</p></figcaption></figure>

### Mode

The ‘Trend’ and ‘Trend change’ options change the mode between the following:

* **‘Trend’ disabled** - the latest datastream value is displayed.
* **‘Trend’ enabled, ‘Trend change’ disabled** -in addition to the display of the latest datastream value, an arrow point up (increasing trend) or down (decreasing trend) is shown based on the first and last values over the ‘TREND PERIOD’.  The ‘TREND PERIOD’ is also displayed. &#x20;
* **‘Trend’ enabled, ‘Trend change’ enabled** - in addition to the display of the latest datastream value, an arrow point up (increasing trend) or down (decreasing trend) is shown, and to the right of the trend arrow a numerical value for the change in value over the ‘TREND PERIOD’.  The ‘IGNORE DELTA FLUCTUATIONS’ setting will cause the trend calculation to ignore (filter) values less than this setting. &#x20;

‘TREND PERIOD’ defines the period over which a trend will be evaluated. The options are: 15 min, 30 min, 1 h, 3h, 6h, 12h, 1d.  No trend arrow or trend change numerical value will be displayed until at least one trend period has elapsed.

### Datastream

Select or create a datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) integer or double. Widget properties (label, color, etc.) are also changed via the datastream, but only for virtual, enumerable, and location pins, not digital and analog pins.

The “color” property changes the color of the radial gauge and the latest value shown in the center of the gauge.

### Widget Controls

The widget has no controls.

### How to process widget input on the device

The datastream value displayed is updated whenever the value stored on Blynk.Cloud changes.

#### Reading the widget value(s)

```cpp
BLYNK_WRITE(V1) {
// Called when the datastream V1 value changes

// Assign incoming value from pin V1 to a variable
// according to the datastream data type
int pinValue = param.asInt(); 
// float pinValue = param.asFloat()
// double pinValue = param.asDouble();
// String pinValue = param.asStr()
// String pinValue = param.asString()
// String pinValue = param.getBuffer()  // raw data from param buffer
// int value = param.getLength()  // raw data from param buffer

if (pinValue == 1){
  // do something when the value is 1
} else if (pinValue == 0) {
  // do something when the value is 0
}

Serial.print("V1 value is: "); // print value to serial monitor
Serial.println(pinValue);
}
```

#### Changing the datastream value

You can update the assigned datastream value using the hardware or HTTP API.&#x20;

**Hardware:**

```cpp
Blynk.virtualWrite(vPin, 1);
```

**HTTP API:**

```cpp
https://{server_address}/external/api/update/?token={your 32 char token}&V0=1

https://{server_address}/external/api/batch/update/?token={your 32 char token}&V0=1
```

{% hint style="danger" %}
Don't put **`Blynk.virtualWrite()`**into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, use flags, or [timers](../../blynk.edgent-firmware-api/blynk-timer.md).
{% endhint %}



Sketch:[ Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

Sketch:[ ](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)[Set Property](https://github.com/blynkkk/blynk-library/blob/master/examples/More/SetProperty/SetProperty\_SingleValue/SetProperty\_SingleValue.ino)

Sketch:[ ](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonPoll/ButtonPoll.ino)[VirtualPinWrite](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/VirtualPinWrite/VirtualPinWrite.ino)

Sketch: [VirtualPinRead](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/VirtualPinRead/VirtualPinRead.ino)



### Change Widget Properties

You can change certain properties of the Widget from your hardware. For that, use this command:&#x20;

```cpp
Blynk.setProperty(vPin, "widgetProperty", "propertyValue"); 
```

Where:&#x20;

* `vPin` is: virtual pin number the widget is assigned to
* `widgetProperty`: property you want to change
* `propertyValue`: value of the property you want to change

{% hint style="danger" %}
Don't put **`Blynk.setProperty()`**into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers.
{% endhint %}



### Properties you can change

You can change the properties _label_, _color_, _isDisabled_, _isHidden_ of the widget from your hardware, or via an [HTTP API](broken-reference). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.&#x20;

#### **Change Label**

```cpp
Blynk.setProperty(V1, "label", "Air temperature");
```

#### **Set Color**

```cpp
//#D3435C - Blynk RED 
Blynk.setProperty(V1, "color", "#D3435C");
```

#### **Disable/Enable**

Widget will be greyed out on UI and users won't be able to tap on it.

```cpp
Blynk.setProperty(V1, "isDisabled", true);
```

#### **Show/Hide**

Widget will be hidden from dashboard. Design your UI so that it doesn't look weird when there is no widget.

```cpp
Blynk.setProperty(V1, "isHidden", true);
```

### Change widget properties via HTTPs API

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}" method="get" summary="Updates the Datastream Property and all assigned Widgets" %}
{% swagger-description %}
The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&label=My%20Label`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&color=%23D3435C`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isDisabled=true`
{% endswagger-description %}

{% swagger-parameter in="query" name="token" type="string" required="true" %}
Device [auth token](../../concepts/device.md#authtoken) from Device info
{% endswagger-parameter %}

{% swagger-parameter in="query" name="pin" type="string" required="true" %}
The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="query" name="{property}" type="string" %}
The property of the widget you want to update: `label`, `color`, `isDisabled`, `isHidden`
{% endswagger-parameter %}

{% swagger-parameter in="path" name="{server address}" type="string" required="true" %}
Get from the bottom right of your Blynk console. [More information](../../blynk.cloud/device-https-api/troubleshooting.md).
{% endswagger-parameter %}

{% swagger-parameter in="query" name="label" type="string" %}
the text used as widget label
{% endswagger-parameter %}

{% swagger-parameter in="query" name="color" type="string" %}
button color hexadecimal, must include the hash # character urlencoded as %23
{% endswagger-parameter %}

{% swagger-parameter in="query" name="isDisabled" type="string" %}
true or false
{% endswagger-parameter %}

{% swagger-parameter in="query" name="isHidden" type="string" %}
true or false
{% endswagger-parameter %}

{% swagger-response status="200" description="Success" %}
```
```
{% endswagger-response %}

{% swagger-response status="400" description="Could not find a device token" %}
```
{"error":{"message":"Invalid token."}}
```
{% endswagger-response %}
{% endswagger %}

### **Sync to the latest known state**&#x20;

You can update your hardware to the latest datastream value from Blynk.Cloud after your hardware went offline, and then came online again. Use `Blynk.syncVirtual()` to update a single virtual pin, or `Blynk.syncAll()` to update all virtual pins. See [State Syncing](../../blynk.edgent-firmware-api/state-syncing.md) for more details.

```cpp
BLYNK_CONNECTED() { 
  // Called when hardware is connected to Blynk.Cloud  

  // get the latest value for V1
  Blynk.syncVirtual(V1); 

  // Request Blynk server to re-send latest values for all pins
  Blynk.syncAll()
}
```
