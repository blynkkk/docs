# Actions with devices

You can perform various actions with individual and multiple devices. Actions are accessible from the List of devices, and from Device Profile views.

![](https://user-images.githubusercontent.com/72824404/120639525-1ad2aa00-c47a-11eb-9733-10677e6fd766.png)

## Create Device

In the list of devices, click **New Device.** A dialogue will pop up:

![](https://user-images.githubusercontent.com/72824404/120639196-c5969880-c479-11eb-849f-6bc5e298e2a6.png)

1. **Choose template** – click this field and select the Template from the dropdown list
2. **Device Name** – give it a meaningful name up to 60 characters. Use only letters, digits, and spaces.
3. Click **Create** button to confirm the action.

_\*\*\*\*_

## Actions Column (mouse over the last column)

### Rename

Opens Rename Device modal window. Input new name up 60 characters here. Confirm.

![](https://user-images.githubusercontent.com/72824404/120640485-37231680-c47b-11eb-86d4-9336d8b047e9.png)

### Download report

In this view you can configure and generate report.

![](https://user-images.githubusercontent.com/72824404/120641024-cf210000-c47b-11eb-941e-dd8ac0254485.png)

**Report Settings:**

**Time range:** Choose a time range from today's date and time, back to selected range

**Include events data:** this option will include timestamps and Event names into the report. You need to have [Events](../../getting-started/events-tutorial.md) set up.

**Send link to email:** when on, a link to download a report will be sent to the specified email address below

**Data Aggregation:** defines how data in the report will be aggregated (compressed). Aggregation means that data will be averaged to 1 value per selected time range.

For example, if device sent 60 values in 1 minute, only 1 value will be in the report. This will be an averaged value from all 60 readings. `AVG(reading1, reading2, reading3...reading N)`

Raw data means no aggregation will be applied

**Timezone correction:** set up if you need to adjust timestamps in the report to a specific timezone

**Date and time format:** Change the date and time format to be used in report

\*\*\*\*

### Device Transfer

![Device Transfer](https://user-images.githubusercontent.com/72824404/120641371-3343c400-c47c-11eb-8a5d-a66ec4290d30.png)

You can use the device transfer feature to achieve the next goals:

* Change the device ownership
* Move the device within your organization hierarchy

If you don't see this option, most likely you don't have enough permissions. Contact your administrator.

#### Ownership change

Every device has an owner. Usually, the device owner has more access over the device than other users. However, this is fully configurable over **view own devices** and **view organization devices** permissions. To change the ownership, device transfer action is used.

In order to change the ownership you need:

* The new device owner should belong to your organization
* The new device owner account should exist and be activated (user logged at least once)

Once the device is transferred, both parties will receive a confirmation.

#### Move device to another organization within your hierarchy

You can also use the **device transfer** action to move the device within your organization hierarchy.

In order to move the device within organization hierarchy you need:

* The new device owner should belong to your or underlying organizations
* The new device owner account should exist and be activated (user logged at least once)
*   The organization of the new device owner should have the template of the transferred device.

    Right now, all templates from the parent organization are added automatically when the new organization is created, however you can change that

Once the device is transferred, both parties will receive a confirmation.

For example, you can create the sub organization, invite the new user to it, and transfer the device to this new user. After the transfer the device will be visible only for the user from the transferred organization and for all users with **view organization devices** permission enabled from the above, parent organizations along with **switch organization** permission.

#### Move device to another organization not from your hierarchy

This feature is not yet implemented and will be available when **Template publishing** will be delivered.

### Edit Template Dashboard

A quick way to edit a dashboard layout for the template of current device. When selected, you will be sent to Device Template -> [Template Dashboard](../templates/dashboard/) edit

{% hint style="info" %}
Dashboard Editing available from device profile view in [Developer Mode](../../getting-started/developer-mode.md) only.
{% endhint %}

### Notification settings

Opens [Notifications Management](../../getting-started/notification-management/)

### Erase data

Erase all device data. **⚠️ It's a critical action**

### Delete Device owner

Clear device ownership. Device can be transferred to a new owner. **⚠️ It's a critical action**

### Delete Device

Deletes Device entry and all it's data. **⚠️ It's a critical action**

\*\*\*\*

## Bulk actions

Bulk actions are available when multiple devices are selected in the list view. To access these actions choose devices and press action button ("three dots") at the top of the device list.

{% hint style="warning" %}
Only loaded/visible devices will be selected. To load devices - scroll down to reveal more devices.
{% endhint %}

* **Tag:** apply a [tag](../settings/organization-settings/tags.md) to multiple devices
* **Export devices CSV:** download the list of devices in CSV format&#x20;
* **Notification settings** - apply same notification settings to multiple devices
* **Delete:** deletes all selected devices their data.**⚠️ It's a critical action**
