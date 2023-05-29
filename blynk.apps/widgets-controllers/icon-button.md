# Icon Button

The Icon Button assigns icons that are displayed according to the assigned datastream on/off state. The icon line and background colors may be configured based on the on/off state. You can also configure the button style and shape. &#x20;



### Mode

Button can operate in these modes:&#x20;

1. **Push.** Set to ON state when pressed, then back to OFF state when released
2. **Switch.** Toggles between ON/OFF state each time it is pressed&#x20;
3. **Page.** Opens a specified app page when pressed (requires [Plus](https://blynk.io/pricing) plan)
4. **QR.** Opens phone QR Scanner (requires [PRO](https://blynk.io/pricing) plan)

#### How the QR code scanner works

End users will tap on the widget and a code scanner (camera) will open. The camera should be pointed to the code.

Once the code is successfully scanned, its contents will be sent to the hardware in a String format to the specified Datastream. The scanner screen will be closed automatically. A String Datastream should be added to the Device Template to accept these values.

Value of the code is sent as is (not pre-processed or post-processed by Blynk).&#x20;

In case of scanning an unsupported format, no error will be shown. User would need to close the scanner view (camera) manually.

End-users would need to grant permissions to use the camera on the smartphone OS level. If permission wasn’t granted, a message will be shown to go to settings to enable access to the camera.

#### Scanner works with these code formats

* QR&#x20;
* AZTEC
* CODE\_39
* CODE\_39 mod 43
* CODE\_93&#x20;
* CODE\_128&#x20;
* DATA\_MATRIX
* EAN\_8
* EAN-13
* ITF
* PDF\_417
* UPC\_E

Android app can additionally support these formats:

* CODABAR
* MAXICODE
* RSS\_14
* RSS\_EXPANDED
* UPC\_A
* UPC\_EAN\_EXTENSION



### Datastream

Select or create a datastream of [data type](../../blynk.console/templates/datastreams/datastreams-common-settings/data-type.md) integer, double, or string.  Widget properties (label, color, etc.) are also changed via the datastream, but only for virtual, enumerable, and location pins, not digital and analog pins.



### How to process button input on the device

When button is pressed, value is sent and stored into the Blynk.Cloud. After that it's sent to your device.

#### Reading the button value

For example, if Icon Button Widget is set to Datastream with Virtual Pin V1, you can use such code:

```cpp
BLYNK_WRITE(V1) // this command is listening when something is written to V1
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  
  if (pinValue == 1){
   // do something when button is pressed;
  } else if (pinValue == 0) {
   // do something when button is released;
  }
  
  Serial.print("V1 button value is: "); // printing value to serial monitor
  Serial.println(pinValue);
}
```

Sketch:[ Basic Sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

Sketch:[ Physical Button Interrupt](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonInterrupt/ButtonInterrupt.ino)

Sketch:[ Physical Button Poll](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/ButtonPoll/ButtonPoll.ino)

Sketch: [Physical Button State Sync](https://github.com/blynkkk/blynk-library/blob/master/examples/More/Sync/SyncPhysicalButton/SyncPhysicalButton.ino)



#### Changing button state

You can also update the state of the button from hardware.

```cpp
Blynk.virtualWrite(vPin, HIGH);
```

or

```cpp
Blynk.virtualWrite(vPin, 1);
```

{% hint style="danger" %}
Don't put **`Blynk.virtualWrite()`**into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, use flags, or [timers](../../blynk.edgent-firmware-api/blynk-timer.md).
{% endhint %}

##

### Change Icon Button Properties

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

You can change the properties _onColor_, _offColor_, _onBackColor_, _offBackColor_, _label_, _isDisabled_, _isHidden_, and _page_ of the widget from your hardware, or via an [HTTP API](broken-reference). The color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.&#x20;

#### Set a custom label for the widget

```cpp
Blynk.setProperty(V1, "label", "Toggle");
```

#### Set a custom ON/OFF icon color associated with the widget state

```cpp
Blynk.setProperty(V1, "onColor", "#73D13D");  // green
Blynk.setProperty(V1, "offColor", "#ED9D00");  // orange
```

#### Set a custom ON/OFF background color associated with the widget state

```cpp
Blynk.setProperty(V1, "onBackColor", "#73D13D");  // green
Blynk.setProperty(V1, "offBackColor", "#ED9D00");  // orange
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

#### **Change Page Target**

This command will set which page should open when the icon button is pressed. PageId can be found in the mobile app in developer mode:  Toolbox -> Pages

```cpp
Blynk.setProperty(V1, "page", "pageId");
```

### Change widget properties via HTTPs API

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={your 32 char token}&pin={your vPin}&{property}={value}" method="get" summary="Updates the Datastream Property and all assigned Widgets" %}
{% swagger-description %}
The endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu.

**Example:**\
`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V2&label=My%20Label`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&onColor=%23D3435C`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&isDisabled=true`

`https://blynk.cloud/external/api/update/property?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&pin=V1&page={pageID}`
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

`onLabel`

,

\




`offLabel`

, 

`label`

, 

`onColor`

, 

`offColor`

, 

`onBackColor`

, 

`offBackColor`

, 

`color`

,

\




`isDisabled`

, 

`isHidden`

, 

`page`
{% endswagger-parameter %}

{% swagger-parameter in="path" name="{server address}" type="string" required="true" %}
Get from the bottom right of your Blynk console. 

[More information](../../blynk.cloud/troubleshooting.md)

.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="label" type="string" %}
the text used as widget label
{% endswagger-parameter %}

{% swagger-parameter in="query" name="onColor" type="string" %}
custom icon line color associated with the widget ON/OFF state
{% endswagger-parameter %}

{% swagger-parameter in="query" name="offColor" type="string" %}
custom icon line color associated with the widget ON/OFF state
{% endswagger-parameter %}

{% swagger-parameter in="query" name="onBackColor" type="string" %}
custom background color associated with the widget ON/OFF state
{% endswagger-parameter %}

{% swagger-parameter in="query" name="offBackColor" type="string" %}
custom background color associated with the widget ON/OFF state
{% endswagger-parameter %}

{% swagger-parameter in="query" name="isDisabled" type="string" %}
true or false
{% endswagger-parameter %}

{% swagger-parameter in="query" name="isHidden" type="string" %}
true or false
{% endswagger-parameter %}

{% swagger-parameter in="query" name="pageID" type="string" %}


[pageID](../pages.md#changing-target-page-from-hardware)


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

You can update your hardware to the latest datastream value from Blynk.Cloud after your hardware went offline, and then came online again. Use `Blynk.syncVirtual()` to update a single virtual pin, or `Blynk.syncAll()` to update all virtual pins. See [State Syncing](../../blynk.edgent-firmware-api/state-syncing.md) for more details.

```cpp
BLYNK_CONNECTED() { 
  // Called when hardware is connected to Blynk.Cloud  

  // get the latest value for V1
  Blynk.syncVirtual(V1); 

  // Request Blynk server to re-send latest values for all pins
  Blynk.syncAll()
}
```