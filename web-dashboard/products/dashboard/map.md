# Map

{% hint style="warning" %}
Realtime updates for the map is not yet implemented.
{% endhint %}

Map widget displays different types of data linked to GPS Datastream, e.g. speed, fuel/charge level, temperature, vehicle load, number of passengers, direction, etc..

## Map and GPS track

![](../../../.gitbook/assets/map-track.png)

* **Show loaction track** – enable it to view the whole route. Otherwise only track points and direction will be displayed. **Color** and **line thickness pickers** are available for the Track.
* **Disconnect track points period** – enable it in case you need to split the track if timestamp delta between 2 points is higher than specified value.
* **Show direction** – enabling this option will show the arrows on the Track to ease the understanding of it's direction.
* Map Style – select the one you find the best for your purposes. 7 styles are available now:
  * Streets
  * Outdoors
  * Light
  * Dark
  * Satellite
  * Satellite+Streets
  * Blynk Light

## Callout

![](../../../.gitbook/assets/callout.png)

Callout is used to view specified Datastreams' value that was actual at the place and time selected by user in Map Widget.

* **Add Value** – click this button to search and select for any Datastream you want to show in Callout window.
* **Move** – hover on the previosly added Datastream panel for action buttons to appear. Hold Move button and change the position of Callout Value, release mouse button, repeat with other panels once you find it fine.
* **Delete** – hover on the previosly added Datastream panel for action buttons to appear. Click Delete button \(no confirmation is applied here\)

## Track Overlays

## Misc

Here you can set up Device's **actual track point design**.

Select one of 4 track point styles:

* Point
* Course
* Truck
* Device name

Select Datastream that contains course information in degrees \(e.g. it gets it from Device's compass\) so the track point can **show course direction** \(this feature is supported by Course and Truck point styles\)

![](../../../.gitbook/assets/captured-2021-03-26t164032.061%20%281%29.gif)

# Insert the data

Let's say we have the Location Datastream assigned to the Virtual Pin 5.
For the map you can update the data from the hardware:

```
Blynk.virtualWrite(V5, longitude, latitude);
```

Also, you can insert the data via HTTPS API:

`https://{server_address}/external/api/update?token={token}&V5=longitude&V5=latitude`  

You can also send multiple datastreams within the same request.
In that case these datastreams would be displayed in the callout with the same timestamp:

- `https://{server_address}/external/api/batch/update?token={token}&V5=longitude&V5=latitude&V6={somevalue}`

{% hint style="warning" %}
Please pay attention to the order of the coordinates. `Longitude` should always go first.
{% endhint %}


