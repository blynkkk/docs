# Dashboards

### Overview

Dashboards put you in the driver's seat for managing and monitoring all your devices in one place. They allow you to bring together data from different devices and control them from a single dashboard. Even if they belong to different templates, you can work with them simultaneously.

For example, you can display the average temperature value from 10 devices on a single Label widget or turn on multiple devices in a single click.

<figure><img src="../.gitbook/assets/01_overview.avif" alt=""><figcaption><p>Dashboards overview</p></figcaption></figure>

### Dashboard Data Filtering

In order to meet every needs we have developed three-layered device filtration allows you to cover all cases from small to enterprise scale.\


#### Layer 1: Dashboard Data Source

Dashboard Data Source allows you to refine the devices that should be included to the dashboard by selecting specific templates and organizations.

For example, you have three different products: a heater, an air conditioner, and a fan. However, you want to build a dashboard only for heaters. In that case, you can select the corresponding template that contains heaters as the dashboard data source, ensuring that only such devices are included.

<div align="left"><figure><img src="../.gitbook/assets/02_filters_datasource.png" alt="" width="372"><figcaption><p>Layer 1: Dashboard Data Source</p></figcaption></figure></div>

By default, the data source for the entire dashboard includes All devices (Templates = All, Organizations = All).  The Dashboard Data Source is editable anytime, but be careful as the changes affects all added widgets and may broke some of your settings.

<div align="left"><figure><img src="../.gitbook/assets/03_dash_datasource copy.avif" alt="" width="375"><figcaption><p>Setting up data source for your dashboard</p></figcaption></figure></div>



#### Layer 2: Widget Data Source

By default each widget is assigned to All devices from your Dashboard Data Source.

However, you can narrow down the device selection for any widget.

<div align="left"><figure><img src="../.gitbook/assets/04_filters_perwidget.png" alt="" width="372"><figcaption><p>Layer 2: Widget Data Source</p></figcaption></figure></div>

To specify devices for the widget:

* Open widget settings
* Navigate to Devices on a Data tab.
* Choose devices by selecting a segment bubble, applying filters, or picking them manually from the table.

Each widget may be assigned to a different subset of devices.

<figure><img src="../.gitbook/assets/05_filters_perwidget1.avif" alt=""><figcaption><p>Devices that are assigned to the widget</p></figcaption></figure>

#### Segments

"**All**" segment is assigned by default. It means all devices corresponding the dashboard data source are assigned. **The segments in widgets contain only devices corresponding dashboard data source, other devices are filtered out.**

Next to the "All" there are other segments that were created on a Devices page.\
You can select any of these segments.

#### Filters

Also you can select devices by applying filters (e.g. Device name contains “heater”). The filters work the same as on the Devices page.

#### Manual Selection

To assign particular device(s) as a widget data source select it from the table. Once you select the first device, the new segment "Selected devices \[count]" appears.

You may select up to 50 devices.

#### Layer 3. Dynamic Filters

Dynamic filters are available in View mode after a dashboard is created and are accessible to all users with dashboard access. These filters allow users to temporarily focus on specific devices included in the dashboard. They do not affect other users and are reset after the page is reloaded. The Filters button is located in the top-right corner.

There are three dynamic filters: Organizations, Templates, and Devices. The filter options are based on the dashboard's data source.

<div align="left"><figure><img src="../.gitbook/assets/06_filters_dynamic.avif.gif" alt="" width="384"><figcaption><p>Layer 3. Dynamic Filters</p></figcaption></figure></div>

<div align="left"><figure><img src="../.gitbook/assets/07_filters_dynamic1.avif" alt="" width="558"><figcaption><p>Apply dynamic filters to the dashboard</p></figcaption></figure></div>



### Creating a Dashboard

Access Dashboard Page: Go to the Dashboards page and click the New Dashboard button in the sidebar.

* To create a dashboard you need to have a Manage Dashboards permission. Additionally you need to have View Templates permission to be able to work on a template level.

![Group 3-3.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl--A1lXgmWWi/8e1d6f5301a164ecc78439b03eb96badc30c26e4e1ab74b630d0e213a6c51a6a870a8606a7099bdd6d26a34079aa8d271b1e684be03d3f658cdfd4b61dc4d46508e2864e2cafd63380bd4017f9b2e0af985931967ff48b9e39ae661b1f283aad9458bb95)The new dashboard will open in an empty state in Edit mode.Define Dashboard Data Source:\
Firstly, we recommend to narrow down the devices included to the dashboard if you don’t need all of them. It will make the dashboard configuration faster and simpler for you. To do that cliick the Change... button inside a Dashboard Data Source box and select desired templates and organizations.

![Screenshot 2024-11-14 at 15.02.15.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-zK0tNGItOK/3dc5542e6ed2d9550a3099e00cd4dbcab2ace778e66d80bc90fa8f34f7d63c8f26918629d7911b360930b740e18ac24be1b1141f2b4cafdf853f01c9738b77762c633a9b640aac170b26b7e01b38340a3d9b36be0e18aa3c2f7c58d7a020059d10299a60)

\
Build Your Dashboard: Add widgets from the Widget Box and configure them according to your needs. To add a widget double-click it or drag into the canvas.

![Screenshot 2024-11-14 at 16.34.54.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-U5HBIKwh50/561ad4fbdf3ad2442830738bd092089e23d2421b43860b4ededbf9eebbf377662f0332d43d1a92b58bc8fd273a8a6ae935f8f2dc42b161ca09c216bdf6b505be5e40a5380ac158b47f65980bf2c913a090101f7ec9d971a050c36f8f663e239fd96038d6)

Customize Dashboard Settings: Rename dashboard by clicking on it and entering the name. Also, you can set a default date range that is relevant to your data and will apply every time you open the dashboard and manage who can see the dashboard.Save Your Dashboard: Once you are satisfied with the dashboard view, click the Save Dashboard button in the top right corner. Congrats, your first dashboard is live.Manage Access: By default, only roles with Manage analytics permission from the organization where the dashboard was created have an access. You can grant view access to other roles through the Manage Access menu either in Edit mode or options menu.

![Screenshot 2024-11-14 at 16.37.32.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-2NSMWpGpBP/90c3d4c3d0da9b4aad0ff67c80f2e5f2fff7595c6fac752990d82abbdf5ccfc7c9a7ebc6a6961acb2eafb58654761b855c239b7b22e2452226523d317f99e2be72a3618d8dd6f90b8e60592dca9f2155a98afced362fedc438db8633e762c65ab2e68a04)

### Widgets

Each widget has its own settings, similar to those on a [Device Dashboard](https://docs.blynk.io/en/blynk.console/templates/dashboard) but adjusted slightly to work correctly with multiple devices.The following widgets are currently supported:

#### Device Metrics Widgets

Control Widgets:

These widgets can be used to perform management operations on devices, such as turning devices on or off, or changing values.

* Switch
* Slider

Display Widgets:

These widgets can be used to display a metric value from multiple devices, or historical data for the selected period of time.

* Label
* Chart: Metrics over time, agg.
* Chart: Metric by devices

![Screenshot 2024-11-14 at 18.24.01.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-uRWyBf1cSU/c83bed1ceb496c6372555c17144587b8958a28efd78634b4574f5581da1ff656b90911b86fe9e66410fd2ad3d67b6964e0865275ea5d992e2987f24560dc7b3a8ca36d05559ca49f0adca2fc73459fc25e62a6e66ea74cf5c59c2795529a229abb30e8da)

#### Event Widgets:

The dashboard includes 9 ready-to-use widgets that display data about events. These widgets provide insights into the latest events, most frequent events, critical events, and more. You can analyze trends and event distribution across devices and organizations, helping you stay informed and make data-driven decisions.

![Screenshot 2024-11-14 at 18.22.01.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-HFX6IvX1l0/214ebab9c72e2b5d3ac921186c96c4928747e39885eb805f65dace6844ea3c8d9b016ab1a33943d553fbb455afa90345023fe3460582ed22ed7b247381a9dbff22b93e6e539f3485ba1a43566d6573e7e0476be3c78b658588b997c01e70a2937783ebb1)

### Device metrics widgets

Device metrics widgets are designed to display or interact with datastream values, offering insightful data visualization and control.

#### Datastreams

All device metrics widgets require an assigned datastream to function. To streamline this process and enhance your experience, we’ve developed a Virtual Pin approach for datastream selection.

Instead of manually mapping multiple datastreams one by one, you only need to select a single Virtual Pin. All datastreams associated with that Virtual Pin will automatically be assigned to the widget, saving time and reducing complexity.

This approach simplifies widget setup and ensures a seamless connection to the data you need.Before creating a dashboard, you should standardize the datastreams across the templates so that the corresponding Virtual Pins contain the same data. For example, V1 represents Brightness across all templates.E.g. You have launched a new product model. And you want to add new data to one of your existing dashboards. If you have datastreams standardized the same way as for the existing products, you just need to add the new product to the dashboard data source (if it wasn’t) and all of your widgets will be updated immediately and you will get insights in a moment.

#### Data Types

Current widgets support only Integer and Double types, so the datastreams with another type will be ignored and haven't been taken into calculation.

{% hint style="success" %}
For example, you selected V1 Pin for showing Average value using Label widget. And it has Integer type in 4 templates and String type in 2 templates. The value will reflect an Average of 4 datastreams among 4 templates. The 2 String datastreams will be ignored regardless of the data selection.
{% endhint %}

#### How to select datastreams

To select datastreams, choose a row from the dropdown. The dropdown displays all datastreams, grouped by Virtual Pin, based on the templates corresponding to the dashboard's data source.

![Screenshot 2024-12-10 at 11.22.31.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-aS5soIkPK9/bc28abe4a0ecea33b70728bd864584625135cd2a5c5e831d6f916f09b16d079046119cae294a8ef367dfa20a80c341a01b50e4edf6a82bbb63c8ba2e931b02604758716364cb198bf47e55885059644be5d4c431a344340b25e011404e24b0d031ff318b)

\
Once you select the row, a datastreams preview appears on the right, displaying the datastreams associated with the selected Virtual Pin across all templates included in the dashboard. This preview helps you quickly assess the data and confirm that the correct datastreams are connected for each template.

![Screenshot 2024-12-10 at 11.23.20.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-7afQd6007u/fa57c802a7ea2674b884aaee7e784efa79e27e25eaf0748f12caaf4433ed5a1545657b4e9bffb4465b4e7942f32057acdfaeae3f7901a2ea81cd3291db05764ce5d5a6271ca602b8f2ff54e36962b7c1559689998eb273621dfeb133b117a00f17bdc2ad)

#### Aggregation types

We support 4 aggregation types across all widgets: Average, Min, Max, and Sum.Also the Label widget supports additional aggregation type - Latest value. It is available only if 1 device selected and streams its latest value once in a 10 sec.  ![Screenshot 2024-11-14 at 16.27.15.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-xcs1A-tYQw/e7bf863c1568a0c8bc35eaf7377b74449ea6152d79ec8d0bf81ea6677c3026688171bb886e9ea8da297a2280e52082989e5fcef21d08107345350d321139d304ce9219e31dcdf7fb5cb085e60fa235d7869c7c0c85c73bfbafbec2ac2e0e0cfdd8c2c43b)

#### Decimals

Determines the number of decimal places displayed for numerical values in the widget (e.g., #.## for 25.35).

#### Units

Specifies the measurement unit to display alongside values (e.g., °C, %, kWh) for clarity and context.Note that this is purely a label and does not involve any unit conversion of the values\


### Switch

The Switch widget sends a command to the devices, typically 1 for ON and 0 for OFF. This widget allows you to turn multiple devices on or off with a single click. Additionally, it can interact with other datastreams and perform various operations that involve two states, such as enabling or disabling features, toggling between modes, or setting specific conditions.

![switch.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-Z3QktImNMg/1e74d8749ec8cd778731f450f4429f4eccfdb20f91d9e01dfb7c5f0e64b3d81aacb87cd2cbeb1ffcfe189f4e375e9ce0fdb25e8ef28fc5a2624aecc6210b8c16ae3d15a83f60bd5a4e4958a7422e0f69a2dc1da07583bb00ffff58c3f7df7e272b63ee31)

Please note that the switch does not reflect the current state of devices. It serves as a control for setting the desired state.

{% hint style="success" %}
Note that the value will be sent to all currently online devices. For offline devices, the value will be stored on the server. When any of these offline devices go online, they may request the latest state via Blynk.sync() if necessary.
{% endhint %}

How to configure:

1. Select a datastream.
2. Set On/Off values.
3. Narrow down device selection (optional).
4. Design. Navigate to Design tab to adjust widget appearance such as color and labels.\


### Slider

The Slider widget sends a value to devices within a defined range. Move the slider handle or use the fine control buttons (+ and -) to set the value precisely. It may be used to adjust temperature setpoint, fan speed, brightness level, etc.

![slider.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-M_oIUBjWcz/bc7de26fe60590cd92ed99e50b15e77234684db2068ab06154d3d0e00f5769d84b851698c65cb59a3200ce11ba429eca2fabfb09c560d22cd1f4a269b7cde34fd6947bc0471bf08fb871b72288b79b0bd462e5d3351c24217c42a6d2bdbf02750d8983a4)

Please note that the slider does not reflect the current value on devices. It serves as a control for setting the desired value.Note that the value will be sent to all currently online devices. For offline devices, the value will be stored on the server. When any of these offline devices go online, they may request the latest state via Blynk.sync() if necessary.

How to configure:

1. Select a datastream.
2. Set Values Range. Enter Min and Max values and Handle step value.
3. Narrow down device selection (optional).
4. Design. Navigate to Design tab to edit the name, choose a color, or enable fine controls.

### Label

The Label widget provides a clear, aggregated view of important data from single or multiple devices.

![label.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-s6dN9TKI7i/00d6b70aae1963987bed4e800bc3bd843ee6924da1b10c4385dc552a8ae823372c119c62636fb1373c57df8c711922fc11afc0024e947b5c40b301a725da639efc8d16e60ab220a9fb296dd61f1c80358d8f7848958a891699ad1649add55762d0d28c8b)

By combining data from multiple devices, the Label widget helps you make informed decisions. It is useful in many cases such as:

**Construction**: Display the total energy consumption of a building by aggregating data from all smart meters and sensors.

**Agriculture**: Show the average humidity level across multiple greenhouses to ensure optimal growing conditions.

**Manufacturing**: Present the total output or efficiency rate of production lines by aggregating data from various machines and sensors.

**Smart Homes**: Display the overall air quality index by combining readings from multiple air quality sensors throughout the house.

How to configure:

1. Select datastreams.
2. Choose aggregation type. You can choose Average, Min, Max, Sum, or Latest value (only if 1 device selected).
3. Narrow down device selection (optional).
4. Design. Navigate to Design tab to configure options such as Background color, Level, and Content Alignment.

Ensure that Enable History Data switch is enabled across all used datastreams. Otherwise the widget will not display the data.

1. Navigate to Developer Tools → Templates.
2. Open a template → Datastreams tab.
3. Click on a datastream.
4. Open Advanced Settings.
5. Turn on the Enable history data.

![Screenshot 2024-11-14 at 16.59.00.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-57x314Ek8o/ce1488dccb6e7cad7e79afe1b324526eef63c7efe7cf2048eacd2d965b1ff98ba3e766bb33d933ea7f3f1c39ae65a11ec752dbc14c9f8f5bf099ac1aeb045819623adf58b719138f4034fb4d92f306c0eb8222498e343dee03c04e48bbb21421a1bdc240)

### Chart: Metrics over time, agg.

This widget provides a visual representation of historical data, making it easier to identify trends, patterns, and anomalies over time.

![metrics\_over\_time.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-YWWcNhDf3f/f3b0c5c9086926300063ff4a9c63dd7950618f54df65057e778efd34fecc53dc28d04ec5918100c50f9c223d4ff5aeda71bd17383c229b32cc4897873576e485e36d6fd470662cb4f5c5aec1597fcc93bf23ebcc2cc18ce78ebc1f919fd9f03a5bac2d77)

By supporting multiple data series, the widget allows you to compare different data types simultaneously, such as temperature and humidity, or energy consumption and production output. You can also compare energy consumption or any other metric by different aggregation types, e.g. Min Temperature vs Max Temperature.

How to configure:

1. Select datastreams. The chart supports up to 5 series.
2. Choose aggregation type. You can choose Average, Min, Max, or Sum for each data series.
3. Narrow down device selection (optional).
4. Design. Navigate to Design tab to select the chart view (line, area, column (bar), or stepline) set colors, axis and series names.

### Chart: Metric by devices

This chart displays datastream values from multiple selected devices on a single chart, with each device represented by a distinct line. You can customize the chart by selecting specific devices.

The charts supports showing up to 8 devices simultaneously.

![metric\_by\_devices.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-deq7rK1OaW/b30051cbe41cc6805b6ee7b13e5e8ad5be42814befe6933094c31dcea41e574e6d0d8d31fab00870e1b57ea78c8e01577ad0e66d2f99b238d2a7d430fd8390fe74d807181a1b51aa76c4b7ce7283b35dc2a8d274e4da8916a8523a862c00e5ac1ab0a095)

How to configure:

1. Select datastream.
2. Narrow down device selection (optional).
3. Design. Navigate to Design tab to set widget title.

### Date range picker

You can find the date range picker under the Dashboard name.

![Screenshot 2024-11-14 at 17.12.34.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-rZR8ehf8-7/b5e793d4224cbfb13769a9f7329b65d841fc61edad7161279697fc7ee22c36026219c00afcb4ff40a5c1f3507c27f5b2bf17300cdaee79b54affdc2ce0fa59ecbed311b52a0b10d101207364538b149973942b512091039141020aada6f6f2755bc2d9da)

This picker allows you to analyze historical data across different periods. It includes predefined ranges such as:1d - displays data for the last 24 hours.

* 1w - displays data for the last 7 days.1mo - displays data for the last 30 days.
* 3mo - Displays data for the last 90 days.
* 1y - Displays data for the last 365 days.

Please note, the date range picker does not affect the Control widgets and the widgets showing Latest value. Regardless of the selected range, it operates the same.

### Managing Access

By default, only users with the “Manage Dashboards” permission in the organization where the dashboard was created can access it. These users can view and edit all dashboards in that organization.

Please note that creating or editing a dashboard also requires the View Template permission.

You can also grant View access to specific dashboards for additional users using the Manage Access option, available in the menu or Edit mode.

![Screenshot 2024-11-14 at 16.37.32.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-2NSMWpGpBP/90c3d4c3d0da9b4aad0ff67c80f2e5f2fff7595c6fac752990d82abbdf5ccfc7c9a7ebc6a6961acb2eafb58654761b855c239b7b22e2452226523d317f99e2be72a3618d8dd6f90b8e60592dca9f2155a98afced362fedc438db8633e762c65ab2e68a04)

Dashboards can be shared with sub-organizations, allowing you to create a single dashboard and share it across all sub-orgs. However, shared dashboards can only be edited in the organization where they were created.

Access to a dashboard depends on the organizations included in its data source:

* **All or Only Sub-Organizations**: The dashboard is shared with all sub-organizations.
* **Specific Organizations**: The dashboard is shared only with those selected organizations.
* **Current Organization Only**: The dashboard is not shared with sub-organizations.



![Group 3-1.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-mt140P37WT/edf8062436798e93ec1507c2bae9f9c521952c11b689f915b139c7282b86663f8c9a32048ddfb018502d0a7b320617515470d885bff92870e061110e419192f3986ca12f623698d7814f48553c636997d004b38858d02cdac2792f585c5909326f48974d)

### Setting a Dashboard as the Homepage

Normally, when you log into Blynk, you’d see the device page first. This feature lets you set a dashboard as the homepage.By customizing your Homepage, you can ensure the data that matters most to you is always front and center. This makes it easier to keep track of key metrics, trends, and control devices.How to Set a Dashboard as the Homepage

1. **Open a dashboard**: Go to Dashboards and open the dashboard you want to set as the homepage.
2. **Open menu**: Find the Options menu in the top right corner.
3. **Set as homepage**: Choose the “Set as homepage” option from the menu.



![Set as Homepage.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-DtfHehj26J/c284e9197d40543445dac7b9a84800887a0b15aea37006d194bffe3e1b2754061f4fde48374094eab3cd300b5695cdb717e61f21eb56723ebd1f9ca2c100469099e09e4ef6c407ae53176bd6f385eb296e48eab19975ab86cc84f4a68071bcdf5519774e)

The home icon appears at the top of the Main Navigation menu once you’ve set the homepage.

The homepage applies per organization, so each of your organizations can have its own homepage.

![home.png](https://codahosted.io/docs/ULfOVK4kyk/blobs/bl-MGqMTp08Mk/5af236286a1cb4693534abc4aefdaeffd7b9994d5381c0866f0e75c26392597750b6547af8c7cae725560deba723b5219a0863f5df0348bddd7fa2d3c79fbf84defdbd220be0118a875bf92f22c6d15a6883809539225e406081bcc18775f96c3454b36b)

\
\
\
\
\
