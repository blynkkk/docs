# Overview

## Main screen 

The main app screen consists of up to 3 tabs depending on the configuration:  


**Devices**  
This section is open by default when you open the app. When there are no devices yet, there's a button "Add new device".  
All created devices will be listed here and their tiles will look according to their [template ](../web-dashboard/for-developers/products/)type.

**Automation**  
You can automate your connected devices with the following triggers:  
  
- Time of the day  
- Sunset and sunrise  
- Device trigger  
- Manual execution \(Scenes\)  
  
****This section is visible only when a template has at least one datastream enabled for automation.   
To enable the datastream for automation, please read the [Datastreams](../web-dashboard/for-developers/products/datastreams/datastreams-common-settings/) article.

**Alerts**  
The list of important alerts from all devices will be here. In order to be listed here, the template should have the [Event](../web-dashboard/for-developers/products/events/) configured and the event should be [triggered](../web-dashboard/for-developers/products/events/how-to-trigger-events.md) in the device.

## Device dashboard

When a user taps on the device tile, the device dashboard will be opened. It consists of widgets that allow controlling and monitoring the device. The layout of the widgets and their settings can be edited in the [Developer mode](developer-mode/)  
  
**Information and Timeline**  
At the top right corner of the dashboard, there's an \[...\] icon that opens another view with the   
Device Information and Timeline.  
On the Information tab, you can edit a device name, change other [metadata](../web-dashboard/for-developers/search/devices-1/device-view/metadata.md) values, view other things like firmware version, etc.  
On the Timeline tab, you'll find the list of all events of the device \(for example online, offline and custom [Events](../web-dashboard/for-developers/products/events/)\)  
  
**Device Actions menu**  
At the top right corner of the Information and Timeline tabs, there's an \[...\] icon that opens an actions menu with the following options:  
- Reconfigure  
- Erase all device data  
- Delete device

## Main menu

At the top left corner, there's a user icon that will open the main menu when you tap on it. This menu consists of the following entries.  
**My profile**  
Here you can change your name, password, or delete your account.  
**Organization settings**  
Here you can change the organization name, description, and timezone.  
**Members**  
Here you can invite   
**Switch organization**  
If you have other [organizations](../web-dashboard/for-developers/organizations.md) created, you can switch to and from them using this switch.

## **Right menu**

At the top left corner, there's a hamburger icon that will open the right sidebar menu when you tap on it.  
Depending on the active section it offers to add new Device or create new Automation.  


In the devices section, this menu also offers the sorting options for the device list.

  


