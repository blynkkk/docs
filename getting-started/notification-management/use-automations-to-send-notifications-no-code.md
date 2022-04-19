# Use Automations To Send Notifications (no code)

Let's say you need to send a notification if a sensor logs temperature above 40ºC. The simplest way to do that would be to use Automations.&#x20;

Automations is a powerful Blynk feature that allows you to to set up sequences of actions (scenarios) triggered by a certain event.

In our example, the Automation scenario would look like that:&#x20;

**WHEN** `Temperature value > 40` **DO THIS:** send notification



### Here is how to make it work:

1. Set up Datastream for Automations
2. Create Automation to send notifications

Let's walk you through step-by-step guide on setting up notifications:

## 1. Set up Datastream for Automations

### Expose Datastreams to Automation

First thing you need is to tell Blynk which Datastream can be used for Automations.

1. Go to  Template -> Click Edit->_Datastreams_ tab.
2. Open Datstream Settings by clicking on its name&#x20;
3. Expand **Advanced Settings** option
4. Turn on **Expose to Automation** switch
5. Enable **Available in Conditions** below. This means that values from this Datastream can trigger Automation scenario.



![](../../.gitbook/assets/cpt2105201739-1919x971.gif)

###

### Choose the Type of Automation

Type defines what kind of Action or Trigger is it and how it will be presented for the user when using Automation. For example, if it's a temperature, use `Sensor` type

| Type                  | Description                                                                                                                                                                                                 |      GUI     | Condition | Action | Settings |
| --------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :----------: | :-------: | :----: | :------: |
| **Main Power Switch** | Control that turn device ON/OFF. You can have **only one** Main Power Switch per Product                                                                                                                    |    Switch    |     •     |    •   |     •    |
| **Switch**            | Controls property that has on/off state. **Don't use this property for Main Power Switch**                                                                                                                  |    Switch    |     •     |    •   |     –    |
| **Range Control**     | Controls a property within a set range. Min/Max values are taken from Datastream settings. This parameter also requires a `step` value. Step defines increments between min and max value of the datastream |    Slider    |     •     |    •   |   Step   |
| **Color**             | Controls properties where color can be set. Include Brightness if needed.                                                                                                                                   | Color picker |     •     |    •   |     –    |
| **Sensor**            | Read-only property to use sensor data as a Condition                                                                                                                                                        |     Value    |     •     |        |     –    |





### Make Available in Conditions

Click on Available in Conditions. This will tell Blynk that you would like to use value from this Datastream as a trigger condition.

****

![](../../.gitbook/assets/expose\_to\_auto.gif)

###

### Apply Changes to Template

After you set up the Datastreams you would like to use for Automations, apply changes to template.

Click on _Save_, then _Apply Changes_ to all devices of this Template.&#x20;

![](<../../.gitbook/assets/image (33).png>)







## 2. Create Automation



You can create Automations in both Blynk.Apps and Blynk.Console. In this article we will cover mobile app flow only.

### **Setting up automation in Blynk app**

1. Open Blynk app -> Automations (if you don't see Automations tab - check your Datastream settings)
2. Tap on _Add Automation_ button or on the plus icon in the top right corner
3. Choose **Device State** as a Condition. This means that certain device state will trigger automation
4. Set up the condition itself. For example, when temperature < 40ºC.

![](<../../.gitbook/assets/image (35) (1).png>)

After condition is ready, press **Add action** and choose the type of notification you would like to send:

![Choose action type](https://user-images.githubusercontent.com/72790181/120281347-81f92e80-c2c1-11eb-989d-fb5832653d9f.png)

You can send:

1. **Email** - will send email to specified recipient(s)
2. **Push notification** - will send a push notification (in-app notification) to specified recipients
3. **SMS** - will send an SMS. (This option is available in [White-label](https://www.blynk.io/pricing#business) solution only)

Optionally, you can include placeholders in the message:

* `{ORG_NAME}` - name of the organization device belongs to
* `{PRODUCT_NAME}` - name of the Template belongs to
* `{DEVICE_NAME}` - device name
* `{TRIGGER_VALUE}` - if **Device State** trigger was used, this will be the value of the trigger

For example, if you want to send the push notification when the temperature is higher than 40 degrees, The message constructor will look like this:

_"Temperature of `{DEVICE_NAME}` is too high! Current temperature is `{TRIGGER_VALUE}`ºC"_

Resulted message will be: `Temperature of Living Room Sensor is too high! current temperature is 43.7ºC!`

###

### Limit Period

To avoid sending multiple notifications, you can set limits. Click on the Settings icon

![Limit period (tap on limit period)](https://user-images.githubusercontent.com/72790181/120785065-6e55fe00-c535-11eb-8979-f3eb1b50ecf1.png)

This setting defines a period how many times notification will be sent, not looking at how many triggers happened.

To better understand it, check out the possible timeline for our automation example: "_When temperature is higher than 40, send Email Notification_" with a **limit period** of **1 hour**.

* _9:30_ - Device sends the temperature value of 41º. Automation is triggered and notification is sent to the recipient. Limit period timer starts.
* _9:40_ - Device sends the temperature value of 42º. Notification is **not sent** because 1 hour hasn't passed yet. Limit period timer is now at 10 minutes since the first trigger.
* _10:30_ - Limit period timer resets.
* _10:31_ - Device sends the temperature value of 42º. Notification will be sent again, as one hour has already passed since first occurrence. Limit period timer starts again...

