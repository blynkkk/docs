# Dashboard

Here users can view and/or change Device data Datastreams in Widgets that were created during [Template's Dashboard setup](../../products/dashboard/).

![](../../../.gitbook/assets/device_dashboard.gif)

Select or adjust Time Period using the switches on top of the tab.

6 widget types can be met in this tab \(depends on what's set up by Template owner\):

## **Slider**

Slider ****allows to view and send values to Virtual Pin of the selected Device. Usage examples: volume, brightness, RPM, flap position control, etc.. Move slider **handle** or fine control steps **+** and **–** buttons \(optional\) to set the value.   
Please keep in mind that different step ammounts can be set to handler and buttons.

![Slider widget example](../../../.gitbook/assets/slider.gif)

## Switch

The simpliest widget used to send commands and view binary statuses of the device, such as power/option ON/OFF

![Switch widget example](../../../.gitbook/assets/switch.gif)

## **Label**

This widget displays value of Virtual Pin e.g. length/distance, mass, duration, volume, temperature and other data types including strings.Also it can show level/progress bar \(horizontal or vertical\) and/or have widget colors changes based on getting different predefined values.

![](../../../.gitbook/assets/label.png)

## **Chart**

It's used to visualise live and historical data. You can use it for sensor data, for binary event logging and more. Chart display can be of 4 types: _Line, Area, Column, Stepline_

General chart properties:

* **Values axis** \(vertical\) – each Datastream added to Chart widget has it's scale on the right and left. It can be set manually or to be autoscaled during Template dashboard setup.
* **Timeline Axis** \(horizontal\) – helps to find values actual for the exact time the search is performed.
* **Hover the chart** – views value ant time for each selected point for each Datastream.

![Stepline chart widget example](../../../.gitbook/assets/chart2.gif)

![Area chart widget example](../../../.gitbook/assets/chart1.gif)

## **Map**

**T**his widget displays device locations/route and data sets \(predefined by Template owner\) that are assigned to GPS data.

![Map widget example](../../../.gitbook/assets/map_widget.png)

1. Specify the time period if it's needed \(top center of the widget\):

   1. select the day: click arrows to switch to previous/next day or click on the day to open date picker, search and click on the date you want;
   2. set day time period: click the field containing time data to open time picker, set hh:mm for both start and end of the period; 

2. Change track overlay by selecting available in top right dropdown menu. It's used for values/statuses differences visualization that can be checked in track overlays legend \(bottom right\) 
3. Navigate to the point you want to check:
   1. use scale management buttons at top left of the widget;
   2. move the map by moving the mouse with left mouse button hold;
   3. click the point or area \(nearest point data will be displayed\);

![Scale management buttons](../../../.gitbook/assets/map_nav_but.gif)

Now you can see all the data that was actual while the device was on the selected location.  
It always starts with Date and Time in the first line, Location Longtitude and Latitude in second line and all other data in further lines.

## **Modules**

This widget is extremely useful in cases your Product devices use detachable modules that can be attached accordingly to use conditions.  
Each module has it's own tools, units, details that are represented by Datastreams sets configured under each module.  
****Here you can view and edit values of Datastreams used in each Module.

![](../../../.gitbook/assets/modules2.png)

![](../../../.gitbook/assets/module.png)

_Example:_   
Your Product is a road cleaning machine and it has summer setup with fan and dry broom modules and winter setup with snow brush and dryer modules. Fan and dryer use socket A for connection, broom and brush use socket B. Each module has Datastream set to represent the connectivity such as V0 for fan and V1 for dryer. So in Display Data for socket A you can switch between Fan and Dryer by enabling and disabling those Datastreams. Once connectivity DS is set to ON all the other Datastreams of Module will be displayed in Socket A tab. 

