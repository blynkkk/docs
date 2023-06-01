# Marketing

## Blynk Marketing Add-On

Marketing add-on unlocks the two powerful features: in-app click tracking and in-app messaging.&#x20;

{% hint style="info" %}
The add-on is available to Business plan subscribers only. Contact your launch engineer to unlock and set up.
{% endhint %}

### In-App Tracking

The feature gives you better understanding of how customers are using your products and the app. Blynk apps are tracking click/tap events and send results to Firebase.&#x20;

_Typical use case: track how often customers use a certain feature or track most common user journeys._

{% hint style="success" %}
All collected data is anonymized. There is no way to track actions of a particular user.
{% endhint %}

In Firebase you can build custom reports, or ask Blynk team to set them up for you.

**To enable in-app tracking and set up the add-on contact your launch engineer.**&#x20;

There are two types of events: events tracked by default and events related to your device dashboard (widgets).

Here is what can be tracked:

#### Default Mobile App Events

<table><thead><tr><th width="230.66666666666663">Event name</th><th width="187">Description</th><th width="213">Examples</th><th width="261">Additional Parameters</th><th width="285">Specifics</th></tr></thead><tbody><tr><td><code>bl_device_add</code></td><td>User starts device adding procedure</td><td>- tap "Add New Device" from right-side panel<br>- tap "Add New Device" from main screen when there are no devices</td><td>bl_selection=wifi|qr</td><td></td></tr><tr><td><code>bl_device_added</code></td><td>Device adding process successfully completed</td><td></td><td><p>bl_template_id</p><p>bl_template_name</p></td><td></td></tr><tr><td><code>bl_view_devicedash</code></td><td>User views device dashboard</td><td>- tap "Device" tab item on the bottom when there is seingle device<br>- tap on device tile on the "Devices" screen<br>- launch the app with a single device</td><td>bl_template_id bl_template_name</td><td></td></tr><tr><td><code>bl_view_deviceinfo</code></td><td>User views the device info screen</td><td>1. open device info screen by tapping "3 dots" icon on top right on device dashboard  header<br>2. select "Information" tab on top of the Device Info screen</td><td>bl_template_id bl_template_name</td><td></td></tr><tr><td><code>bl_view_timeline</code></td><td>User views the device timeline screen</td><td><p>1. open device info screen by tapping "3 dots" icon on top right on device dashboard  header</p><p>2. select "Timeline" tab item on top of the Device Info screen</p></td><td>bl_template_id bl_template_name</td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td></tr><tr><td><code>bl_tap_deviceactions</code></td><td>User open device action menu</td><td><p>1. open device info screen by tapping "3 dots" icon on top right on device dashboard  header</p><p>2. tap "3 dots" icon in the  Device Info header</p></td><td></td><td></td></tr><tr><td><code>bl_tap_devicereconfig</code></td><td>User selects "Reconfigure" from device action menu</td><td><p>1. open device info screen by tapping "3 dots" icon on top right on device dashboard  header</p><p>2. select "Timeline" tab item on top of the Device Info screen<br>3. tap Reconfigure</p></td><td>bl_template_id bl_template_name</td><td></td></tr><tr><td><code>bl_tap_deviceerasedata</code></td><td>User selects "Erase all device data" from device action menu</td><td></td><td>bl_template_id bl_template_name bl_device_erase_data_type</td><td></td></tr><tr><td><code>bl_tap_devicedelete</code></td><td>User selects "Delete device" from device action menu</td><td></td><td>bl_template_id bl_template_name</td><td></td></tr><tr><td><code>bl_tap_devicenotifications</code></td><td>User selects "Notifications settings" from device action menu</td><td></td><td>bl_template_id bl_template_name</td><td>Android only (Android 8 and later)</td></tr><tr><td></td><td></td><td></td><td></td><td></td></tr><tr><td><code>bl_view_devicelist</code></td><td>User views Device list (tiles)</td><td>- tap "Devices" tab item on the bottom bar of main screen when there are multiple on zero devices<br>- launch the app with multiple or zero devices</td><td></td><td></td></tr><tr><td><code>bl_view_automations</code></td><td>User views Automations section</td><td>- tap "Automation" tab item on the bottom bar of main screen</td><td></td><td></td></tr><tr><td><code>bl_view_notifications</code></td><td>User views Notification section</td><td>- tap "Notifications" tab item on the bottom bar of main screen</td><td></td><td></td></tr><tr><td><code>bl_view_clients</code></td><td>User views Clients section (requires Partners Add-On)</td><td>- tap "Clients" tab item on the bottom bar of main screen</td><td></td><td>Available only on servers with Partner Sign Up available</td></tr><tr><td><code>bl_view_grouplist</code></td><td>User views Groups section</td><td>- tap "Groups" tab item on the bottom bar of main screen</td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td></tr><tr><td><code>bl_tap_newautomation</code></td><td>User started creating new automation</td><td>- tap "Create Automation" from right menu or from Automations screen when there are no automations</td><td><p>bl_automation_tmpl_rule_type or </p><p>bl_automation_tmpl_id bl_automation_tmpl_name</p></td><td></td></tr><tr><td><code>bl_automationcreated</code></td><td>Automation added successfully</td><td></td><td><p>bl_automation_tmpl_rule_type or </p><p>bl_automation_tmpl_id bl_automation_tmpl_name</p></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td></tr><tr><td><code>bl_view_orgprofile</code></td><td>User views organization profile</td><td>- open Organization Settings screen from left menu<br>- tap "Information" tab item on tabs from Organization Settings screen</td><td></td><td></td></tr><tr><td><code>bl_view_orgmembers</code></td><td>User views organization members list</td><td>- tap "Members" tab item on tabs from Organization Settings screen</td><td></td><td></td></tr><tr><td><code>bl_view_orgcontractor</code></td><td>User views organization contractor page (requires Parner add-on)</td><td>- tap "Contractor" tab item on tabs of Organization settings screen</td><td></td><td>Available only on servers with Partner Sign Up available</td></tr><tr><td><code>bl_view_addmember</code></td><td>User views "Invite New Member" screen</td><td>- tap "Add Member" icon on topbar right from Organization Settings screen</td><td></td><td></td></tr><tr><td><code>bl_memberadded</code></td><td>New member invitation successfully sent</td><td></td><td></td><td></td></tr><tr><td><code>bl_tap_orgchange</code></td><td>Users taps on "Change organization" option on Organization profile screen</td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td></tr><tr><td><code>bl_view_usersettings</code></td><td>User views app Settings</td><td>- tap "Settings" from left menu</td><td></td><td></td></tr><tr><td><code>bl_tap_mutenotifications</code></td><td>User changes "Mute all notifications" setting</td><td></td><td>bl_selection</td><td></td></tr><tr><td><code>bl_tap_notificationsoffline</code></td><td>User changes "Notify when device goes offline" setting</td><td></td><td>bl_selection</td><td></td></tr><tr><td><code>bl_tap_keepscreenon</code></td><td>User changes "Keep screen always ON" setting</td><td></td><td>bl_selection</td><td></td></tr><tr><td><code>bl_tap_biometricauth</code></td><td>User changes "Biometric authentication" setting (Androdi Only</td><td></td><td>bl_selection</td><td></td></tr><tr><td><code>bl_tap_notificationschannel</code></td><td>User selects to view specific notification channel settings (Android only)</td><td>- tap Devices, Automations, Other, Critical channel settings</td><td>bl_selection=DEVICES|AUTOMATIONS|GENERAL</td><td>Android only</td></tr><tr><td><code>bl_tap_themestyle</code></td><td>User changes theme style: Dark, Light, Follow System</td><td></td><td>bl_selection=dark|light|follow_system</td><td>Android only for now</td></tr><tr><td><code>bl_tap_thememode</code></td><td>User changes theme mode: App, Material (Android only)</td><td></td><td>bl_selection=app|material</td><td>Android only for now</td></tr><tr><td></td><td></td><td></td><td></td><td></td></tr><tr><td><code>bl_app_review_request</code></td><td>Users views review request for App Store</td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td></tr><tr><td><code>bl_provisioning_error</code></td><td>App shows previous provisioning try error, returned by the hardware during provisioning</td><td>If there is an error during device provisioning, on next attempt app will try to report the error code</td><td>bl_ssid bl_error bl_template_id bl_firmware_version bl_firmware_type</td><td>Android only for now</td></tr></tbody></table>

### **Blynk In-App Messaging**

This feature allows you to reach users with a promotion / informational message when they are inside of your app, or drive them back into your app using a push notification.&#x20;

This is helpful when you are trying to promote new products or features, convert users to additional paid services or simply educate them on how to best use your product.

Using Blynk.Console you will be able to:

* set up one-time or recurring campaigns&#x20;
* start them immediately or schedule for a specific start time&#x20;
* track the results - impressions, open rate, clicks and actions

Blynk in-app messaging allows sending **push notifications**, **in-app messages** or combine them in one campaign.



