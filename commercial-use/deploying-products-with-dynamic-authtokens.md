# Deploying Products With Dynamic AuthTokens

Every device needs a unique AuthToken in order to authenticate in Blynk.Cloud. During prototyping, you can manually add AuthToken to every device. However, when working with commercial products you would need a scalable approach to eliminate manual work.



### Why use dynamic AuthTokens

1. With this approach, you don't have to flash different AuthTokens onto every device. You can use the same firmware on every device, which significantly simplifies the production process.
2. Dynamic AuthTokens workflow is included in Blynk.Edgent and works out-of-the-box.
3. This flow is integrated with Blynk.apps providing great user experience 

{% hint style="info" %}
Dynamic AuthTokens works only with Wi-Fi devices. Supported devices are: ESP32, ESP8266, WiO Terminal by Seeed, Arduino MKR1010, Arduino Nano 33IoT, and Texas Instruments CC3220. Raspberry Pi will be supported soon.
{% endhint %}

### \*\*\*\*

### **How Dynamic AuthTokens work**

Dynamic AuthToken generation is a part of the device provisioning process:

1. In the beginning, your device will act as an Access Point \(AP\). It means that your device will broadcast its own WiFi network with an SSID \(name\) similar to `Blynk Device-1234`
2. Your smartphone will connect to this AP with the Blynk app \(or from smartphone settings\) and they will start communicating directly with each other over WiFi
3. Blynk app will ask your customers for the name \(SSID\) and password of the WiFi network they would like to connect their device to.
4. WiFi information \(SSID and password\) will be sent to the device.
5. Also, Blynk app will request **a new AuthToken** from the server and send this AuthToken to the device.
6. Device will store all of these parameters in Flash/EEPROM memory
7. After that, device will automatically reboot. The AP mode will be turned off.
8. Device will use the WiFi credentials your client provided to connect to their home or office WiFi network 
9. After the successful authentication, the device is added to their account and ready to use
10. If they later need to connect to this device to a different network, WiFi credentials can be changed by using Blynk app, by resetting the device with a physical button \(you would need to plan it into your electrical circuit design\)



### Preparation

In general, Blynk.Edgent covers everything you need to enable your productst to get AuthTokens Following this guide will give you a full understanding of how this process works.

{% page-ref page="../getting-started/activating-devices/blynk-edgent-wifi-provisioning.md" %}

{% hint style="warning" %}
**IMPORTANT**: When working on an electrical design for your product: 

1. Plan a physical button that will allow your customers to reset the device to its factory settings. E.g. holding this button for N seconds will erase the AuthToken \(and WiFi credentials\).
2. Plan an LED to indicate the status of the device. It can be RGB or a single color LED.

You can find references to handling reset and statuses indication in Blynk.Edgent examples.
{% endhint %}



### Delivering devices to the client

Your clients will use the Blynk app to connect their devices. Here is an example of how it works:

{% hint style="info" %}
User experience is different for iOS and Android devices. Future updates of these operating systems can result in UI changes. These changes are handled by Blynk.  
{% endhint %}

{% embed url="https://www.youtube.com/watch?v=bXPEEmsEtPM" %}

