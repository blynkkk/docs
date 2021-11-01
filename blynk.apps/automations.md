---
description: Automations let you automate
---

# Automations

Automations is a powerful feature that allows end-users to set up their own sequences of actions that starts when a certain **trigger **happens. Automations can be set up to work between device. A trigger fired on one device, can cause another devices to perform actions. 

Automation examples:

* If temperature sensor  shows temperature above 40 degrees, turn the Boiler OFF
* Every Tuesday at 8pm turn the Garden Lights Off

{% hint style="danger" %}
Automations should be properly configured[ in Template settings](../blynk.console/templates/datastreams/datastreams-common-settings/automation.md). Otherwise, Automation tab will be unavailable in Blynk.Apps
{% endhint %}

Automations are created per organization and available only for the users who has permissions. In order to enable automation permissions.

{% hint style="info" %}
Automations feature is a replacement for some of the Blynk 1.0 (Legacy) widgets like: Timer, Bridge, and Eventor.
{% endhint %}



### Triggers

Automations can be based on these triggers:

* **Time of Day** - a specific time of the day and for day of week will trigger the automation
* **Sunset / Sunrise** - (also called astronomical timer). Based on the location of device, Blynk will calculate the sun position time and use it as a trigger. Current sunset algorithm doesn't take into account the altitude of the selected region which makes this calculation less precise for the mountainous regions.
* **Device state** -  certain value of defined datastream will trigger the automation. For example, if temperature > 40 degrees, turn the boiler off
* **Scene** - manual activation of automation scenario

One trigger, can be used to start actions on multipe devices. 



### Actions

Actions define what should happen upon trigger. You have these options: 

1. **Set a device to...** - this action allows you to set a datastream of device to a specified state. For example, turn something on/off, set datastream to a value
2. **Wait** - allows you to delay the next action in the list or conntinue the execution at specified time
3. **Send Email** - will send email to specified recipient(s)
4. **Send notification** - will send a push notification (in-app notification) to specified recipients 
5. **Send SMS** - will send an SMS. This is only available in [White-label](https://www.blynk.io/pricing#business) solution

Notifications can contain placeholders. Check details below.

### ****

### **Setting up automations**

Automations are created per organization and only available for users with permission for it. To enable automation permissions:

* Go to the **Settings** -> **Roles and Permissions**
* Find **Organizations **section and enable **Create/Edit/View/Delete Automations** permissions for the required role
* The availability of **Scene** trigger is controlled in: Settings - > Roles and Permissions - > Organizations -> **Automation execute **row

![No automations](https://user-images.githubusercontent.com/72790181/120281222-57a77100-c2c1-11eb-82fc-5d872520671f.png)

Tap **Add automation** to create a new one or use plus icon in the upper right corner.

![Choose condition](https://user-images.githubusercontent.com/72790181/120281228-5b3af800-c2c1-11eb-8e54-267b8aed6e79.png)

1. Fill in Automation name
2. Choose cover picture
3. Set a condition that will trigger an automation

![No actions](https://user-images.githubusercontent.com/72790181/120281259-64c46000-c2c1-11eb-9b25-84c4e9e294b7.png)

After setting the condition you can **Add action** that will be performed when the condition is triggered

![Choose action type](https://user-images.githubusercontent.com/72790181/120281347-81f92e80-c2c1-11eb-989d-fb5832653d9f.png)

After pressing **Add action** button you’ll see a modal with types of actions.

{% hint style="info" %}
If you don't see **Set device to..** action, check that you properly configured datastreams in device template. You need to[ explicitly define](../blynk.console/templates/datastreams/datastreams-common-settings/automation.md) which datastreams are exposed to Automations.
{% endhint %}

![Automation ready](https://user-images.githubusercontent.com/72790181/120281482-ad7c1900-c2c1-11eb-95a7-7352d126ba73.png)

After adding the first action you can continue adding more of them or save this automation

![Automations tab](https://user-images.githubusercontent.com/72790181/120281496-b1a83680-c2c1-11eb-8f99-04188d31fce7.png)

When Automations are created you can manually disable/enable them and edit

## Notification actions

You can send these types of notifications:

1. **Send Email** - will send email to specified recipient(s)
2. **Send notification** - will send a push notification (in-app notification) to specified recipients
3. **Send SMS** - will send an SMS. This is only available in [White-label](https://www.blynk.io/pricing#business) solution

You can include placeholders in the message:

* `{ORG_NAME} ` - name of the organization device belongs to
* `{PRODUCT_NAME}` - name of the Template belongs to
* `{DEVICE_NAME} `- device name
* `{TRIGGER_VALUE} `- if "Device State" trigger was used, this will be the value of the trigger

For example, if you want to send the push notification when the temperature is higher than 40 degrees, The message constructor will look like this: 

Temperature of `{DEVICE_NAME}` is too high, current value is `{TRIGGER_VALUE}`ºC!

Resulted message will be: `Temperature of Living Room Sensor is too high, current value is 43ºC!`

## Limit period

![Limit period (tap on limit period)](https://user-images.githubusercontent.com/72790181/120785065-6e55fe00-c535-11eb-8979-f3eb1b50ecf1.png)

Automations with **Device state** trigger have a **limit period **setting. It defines a period during which only one action will be performed, no matter how many triggers were recorded.

For example, if you sett **limit period **to one hour for such automation:  _"When temperature is higher than 20º, send Email Notification". _Let's look at possible timeline:

* _9:30_ - Device sends the temperature value of 21º. Automation is triggered and notification was sent to the recipient. Limit period timer started
* _9:40_ - Device sends the temperature value of 22º. Notification is not sent because 1 hour hasn't  passed yet. Limit period timer is now at 10 minutes since the first trigger
* _10:30_ - Limit period timer resets
* _10:31_ - Device sends the temperature value of 22º. Notificaiton will be sent again, as one hour has already passed since first occurrence

