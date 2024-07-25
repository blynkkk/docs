---
description: Create a template, set up the integration and import your first device
---

# Getting Started

The easiest way to prototype a device on Blynk and correctly configure the integration is to use a device that is already [connected to The Things Network](https://www.thethingsindustries.com/docs/devices/adding-devices/). Once the device is connected and successfully goes online, [create a new template on Blynk](../../getting-started/template-quick-setup/) for this device. Once you have created a new template, navigate to the **Developer Zone -> Integrations -> The Things Network**. Click the "**+ Add**" button and select the template you previously created.

<figure><img src="../../.gitbook/assets/add-application.png" alt="" width="563"><figcaption><p>Create a new The Things Network Application on Blynk</p></figcaption></figure>

In the application settings, fill in The Things Network hostname, username, and password. To [obtain the credentials](https://www.thethingsindustries.com/docs/integrations/mqtt/#creating-an-api-key), navigate to the application page you wish to connect on The Things Network. Click on the **Integrations** button in the left sidebar and select **MQTT**. Copy the Public TLS address under the MQTT server host section and paste it into Blynk (if you are going to use non-TLS MQTT address, change the switch to "**Insecure**"). Then, copy the username from the page and paste it into Blynk. After that, click on the "**Generate new API key**" button, copy the password, and paste it into Blynk.

<div data-full-width="false">

<figure><img src="../../.gitbook/assets/Снимок экрана 2024-07-18 в 16.36.27.png" alt=""><figcaption><p>Capturing the credentials from The Things Network</p></figcaption></figure>

</div>

Click the "**Connect**" button at the bottom of the application card on Blynk. You will see the integration status change to "**Connected**".

{% hint style="info" %}
At this point, the metadata for _TheThingsNetwork Device_ will be created in the template if it wasn't created before. Blynk uses this metadata to identify each device in The Things Network application.
{% endhint %}

<figure><img src="../../.gitbook/assets/the-things-network-application-connected (1).png" alt="" width="563"><figcaption><p>The Things Network Integration Page with a Connected Application</p></figcaption></figure>

Once this is done, Blynk will automatically create the device connected to The Things Network as soon as it sends any data. This device will then be available on the [Devices page](../../blynk.console/devices/).

## Sending uplink and downlink messages

Once your first device is connected to Blynk, it's time to transfer some data! Start by configuring [the Payload formatter on The Things Network](https://www.thethingsindustries.com/docs/integrations/payload-formatters/).

### Uplink

For uplinks, Blynk requires the data to be in _key-value_ pair format, where the _key_ is either the datastream name or pin (such as `v1` or `a10`) and the _value_ is the datastream value. The value type must match the datastream value type! Here is an example of the decoded uplink:

```json
{
  "temperature": 24.1,
  "humidity": 54
}
```

In this example, Blynk will set the datastream with the name "temperature" to the value 24.1 and the datastream with the name "humidity" to the value 54. The datastreams configuration for this example may look like this:

<figure><img src="../../.gitbook/assets/Снимок экрана 2024-07-18 в 16.37.27.png" alt=""><figcaption><p>The datastreams configuration for the uplink and downlink examples</p></figcaption></figure>

{% hint style="info" %}
Each time Blynk receives an update from the device, it will trigger the Online lifecycle event. Therefore, it is recommended [to configure a meaningful wait time](../../blynk.console/templates/connection-lifecycle.md) to prevent your device from being stuck in the offline state.
{% endhint %}

### Downlink

For each datastream update via the web dashboard, mobile application, automation, etc., Blynk will send a separate downlink to the device. Here is an example of the downlink that Blynk will send to the device, indicating that the datastream with the name "speed" (pin `v2`) has been updated to the value `3`:

```json
{
  "name": "speed",
  "pin": "v2",
  "ts": 1721202415068,
  "value": 3
}
```

The `ts` field represents the timestamp in Unix milliseconds format when the value was actually updated.

## Application Statuses

Each application has its own status, representing its current state:

* **Not Connected**: This initial status indicates that the application has not been saved yet. Therefore, Blynk has not yet connected to the application, and the integration will not work. This status also applies when Blynk initially fails to connect to The Things Network with the specified parameters.
* **Connected**: This status represents the normal state of the integration. Everything should operate normally in this status.
* **Broken**: This status indicates a problem related to the application. Possible issues include Blynk failing to establish a connection with The Things Network server (e.g., due to a server restart), invalid credentials, or an internal error on The Things Network. In this status, Blynk will periodically try to reconnect to The Things Network server to fix the integration. Once the integration operates normally, Blynk will automatically change the status to _Connected_.
