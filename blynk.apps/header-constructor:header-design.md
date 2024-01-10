# Header Design

You can customize the appeal of the header by easily changing its size, color, adding a border, or modifying its content colors.

## How to change Header Design?

Press the "paint bucket" icon to access the Header Settings page. 

![image](https://github.com/vveretko/vveretko/assets/72790181/466d32ca-3872-4753-bab5-5aec17f2a50c)

## Header settings:

**Theme** - Define how the header will appear in different app themes.

**Background color** - Choose any color you want and the header background will change accordingly.

**Content design** - Select from Dark or Light content colors to ensure the header content looks good on your custom background.

**Datastream (optional)** - For setProperty.

**Border -** You can apply a bottom stroke or a shadow to the header body to separate it from other content.

### **Change Header Properties**

You can change certain properties of the Header from your hardware. For that, use this command:

`Blynk.setProperty(vPin, "headerProperty", "propertyValue");`

Where:

`vPin` is: virtual pin number the widget is assigned to

`headerProperty`: property you want to change

`propertyValue`: value of the property you want to change

Don't put **`Blynk.setProperty()`**into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers.

### **Properties you can change**

You can change the *color* and *contentDesign* properties from your hardware, or via an [HTTP API](notion://www.notion.so/en/blynk.cloud). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.

#### Set color
`//#D3435C - Blynk RED
Blynk.setProperty(V1, "color", "Air temperature");`

#### Set content design
`Blynk.setProperty(V1, "contentDesign", "dark");`

### Change Header properties via HTTPs API

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}" method="get" summary="Updates the Datastream Property and all assigned Widgets" %}
{% swagger-description %}
The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&color=%2300000`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&contentDesign=dark`
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
The property of the widget you want to update: 

`color`

, 

`contentDesign`

{% endswagger-parameter %}

{% swagger-parameter in="path" name="{server address}" type="string" required="true" %}
Get from the bottom right of your Blynk console. 

[More information](../../blynk.cloud/device-https-api/troubleshooting.md)

.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="color" type="string" %}
Header color hexadecimal, must include the hash # character urlencoded as %23.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="contentDesign" type="string" %}
light or dark
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

## Resizing

In the default state, the header size depends on its content. However, you can manually change the size by dragging the handle at the bottom of it.

![image](https://github.com/vveretko/vveretko/assets/72790181/b849c4c9-10b2-4f1c-a154-4b2d64521bdb)

