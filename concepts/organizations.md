---
description: How multi-tenant tree-like organizational structure works
---

# Organizations

Every user of Blynk is a member of an Organization. This could be a one-person organization, a family, or a company with hundreds of employees.

{% hint style="warning" %}
Creating a multi-level organizational structure is a feature available for **PRO or higher-paid** plans.&#x20;

The **FREE and PLUS** plans support multiple users, and the assignment of roles to those users ([see plan limits](https://blynk.io/pricing)).
{% endhint %}

### Introduction

Organizations enable you to categorize your devices and users, assigning them roles, permissions, and locations. The structure is a tree-like hierarchy, where a user assigned to an organization has permission to all sub-organizations beneath it (with `View Sub Organizations` permission granted), and the assigned devices and data. This multi-tenancy functionality allows you to easily scale your project, and customize it to your particular needs. The maximum depth of organizations is four (could be increased for business clients by request), as shown in the example image below.

<figure><img src="../.gitbook/assets/organizations-levels.png" alt=""><figcaption><p>Maximum organization depth</p></figcaption></figure>

The first Blynk account created for an organization becomes the root organization. It is defined under ‘Settings - ORGANIZATION SETTINGS’.  If you invite users by email that doesn't have a Blynk account, they will invited to that root organization. You cannot invite users that already have a Blynk account.

Every Organization consists of:

* Users with assigned roles and permissions
* Templates
* Devices
* Locations
* Sub-organizations
* Automations
* Tags

#### Users

Every user of Blynk is a member of an organization. This could be a one-person organization, a family, or a company with hundreds of employees. Every member of an organization has a role. Roles control how users access the data with a [set of permissions](../blynk.console/settings/access.md).

#### Devices

Every device has at least one user assigned as the owner to it via [device transfer](../blynk.console/organizations/browse-and-edit-a-sub-organization.md#how-to-move-a-device-to-a-sub-organization).  Multiple users may view a device (see [device sharing](../blynk.console/devices/device-sharing.md)).

#### Locations

[Locations](../blynk.console/locations/) allow you to tag devices with named location details (address and latitude/longitude).  Use sub-organizations to group users and devices, and to control access/permissions for users,  device configuration, and data.

#### Sub-organizations

Sub-organizations can be of four [types](../blynk.console/settings/organization-settings/general.md) that are available only for Business users. For the PRO plan the sub-organization type is assigned automatically and defaults to 'client'.

### Planning Your Organization

The full management and configuration are more easily accomplished using the Blynk.Console.  Blynk.App does allow you to add / invite new users and devices to the root and sub-organizations, edit many of the organization settings, and browse the sub-organizations (with required permission granted).

You need to be logged into Blynk as a user with a role and set of permissions that will allow you to create/edit organizations, templates, users, etc. A user has access only to the organization he is assigned to. Access to the sub-organizations is possible only when the user has a specific permission `Switch to Sub Organizations`. The root organization user with ‘Admin’ role and default permissions are sufficient:

![Sub organization permissions](../.gitbook/assets/screenshot-blynk-qa.com-2023.01.04-19\_52\_35.png)

Sketch out your current root organization including templates, devices, and users. Then lay out the sub-organization and include the templates, at least one user with ‘Admin’ role, one device, and the user who will be assigned as the device owner (it can be the admin of the sub-organization or any other user assigned to the sub-organization).

<figure><img src="../.gitbook/assets/organizations-diagram (1).png" alt=""><figcaption><p>Multi-level organizational structure</p></figcaption></figure>

In the example above in the Muller Boiler Group organization **user R** has access to the Thermostat of **user W** and vice versa, **user W** has access not only to their own Thermostat but also to the Boiler owned by **R**.&#x20;

For the users to have access to their own devices only, create a structure like United Heaters Inc. on the image, where a sub-organization is created for each user, so **M** only has access to Pool Heater, while **H** can only see data from their Thermostat and manage this device only.

**User A** from the parent organization has access to all devices in the sub-organizations within their hierarchy.

Decide on roles for the users (‘Admin’, ‘Staff’, ‘User’), and what [permissions](../blynk.console/settings/access.md) you want to configure for each role. Review this by accessing ‘Settings -> Roles and permissions’ from the sidebar.

{% hint style="info" %}
Keep in mind that by default, members assigned the ‘Staff’ role will be able to see and manage devices.&#x20;

And by default, members assigned the ‘User’ role with default permissions cannot see or manage devices, even those devices transferred to them.&#x20;

The organization permission ‘View devices’ under ‘Owned Devices’ must be enabled for the ‘User’ role by the organization ‘Admin’ user (or other with appropriate permissions). This is the same for other device permissions such as provision, edit, control, etc, and those under the roles and permissions group ‘Organization Devices’.
{% endhint %}

Every sub-organization should have at least one member assigned the role ‘Admin’.  The only way to assign a user with the ‘Admin’ role to a sub-organization is to invite someone who is not currently assigned a Blynk account.  Invite the user to join the sub-organization and assign them the role of ‘Admin’.

After the sub-organization ‘Admin’ member has been assigned, other Blynk members may be transferred by providing the email for the sub-organization ‘Admin’ or invited by providing their email address. The transfer is possible only within the same hierarchy of organizations.

{% hint style="success" %}
Although you can define what devices users may see and manage through roles and permissions, it is easier to manage that for multiple users by assigning those users and devices to a sub-organization.  \


1. Create a sub-organization
2. Assign an administrator, [invite](../blynk.console/organizations/browse-and-edit-a-sub-organization.md#invite-users-to-a-sub-organization) or [transfer](../blynk.console/organizations/browse-and-edit-a-sub-organization.md#how-to-transfer-a-user-to-another-organization) the user to that sub-organization
3. Create the device or [transfer](../blynk.console/organizations/browse-and-edit-a-sub-organization.md#how-to-move-a-device-to-a-sub-organization) it to the user. &#x20;



It is important to assign an appropriate role to the user that gives them permission to view and/or manage the devices assigned to the organization (by default, ‘User’ role is insufficient, but ‘Staff’ is). &#x20;

Note that device templates may not be viewed or edited by users in the sub-organization unless you [assign a template to the sub-organization](../blynk.console/organizations/browse-and-edit-a-sub-organization.md#add-templates-to-a-sub-organization).
{% endhint %}

{% content-ref url="../blynk.console/organizations/create-a-sub-organization.md" %}
[create-a-sub-organization.md](../blynk.console/organizations/create-a-sub-organization.md)
{% endcontent-ref %}

{% content-ref url="../blynk.console/organizations/browse-and-edit-a-sub-organization.md" %}
[browse-and-edit-a-sub-organization.md](../blynk.console/organizations/browse-and-edit-a-sub-organization.md)
{% endcontent-ref %}

Learn about existing limitations [here](../blynk.console/limits.md#organization-limits).
