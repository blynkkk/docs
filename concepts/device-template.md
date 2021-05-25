# Device Template

Device Template is a set of configurations inherited by devices of a similar type. 

Imagine smart home switches. They all perform a similar function and we can assume they should have the same data model, GPIOs, firmware code, etc. If you would need to introduce changes to all these devices, instead of editing each of them you could just edit a Device Template and all devices will be updated.



![Diagram of how devices are related to templates ](../.gitbook/assets/image-placeholder.png)



Every Device Template has a **Template ID** – ****a unique template identifier that helps Blynk to recognize the type of added device and attach all other template elements:

**General Settings:**  general settings of the device

**Metadata**: a table of `key:value` data attached to every device. `Keys` are static, and `values` are related for each device. For example Serial Number field can belong to every device, but the actual value is different. 

**Datastreams:**  channels for any time-stamped data that flows in and out from the device to the cloud. For example sensor data should go through a Datastream. If you used the first version of Blynk platform, these are Virtual Pins. 

**Events:**  important events in the life of the device that should be logged and, if needed, used for notifications. Events can be triggered from the device itself or externally using HTTP API

Template also includes two dashboards:

![Uploading Template.png…]()

**Web Dashboard:**  a set of UI elements \(widgets\) to visualize the data from the device accessible for the users in Blynk.360 – a web-based application.

**Mobile Dashboard:**  a set of UI elements \(widgets\) to visualize the data in Blynk mobile apps for iOS and Android. Mobile apps also contain a template of how device is represented in the list of devices \(tiles\) 



### Related Articles

{% page-ref page="../getting-started/working-with-templates/" %}

{% page-ref page="device-template.md" %}



\*\*\*\*

