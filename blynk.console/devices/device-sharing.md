# Device Sharing

Blynk doesn't allow anonymous device sharing like it was done in the first version of Blynk. If you want to share the device, users you want to share the device with should be registered within the Blynk.Console.

Device sharing is handled with permission **View Organization Devices**, **Control Organization Devices**, **View Own Devices**, and **Control Own Devices**.

At the moment in order to share the device you have 2 options:

* Invite the user to your organization
* Create sub organization, invite the user to the sub organization and transfer the device into it

## Sharing via Own organization

In order to share your device with someone, you just need to invite this user to your organization.

Right now you can select **Admin**, **Staff** or **User** roles during the invitation.
User should have a role with **View Organization Devices** permission in order to see your devices.
Have in mind, that default **User** role doesn't have any permissions. You need to set required permissions for this and other roles.
Otherwise, invited user will see the empty screen without any devices.

You can [transfer the device ownership](actions-with-devices.md#device-transfer) to the user you want to share the device with within your organization \(user should be invited to your organization\). In that case, you can restrict the access of the user to other devices within organization, so user with permission **View Own Devices** will see only devices where he is the owner.

In other words, users that don't have permission **View Organization Devices** can't see other organization devices. They can only see the devices where they are owners and only if they have **View Own Devices** permission. Users with **View Organization Devices** can see all devices within organization they belong to.

This type of sharing is useful when you have only one user to share the device with and you don't want to isolate the device within other organization.

For example, you want to share your garage door with your wife, so you both can view and control the garage doors. At the same time, you have other devices you're playing with, and you don't want your wife to see them \(because one of the devices is drinking machine, so obviously you don't want your wife to be aware of it\). You invite your wife with a role that has **View Own Devices** and **Control Own Devices** permissions, and you transfer the ownership of the garage doors device to the wife. Now you \(as administrator\) can see all devices, and she \(as device owner\) can view and control only the garage doors device.

## Sharing via sub organization

You can create the sub organization, invite multiple users you want to share the device with and transfer the device ownership to one of those users \(you still need to transfer the ownership, as the device transfer could be done only by the user email\). For that type of sharing all users within sub organization should have **View Organization Devices** permission. Otherwise, device will be visible only for the owner of the device. Have in mind, that users from sub organizations never can see any data from the upper organization hierarchy.

This type of sharing is useful when you want to share the device with many users. You still will be able to see this device in the search or via **organization switch**.

For example, now your children grown up, and you want to share your garage door with not only your wife but also with a children. But, you still have your drinking machine \(it was helping you while your children were growing\), so you don't want to share it with your wife and children. The device can have only one owner. You can give **View Organization Devices** permission your to your family. However, in that case your family will see other devices within your organization. So you have to create a new sub organization, invite into it your family with **View Organization Devices** permissions, and now they will be able to view the garage doors. Sub organization has only one device, so your family will see only it. While you still be able to see the devices in own/root organization via the search and in the sub organization via **organization switch**.

