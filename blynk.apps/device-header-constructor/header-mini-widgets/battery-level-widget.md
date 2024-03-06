# Battery Level widget

This widget provides a clear visual representation of your battery level, accompanied by a percentage indicator for quick reference.

<figure><img src="../../../.gitbook/assets/battery-level-mobile-header-widget.png" alt=""><figcaption></figcaption></figure>

### Settings

**Datastream** - Select or create a datastream of data type `integer` or `double`. Value should come in 0-100 range.

**Show value** - You can show the battery % value. Turn it off to see just the icon.



### **Properties you can change**

You can hide/show header widgets from device. Use `isHidden` property API:

```
Blynk.setProperty(vPin, "isHidden", "propertyValue");
```

Where:

`vPin` is: virtual pin number the widget is assigned to

`isHidden`: property that controls the widget visibility

`propertyValue`: value of the property you want to change. _true_ and _false_ values are supported.



Example:

```
Blynk.setProperty(V12, "isHidden", true); // This will hide the widget
```

{% hint style="warning" %}
Don't put **`Blynk.setProperty()`** into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers.
{% endhint %}

### Change widget properties via HTTPs API

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}" method="get" summary="Updates the Datastream Property and all assigned Widgets" %}
{% swagger-description %}
The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isHidden=true`
{% endswagger-description %}

{% swagger-parameter in="query" name="token" type="string" required="true" %}
Device [auth token](../../../concepts/device.md#authtoken) from Device info
{% endswagger-parameter %}

{% swagger-parameter in="query" name="pin" type="string" required="true" %}
The datastream [virtual pin](../../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="query" name="{property}" type="string" %}
The property of the widget you want to update: `isHidden`
{% endswagger-parameter %}

{% swagger-parameter in="path" name="{server address}" type="string" required="true" %}
Get from the bottom right of your Blynk console. [More information](../../../blynk.cloud/device-https-api/troubleshooting.md).
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
