# Time input

This widget allows the user to interactively specify a time value simply as hours and minutes, or in detail with the day of the week, sunrise/sunset, and/or timezone. A single time selection, or both start/stop times may be configured for input.

### Datastream

Select or create a datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) string.

### Widget Controls

When the widget is tapped, a window pops up that allows the user to interactively specify the time value in 24 hour format. Make sure to tap the “OK” button at the top right when the input is finished.

### Widget Settings

* **TIME FORMAT** - choose a time display format from the options of:  HH:mm, HH:mm:ss, HH:mm - aa, HH:mm:ss -aa. All in 24 hour format.
* **Allow start/stop input** - when disabled, only one time input is presented. When enabled, both start and stop time input is presented.
* **Allow day of week selection** - presents the days of the week Sun .. Sat for the user to select from when enabled. The selection is displayed in the lower left of the widget.
* **Allow sunset/sunrise selection** - adds option of sunrise or sunset to the start/stop selection.
* **Allow timezone selection** - adds an option of selecting the time zone from a list.

### How to process widget with the hardware

When the number is entered into the widget input field or +/- tapped, the new value is sent and stored into the Blynk.Cloud. After that it's sent to your device.

#### Reading the widget value(s)

The time selections are assigned to the datastream as an array with four elements (0..3).

```cpp
BLYNK_WRITE(V1) {
// Called when the datastream V1 value changes

// param[0] is the user time value selected in seconds.
Serial.print("Start time in sec: "); Serial.println(param[0].asInt());
  
// param[1] is the stop time in seconds (when option enabled)
Serial.print("Stop time in sec: "); Serial.println(param[1].asInt());
  
// param[2] is the timezone (Ex. "America/New_York")
Serial.print("Timezone: "); Serial.println(param[2].asStr());

// param[3] is the day of the week where 0=Sun .. 6=Sat
Serial.print("Day of week: : "); Serial.println(param[3].asInt());

// param[4] is the time zone offset from UTC in seconds
Serial.print("param[4].asStr(): ");      Serial.println(param[4].asInt());

}
```

**HTTP API call :**

```cpp
https://{server_address}/external/api/get/?token={your 32 char token}&V1
```

#### Changing the datastream value(s)

You can change the value of the datastream assigned to the widget with the hardware or HTTP API.

For a datastream V1 assigned data type of \[string/integer/double/enum/location]:

**Hardware:**

```cpp
uint32_t start_sec = 3660;  //1 hr, 1 min
uint32_t stop_sec = 3720; //1 hr, 2 min
String tz = "America/New_York";
uint8_t dow = 1;  // Day of Week; 0=Sun .. 6=Sat
int32_t utc_offset = -144000; // UTC offset in seconds
Blynk.virtualWrite(V2, start_sec, stop_sec, tz, dow, utc_offset);
```

**HTTP API:**

```cpp
https://{server_address}/external/api/update/?token={your 32 char token}&V1=3660&V1=3720&V1=America/New_York&V1=1&V1=-144000
```

{% hint style="danger" %}
Don't put **`Blynk.virtualWrite()`**into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, use flags, or [timers](../../blynk-library-firmware-api/blynk-timer.md).
{% endhint %}



Sketch:  [SimpleTimeInput](https://github.com/blynkkk/blynk-library/tree/master/examples/Widgets/TimeInput/SimpleTimeInput)

Sketch:  [AdvancedTimeInput](https://github.com/blynkkk/blynk-library/tree/master/examples/Widgets/TimeInput/AdvancedTimeInput)

Sketch:  [UpdateTimeInputState](https://github.com/blynkkk/blynk-library/tree/master/examples/Widgets/TimeInput/UpdateTimeInputState)



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

You can change the properties _label_, _color_, _isDisabled_, _isHidden_ of the widget from your hardware, or via an [HTTP API](broken-reference). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.&#x20;

#### **Change Widget Label**

```cpp
Blynk.setProperty(V1, "label", "Air temperature");
```

#### **Set Text Color**

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

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}" method="get" summary="Updates the Datastream Property and all assigned Widgets" %}
{% swagger-description %}
The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&label=My%20Label`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&color=%23D3435C`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isDisabled=true`
{% endswagger-description %}

{% swagger-parameter in="query" name="token" type="string" required="true" %}
Device [auth token](../../concepts/device.md#authtoken) from Device info
{% endswagger-parameter %}

{% swagger-parameter in="query" name="pin" type="string" required="true" %}
The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="query" name="{property}" type="string" %}
The property of the widget you want to update: `label`, `color`, `isDisabled`, `isHidden`
{% endswagger-parameter %}

{% swagger-parameter in="path" name="{server address}" type="string" required="true" %}
Get from the bottom right of your Blynk console. [More information](../../blynk.cloud/device-https-api/troubleshooting.md).
{% endswagger-parameter %}

{% swagger-parameter in="query" name="label" type="string" %}
the text used as widget label
{% endswagger-parameter %}

{% swagger-parameter in="query" name="color" type="string" %}
button color hexadecimal, must include the hash # character urlencoded as %23
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

You can update your hardware to the latest datastream value from Blynk.Cloud after your hardware went offline, and then came online again. Use `Blynk.syncVirtual()` to update a single virtual pin, or `Blynk.syncAll()` to update all virtual pins. See [State Syncing](../../blynk-library-firmware-api/state-syncing.md) for more details.

```cpp
BLYNK_CONNECTED() { 
  // Called when hardware is connected to Blynk.Cloud  

  // get the latest value for V1
  Blynk.syncVirtual(V1); 

  // Request Blynk server to re-send latest values for all pins
  Blynk.syncAll()
}
```
