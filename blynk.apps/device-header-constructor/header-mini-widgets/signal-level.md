---
description: >-
  This widget provides a clear visual representation of the device's signal
  strength, accompanied by an optional value indicator for quick reference.
---

# Signal Level Widget

<figure><img src="../../../.gitbook/assets/signal-level.png" alt=""><figcaption><p>Signal Level Widget</p></figcaption></figure>

### Settings

**Datastream** - Select or create a datastream of data type integer, or double.&#x20;

**Icon** - Select from three options to represent Signal Level. The data stream’s minimum and maximum values are automatically mapped to four signal level icons, plus a ‘No Signal’ state.&#x20;

**Show value** - You can show the datastream value. Turn it off to see just the icon.&#x20;

**Label** - Set custom label before the value. E.g Signal Level: /value/



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

{% hint style="info" %}
Updates the Datastream Property and all assigned Widgets!
{% endhint %}

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}`

The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isHidden=true`

#### Path Parameters

| Name                                               | Type   | Description                                                                                                                    |
| -------------------------------------------------- | ------ | ------------------------------------------------------------------------------------------------------------------------------ |
| {server address}<mark style="color:red;">\*</mark> | string | Get from the bottom right of your Blynk console. [More information](../../../blynk.cloud/device-https-api/troubleshooting.md). |

#### Query Parameters

| Name                                    | Type   | Description                                                                                                       |
| --------------------------------------- | ------ | ----------------------------------------------------------------------------------------------------------------- |
| token<mark style="color:red;">\*</mark> | string | Device [auth token](../../../concepts/device.md#authtoken) from Device info                                       |
| pin<mark style="color:red;">\*</mark>   | string | The datastream [virtual pin](../../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v") |
| {property}                              | string | The property of the widget you want to update: `isHidden`                                                         |
| isHidden                                | string | true or false                                                                                                     |

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
