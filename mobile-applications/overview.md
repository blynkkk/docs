---
description: Blynk.App main tabs and features
---

# Overview

Application generally consists of [main screen](./overview.md#main-screen) and 2 menu sliders: the [main one](./overview.md#main-menu) (slides from the left) and [secondary one](./overview.md#right-menu) that slides from the right.

## Main screen 

The main screen consists of up to 3 tabs depending on the configuration: [Devies](./overview.md#devices), [Automation](./overview.md#Automation) and [Notifications](./overview.md#Notifications)


### **Devices**
![](../.gitbook/assets/2-no-devices.png)  ![](../.gitbook/assets/1-main-screen.png)

This section is open by default when you open the app. When there are no devices yet, there's a button "Add new device".  
All created devices will be listed here and their tiles will look according to their [template ](../web-dashboard/products/)type.

### **Automation**

{% hint style="info" %}
This section is visible only when a template has at least one datastream enabled for automation.   
To enable the datastream for automation, please read the [Datastreams](../web-dashboard/products/datastreams/datastreams-common-settings/) article.
{% endhint %}

![](../.gitbook/assets/3-automations.png)

You can automate your connected devices with the following triggers:

* Time of the day
* Sunset and sunrise
* Device trigger
* Manual execution \(Scenes\)

### **Notifications**

![](../.gitbook/assets/alerts.png)

The list of notificatios and important alerts from all devices will be here. 

{% hint style="info" %}
In order to be listed here, the template should have the [Event](../web-dashboard/products/events/) configured and the event should be [triggered](../web-dashboard/products/events/how-to-trigger-events.md) in the device.
{% endhint %}

## Device dashboard

![](../.gitbook/assets/device-dashboard.png)

When a user taps on the device tile, the device dashboard will be opened. It consists of widgets that allow controlling and monitoring the device. The layout of the widgets and their settings can be edited in the [Developer mode](../getting-started/developer-mode.md)

### **Device Info and Timeline**

At the top right corner of the dashboard, there's an ... icon that opens another view with the   
Device Information and Timeline.  
****  
On the **Device Info** tab, you can edit a device name, change other [metadata](../web-dashboard/search/devices-1/device-view/metadata.md) values, view other things like firmware version, etc.

![](../.gitbook/assets/device-info-1-.png)

On the **Timeline** tab, you'll find the list of all events of the device \(for example online, offline and custom [Events](../web-dashboard/products/events/)\)

![](../.gitbook/assets/timeline-1-.png)

### **Device Actions menu**

![](../.gitbook/assets/device-actions.png)

At the top right corner of the Device Info and Timeline tabs, there's **Configure** \(gear\) ****icon that opens an actions menu with the following options:

* Reconfigure
* Erase all device data
* Delete device

## Main menu

![](../.gitbook/assets/main-menu.png)

At the top left corner, there's a **Profile** icon that will open the main menu when you tap on it. This menu consists of the following entries:

* **My profile** – here you can change your name, password, or delete your account.
* **Organization settings** – ****here you can change the organization name, description, and timezone.
* **Members** – here you can invite new users to an organization by sending them an Email
* **Switch organization** – if you have other [organizations](../web-dashboard/organizations.md) created, you can switch to and from them using this switch.

## **Right menu**

At the top left corner, there's a hamburger icon that will open the right sidebar menu when you tap on it.  
Depending on the active section it offers to add new Device or create new Automation.

![](../.gitbook/assets/sidebar-opened-2-.png)

In the devices section, this menu also offers the sorting options for the device list.  


