# Deploying Products With Dynamic AuthTokens

Every device needs a unique AuthToken in order to authenticate in Blynk.Cloud. During prototyping, you can manually add AuthToken to every device. However, when working with commercial products you would need a scalable approach to eliminate manual work.

#### Why use dynamic AuthTokens

1. With this approach, you don't have to flash different AuthTokens onto every device. You can use the same firmware on every device, which significantly simplifies the production process.
2. Dynamic AuthTokens workflow is included in Blynk.Edgent and works out-of-the-box.
3. This flow is integrated with Blynk.Apps providing great user experience for end customers.

{% hint style="info" %}
Dynamic AuthTokens are currently supported on:

* **Arduino:** ESP32 series, ESP8266, Seeed WIO Terminal
* **Particle Gen 3 devices:** Muon, Argon, Boron, Photon 2, Tracker, P2, BSOM, MSOM
* **MicroPython:** ESP32 series, Raspberry Pi Pico W
* **Blynk.NCP:** ESP32 series
{% endhint %}

####

### **Device Activation With Dynamic AuthTokens**

Dynamic AuthToken generation is a part of the device provisioning process:

1. In the beginning, your device will act as an Access Point (AP) — unless it's a BLE-assisted device, in which case it advertises over Bluetooth instead of broadcasting a WiFi network. Either way, your device becomes discoverable with a name similar to `Blynk Device-1234`.
2. Your smartphone will connect to this AP with the Blynk app (or from smartphone settings) and they will start communicating directly with each other over WiFi.
3. Blynk app will ask your customers for the name (SSID) and password of the WiFi network they would like to connect their device to.
4. WiFi information (SSID and password) will be sent to the device.
5. Also, Blynk app will request **a new AuthToken** from the server and send this AuthToken to the device.
6. Device will store all of these parameters in Flash/EEPROM memory.
7. After that, the device will automatically reboot. The AP mode will be turned off.
8. The device will use the WiFi credentials your client provided to connect to their home or office WiFi network.
9. After successful authentication, the device is added to their account and is ready to use.
10. If they later need to connect this device to a different network, WiFi credentials can be changed by using Blynk app, by resetting the device with a physical button (you would need to plan it into your electrical circuit design).

{% hint style="info" %}
If your device also keeps a BLE connection alive during this process, the app can show your customer the device's live status and exact error codes as each of these steps happens, instead of only finding out after the fact. See Real-time feedback during provisioning (BLE).
{% endhint %}

#### Preparation

In general, Blynk.Edgent covers everything you need to enable your products to get AuthTokens. Following this guide will give you a full understanding of how this process works.

{% hint style="warning" %}
**IMPORTANT**: When working on an electrical design for your product:

1. Plan a physical button that will allow your customers to reset the device to its factory settings. E.g. holding this button for N seconds will erase the AuthToken (and WiFi credentials).
2. Plan an LED to indicate the status of the device. It can be RGB or a single color LED.

You can find references to handling reset and statuses indication in Blynk.Edgent examples.
{% endhint %}

#### Testing WiFi Provisioning Process

Before delivering your IoT products to new customers, it's beneficial to test the user experience your clients will face. Here is an example of how adding new device would work.

{% hint style="info" %}
User experience is different for iOS and Android devices. Future updates of these operating systems can result in UI changes. These changes are handled by Blynk.
{% endhint %}

{% embed url="https://www.youtube.com/watch?v=bXPEEmsEtPM" %}

#### Monitoring provisioning at scale

Once you have real customers provisioning real devices, you'll want visibility into how that's actually going — not just how it worked in your own test. **Provisioning Sessions** in Blynk.Console (Developer Zone) logs every attempt across your organization and sub-organizations, with success rates, average duration, and most common errors broken down by iOS/Android, plus a full step-by-step timeline for any individual session.

This is especially useful in the PRO/Enterprise workflows below, where you may not be the one running the provisioning yourself.

#### Delivering products to clients (PRO plan workflow)

Here is the recommended workflow for managing customers in PRO plan so that your clients only see devices they own, while you, as an administrator, can get access to all the devices, users, organizations, etc.

PRO plan was designed for managed services, where you would need to manually create and manage each customer.

First of all, you need to get familiar with the Multi-tenancy concept, organizations hierarchy, and user permissions as you will be using these features often.

To create a new client:

* Create a new sub-organization for your client in **Blynk.Console → Organizations -> Create New Organization**
* There will be 4 tabs: Info, Devices, Users, and Locations. Go through them and set up your client. Give them a name, and in the Users Tab invite your client to this organization using their email address.
* Your customer will get an invitation email with a link to create a new account by simply creating a password.
* Customer will log in using Blynk.Apps for iOS and Android or Blynk.Console.
* In the app, they will tap on Add New Device and go through WiFi provisioning steps to connect the device to their home or office WiFi network
* Device will appear under their account and now it's ready to use.

Alternatively, if you know the client's WiFi credentials or you provide a mobile hotspot together with the device, you can provision the device under your organization and then transfer it to the client. To do that:

* Activate the device in your organization
* Create a new sub-organization for your client in **Blynk.Console → Organizations -> Create New Organization**
* There will be 4 tabs: Info, Devices, Users, and Locations. Go through them and set up your client. Give them a name, and in the Users Tab invite your client to this organization using their email address.
* Your customer will get an invitation email with a link to create a new account by simply creating a password
* Customer will log in using Blynk.Apps for iOS and Android or Blynk.Console
* Once their account is active, use the Device Transfer feature
* The device will be transferred to the client and is ready for use.

#### Delivering products to clients (Enterprise plan workflow)

With [Enterprise plan](https://blynk.io/pricing) you no longer need to invite each client manually like in PRO plan. They can create accounts and claim devices by themselves. Here is how it works:

* Customer will log in using your branded apps for iOS and Android or your branded web console
* In the app, they will tap on Add New Device and go through WiFi provisioning steps to connect the device to their home or office WiFi network
* The device will appear under their account ready to use.

#### Managing and Troubleshooting Clients

Once you have active clients, you will most likely need to help them with different questions they have. Here is what you need to become fluent with to provide a good level of customer support:

**1. Navigating between organizations.**

With Blynk you can switch to any sub-organization to see "what client sees". When switched, you also get access to this organization's settings like user permissions and more.

To go back to your main organization - click on the Blynk icon in the top left corner.

You can also switch organizations in the mobile app by tapping on the My Organizations in the left menu - then choosing an organization you want to switch to.

**2. Transferring devices.**

With Blynk you can do all sorts of assets transfer:

* Transfer user to a different organization. Go to Users - hover on the actions button - Transfer User. You would need an email of an administrator of the destination organization.
* Transfer device (change owner) from one organization to another. The new owner should be specified.
* Transfer sub-organization under a different organization. Think about it as moving a folder with files to another folder on your computer.



**3. User permissions**

In Blynk, Permissions are set per organization, which gives you full control of how your clients access devices and other data.

Sometimes it can cause a situation where users can't access some app features.

To check permissions for current organization and user role

1. Go to Organizations section - find the organization you need
2. Switch to this organization
3. Go to Organization Settings (a Cog icon near the organization name in the top bar) -> Roles and permissions

**Advanced use of permissions:**

You can change and apply permissions for all clients or for a group of clients. To do that, you can create such a structure:

* Create a new Organization. For example: My Clients (with no users in it)
* Switch to My Clients
* Set up permissions in this organization as needed
* Any sub-organization you create under My Clients organization will inherit the set of permissions

You can then edit permissions in My Clients organization and when applying changes, enable the switch **Apply to sub-organizations -> Overwrite**
