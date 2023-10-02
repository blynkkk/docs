# zeRGBa

zeRGBa is a control for choosing colors that are sent as RGB values. RGB represents a color derived from the primary red, green, and blue colors, and with an intensity varied for each color between a level of 0 and 255.&#x20;

### Mode

For both modes, the widget will update the datastream(s) with the RGB color values based on the widget position.

* **Simple** - Assign one datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) integer or double each to R, G, and B (a total of three datastreams). &#x20;
* **Advanced** - Assign one datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) string.  In the hardware, you access the RGB values from the datastream.  The RGB values will each vary between 0 and 255. &#x20;

### Widget Controls

The widget has one control, the color picker. Press and then slide the control across the colored zebra image to vary the RGB color values output to the datastream.

### Settings

The same settings apply to both modes of Simple and Advanced.

* **Send on release** - when enabled, the widget only send the RGB values when the user releases the control.

### How to process widget input on the hardware

When the widget control is pressed and moved, the value is sent and stored into the Blynk.Cloud. After that it's sent to your hardware.

#### Reading the widget value(s)

**Simple Mode**

```cpp
BLYNK_WRITE(V4) {   
  // Called when virtual pin V4 is updated by 
  // Blynk.App RGB widget. 
  int r = param.asInt();  // For datastream of data type integer
  //double r = param.asDouble();    // For datastream of data type double
  Serial.print("V4: R =");
  Serial.println(r);
} // BLYNK_WRITE(V4)


BLYNK_WRITE(V5) {   
  // Called when virtual pin V5 is updated by 
  // Blynk.App ZeRGBa widget. 
  int g = param.asInt();  // For datastream of data type integer
  //double g = param.asDouble();    // For datastream of data type double
  Serial.print("V5: g =");
  Serial.println(y);
} // BLYNK_WRITE(V5)


BLYNK_WRITE(V6) {   
  // Called when virtual pin V5 is updated by 
  // Blynk.App ZeRGBa widget. 
  int b = param.asInt();  // For datastream of data type integer
  //double b = param.asDouble();    // For datastream of data type double
  Serial.print("V5: b =");
  Serial.println(b);
} // BLYNK_WRITE(V6)
```

**Advanced Mode**

```cpp
BLYNK_WRITE(V2) {   
  // Called when virtual pin V2 is updated from the Blynk.App
  // V2 is a datastream of data type String assigned to a   
  // Blynk.App ZeRGBa widget.
  int r = param[0].asInt();
  int g = param[1].asInt();
  int b = param[2].asInt();
  Serial.print("V2: r = ");
  Serial.print(r);
  Serial.print("\t g=");
  Serial.print(g);
  Serial.print("\t b=");
  Serial.println(b);
} // BLYNK_WRITE(V2)
```

#### Changing the datastream value(s)

You can also change the datastream value with the hardware, resulting in a change to the widgets assigned to that datastream.

**Simple Mode**

If V1, V2, and V3 are datastreams of data type integer, and each assigned to the ZeRGBa widget a R, G, B respectively, then the following will set the color to Blynk green.

```cpp
Blynk.virtualWrite(V1, 35);
Blynk.virtualWrite(V2, 196);
Blynk.virtualWrite(V2, 142);
```

**Advanced Mode**

If V3 is a datastream of data type string, then the following code will position the color picker at Blynk green.

```cpp
Blynk.virtualWrite(V3, 35, 196, 142);
```



Sketch:[ Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

Sketch:[ ](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)[NeoPixel](https://github.com/blynkkk/blynk-library/blob/master/examples/More/NeoPixel/NeoPixel.ino)



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

You can change the properties “label”, “color”, “isDisabled” and “isHidden” of the widget from your hardware, or via an [HTTP API](broken-reference). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.

#### Set a custom label for the widget

```cpp
Blynk.setProperty(V1, "label", "Toggle");
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

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isDisabled=true`
{% endswagger-description %}

{% swagger-parameter in="query" name="token" type="string" required="true" %}
Device [auth token](../../concepts/device.md#authtoken) from Device info
{% endswagger-parameter %}

{% swagger-parameter in="query" name="pin" type="string" required="true" %}
The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="query" name="{property}" type="string" %}
The property of the widget you want to update: `label`,\
`isDisabled`, `isHidden`
{% endswagger-parameter %}

{% swagger-parameter in="path" name="{server address}" type="string" required="true" %}
Get from the bottom right of your Blynk console. [More information](../../blynk.cloud/device-https-api/troubleshooting.md).
{% endswagger-parameter %}

{% swagger-parameter in="query" name="label" type="string" %}
the text used as widget label
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

```cpp
BLYNK_CONNECTED() { 
  // Called when hardware is connected to Blynk.Cloud  

  // get the latest value for V1
  Blynk.syncVirtual(V1); 

  // Request Blynk server to re-send latest values for all pins
  Blynk.syncAll()
}
```

You can update your hardware to the latest datastream value from Blynk.Cloud after your hardware went offline, and then came online again. Use `Blynk.syncVirtual()` to update a single virtual pin, or `Blynk.syncAll()` to update all virtual pins. See [State Syncing](../../blynk.edgent-firmware-api/state-syncing.md) for more details.
