# Deploying Products With Dynamic AuthTokens

Every device needs a unique AuthToken in order to authenticate in Blynk.Cloud. During prototyping, you can manually add AuthToken to every device. However, when working with commercial products you would need a scalable approach to eliminate manual work.



## Why use dynamic AuthTokens

1. With this approach, you don't have to flash different AuthTokens onto every device. You can use the same firmware on every device, which significantly simplifies the production process.
2. Dynamic AuthTokens workflow is included in Blynk.Edgent and works out-of-the-box.
3. This flow is integrated with Blynk.Apps providing great user experience for end customers.&#x20;

{% hint style="info" %}
Dynamic AuthTokens works only with Wi-Fi devices. Supported devices are: ESP32, ESP8266, WiO Terminal by Seeed, Arduino MKR1010, Arduino Nano 33IoT, and Texas Instruments CC3220. Raspberry Pi will be supported soon.
{% endhint %}

### ****

## **How Dynamic AuthTokens work**

Dynamic AuthToken generation is a part of the device provisioning process:

1. In the beginning, your device will act as an Access Point (AP). It means that your device will broadcast its own WiFi network with an SSID (name) similar to `Blynk Device-1234`
2. Your smartphone will connect to this AP with the Blynk app (or from smartphone settings) and they will start communicating directly with each other over WiFi
3. Blynk app will ask your customers for the name (SSID) and password of the WiFi network they would like to connect their device to.
4. WiFi information (SSID and password) will be sent to the device.
5. Also, Blynk app will request **a new AuthToken** from the server and send this AuthToken to the device.
6. Device will store all of these parameters in Flash/EEPROM memory
7. After that, device will automatically reboot. The AP mode will be turned off.
8. Device will use the WiFi credentials your client provided to connect to their home or office WiFi network&#x20;
9. After the successful authentication, the device is added to their account and ready to use
10. If they later need to connect to this device to a different network, WiFi credentials can be changed by using Blynk app, by resetting the device with a physical button (you would need to plan it into your electrical circuit design)



## Preparation

In general, Blynk.Edgent covers everything you need to enable your productst to get AuthTokens Following this guide will give you a full understanding of how this process works.

{% content-ref url="../getting-started/activating-devices/blynk-edgent-wifi-provisioning.md" %}
[blynk-edgent-wifi-provisioning.md](../getting-started/activating-devices/blynk-edgent-wifi-provisioning.md)
{% endcontent-ref %}

{% hint style="warning" %}
**IMPORTANT**: When working on an electrical design for your product:&#x20;

1. Plan a physical button that will allow your customers to reset the device to its factory settings. E.g. holding this button for N seconds will erase the AuthToken (and WiFi credentials).
2. Plan an LED to indicate the status of the device. It can be RGB or a single color LED.

You can find references to handling reset and statuses indication in Blynk.Edgent examples.
{% endhint %}



## Testing WiFi Provisioning Process

Before delivering your IoT products to new customers, it's beneficial to test the user experience your clients will face. Here is an example of how adding new device would work.

{% hint style="info" %}
User experience is different for iOS and Android devices. Future updates of these operating systems can result in UI changes. These changes are handled by Blynk. &#x20;
{% endhint %}

{% embed url="https://www.youtube.com/watch?v=bXPEEmsEtPM" %}

###

## Delivering products to clients (PRO plan workflow)

Here is a recommended workflow for managing customers in PRO plan so that your clients only see devices they own, while you, as an administrator can get access to all the devices, users, organizations, etc.

PRO plan was designed for managed services, where you would need to manually create and manage each customer.&#x20;

First of all, you need to get familiar with the [Multi-tenancy concept](../concepts/multi-tenant-tree-structure.md), organizations hierarchy, and user permissions as you will be using these features often.&#x20;

To create a new client:

* Create a new sub-organization for your client in **Blynk.Console → Organizations -> Create New Organization**
* There will be 3 tabs: Info, Templates, Users.  Go through thema and set up your client. Give it a name, make sure all needed device templates are enabled for this organization, and in the Users Tab invite your client to this organization using their email address. &#x20;
* Your customer will get an invitation email with a link to create a new account by simply creating a password.
* Customer will log in using Blynk.Apps for iOS and Android or Blynk.Console.
* In the app they will tap on Add New Device and go through WiFi provisioning steps to connect the device to their home or office WiFi network
* Device will appear under their account and now it's ready to use





Alternatively, if you know client's WiFi credentials or you provide a mobile hotspot together with the device, you can provision the device under your organization and then transfer it to the client. To do that:&#x20;

* Activate the device in your organization&#x20;
* Create a new sub-organization for your client in **Blynk.Console → Organizations -> Create New Organization**
* There will be 3 tabs: Info, Templates, Users.  Go through thema and set up your client. Give it a name, make sure all needed device templates are enabled for this organization, and in the Users Tab invite your client to this organization using their email address. &#x20;
* Your customer will get an invitation email with a link to create a new account by simply creating a password.
* Customer will log in using Blynk.Apps for iOS and Android or Blynk.Console.
* Once their account is active, use the [Device Transfer](https://docs.blynk.io/en/blynk.console/devices/actions-with-devices#device-transfer) feature.&#x20;
* Device will be transferred to the client and is ready for use.&#x20;



## Managing and Troubleshooting Clients

Once you have active clients, you will most likely need to help them with different questions they have. Here is what you need to become fluent with to provide a good level of customer support:



### 1. Navigating between organizations.&#x20;

With Blynk you can switch to any sub-organization to see "what client sees". When switched, you also get access to this organization's settings like user permissions and more.

To go back to your main organization - click on the Blynk icon in the top left corner.  &#x20;

You can also switch organizations in the mobile app by tapping on the organization name in the left menu (_Test Reseller_ on the screenshot below) - then choosing Switch organization menu

![](<../.gitbook/assets/image (40).png>)

### 2. Transferring devices.

With Blynk you can do all sorts of assets transfer:

* Transfer user to a different organization. Go to Users - hover on the actions button - Transfer User. You would need an email of an administrator of the destination organization.

![](<../.gitbook/assets/image (38).png>)

&#x20;

* [Transfer device](https://docs.blynk.io/en/blynk.console/devices/actions-with-devices#device-transfer) (change owner) from one organization to another. A new owner should be specified.
* Transfer sub-organization (available in Business Plan only)under a different organization. Think about it as moving a folder with files to another folder on your computer.&#x20;

####

### 3. User permissions&#x20;

In Blynk, Permissions are set per organization, which gives you full control of how your clients access devices and other data.&#x20;

Sometimes it can cause a situation where users don't can't access some app features



To check permissions for a current organization and user role

1. Go to Search - Organizations section - find the organization you need  &#x20;
2. Switch to this organization
3. Go to Organization Settings -> Roles and permissions

#### **Advanced use of permissions:**

You can change and apply permissions for all clients or for a group of clients. To do that, you can create such a structure:



![](<../.gitbook/assets/image (36).png>)

* Create a new Organization. For example: My Clients (with no users in it)
* Switch to My Clients
* Set up permissions in this organization as needed
* Any sub-organization you create under My Clients organization will inherit the set of permissions

You can then edit permissions in My Clients organization and when applying changes, enable the switch **Apply to sub-organizations -> Overwrite**

![](<../.gitbook/assets/image (35).png>)

