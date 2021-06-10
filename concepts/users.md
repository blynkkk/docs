---
description: Types of users
---

# Users

Every registered user on Blynk is **always** a member of an Organization, even if it's just a single-person organization. Such structure enables [multi-tenancy](multi-tenant-tree-structure.md). Within the organization there can be different types of users:

## **Types of users**

{% hint style="info" %}
Types of users are related to, but different from [Roles and Permission](../blynk.console/settings/access.md).
{% endhint %}

### **Developers**

Users of this type have access to all the functionality required to configure the platform for use by end-users \(also called Clients\). This is usually someone who builds the hardware, develops the firmware, and does all the needed configurations.

By default, the _\*\*_first user in Organization becomes a Developer

{% hint style="info" %}
Currently, only one developer is allowed per Organization to avoid sync issues. This limit might be changed later.
{% endhint %}



### **End-users \(also Clients\)**

These users can add devices and use the platform's functionality based on their role and set of permissions, but they can't edit any configurations made by the Developer.

### **Partners**

Available in Enterprise version only. These are the members of Partners organization with an _\*\*_additional set of functionality to create and manage clients. Partners could be:

* Distributor 
* Reseller 
* Contractor 
* Installer

## **Roles and permissions**

{% hint style="info" %}
Access to user management including roles and permissions depends on your [plan](https://blynk.io/pricing%20).
{% endhint %}

Each user has a **role** in the organization**.** By default there are three main roles.

* Admin
* Staff
* User

Each role has a set of permissions. Read more about it here

