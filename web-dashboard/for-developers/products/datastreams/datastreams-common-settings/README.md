# Datastreams Common Settings

## BASIC SETTINGS

**NAME** – always give a meaningful name to the Datastream as it's extensively used across the platform. Duplicate names are not allowed.

**ALIAS** – an alternative Datastream name which can be changed by the end-user. For example, it can be used by voice assistants like Amazon Echo \(Alexa\) and Google Home Assistant . You can only use letters, digits and spaces. No other characters are allowed. Duplicate aliases are not allowed.

**COLOR** – Each Datastream can have it's own color. It's handy to differentiate them by type, group or any other attribute. Pick one of 8 preset colors or set any other by [HTML color code](https://html-color-codes.info/).

**DEFAULT VALUE** – Default value is used to specify the value that will be set for the Datastream on the first connection of a Device. It will de displayed until another value is sent by Device, Blynk.App or Blynk.360.

## ADVANCED SETTINGS

**Save raw data \(plan restrictions apply\)** – enabling this setting allows to save unprocessed data from the sensor or source. By default server stores only 1 data point per data stream per minute. In case you sent more than 1 point within 1 minute interval - value for that data stream will be averaged.

Raw data allows you to store every value that hardware sends.

**Invalidate** – some Datastreams have meaningful value only when it is fresh \(updated recently\). For such Datastreams you can setup the invalidation period and invalidate the value according to the selected policy.   
  
For example, you made an thermometer and interested in the current temperature outside the window. Thermometer wakes up hourly and sends the current temperature to the display widget on the web or mobile. Let's assume you made a setup with the 2 hours invalidation period and selected `No Data` policy.  
  
Due to any malfunction your device could stop sending the updates. Without the invalidation period you will always see the latest value on the screen. However, with invalidation period after 2 hours since the last update - value will be invalidated with `No Data` label. So end users will not be confused with the "freezed latest value".

Currently you can select one of the following invalidation policies:

* **Nothing** - widget will be empty and will show nothing
* **Default** - widget will be filled with the default value of the data stream if it is present
* **No Data** - text `No Data` will be showed
* **Empty** - text `Empty` will be showed
* **--** - text `--` will be showed

**Wait for confirmation from device** – for some critical actions it is very important to know that hardware actually received the command and applied the received value from the user input.

For such use cases Data Stream has confirmation property. It allows you to setup the interval during which user can wait for the response from the device, while the widget used to send the value will be disabled.

For example, let's assume you have a garage door and which you can open by sending the `1` value via the button that is assigned to the Virtual Data Stream on `V1` and you have set the `Wait for confirmation` period for 5 seconds.

When you click on the button - it sends `1` value to the hardware. In case hardware is online and accepts the value - it can send back the applied value \(telling us that door was successfully opened\). If hardware wasn't online or haven't send any confirmation sue to error or non acceptable value - data stream value will be reverted to the previous value.

Here is a simplest code example that shows how you can make it work:

```text
BLYNK_WRITE(V1)
{   
  int value = param.asInt();
  if (value == 1) {
     if (openDoor()) {
       Blynk.virtualWrite(V1, "1"); // confirm the value, ui will enable the button
     } else {
       Blynk.virtualWrite(V1, "0"); // you can send back any other value, 
                                    // saying that change was unsuccessful
                                    // ui will enable the button
     }
  }
}
```

**Sync with latest server value every time device connects to the cloud** – enable this option to set higher priority to the values changes made in Blynk.App or Blynk.360 instead of those sent from a Device. Useful for controlling Devices.

**AUTOMATION AND VOICE ASSISTANT**

* **Expose to Automation** – enable this option to allow the Datastream to be used in Automations
* **Expose to Voice Assistants** – enable this option to allow the Datastream to receive Voice Assistants commands.





