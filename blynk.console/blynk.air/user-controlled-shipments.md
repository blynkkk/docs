---
description: The feature that allows end-user to decide when to apply a new firmware update
---

# User-controlled Shipments

By default, all shipments are delivered automatically if the device meets the shipment conditions. However, sometimes, when interrupting your hardware with firmware updates is not desired and you want end-users to control the device firmware updates manually - you can use the **user-controlled Shipments**.

To enable user-controlled shipments you need to add the "Firmware Update Control" metafield to your template. By [adding this metafield to your device template](../templates/metadata/), you provide the ability for the end-users to control device updates manually for every newly created shipment. "Firmware Update Control" metafield works the same way as other metafields. It has a default state for auto-updates switch and you can require the end-user to set the state of the auto-update control during the device provisioning.

After adding the metafield, the user can disable or enable firmware auto-updates both: in the [Blynk.Console](../devices/device-profile/device-info.md) and Blynk.App device information page.

<figure><img src="../../.gitbook/assets/new-firmware-available-in-app.png" alt=""><figcaption><p>"Firmware Update Control" metafield look in the mobile device information window</p></figcaption></figure>

If the user disables auto-update, as soon as a new update is available, we will display a button to update the firmware on the device information screen. After the user clicks on the "Update Firmware" button, we will send the new firmware to the device if it is online or wait until the device goes online to send the new firmware. Note that the preferred shipment time is ignored in this case. Blynk will send an update as soon as possible.

<div data-full-width="false">

<figure><img src="../../.gitbook/assets/firmware-updates.png" alt="" width="375"><figcaption><p>Firmware Update pop-up window on the Blynk.Console</p></figcaption></figure>

</div>



In addition, if you want to notify users who have disabled auto-update of a new firmware update, you can enable the "Send push notification" option in the shipment settings. The notification will be sent to all eligible users when the shipment is created.

<figure><img src="../../.gitbook/assets/ota-settings.png" alt=""><figcaption><p>Shipment Settings</p></figcaption></figure>

For White-Label customers, Blynk also provides the ability to create a "Critical Shipment": such a shipment will ignore user-configured auto-update settings.

Alternatively, you can remove the "Firmware Update Control" metafield from the template to automatically propagate the update to every user.
