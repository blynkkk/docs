# New Shipping

## Shipping name

Each shipping should have a unique name.

1. Click the **Keyboard pictogram** near the default shipping name (top left screen area)
2. Type a new name (40 characters limit)
3. Click **Save pictogram**

<div align="left">

<img src="../../../.gitbook/assets/shipping name.gif" alt="">

</div>



## Target selection

![Target selection area](../../../.gitbook/assets/Air\_target\_selection.PNG)

**Template** – select a Template available in your Organization from the dropdown menu

**Preferred time** – select the best option for the firmware update time period:

* **Any** – (default option) devices will be updated as soon as they connect to the server.&#x20;
* **Night** – 12AM-6AM
* **Morning** – 6AM-12AM
* **Afternoon** – 12AM-6PM
* **Evening** – 6PM-12AM

The preferred time is calculated for every device based on the next logic:

1. If the device has a `Location metafield` and has an assigned location within metafield - the timezone for the preferred time is taken from the assigned location for that device. The timezone of the location is resolved when the location is created;
2. If the device has a `Timezone metafield` and it is set - the timezone is taken from it;
3. If the above is not true - the timezone is taken from the device organization;



**Apply Update if the Device has** – firmware comparison conditions checks:

* **Lower firmware version** – (default option) a semantic version is parsed from the binary file and compared against the device's firmware version.&#x20;
* **Earlier build date, Another build date** – the build date of the binary file is parsed from the firmware info and compared against the stored one in the device information.
* **Lower generic version** – Blynk.Edgent library version is compared.



**Devices Selection Table** – 2 options available here:&#x20;

* **Select devices** available if you want to update certain devices by marking their checkboxes.
* **leave the selections empty** and all of the selected Product's/Template's devices will be updated including those that will be added in the future.&#x20;

There are sorting (all columns) and filtering (Firmware Version column only) options available to make Device search easier:

![Sort, filter, select demo](../../../.gitbook/assets/Air\_Devices\_selection.gif)

## **Firmware info**

When the binary file is uploaded, the extracted information is shown in this section. It is useful for making sure you have picked the right file.

![](<../../../.gitbook/assets/image (7).png>)

## Review and Start

* **Attempts limit** and **Attempts reset the period**\
  If the device has failed to update N times, the server will stop trying to update it until the attempts reset period passes (which is 24 hours by default).

![](../../../.gitbook/assets/Air\_Review\_and\_Start.PNG)
