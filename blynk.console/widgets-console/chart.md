# Chart

{% hint style="warning" %}
_**Note:**_ please remember that web and mobile app widgets are set up separately in the Web Dashboard and Mobile App Dashboard sections correspondingly. They can still use the same datastreams to access the same data (Map widget is an exception – a different codebase is used for Map on mobile and web).
{% endhint %}

The chart widget helps you to visualize live and historical data from multiple datastreams with a [data type](https://docs.blynk.io/en/blynk.console/templates/datastreams/datastreams-common-settings/data-type) of integer or double. You can use it for sensor data, for binary event logging and more. The data may be plotted as a line, area, column (bar), or a stepline.&#x20;

* **Values axis** (vertical) – each Datastream added to Chart widget has it's scale on the right and left. It can be set manually or to be auto-scaled during Template dashboard setup.
* **Timeline Axis** (horizontal) – helps to find values actual for the exact time the search is performed.
* **Hover the chart** – views value ant time for each selected point for each Datastream.

<figure><img src="https://files.gitbook.com/v0/b/gitbook-legacy-files/o/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MVLXy69EogCOTmSZVul%2F-MVM0tyZhHW7hxWOM0dh%2FChart2.gif?alt=media&#x26;token=d8e60384-9ec2-4bdc-9246-85586bc2e19b" alt=""><figcaption><p>Stepline chart widget example</p></figcaption></figure>

<figure><img src="https://files.gitbook.com/v0/b/gitbook-legacy-files/o/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MVLXy69EogCOTmSZVul%2F-MVM0zztBlPi-PSyYwVQ%2FChart1.gif?alt=media&#x26;token=47c35cc0-6486-4baa-a253-edf24230b0d0" alt=""><figcaption><p>Area chart widget example</p></figcaption></figure>

### **Settings**

* **Chart Title** – This is the label shown at the top of the widget. The default is the name assigned to the datastream.\

* **Datastreams** – [data type](../templates/datastreams/datastreams-common-settings/data-type.md) of integer or double may be assigned. You may create a new virtual pin or enumerable datastream directly by choosing the ‘+ Create New’ option. Multiple datastreams may be plotted on the chart.
*   **Edit Chart** - this option to the left of each datastream allows you to customize the appearance of the datastream values in the chart.



    * **Max/Min/Avg** - choose between plotting the average, max, and minimum value.



    * **Move Source** - allows you to change the order of datastreams in the legend.



    * **CHART TYPE** - the data may be plotted as a line, area, column (bar), or a stepline.



    * **Color** - choose the color of the line, area, column, or stepline.



    * **Show Y-axis** - will display a labeled y-axis when enabled.



    * **Autoscale** - automatically scales the y-axis.



    * **Override Datastream’s Min/Max fields** - this option is only available when ‘Autoscale’ is disabled. When enabled, the chart y-axis scale takes on the assigned ‘MIN’ and ‘MAX’ values.



    * **MINIMUM Y AXIS RANGE** - This option is only available when the option ‘Override Datastream’s Min/Max fields’ is disabled.


* **Show legend** - adds a legend to the top of the chart under the title when enabled.\


![Chart widget setup demo](../../.gitbook/assets/chart\_setup.gif)

