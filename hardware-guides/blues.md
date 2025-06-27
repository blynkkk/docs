---
description: The integration guide with Blues
---

# Blues

[Blues](https://blues.com/) is a hardware manufacturer that specializes in IoT connectivity solutions, offering efficient, secure, and low-power data communication. Their tools enable developers to integrate cellular IoT functionality into devices with minimal coding and setup, streamlining global data transmission.

Blynk offers built-in integration with Blues, enabling seamless data visualization, downlink scheduling, lifecycle status monitoring, and simplified device provisioning, along with other advanced features.

### How to Connect Blues Devices to Blynk

This guide walks you through connecting your Blues-enabled devices (via Notehub) to Blynk’s IoT platform using the built-in integration — from setting up credentials to routing data and provisioning devices.

#### 1. Get Your Notehub API Credentials

In your [Notehub](https://notehub.io/) project:

* Navigate to **Settings** → **Programmatic API Access**
* Click **Generate Programmatic Access** to create a Client ID and Client Secret. Copy both values.
* Click “Save” — this is required for the credentials to be active. Without saving, Blynk will not be able to authenticate.

<figure><img src="../.gitbook/assets/Снимок экрана 2024-08-26 в 13.47.41.png" alt=""><figcaption><p>Notehub Project settings page</p></figcaption></figure>

#### 2. Create a Template in Blynk Console

In the Blynk Console:

* Go to **Developer Zone** → **My Templates**.
* Click New Template.
* Choose Blues as the hardware type.
* Set the connection type (WiFi, Cellular, or Any).
* Add datastreams that match the keys your device sends via Notehub.

<figure><img src="../.gitbook/assets/Снимок экрана 2024-08-26 в 14.28.05.png" alt=""><figcaption><p>Template datastreams configuration example</p></figcaption></figure>

> Each template is mapped to [a Notehub ProductUID](https://dev.blues.io/api-reference/glossary/#productuid) to group common devices.&#x20;

Blynk will attempt to map all keys from all Notefiles to corresponding datastreams. For downlinks, Blynk will send a `blynk.qi` [Notefile](https://dev.blues.io/api-reference/glossary/#notefile) with the datastream name as the key. Below is an example of the Notefile body that Blynk will create:

```json
{
  "coffee_strength": 3,
  "idle": false,
  "state": "Working",
  "location": [-73.935242, 40.730610]
}
```

{% hint style="success" %}
Use the ['Log when device reports any data'](../blynk.console/templates/connection-lifecycle.md#log-when-device-reports-any-data) feature in Connection Lifecycle tab to mark the device as online with each uplink received from Blues.
{% endhint %}

After finishing the template configuration, save it.



#### 3. Authorize the Blues Integration in Blynk Console

In the Blynk Console:

* Go to **Developer Zone** → **Integrations** → **Blues**.
* Paste the Client ID and Client Secret you copied from Notehub.
* Click Connect.

This authorizes Blynk to access your Notehub project and fetch your ProductUIDs.

<figure><img src="../.gitbook/assets/Снимок экрана 2024-08-26 в 13.48.20.png" alt=""><figcaption><p>Blynk integrations page</p></figcaption></figure>



#### 4. Map Your Template to a ProductUID

In the Blynk Console still in the Blues Integration screen:

* Locate the ProductUID for your Notehub project.
* In the Blynk Template column, select the template you created.
* Click Add.

<figure><img src="../.gitbook/assets/Снимок экрана 2024-08-26 в 14.21.21.png" alt=""><figcaption><p>Blues Integration page</p></figcaption></figure>

> At this point, the _Blues Device_ metafield will be created in the template if it wasn't created before. Blynk uses this metadata to identify each device in the Notehub.

If your Notehub project already has devices **click the import icon in the Actions column** to bring them into Blynk.



#### 5. Enable the Blynk Route in Notehub

In your Notehub project:

* Go to **Routes** → **Create Route**.
* Select Blynk from the list of integrations.

<figure><img src="../.gitbook/assets/blynk-route-creation-notehub.png" alt=""><figcaption><p>Blynk Route creation on Notehub</p></figcaption></figure>

* Select the correct Blynk region — this must match the region in your Blynk Console URL.

<figure><img src="../.gitbook/assets/blynk-region.png" alt=""><figcaption><p>You can find the Blynk region at the bottom right of the Blynk Console</p></figcaption></figure>

* Confirm the route.



## Device provisioning

At this stage, your integration is active and ready to receive data.

If you don’t have any devices connected in Notehub — or don’t need to import existing ones — you can provision Blues devices directly in Blynk.

This can be done manually one-by-one or at scale.

### **Option 1: Manual Provisioning**

To provision a device using Blynk, create it manually in Blynk Console and configure the Blues Device ID metafield:

1. In the Blynk Console, navigate to **Devices** -> **+ New Device** -> **From Template**.
2. Select the template and give the device a meaningful name.
3. Open the **Info & Metadata** page and enter the Blues Device ID in the **Blues Device** field.

Once you save the value, Blynk will automatically create the device in your Notehub project.

<figure><img src="../.gitbook/assets/Снимок экрана 2024-08-26 в 14.42.28.png" alt=""><figcaption><p>Configuring a Blues Device ID manually</p></figcaption></figure>

### **Option 2:** Mass device provisioning with Static Tokens

To simplify device provisioning for end-users, you can use Static Tokens:

1.  Create a CSV file with Blues Device IDs listed in each row. For example:

    ```csv
    Blues Device
    dev:951624746484292
    dev:869120174936381
    ```
2. Navigate to **Developer Zone** -> **Static Tokens** -> **+ Generate Static Tokens** -> **Create From File**. Select the template and upload the file.
3. Map the row with Blues Device IDs to the Blues Device metafield and click **Create**.

Blynk will generate one static token and QR code per row. These can be scanned in the Blynk Mobile App or registered in the Console, which will automatically create devices in both Blynk and Notehub.



## Next steps

With a configured Blynk template and a working device, you can now start creating a [Web Dashboard](../blynk.console/templates/dashboard/) and [Mobile application](../blynk.apps/constructor.md).

Next, take advantage of other powerful Blynk features, such as [Automations](../concepts/automations.md), [WebHooks](../blynk.console/settings/developers/webhooks.md), [Device Connection Lifecycle](../concepts/connection-lifecycle-management/), and the [Device HTTPS API](../blynk.cloud/device-https-api/), to build more advanced workflows.
