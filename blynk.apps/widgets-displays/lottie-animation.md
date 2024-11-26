# Lottie Animation

{% hint style="info" %}
Available to PRO and higher subscribers.
{% endhint %}

This widget allows you to display an animated Lottie image. Lottie is a JSON based file format for vector graphics animation.  It is intended as a lighter alternative to other [animated graphic](image-animation.md) file formats (GIF, APNG, ...).  It is commonly used in applications and web pages.

<figure><img src="../../.gitbook/assets/Animation-docs-1.gif" alt="" width="375"><figcaption></figcaption></figure>

### Widget Controls

The widget has the following controls:

1. URL ADDRESS: The URL to .json file.
2. Auto-Play: Play the animation once when the device is initially displayed in the app.&#x20;
3. Play in Loop: Play the animation repeatedly.\


### Datastream

Select or create a datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) string. The datastream value of “play” will cause the animation to play, and the value of “stop” will cause the animation to stop.&#x20;

### Change Widget Properties

You can change the properties of the widget from your hardware using the command:&#x20;

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



#### Properties you can change

You can change the properties _url_, _autoplay_, and _loop_ of the widget from your hardware, or via an [HTTP API](../../blynk.cloud/device-https-api/update-property.md). Substitute ‘V2’ in the examples below with the datastream virtual pin reference (V0, V1 ...V255) you have configured for this widget. Make sure any string values are [URL encoded](https://en.wikipedia.org/wiki/URL_encoding).&#x20;

```cpp
Blynk.setProperty(V2, "url", "https://mechatronicsolutionsllc.com/Blynk_animated_image_breathing.json"); 
// Change image URL via hardware
```

```cpp
Blynk.setProperty(V2, "autoplay", "true"); // Start the image animation
Blynk.setProperty(V2, "autoplay", "false"); // Stop the image animation
```

```cpp
Blynk.setProperty(V2, "loop", "true"); // Set the image to replay from the beginning
Blynk.setProperty(V2, "loop", "false"); // Set the image to stop at the end of the animation

```

### Change widget properties via HTTPs API

## Updates the Datastream Property and all assigned Widgets

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}`

The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&autoplay=true`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&url=https://mechatronicsolutionsllc.com/Blynk%20animated%20image%20beat%20(1).gif`

#### Path Parameters

| Name                                               | Type   | Description                                                                                                                 |
| -------------------------------------------------- | ------ | --------------------------------------------------------------------------------------------------------------------------- |
| {server address}<mark style="color:red;">\*</mark> | string | Get from the bottom right of your Blynk console. [More information](../../blynk.cloud/device-https-api/troubleshooting.md). |

#### Query Parameters

| Name                                    | Type   | Description                                                                                                    |
| --------------------------------------- | ------ | -------------------------------------------------------------------------------------------------------------- |
| token<mark style="color:red;">\*</mark> | string | Device [auth token](../../concepts/device.md#authtoken) from Device info                                       |
| pin<mark style="color:red;">\*</mark>   | string | The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v") |
| property                                | string | The property of the widget you want to update: `autoplay`, `loop`, `url`                                       |
| autoplay                                | string | true or false                                                                                                  |
| loop                                    | string | true or false                                                                                                  |
| url                                     | string | the image URL, should be urlencoded                                                                            |

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



### Sync hardware to the latest datastream value

You can update your hardware to the latest datastream value from Blynk.Cloud after your hardware went offline, and then came online again.

```cpp
BLYNK_CONNECTED() { // Executes every time Blynk is connected to the Blynk.Cloud 
 Blynk.syncVirtual(V2); // Synchronize variable V2 with the latest value stored in Blynk.Cloud
}
```

### Change the datastream value with the hardware

Use the `Blynk.virtualWrite()` command to set the datastream value to “play” to cause the animation to play, and the value “stop” to cause the automation to stop playing.&#x20;

```cpp
const uint32_t TIMER_INTERVAL_V_MS = 15000;
uint32_t timerLastVn = 0;
uint8_t toggle = 0;


void timerVn(uint8_t vPin) {
 if (timerLastVn > millis()) timerLastVn = millis();
 if ((millis() - timerLastVn) > TIMER_INTERVAL_V_MS) { 
 if (toggle == 1) {
 toggle = 0;
 Blynk.virtualWrite(vPin, "play"); // play animation
 } else { // toggle == 0
 toggle = 1;
 Blynk.virtualWrite(vPin, "stop"); // stop animation
 }
 timerLastVn = millis(); 
 } 
} // timerVn()


void setup() {
} // setup()


void loop() {
 timerVn(V2)
} // loop()

```

### Change the datastream value with the HTTP API

Use the Blynk HTTP API to set the datastream value to _play_ to cause the animation to play, and the value _stop_ to cause the automation to stop playing.

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/update/property?token={your 32 char token}&{pin}={value}`

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&V2=stop`

#### Path Parameters

| Name                                               | Type   | Description                                                                                                                 |
| -------------------------------------------------- | ------ | --------------------------------------------------------------------------------------------------------------------------- |
| {server address}<mark style="color:red;">\*</mark> | string | Get from the bottom right of your Blynk console. [More information](../../blynk.cloud/device-https-api/troubleshooting.md). |

#### Query Parameters

| Name                                    | Type   | Description                                                                                                    |
| --------------------------------------- | ------ | -------------------------------------------------------------------------------------------------------------- |
| token<mark style="color:red;">\*</mark> | string | Device [auth token](../../concepts/device.md#authtoken) from Device info                                       |
| pin<mark style="color:red;">\*</mark>   | string | The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v") |
| value                                   | string | The desired value of the pin (play or stop)                                                                    |

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



### Control hardware with datastream value

You can configure the hardware to respond to a change in a datastream value by configuring the `BLYNK_WRITE()` command.&#x20;

```cpp
BLYNK_WRITE(V1) {
 // Called when the datastream value for V1 changes
 String value = param.asStr();
 if (value=="play") {
  Serial.println("V1 'play' command received'");
 } else if (value=="stop") {
  Serial.println("V1 'stop' command received'");
 } else {
  Serial.print("Unexpected V1 value of: ");
  Serial.print(value);
  Serial.println("");
 }
}
```
