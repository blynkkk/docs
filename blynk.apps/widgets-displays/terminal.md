# Terminal

Displays the assigned datastream of data type string values since the app was last refreshed in a scrolling list. It optionally provides a text input area for the user to assign new values to the assigned datastream. Special commands are available for the hardware to assign data to the datastream using the print/println/write methods.&#x20;

{% hint style="info" %}
Note that the terminal display is cleared with every app refresh for Free plan.&#x20;

With **Plus plan** the widget stores up to 10 lines of historical data. It stores up to 25 lines with the **PRO plan**.
{% endhint %}

### Datastream

Select or create a datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) string.

### Widget Controls

The widget has the following controls:

* **Scroll** - drag the display area vertically to scroll the contents.
* **Text input field**: When ‘Input Line’ in settings is enabled, the text input field is displayed and allows the user to enter text that will update the assigned datastream. Note that any user input will have a “>” character before it in the widget display to differentiate it from values obtained from the datastream.

### Widget Settings

* **Input line** - when enabled, the text input area below the display is shown.
* **Add new line** - when enabled, a new line (CrLf) is added after content is entered into the text area.
* **Autoscroll** - when enabled, datastream content will be automatically scrolled to show the latest at the bottom of the display area.



### How to process widget with the hardware

The datastream value displayed is updated whenever the value stored on Blynk.Cloud changes.

#### Reading the widget value(s)

For a datastream of data type string assigned to V1:

```cpp
BLYNK_WRITE(V1) {
// Called when the datastream V1 value changes

// Assign incoming value from pin V1 to a variable
// String pinValue = param.asStr()
String pinValue = param.asString()

Serial.print(“V1: ‘“);
Serial.print(pinValue);
String.println(“‘“);
}
```

#### Changing the datastream value(s)

You can change the value of the datastream assigned to the widget with the hardware or HTTP API. For a datastream of data type string assigned to V1:

**Hardware:**

```cpp
Blynk.virtualWrite(V1, “my new datastream value”);
```

Or you can use the following special functions for this widget: &#x20;

```cpp
// Include Blynk library appropriate for your hardware
#include <BlynkSimpleEsp8266_SSL.h> // secure SSL version

// WidgetTerminal must follow Blynk library include
WidgetTerminal terminal(V1);	

void loop() {
  delay(30000);

  // Erase all values in the terminal
  terminal.clear(); 


  // Print values, like Serial.print
  terminal.print();   

  // Print values, like Serial.println()
  terminal.println();
 
  // Write a raw data buffer
  terminal.write();

  // Ensure that data was sent out of device
  terminal.flush();
	
}
```

**HTTP API:**

```cpp
https://{server_address}/external/api/update/?token={your 32 char token}&V1=my%20new%20datastream%20value
```

{% hint style="danger" %}
Don't put **`Blynk.virtualWrite()`**&#x69;nto the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, use flags, or [timers](../../blynk.edgent-firmware-api/blynk-timer.md).
{% endhint %}



Sketch:  [Terminal](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/Terminal/Terminal.ino)

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

You can change the properties _label_, _color_, _isDisabled_, _isHidden_ of the widget from your hardware, or via an [HTTP API](/broken/pages/-MboZKh3GURRjbTTpUUV). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.&#x20;

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
