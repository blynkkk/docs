# Chart

{% hint style="warning" %}
_**Note:**_ please remember that web and mobile app widgets are set up separately in the Web Dashboard and Mobile App Dashboard sections correspondingly. They can still use the same datastreams to access the same data (Map widget is an exception – a different codebase is used for Map on mobile and web).
{% endhint %}

Chart is used to visualise live and historical data. You can use it for sensor data, for binary event logging and more. Chart display can be of 4 types: _Line, Area, Column, Stepline_General chart properties:

* **Values axis** (vertical) – each Datastream added to Chart widget has it's scale on the right and left. It can be set manually or to be auto-scaled during Template dashboard setup.
* **Timeline Axis** (horizontal) – helps to find values actual for the exact time the search is performed.
* **Hover the chart** – views value ant time for each selected point for each Datastream.

<figure><img src="https://files.gitbook.com/v0/b/gitbook-legacy-files/o/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MVLXy69EogCOTmSZVul%2F-MVM0tyZhHW7hxWOM0dh%2FChart2.gif?alt=media&#x26;token=d8e60384-9ec2-4bdc-9246-85586bc2e19b" alt=""><figcaption><p>Stepline chart widget example</p></figcaption></figure>

<figure><img src="https://files.gitbook.com/v0/b/gitbook-legacy-files/o/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MVLXy69EogCOTmSZVul%2F-MVM0zztBlPi-PSyYwVQ%2FChart1.gif?alt=media&#x26;token=47c35cc0-6486-4baa-a253-edf24230b0d0" alt=""><figcaption><p>Area chart widget example</p></figcaption></figure>

### **Settings**

* **Add source** – it's possible to set several Datastream **Sources** under one Chart. Click and set up as much as you need.\

* **Chart Title** – name a chart so you or your client understand what it's about\

* **Source Label** – The easiest way to name it/them is giving used Datastreams names.  \

* **Source** – there are two fields:\

  * the  right one contains _**Datastreams used in the Product**_. Select one;  \

  *   the left is _**Source aggregation type menu**_ it's used to select an option to be used in chart data plotting:

      **AVG of** will plot average value per minute;

      **Raw of** data will plot using all the data available;

      **SUM of** will summarize all incoming values to the specified Virtual Pin;

      **MIN of** will plot minimum value per minute;

      **MAX of** will plot maximum value per minute;

      **COUNT of** will plot the number of times data was sent by device per minute;\

* **Chart type** - 4 types are available: _Line, Area, Column, Stepline_. Pick a color to make it different from other sources may use under this chart. &#x20;
  * **Show Y-axis** – enable if it's needed to view Datastream values on the axis (X-axis displays the time); &#x20;
  * **Autoscale** – enable if there's no specific limitations of the data values needed to be viewed. Otherwise specify them by setting the values in **MIN** and **MAX** fields.\

* **Enable zoom** – enable if chart zoom may be useful. Otherwise leave it disabled.

![Chart widget setup demo](../../.gitbook/assets/chart\_setup.gif)

