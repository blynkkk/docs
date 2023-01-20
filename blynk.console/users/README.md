---
description: Here you can Invite, View, Edit, Transfer and Delete users.
---

# Users



<figure><img src="../../.gitbook/assets/users-table 2.png" alt=""><figcaption></figcaption></figure>

## Users list

This table shows the Organization's users information:

* **Name** – user's name and last name (optional) that was assigned to User during invitation or sign up
* **Role** – displays one of  3 roles available: **Admin, Staff, User** with different [access and permissions](../settings/access.md).
* **Location** – displays location user was assigned to during invitation or sign up
* **Status** – 3 registration statuses are possible:
  * **pending** – the user is invited, but the email is not confirmed (user haven't logged in)&#x20;
  * **active** – the user confirmed the email, logged at least one time&#x20;
  * **inactive** – the user hasn't logged for 1 month
* **Last login** – last time user logged in hh:mm M D, Y format (year is hidden if it's current)
*   **Actions-**displays a menu of actions that can be applied to this User: Edit,&#x20;

    Change Password, Send Device Log, Force Logout, Transfer User, Delete Account.

### Table interaction

Click on the user's name to get to the [User Profile](user-view.md) and detailed information about a specific user.

All columns support sorting.

Role and Status columns support additional filtering option (multiple choice).\
On clicking filter icon select desired option(s) from the drop-down menu and press OK in order to change the table view. Click reset in the same menu if you want to return to default table view.

#### Hover options:

* **Initials** – shows check bocks allowing to select the user for further Bulk Actions
* **Name** – opens Email containing hint. Click on it to copy user's Email address
* **User role** – click opens [Role Permissions list](../settings/access.md) on the right part of the screen&#x20;

### Bulk actions on users

The  **Bulk Action** available here is to Apply Tag, Export Users (CSV) and Delete the users.&#x20;

#### **Apply Tag**

1. Select all users by marking **checkbox** in columns naming row or specify users selection by marking each user's checkbox.
2. Once users selection is made **Apply Tag** button appears on the top right of the screen.
3. In the modal window that appears, select **a Tag** from **the List of Tags.**
4. Confirm or cancel the action.

#### Export Users (CSV)

1. Select all users by marking **checkbox** in columns naming row or specify users selection by marking each user's checkbox.
2. Once users selection is made **Export Users (CSV)** button appears on the top right of the screen.
3. File is ready. You can download it now.
4. Confirm or cancel the action.

#### Delete the users

1. Select all users by marking **checkbox** in columns naming row or specify users selection by marking each user's checkbox.
2. Once users selection is made **Delete** button appears on the top right of the screen.
3. Don't worry, there's a prompt  "Are You Sure You Want To Delete Selected Users?" with **Cancel** and **Yes, Delete** buttons.
4. Confirm or cancel the action

### Single actions on users

**Single Actions** menu is triggered by hovering Actions column in user's row. Available actions:

* **Edit** – edit data that was provided during invitation. Same modal window as for Invite User. Email can't be changed.
* **Change Password** – modal window opens.  "Are you sure want to change user password?" prompt NEW PASSWORD input field.

![Change Password modal window](../../.gitbook/assets/change\_password\_modal.png)

* **Send Device Log** – sends selected user's devices logs to Administrator's Email
* **Force Logout** – logs user out immediately. No confirmations required.
* **Transfer User** – you can transfer this user to another organization. You would need to input an email address of administrator in a Destination Organization Administrator Email field.

![Transfer User modal window](../../.gitbook/assets/transfer\_user.png)

* **Delete Account** – modal window will appear. Type DELETE and confirm the action are required.

![Delete User modal window](../../.gitbook/assets/delete\_user\_modal.gif)

## Invite New User

You can invite users that don’t currently have a Blynk account and assign them the [roles](../settings/access.md) of ‘Admin’, ‘Staff’, or ‘User’. Go to Search -> Users and click the 'Invite New User' button.

<img src="../../.gitbook/assets/image (19).png" alt="" data-size="original">

Fill out the short form to invite the user to current organization.

**User name** – fill in this field with First and Last names of the user you want to invite.

**Email Address** – be sure to input correct Email. The invitation letter with the link to create a password will be sent to it.

**Role** – select user's role in this Organization. _Admin, Staff_ and _User_ roles are available from the dropdown menu.

Click **Invite** once all is done here. The invitation letter will be sent to user's Email and user account will appear in the current organization user list as Pending until they create their password and log in at least once.

If you need to add a user to a specific organization, [switch to that organization](../organizations/browse-and-edit-a-sub-organization.md#switching-to-a-sub-organization) first. Then use the same procedure as above or invite the user to current organization and then [transfer](../organizations/browse-and-edit-a-sub-organization.md#how-to-transfer-a-user-to-another-organization) them as needed.

Existing Blynk members will need to be [transferred](./#how-to-transfer-a-user-to-another-organization).
