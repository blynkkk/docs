# Automations

### Introduction

An [automation](automations.md) performs one or more actions based on a condition.

The types of **conditions** that may be defined are: Schedule, Sunrise/Sunset, Device State, and Scene. The **Schedule** condition allows you to trigger an event based on the current date/time reaching a particular set of date/time values (all relative to a specified time zone). A **Sunrise/Sunset** condition triggers an event when the time before/after sunrise/sunset occurs relative to a set of defined week days, at a specific geographic location. The **Device State** triggers an action based on the value of a [Datastream](../blynk.console/templates/datastreams/). The **Scene** option allows you to manually trigger an automation event from the [Blynk.App](broken-reference) mobile app or the [Blynk.Console](broken-reference) web app.

One or more actions may be executed sequentially when a condition's requirement has been met. The types of actions include a mobile app notification, an email, a delay, and setting a [Datastream](../blynk.console/templates/datastreams/) value. Actions may be triggered by multiple devices.

Note that the value of a Datastream may be used by a condition, and an action can be configured to set a Datastream to a new value. Using widgets on the Blynk.Console and/or Blynk.App, you can visualize and change the values of Datastreams. You may also access Datastreams within the firmware of an IoT device, and by using the Blynk.Cloud HTTPS API.

### Preparing Template & Datastreams

[Automations](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.njlxi3d5cr93) are created per [Organization](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.xggge7nz5d52) and are only available for users with permission for it. By default, the first user in the [Organization](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.xggge7nz5d52) becomes a [Developer](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.k7jmufoofukc) and has sufficient permissions to create an [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.njlxi3d5cr93).

Enable automation permissions for other roles by visiting the [Blynk.Console](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.hry24cwv591c), click on the 'Settings' option on the main menu, access the 'Roles and permissions' menu option, expand the 'Organizations' section and find the 'Automations' permissions. Set the role's create/edit/view/delete/execute/manage permissions as appropriate for the role.

![](https://lh4.googleusercontent.com/xojjAJydkpnR5BokM2dPAp8txz4iiUPcsVdOSYtJt8c0Ml8G40gN4haxRWPlFeMZOfWheFE-SHF5HGdadS2\_jDd9pVXi56\_8fudweCu5rjjZbaC8KkcrcK2xZokz9oXFHumOMAntQn0Zz2cOMQ)

The Developer Mode must be turned on in order to edit the Automations options for a [Template](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.kftiwj4nonzj).  The Developer Mode can be turned on from the [Blynk.Console](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.hry24cwv591c) or the [Blynk.App](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.amxwygon3fmj).

The ‘Automations’ icon in both the [Blynk.App](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.amxwygon3fmj) and the [Blynk.Console](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.hry24cwv591c) will not be visible until at least one [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) listed in the [Template](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.kftiwj4nonzj) under the ‘Automations’ tab has a condition or action option turned on. Even if none of your existing [Datastreams](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) will be involved in any [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.n0xggfd5ieg), you can simply enable the ‘Condition’ or ‘Action’ switch for any [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) (no harm will be done), or create a [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) if none exist. Otherwise, build your first [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.n0xggfd5ieg) based on the [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) that will be used as either the ‘Condition’ or ‘Action’ for the [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.n0xggfd5ieg).

From the [Blynk.Console](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.hry24cwv591c), click on the main menu icon for 'Templates'. Choose a [Template](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.kftiwj4nonzj) from the list that appears. At the top, choose the 'Automations' tab. A list of [Datastreams](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) for the [Template](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.kftiwj4nonzj) will appear, with columns labeled 'Condition' and 'Action' that each have an enable/disable switch for each [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t). At the top right of the screen, click the 'Edit' button.

![](https://lh4.googleusercontent.com/vf-aA9Q8Ni7nevWNpVnrN5g5o-D0LL7D0hkKJAg8GRxE8xfpH5mI10sH8baDiTHQ7-KYbPLtvpzhEC-IHVBJmHGyyR\_nmjiciwvQc5L7soAxXkXWrPgrg5fH6DZXg1EOk8ceqIlUmDKdi4JcTw)

In the table column labeled ‘Type of Automation’, make a choice for the [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) to be associated with your [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.n0xggfd5ieg).  The choices vary by the [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) data type (double, integer, string, enumerable).  All options except for ‘Sensor’ define what type of GUI control will be presented to the User when defining the [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.n0xggfd5ieg) in the [Blynk.App](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.amxwygon3fmj).

#### Template Automation Options

| Type of Automation | Data Type                                                  | Description                                                                                                    | Blynk.App Automation GUI Control |
| ------------------ | ---------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------- | -------------------------------- |
| Power Switch       | Integer                                                    | Typically 0 = on, 1 = off Max 1 Power Switch per product                                                       | Switch                           |
| Switch             | Integer                                                    | Typically 0 = on, 1 = off                                                                                      | Switch                           |
| Range Control      | Integer                                                    | The min/max is defined by the Datastream. The slider step value is defined in the ‘Type of Automation’ column. | Slider                           |
| Color              | String                                                     | Color value and Alpha (transparency)                                                                           | Color Slider                     |
| Enumerable         | Enumerable                                                 | An integer value corresponds to a string value                                                                 | a list of the enumeration values |
| Sensor             | <p>Double </p><p>Integer</p><p>String</p><p>Enumerable</p> | Cannot be an action                                                                                            | N/A                              |

If the value of the [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) will be used to trigger an action, then enable the ‘Condition’ switch in the table.  If the value of the [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) is to be changed by the [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.n0xggfd5ieg), then enable the ‘Action’ switch in the table.

Enable at least one 'Condition' or 'Action' for a [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) and then click the 'Save And Apply' button at the top right of the screen. Refresh the browser window (CTRL-F5), and the 'Automations' icon will be visible in the [Blynk.Console](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.hry24cwv591c) main menu. Restart the [Blynk.App](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.amxwygon3fmj), and the 'Automations' icon will be visible at the bottom of the screen in between the 'Devices' and 'Notifications' icons.

You may create an [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.njlxi3d5cr93) scenario in either the [Blynk.Console](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.hry24cwv591c), or the [Blynk.App](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.amxwygon3fmj). Creating an [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.njlxi3d5cr93) in one app will cause it to be accessible in the other app (you may need to refresh the other app).

### Create an Automation

From the [Blynk.Console](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.hry24cwv591c), click on the 'Automations' icon on the main menu.  From the [Blynk.App](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.amxwygon3fmj), click on the ‘Automations’ icon at the bottom of the home screen.

Choose a condition from the options of:

* Schedule allows you to trigger an action based on the current date/time reaching a particular set of date/time values (all relative to a specified time zone).
* Sunrise/Sunset triggers an action when the time before/after sunrise/sunset occurs according to a set of week days, at a specific geographic location.
* Device State triggers an action based on the value of a Datastream.
* Scene is a manual trigger of an Automation directly from the 'Automations' page in the Blynk.Cloud or Blynk.App.

After you have the 'When' condition defined, the next step is to configure one or more 'Do this' actions. The action choices are:

* Control Device - select a specific Device to control by setting a Datastream value.
* Send Email will send an email to one or more Users with optional details about the Organization, Template name, Device name, and/or Datastream value included (availability of each depends on the Datastream data type and type of automation).
* Send In-App Notifications to one or more Users' Blynk.App with optional details about the Organization, Template name, Device name, and/or Datastream value included (availability of each depends on the Datastream data type and type of automation).
* Wait, Then Do Something - delay until a specific time of the day is reached (in a specified timezone), or until a timer between 1 sec and 24 hours elapses.
* Send SMS will send a text message to one or more Users's Blynk.App with optional details about the Organization, Template name, Device name, and/or Datastream value included (availability of each depends on the Datastream data type and type of automation). This option is available only to BUSINESS subscribers.

The ‘Send Email’, ‘Send In-App Notifications’, and ‘Send SMS’ actions support the use of placeholders. Placeholders are key/value pairs that refer to Blynk account metadata and DataStream values.

* {ORG\_NAME} - name of the organization the device is assigned to.&#x20;
* {PRODUCT\_NAME} - name of the Template used.&#x20;
* {DEVICE\_NAME} - the IoT Device name as displayed under ‘DEVICES’.
* {TRIGGER\_VALUE} - if a Device State trigger was used, this will be the value of the trigger.

The 'Name' and 'Cover' should also be configured for the new automation. If the Automation has a Device State condition defined, then an option of 'LIMIT PERIOD' is available and should be configured. The limit period prevents multiple executions of an Automation within the limit period duration, beginning from when the last trigger occurred.

{% hint style="info" %}
Limit Period Example

For the Automation scenario of: “When temperature is higher than 40, send Email Notification" with a limit period of 1 hour”, if the temperature rises and exceeds 40 at 9:30 am, then no additional notifications will be sent until 1 hour later at 10:30 am. At 10:30 am, the limit period resets, permitting another notification to be sent at 11:30 am if the temperature continues to exceed 40.
{% endhint %}

### Automation Management

After the Automation is configured, it will appear in the 'Automations' list as a card, with the count of actions defined, and the last date/time that the Automation was executed. A switch on the card allows the Automation to be enabled/disabled.

If the condition of type 'Scene' was chosen, a 'Execute automation' button will also be available within the rectangle, otherwise a 'Disable automation' button will be available.

The images that follow, show how the Automation card appears in both the Blynk.Console and the Blynk.App. Recall that creating an Automation in one app (Blynk.Console or Blynk.App) will cause it to be accessible in the other app.

![](https://lh4.googleusercontent.com/uJ7Udloy71j6EfNDj6Kb2TFnEjDpJuI7dXzQ2oRENgAxiQ-ZcTZNRgCggwqx4Xr4NOzNc7WJrZt7fmGqRefNeBi\_1C7t0zNBpFtQ6PdJfLqdBmdyK1QG2FgD4OhPR2TlZa0dJqpE5VhMGf7zbg)![](https://lh4.googleusercontent.com/xavgv1SGUbFNLkmBTfu-X4ncgbcdwet50\_UW0tsi4ymnnsUOjkcuJ0Rk8JtgnaFA04kDcOLlmxVGDUp7WjCyeFY\_v5b3O6tDajaucvBdLFRoB6oC\_3BTSZc7oXDARQs1tLrl-k3I-mBY6KCdnA)

Within the Blynk.App, you can see Automations the device is participating in. From the Device page, select the ‘...’ icon in the upper right of the screen. Choose the ‘Information’ tab, and the Automations the device is participating in will be listed under the ‘AUTOMATIONS’ section.

![](https://lh3.googleusercontent.com/L3ohpOLyjhs\_\_HwuSdHzrrv9L5vt4p1kFq8-4remvKtUNyLog7zFZK1JloSbVBRKRl3Z8RYm4TgBBeC3YzZGYhQ81YH-CAYrmuFNmTPkF\_Y3KJzqLwcsxoaHAYMOZCrx70ceWvMdVT5bGBbuaA)

If you click on the ‘AUTOMATIONS’ section, you may enable/disable the participation of the Device in Automations.

![](https://lh5.googleusercontent.com/ymLGrVCQr62bScdKk5E5IRqxgrhcWJI4H63b8QGqI2H5Q3xFu344jC9JA\_TIqlBd1OgBCMphNGY5xRMc51knLrSGD3115Kqh30HgIFJ2ShDuMLjmtaRAs6qHfWJd39VQsnX8lzwKv-q2NcsKIg)

### Automations Logs

In the [Blynk.Console](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.hry24cwv591c), you may also view the Automation Logs while editing an [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.n0xggfd5ieg).  This option is not available in the [Blynk.App](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.amxwygon3fmj).

![](https://lh5.googleusercontent.com/5626PQoO5gYsmKuu6hXSFK\_qDJS4tPWOyxdmWB5dZEsV2Mn6s4knXqpUJ4Vuuwwp\_cfXFZxWl5BMrsGw0SQjwfKKFw5vT864iKsIEmzUhaDxeKeT3jH4KR1-AFKLVdQ9-p2WlY1WihkoxBpePA)

Selecting the ‘Automation Logs’ icon will display a page with a history of the executions of the [Automation](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.n0xggfd5ieg).  The summary includes the date/time when it was executed, from what [Device](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.p39oifjipyk4), the [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t) employed, and the value of the [Datastream](https://docs.google.com/document/d/1Ov\_hYFmcVgPfRA\_8SMv1raMtXEykAQ\_I9Uo1GwYDOM8/edit#bookmark=id.4beq33tc010t).

![](https://lh5.googleusercontent.com/kjXex\_900CfRg1nOxtaDRselm3v8gEVwXxu6lWjd\_ZcaU2yyuzVFipwLaG5Cq45p05beK8WxkSRQOg6vXny\_rchv0eaOjjmHLzn-8NmwY29gC1ufv-B08iXvqRkYtG5eM6w2S6kEQGQPk5-W0A)

