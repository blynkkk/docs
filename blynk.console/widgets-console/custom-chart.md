# Custom Chart

The Custom Chart widget is a chart that is fully configurable by your users. You add the widget to your template web dashboard, and then you or your users may customize it from the Device console.&#x20;

{% hint style="info" %}
The datastream(s) must already exist prior to customizing the chart with the advanced settings _Save raw data_ and _Show in Custom Charts_ enabled for them.&#x20;
{% endhint %}

It can be a good idea to create a separate tab in your device web dashboard, especially if you need different access permissions for it.

From Developer Zone -> My Templates -> Selected Template -> Web Dashboard, select or create a tab. Then drag and drop the Custom Chart widget to the tab’s window.

#### Settings

**Default Datastreams**\
Select the list of datastreams of any data type (integer, double, string, enumerable, GPS) that will be shown to the end user by default. Users can later adjust this list as needed.

**Data Aggregation**\
Define how the data will be aggregated:

* **Raw (RAW)** – Plots all available data points without aggregation. Best for detailed, high-frequency monitoring. Loads data in **3-day chunks**.
* **Average (AVG)** – Plots the average value per minute. Useful for smoothing out fluctuations and identifying trends. Loads data in **1-week chunks**.
* **Sample (SAMPLE)** – Plots every Xth raw value (e.g., every 2nd, 5th, or 10th), depending on the amount of data sent by your device. Useful when your device is sending signals instead of continuous updates, providing a clearer picture of periodic events. Loads data in **1-week chunks**.

Each aggregation type has a **100,000 data points per datastream limit**.

<figure><img src="https://lh7-us.googleusercontent.com/QHl3_swz1p00VQ932l4dagDCOGRX-_cglL43AM2siyg5u6P-tPZxzFl3CjCk7lOidy2G8TfEx2dUQdNQP5rexvBTkLMgwOyP4i2tWv3f0wz3OwkHoFqoiKFVyNU_dmqWvjh6XF6kGZiSOxhaV6zwuJ4" alt=""><figcaption></figcaption></figure>

### Time Period

The slider below the chart will adjust the time period displayed.  Note that the Time Period Filter above the chart has no effect on the time period displayed.
