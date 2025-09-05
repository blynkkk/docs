---
description: >-
  Build structured databases that connect your business data with IoT devices
  and sensors
---

# Databases

Databases allow you to create custom structured databases to store and organize your information. Each table can have multiple columns of different types, with built-in validation, permissions, and integration with your IoT devices.

Databases are integrated with Blynk.Console and mobile applications.

### Supported Column Types

| Column Type          | Description                           | Best Used For                                      |
| -------------------- | ------------------------------------- | -------------------------------------------------- |
| **Text**             | Store words, sentences, or paragraphs | Names, descriptions, notes, addresses              |
| **Integer**          | Whole numbers only                    | Counts, quantities, IDs, ages                      |
| **Double**           | Numbers with decimals                 | Measurements, prices, percentages, sensor readings |
| **Date**             | Calendar dates                        | Deadlines, birthdays, creation dates, schedules    |
| **Enum**             | Predefined list of options            | Status values, categories, priority levels         |
| **Device Reference** | Link to your IoT devices              | Associate records with specific devices            |
| **Table Reference**  | Link to other data tables             | Connect related information across tables          |
| **Formula**          | Calculated values                     | Automatic calculations based on other columns      |
| **List**             | Multiple device references            | When one record relates to several devices         |
| **Aggregation**      | Summary calculations                  | Totals, averages, counts from related data         |

### System-Managed Columns

{% hint style="info" %}
These columns are automatically maintained by the system and cannot be manually edited.
{% endhint %}

| Column Type      | What It Stores                     |
| ---------------- | ---------------------------------- |
| **Created At**   | When the record was first created  |
| **Modified At**  | When the record was last updated   |
| **Created By**   | Who created the record             |
| **Organization** | Which organization owns the record |

### Column Configuration

#### Text Columns

Configure text-based data with validation and formatting options.

| Setting                | Description                  | Example                                      |
| ---------------------- | ---------------------------- | -------------------------------------------- |
| **Minimum Characters** | Shortest allowed text length | Require at least 3 characters for names      |
| **Maximum Characters** | Longest allowed text length  | Limit descriptions to 500 characters         |
| **Default Value**      | Text automatically filled in | "New Item" or "{timestamp}" for current date |
| **Placeholder**        | Helpful hint text            | "Enter customer name here..."                |
| **Required**           | Must be filled in            | ✓ Make name field mandatory                  |

{% hint style="info" %}
Use `{timestamp}` in default values to automatically insert the current date and time.
{% endhint %}

#### Number Columns (Integer & Double)

Configure numeric data with precision and unit support.

| Setting            | Description                    | Example                             |
| ------------------ | ------------------------------ | ----------------------------------- |
| **Minimum Value**  | Smallest allowed number        | Don't allow negative quantities     |
| **Maximum Value**  | Largest allowed number         | Limit temperature readings to 100°C |
| **Default Value**  | Number automatically filled in | Start quantity at 0                 |
| **Unit**           | Measurement unit display       | °C, kg, meters, $                   |
| **Decimal Format** | How many decimal places        | Show 2 decimals for prices          |
| **Required**       | Must be filled in              | ✓ Require price entry               |

#### Date Columns

Configure date fields with range restrictions.

| Setting         | Description           | Example                          |
| --------------- | --------------------- | -------------------------------- |
| **Start Limit** | Earliest allowed date | No dates before January 1, 2020  |
| **End Limit**   | Latest allowed date   | No future dates beyond next year |
| **Required**    | Must be filled in     | ✓ Require delivery date          |

#### Enum (Dropdown) Columns

Create predefined lists of options for consistent data entry.

| Setting               | Description                 | Example                             |
| --------------------- | --------------------------- | ----------------------------------- |
| **Options List**      | Available choices           | Low/Medium/High or Red/Yellow/Green |
| **Default Selection** | Automatically chosen option | Default to "Medium" priority        |
| **Required**          | Must select an option       | ✓ Require status selection          |

#### Device Reference Columns

Link records to your IoT devices for better data organization.

| Setting               | Description                       | Example                                  |
| --------------------- | --------------------------------- | ---------------------------------------- |
| **Device Template**   | Filter to specific device types   | Only show temperature sensors            |
| **Deletion Behavior** | What happens if device is deleted | Remove reference or delete entire record |
| **Required**          | Must select a device              | ✓ Require device assignment              |

{% hint style="warning" %}
When a referenced device is deleted, you can choose to either remove the reference (set to null) or delete the entire record. Choose carefully based on your data integrity needs.
{% endhint %}

#### Table Reference Columns

Create relationships between different data tables.

| Setting               | Description                              | Example                               |
| --------------------- | ---------------------------------------- | ------------------------------------- |
| **Target Table**      | Which table to link to                   | Link to "Customers" table             |
| **Deletion Behavior** | What happens if linked record is deleted | Remove link or delete this record too |
| **Required**          | Must select a linked record              | ✓ Require customer selection          |

#### Formula Columns

Create calculated fields that automatically compute values based on other columns.

| Setting                | Description             | Example                                     |
| ---------------------- | ----------------------- | ------------------------------------------- |
| **Formula Expression** | Calculation to perform  | `price * quantity` or `(temp_f - 32) * 5/9` |
| **Unit**               | Display unit for result | $, %, °C                                    |
| **Decimal Format**     | Result precision        | Show 2 decimal places                       |

{% hint style="info" %}
Formula columns are read-only and automatically recalculate when referenced columns change.
{% endhint %}

#### List Columns

Store multiple references in a single field.

<table><thead><tr><th>Setting</th><th width="246">Description</th><th>Example</th></tr></thead><tbody><tr><td><strong>Maximum Items</strong></td><td>How many items allowed</td><td>Allow up to 5 devices per record</td></tr><tr><td><strong>Item Type</strong></td><td>What can be added to list</td><td>Only device references currently supported</td></tr></tbody></table>

#### Aggregation Columns

Create summary calculations across related data.

| Setting              | Description            | Example                       |
| -------------------- | ---------------------- | ----------------------------- |
| **Source Table**     | Where to get data from | "Orders" table                |
| **Linking Column**   | How tables connect     | Match customer ID             |
| **Value Column**     | What to calculate      | Sum the "amount" column       |
| **Calculation Type** | Type of summary        | Sum, Average, Count, Min, Max |
| **Unit**             | Display unit           | $ for monetary totals         |

**Available Aggregation Types**

* **Sum**: Add up all values
* **Average**: Calculate the mean value
* **Count**: Count the number of records
* **Minimum**: Find the smallest value
* **Maximum**: Find the largest value

### Table Configuration

#### General Settings

Configure the basic properties of your data table.

| Setting            | Description                                            |
| ------------------ | ------------------------------------------------------ |
| **Table Name**     | Internal system name (no spaces or special characters) |
| **Display Name**   | Friendly name shown to users in the interface          |
| **Singular Name**  | What to call one record ("Customer" not "Customers")   |
| **Display Column** | Which column to show as the main identifier            |
| **Hide on Mobile** | Whether to show this table on mobile devices           |
| **Icon**           | Visual icon URL for the table                          |

#### Data Sharing Settings

Control how data is shared within your organization structure.

| Setting                          | Description                              |
| -------------------------------- | ---------------------------------------- |
| **Share with Sub-Organizations** | Allow child organizations to see records |
| **Allow Row Creation**           | Let users add new records to the table   |

#### Access Control

Configure who can view and edit data at different organizational levels.

**Permission Levels**

| Permission Level           | Description                                            |
| -------------------------- | ------------------------------------------------------ |
| **Root Organization View** | Roles that can see records in the main organization    |
| **Root Organization Edit** | Roles that can modify records in the main organization |
| **Sub Organization View**  | Roles that can see records in child organizations      |
| **Sub Organization Edit**  | Roles that can modify records in child organizations   |

{% hint style="warning" %}
Be careful when setting permissions. Overly restrictive permissions can prevent users from accessing needed data, while overly permissive permissions can compromise data security.
{% endhint %}

### Best Practices

#### Getting Started

{% hint style="info" %}
**Start Simple**: Begin with basic Text and Number columns, then add advanced features like formulas and aggregations as your needs grow.
{% endhint %}

#### Naming Conventions

* **Use Meaningful Names**: Choose clear, descriptive column names that explain what the data represents
* **Be Consistent**: Use the same naming style throughout your tables
* **Avoid Special Characters**: Stick to letters, numbers, and underscores for system names

#### Data Validation

* **Set Appropriate Limits**: Use min/max values and character limits to prevent data entry errors
* **Use Required Fields Wisely**: Only mark fields as required if they're truly essential
* **Provide Good Defaults**: Set sensible default values to speed up data entry

#### Relationships and References

* **Plan Relationships**: Think about how your tables connect before creating references
* **Choose Deletion Behavior Carefully**: Consider what should happen when referenced data is deleted
* **Use Device References**: Link records to devices to take advantage of IoT integration

#### Security and Access

* **Test Permissions**: Verify that the right people can access and edit your data
* **Review Regularly**: Periodically review access permissions as your team changes
* **Use Role-Based Access**: Assign permissions to roles rather than individual users

#### Performance Considerations

* **Limit Formula Complexity**: Keep formula expressions simple for better performance
* **Be Mindful of Aggregations**: Complex aggregations on large datasets may impact performance
* **Consider Mobile Users**: Use the "Hide on Mobile" setting for complex tables not suitable for small screens



{% hint style="success" %}
For additional support, consult your account manager
{% endhint %}
