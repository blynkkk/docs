# Video

The video widget allows you to display static, live, and streaming video(s) contained within a [M3U8 playlist](https://www.rfc-editor.org/rfc/rfc8216.html).  An M3U8 playlist is a Unicode version of an M3U playlist. &#x20;

### Datastream

Select or create a datastream of [data type string](../templates/datastreams/datastreams-common-settings/data-type.md).

At the moment Blynk doesn't provide streaming servers. So you can either stream directly from the camera, use third-party services, or host your own streaming server (on Raspberry Pi for example).

### Widget Controls

The video widget has the following controls:

* **Play / Pause:**  Press the play button to start or continue the video.  Press the pause button to stop the video. &#x20;
* **Frame Sider:**  Grab and slide it to position the video to a particular frame. &#x20;
* **Audio:** Adjust the audio volume or mute it.&#x20;
* **Full Screen:**  View the video in full screen.&#x20;
* **Playback Speed:**  Adjust the video playback speed. &#x20;

### How to change the video URL property

You can change the URL from your [hardware](../../blynk-library-firmware-api/widget-properties.md), or via an [HTTP API](../../blynk.cloud/device-https-api/update-property.md) by using the property name ‘url’.

```cpp
Blynk.setProperty(V1, "url", "http://my_new_video_url");
```

```
https://{server_address}/external/api/update/property?token={your 32 char token}&pin=V1&url={http://my_new_video_url}
```

### Change Video Properties

You can change the widget’s other properties (label, isDisabled, isHidden) from your [hardware](../../blynk-library-firmware-api/widget-properties.md), or via an [HTTP API](../../blynk.cloud/device-https-api/update-property.md). Set the property to True or an integer value of 1 to disable / hide the widget, or set the property to False / zero (0) to enable or make it visible. &#x20;

```cpp
Blynk.setProperty(V1, "isDisabled", "True");
```

```
https://{server_address}/external/api/update/property?token={your 32 char token}&pin=V1&isDisabled=1
```

```cpp
Blynk.setProperty(vPin, "widgetProperty", "propertyValue"); 
```

Where:&#x20;

* `vPin` is: virtual pin number the widget is assigned to
* `widgetProperty`: property you want to change
* `propertyValue`: value of the property you want to change

{% hint style="danger" %}
Don't put **`Blynk.setProperty()`**into the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, or use timers.
{% endhint %}
