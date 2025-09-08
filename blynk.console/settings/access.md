---
description: Access and permissions management for different user roles
---

# Roles and Permissions

### Plans

* With a **Free plan** you can only use the default roles with their fixed permissions.
* With a **PRO plan** you can edit permissions for the default roles.
* With an **Enterprise plan** you get full control with **Custom Roles:** create, rename, and delete roles.

***

### Default Roles

Blynk has 3 default roles that can have different sets of permissions:

* **Admin** – is intended to have the highest level of permissions
* **Staff** – we recommend to set up and use this role for internal company functions and client support
* **Users** – is intended to have the most limited set of permissions, mostly focused on managing their own devices

***

### Custom Roles (Enterprise only)

With Custom Roles, organizations can build their own role structure beyond the defaults. With this feature, you can add, rename, or remove roles while keeping role management consistent across your organization hierarchy.

#### Capabilities

* **Create new roles**\
  Only Blynk team can create custom roles, by client request. You can have up to **9 roles**.
* **Rename roles**\
  Change role names anytime. The system applies renames across the entire organization hierarchy.
* **Delete roles**
  * To delete a role select a replacement role before deletion.
  * If the deleted role has users, the system transfers them to the replacement role.
  * You cannot delete the **Admin role** to ensure at least one role always exists.
* **Organization-wide consistency**\
  You can set role permissions for each organization separately. But role structure always applies to the whole organization hierarchy.
* **Roles Across the App**\
  Custom Roles appear everywhere you manage roles in Blynk: device dashboard tab permissions, dashboard permissions, mobile pages permissions, etc.

## Editing Roles and Permissions

![](../../.gitbook/assets/Roles_and_Perms.gif)

Blynk has 3 default roles that can have different sets of permissions:

* **Admin** – is intended to have the highest level of permissions
* **Staff** – we recommend to set up and use this role for internal company functions and client support
* **Users** – is intended to have the most limited set of permissions, mostly focused on managing their own devices

### Actions

* **Collapse/Expand all** in Actions block – applies eponymous actions to expandable permissions list
* **+ / -** buttons – click to expand/collapse specific permission sections
* **Enable/Disable** switches – use the switches to grant/prohibit certain access level and permissions to specific users types. Note that some permissions are dependent on other permissions

### The Full List of Permissions

#### Permissions Control

* View roles and permissions
* Create new roles
* Edit roles
* Delete roles

#### Users

* View users
* Invite new users
* Edit users
* Delete users
* Change user passwords
* Force Logout
* View user actions log
* Transfer users
* Download users list
* Suspend users

#### Devices

> Own Devices

* View devices (currently it's under "Provision new devices")
* Delete device data
* Download reports
* View timeline

> Organization Devices

* View devices (currently it's under "Add new devices from web")
* Add new devices from using web app
* Delete data from devices
* Download reports
* Access service tab

> Auth Tokens

* Edit auth tokens

> Transfers

* Transfer devices

#### Blynk.Air: Firmware Over-The-Air Updates

* Get access
* Create new firmware shipments
* Stop/pause shipments

#### Templates

* View templates (currently it's under "Add new template")

#### Organizations

* Access organization settings
* Switch to sub-organizations
* Transfer organizations

> Owned Locations

* View locations
* Create new locations
* Edit locations
* Delete locations
* Assign users to locations

> Organization's Locations

* View locations
* Create new locations
* Edit locations
* Delete locations
* Assign users to locations

> Automations

* View automations
* Create automations
* Edit automations
* Delete automations
* Execute automations

> Developer API

* View OAuth token settings
* Create OAuth tokens
* Edit OAuth tokens
* Delete OAuth tokens

> **Analytics**

* View analytics

> **Rule Engine (under development)**

* View rule groups
* Create rule groups
* Edit rule groups
* Delete rule groups
