# Common Web Dashboard Navigation and Actions

## Global Navigation Menu. 

The **menu** is located on the left edge of the application and it's accessible any time and almost any place excepts for open modal windows.

![Navigation Menu](../../.gitbook/assets/navigation_menu.gif)

Clicking on a menu item will lead to a specific section of Blynk.360  
Menu sections:

* Organization Logo \(can be changed in [Organization Settings](../../web-dashboard/for-developers/settings/organization-settings/general.md)\)
* [Search](../../web-dashboard/for-developers/search/)
* [Analytics](../../web-dashboard/for-developers/analytics.md)
* [Products / Templates](../../web-dashboard/for-developers/products/)
* [Organization](../../web-dashboard/for-developers/organizations.md)
* [Blynk.Air](../../web-dashboard/for-developers/blynk.air/)
* [Rule Engine](../../web-dashboard/for-developers/rule-engine.md)
* [Settings](../../web-dashboard/for-developers/settings/)
* [User Profile](../../web-dashboard/for-developers/user-profile.md)

**Note:** if some sections buttons are missing contact your Organization administrator.

## Create

**Create** button is located in the upper right corner and has different names depending on the section is opened at the moment \(**+ New Device** in Devices section, **+ Invite New User** in Users section, etc..\)

![List view Create button position](../../.gitbook/assets/create_from_table.png)

Also it has screen center location if no entities are present_:_

![No entities Create button position](../../.gitbook/assets/create_from_start.png)

\_\_

_Action:_ 

* **Create** the entitty of the selected section

## Save / Cancel

This group of buttons is located in the upper right corner when in Create or Edit mode.

![](../../.gitbook/assets/cancel_save.png)

_Actions:_

* **Save** button – saves changes on the form
* **Cancel** button – cancels changes on the form
* **Delete** button \(available in Products and Organizations edit modes\)– deletes selected entity

## Actions Menu

Actions Menu button is located near a specific entity, e.g.: devices, user, table rows.   
When you hover the context menu icon![Image](../../.gitbook/assets/actions_menu.png)a pop-up menu appears with items \(actions\) that can be performed on this entity.

Locations examples:   

![User Profile Actions Menu](../../.gitbook/assets/profile_actions_menu.png)

![Devices list Actions Menu](../../.gitbook/assets/list_actions_menu.png)

![Device Actions Menu](../../.gitbook/assets/device_actions_menu.png)

## Modal windows 

Modal windows are used for editing, displaying, deleting information or entities. 

They can be of 2 types: 

* Create or Edit 
* Take Critical Actions

![Edit User modal window](../../.gitbook/assets/user_profile_edit%20%281%29.png)

![Critical action modal window](../../.gitbook/assets/critical_modal.png)



Modals have the following structure:

* **Title** – describes the context of the actions in which the modal is open, e.g.: Edit Device, Delete User
* **Warning \(optional\)** – note about the action is critical and it's impacts description 
* **Body** – displays form elements and other information. 
* **Buttons area** – in most cases contains Save / Cancel buttons group. Optional: Delete, Transfer

## Tables

Table is the main type of data display in Blynk.360. 

![](../../.gitbook/assets/products_table.png)

Table contents and actions:

* **Column headings**
* **Table rows** – entity data display
* Also, the table has the ability to sort and filter the elements of the table.
  * **Sorting** – clicking the column heading you can sort the items in the table - !an example is needed
  * **Filtration –** click on the filter icon to filter the elements in the table by the specified parameter:

![Shipments table sorting and filtering](../../.gitbook/assets/shipments_table_sorting.gif)

* **Copy an item** – there's an option to copy to the clipboard some elements:

![Copy Email from the row](../../.gitbook/assets/copy_from_row.gif)

* **Actions column** – context menu containing the actions that can be applied to a selected entity

![Actions column interaction](../../.gitbook/assets/actions_column.gif)

* **Multiple choice** – click on the checkbox in the first column \(after hover an entity logo\) allows you to select several elements and apply bulk actions \(for example, delete\) by selecting the desired item from the context menu.

![Locations selection](../../.gitbook/assets/locations_select.gif)

* **Switch to entity display**  – click on an element of the table to the display the entity  - !an example is needed

![Swicth to device and back to table ](../../.gitbook/assets/switch_to_from-devices.gif)



