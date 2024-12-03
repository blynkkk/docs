# Filters

### Overview

Filters allow you to refine your device list based on specific parameters. You can add filters using the search bar or the **Add Filter** button. Filters can be applied to various attributes, enabling precise and dynamic segmentation. By combining and customizing filters, you can create complex queries for more specific device management.

### Types of Filters

#### Available Device Filter Types

You can filter devices by the following parameters:

* **Device Activated By** – Filter by the email of the person who activated the device.
* **Device Activated** – Filter by the date of device activation.
* **Device Owner Name** – Filter by the name of the device owner.
* **Device Owner Email** – Filter by the email of the device owner.
* **Device Status** – Filter by the current status of the device.
* **Device Last Reported** – Filter by the date when the device last sent data.
* **Device Name** – Filter by the name of the device.
* **Metadata** – Filter by custom metadata fields.
* **Organization Name** – Filter by the organization the device is associated with.
* **Tag** – Filter by assigned tags.
* **Template Name** – Filter by the template used by the device.
* **Location** – Filter by location data such as address, ZIP code, city, or country.
* **Contact** – Filter by contact metadata.

#### Filtering Conditions

Each filter type supports various filtering conditions depending on the parameter:

* **Number-based Filters**:
  * Is equal to
  * Is not equal to
  * Is empty
* **Text-based Filters**:
  * Contains
  * Does not contain
* **Date-based Filters**:
  * Less than
  * More than

#### Multiple Values and Bulk Filtering Conditions

* You can apply multiple values to a single filter, which will act as an "OR" condition.
* When adding multiple filters, you can define the bulk filtering condition. There are two options:
  * **Match All** (AND condition): Entities must satisfy all filter criteria.
  * **Match Any** (OR condition): Entities must satisfy any of the filter criteria.



### How to Add and Apply Filters

#### Adding Filters

**Using the Search Bar:**

1. Enter the filter value in the search field.
2. Choose the filter from the autocomplete list.

**Using the `Add Filter` Button:**

1. Click the **Add Filter** button below the search bar.
2. Select the filter type from the dropdown menu.
3. Apply the desired filtering condition and enter the necessary values



#### Applying Filter Logic

**Single Filter:**

* When applying a single filter, the filtering is based on the selected parameter and value.

**Multiple Filters:**

1. Add the first filter and set the desired criteria.
2. Add additional filters as needed.
3. Select the bulk condition:
   * **Match All**: The device must satisfy all the filter criteria.
   * **Match Any**: The device must satisfy any of the filter criteria.

### Examples

#### Example 1: Filtering by Device Name

1. Add a filter for **Device Name**.
2. Select `Contains` as the filtering condition.
3. Enter the value "Sensor".

This will display devices whose names contain "Sensor."

#### Example 2: Combining Filters

1. Add a filter for **Location (City)** and set it to `Contains` "New York".
2. Add a filter for **Device Status** and set it to `Contains` "Online".
3. Set the bulk filtering condition to **Match All**.

This will display online devices located in New York.

#### Example 3: Single Filter with Multiple Values

1. Add a filter for **Device Tag**.
2. Select `Contains` as the filtering condition.
3. Enter the values "Error" and "Problem".

This will display devices with tags that contain either "Error" or "Problem."

### Limitations

* You can add a maximum of 5 filters.
* A single filter can contain a maximum of 10 values.
