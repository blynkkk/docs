# Joystick

This widget allows you to control something in four directions, such as a pair of servos or electric motors.

### Mode

For both modes, the joystick will update the datastream(s) with the minimum X to the left, the maximum X to the right, the minimum Y to the bottom, and the maximum Y to the top.

**Simple** - Assign one datastream each to the X and Y directions of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) integer or double. The output from the joystick movement will vary between the datastream min and max values.

**Advanced** - Assign one datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) string. In the hardware, you access the X and Y direction values from the datastream. The X and Y values will vary between 0 and 255.

### Widget Controls

The widget has one control, the joystick. Press and then slide the joystick radially from the center position to change the X and Y direction outputs.

### Settings

The same settings apply to both modes of Simple and Advanced.

* **Autoreturn** - when enabled, the joystick will return to the center position after it is released by the user. &#x20;
* **Rotate on tilt** - when enabled, the output from the joystick will keep the X and Y directions aligned relative to the smartphone screen orientation (portrait / landscape).

### How to process widget input on the hardware

When the joystick is pressed and moved, the value is sent and stored into the Blynk.Cloud. After that it's sent to your hardware.

#### Reading the widget value

**Simple Mode**

```cpp
BLYNK_WRITE(V4) {   
  // Called when virtual pin V4 is updated by 
  // Blynk.App joystick widget. 
  int x = param.asInt();  // For datastream of data type integer
  //double x = param.asDouble();    // For datastream of data type double
  Serial.print("V4: x =");
  Serial.println(x);
} // BLYNK_WRITE(V4)


BLYNK_WRITE(V5) {   
  // Called when virtual pin V5 is updated by 
  // Blynk.App joystick widget. 
  int y = param.asInt();  // For datastream of data type integer
  //double y = param.asDouble();    // For datastream of data type double
  Serial.print("V5: y =");
  Serial.println(y);
} // BLYNK_WRITE(V5)
```

**Advanced Mode**

```cpp
BLYNK_WRITE(V2) {   
  // Called when virtual pin V2 is updated from the Blynk.App
  // V2 is a datastream of data type String assigned to a   
  // Blynk.App joystick widget.
  int x = param[0].asInt();
  int y = param[1].asInt();
  Serial.print("V2: x = ");
  Serial.print(x);
  Serial.print("\t y=");
  Serial.println(y);
} // BLYNK_WRITE(V2)
```



#### Changing the datastream value(s)

You can also change the datastream value with the hardware, resulting in a change to the widgets assigned to that datastream.

**Simple Mode**

If V1 and V2 are datastreams of data type integer with the minimum value set to 0 and the maximum set to 255, and V1 is assigned to the joystick X direction, and V2 is assigned to the joystick Y direction, then the following code will move the joystick to the left and upward:

```cpp
Blynk.virtualWrite(V1, 0);
Blynk.virtualWrite(V2, 255);
```

**Advanced Mode**

If V3 is a datastream of data type string, then the following code will move the joystick to the left and upward position:

```cpp
Blynk.virtualWrite(V3, 0, 255);
```



Sketch:[ ](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)[Joystick](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/Joystick/Joystick.ino)

Sketch:[ ](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)[Servo](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/Servo/Servo.ino)



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
Don't put **`Blynk.setProperty()`**&#x69;nto the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers.
{% endhint %}

### Properties you can change

You can change the properties “label”, “color”, “isDisabled” and “isHidden” of the widget from your hardware, or via an [HTTP API](/broken/pages/-MboZKh3GURRjbTTpUUV). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.

#### Set a custom label for the widget

```cpp
Blynk.setProperty(V1, "label", "Toggle");
```

#### **Color**

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

## Updates the Datastream Property and all assigned Widgets

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}`

The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&label=My%20Label`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&color=%23D3435C`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isDisabled=true`

#### Path Parameters

| Name                                               | Type   | Description                                                                                                                 |
| -------------------------------------------------- | ------ | --------------------------------------------------------------------------------------------------------------------------- |
| {server address}<mark style="color:red;">\*</mark> | string | Get from the bottom right of your Blynk console. [More information](../../blynk.cloud/device-https-api/troubleshooting.md). |

#### Query Parameters

| Name                                    | Type   | Description                                                                                                                                     |
| --------------------------------------- | ------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| token<mark style="color:red;">\*</mark> | string | Device [auth token](../../concepts/device.md#authtoken) from Device info                                                                        |
| pin<mark style="color:red;">\*</mark>   | string | The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v")                                  |
| {property}                              | string | <p>The property of the widget you want to update: <code>label</code>, <code>color</code>,<br><code>isDisabled</code>, <code>isHidden</code></p> |
| label                                   | string | the text used as widget label                                                                                                                   |
| isDisabled                              | string | true or false                                                                                                                                   |
| isHidden                                | string | true or false                                                                                                                                   |
| color                                   | string | color hexadecimal, must include the hash # character urlencoded as %23                                                                          |

{% tabs %}
{% tab title="200 Success" %}
```
```
{% endtab %}

{% tab title="400 Could not find a device token" %}
```
{"error":{"message":"Invalid token."}}
```
{% endtab %}
{% endtabs %}

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
