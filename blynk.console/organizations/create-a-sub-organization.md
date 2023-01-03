# Create a Sub-Organization

Login to Blynk as a user with a role and permissions that will allow you to create/edit an organization, add/edit templates, edit devices, and transfer users. The ‘Admin’ role with default permissions is sufficient.

* As an ‘Admin’ of the parent or root organization create the sub-organization
* Enable any device templates that will be available to the sub-organization
* Invite a new user who does not have a Blynk account to be the role of ‘Admin’ for the sub-organization
* Transfer or invite other users to the sub-organization. Be sure give them appropriate roles or permissions to view and/or manage devices (by default, the ‘Staff’ role is sufficient)
* Create devices or transfer them to the sub-organization users. Members with the correct roles and permissions can also create and provision devices.

From the Blynk.Console sidebar, click on the ‘Organizations’ icon, and then the ‘+ Create New Organization’ button.

<figure><img src="../../.gitbook/assets/add-organization.png" alt=""><figcaption></figcaption></figure>

Under the ‘Info’ tab, assign a ‘NAME’, and optionally a ‘DESCRIPTION’ and logo.  Logo image must be between 500x500px and 4096x2048 pixels.

Click on the ‘Templates’ tab, and then click on one or more templates to be enabled for the sub-organization. Enabling a template will permit devices to be later transferred to designated users in that sub-organization.

<figure><img src="../../.gitbook/assets/add-templates.png" alt=""><figcaption></figcaption></figure>

Click on the ‘Users’ tab to add members who will have access to the devices and data associated with the templates selected.

You can dynamically invite users that currently don’t have a Blynk account and assign them the [roles](../settings/access.md) of ‘Admin’, ‘Staff’, or ‘User’ on this tab as well.

Existing Blynk members will need to be [transferred](browse-and-edit-a-sub-organization.md#how-to-transfer-a-user-to-another-organization) via Search -> Users -> All -> Actions -> Transfer User (in this case as an admin of the root organization you will see all users within your hierarchy), or Settings -> ORGANIZATION SETTINGS -> Users (in this case you will see the users assigned to the current sub-organization you are viewing, so make sure to switch to the org you need first).

{% hint style="info" %}
Users can only be transferred within the same hierarchy. E.g.: If a user has a Blynk account, that's not within your organization structure, they will have to delete their account prior to being added to your organization or use a different email that hasn't been in use on Blynk.
{% endhint %}

Click the ‘Create’ button when finished. Repeat the process to create any other sub-organizations. &#x20;

Once a sub-organization is created, you may transfer devices to the sub-organization by [assigning a user to a device](browse-and-edit-a-sub-organization.md#how-to-assign-a-device-to-a-user).  You may also create new devices and then assign a user to the device, or the user may [provision the device](../../getting-started/activating-devices/blynk-edgent-wifi-provisioning.md).

### Creating a multi-level organizational structure

There are two key ways to create a tree-like multi-level structure.

* from the root-level organization
* from the parent organization

#### Creating a third-level organization from the root-org

The flow is to [create all the organizations](create-a-sub-organization.md#creating-a-sub-organization) you need as sub-organizations of the root org using the 'New Organization' button and after that assign the child sub-organizations to their parent sub-organizations according to your planned structure.

To assign a child sub-organization to a parent sub-organization log in as an admin of the root organization, go to Search -> ORGANIZATIONS -> My organizations -> Actions and select 'Transfer Organization' from the drop-down menu. You will be taken to a dialog where you can type in the name of a parent sub-organization or select it from the list to assign the child sub-organization to it. You will be able to review the new hierarchy before confirming the transfer.

{% hint style="warning" %}
When transferring organization, you will move all the assets, including devices, users, sub organizations (and their assets) under another organization in the hierarchy.
{% endhint %}

{% hint style="info" %}
The transfer is a critical action that can affect how users access devices and their data. It can be reversed by transferring the sub-organization back.
{% endhint %}

#### Creating a third-level organization from the parent-org

The admin of the parent sub-organization creates a sub-organization of the deeper level using the common [sub-org creation flow](create-a-sub-organization.md#creating-a-sub-organization).

{% hint style="info" %}
As a root-org admin you can create sub-organizations under the organizations in your hierarchy if you [switch to the organization](create-a-sub-organization.md#creating-a-sub-organization) that is planned to be the parent one. Then you can act as the admin if this organization and [create a sub-organization](create-a-sub-organization.md#creating-a-sub-organization) as usual.
{% endhint %}

Learn about existing limitations [here](../limits.md#organization-limits).
