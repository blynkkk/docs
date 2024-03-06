# Device Sharing

Blynk doesn't allow anonymous device sharing like it was done in the first version of Blynk. If you want to share the device, users you want to share the device with should be registered within the Blynk.Console.

Device sharing is handled with permission **View Organization Devices**, **Control Organization Devices**, **View Own Devices**, and **Control Own Devices**.

At the moment in order to share the device you have 2 options:

* Invite the user to your organization
* Create a sub-organization (available only for the **PRO** users), invite the user to the sub-organization, and transfer the device into it

In both above use cases the user could provision the device by himself after he is invited to the org or suborg.

## Sharing via Own organization

In order to share your device with someone, you just need to invite this user to your organization.

Right now you can select **Admin**, **Staff,** or **User** roles during the invitation. Users should have a role with **View Organization Devices** permission in order to see their devices. Keep in mind, that the default **User** role doesn't have any permissions. You need to set the required permissions for this and other roles. Otherwise, the invited user will see the empty screen without any devices.

You can [transfer the device ownership](actions-with-devices.md#device-transfer) to the user you want to share the device with within your organization (the user should be invited to your organization). In that case, you can restrict the access of the user to other devices within the organization, so the user with permission to **View Own Devices** will see only devices where he is the owner.

In other words, users who don't have permission to **View Organization Devices** can't see other organization devices. They can only see the devices where they are owners and only if they have **View Own Devices** permission. Users with **View Organization Devices** can see all devices within the organization they belong to.

This type of sharing is useful when you have only one user to share the device with and you don't want to isolate the device within another organization.

For example, you want to share your garage door with your wife, so you both can view and control the garage doors. At the same time, you have other devices you're playing with, and you don't want your wife to see them (because one of the devices is a beer machine, so obviously you don't want your wife to be aware of it). You invite your wife with a role that has **View Own Devices** and doesn't have **Control Own Devices** permission, and you transfer the ownership of the garage doors device to the wife. Now you (as administrator) can see all devices, and she (as device owner) can view and control only the garage doors device.

## Sharing via sub-organization

You can create the sub-organization, invite multiple users you want to share the device with and transfer the device ownership to one of those users (you still need to transfer the ownership, as the device transfer could be done only by the user email). For that type of sharing all users within sub-organization should have **View Organization Devices** permission. Otherwise, the device will be visible only to the owner of the device. Keep in mind, that users from sub-organizations never can see any data from the upper organization hierarchy.

This type of sharing is useful when you want to share the device with many users. You still will be able to see this device in the search or via the **organization switch**.

For example, now your children are grown up, and you want to share your garage door with not only your wife but also with children. But, you still have your drinking machine (it was helping you while your children were growing), so you don't want to share it with your wife and children. The device can have only one owner. You can give **View Organization Devices** permission to your family. However, in that case, your family will see other devices within your organization. So you have to create a new sub-organization and invite into it your family with **View Organization Devices** permissions, and now they will be able to view the garage doors. Sub-organization has only one device, so your family will see only it. You still be able to see the devices in the own/root organization via the search and in the sub-organization via **organization switch**.
