# LCD

This widget simulates a common 16x2 LCD.



### Datastream

* **Simple mode** - select or create a datastream of [data type](https://docs.blynk.io/en/blynk.console/templates/datastreams/datastreams-common-settings/data-type) integer, double or string for the first and second lines of the display.
* **Advanced mode** - select or create a single datastream of [data type](https://docs.blynk.io/en/blynk.console/templates/datastreams/datastreams-common-settings/data-type) integer, double or string.&#x20;

### Widget Controls

The widget has no controls.

### Mode

* **SIMPLE** - the datastream value is shown left justified on each line of the LCD. You can add text before and after the value displayed by navigating to ‘Design’ -> ‘FIRST LINE’ and then enter “/value1/ kg” excluding the double quotes. The datastream value of 3.14159 will be displayed as “3.14159 kg”. &#x20;
* **ADVANCED** - allows you to send clear and positioning commands just like those sent to a physical LCD. See sketch: [LCD Advanced Mode](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/LCD/LCD\_AdvancedMode/LCD\_AdvancedMode.ino)



### How to process widget with the hardware

When widget is pressed, value is sent and stored into the Blynk.Cloud. After that it's sent to your device.

#### Reading the widget value: **Simple Mode**

For the widget configured in Simple mode and datastream V1 assigned to the LCD line 1, and V2 assigned to the LCD line 2:

```cpp
BLYNK_WRITE(V1) {
// Called when the datastream V1 value changes

// Assign incoming value from pin V1 to a variable
// according to the datastream data type
int pinValue = param.asInt(); 
// double pinValue = param.asDouble();
// String pinValue = param.asStr()
// String pinValue = param.asString()

Serial.print(“V1: “);
Serial.println(pinValue);
}

BLYNK_WRITE(V2) {
// Called when the datastream V2 value changes

// Assign incoming value from pin V2 to a variable
// according to the datastream data type
int pinValue = param.asInt(); 
// double pinValue = param.asDouble();
// String pinValue = param.asStr()
// String pinValue = param.asString()

Serial.print(“V2: “);
Serial.println(pinValue);
}
```

#### Reading the widget value: **Advanced Mode**

For the widget configured in Advanced mode and datastream V1 of data type string assigned to the LCD:

```cpp
BLYNK_WRITE(V1) {
// Called when the datastream V1 value changes

// String pinValue = param.asStr()
String pinValue = param.asString()

Serial.print(“V1: “);
Serial.println(pinValue);
}
```

#### Changing the datastream value(s): **Simple Mode**

You can change the value of the datastream assigned to the widget with the hardware or HTTP API. For the widget configured in Simple mode and datastream V1 assigned to the LCD line 1, and V2 assigned to the LCD line 2:

**Hardware:**

```cpp
Blynk.virtualWrite(V1, “My LCD Line 1”);	
Blynk.virtualWrite(V2, “My LCD Line 2”);
```

**HTTP API:**

```cpp
https://{server_address}/external/api/update/?token={your 32 char token}&V1=My%20LCD&20Line&202
```

#### Changing the datastream value(s): Advanced **Mode**

You cannot use Blynk.virtualWrite() or HTTP API with the LCD widget in advanced mode because the changes to the datastream will not be reflected in the LCD widget.  You must use the functions as demonstrated in the sketch [LCD Advanced Mode](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/LCD/LCD\_AdvancedMode/LCD\_AdvancedMode.ino).



{% hint style="danger" %}
Don't put **`Blynk.virtualWrite()`**into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, use flags, or [timers](../../blynk.edgent-firmware-api/blynk-timer.md).
{% endhint %}



Sketch:  [LCD Advanced Mode](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/LCD/LCD\_AdvancedMode/LCD\_AdvancedMode.ino)

Sketch: [LCD\_SimpleMode](https://github.com/blynkkk/blynk-library/tree/master/examples/Widgets/LCD/LCD\_SimpleMode)

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

You can change the properties _color_, _isDisabled_, _isHidden_ of the widget from your hardware, or via an [HTTP API](broken-reference). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.

#### **Set Widget Color**

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

**Example:**

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
