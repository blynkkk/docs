# Forward Device Data

It is possible to create an automation that will forward a datastream triggered value to one or more other devices. Works with datastreams of data type integer, double, and string.

1. Create a **master** datastream for a device template that will have the triggered value.
2. Create one or more **slave** datastreams within any device template.
3. Create an automation and choose the condition type of ‘Device State’. Assign the master device and the datastream.
4. Configure the **action** as ‘Forward Device Data’ and specify the slave device and datastream.
5. Under ‘Settings’, configure an appropriate ‘LIMIT PERIOD’.
6. Click the ‘Save’ button to save the automation.

Note that Forward Device Data is not limited to devices within the device template of the forwarding device (master). You can forward device data to any device in any template.

Two methods exist to forward device data to more than one device:

* Any device monitoring the datastream that is the target of the action ‘Forward Device Data’ will receive the update via a BLYNK\_WRITE().&#x20;
* Multiple actions may be defined for an automation, with each action configured as ‘Forward Device Data’ targeting a different device and datastream.&#x20;

{% hint style="info" %}
IMPORTANT: The automation setting ‘LIMIT PERIOD’ will limit how often the automation will forward a datastream triggered value.
{% endhint %}