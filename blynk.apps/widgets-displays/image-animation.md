# Image Animation

This widget allows you to display an animated GIF or APNG image. From your hardware or the HTTP API you can change the image URL, and start and stop the animation.&#x20;

### Widget Controls

The widget has the following controls:

1. URL ADDRESS: The URL to either a GIF or APNG (animated PNG) file. The image will be shown in the preview area at the top of the page.&#x20;
2. Auto-Play: Play the animation once when the device is initially displayed in the app, or when the datastream value or properties ‘url’, ‘autoplay’, or ‘loop’ are changed.
3. Play in Loop: Repeats playing the animation from the start.&#x20;

### Datastream

Select or create a datastream of [data type](https://docs.blynk.io/en/blynk.console/templates/datastreams/datastreams-common-settings/data-type) string. The datastream value of “play” will cause the animation to play, and the value of “stop” will cause the animation to stop.

### Change Widget Properties

You can change the properties of the widget from your [hardware](https://docs.blynk.io/en/blynk.apps/widgets-app/button#change-button-properties) using the command:&#x20;

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

#### Properties you can change

You can change the properties ‘url’, ‘autoplay’, and ‘loop’” of the widget from your [hardware](https://docs.blynk.io/en/blynk.apps/widgets-app/button#change-button-properties), or via an [HTTP API](https://docs.blynk.io/en/blynk.cloud/update-property). Substitute ‘V2’ in the examples below with the datastream virtual pin reference (V0, V1 ...V255) you have configured for this widget. Make sure any string values are [URL encoded](https://en.wikipedia.org/wiki/URL\_encoding).&#x20;

```cpp
Blynk.setProperty(V2, "url", "https://mechatronicsolutionsllc.com/Blynk%20animated%20image%20beat%20(1).gif"); 
// Change image URL via hardware
```

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&url={your .gif URL}" method="get" summary="" %}
{% swagger-description %}
**Example:**

\




`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&url=https://mechatronicsolutionsllc.com/Blynk%20animated%20image%20breathing%20(1).gif`
{% endswagger-description %}

{% swagger-parameter in="path" name="pin" type="string" %}
Virtual pin number (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="path" name="url" type="string" %}
The URL where your .gif file is hosted
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
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



```cpp
Blynk.setProperty(V2, "autoplay", "true"); // Start the image animation
Blynk.setProperty(V2, "autoplay", "false"); // Stop the image animation
```

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&autoplay=true" method="get" summary="" %}
{% swagger-description %}
**Example:**

\




`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&autoplay=true`
{% endswagger-description %}

{% swagger-parameter in="path" name="pin" type="string" %}
Virtual pin number (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
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

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&autoplay=false" method="get" summary="" %}
{% swagger-description %}
**Example:**

\




`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&autoplay=false`
{% endswagger-description %}

{% swagger-parameter in="path" name="pin" type="string" %}
Virtual pin number (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
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



```cpp
Blynk.setProperty(V2, "loop", "true"); // Set the image to replay from the beginning
Blynk.setProperty(V2, "loop", "false"); // Set the image to stop at the end of the animation

```

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&loop=true" method="get" summary="" %}
{% swagger-description %}
**Example:**

\




`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&loop=true`
{% endswagger-description %}

{% swagger-parameter in="path" name="pin" type="string" %}
Virtual pin number (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
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

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&loop=false" method="get" summary="" %}
{% swagger-description %}
**Example:**

\




`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&loop=false`
{% endswagger-description %}

{% swagger-parameter in="path" name="pin" type="string" %}
Virtual pin number (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
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

Use the Blynk [HTTP API](https://docs.blynk.io/en/blynk.cloud/https-api-overview) to set the datastream value to “play” to cause the animation to play, and the value “stop” to cause the automation to stop playing.&#x20;

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&{your vPin}=stop" method="get" summary="" %}
{% swagger-description %}
**Example:**

\




`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&V2=stop`
{% endswagger-description %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
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

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&{your vPin}=play" method="get" summary="" %}
{% swagger-description %}
**Example:**

\




`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&V2=play`
{% endswagger-description %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
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



### Control hardware with datastream value

You can configure the hardware to respond to a change in a datastream value by configuring the `BLYNK_WRITE()` command.&#x20;

```cpp
BLYNK_WRITE(V2) // Called when the datastream value for V2 changes
{
 int pinValue = param.asInt(); // assigning incoming value from virtual pin V2 to a variable
 
 if (value=="play") {
 Serial.println("V2 'play' command received'");
 } else if (value=="stop") {
 Serial.println("V2 'stop' command received'");
 } else {
 Serial.print("Unexpected V2 value of: ");
 Serial.print(value);
 Serial.println("");
 }

}
```
