# WebPage Button

Web Page Button is a button that opens in-app browser with a provided URL.

### Examples of use

* Show any web page inside of Blynk app: documentation, online store, etc
* Open your web app (check the placeholders below)
* Payment URL



### Settings

**Link Name:** text to be displayed on the button

**URL**: specifies which URL should be opened in the browser.&#x20;

You can use placeholders for URL:

* `deviceID` - device ID in Blynk
* `userID` -  ID of the user pressing the button
* `userEmail` - email of the user pressing the button

Example URL with placeholders:

```
https://mywebapp.com/action?user=/userID/&device=/deviceID/
```

**Lock Size:** when On, size of the button will be relative to the text

**Open in browser**: When ON, pressing the button will open the OS browser. User will leave the Blynk app&#x20;



### Change Button Properties

You can change certain properties of the Widget from your hardware. For that, use this command:&#x20;

```cpp
Blynk.setProperty(vPin, "widgetProperty", "propertyValue"); 
```

Where:&#x20;

* `vPin` is: virtual pin number the widget is assigned to
* `widgetProperty`: property you want to change
* `propertyValue`: value of the property you want to change

{% hint style="danger" %}
Don't put **`Blynk.setProperty()`**&#x69;nto the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers.
{% endhint %}

### Widget Properties you can change from device

You can change the properties _onLabel_, _offLabel_, _onColor_, _offColor_, _onBackColor_, _offBackColor_, _label_, _color_, _isDisabled_, _isHidden_, and _page_ of the widget from your hardware, or via an [HTTP API](broken-reference). The color hexadecimal values in the HTTP API URL must include the hash # character urlencoded as %23.&#x20;

#### **URL**

Change the URL to be open. You can use placeholders described [above](webpage-button.md#settings).

```cpp
Blynk.setProperty(V1, "url", "https://mywebsite.com");
```

#### Set a custom ON/OFF background color associated with the widget state

```cpp
Blynk.setProperty(V1, "onBackColor", "#73D13D");  // green
Blynk.setProperty(V1, "offBackColor", "#ED9D00");  // orange
```

#### Set a custom ON/OFF label text color associated with the widget state

```cpp
Blynk.setProperty(V1, "onColor", "#73D13D");  // green
Blynk.setProperty(V1, "offColor", "#ED9D00");  // orange
```

#### Set a custom ON/OFF label associated with the widget state

```cpp
Blynk.setProperty(V1, "onLabel", "Playing");
Blynk.setProperty(V1, "offLabel", "Idle");
```

#### **Show/Hide**

Widget will be hidden from dashboard. Design your UI so that it doesn't look weird when there is no widget.

```cpp
Blynk.setProperty(V1, "isHidden", true);
```

{% hint style="warning" %}
Plan your UI layout so that it looks good even if widget is hidden.
{% endhint %}

#### **Disable/Enable**

Widget will be greyed out on UI and users won't be able to tap on it.

```cpp
Blynk.setProperty(V1, "isDisabled", true);
```



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
