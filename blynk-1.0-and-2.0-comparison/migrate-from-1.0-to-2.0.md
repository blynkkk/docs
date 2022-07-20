# Migrating to the new Blynk - Full Guide

### **Introduction**

In May 2021, Blynk released the latest generation of the Blynk IoT Platform called “Blynk IoT”. This guide is intended to assist someone currently using the legacy version of Blynk (“Blynk Legacy”) to migrate to the latest Blynk system. The Blynk Legacy version shutdown timeline is:

* The Blynk Legacy platform support stopped - May 27, 2021&#x20;
* Legacy app closed for new user registration - September 5, 2021&#x20;
* Legacy apps removed from the AppStore and Google Play (apps continue to work for existing users) - June 30, 2022&#x20;
* In-app purchases deprecated - September 30, 2022&#x20;
* Legacy server shutdown - December 31, 2022

## How to migrate from legacy Blynk to Blynk IoT

### Getting Started

* Create a [new account](https://blynk.cloud/dashboard/register) on Blynk.Console (your old account does not exist on the new platform). This should be done by the Developer, the single user who builds the hardware, develops the firmware, and does all of the device configurations.
* Install Blynk IoT app on your mobile device. Make sure it runs Android 5 or later and/or iOS 14.1 or later.
* Check [here](../blynk.edgent-firmware-api/supported-boards.md) to confirm that your IoT hardware is supported by Blynk IoT. Note that all boards supported under Legacy Blynk are also supported under the new Blynk IoT.
* Map out the widgets you intend to utilize in both the Blynk IoT app and Blynk.Console (web console). Begin with your existing Blynk Legacy configuration, then evaluate the [new Blynk IoT widget options](migrate-from-1.0-to-2.0.md#blynk.app) against your map.
* Enable [developer mode](../getting-started/developer-mode.md#how-to-enable-developer-mode) in either the Blynk.Console (web app), or the Blynk IoT (Android/iOS mobile app).
* Build a new [device template](../concepts/device-template.md) from the Blynk.Console, or the Blynk IoT app. It is highly recommended you initially use the Quickstart Template and Quickstart Device automatically created when you walk through the Quickstart flow suggested to you at [setting up a new account](https://blynk.cloud/dashboard/register), and keep it simple to verify the complete workflow and communication between your IoT device, the Blynk.Cloud, Blynk IoT, and the **** Blynk.Console. Note that Blynk Legacy Device Tiles Widget is replaced by Device Templates in Blynk IoT and it became the default view for the list of devices.
* Provision your device(s) using one of the three [device activation methods](../getting-started/activating-devices/). Depending on the activation method chosen, you may need to add a device to your account using the Blynk IoT or Blynk.Console.
* [Follow this tutorial](../getting-started/template-quick-setup/) to verify communication between your first IoT device, the Blynk.Console, and Blynk IoT. You will also need to configure [Datastreams](../blynk.console/templates/datastreams/).
* Add more features in the form of Datastreams and Widgets to your Template and IoT device sketch, confirming functionality one item at a time.
* Continue with the migration of legacy features such as Event Logging, OTA, Device Sharing (via QR code), and HTTP AP.

### Service Subscription

Blynk IoT products and services are provided as a subscription plan. Visit [blynk.io/pricing](https://blynk.io/pricing) to see the plan options. A FREE plan is available for you to explore the new Blynk platform capabilities.

For those of you who purchased Energy in the legacy app, we provide a 50% discount on the first year or first month of a Plus or PRO subscription. The promo code (obtained from the legacy app) can be redeemed in the Blynk.Console only, and is valid until Aug 31, 2022. The discount may also be applied to an upgrade from the FREE plan to Plus or PRO.

### IoT Hardware & Firmware

Blynk may be deployed on more than 400 IoT device types, including Arduino, Particle, ARM mbed, TI Energia, MicroPython, Node.js, OpenWRT, and many Single Board Computers. You can review the [list of supported devices and provisioning options](../blynk.edgent-firmware-api/supported-boards.md) for them.

Update the library on the device to the latest version. Modify your firmware to add `BLYNK_TEMPLATE_ID` and `BLYNK_DEVICE_NAME` in the top of your firmware (prior to any includes).

Note that Datastreams now provide the data transfer between your IoT device, the Blynk.Console, and Blynk IoT. They are similar to the Blynk Legacy virtual pins, but with much more capability.

Replace Blynk.notify(), Blynk.email(), Blynk.tweet(), Blynk.sms() with Blynk.logEvent(). Read this guide on how to set up Events with notifications.

WiFi, cellular, USB, and Ethernet are supported by Blynk IoT. Classic Bluetooth and low energy Bluetooth (BLE) are not currently supported.

Over-The-Air Firmware Updates (OTA) are triggered by a new shipment created in Blynk.Air. Extensive management and control over multiple device OTA is provided by Blynk.Air.

### Blynk.Console

The Blynk.Console is a no-code web application that allows you to:

* Configure and manage devices, users, data, and organizations.&#x20;
* Create a dashboard with multiple tabs for interacting with your devices via Widgets.

If needed you can get better understanding of the general concepts of devices, templates, users, organizations, multi-tenancy, and automations.

Blynk account supports an organization and sub-organizations (available in PRO and Business Plans). Members (users), devices, and locations are assigned to organizations or sub-organizations. Members may be assigned the role of 'Admin', 'Staff', or 'User'. See also the documentation, and this blog.

### Blynk.App

The no-code phone application for Blynk IoT supports many new features:

* Pages - now you can create multiple pages and point Button Widgets to open them.&#x20;
* 16 new widgets: icon button, image button, step slider, vertical step slider, slop control, switch button, level slider, level slider with switch, radial gauge, enhanced gauge, gradient ramp, icon, link button, link image button, alias.

Note the following regarding the former Blynk Legacy widgets:

* Bridge widget for device-to-device communication is replaced by Automations, and the upcoming Rule Engine.
* Eventor widget is replaced by Automations.&#x20;
* Timer widget is replaced by Automations.
* RTC widget is replaced by Time API.
* WebHook widget is replaced by Webhooks feature in the Blynk.Console. They are triggered by a system event or a Datastream.
* Notifications and Email widgets are replaced by Automations and Template Events.
* Twitter widget was deprecated, but you can use Webhooks.
* Terminal widget is replaced by the Terminal Widget available in both the Blynk.App and Blynk.Console.&#x20;
* Table widget is not yet available.
* Device Selector is replaced with Device Tiles in both Blynk.App and Blynk.Console. Several devices can be grouped to be controlled simultaneously by a single command using Blynk.App Groups feature (available in Business Plan only).
* Device Tiles are replaced by Device Templates. Tiles is a new default view for list of devices.
* Reports widget was replaced with Download Report feature in Blynk.Console. Scheduled reports are not available yet.
* The widget min/max property is now defined within a Datastream.

Adjust indexing for Image Gallery, Menu, Icon, Segmented Switch, Icon Segmented Switch widgets. It used to start with one (1), but in the new Blynk IoT it starts from the min value of the associated DataStream.

Make sure you are in Developer Mode when building the application.

### HTTP API

If you're using HTTP API, you need to update your server and request URLs.





## Account and projects migration

You will need to [create a new account](https://blynk.cloud/) and re-create new device templates.
