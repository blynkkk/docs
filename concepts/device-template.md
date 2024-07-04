# Device Template

A Device Template is a collection of configurations shared by devices of a similar type.&#x20;

Consider smart home switches as an example. These devices typically perform comparable functions and often have the same data model, GPIO assignments, firmware code, etc. Instead of editing each device individually when changes are required, you can modify a Device Template, and all associated devices will be updated accordingly.

Each Device Template possesses a `Template ID`, a unique identifier that enables Blynk to recognize the device type and link it to the relevant template elements:

1. **General Settings**: These encompass the device's overall settings.
2. [**Metadata**](../blynk.console/templates/metadata/): This consists of a `key:value` data table associated with every device. While keys remain static, values differ for each device. For instance, a Serial Number field may be present for every device, but the actual value varies.
3. [**Datastreams**](../blynk.console/templates/datastreams/): These are channels for time-stamped data transmitted between the device and the cloud. For example, sensor data should pass through a Datastream. In the context of the first version of the Blynk platform, these are akin to Virtual Pins.
4. [**Events**](../getting-started/events-tutorial.md): These represent significant occurrences in a device's lifecycle that should be logged and, if necessary, used for notifications. Events can be initiated by the device itself or externally via the HTTP API.
5. [**Automations**](automations.md) **settings:** defining which Datastreams should be exposed to Automations &#x20;

A Template also comprises two dashboards:

![Template](https://user-images.githubusercontent.com/72824404/119498209-0a317e00-bd6e-11eb-84d1-ae6565dfb7d3.png)

1. **Web Dashboard**: This includes a set of UI elements ([widgets](../blynk.console/widgets-console/)) for visualizing device data, accessible to users via Blynk.Console, a web-based application.
2. **Mobile Dashboard**: This contains a set of UI elements ([widgets](../blynk.apps/widgets-app/)) for displaying data in Blynk mobile apps on iOS and Android. Mobile apps also feature a template that represents devices in the list of devices (tiles).







## Related Articles

{% content-ref url="../getting-started/template-quick-setup/" %}
[template-quick-setup](../getting-started/template-quick-setup/)
{% endcontent-ref %}

{% content-ref url="../blynk.console/limits.md" %}
[limits.md](../blynk.console/limits.md)
{% endcontent-ref %}

\*\*\*\*
