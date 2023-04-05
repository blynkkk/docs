# Button

The button is made to turn something on and off on your device. However, it can do more. There are different types of buttons, but most of the settings are self-explanatory. This document only covers unique settings.&#x20;



### Datastream

Select the Datastream to send values from the button to device.&#x20;

If you would like to change [properties](https://docs.blynk.io/en/blynk.apps/widgets-app/button#change-button-properties) (color, label, etc.) of the widget, you would need a Datastream as well.&#x20;



### Mode

Button can operate in these modes:&#x20;

1. **Push:** when finger released - button will switch to OFF state
2. **Switch:** when finger is released - the button will stay in the pressed state
3. **Page:** button will open a specified [page](../pages.md)
4. **QR:** button will open the code scanner. Read below:

#### How the QR code scanner works.

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



## How to process button input on the device

When button is pressed, value is sent and stored into the Blynk.Cloud. After that it's sent to your device.

### Reading the button value

For example, if Button Widget is set to Datastream with Virtual Pin V1, you can use such code:

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

Find a full code example for your hardware [here](https://examples.blynk.cc/?board=ESP32\&shield=ESP32%20WiFi\&example=GettingStarted%2FGetData).&#x20;



### Changing button state

You can also update the state of the button from hardware.

```cpp
Blynk.virtualWrite(vPin, HIGH);
```

or

```cpp
Blynk.virtualWrite(vPin, 1);
```

{% hint style="danger" %}
Don't put **`Blynk.virtualWrite()`**into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, use flags, or [timers](https://docs.blynk.io/en/blynk.edgent-firmware-api/blynk-timer).
{% endhint %}

##

## Change Button Properties

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

Examples below use Virtual Pin V01. Change to your parameters.&#x20;

**Change On/Off labels:**

```cpp
Blynk.setProperty(V1, "onLabel", "ON");
Blynk.setProperty(V1, "offLabel", "OFF");
```



**Set Button Color:**

```cpp
//#D3435C - Blynk RED 
Blynk.setProperty(V1, "color", "#D3435C");
```



**Disable/Enable**. Widget will be greyed out on UI and users won't be able to tap on it.

```cpp
Blynk.setProperty(V1, "isDisabled", true);
```



**Show/Hide**. Widget will be hidden from dashboard. Design your UI so that it doesn't look weird when there is no widget.

```cpp
Blynk.setProperty(V1, "isHidden", true);
```



**Change Page Target**. This command will set which page should open when the button is pressed. PageId can be found in the mobile app in developer mode:  Toolbox -> Pages

```cpp
Blynk.setProperty(V1, "page", "pageId");
```



**Sync to the latest known state**&#x20;

Get the latest known value from the server. For example, after your hardware went offline and then became online again.

```cpp
BLYNK_CONNECTED() { // checks if there is a connection to Blynk.Cloud  
  Blynk.syncVirtual(V1); // get the latest value
}

BLYNK_WRITE(V1) // this command is listening when something is written to V1
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  
  if (pinValue = 1){
   // do something when button is pressed;
  } else if {
  (pinValue = 0)
   // do something when button is released;
  }
}
```
