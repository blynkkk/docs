# Create a Sub-Organization

The workflow is to log in to Blynk, create the sub-organization(s), assign templates, assign an ‘Admin’ member, transfer or create users, and finally create or transfer devices (assign a user to the device).  Members with the correct roles and permissions can also create and provision devices.

Login to Blynk as a user with a role and permissions that will allow you to create/edit an organization, add/edit templates, edit devices, and transfer users. The ‘Admin’ role with default permissions is sufficient.

From the Blynk.Console sidebar, click on the ‘Organizations’ icon, and then the ‘+ Create New Organization’ button.

<figure><img src="../../.gitbook/assets/add-organization.png" alt=""><figcaption></figcaption></figure>

Under the ‘Info’ tab, assign a ‘NAME’, and optionally a ‘DESCRIPTION’ and logo.  Logo image must be between 500x500px and 4096x2048 pixels.

Click on the ‘Templates’ tab, and then click on one or more templates to be enabled for the sub-organization. Enabling a template will permit devices to be later transferred to designated users in that sub-organization.

<figure><img src="../../.gitbook/assets/add-templates.png" alt=""><figcaption></figcaption></figure>

Click on the ‘Users’ tab to add members who will have access to the devices and data associated with the templates selected.

You can dynamically invite users that currently don’t have a Blynk account and assign them the [roles](https://docs.blynk.io/en/blynk.console/settings/access#roles-and-permissions) of ‘Admin’, ‘Staff’, or ‘User’ on this tab as well. See ‘[How to Assign a Device to a User](https://docs.google.com/document/d/1y\_PpM8KAuvTYCgAaOjuDmh5oL637Vq4Dcuel07LGCkM/edit?pli=1#bookmark=id.je16rq9h3eu)’ for more details.

Existing Blynk members will need to be transferred via [Search -> Users -> All](https://docs.blynk.io/en/blynk.console/users/users-list#users-table) -> Actions -> Transfer User, or [Search -> Organizations](https://docs.blynk.io/en/blynk.console/settings/organization-settings/users#hover-options), [Settings -> ORGANIZATION SETTINGS -> Users](https://docs.blynk.io/en/blynk.console/settings/organization-settings/users#hover-options).

{% hint style="info" %}
Users can only be transferred within the same hierarchy. E.g.: If a user has a Blynk account, that's not within your organization structure, they will have to delete their account prior to being added to your organization or use a different email that hasn't been in use on Blynk.
{% endhint %}

Click the ‘Create’ button when finished. Repeat the process to create any other sub-organizations. &#x20;

Once a sub-organization is created, you may transfer devices to the sub-organization by [assigning a user to a device](https://docs.google.com/document/d/1y\_PpM8KAuvTYCgAaOjuDmh5oL637Vq4Dcuel07LGCkM/edit?pli=1#bookmark=id.je16rq9h3eu).  You may also create new devices and then [assign a user to the device](https://docs.google.com/document/d/1y\_PpM8KAuvTYCgAaOjuDmh5oL637Vq4Dcuel07LGCkM/edit?pli=1#bookmark=id.je16rq9h3eu), or the user may [provision the device](https://docs.blynk.io/en/commercial-use/deploying-products-with-dynamic-authtokens#delivering-products-to-clients-pro-plan-workflow).

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

Learn about existing limitations [here](https://docs.blynk.io/en/blynk.console/limits#organization).
