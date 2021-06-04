---
description: Automations let you set an automated control of your devices
---

# Automations
{% hint style="info" %}
Automations are replacement for old Blynk TimeInput, Timer, Bridge and Eventor widgets
{% endhint %}
{% hint style="warning" %}
Automations should be [enabled in Template settings](../web-dashboard/products/datastreams/datastreams-common-settings/automation.md) first. Otherwise Automation tab will be unavailable in Blynk.App
{% endhint %}

![No automations](https://user-images.githubusercontent.com/72790181/120281222-57a77100-c2c1-11eb-82fc-5d872520671f.png)

Tap **Add automation** to create a new one

![Choose condition](https://user-images.githubusercontent.com/72790181/120281228-5b3af800-c2c1-11eb-8e54-267b8aed6e79.png)

If you don't see "Device state" condition that means you haven't enabled any datastream to work with automations.
You need [to explicitly define](../web-dashboard/products/datastreams/datastreams-common-settings/automation.md) what datastreams will work as conditions.

Blynk currently supports 4 types of automations:

* **Time of Day** - allows you to trigger at a specific time of the day and for the specific day.
* **Sunset / Sunrise** - allows you to trigger at sunset/sunrise.

  This kind of automation is triggered based on the selected location.

  For the different locations you'll get the different sunset/sunrise time.

  Also, current sunset algorithm doesn't take into account the altitude of the selected region.

  So the sunset/sunrise time calculation may be not precise for the mountain regions.

* **Device state** - allows you to trigger based on the device datastream values. For example, if temperature &gt; 40 degrees turn of the boiler
* **Scene** - allows to manually trigger multiple actions. For example, set the temperature to 30 degrees and turn off the alarm.

  The visibility of this type of the automation is controlled via permissions.

{% hint style="info" %}
Automations can work across multiple devices
{% endhint %}

- Create an Automation name
- Choose cover picture
- Set a condition that will trigger an automation

![No actions](https://user-images.githubusercontent.com/72790181/120281259-64c46000-c2c1-11eb-9b25-84c4e9e294b7.png)

After setting the condition you can **Add actions** that will be performed when the condition is triggered

![Choose action type](https://user-images.githubusercontent.com/72790181/120281347-81f92e80-c2c1-11eb-989d-fb5832653d9f.png)

After pressing Add action button you’ll see a modal with types of actions.
You can choose actions that will change the device’s state, send a notification to your smartphone or send an email to the specified address.

If you don't see "Set device to" action that means you haven't enabled any datastream to work with automations.
You need [to explicitly define](../web-dashboard/products/datastreams/datastreams-common-settings/automation.md) what datastreams can work as actions.

![Automation ready](https://user-images.githubusercontent.com/72790181/120281482-ad7c1900-c2c1-11eb-95a7-7352d126ba73.png)

After adding the first action you can continue adding more of them or save this automation

![Automations tab](https://user-images.githubusercontent.com/72790181/120281496-b1a83680-c2c1-11eb-8f99-04188d31fce7.png)

When Automations are created you will see the list of them. Here you can disable/enable automations and open their settings for view and edit.

