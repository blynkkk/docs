# Data Converters

Data Converter lets IoT devices send arbitrary HTTP requests (to a provided endpoint) or MQTT messages with any body, topic, or method, and use a user-written script to handle them — parsing payloads and headers, authenticating the device, transforming and writing values to Blynk datastreams, logging events, and returning acknowledgements or replies — enabling easy integration of legacy or non-standard devices without changing firmware.

The Data Converter is configured within a [Device Template](../../../concepts/device-template.md) and can be accessed from the Blynk Console under: Developer Zone → Template your devices will use → Data Converters.

{% content-ref url="http-data-converter.md" %}
[http-data-converter.md](http-data-converter.md)
{% endcontent-ref %}

{% content-ref url="mqtt-data-converter.md" %}
[mqtt-data-converter.md](mqtt-data-converter.md)
{% endcontent-ref %}

## Limitations

**HTTP Data Converter**

* Maximum request content length: 1 MB
* Maximum total headers size: 4 KB
* Maximum initial line length (method + URI + HTTP version): 4 KB
* The following HTTP request methods are supported: `GET`, `POST`, `PUT`, `HEAD`, `OPTIONS`, `PATCH`, `DELETE`, `CONNECT`, and `TRACE`
* When using authentication via metadata field, only the following metadata types are supported: Text, Device Name, ICCID, IMEI, Number. If multiple devices share the same metafield value, only one of them will be matched during authentication; the server’s behavior in this case is undefined.
* Only 2 HTTP decoders are allowed per template

**MQTT Data Converter**

* Maximum uplink message size: 1 MB
* At least one of the two functions (`handleUplink` or `handleDownlink`) must be declared
* Only 1 MQTT decoder is allowed per template
* During a single script execution:
  * Maximum of 5 MQTT messages can be published

**Common**

* Maximum heap memory: 5 MB
* Maximum stack size: 128 KB
* During a single script execution:
  * Maximum of 256 datastreams can be updated
  * If a datastream is updated multiple times, only the last value will be applied
  * Maximum of 3 events can be logged
* Error names are truncated to 100 characters, while error messages and stack traces are truncated to 1024 characters

These limits apply per script execution and are enforced to ensure reliability and performance of the Blynk backend. Also, see the TypeScript declarations for additional limits.
