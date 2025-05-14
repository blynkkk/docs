# Dashboard Widgets

Each widget has its own settings, similar to those on a [Device Dashboard](../templates/dashboard/) but adjusted slightly to work correctly with multiple devices.

The following widgets are currently supported:

#### Device Metrics Widgets

**Control Widgets**:

These widgets can be used to perform management operations on devices, such as turning devices on or off, or changing values.

* Switch
* Slider



**Display Widgets**:

These widgets can be used to display a metric value from multiple devices, or historical data for the selected period of time.

* Label
* Chart: Metrics over time, agg.
* Chart: Metric by devices

<div align="left"><figure><img src="../../.gitbook/assets/12_device_metrics_widgets.avif" alt=""><figcaption><p>Device Metrics Widgets</p></figcaption></figure></div>



#### **Event Widgets**

The dashboard includes 9 ready-to-use widgets that display data about events. These widgets provide insights into the latest events, most frequent events, critical events, and more. You can analyze trends and event distribution across devices and organizations, helping you stay informed and make data-driven decisions.

<div align="left"><figure><img src="../../.gitbook/assets/13_event_widgets.png" alt=""><figcaption><p>Event Widgets</p></figcaption></figure></div>



### Device metrics widgets

Device metrics widgets are designed to display or interact with datastream values, offering insightful data visualization and control.

#### Datastreams

All device metrics widgets require an assigned datastream to function. To streamline this process and enhance your experience, we’ve developed a **Virtual Pin** approach for datastream selection.

Instead of manually mapping multiple datastreams one by one, you only need to select a single Virtual Pin. All datastreams associated with that Virtual Pin will automatically be assigned to the widget, saving time and reducing complexity.

This approach simplifies widget setup and ensures a seamless connection to the data you need.

{% hint style="warning" %}
Before creating a dashboard, standardize the datastreams across the templates included in it so that the corresponding Virtual Pins contain the same data. For example, V1 represents Brightness across all templates.
{% endhint %}

E.g. You have launched a new product model. And you want to add the data from it to one of your existing dashboards. If you have datastreams standardized the same way as for the existing products, you just need to add the new product (template) to the dashboard data source and all of your widgets will be updated immediately.

#### Data Types

Current widgets support only Integer and Double data types. Datastreams of any other type will be ignored and excluded from calculations.

{% hint style="success" %}
For example, if you set the V1 Pin to display the Average value in a Label widget, and V1 uses the Integer type in four templates but String type in two, the calculation will only include the four Integer datastreams. The two String datastreams will be ignored, regardless of the data selection.
{% endhint %}

#### How to select datastreams

To select datastreams, choose a row from the dropdown. The dropdown displays all datastreams, grouped by Virtual Pin, based on the templates included in the dashboard's data source.

<figure><img src="../../.gitbook/assets/14_select_datastream.avif" alt=""><figcaption><p>Select datastreams grouped by Virtual Pin</p></figcaption></figure>

Once you select the row, assigned datastreams preview appears on the right, displaying the datastreams associated with the selected Virtual Pin across all templates included in the dashboard. This preview helps you quickly assess the data and confirm that the correct datastreams are connected for each template.

<div align="left"><figure><img src="../../.gitbook/assets/15_datastreams_preview.avif" alt=""><figcaption><p>Assigned datastreams preview</p></figcaption></figure></div>



#### Aggregation types

Blynk supports 4 aggregation types across all widgets: Average, Min, Max, and Sum.

Also the **Label widget** supports additional aggregation type - **Latest value**.&#x20;

{% hint style="info" %}
**Latest value** aggregation type is available only if **1 device** is selected and updates its latest value once in a 10 sec.
{% endhint %}

<div align="left"><figure><img src="../../.gitbook/assets/16_aggregation_types.avif" alt="" width="563"><figcaption><p>Aggregation types</p></figcaption></figure></div>

&#x20;&#x20;

#### Decimals

Determines the number of decimal places displayed for numerical values in the widget (e.g., #.## for 25.35).

#### Units

Specifies the measurement unit to display alongside values (e.g., °C, %, kWh) for clarity and context.

{% hint style="warning" %}
Note that this is purely a label and does not involve any unit conversion of the values.
{% endhint %}

### Switch

The Switch widget sends a command to the devices, typically 1 for ON and 0 for OFF. This widget allows you to turn multiple devices on or off with a single click. Additionally, it can interact with other datastreams and perform various operations that involve two states, such as enabling or disabling features, toggling between modes, or setting specific conditions.

{% hint style="info" %}
Please note that the switch does not reflect the current state of devices. It serves as a control for setting the desired state.
{% endhint %}

<div align="left"><figure><img src="../../.gitbook/assets/switch.png" alt="" width="276"><figcaption><p>Switch</p></figcaption></figure></div>

{% hint style="warning" %}
The value will be sent to all currently online devices. For offline devices, the value will be stored on the server. When any of these offline devices goes online, they may request the latest state via Blynk.sync() if necessary.
{% endhint %}

**How to configure**:

1. Select a datastream.
2. Set On/Off values.
3. Narrow down device selection (optional).
4. Design. Navigate to Design tab to adjust widget appearance such as color and labels.\


### Slider

The Slider widget sends a value to devices within a defined range. Move the slider handle or use the fine control buttons (+ and -) to set the value precisely. It may be used to adjust temperature setpoint, fan speed, brightness level, etc.

{% hint style="info" %}
Please note that the slider does not reflect the current value on devices. It serves as a control for setting the desired value.
{% endhint %}

<div align="left"><figure><img src="../../.gitbook/assets/slider (1).png" alt="" width="330"><figcaption><p>Slider</p></figcaption></figure></div>

{% hint style="warning" %}
The value will be sent to all currently online devices. For offline devices, the value will be stored on the server. When any of these offline devices goes online, they may request the latest state via Blynk.sync() if necessary.
{% endhint %}

**How to configure**:

1. Select a datastream.
2. Set Values Range. Enter Min and Max values and Handle step value.
3. Narrow down device selection (optional).
4. Design. Navigate to Design tab to edit the name, choose a color, or enable fine controls.

### Label

The Label widget provides a clear, aggregated view of important data from single or multiple devices.

<div align="left"><figure><img src="../../.gitbook/assets/label.png" alt="" width="207"><figcaption></figcaption></figure></div>

By combining data from multiple devices, the Label widget helps you make informed decisions. It is useful in many cases such as:

**Construction**: Display the total energy consumption of a building by aggregating data from all smart meters and sensors.

**Agriculture**: Show the average humidity level across multiple greenhouses to ensure optimal growing conditions.

**Manufacturing**: Present the total output or efficiency rate of production lines by aggregating data from various machines and sensors.

**Smart Homes**: Display the overall air quality index by combining readings from multiple air quality sensors throughout the house.



**How to configure**:

1. Select datastreams.
2. Choose aggregation type. You can choose Average, Min, Max, Sum, or Latest value (only if 1 device selected).
3. Narrow down device selection (optional).
4. Design. Navigate to Design tab to configure options such as Background color, Level, and Content Alignment.

{% hint style="warning" %}
Ensure that **Enable History Data** switch is enabled across all used datastreams. Otherwise the widget will not display the data.

1. Navigate to Developer Tools → Templates.
2. Open a template → Datastreams tab.
3. Click on a datastream.
4. Open Advanced Settings.
5. Turn on the Enable history data.


{% endhint %}

<figure><img src="../../.gitbook/assets/17_enable_history.avif" alt=""><figcaption><p>Enable History Data</p></figcaption></figure>



### Chart: Metrics over time, agg.

This widget provides a visual representation of historical data, making it easier to identify trends, patterns, and anomalies over time.

<figure><img src="../../.gitbook/assets/metrics_over_time.png" alt=""><figcaption><p>Chart: Metrics over time, agg.</p></figcaption></figure>

By supporting multiple data series, the widget allows you to compare different data types simultaneously, such as temperature and humidity, or energy consumption and production output. You can also compare energy consumption or any other metric by different aggregation types, e.g. Min Temperature vs Max Temperature.

**How to configure**:

1. Select datastreams. The chart supports up to 5 series.
2. Choose aggregation type. You can choose Average, Min, Max, or Sum for each data series.
3. Narrow down device selection (optional).
4. Design. Navigate to Design tab to select the chart view (line, area, column (bar), or stepline) set colors, axis and series names.

### Chart: Metric by device

This chart displays datastream values from multiple selected devices on a single chart, with each device represented by a distinct line. You can customize the chart by selecting specific devices.

The chart can display data from up to **eight** devices at the same time.

<figure><img src="../../.gitbook/assets/metric_by_devices.png" alt=""><figcaption><p>Chart: Metric by device</p></figcaption></figure>

**How to configure**:

1. Select datastream.
2. Narrow down device selection (optional).
3. Design. Navigate to Design tab to set widget title.

### Device Table

The Device Table widget displays the latest datastream values from multiple devices along with their connection statuses. This makes it ideal for quickly identifying outliers, and comparing metrics across devices. Whether you're managing 10 or 1,000 devices, the table gives you a clear and actionable overview of their current state—helping you make faster decisions and keep operations running smoothly.

<figure><img src="https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-DXh201Sctf/f22b8d8e4a3066e6280206ff81bca083bf9fff2ddf9a6066c8c8a16bb9ad74a5ccf207fef3e274a3efe3096403284dfd52c46f90112e2d77a083a24bda8ac0e83af54ada73ee09100b8c5a87284cfbec0d59d41f3eac03d334f9d3e86d2b96992380ff2a" alt=""><figcaption></figcaption></figure>

### How to Configure

1. Add the Device Table widget to your dashboard.
2. Select the devices you want to display in the table.
3. Configure the columns (up to 20 supported).
4. (Optional) Add conditional formatting.
5. Adjust table settings such as Title, Default Sort, and Devices per Page.

### Selecting Devices

In this tab, you can choose which devices are shown in the table. You can:

* Select segments
* Apply filters
* Manually pick individual devices

By default, all devices from the Dashboard Data Source are selected.

### Columns

Once devices are selected, you can configure which datastreams appear as columns in the table (up to 20 columns).

#### Datastream Value Columns

Currently, only datastream value columns are supported, showing each datastream’s latest value. Data is refreshed every 10 seconds.

<figure><img src="https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-Dxg9tv_LnN/917b0d96f9bf82b95ee1213a2e6af8c7f35d513d0337136c524aab6bdeb543bb8b06ea54b472227a80f3203085d76d5ecfc88e70571790cd7201ccbc50d29ce7a7b4366fd5568b09f3184dce342f151ac0547742ef20e9b04245714660584b4cbc1137e8" alt=""><figcaption></figcaption></figure>

{% hint style="warning" %}
Preview displays dummy datastream values for 10 random devices from your selection. Real values will load after saving the dashboard.
{% endhint %}

#### Column Settings

* Column Name: By default, the name is taken from one of the selected datastream, but you can rename it.
* Display Options: There are three display options: Values, Bars, and Icons.



*

    <figure><img src="https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-WzAi206iqm/47a5413f32c6abf051ba01dc4b8e4df0200174eeedb6c9936828ca5e03040d3ab64ca7cb37e039e7173b220de5f45a3d5486f407cd05479db6018a9eb028d2652690e4c515196843629a5dbc413c1990a9d515d83fccf1e3819b27086e1a61d98adc59e9" alt=""><figcaption></figcaption></figure>
*
  * Values (default) - show datastream values as it is.

<figure><img src="https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-if_VZwDBKx/18bd17e58a67096b484e75fd03836a05888d5d228d2f280dfcef78dcf9bb8f3cbc307c898cf1eb750503d080cb5ede4f7f0416fa6bb0ca5a4d27ded33a0d69e3eed0e6923d30d7c475eb91c743c39156641cfbbe7b957d24cc55d78c81507b77267ed159" alt=""><figcaption></figcaption></figure>

*
  * Bars: Adds a colored bar in the background of the cell. You can set a min/max range, pick a color, and optionally enable dynamic color based on conditional formatting. Threshold lines or ranges are also supported.
  *

      <figure><img src="https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-j_XBRMiExf/ddd5eb448a93fc4ccc88cce9669ead48dab3922c67006fd7242a85223355ec8a0a96e7c38af4bbfa416b3cdd9ad53ed5ae88d1a698424cf7fd2bbeac147483e5aa91365eb54a1443c1f62fb7c60b077c71df5fef7b79cdb8f534fcb8eea031dc94fbfd1d" alt=""><figcaption></figcaption></figure>
  * Icons: Replaces values with icons. Define a value range and assign specific icons and colors for each value step.

\


<figure><img src="https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-uHq6JVe0ay/3d5030e61897e7edc3674d15540bfd0ffe976ef893ceff4194e6e131b0e13e11050df04390a7699d8788a93589132516e251dc67fb1242e2baf83d69ecf6eaaf46895100c0705fc5983e842aa1bc397f78e3a46db001266c1a350c47300c4cbb2bd35a67" alt=""><figcaption></figcaption></figure>

#### Conditional Formatting

Once you’ve configured columns, you can enhance the table visually by applying conditional formatting rules.

<figure><img src="https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-nB-WFYfJWt/8e80da0fd7b1be56541f4f6852956920a26b9cec148e791c0d9f2d11f6ad8cb314e3b5d831b8ba6a872d20cc5101d40453a14f0cb6703182d4a69192c009c779a08a0c48eee120195db14867deb6a9a978bae1fddd284cae4dfb7b7646d5f362360648ee" alt=""><figcaption></figcaption></figure>

This feature lets you highlight differences in device values using color gradients. You can start with one of the preset gradients or fully customize your own by adjusting the color and values. For each point on the gradient, you can define both the background and the content color.

<figure><img src="https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-ZGIjjlJ8aT/135a853b3c3dfb82ccb7029738aa818d14f73e7fedff51cc5f2dcb2f051db39c21678590b011576b38d509fd15d349165c1522abbeb7512bd06d8b1eb4b1c67476e3d664f3568d3cb320c5f866ba36d864460deee78b57a0044fc1b6370df5ccd2a5079d" alt=""><figcaption></figcaption></figure>

If you want the same formatting applied across all columns in the table, simply enable the Color all columns option.\


### Table Settings

In this tab, configure:

* Title: The table title.
* Default Sort Option: Choose a column and sort direction (ascending/descending). Users can re-sort while viewing by clicking on column headers, but settings will reset to the default on refresh.
* Devices per Page: Set the number of devices displayed per page to control the amount of visible data at a time.

<figure><img src="https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-7uhmUqKdML/5705f717fb90e6bafe65110e72f5d2b2e81d4218dfb47c40fb1d73807c78e1b06248c61d065a9a522ef27f05c7682e50a236d47a6d8420e084f28a66bea56e4ac492ad4a4b717c9f5782a2759aba978a80f2c8ea0d09809c3193742123984a5a80af9af9" alt=""><figcaption></figcaption></figure>

