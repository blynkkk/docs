# Header buttons

You can add up to 2 header buttons and assign a Standalone Page to each of them.

To add a header button, simply click the “plus” icon at the top of the header, and its settings will open.

![add-header-button](https://github.com/vveretko/vveretko/assets/72790181/070d1469-ce30-464e-bf57-b942ba1f9909)

## Header button settings:

**Datastream (optional)** - For setProperty.

**Page** - Select a page to open when pressing this button on the Device Dashboard. Only Standalone Pages are supported.

**Icon** - Define how this button will appear to the user.

**Appearance Animation** - The page can slide in from the bottom or from the right.

### **Change Header Button Properties**

You can change *isHidden* of the Header Button from your hardware. For that, use this command:

`Blynk.setProperty(vPin, "isHidden", "propertyValue");`

Where:

`vPin` is: virtual pin number the widget is assigned to

`isHidden`: property that controls the button visibility

`propertyValue`: value of the property you want to change. *true* and *false* values are supported.

{% hint style="danger" %} Don't put **Blynk.setProperty()**into the void loop() as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers. {% endhint %}

### Change button properties via HTTPs API

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}" method="get" summary="Updates the Datastream Property and all assigned Widgets" %}
{% swagger-description %}
The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isHidden=true`
{% endswagger-description %}

{% swagger-parameter in="query" name="token" type="string" required="true" %}
Device 

[auth token](../../concepts/device.md#authtoken)

 from Device info
{% endswagger-parameter %}

{% swagger-parameter in="query" name="pin" type="string" required="true" %}
The datastream 

[virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md)

 (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="query" name="{property}" type="string" %}

{% endswagger-parameter %}

{% swagger-parameter in="path" name="{server address}" type="string" required="true" %}
Get from the bottom right of your Blynk console. 

[More information](../../blynk.cloud/device-https-api/troubleshooting.md)

.
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
