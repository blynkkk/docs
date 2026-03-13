# Geomap

#### Overview

The Geomap widget allows you to display device locations on a world map. It provides a real-world view of where your devices are located and helps you monitor their status and key data at a glance.

{% hint style="info" %}
The widget is available on **Pro and Enterprise plans**.
{% endhint %}

<figure><img src="../../../.gitbook/assets/GeoMap_example.png" alt=""><figcaption></figcaption></figure>

Device location is determined automatically in the following order:

1. **Metadata location** set in the device profile
   * **GPS coordinates:** If “Use location data from device (e.g. GPS)” is enabled in the Location Metadata, the system uses the coordinates sent by the device to the Location datastream.
   * Otherwise, the system uses either the **organization’s default location** or the **static location defined in the metafield** itself.
2. **IP-based geolocation** — used if no location metadata is available.

This logic ensures that every device can appear on the map, even if it doesn’t provide precise GPS data.

{% hint style="warning" %}
If neither Location Metadata nor IP information is available, the device will not be shown on the map.
{% endhint %}

#### How to Configure

1. **Add the widget**\
   Open your dashboard, click **Add Widget**, and select **Geomap**.

<figure><img src="../../../.gitbook/assets/Geomap_widget_box.png" alt=""><figcaption></figcaption></figure>

2. **Select devices**\
   In the **Data** tab, choose which devices you want to display on the map. By default, all devices from the dashboard’s data source are selected.

<figure><img src="../../../.gitbook/assets/Geomap_select devices.png" alt=""><figcaption></figcaption></figure>

3. **Configure marker styles**\
   Open the **Design** tab to customize how device markers look and what information they display for each device template.

{% hint style="warning" %}
Marker settings apply to all devices from the same template.
{% endhint %}

**Device Marker Styles:**\
You can select one of three marker styles:

* **Image** — shows the device image.
* **Value** — shows a selected datastream value.
* **Indicator** — shows the device as a circle, best for maps with many similar devices.<br>

4. **Enable Color Based on Value (optional)**
5. Turn on Color based on value to highlight devices according to their data or status:
   * Use a gradient scale or set custom thresholds for a chosen datastream (red - danger, green-normal).
   * Color markers based on connection status (online/offline).

<figure><img src="../../../.gitbook/assets/geomap_color_on_value.png" alt=""><figcaption></figcaption></figure>

This helps you spot abnormal values or disconnected devices immediately.\
All marker styles support the **Color based on value** option.<br>

5. **Set up popup details**\
   Configure which datastreams appear in the popup tooltip when clicking a device marker. You can display up to **5 datastreams per device**, providing more detail without cluttering the map view.

<figure><img src="../../../.gitbook/assets/Geomap_popup.png" alt=""><figcaption></figcaption></figure>

6. **Adjust map view**\
   In the **Settings** tab, choose your preferred map style. This style will be applied by default when the dashboard is loaded.

<figure><img src="../../../.gitbook/assets/Geomap_settings.png" alt=""><figcaption></figcaption></figure>

7. **Save your dashboard**\
   Once configured, the widget is ready to use.

#### Sharing to Sub-Orgs

If the dashboard is shared with sub-organizations, users in those sub-orgs will only see the devices they have permission to access. Devices outside their scope are automatically filtered out. This ensures that each user sees only the relevant devices in their Geomap view.
