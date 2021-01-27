---
description: >-
  This page includes common fields options descriptions in top section and Type
  specific settings (if they are present) under Types descriptions in lower
  section.
---

# Metadata Types

## Common Metadata settings for all Types:

* _**`Metadata Type Name`**_ – type default value that will be used and can be changed during Add Device procedure.  200 characters limit. 
* **ADVANCED SETTINGS** – click `+` to access the following settings: 
  * **SHORT DESCRIPTION** – fill this field with information corresponding to the hint "Help end-users understand what this field is about and how it will be used." 100 characters limit. 
  * **MOBILE APP PROVISIONING**  
    * **Include in Mobile App Provisioning** \(switch\) – enabling this option allows to edit current Metadata Field during Device Provisioning 
    * **This is a required field** \(checkbox\) – marking the checkbox makes current Metadata Field mandatory during Device Provisioning 
    * **Exclude from “Recently used profile”** \(checkbox\) – marking the checkbox excludes current Metadata Field during Provisioning of the next Device

### Basic Metadata types 

Those 5 are present in any Product and can not be deleted:

* **Device Name** – here you can type default Device name. 200 characters limit.
* **Device Owner** – here you can type default Device Owner name or Email. 200 characters limit.
* **Location** – here you can type default Location name. 200 characters limit.
  * **PREMISES ELEMENTS TO INCLUDE ALONG WITH THE ADDRESS** \(un/mark desired checkboxes\):
    * **Building Name**
    * **Floor**
    * **Unit**
    * **Room**
    * **Zone**
* **Device Timezone** – select actual or preferred Timezone from the dropdown list
* **Hotspot Name** – here you can type default Hotspot name. 200 characters limit.

### Additional Metadata types available:

* **Text** – name this field any way you want and type default value for it. 255 characters limit for both fields.
* * **Number** – field name examples: "Serial number", "Unit S/N", "Plate Number", etc. 200 characters limit.

  * **DEFAULT VALUE** – set default value up to 15 digits. Stepper buttons are available for this field.
  * **MIN/MAX VALUES \(OPTIONAL\)** – set value range limits. Stepper buttons are available.
  * **STEP** – \(Optional\) set values change amount per one step. Stepper buttons are available.

* **Unit** – field name examples: ""Temperature", "Volume", ''Pressure", etc.. 200 characters limit.

  * **VALUE** – set default value up to 15 digits. Stepper buttons are available for this field.
  * **UNITS** – select metric or imperial unit from the dropdown list.
  * **MIN/MAX VALUES \(OPTIONAL\)** – set value range limits. Stepper buttons are available.
  * **STEP** – \(Optional\) set values change amount per one step. Stepper buttons are available.

* **Time Range** – field name examples: "Startup Delay", "Work period", etc.. 200 characters limit.

  * **FROM** and **TO** – select or type HH:MM value for each margin of the period. **Now** option is available – sets actual time for the selected field. Confirm by clicking OK. Reset by **X**

  \*\*\*\*

* **Contact** – field name examples: "Contact Person", "Representative", etc.. 200 characters limit. Un/mark checkboxes below to activate those fields.
  * **Allow default values** \(switch\) – enable this option to open default values fields \(200 characters limit\) for all the entities below:

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

    \*\*\*\*
* **Time** – field name examples: "Sunrise", "Sunset", "Start", etc.. 200 characters limit. Select or type HH:MM value. **Now** option is available – sets actual time for the selected field. Confirm by clicking OK. Reset by **X** 
* **Cost** – field name examples: "Maintenance cost", "Transit price", etc.. 200 characters limit.

  * **CURRENCY –** select the currency available in the dropdown list: ****USD, EUR, GBP, CNY, RUB
  * **PRICE** – set default price value
  * **PER QUANTITY** – set default numeric value of **UNITS** – select metric or imperial unit from the dropdown list.
  * **MIN/MAX VALUES \(OPTIONAL\) –** define the prices range

* **Coordinates** – field name examples: "Factory Location", "Shipping Facility", etc. 200 characters limit.
  * **LAT** – set latitude default value here**,  LON** – set longtitude default value here 
* **Switch** – this field purpose is to show to options of the same entity

  * **STRING** – ****give a name or a description of an entity. 200 characters limit
  * **OPTION A** – set or describe one of two possible options. No characters limitations.
  * **OPTION B** –  set or describe second of two possible options. No characters limitations.

  \*\*\*\*

* **Device Reference** – field name examples: "Other boards versions", "Part of group with", etc.. 200 characters limit.

  * **PRODUCT\(S\)** – type/search/select the existing Product/s

* **List** – name a list of entities you want to create. ****200 characters limit.
  * **OPTIONS** – create a list of entitites by adding them to this field. No characters limitations. Remove entity by clicking **X.**  
* **Table** – here you can add .csv format table
  * **TEXT** – name the table you'll add. 200 characters limit.
  * **Upload data file \(.csv\)** – click this area and your PC browser window will be opened. Select the .csv table you want to add and confirm the action. Drag'n'Drop is supported. 
* **IMEI** – type/paste default [International Mobile Equipment Identity](https://en.wikipedia.org/wiki/International_Mobile_Equipment_Identity) here. 15 digits limit. 
* **ICCID** – type/paste default [Integrated Circuit Card Identifier](https://en.wikipedia.org/wiki/SIM_card#ICCID) here. 200 characters limit.

