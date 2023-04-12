# Devices

This is the main view, where you can manage all devices that belong to your organization, including the sub-organizations (if you have any)

![](https://user-images.githubusercontent.com/72824404/120637733-ecec6600-c477-11eb-9aff-24dbddbcb29a.png)

## Predefined Filters

In the sidebar there are segments of devices.&#x20;

![](https://user-images.githubusercontent.com/72824404/120638891-68024c00-c479-11eb-8fa0-adc2f1644392.png)

**My Devices** – List of devices that belong to your organization and the ones you have access to based on role and assigned permissions

**All** **Devices**– list of all devices that your organization has access to, including all devices in sub organizations. &#x20;



## Quick search

You can search devices by almost any parameter.&#x20;

![](../../.gitbook/assets/quick-search.gif)

Search can be performed by the following fields:

* Device Name
* ICCID
* Firmware Version
* Organization Name
* Device Model
* Template Name
* Device Owner Name
* Hotspot Name
* Contact Email, Street Address, Phone Number
* IMEI
* Auth Token
* Serial Number
* Device ID
* Tag
* other [Metadata](device-profile/metadata.md) set in [Template](../../concepts/device-template.md)

#### Search steps:

1. Click on Devices row in Search Filtering Panel
2. Start typing to perform a search. Search results will be segmented by sections will appear in the dropdown.&#x20;
3. Click on result you need and you'll get all the Devices containing it in Table View
4. Use sorting and filter of the table columns to narrow down the search.

## Table view

{% hint style="info" %}
Keep scrolling down to load more devices.
{% endhint %}

**Navigation:**

* Click on **Device Name** – opens [Device View](device-profile/)
* Click on **Device Owner** – opens Device Owner profile
* Click on **Organization Name** – opens device [Organization](../organizations.md)

## Map view

Here you can search and view Devices (depending on selected filter) by their locations.

![](https://user-images.githubusercontent.com/72824404/120645490-28d7f900-c481-11eb-8ea5-189ee5095ec3.png)

Applied filtering option and Devices count are shown at top left.

Map supports mouse scroll zoom in/out.\
Hold left mouse button to move the map.

You'll see dots of two colors on the map:

* **Blue** – devices group with built-in devices counter. Click it to zoom in and view devices.
* **Orange** – device. Click it to view device name, template logo, actual connectivity status and latest in/accessibility date. Click on Device Name on map opens [Device View](device-profile/).
