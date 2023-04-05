# WebPage Button

Web Page Button is a button that opens in-app browser with a provided URL.

### Examples of use

* Show any web page inside of Blynk app: documentation, online store, etc
* Open your web app (check the placeholders below)
* Payment URL



### Settings

**Link Name:** text to be displayed on the button



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



**Lock Size:** when On, size of the button will be relative to the text



**Open in browser**: When ON, pressing the button will open the OS browser. User will leave the Blynk app&#x20;





### Widget Properties you can change from device

Examples below use Virtual Pin V01. Change to your pin.&#x20;



**URL.** Change the URL to be open. You can use placeholders described above.

```cpp
Blynk.setProperty(V1, "url", "https://mywebsite.com");
```



**Disable/Enable**. Widget will be greyed out on UI and users won't be able to tap on it.

```cpp
Blynk.setProperty(V1, "isDisabled", true);
```



**Show/Hide**. Widget will be hidden from dashboard.&#x20;

{% hint style="warning" %}
Plan your UI layout so that it looks good even if widget is hidden.
{% endhint %}

```cpp
Blynk.setProperty(V1, "isHidden", true);
```

