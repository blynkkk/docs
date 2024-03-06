# Header Mini Widgets

Add up to 6 Mini Widgets to the header widgets to display battery level, the last reported timestamp, datastream value, and more.

You can utilize  2 rows, each row containing up to 3 mini widgets.

<div align="left">

<figure><img src="../../../.gitbook/assets/all-mobile-header-widgets (1).png" alt="" width="375"><figcaption></figcaption></figure>

</div>

<table data-header-hidden><thead><tr><th data-type="content-ref">Header Mini Widgets</th><th data-hidden></th><th data-hidden></th><th data-hidden></th><th data-hidden data-type="content-ref"></th><th data-hidden></th></tr></thead><tbody><tr><td><a href="connection-status-widget.md">connection-status-widget.md</a></td><td></td><td></td><td></td><td><a href="last-reported-widget.md">last-reported-widget.md</a></td><td></td></tr><tr><td><a href="last-reported-widget.md">last-reported-widget.md</a></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td><a href="tabs-widget.md">tabs-widget.md</a></td><td></td><td></td><td></td><td><a href="datastream-value-widget.md">datastream-value-widget.md</a></td><td></td></tr><tr><td><a href="datastream-value-widget.md">datastream-value-widget.md</a></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td><a href="image-widget.md">image-widget.md</a></td><td></td><td></td><td></td><td><a href="battery-level-widget.md">battery-level-widget.md</a></td><td></td></tr><tr><td><a href="battery-level-widget.md">battery-level-widget.md</a></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td><a href="tags-widget.md">tags-widget.md</a></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td></tr></tbody></table>

### **Adding And Deleting Widgets**

To add a header widget, click on the "plus" icon located below the Template name, which will open the Widget Box. Select the desired widget from the available options.

Once the first widget is added, you'll notice two “plus” icons, enabling you to add widgets in different rows for enhanced customization.

To remove a widget, press on it to access its settings, and then tap the “trash” icon positioned at the top right corner. This will promptly delete the selected widget from your configuration.

<figure><img src="../../../.gitbook/assets/add-mobile-header-widget (1).png" alt=""><figcaption></figcaption></figure>



### **Properties**

You can hide/show header widgets from device. Use `isHidden` property API:

```
Blynk.setProperty(vPin, "isHidden", "propertyValue");
```

Where:

`vPin` is: virtual pin number the widget is assigned to

`xisHidden`: property that controls the widget visibility

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



