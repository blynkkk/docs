# Header Buttons

By default, there are 2 system buttons in the header: Timeline and Device Info. They can't be removed or hidden.&#x20;

You can add up to 2 custom buttons which will open a [Standalone Page](../pages.md#standalone-pages) to each of them.

Tap the “plus” icon at the top of the header, and choose the page that should be opened.&#x20;

<figure><img src="../../.gitbook/assets/add-mobile-header-button (1).png" alt=""><figcaption></figcaption></figure>

### Header button settings

**Datastream (optional)** - choose Datastream if you plan to change layout with firmware API or HTTP API  `setProperty` command.

**Page** - Select a page to open. Only Standalone Pages are supported.

**Icon** - Define how this button will appear to the user.

**Appearance Animation** - The page can slide in from the bottom or from the right.



### **Change Header Button Properties**

You can change certain properties of the button from your hardware. For that, use this command:

```
Blynk.setProperty(vPin, "widgetProperty", "propertyValue"); 
```

Where:

* `vPin` is: virtual pin number the widget is assigned to
* `widgetProperty`: property you want to change
* `propertyValue`: value of the property you want to change

{% hint style="warning" %}
Don't put **`Blynk.setProperty()`** into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers.
{% endhint %}

### Properties you can change

You can change the properties _`isHidden`_, and _`page`_ of the button from your hardware. The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.

### **Change Header Button Properties**

**Show/Hide**

You can hide the button by changing `isHidden` property from device:

```cpp
Blynk.setProperty(V1, "isHidden", "propertyValue");
```

**Change Page Target**

This command will set which page should open when the button is pressed. PageId can be found in the mobile app in developer mode: Toolbox -> Pages

```cpp
Blynk.setProperty(V1, “page”, “pageId”);
```



### Change button properties via HTTPs API

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}" method="get" summary="Updates the Datastream Property and all assigned Widgets" %}
{% swagger-description %}
The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isHidden=true`
{% endswagger-description %}

{% swagger-parameter in="query" name="token" type="string" required="true" %}
Device [auth token](../../concepts/device.md#authtoken) from Device info
{% endswagger-parameter %}

{% swagger-parameter in="query" name="pin" type="string" required="true" %}
The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="query" name="{property}" type="string" %}
The property of the widget you want to update: `isHidden`
{% endswagger-parameter %}

{% swagger-parameter in="path" name="{server address}" type="string" required="true" %}
Get from the bottom right of your Blynk console. [More information](../../blynk.cloud/device-https-api/troubleshooting.md).
{% endswagger-parameter %}

{% swagger-parameter in="query" name="isHidden" type="string" %}
true or false
{% endswagger-parameter %}

{% swagger-parameter in="query" name="page" type="string" %}
[pageID](../pages.md#id-3.-linking-page-to-an-entry-point)
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
