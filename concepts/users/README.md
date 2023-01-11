---
description: Types of users
---

# Users

Every registered user of Blynk is a member of an organization. This could be a one-person organization, or a company with hundreds of employees.  Every member of an organization has a [role](https://docs.blynk.io/en/blynk.console/settings/access#roles-and-permissions) and is of certain [type](./#types-of-users). Roles control how users access the data according to a [set of permissions](https://docs.blynk.io/en/blynk.console/settings/access).&#x20;

### Limits by Plan

When a user subscribes to a [Blynk plan](https://blynk.io/pricing), they become by default a user of type [Developer](./#developers),  assigned the role of [Admin](./#roles-and-permissions) to the [root organization](../organizations.md). The number of additional users varies by [plan](https://blynk.io/pricing), and so does the ability to revise the [set of permissions](../../blynk.console/settings/access.md) for each [role](https://docs.blynk.io/en/blynk.console/settings/access#roles-and-permissions). &#x20;

Free and Plus plans have a locked set of permissions for each role, meaning the default permissions by role cannot be changed. PRO and Business plans have permissions that may be edited by role.

### **Types of users**

{% hint style="info" %}
Types of users are related to, but different from [Roles and Permission](../../blynk.console/settings/access.md).
{% endhint %}

#### **Developers**

Users of this type have access to all the functionality required to configure the platform for use by end-users (also called Clients). This is usually someone who builds the hardware, develops the firmware, and does all the needed configurations.  By default, the first user in Organization becomes a Developer and is assigned the [role](https://docs.blynk.io/en/blynk.console/settings/access#roles-and-permissions) of Admin.

{% hint style="info" %}
Currently, only one developer is allowed per Organization to avoid sync issues. This limit might be changed later.
{% endhint %}



#### **End-users (Clients)**

These users can add devices and use the platform's functionality based on their role and set of permissions, but they can't edit any configurations made by the Developer.

#### **Partners**

Available in Enterprise version only. These are the members of Partners organization with an additional set of functionality to create and manage clients. Partners could be:

* Distributor&#x20;
* Reseller&#x20;
* Contractor&#x20;
* Installer

As partners functionality is only available in the Business plans the exact set of permissions for these additional user types can be configured according to the client’s needs.

### **Roles and permissions**

{% hint style="info" %}
Access to user management including roles and permissions depends on your [plan](https://blynk.io/pricing).
{% endhint %}

Each user has a **role** in the organization**.** By default there are three main roles.

* **Admin** – is intended to have the highest level of permissions
* **Staff** – we recommend to set up and use this role for internal company functions and client support
* **Users** – is intended to have the most limited set of permissions, mostly focused on managing their own devices

Each role has a set of permissions. Read more about it [here](../../blynk.console/settings/access.md).





