# Datastreams Common Settings

## BASIC SETTINGS

**NAME** – always give a meaningful name to the Datastream as it's extensively used across the platform. Duplicate names are not allowed.

**ALIAS** – an alternative Datastream name which can be changed by the end-user. For example, it can be used by voice assistants like Amazon Echo \(Alexa\) and Google Home Assistant . You can only use letters, digits and spaces. No other characters are allowed. Duplicate aliases are not allowed.

**COLOR** – Each Datastream can have it's own color. It's handy to differentiate them by type, group or any other attribute. Pick one of 8 preset colors or set any other by [HTML color code](https://html-color-codes.info/).

**DEFAULT VALUE** – Default value is used to specify the value that will be set for the Datastream on the first connection of a Device. It will de displayed until another value is sent by Device, Blynk.App or Blynk.360.

## ADVANCED SETTINGS

**Save raw data \(plan restrictions apply\)** – enabling this setting allows to save unprocessed data from the sensor or source.

**Invalidate** – enabling this setting allows to postpone Default Values appliance for the period of time set in **in** fields \(set value and select **sec/min/hours** time unit\). At the end of this period value set in **then set** is applied \(the options here are: **Nothing, Default, No Data, Empty** or **manual input**\).

**Wait for confirmation from device** – 

**Sync with latest server value every time device connects to the cloud** – enable this option to set higher priority to the values changes made in Blynk.App or Blynk.360 instead of those sent from a Device. Useful for controlling Devices.

**AUTOMATION AND VOICE ASSISTANT**

* **Expose to Automation** – enable this option to allow the Datastream to be used in Automations
* **Expose to Voice Assistants** – enable this option to allow the Datastream to receive Voice Assistants commands.





