# Image Gallery

Displays one or more images specified by a HTTPS URL. You can change the image shown by configuring a datastream of type integer and then changing the datastream value to correspond to the image URL index (beginning at 0). If only one image URL is assigned, then the datastream value is ignored. Make sure to encode the image URL.

### Datastream

Select or create a datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) integer.

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

You can update the assigned datastream value using the hardware or HTTP API. You can change the image shown by changing the datastream value to correspond to the image URL index (beginning at 0). If only one image URL is assigned, then the datastream value is ignored. Make sure to encode the image URL.

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

You can change the properties _label_, _isDisabled_, _isHidden_ of the widget from your hardware, or via an [HTTP API](broken-reference). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.&#x20;

#### **Change Widget Label**

```cpp
Blynk.setProperty(V1, "label", "Air temperature");
```



**Change Opacity, Scale, Rotation**

```cpp
Blynk.setProperty(V1, "opacity", 50); // 0-100%
```

```cpp
Blynk.setProperty(V1, "scale", 30); // 0-100%
```

```cpp
Blynk.setProperty(V1, "rotation", 10); //0-360 degrees
```



**Change Images**

Change the individual image by its index:

<pre class="language-cpp"><code class="lang-cpp"><strong>Blynk.setProperty(V1, "url", 1, "https://image1.jpg");
</strong></code></pre>

Change a list of URLs for the widget. First image will have index `0`, next `1`, and so on.&#x20;

```cpp
Blynk.setProperty(V1, "urls", "https://image1.jpg", "https://image2.jpg");
```

{% hint style="warning" %}
Make sure you not exceed the max string size of 255 chars when sending a long list of URLs&#x20;
{% endhint %}

You can also use images from uploaded [assets.md](../../blynk.console/templates/assets.md "mention") by referencing its id:

```
Blynk.setProperty(V1, "url", 1, "template_asset://id");
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

<mark style="color:blue;">`GET`</mark>&#x20;

```
https://{server_address}/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}
```

The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Examples:**

```
https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&label=My%20Label
```

```
https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isDisabled=true
```

```html
https://blynk.cloud/external/api/update/property?token={token}&pin={pin}&url={index}&url={url}
```

```
https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&url=2&url=https://image%202.jpg
```

```
https://blynk.cloud/external/api/update/property?token={token}&pin={pin}&urls={url1}&urls={url2}&urls={url3}
```

```
https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&urls=https://image%201.jpg&urls=https://image%202.jpg&urls=https://image%203.jpg
```

####

#### Path Parameters

| Name                                               | Type   | Description                                                                                                                 |
| -------------------------------------------------- | ------ | --------------------------------------------------------------------------------------------------------------------------- |
| {server address}<mark style="color:red;">\*</mark> | string | Get from the bottom right of your Blynk console. [More information](../../blynk.cloud/device-https-api/troubleshooting.md). |

#### Query Parameters

| Name                                    | Type   | Description                                                                                                    |
| --------------------------------------- | ------ | -------------------------------------------------------------------------------------------------------------- |
| token<mark style="color:red;">\*</mark> | string | Device [auth token](../../concepts/device.md#authtoken) from Device info                                       |
| pin<mark style="color:red;">\*</mark>   | string | The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v") |
| {property}                              | string | The property of the widget you want to update: `label`, `isDisabled`, `isHidden`, `url`, `urls`                |
| label                                   | string | the text used as widget label                                                                                  |
| isDisabled                              | string | true or false                                                                                                  |
| isHidden                                | string | true or false                                                                                                  |
| url                                     | string | Replace image by its index. Indexes start from 0. URL should be urlencoded                                     |
| urls                                    | string | Replace the whole set of images with the new set of URLs. The URLs should be urlencoded                        |

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
