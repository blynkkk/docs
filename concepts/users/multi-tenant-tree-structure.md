---
description: How different types of users can access the data on Blynk platform
---

# Multi-tenancy

In most IoT applications, there is usually a need to access devices and other data by multiple users, also commonly referred to as _tenants_.

A tenant can mean a lot of things, and based on the type of application you are building these can be individual users or organizations. Regardless of the application, however, the main idea is that tenant's assets (devices, users, locations, etc.) should always be protected from unauthorized access.

Blynk platform offers a simple and flexible way to set up and manage multi-tenant IoT applications at any scale.

{% hint style="info" %}
Multi-tenancy functionality can be limited by the plan you are using. [Upgrade](https://blynk.io/pricing) to a higher plan to get complete access to this feature.
{% endhint %}

Every user of Blynk is a member of an Organization. This could be a one-person organization, a family, or a company with hundreds of employees. Additionally, every member of an organization has a role. Role controls how users access the data with a set of permissions. Read more [here](../../blynk.console/settings/access.md).

Organizations can have sub-organizations and also be a part of a larger organization, forming a tree-like structure.

The diagram below shows imaginary companies: **United Heaters Inc.** and **Muller Boilers Group**, which are customers of **WarmPlus Corporation.** Each of these companies can have multiple users and devices.



<img src="../../.gitbook/assets/image (44).png" alt="" data-size="original">



It's important to understand that any user that is above a tenant in a hierarchy will have access to child tenant’s devices as well. Such an approach allows complex hierarchies to be created. For example, United Heaters could have distributors and contractors underneath them who in turn can have their own customers.

You can assign users to any level in the hierarchy and they will have access to their own devices and any device beneath them.

