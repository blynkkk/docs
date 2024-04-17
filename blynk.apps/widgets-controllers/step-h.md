# Step H

A horizontal widget that increments or decrements the datastream value in increments of a step value when the user taps on either the ‘+’ or ‘-’ icons.  It can also be configured to send the step value itself.

### Datastream

Select or create a datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) integer or double. Widget properties (label, color, etc.) are also changed via the datastream, but only for virtual, enumerable, and location pins, not digital and analog pins.

### Settings

* **Step** - the increment/decrement value to be applied to the assigned datastream.&#x20;
* **Send step** - when enabled, sends the step value rather than the incremented/decremented datastream value. &#x20;
* **Loop values** - set the assigned datastream value to its minimum value when the next applied step value would reach the datastream maximum value.

### Widget Controls

The widget has the following controls:

1. **+ button**: Increments the datastream value by step if ‘Send step’ is disabled, otherwise sends the step value when ‘Send step’ is enabled.
2. **- button**: Decrements the datastream value by step if ‘Send step’ is disabled, otherwise sends the step value when ‘Send step’ is enabled.

### How to process widget input on the device

When the control is pressed, value is sent and stored into the Blynk.Cloud. After that it's sent to your device.

#### Reading the widget value

For example, if Slider widget is set to Datastream with Virtual Pin V1, you can use such code:

```cpp
BLYNK_WRITE(V1) // this command is listening when something is written to V1
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  
  if (pinValue == 1){
   // do something when the control is pressed;
  } else if (pinValue == 0) {
   // do something when the control is released;
  }
  
  Serial.print("V1 value is: "); // printing value to serial monitor
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

You can change the properties _step_, _color_, _label_, _isDisabled_, _isHidden_, and _page_ of the widget from your hardware, or via an [HTTP API](broken-reference). The color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.

#### Set a custom step

```cpp
Blynk.setProperty(V1, "step", "10");
```

Set a custom step or datastream value increment/decrement.&#x20;

#### Set a custom label for the widget

```cpp
Blynk.setProperty(V1, "label", "Status");
```

#### **Show/Hide**

```cpp
Blynk.setProperty(V1, "isHidden", true);
```

Widget will be hidden from dashboard. Design your UI so that it doesn't look weird when there is no widget.

#### **Disable/Enable**

```cpp
Blynk.setProperty(V1, "isDisabled", true);
```

Widget will be greyed out on UI and users won't be able to tap on it.

#### Change color of the +/- button icons

```cpp
Blynk.setProperty(V1, "color", "#73D13D");  // green
Blynk.setProperty(V1, "color", "#ED9D00");  // orange
```



### Change widget properties via HTTPs API

## Updates the Datastream Property and all assigned Widgets

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}`

The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&step=10`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&label=My%20Label`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&color=%23D3435C`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isDisabled=true`

#### Path Parameters

| Name                                               | Type   | Description                                                                                                                 |
| -------------------------------------------------- | ------ | --------------------------------------------------------------------------------------------------------------------------- |
| {server address}<mark style="color:red;">\*</mark> | string | Get from the bottom right of your Blynk console. [More information](../../blynk.cloud/device-https-api/troubleshooting.md). |

#### Query Parameters

| Name                                    | Type   | Description                                                                                                      |
| --------------------------------------- | ------ | ---------------------------------------------------------------------------------------------------------------- |
| token<mark style="color:red;">\*</mark> | string | Device [auth token](../../concepts/device.md#authtoken) from Device info                                         |
| pin<mark style="color:red;">\*</mark>   | string | The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v")   |
| {property}                              | string | The property of the widget you want to update: `step`, `label`, `color`, `isDisabled`, `isHidden`                |
| label                                   | string | the text used as widget label                                                                                    |
| isDisabled                              | string | true or false                                                                                                    |
| isHidden                                | string | true or false                                                                                                    |
| color                                   | string | change the color of the +/- button icons, color hexadecimal, must include the hash # character urlencoded as %23 |
| step                                    | string | Set a custom step or datastream value increment/decrement                                                        |

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



### Sync to the latest known state

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
