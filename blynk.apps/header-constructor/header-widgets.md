# Header Widgets

Header widgets enable the display of important information in the device header, such as battery level, the last reported timestamp, datastream value, and more.

## **Adding and Deleting**

To add a header widget, click on the "plus" icon located below the Template name, which will open the Widget Box. Select the desired widget from the available options.

Once the first widget is added, you'll notice two “plus” icons, enabling you to add widgets in different rows for enhanced customization.

To remove a widget, press on it to access its settings, and then tap the “trash” icon positioned at the top right corner. This will promptly delete the selected widget from your configuration.
![add-header-widget](https://github.com/blynkkk/docs/assets/72790181/8c0c95dc-8585-4de4-8fca-c9fdda7ea9cb)


## Connection Status widget

This widget displays the device’s current status as a text label.
![connection-status](https://github.com/blynkkk/docs/assets/72790181/e291b819-fec5-485d-810e-7e12414ee9ea)


### Settings

**Datastream (optional)** - For setProperty.

### **Change Widget Properties**

You can change *isHidden* of the widget from your hardware. For that, use this command:

`Blynk.setProperty(vPin, "isHidden", "propertyValue");`

Where:

`vPin` is: virtual pin number the widget is assigned to

`isHidden`: property that controls the button visibility

`propertyValue`: value of the property you want to change. *true* and *false* values are supported.

{% hint style="danger" %} Don't put **Blynk.setProperty()**into the void loop() as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers. {% endhint %}

### Change Widget properties via HTTPs API

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


## Last Reported widget

This widget shows the timestamp of the last time Blynk received the data from the device.
![last-reported](https://github.com/blynkkk/docs/assets/72790181/b8b964b7-a13e-44ed-afe5-08852e6dbd97)


### Settings

**Datastream (optional)** - For setProperty

**Show icon** - To show/hide the “Clock” icon on the left.

**Show label** - To show/hide the “Last reported” text.

### **Change Widget Properties**

You can change *isHidden* of the widget from your hardware. For that, use this command:

`Blynk.setProperty(vPin, "isHidden", "propertyValue");`

Where:

`vPin` is: virtual pin number the widget is assigned to

`isHidden`: property that controls the button visibility

`propertyValue`: value of the property you want to change. *true* and *false* values are supported.

{% hint style="danger" %} Don't put **Blynk.setProperty()**into the void loop() as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers. {% endhint %}

### Change widget properties via HTTPs API

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

## Tabs widget

Adds one or more tabs to the top of the device mobile dashboard in order to expand and organize the user interface space. You can drag widgets between tabs.
Note that plan limits apply here.
![tabs](https://github.com/blynkkk/docs/assets/72790181/01e95686-b12d-4910-acbb-5e7bbae0ee4f)


### **Navigating the Tabs Editor:**

To access the Tabs editor, simply tap on the active tab. In the editor, you can rename tabs, alter their order, add new tabs, and swipe left to delete a tab. Note that the last two tabs are permanent and cannot be removed, but you can delete the entire widget by pressing the “Trash” icon located at the top right.

### **Moving Widgets Between Tabs:**

1. Press and hold the widget you wish to move.
2. Drag it over the tab where you want it to be placed and hold until the tab opens.
3. Release the widget in the desired position to seamlessly move it between tabs.

## Datastream Value widget

Displays the latest datastream / virtual pin value. Units assigned to the datastream are also displayed. Labels may also be optionally added before and after the displayed value.
![datastream-value](https://github.com/blynkkk/docs/assets/72790181/ad4451c9-58c1-451c-9179-dc91f47608da)


### Settings

**Datastream** - Select or create a datastream of [data type](notion://www.notion.so/en/blynk.console/templates/datastreams/datastreams-common-settings/data-type) integer, double, enumerable or string.

**Label** - Set custom label before the value. E.g Temperature: `/value/`

### **Change Widget Properties**

You can change *isHidden* of the widget from your hardware. For that, use this command:

`Blynk.setProperty(vPin, "isHidden", "propertyValue");`

Where:

`vPin` is: virtual pin number the widget is assigned to

`isHidden`: property that controls the button visibility

`propertyValue`: value of the property you want to change. *true* and *false* values are supported.

{% hint style="danger" %} Don't put **Blynk.setProperty()**into the void loop() as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers. {% endhint %}

### Change widget properties via HTTPs API

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

## Image widget

Improve your header visually with a custom image that can be controlled from hardware.
![image-header-widget](https://github.com/blynkkk/docs/assets/72790181/d5760548-9f36-48ef-ad41-471f0d2bd531)


### Settings

**Theme** - Define how the widget design will appear in different app themes.

**Datastream** - Select or create a datastream of [data type](notion://www.notion.so/en/blynk.console/templates/datastreams/datastreams-common-settings/data-type) integer.

**Handle values out of range as empty -** Toggle ON to display nothing on the widget when the value is outside the expected range. If this setting is turned OFF, the image closest to the current value will be shown.

**Images** - Specify a list of images to display, where the Image ID corresponds to the respective values of the datastream.

**Full width** - Define the width of the image container to ensure optimal presentation.

**Images scaling** - Choose between FIT or FILL options to adjust how the image appears within the container.

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

You can change the properties _url_,_urls_ _isHidden_ of the widget from your hardware, or via an [HTTP API](broken-reference). The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.&#x20;

#### **Change Images**
Change the individual image by its index:
```cpp
Blynk.setProperty(V1, "url", 1, "https://image1.jpg");
```
Change a list of URLs for the widget. First image will have index `0`, next `1`, and so on. 
```cpp
Blynk.setProperty(V1, "urls", "https://image1.jpg", "https://image2.jpg");"
```
{% hint style="danger" %}
Make sure you not exceed the max string size of 255 chars when sending a long list of URLs 
{% endhint %}

```

#### **Show/Hide**

Widget will be hidden from header. Design your UI so that it doesn't look weird when there is no widget.

```cpp
Blynk.setProperty(V1, "isHidden", true);
```



### Change widget properties via HTTPs API

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
The property of the widget you want to update: 

`url`

, 

`urls`

, 

`isHidden`
{% endswagger-parameter %}

{% swagger-parameter in="path" name="{server address}" type="string" required="true" %}
Get from the bottom right of your Blynk console. 

[More information](../../blynk.cloud/device-https-api/troubleshooting.md)

.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="url" type="string" %}
replace image url
{% endswagger-parameter %}

{% swagger-parameter in="query" name="urls" type="string" %}
change multiple URLs
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

## Battery level widget

This widget provides a clear visual representation of your battery level, accompanied by a percentage indicator for quick reference.
![battery-level-header-widget](https://github.com/blynkkk/docs/assets/72790181/9762a482-0eaf-4e65-aaec-20c6e36b3697)


### Settings

**Datastream** - Select or create a datastream of [data type](notion://www.notion.so/en/blynk.console/templates/datastreams/datastreams-common-settings/data-type) integer or double.

Value should come in 0-100 range.

**Show value** - You can bide the value to see the battery icon only.

### **Change Widget Properties**

You can change *isHidden* of the widget from your hardware. For that, use this command:

`Blynk.setProperty(vPin, "isHidden", "propertyValue");`

Where:

`vPin` is: virtual pin number the widget is assigned to

`isHidden`: property that controls the button visibility

`propertyValue`: value of the property you want to change. *true* and *false* values are supported.

{% hint style="danger" %} Don't put **Blynk.setProperty()**into the void loop() as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers. {% endhint %}

### Change widget properties via HTTPs API

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


## Tags widget

Display a list of tags assigned to the device.
![tags-header-widget](https://github.com/blynkkk/docs/assets/72790181/cfc323a1-8d87-4bb2-98d6-ce79ae57b25a)


### Settings

**Datastream (optional)** - For setProperty.

### **Change Widget Properties**

You can change *isHidden* of the widget from your hardware. For that, use this command:

`Blynk.setProperty(vPin, "isHidden", "propertyValue");`

Where:

`vPin` is: virtual pin number the widget is assigned to

`isHidden`: property that controls the button visibility

`propertyValue`: value of the property you want to change. *true* and *false* values are supported.

{% hint style="danger" %} Don't put **Blynk.setProperty()**into the void loop() as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers. {% endhint %}

### Change widget properties via HTTPs API

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
