# RGB Light Control

This widget is intended to allow you to control an RGB connected to your hardware. It not only allows you to dynamically set the color, but you can also turn the RGB on/off, set the brightness, and choose custom animation effects. &#x20;

### Datastream

Four datastreams are required for this widget:

1. **COLOR** - select or create a datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) string for the color.  The three RGB color values are independently available to be read by the hardware.&#x20;
2. **BUTTON** - select or create a datastream of data type integer or double with the minimum and maximum values that will turn on/off the RGB connected to the hardware..
3. **BRIGHTNESS** - select or create a datastream of data type integer or double to represent the color intensity, with a minimum value of 0 and a maximum value of 100. &#x20;
4. **ANIMATION SPEED** - select or create a datastream of data type integer or double with a range of values from 0 to 10,000.&#x20;

Widget properties (label, color, etc.) are also changed via the datastreams, but only for virtual, enumerable, and location pins, not digital and analog pins.&#x20;

### Mode

The Color Circle displays a rainbow of colors. The user moves the Color Picker radially around the Color Circle to choose a particular color. Tap one of three radio buttons to select between the Color, White, and Animation modes.

* **Color Mode**: The user selects a hue/color on the Color Circle using the Color Picker. The Radial Slider allows the user to select a **luminance** (brightness) varying from 0 to 100.
* **White Mode**: When the ‘White Tints’ option is selected, white tints may be selected with the Color Picker (red 219 to 255, green 219 to 255, blue 169 to 255). When the ‘White Only’ option is selected, the Color Picker is disabled, the RGB values are set to white, and only the brightness may be adjusted with the radial slider. &#x20;
* **Animation Mode**: Choose the animation type by selecting the Strobe/Fade button, or the Change button for a pattern selection. The radial slider sets the animation speed in the range of 0 to 1000.  The Color Picker is disabled.

{% hint style="info" %}
The RGB Light Control widget in Color Mode or White Mode with White Tints option generates RGB color values for a common cathode RGB.  If you are using a common anode RGB with your hardware, then you need to adjust the values in your firmware by subtracting each of them from 255.
{% endhint %}

### Settings

* **WHITE MODE** - The ‘White Tints’ option allows you to choose white tints with the Color Picker. The ‘White Only’ disables the Color Picker and only the white brightness may be adjusted with the radial slider. &#x20;
* **Send on release** - enable to only update the datastreams when the control is released by the user (recommended). Otherwise the datastreams will be continuously updated based on the color chosen until the control is released.

Sketch:[ Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

Sketch:[ ](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)[NeoPixel](https://github.com/blynkkk/blynk-library/blob/master/examples/More/NeoPixel/NeoPixel.ino)

[Detailed guide with the firmware example](https://blynk.io/blog/rgb-control-widget) in our blog post.\


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

You can change the properties “isDisabled” and “isHidden” of the widget from your hardware, or via an [HTTP API](broken-reference). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.&#x20;

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

**Example:**

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
| {property}                              | string | The property of the widget you want to update: `isDisabled`, `isHidden`                                        |
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
