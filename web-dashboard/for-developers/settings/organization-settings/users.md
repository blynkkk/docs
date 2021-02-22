---
description: 'Here you can Invite, View, Edit, Transfer and Delete users.'
---

# Users

![Users Table view](../../../../.gitbook/assets/orgset_users.png)

## Invite

Invite button \(top right of the screen\) click opens Invite New User modal window. Fill all mandatory  fields to proceed with user invitation.

* **Name** – Use only letters, hyphens, dots and spaces
* **Email** – Email is required
* **Role** – select from the drop-down list on of the 3 roles available: **Admin, Staff, User** with different [access and permissions](../access.md).
* **Phone Number** \(optional\) – 15 digit international phone format for any country. There's a country code selector which can help in case you're not sure about the exact digits. Also it shows country flag after manual input.
* **Assign to Location** \(optional\) – click + and select from the Locations available

Click modal window Invite button to finish the process. An invitation mail will be sent to user's Email. 

![Invite User Modal window](../../../../.gitbook/assets/invite_user.gif)

## Search

You can search for a specific user by typing the part or the whole Name, Email,  Role or Location.  
The result \(multiple results are possible\) will be given in the Users table. 

## Users table

This table shows the Organization's users information:

* **Name** – user's name and last name \(optional\) that was assigned to User during invitation or sign up
* **Role** – displays one of  3 roles available: **Admin, Staff, User** with different [access and permissions](../access.md).
* **Location** – displays location user was assigned to during invitation or sign up
* **Status** – 3 registration statuses are possible:
  * **pending** – the user is invited, but the email is not confirmed \(user haven't logged in\) 
  * **active** – the user confirmed the email, logged at least one time 
  * **inactive** – the user hasn't logged for 1 month
* **Last login** – last time user logged in. hh:mm M D, Y format \(year is hidden if it's current\)

### Table interaction

All the columns support sorting.

Role and Status columns support additional filtering option.  
Select desired option\(s\) from the menu appears on clicking filter icon and press OK in order to change the table view. Click reset in the same menu if you want to return to default table view.

#### Hover options:

* **Initials** – shows checkboks allowing to select the user for further Bulk Actions
* **Name** – opens Email containing hint. Click on it to copy user's Email address
* **User role** – click opens [Role Permissions list](../access.md) on the right part of the screen  

The only **Bulk Action** available here is to Delete the users. 

1. Select all users by marking **checkbox** in columns naming row or specify users selection by marking each user's checkbox.
2. Once users selection is made **Delete** button appears on the top right of the screen.
3. Don't worry, there's a prompt  "Are You Sure You Want To Delete Selected Users?" with **Cancel** and **Yes, Delete** buttons.
4. Confirm or cancel the action 

**Single Actions** menu is triggered by hovering Actions column in user's row. Available actions:

* **Edit** – edit data that was provided during invitation. Same modal window as for Invite User. Email can't be changed.
* **Change Password** – modal window opens.  "Are you sure want to change user password?" prompt NEW PASSWORD input field.

![Change Password modal window](../../../../.gitbook/assets/change_password_modal.png)

* **Send Device Log** – sends selected user's devices logs to Administrator's Email
* **Force Logout** – logs user out immediately. No confirmations required.
* **Transfer User** – you can transfer this user to another organization. You would need to input an email address of administrator in a Destination Organization Administrator Email field.

![Transfer User modal window](../../../../.gitbook/assets/transfer_user.png)

* **Delete Account** – modal window will appear. Type DELETE and confirm the action are required.

![Delete User modal window](../../../../.gitbook/assets/delete_user_modal.gif)











### 







