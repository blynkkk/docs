---
description: Blynk.Apps main functionality
---

# Overview

Blynk offers native iOS and Android mobile apps which allow to remotely control connected devices and visualize data from them.

App operates in two modes:

#### **Developer Mode**

The primary function of Developer Mode in the mobile app is to [build and edit the Mobile Dashboard User interface (GUI) for the given Device Template](constructor.md).

Mobile Dashboard is built from Widgets - modular UI elements which can be positioned on the canvas. Every Widget serves a special function (a button, a slider, a chart, etc). Every Widget has it's own settings based on its functionality**.**

#### **End-user mode**

This mode is used by both the makers and the end-users.

It's focused on devices, automations and notifications view and management with the help of widgets and additional screens containing specific information about data that is set/sent/received to/from Blynk.Cloud and devices.

## Home screen

Home screen consists of up to 3 tabs depending on the configuration: [Devices](overview.md#devices), [Automation](overview.md#automation) and [Notifications](overview.md#notifications)

### **Devices**

![Devices tab](https://user-images.githubusercontent.com/72790181/119994901-b923c300-bfd5-11eb-9475-a0d1826a875b.png)

This section is open by default when you open the app. All created devices will be listed here and their tiles will look according to their [template ](../blynk.console/templates/)type. To add new device go to the [Right](overview.md#right-menu) menu by tapping the top right button in the navigation bar. There are also options to change how devices are sorted.

If there are no devices yet, there is a button "Add new device" in the middle wich takes you right to the device provisioning routine.

### **Automation**

{% hint style="info" %}
This section is visible only when a template has at least one datastream enabled for automation.\
To enable the datastream for automation, please read the [Datastreams](../blynk.console/templates/datastreams/datastreams-common-settings/) article.
{% endhint %}

![Automation tab](https://user-images.githubusercontent.com/72790181/119659015-711a6a00-be36-11eb-982f-f4d3ab66a0c3.png)

You can [automate](../concepts/automations.md) your connected devices with the following triggers:

* Time of the day
* Sunset and sunrise
* Device trigger
* Manual execution (Scenes)

### **Notifications**

![Notifications tab](https://user-images.githubusercontent.com/72790181/119659055-7a0b3b80-be36-11eb-8eeb-8eaf4f27957a.png)

The list of notifications from all devices will be here.

{% hint style="info" %}
In order to be listed here, the template should have the [Event](../blynk.console/templates/events/) configured and the event should be [triggered](../blynk.console/templates/events/custom-events/events--how-to-log-events.md) in the device.
{% endhint %}

## Device dashboard

![Device dashboard](https://user-images.githubusercontent.com/72790181/119659080-7f688600-be36-11eb-8cb0-63d378339091.png)

When a user taps on the device tile, the device dashboard will be opened. It consists of widgets that allow controlling and monitoring the device. The layout of the widgets and their settings can be edited in the [Developer mode](../getting-started/developer-mode.md)

### **Device Info and Timeline**

At the top right corner of the dashboard, there's an ... icon that opens another view with the\
Device Information and Timeline.

On the **Device Info** tab, you can edit a device name, change other [metadata](../blynk.console/devices/device-profile/metadata.md) values, view other things like firmware version, etc.

![Device profile](https://user-images.githubusercontent.com/72790181/119659123-898a8480-be36-11eb-9088-46e48b4c0015.png)

On the **Timeline** tab, you'll find the list of all events of the device (for example online, offline and custom [Events](../blynk.console/templates/events/))

![Timeline](https://user-images.githubusercontent.com/72790181/119659291-b048bb00-be36-11eb-8d83-762314da9862.png)

### **Device Actions menu**

![Device actions menu](https://user-images.githubusercontent.com/72790181/119659307-b50d6f00-be36-11eb-86fb-69df17cef2bc.png)

At the top right corner of the Device Info and Timeline tabs, there's **Configure** (gear) \_\*\*\_icon that opens an actions menu with the following options:

* Reconfigure
* Erase all device data
* Delete device

## Main menu

![Left sidebar](https://user-images.githubusercontent.com/72790181/119659337-bc347d00-be36-11eb-82a1-19c3d94d2787.png)

At the top left corner, there's a **Profile** icon that will open the main menu when you tap on it. This menu consists of the following entries:

* **My profile** – here you can change your name, password, or delete your account.
* **Organization settings** – \_\*\*\_here you can change the organization name, description, and timezone.
* **Members** – here you can invite new users to an organization by sending them an Email
* **Switch organization** – if you have other [organizations](overview.md) created, you can switch to and from them using this switch.

## **Right menu**

![Right sidebar](https://user-images.githubusercontent.com/72790181/119659382-c5bde500-be36-11eb-89da-c0e8c774600a.png)

At the top right corner, there's a hamburger icon that will open the right sidebar menu when you tap on it.\
Depending on the active tab on the [Main screen](overview.md#main-screen) it offers to add new Device, create new Automation, new Group, etc.

This menu also offers the various sorting and stacking options for the devices and device groups list.
