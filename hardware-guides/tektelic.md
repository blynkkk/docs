# TEKTELIC

**TEKTELIC** is a hardware manufacturer that specializes in end-to-end LoRaWAN® IoT connectivity solutions, offering a broad portfolio of carrier-grade gateways, sensors, and devices built for reliable, long-life deployments. Their solutions enable developers and organizations to integrate LoRaWAN functionality across a wide range of industries and environments with minimal setup, streamlining wireless data transmission at scale.

### How to Connect TEKTELIC Devices to Blynk

This guide walks you through connecting your TEKTELIC devices (via TTN) to Blynk's IoT platform using the native cloud-to-cloud integration — from setting up credentials to routing data and provisioning devices.&#x20;

### 1. Register the Sensor on The Things Stack (TTN)

Before Blynk can see your data, the sensor must be authorized on TTN.

* **Create an Application:** Log in to your TTN Console, go to **Applications**, and click **+ Create application**.
* **Register End Device:**
  * **Brand:** Select `TEKTELIC Communications Inc.`
  * **Model:** Select your specific sensor.
  * **Hardware/Firmware Version:** Choose the latest available.
  * **Join Settings:** Enter the `DevEUI`, `JoinEUI` (AppEUI), and `AppKey` found on the sticker or the commissioning sheet provided by TEKTELIC.
* **Payload Formatter:** Since you selected the device from the repository, TTN should automatically apply the correct JavaScript formatter. This converts the raw hex payload into readable JSON like `{"leak_detected": true}`.

***

### 2. Configure the Blynk Template

Blynk needs a "blueprint" to understand the data coming from TTN.

{% hint style="warning" %}
The number and types of Datastreams you need to create will depend on the specific sensor you are connecting. In this example, we use a TEKTELIC leak detection sensor as a reference setup.
{% endhint %}

* **Create Template:** In the Blynk Console, go to **Developer Zone → My Templates → New Template**. Give it a name like `TEKTELIC Leak Sensor`.
* **Leak Status:** Create a Datastream on Virtual Pin `V1`, Data Type: `Integer` (0 for dry, 1 for leak).
* **Battery Voltage:** Create a Datastream on Virtual Pin `V2`, Data Type: `Double`.
* **Temperature/Humidity:** _(If supported by your model)_ Create corresponding Datastreams.
* **Web/Mobile Dashboard:** Drag and drop a **LCD** or **Value Display** widget and link it to your Virtual Pins.

{% hint style="info" %}
Datastream names must match the JSON keys produced by the TTN Payload Formatter exactly (e.g., `leak_detected` vs `moisture_detected`).
{% endhint %}

***

### 3. Set Up the TTN Integration in Blynk

This is the bridge that links the two clouds.

1. **Add Integration:** In the Blynk Console, go to **Developer Zone → Integrations → The Things Stack** and click **+ Add**.
2. **Authentication:** Enter the MQTT credentials from your TTN Application:
   * **Public Address:** e.g., `eu1.cloud.thethings.network`
   * **Username:** Your TTN Application ID
   * **Password:** A generated API Key from the TTN Console (**Integrations → MQTT**)
3. Click **Connect**. The status should change to **Connected**.

***

### 4. Trigger the Sensor

Once configured, pull the battery tab on your TEKTELIC sensor.

* **In TTN:** Check the **Live Data** tab. You should see a `Join Request` followed by an `Uplink`.
* **In Blynk:** As soon as the first uplink arrives, Blynk will automatically provision the device if you enabled **Automated Onboarding**. The values on your dashboard should update instantly.

<br>
