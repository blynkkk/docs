# Metadata

Metadata is a set of `key:value` data attached to every device. `Keys` are static, and `values` are related for each device.&#x20;

For example, a Serial Number Metadata field can be attached to every device, but the actual value is different.

Unlike Datastreams, Metadata is not supposed to change very often. &#x20;

![](../../../.gitbook/assets/metadata\_table.PNG)

Metadata can be of different types. Choose the most relevant type for every characteristic.\
For example, if you would need to associate Serial Number with every product, add the “Number” metadata field. Metadata is also used during device provisioning and configiration process. Staff, installing the equipment will be able to fill it in.

![](<../../../.gitbook/assets/metadata types.png>)

Metadata can be edited by users based on their access level.

Default value can be set to each Metadata, be changed during Add Device procedure and edited any time later.

## Common Metadata settings for all Types:

Most of the text fields have 200 characters input limit. Specific differences will be shown in Type info.

* _**`Metadata Type Name`**_ – type default value that will be used and can be changed during Add Device procedure. \

* **Advanced Settings** – click `+` to access the following settings:\

  * **Short Description** – fill this field with information corresponding to the hint "Help end-users understand what this field is about and how it will be used." 100 characters limit.\

  * **Mobile App Provisioning** \

    * **Include in Mobile App Provisioning** (switch) – enabling this option allows to edit current Metadata Field during Device Provisioning\

    * **This is a required field** (checkbox) – marking the checkbox makes current Metadata Field mandatory during Device Provisioning\

    * **Exclude from “Recently used profile”** (checkbox) – marking the checkbox excludes current Metadata Field during Provisioning of the next Device

### Basic Metadata types&#x20;

![](../../../.gitbook/assets/basic\_metadata\_types.PNG)

Those 5 are present in any Product and can not be deleted:

* **Device Name** – here you can type default Device name.&#x20;
* **Device Owner** – here you can type default Device Owner name or Email.&#x20;
* **Location** – here you can type default Location name.&#x20;
  * PREMISES ELEMENTS TO INCLUDE ALONG WITH THE ADDRESS (un/mark desired checkboxes):
    * **Building Name**
    * **Floor**
    * **Unit**
    * **Room**
    * **Zone**
* **Device Timezone** – select actual or preferred Timezone from the dropdown list
* **Hotspot Name** – here you can type default Hotspot name.&#x20;

### Additional Metadata types available:

![](<../../../.gitbook/assets/metadata types.png>)

* **Text** – name this field any way you want and type default value for it. 255 characters limit for both fields.\

*   **Number** – field name examples: "Serial number", "Unit S/N", "Plate Number", etc..

    * **DEFAULT VALUE** – set default value up to 15 digits. Stepper buttons are available for this field.
    * **MIN/MAX VALUES (OPTIONAL)** – set value range limits. Stepper buttons are available.
    * **STEP** – (Optional) set values change amount per one step. Stepper buttons are available.


*   **Unit** – field name examples: ""Temperature", "Volume", ''Pressure", etc..

    * **VALUE** – set default value up to 15 digits. Stepper buttons are available for this field.
    * **UNITS** – select metric or imperial unit from the dropdown list.
    * **MIN/MAX VALUES (OPTIONAL)** – set value range limits. Stepper buttons are available.
    * **STEP** – (Optional) set values change amount per one step. Stepper buttons are available.


*   **Time Range** – field name examples: "Startup Delay", "Work period", etc..

    * **FROM** and **TO** – select or type HH:MM value for each margin of the period. **Now** option is available – sets actual time for the selected field. Confirm by clicking OK. Reset by **X**


* **Contact** – field name examples: "Contact Person", "Representative", etc.. Un/mark checkboxes below to activate those fields.
  *   **Allow default values** (switch) – enable this option to open default values fields for all the entities below:

      * **First Name**
      * **Last Name**
      * **E-mail Address** – validation is restricted to Email format here
      * **Phone Number**
      * **Street Address**
      * **City**
      * **State**
      * **ZIP Code**
      * **Country**
      * **Street Address 2**


* **Time** – field name examples: "Sunrise", "Sunset", "Start", etc.. Select or type HH:MM value. **Now** option is available – sets actual time for the selected field. Confirm by clicking OK. Reset by **X**\

*   **Cost** – field name examples: "Maintenance cost", "Transit price", etc..&#x20;

    * **CURRENCY –** select the currency available in the dropdown list: USD, EUR, GBP, CNY, RUB
    * **PRICE** – set default price value
    * **PER QUANTITY** – set default numeric value of **UNITS** – select metric or imperial unit from the dropdown list.
    * **MIN/MAX VALUES (OPTIONAL) –** define the prices range


* **Coordinates** – field name examples: "Factory Location", "Shipping Facility", etc..
  * **LAT** – set latitude default value here**,  LON** – set longtitude default value here\

*   **Switch** – this field purpose is to show to options of the same entity

    * **STRING** – give a name or a description of an entity.
    * **OPTION A** – set or describe one of two possible options. No characters limitations.
    * **OPTION B** –  set or describe second of two possible options. No characters limitations.


*   **Device Reference** – field name examples: "Other boards versions", "Part of group with", etc..

    * **PRODUCT(S)** – type/search/select the existing Product/s


* **List** – name a list of entities you want to create.
  * **OPTIONS** – create a list of entitites by adding them to this field. No characters limitations. Remove entity by clicking **X.** \

* **Table** – here you can add .csv format table
  * **TEXT** – name the table you'll add.
  * **Upload data file (.csv)** – click this area and your PC browser window will be opened. Select the .csv table you want to add and confirm the action. Drag'n'Drop is supported.\

* **IMEI** – type/paste default [International Mobile Equipment Identity](https://en.wikipedia.org/wiki/International\_Mobile\_Equipment\_Identity) here. 15 digits limit.\

* **ICCID** – type/paste default [Integrated Circuit Card Identifier](https://en.wikipedia.org/wiki/SIM\_card#ICCID) here. \

* **Firmware Update Control** – provides an option to users [manually control device firmware updates](../../blynk.air/user-controlled-shipments.md).
