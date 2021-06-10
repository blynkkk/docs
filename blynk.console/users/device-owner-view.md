# Device Owner View

Here you can view detailed information about Device Owner.

![](../../.gitbook/assets/user-action-menu.png)

The User profile contains information about the user **Name**, user **Organization**, user **Country**, information about the user **Status, Role, Email, Last login, Tags** and there may also be other custom information.‌

**Single Actions** menu is triggered by hovering Actions column in user's row. Available actions:‌

* **Edit** – edit data that was provided during invitation. Same modal window as for Invite User. Email can't be changed.
* **Change Password** – modal window opens. "Are you sure want to change user password?" prompt NEW PASSWORD input field.

​![](https://gblobscdn.gitbook.com/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MT6hiS0aI36GBjRsTba%2F-MT7-J3EfB8vlkdqR5OW%2FChange_Password_modal.PNG?alt=media&token=b92c2f4b-fe91-427c-95d3-736d7464cc82)‌

* **Send Device Log** – sends selected user's devices logs to Administrator's Email
* **Force Logout** – logs user out immediately. No confirmations required.
* **Transfer User** – you can transfer this user to another organization. You would need to input an email address of administrator in a Destination Organization Administrator Email field.

​![](https://gblobscdn.gitbook.com/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MT6hiS0aI36GBjRsTba%2F-MT6zkeGOEe_spfFZUPp%2Ftransfer_user.PNG?alt=media&token=e8915d86-f0c6-4151-9f13-a5b6ad2c12f3)‌

* **Delete Account** – modal window will appear. Type DELETE and confirm the action are required.

​![](https://gblobscdn.gitbook.com/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MT6hiS0aI36GBjRsTba%2F-MT6zIe4imh5mVGVucwl%2FDelete_user_modal.gif?alt=media&token=8842b895-d023-4f5e-9cb9-efa65eaeee5b)

​‌

## Information Tab <a id="information-tab"></a>

The Information tab contains information about:‌

* **Status** – 3 registration statuses are possible:

  * **pending** – the user is invited, but the email is not confirmed \(user haven't logged in\)
  * **active** – the user confirmed the email, logged at least one time
  * **inactive** – the user hasn't logged for 1 month

  ​

* **Email**
* **Nickname**
* **Phone Number** \(optional\) – 15 digit international phone format for any country.
* **Role** – 3 roles available: **Admin, Staff, User** with different [access and permissions](https://app.gitbook.com/@blynk-iot/s/en/blynk.console/settings/access).
* **Client Custom fields-** may contain additional information about the user required for work.
* **Timezone-** user location timezone.

‌

## Actions Log Tab <a id="actions-log-tab"></a>

​![](https://gblobscdn.gitbook.com/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MUS_7EQcoNCzQbrQiOz%2F-MUS_gWYhC5mzbJCq72d%2Fuser%20action%20log.png?alt=media&token=80d3c559-3d40-4f85-9716-b5dbb84063e9)‌

On the Action logs tab, the user can select a time interval to view the actions for this period:

​‌

The table contains information about:‌

* **Time** – Date and time of the Action
* **Organization Name**
* **Client** – \_\*\*\_Android, iOS, Web, HTTPS API, Automation, Alexa, Google Home, Other
* **Action Name**
* **Action Code**

​‌

## Devices Tab <a id="devices-tab"></a>

​![](https://gblobscdn.gitbook.com/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MUSamqSCHLYr7U5Z7QF%2F-MUSdpSqfjHB2TAIShly%2Fuser%20devices.png?alt=media&token=ea22b899-56c1-46c5-8122-777ba2286a8d)‌

The Devices tab contains information about all user devices‌

* **Name** – Name of Device
* **Status –** Online or Offline
* **Model-** Model of Device
* **Last Updated-**Date and time of the last update

