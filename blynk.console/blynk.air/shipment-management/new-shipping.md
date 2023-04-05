# New Shipping

## Shipping name

Each shipping should have unique name.

1. Click **Keyboard pictogram** near default shipping name (top left screen area)
2. Type new name (40 characters limit)
3. Click **Save pictogram**

![](../../../.gitbook/assets/shipping-name.gif)



## Target selection

![Target selection area](../../../.gitbook/assets/air\_target\_selection.png)

**Template** – select a Template available in your Organization from the dropdown menu

**Preferred time** – select the best option of firmware update time period:

* **Any** – (default option) devices will be updated as soon as they connect to the server.&#x20;
* **Night** – 12AM-6AM
* **Morning** – 6AM-12AM
* **Afternoon** – 12AM-6PM
* **Evening** – 6PM-12AM



**Apply Update if the Device has** – firmwares comparison conditions checks:

* **Lower firmware version** – (default option) a semantic version is parsed from the binary file and compared against the device's firmware version.&#x20;
* **Earlier build date, Another build date** – build date of the binary file is parsed from the firmware info and compared against the stored one in the device information.
* **Lower generic version** – Blynk.Edgent library version is compared.



**Devices Selection Table** – 2 options available here:&#x20;

* **select** **Devices** available if you want to update certain devices by marking their checkboxes.
* **leave the selections empty** and all of the selected Product's/Template's devices will be updated including these that will be added in the future.&#x20;

There are sorting (all columns) and filtering (Firmware Version column only) options available to make Devices search easier:

![Sort, filter, select demo](../../../.gitbook/assets/air\_devices\_selection.gif)

## **Firmware info**

When the binary file is uploaded, the extracted information is shown in this section. It is useful for making sure you have picked the right file.

![](<../../../.gitbook/assets/image (4).png>)

## Review and Start

* **Attempts limit** and **Attempts reset period**\
  If the device has failed to update for N times, the server will stop trying updating it until the attempts reset period will pass (which is 24 hours by default).

![](../../../.gitbook/assets/air\_review\_and\_start.png)
