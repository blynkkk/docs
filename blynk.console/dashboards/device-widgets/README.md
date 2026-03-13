# Device Widgets

Each widget has its own settings, similar to those on a [Device Dashboard](../../templates/dashboard/) but adjusted slightly to work correctly with multiple devices.&#x20;

Device widgets can be used to perform management actions such as turning devices on or off or updating values. They can also display data from multiple devices and visualize them on a map or floor plan.

<div align="left"><figure><img src="../../../.gitbook/assets/12_device_metrics_widgets.avif" alt=""><figcaption><p>Device Metrics Widgets</p></figcaption></figure></div>

### How to configure

Device widgets are designed to display or interact with datastream values, offering insightful data visualization and control.

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

<figure><img src="../../../.gitbook/assets/14_select_datastream.avif" alt=""><figcaption><p>Select datastreams grouped by Virtual Pin</p></figcaption></figure>

Once you select the row, assigned datastreams preview appears on the right, displaying the datastreams associated with the selected Virtual Pin across all templates included in the dashboard. This preview helps you quickly assess the data and confirm that the correct datastreams are connected for each template.

<div align="left"><figure><img src="../../../.gitbook/assets/15_datastreams_preview.avif" alt=""><figcaption><p>Assigned datastreams preview</p></figcaption></figure></div>



#### Aggregation types

Blynk supports 4 aggregation types across all widgets: Average, Min, Max, and Sum.

Also the **Label widget** supports additional aggregation type - **Latest value**.&#x20;

{% hint style="info" %}
**Latest value** aggregation type is available only if **1 device** is selected and updates its latest value once in a 10 sec.
{% endhint %}

<div align="left"><figure><img src="../../../.gitbook/assets/16_aggregation_types.avif" alt="" width="563"><figcaption><p>Aggregation types</p></figcaption></figure></div>

&#x20;&#x20;

#### Decimals

Determines the number of decimal places displayed for numerical values in the widget (e.g., #.## for 25.35).

#### Units

Specifies the measurement unit to display alongside values (e.g., °C, %, kWh) for clarity and context.

{% hint style="warning" %}
Note that this is purely a label and does not involve any unit conversion of the values.
{% endhint %}
