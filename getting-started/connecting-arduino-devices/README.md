# Activating your devices

In order to become active in Blynk.Cloud and available for use, each device should have a unique AuthToken. AuthToken is the main identifier of the device in the Blynk Cloud. Depending on the hardware, connectivity, and the IoT use-case you are working on, a way of getting Auth Tokens for your  device can vary.

Here are the two main ways of putting AuthTokens on your devices:

### 1. WiFi provisioning using Blynk.Edgent

For devices that can connect to the Internet over WiFi, we recommend using the built-in **WiFi provisioning** method. This method is sometimes called Dynamic Auth Token provisioning.

Using this method, Blynk app, and Blynk.Edgent will take care of telling your devices how to connect to your home or office WiFi network. New Auth Token will be automatically generated and stored on the device. There is no need to specify WiFi credentials and Auth Token in the firmware code. 

{% hint style="warning" %}
WiFi provisioning is highly recommended if you are working on a commercial WiFi product
{% endhint %}

This method is especially beneficial for commercial applications because:

* You don't know upfront to which WiFi network your clients will connect your products to
* It simplifies the manufacturing process at scale as you can use similar firmware code without a need to manually add Auth Token to each device at the end of the manufacturing line. 

**Read the guide on how to set up WiFi provisioning:**

{% page-ref page="wifi-provisioning.md" %}

### 

### 2. Activating device with Static Auth Token

The main difference from WiFi provisioning is that for every device AuthToken should be generated manually and flashed to the device before it can be used.

This method is recommended for devices that can connect to the internet using Ethernet, Cellular \(2G, 3G, 4G, LTE\) or other types of connection \(that don't require custom WiFi credentials for example\). 

Static Auth Token is often used during the prototyping stage. However, Blynk also offers a complete solution to work with Static tokens in commercial applications  

**Read the full guide on how to use Static Auth Token:**

{% page-ref page="static-authtoken.md" %}



