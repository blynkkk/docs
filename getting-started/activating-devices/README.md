# Device Activation Methods

In order to become active in Blynk.Cloud and available for use, each device should have a unique AuthToken. AuthToken is the main identifier of the device in the Blynk Cloud. Depending on the hardware, connectivity, and the IoT use-case you are working on, a way of getting AuthTokens for your device can vary.

With Blynk you can use three ways to activate devices: 

1. Manually create a device using Blynk.Console for initial prototyping
2. Use Blynk.Inject for WiFi-enabled devices
3. Use Static Tokens for cellular, Ethernet, and other non-WiFi connection methods

### 1. Activating devices with manually generated AuthTokens

This method is recommended for prototyping stages or when you build a device for yourself. It's the most simple method that works with any supported hardware and any connection type.

On a high level, you manually create a new device and then place the generated AuthToken to your device.

The main difference from WiFi provisioning is that AuthToken should be manually generated and flashed to the device before it can be used.

#### Here is a tutorial on how to activate devices manually:

{% page-ref page="manual-device-activation.md" %}

### 

### 2. WiFi provisioning using Blynk.Inject

For supported devices that can connect to the Internet over WiFi, you can use **WiFi provisioning** method which is built-in into Blynk.Apps. 

Using this method, Blynk.Apps, and Blynk.Edgent will take care of telling your devices how to connect to your home or office WiFi network. New AuthToken will be automatically generated and stored on the device. There is no need to specify WiFi credentials and Auth Token in the firmware code.

{% hint style="warning" %}
Using provided WiFi provisioning is highly recommended if you are working on a commercial WiFi product
{% endhint %}

This method is especially beneficial for commercial applications because:

* You don't know upfront to which WiFi network your clients will connect your devices to
* It simplifies the manufacturing process at scale as you use same code without a need to manually add AuthToken to each device

#### Here is a tutorial on how to activate devices with Blynk.Inject:

{% page-ref page="blynk-edgent-wifi-provisioning.md" %}



### 3. Static Token Activation

This method is usually used in commercial applications when you need to deploy a high volume of devices and they will need to be activated by end customers. 

This method works best with non-WiFi devices. 

#### Here is a tutorial on how to activate devices with Static tokens:

{% page-ref page="../../commercial-use/deploying-products-with-static-authtokens.md" %}
