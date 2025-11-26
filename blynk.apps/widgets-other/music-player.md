# Music Player

Simulates a music player interface and sends play, stop, prev, next commands to the hardware. The interface also updates in response to command updates to the datastream from the hardware, Blynk.Console, or HTTP API.

### Datastream

Select or create a datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) string.

### Widget Controls

The widget has the following controls:

1. **Play:** Sends the string command “play” to the hardware via the datastream.
2. **Stop:** Sends the string command “stop” to the hardware via the datastream.
3. **Prev:** Sends the string command “prev” to the hardware via the datastream.
4. **Next:** Sends the string command “next” to the hardware via the datastream.

### How to process button input on the device

When button is pressed, value is sent and stored into the Blynk.Cloud. After that it's sent to your device.

#### Reading the widget value(s)

For example, if Music Player is set to Datastream with Virtual Pin V2, you can use such code:

```cpp
BLYNK_WRITE(V2) {   
  // Called when the datastream virtual pin V2 is updated 
  // by Blynk.Console, Blynk.App, or HTTP API. 

  String value = param.asStr();
  // OR:
  //String value = param.asString();

  if (value == "play") {
    Serial.println("'play' button pressed");    
  } else if (value == "stop") {
    Serial.println("'stop' button pressed");        
  } else if (value == "prev") {
    Serial.println("'prev' button pressed");    
  } else if (value == "next") {
    Serial.println("'next' button pressed");    
  } else {
    Serial.print("V2 = '");
    Serial.print(value);
    Serial.println("'");    
  }
    
} // BLYNK_WRITE()
```

#### Changing the datastream values

```cpp
void EndOfMusicFile() {
  // The end of the music file has been reached.
  // Set the datastream to "stop"
  
  Blynk.virtualWrite(V2, "stop");

  // NOTE: Legacy property below is obsolete.
  //Blynk.setProperty(V2, "isOnPlay", "false");
  
} // EndOfMusicFile()
```

Sketch:[ ](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)[Music Player](https://github.com/blynkkk/blynk-library/blob/master/examples/Widgets/MusicPlayer/MusicPlayer.ino)



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
