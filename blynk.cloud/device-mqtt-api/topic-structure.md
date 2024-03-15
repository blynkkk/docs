# Topic Structure

## Downlink

These topics are used for messages sent from Blynk.Cloud to the device:

* [**downlink/ds/`DATASTREAM`**](./datastreams.md): Carries live updates of datastream values or responses to get/ds requests. This ensures that the device is updated with the latest values or specific data it requested.
* [**downlink/meta/`FIELD`**](./metadata.md): Used to send responses for `get/meta` requests made by the device. This allows the device to update its configuration or status based on cloud-side settings or information.
* [**downlink/ota/json**](./ota.md): Requests from the server to perform a software/firmware update.
* [**downlink/utc/all/json**](./timezone-location.md): Device Time and Timezone information. Used to send response for `get/utc/all/json` request made by the device.
* [**downlink/loc/all**](./timezone-location.md): Device approximate location. Used to send response for `get/loc/all` request made by the device.
* [**downlink/ping**](./miscelaneous.md): Allows server to ping the device. This message is always published with `QOS 1`.
* [**downlink/reboot**](./miscelaneous.md): Instructs the device to reboot. This can be necessary for applying updates, resetting the device's state, or troubleshooting.
* [**downlink/redirect**](./authentication.md#server-redirect): Provides a new MQTT endpoint to which the device should connect. This is part of handling GeoDNS and ensuring the device connects to the most suitable server for improved performance and reliability.
* [**downlink/diag**](./miscelaneous.md): Server diagnostics messages.

## Uplink

These topics are used for messages sent from the device to Blynk.Cloud:

* [**info/mcu**](./authentication.md#firmware-and-device-info): Updates the server with device or firmware information. This is essential for device management and monitoring, allowing Blynk.Cloud to keep track of device types, versions, and other critical information.
* [**ds/`DATASTREAM`**](./datastreams.md): Updates the value of a specific datastream on the cloud. This is how sensor readings, state changes, or any other device-generated information are communicated to the server.
* [**ds/`DATASTREAM`/prop/`PROPERTY`**](./widget-properties.md): Sets a property of the widget associated with a datastream, allowing dynamic changes to how data is displayed or interacted with in the Blynk application.
* [**event/`EVENT`**](./events.md): Publishes an event, which can be used for alerts, emails, push notifications, logging, or triggering other server-side actions based on device activities.
* [**meta/`FIELD`**](./metadata.md): Updates a specific metadata field of the device. This can include configuration parameters, or any other contextual information about the device.
* [**get/ds**](./datastreams.md): Requests the current value of a specific datastream from Blynk.Cloud. This can be used to synchronize device state with server-side values.
* [**get/meta**](./metadata.md): Requests metadata values from Blynk.Cloud, useful for devices needing to confirm or update their configuration based on cloud-stored information.
* [**get/utc/all/json**](./timezone-location.md): Requests time-related information, assisting in time synchronization or scheduling tasks based on accurate time data.
* [**get/loc/all**](./timezone-location.md): Requests approximate location information, which can be used for location-based services, astronomical timers or contextual actions based on the device's location.
