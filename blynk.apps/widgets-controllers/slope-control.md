# Slope Control

Allows you to interactively specify a linear slope for the control of actuators and other devices.



### Datastream

Select or create a datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) string. Widget properties (label, color, etc.) are also changed via the datastream, but only for virtual, enumerable, and location pins, not digital and analog pins.



### Widget Controls

The widget has the following controls:

1. **X1,Y1 coordinate handle**: drag to set the X1, Y1 coordinate position on the grid.&#x20;
2. **X2, Y2 coordinate handle**: drag to set the X2, Y2 coordinate position on the grid.&#x20;

### Widget Settings

* **Send on release** - updates the assigned datastream only when the handle is released by the user (recommended).
* X & Y Axis:
  * **X MIN, X MAX, Y MIN, Y MAX** - The X & Y Axis min/max values are limited to the range of 0 and 100.  The X & Y axis graph range can be limited more by adjusting the MIN and MAX limits for the X and Y Axis.
  * **X GRID, Y GRID** - defines the spacing of the grid shown. &#x20;
  * **X MOVE STEP, Y MOVE STEP** - defines the increment the X & Y points change when the coordinate handles are dragged by the user.
* Points:
  * **X1, Y1, X1, Y2** - customize the label shown for each x,y coordinate.
  * **X1 MIN, Y1 MIN, X2 MIN, Y2 MIN** - limits the min/max value the user can choose on the grid.&#x20;

### How to process widget with the hardware

When widget is pressed, value is sent and stored into the Blynk.Cloud. After that it's sent to your device.

#### Reading the widget value

For example, if the Widget is set to Datastream with Virtual Pin V1, you can use such code:

```cpp
BLYNK_WRITE(V1) {
  // Called when the datastream V1 value changes

  // Assign incoming value from pin V1 to a variable
  uint8_t x1 = param[0].asInt();
  uint8_t y1 = param[1].asInt();
  uint8_t x2 = param[2].asInt();
  uint8_t y2 = param[3].asInt();
  Serial.print("x1: "); Serial.println(x1);
  Serial.print("y1: "); Serial.println(y1);
  Serial.print("x2: "); Serial.println(x2);
  Serial.print("y2: "); Serial.println(y2);

  // WARNING: delta X (x2 - x1) can be zero!
  // slope = (y2 - y1) / (x2 - x1)
  double m = ((double)y2-(double)y1)/((double)x2-(double)x1);
  // intercept = y - m * x
  double b = (double)y1 - m * (double)x1;
  Serial.print("y = "); Serial.print(m,3); Serial.print(" * x + "); Serial.println(b,3);

}
```



#### Changing the datastream value(s)

You can change the value of the datastream assigned to the widget with the hardware or HTTP API.  For a datastream V1 assigned data type of string to the Slope widget.

**Hardware:**

```cpp
uint8_t x1 = 10;
uint8_t y1 = 15;
uint8_t x2 = 65;
uint8_t y2 = 70;
Blynk.virtualWrite(V1, x1, y1, x2, y2);
```

**HTTP API:**

```cpp
https://{server_address}/external/api/update/?token={your 32 char token}&V1=10&V1=15&V1=65&V1=70
```

{% hint style="danger" %}
Don't put **`Blynk.virtualWrite()`**&#x69;nto the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, use flags, or [timers](../../blynk.edgent-firmware-api/blynk-timer.md).
{% endhint %}

Sketch:[ Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

Sketch:[ ](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)[Set Property](https://github.com/blynkkk/blynk-library/blob/master/examples/More/SetProperty/SetProperty_SingleValue/SetProperty_SingleValue.ino)

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
Don't put **`Blynk.setProperty()`**&#x69;nto the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers.
{% endhint %}



### Properties you can change

You can change the properties _label_, _color_, _isDisabled_, _isHidden_ of the widget from your hardware, or via an [HTTP API](/broken/pages/-MboZKh3GURRjbTTpUUV). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.

#### **Change Widget Label**

```cpp
Blynk.setProperty(V1, "label", "Air temperature");
```

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

| Name                                    | Type   | Description                                                                                                    |
| --------------------------------------- | ------ | -------------------------------------------------------------------------------------------------------------- |
| token<mark style="color:red;">\*</mark> | string | Device [auth token](../../concepts/device.md#authtoken) from Device info                                       |
| pin<mark style="color:red;">\*</mark>   | string | The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v") |
| {property}                              | string | The property of the widget you want to update: `label`, `color`, `isDisabled`, `isHidden`                      |
| label                                   | string | the text used as widget label                                                                                  |
| color                                   | string | button color hexadecimal, must include the hash # character urlencoded as %23                                  |
| isDisabled                              | string | true or false                                                                                                  |
| isHidden                                | string | true or false                                                                                                  |

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
