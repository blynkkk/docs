# Map

Map widget displays different types of data linked to GPS Datastream, e.g. speed, fuel/charge level, temperature, vehicle load, number of passengers, direction, etc..

## Map and GPS track

![](../../../../.gitbook/assets/map-track.png)

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

## Track Overlays

## Misc

Here you can set up Device's **actual track point design**.

Select one of 4 track point styles:

* Point
* Course
* Truck
* Device name

Select Datastream that contains course information in degrees \(e.g. it gets it from Device's compass\) so the track point can **show course direction** \(this feature is supported by Course and Truck point styles\)

![](../../../../.gitbook/assets/captured-2021-03-26t164032.061%20%281%29.gif)

