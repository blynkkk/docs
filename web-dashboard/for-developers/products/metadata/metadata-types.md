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
* **Number** – field name examples: "Serial number", "Unit S/N" 200 characters limit.
  * **DEFAULT VALUE** – set default value up to 15 digits. Stepper buttons are available for this field.
  * **MIN/MAX VALUES \(OPTIONAL\)** – set value range limits. Stepper buttons are available.
  * **STEP** – \(Optional\) set values change amount per one step. Stepper buttons are available.
* **Unit** – field name examples: ""Temperature", "Volume", ''Pressure", etc.. 200 characters limit.
  * **VALUE** – set default value up to 15 digits. Stepper buttons are available for this field.
  * **UNITS** – select metric or imperial unit from the dropdown list.
  * **MIN/MAX VALUES \(OPTIONAL\)** – 
  * **STEP**
* **Time Range**
* **Contact**
* **Time**
* **Cost**
* **Coordinates**
* **Switch**
* **Device Reference**
* **List**
* **Table**
* **IMEI**
* **ICCID**

