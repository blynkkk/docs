# Image Map

#### Overview

The **Image Map widget** allows you to place devices on any image and monitor their status in real time. It’s designed for cases where the location or relative position of devices matters—for example, factory floors, offices, greenhouses, or homes.

Unlike GPS-based maps, the Image Map uses images you upload, giving you full control over the layout. You decide what the background looks like, and then position devices manually.

<figure><img src="../../../.gitbook/assets/Image_Map_example.png" alt=""><figcaption></figcaption></figure>

#### How to Configure

1. **Add the widget**\
   Open your dashboard, click _Add Widget_, and choose **Image Map** from the Widget Box.

<figure><img src="../../../.gitbook/assets/Image_map_widget_box.png" alt="Image Map Widget in the Widget Box"><figcaption><p>Image Map Widget in the Widget Box</p></figcaption></figure>

2. **Upload your image**\
   Upload any image to use as the map background. This could be a floor plan, site diagram, equipment layout, or even a simple sketch. The widget supports .jpg and .png formats only.
3. **Add devices**\
   Hover over the image and click in a place you want to add a device.

<figure><img src="../../../.gitbook/assets/Image_Map_add_device.png" alt="Adding Devices in the Image"><figcaption></figcaption></figure>

One you’ve clicked, the spot is created. Then pick a device you want to display there.

<figure><img src="../../../.gitbook/assets/Image_Map_pick_device.png" alt=""><figcaption></figcaption></figure>

4. **Adjust devices**\
   Resize a device marker if needed. You can also reposition devices anytime by dragging them.  Devices stay pinned to their locations for quick reference. You can place up to **50 devices** on one map.
5. **Configure device markers**\
   Choose how the markers look and what data are shown on markers.

{% hint style="info" %}
Device data is updated every 5 sec.
{% endhint %}

#### Device Marker Styles

You can select one of three marker styles:

* **Image** — shows the device image.
* **Value** — shows a selected datastream value.
* **Indicator** — shows the device as a circle, best for maps with many similar devices.

{% hint style="success" %}
Marker settings apply to all devices from the same template.
{% endhint %}

<figure><img src="../../../.gitbook/assets/Image_Map_marker_styles.png" alt=""><figcaption></figcaption></figure>

#### Color Based on Value

Enable **Change color based on value** to highlight devices according to their data. This feature makes it easy to spot abnormal values or changes at a glance, helping you quickly identify issues without scanning each device individually.

You can:

* Use a gradient scheme or set custom color rules based on the minimum and maximum values of a datastream.
* Color markers based on **connection status** (online/offline).

All marker styles support the **Color based on value** option.

<figure><img src="../../../.gitbook/assets/Image_Map_color_on_value.png" alt="Color based on value"><figcaption><p>Color based on value</p></figcaption></figure>

#### Popup

You can optionally add datastreams to display in a popup tooltip when clicking on a device. Each popup supports up to 5 datastreams, giving you quick access to extra details without crowding the map.

**💡 Tip:** Avoid overcrowding by showing only essential datastreams per device. For deeper analysis, combine the Image Map with tables or charts.

<figure><img src="../../../.gitbook/assets/Image_Map_popup.png" alt=""><figcaption></figcaption></figure>

#### Sharing to Sub-Orgs

When a dashboard containing an Image Map widget is shared with sub-organizations, users in the sub-org will see the background image along with only the devices they have access to. Devices from higher-level organizations are automatically filtered out. This ensures that sub-org users always view a clean and relevant map without exposure to unrelated devices.
