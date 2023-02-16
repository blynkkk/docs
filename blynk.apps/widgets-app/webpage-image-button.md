# WebPage Image Button

WebPage Image Button is a button that opens in-app browser with a provided URL. You can provide your own images for ON (pressed) and OFF (idle) states.



### Settings

**URL**: specifies which URL should be opened in the browser.&#x20;

You can use placeholders for URL:

`deviceID` - device ID in Blynk

`userID` -  ID of the user pressing the button

`userEmail` - email of the user pressing the button



Example URL with placeholders:

```
https://mywebapp.com/action?user=/userID/&device=/deviceID/
```

****

**Datastream**: optional parameter. Use if you plan to use set.Property commands

****

**Images**: specify URLs for images for ON (pressed) and OFF (idle) states

****

**Scaling:**&#x20;

**Fit** - will scale the image up or down to fit the widget. Proportions will be preseved

**Fill** - will scale the image up or down to fill the widget. Proportions will be preseved &#x20;



**Open in browser**: When ON, pressing the button will open the OS browser. User will leave the Blynk app&#x20;





### Widget Properties you can change from device

Examples below use Virtual Pin V01. Change to your pin.&#x20;

****

**Disable/Enable**. Widget will be greyed out on UI and users won't be able to tap on it.

```cpp
Blynk.setProperty(V1, "isDisabled", true);
```

****

**Show/Hide**. Widget will be hidden from dashboard.&#x20;

{% hint style="warning" %}
Plan your UI layout so that it looks good even if widget is hidden.
{% endhint %}

```cpp
Blynk.setProperty(V1, "isHidden", true);
```

****

**URL.** Change the URL to be open. You can use placeholders described above.

```cpp
Blynk.setProperty(V1, "url", "https://mywebsite.com");
```

****

**ON/OFF Image URLs.** Change the URL to be opened

```cpp
Blynk.setProperty(V1, "onImageUrl", "https://mywebsite.com/on.png");
Blynk.setProperty(V1, "offImageUrl", "https://mywebsite.com/off.png");
```
