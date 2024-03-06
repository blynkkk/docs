# Alarm & Sound Widget

{% hint style="info" %}
Available to PRO and Enterprise plans subscribers.
{% endhint %}

The alarm and sound widget creates an alarm in the Blynk.Console. It is triggered by a datastream value other than zero (0). &#x20;

### Datastream

Select or create a datastream of [data type integer](../templates/datastreams/datastreams-common-settings/data-type.md).&#x20;

You can change the ‘label’ property of the widget from your [hardware](../../blynk-library-firmware-api/widget-properties.md), or via an [HTTP API](../../blynk.cloud/device-https-api/update-property.md).  &#x20;

### Widget Controls

The alarm and sound widget has the following controls:

* **On / Off:** Disables (mutes) the alarm, or resets it. &#x20;
* **Alarm Sound:**  When the ‘Allow end-user to change the sound’ widget option is enabled, the user can select the alarm sound to be played when the alarm is triggered.&#x20;

### How to trigger the alarm from the hardware

```cpp
Blynk.virtualWrite(V1, HIGH);
```

or

```cpp
Blynk.virtualWrite(V1, 1);
```

Any integer value other than zero (0) will trigger the alarm.  The alarm can be disabled by changing the datastream value to zero (0) by using the `Blynk.virtualWrite()` command.&#x20;

Find full code examples of using `Blynk.virtualWrite()` for your hardware [here](https://examples.blynk.cc/?board=ESP32\&shield=ESP32%20WiFi\&example=GettingStarted%2FGetData).

### Change Alarm and Sound Properties

You can change certain properties of the widget from your hardware using the command:&#x20;

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

You can change the properties “label”, “isHidden” and “isMuted” of the widget from your [hardware](../../blynk-library-firmware-api/widget-properties.md), or via an [HTTP API](../../blynk.cloud/device-https-api/update-property.md). The “isMuted” property is unique to the Alarm and Sound widget and will enable or disable the mute option for the Alarm and Sound widget.&#x20;

```cpp
Blynk.setProperty(V1, "isMuted", "true");
```

```
https://{server_address}/external/api/update/property?token={your 32 char token}&pin=V1&isMuted=true
```

```cpp
Blynk.setProperty(V1, "label", "AlarmnSoundWidget");
```

```
https://{server_address}/external/api/update/property?token={your 32 char token}&pin=V1&label=AlarmnSoundWidget
```

### Sync to the latest datastream value

Get the latest known value from the server. For example, after your hardware went offline and then came online again.

```cpp
BLYNK_CONNECTED() { // checks if there is a connection to Blynk.Cloud  
  Blynk.syncVirtual(V1); // get the latest value
}
```

```cpp
BLYNK_WRITE(V1) // this command is listening when something is written to V1
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  
  if (pinValue = 1){
   // do something when the sound and alarm widget is triggered.
  } else if {
  (pinValue = 0)
   // do something when the sound and alarm widget is disabled.
  }
}
```
