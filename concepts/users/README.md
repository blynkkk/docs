# Users

Blynk allows you to share devices with other users - from a few to thousands and offers a simple and flexible way to set up and manage multi-tenant IoT applications at any scale. Users can be grouped in [organizations](../organizations.md). Every member of an organization has a [role](./#manage-roles-and-permissions) and is of certain [type](./#types-of-users). Roles control how users access the data according to a [set of permissions](../../blynk.console/settings/access.md).&#x20;

### Limits by Plan

When a user subscribes to a [Blynk plan](https://blynk.io/pricing), they become by default a user of type [Developer](./#developers),  assigned the role of [Admin](./#roles-and-permissions) to the [root organization](../organizations.md). The number of additional users varies by [plan](https://blynk.io/pricing), and so does the ability to revise the [set of permissions](../../blynk.console/settings/access.md) for each role. &#x20;

Free and Plus plans have a locked set of permissions for each role, meaning the default permissions by role cannot be changed. PRO and Business plans have permissions that may be edited by role.



## User management

Blynk takes care of all key use cases required for user management: inviting users, account registration, password changes, assigning roles and devices, managing permissions, account deletion.

#### Add user&#x20;

There are multiple ways of adding users to Blynk and they differ by plan.

It is possible for all plans to invite a user to your organization and assign them a selected [role](./#manage-roles-and-permissions) either [from Blynk.Console](../../blynk.console/users/#invite-new-user) or Blynk.App (Main Menu -> Organization settings -> Members -> Invite new member icon in the top right corner).

{% hint style="warning" %}
it is only possible to invite users if they don't have a Blynk account associated with this email. In other cases they should either delete their account before being invited or use some other email.
{% endhint %}

**PRO, Plus, Free plans:** In order to give other users access to your devices, you will need to first invite each user to your organization (or to a sub-organization under yours if you are on PRO). The user will get an invitation sent to their email address and, will be asked to create a password for their Blynk account and then will be able to activate their device with Blynk. Here you can find more information about how to deploy your [WiFi](../../commercial-use/deploying-products-with-dynamic-authtokens.md#delivering-products-to-clients-pro-plan-workflow) and [non-WiFi products](../../commercial-use/deploying-products-with-static-authtokens.md#pro-plan-workflow) to customers using Blynk PRO.

**Business plan:** This plan eliminates the need to invite each user via email and allows [self-registration](../../commercial-use/business-plan-white-label-assets/application-settings/sign-up.md). The user can simply purchase your device, follow the instructions to create an account in your Blynk-powered app / web portal and activate their device. Blynk is working on making it possible for **PRO clients** as well with an add-on.

#### Assign a device to a user

If your clients activate their devices themselves with [WiFi provisioning](../../commercial-use/deploying-products-with-dynamic-authtokens.md) or a [Static token](../../commercial-use/deploying-products-with-static-authtokens.md), the device is assigned to the user automatically.

If you are not using provisioning and already have both the user and the device in your account you can [transfer device ownership](../../blynk.console/devices/actions-with-devices.md#device-transfer) to that user for them to be able to view and control it.

#### Change password

It is possible for any user to reset their password in their User profile either [in Blynk.Console](../../blynk.console/user-profile.md#reset-password) or in [Blynk.App](../../blynk.apps/profile-management/my-profile.md). Organization admin can also [reset password for any user](../../blynk.console/users/#single-actions-on-users) within their organization.

#### Delete user

Organization admin can [delete any user's account](../../blynk.console/users/#single-actions-on-users) within their organization.



### **Types of users**

{% hint style="info" %}
Types of users are related to, but different from [Roles and Permission](../../blynk.console/settings/access.md).
{% endhint %}

#### **Developers**

Users of this type have access to all the functionality required to configure the platform for use by end-users (also called Clients). This is usually someone who builds the hardware, develops the firmware, and does all the needed configurations.  By default, the first user in Organization becomes a Developer and is assigned the [role](https://docs.blynk.io/en/blynk.console/settings/access#roles-and-permissions) of Admin.

{% hint style="info" %}
Currently, only one developer is allowed per Organization to avoid sync issues. This limit might be changed later.
{% endhint %}

If you want some other user to be a developer in your organization you should first switch off the [dev mode](../../getting-started/developer-mode.md) in your account either in Blynk.Console or Blynk.App. After that the other user can switch it on.

#### **End-users (Clients)**

These users can add devices and use the platform's functionality based on their role and set of permissions, but they can't edit any configurations made by the Developer.

#### **Partners**

Available in Enterprise version only. These are the members of Partners organization with an additional set of functionality to create and manage clients. Partners could be:

* Distributor&#x20;
* Reseller&#x20;
* Contractor&#x20;
* Installer

As partners functionality is only available in the Business plans the exact set of permissions for these additional user types can be configured according to the client’s needs.



### **Manage roles and permissions**

{% hint style="info" %}
Access to user management including roles and permissions depends on your [plan](https://blynk.io/pricing).
{% endhint %}

Each user has a **role** in the organization**.** By default there are three main roles.

* **Admin** – is intended to have the highest level of permissions
* **Staff** – we recommend to set up and use this role for internal company functions and client support
* **Users** – is intended to have the most limited set of permissions, mostly focused on managing their own devices

Each role has a set of permissions. With Free and Plus plans you can change permissions for a specific user by changing their role. PRO and Business plans allow editing permissions by role. Read more about it [here](../../blynk.console/settings/access.md).



### Group users into organizations

To simplify access management to devices PRO and Business plan users can group their clients and devices into multi-level [organizations](../organizations.md).
