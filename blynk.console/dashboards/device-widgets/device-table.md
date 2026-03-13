# Device Table

The Device Table widget displays the latest datastream values from multiple devices along with their connection statuses. This makes it ideal for quickly identifying outliers, and comparing metrics across devices. Whether you're managing 10 or 1,000 devices, the table gives you a clear and actionable overview of their current state—helping you make faster decisions and keep operations running smoothly.

<figure><img src="../../../.gitbook/assets/1-table example.png" alt=""><figcaption><p>Device Table Widget</p></figcaption></figure>

#### How to Configure

1. Add the Device Table widget to your dashboard.
2. Select the devices you want to display in the table.
3. Configure the columns (up to 20 supported).
4. (Optional) Add conditional formatting.
5. Adjust table settings such as Title, Default Sort, and Devices per Page.

#### Selecting Devices

In this tab, you can choose which devices are shown in the table. You can:

* Select segments
* Apply filters
* Manually pick individual devices

By default, all devices from the Dashboard Data Source are selected.

#### Columns

Once devices are selected, you can configure which datastreams appear as columns in the table (up to 20 columns).

#### Datastream Value Columns

Currently, only datastream value columns are supported, showing each datastream’s latest value. Data is refreshed every 10 seconds.

<figure><img src="../../../.gitbook/assets/2 - columns.png" alt=""><figcaption><p>Device Table - Columns</p></figcaption></figure>

{% hint style="warning" %}
Preview displays dummy datastream values for 10 random devices from your selection. Real values will load after saving the dashboard.
{% endhint %}

#### Column Settings

* Column Name: By default, the name is taken from one of the selected datastream, but you can rename it.
* Display Options: There are three display options: Values, Bars, and Icons.

<figure><img src="../../../.gitbook/assets/3 - options.png" alt=""><figcaption><p>Display Options</p></figcaption></figure>

*

    * Values (default) - show datastream values as it is.

    <figure><img src="../../../.gitbook/assets/4 - value.png" alt=""><figcaption><p>Values</p></figcaption></figure>

    * Bars: Adds a colored bar in the background of the cell. You can set a min/max range, pick a color, and optionally enable dynamic color based on conditional formatting. Threshold lines or ranges are also supported.

    <figure><img src="../../../.gitbook/assets/5 - bars.png" alt=""><figcaption><p>Bars</p></figcaption></figure>

    * Icons: Replaces values with icons. Define a value range and assign specific icons and colors for each value step.

    <figure><img src="../../../.gitbook/assets/6 - icons.png" alt=""><figcaption><p>Icons</p></figcaption></figure>



#### Conditional Formatting

Once you’ve configured columns, you can enhance the table visually by applying conditional formatting rules.

<figure><img src="../../../.gitbook/assets/7 - conditional formatting.png" alt=""><figcaption><p>Conditional Formatting</p></figcaption></figure>

This feature lets you highlight differences in device values using color gradients. You can start with one of the preset gradients or fully customize your own by adjusting the color and values. For each point on the gradient, you can define both the background and the content color.

<div align="left"><figure><img src="../../../.gitbook/assets/8 - formatting settings.png" alt="" width="563"><figcaption><p>Formatting Settings</p></figcaption></figure></div>

If you want the same formatting applied across all columns in the table, simply enable the Color all columns option.<br>

#### Table Settings

In this tab, configure:

* Title: The table title.
* Default Sort Option: Choose a column and sort direction (ascending/descending). Users can re-sort while viewing by clicking on column headers, but settings will reset to the default on refresh.
* Devices per Page: Set the number of devices displayed per page to control the amount of visible data at a time.

<figure><img src="../../../.gitbook/assets/10 - table settings.png" alt=""><figcaption><p>Table Settings</p></figcaption></figure>
