---
description: How multi-tenant tree-like organizational structure works
---

# Organizations

Every user of Blynk is a member of an Organization. This could be a one-person organization, a family, or a company with hundreds of employees.

{% hint style="warning" %}
Creating an multi-level organizational structure is a feature available for **PRO or higher** paid plans.&#x20;

The **FREE and PLUS** plans support multiple users, and assignment of roles to those users (see plan limits).
{% endhint %}

### Introduction

Organizations enable you to categorize your devices and users, assigning them roles, permissions, and locations. The structure is a tree-like hierarchy, where a user assigned to an organization has permission to all sub-organizations beneath it, and the assigned devices and data. This multi-tenancy functionality allows you to easily scale your project, and customize it to your particular needs. The maximum depth of organizations is four, as shown in the example image below.

<figure><img src="../.gitbook/assets/organizations-levels.png" alt=""><figcaption></figcaption></figure>

The first Blynk account created for an organization becomes the root organization. It is defined under ‘Settings - ORGANIZATION SETTINGS’.  If you invite users by email that do not have a Blynk account, they will inherit that root organization.  You cannot invite users that already have a Blynk account.

Every Organization consists of:

* Users  with assigned roles and permissions
* Templates
* Devices
* Locations
* Sub-organizations

#### Users

Every user of Blynk is a member of an organization. This could be a one-person organization, a family, or a company with hundreds of employees.  Every member of an organization has a role. Roles control how users access the data with a set of permissions.

#### Templates

A template must be [enabled](https://docs.google.com/document/d/1y\_PpM8KAuvTYCgAaOjuDmh5oL637Vq4Dcuel07LGCkM/edit?pli=1#bookmark=kix.6fjbrnh26jrt) for the sub-organization in order for devices associated with it to be transferred to a user.  Templates are created by the root organization. &#x20;

#### Devices

Every device has at least one user assigned as the owner to it via [device transfer](https://docs.blynk.io/en/blynk.console/devices/actions-with-devices#device-transfer).  [Multiple users](https://docs.blynk.io/en/blynk.console/devices/device-sharing#sharing-via-sub-organization) may view a device (see [device sharing](https://docs.blynk.io/en/blynk.console/devices/device-sharing)). &#x20;

#### Locations

[Locations](https://docs.blynk.io/en/blynk.console/locations/locations) allow you to tag devices with a named location details (address and latitude/longitude).  Use sub-organizations to group users and devices, and to control access/permissions for users,  device configuration, and data. &#x20;

#### Sub-organizations

Sub-organizations can be of four [types ](https://docs.blynk.io/en/blynk.console/settings/organization-settings/general)that are available only for Business users. For the PRO plan the sub-organization type is assigned automatically and defaults to 'client'.

### Planning Your Organization

The full management and configuration is more easily accomplished using the Blynk.Console.  Blynk.App does allow you to add / invite new users and devices to the root and sub-organizations, edit many of the organization settings, and to browse the sub-organizations.

You need to be logged into Blynk as a user with a role and set of permissions that will allow you to create/edit organizations, templates, users, etc.  The organization you are assigned to as a user has access only to that organization, and any sub-organizations.  The root organization user with ‘Admin’ role and default permissions is sufficient.

Sketch out your current root organization including templates, devices, and users.  Then lay out the sub-organization and include the templates, at least one user with ‘Admin’ role, one device, and the user who will be assigned as the device owner.

<figure><img src="../.gitbook/assets/organizations-diagram (1).png" alt=""><figcaption><p>Multi-level organizational structure</p></figcaption></figure>

In the example above in Muller Boiler Group organization user R has access to the Thermostat of the user W and vice versa, user W has access not only to their own Thermostat but also to the Boiler owned by R.&#x20;

For the users to have access only to their own devices, create a structure like United Heaters Inc. on the image, where a sub-organization is created for each user, so M only has access to Pool Heater, while H can only see data from their Thermostat and manage this device only.

User A from the parent organization has access to all devices in the sub-organizations within their hierarchy.

Decide on roles for the users (‘Admin’, ‘Staff’, ‘User’), and what permissions you want to configure for each role.  Review this by accessing ‘Settings -> Roles and permissions’ from the sidebar.

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
2. [assign an administrator](https://docs.google.com/document/d/1y\_PpM8KAuvTYCgAaOjuDmh5oL637Vq4Dcuel07LGCkM/edit?pli=1#bookmark=id.7fj59ora61c5), [invite](https://docs.google.com/document/d/1y\_PpM8KAuvTYCgAaOjuDmh5oL637Vq4Dcuel07LGCkM/edit?pli=1#bookmark=kix.x92xrbhclhr6) or [transfer](https://docs.google.com/document/d/1y\_PpM8KAuvTYCgAaOjuDmh5oL637Vq4Dcuel07LGCkM/edit?pli=1#bookmark=kix.x92xrbhclhr6) the user to that sub-organization
3. Create the device or transfer it to the user. &#x20;



It is important to assign an appropriate role to the user that gives them permission to view and/or manage the devices assigned to the organization (by default, ‘User’ role is insufficient, but ‘Staff’ is). &#x20;

Note that device templates may not be viewed or edited by users in the sub-organization unless you [assign a template to the sub-organization](https://docs.google.com/document/d/1y\_PpM8KAuvTYCgAaOjuDmh5oL637Vq4Dcuel07LGCkM/edit?pli=1#bookmark=kix.6fjbrnh26jrt).
{% endhint %}

{% content-ref url="../blynk.console/organizations/create-a-sub-organization.md" %}
[create-a-sub-organization.md](../blynk.console/organizations/create-a-sub-organization.md)
{% endcontent-ref %}



Read more about how to work with organizations [here](https://github.com/blynkkk/docs/tree/2dc305739ee5d42b5fd9d7af9c9d6c057276a5fe/blynk.console/organizations/README.md).

Learn about existing limitations [here](https://docs.blynk.io/en/blynk.console/limits#organization).
