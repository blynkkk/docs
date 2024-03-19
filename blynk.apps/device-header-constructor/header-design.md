# Header Design

Customize the header layout by easily changing its size, color, adding a border, or modifying its content colors.

### How to change Header Design?

Press the "spray" icon to access the Header Settings page.

<figure><img src="../../.gitbook/assets/mobile-header-design-settings (2).png" alt=""><figcaption></figcaption></figure>

### Header settings:

**Theme** - Define how the header will appear in dark or light app themes. Since end-users can choose the theme of the OS they use, it's important to take it into consideration when working on a visual design of your app.&#x20;

**Background color** - Choose the header background. Color can also be changed by device using `setProperty` firmware API

**Content theme** - Select from Dark or Light content colors to ensure the header content looks good on your custom background.

**Datastream (optional)** - choose the Datastream if you plan to change header design from device using `setProperty` API.

**Border -** Apply a stroke or a shadow under the header body



### **Change Header Properties**

You can change certain properties of the Header from your hardware. For that, use this command:

```
Blynk.setProperty(vPin, "headerProperty", "propertyValue");
```

Where:

`vPin` is: virtual pin number the widget is assigned to

`headerProperty`: property you want to change

`propertyValue`: value of the property you want to change

{% hint style="warning" %}
Don't put **`Blynk.setProperty()`** into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers.
{% endhint %}

**Properties you can change**

You can change the _color_ and _contentDesign_ properties from your hardware, or via an HTTP API.&#x20;

{% hint style="warning" %}
The URL must be encoded, so spaces in labels must be replaced with %20, and color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.
{% endhint %}



**Set color**

```
Blynk.setProperty(V1, "color", "#D3435C");
```



**Set content design**

```
Blynk.setProperty(V1, "contentDesign", "dark");
```

### Change Header Properties with HTTPs API

## Updates the Datastream Property and all assigned Widgets

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}`

The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&color=%2300000`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&contentDesign=dark`

#### Path Parameters

| Name                                               | Type   | Description                                                                                                                 |
| -------------------------------------------------- | ------ | --------------------------------------------------------------------------------------------------------------------------- |
| {server address}<mark style="color:red;">\*</mark> | string | Get from the bottom right of your Blynk console. [More information](../../blynk.cloud/device-https-api/troubleshooting.md). |

#### Query Parameters

| Name                                    | Type   | Description                                                                                                    |
| --------------------------------------- | ------ | -------------------------------------------------------------------------------------------------------------- |
| token<mark style="color:red;">\*</mark> | string | Device [auth token](../../concepts/device.md#authtoken) from Device info                                       |
| pin<mark style="color:red;">\*</mark>   | string | The datastream [virtual pin](../../blynk.console/templates/datastreams/virtual-pin.md) (should start with "v") |
| {property}                              | string | The property of the header you want to update: `color`, `contentDesign`                                        |
| color                                   | string | header color hexadecimal, must include the hash # character urlencoded as %23                                  |
| contentDesign                           | string | light or dark                                                                                                  |

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



### Resizing

In the default state, the header size depends on its content. However, you can manually change the size by dragging the handle at the bottom of it.

<div align="left">

<figure><img src="../../.gitbook/assets/mobile-header-resizing (4).png" alt="" width="375"><figcaption></figcaption></figure>

</div>
