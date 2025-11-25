---
description: Optimizing Message Usage in Blynk
---

# Message Usage

### Understanding Message Counting in Blynk

Blynk's message counter is updated whenever a command or communication event occurs. This includes:

* Executing Blynk commands like `Blynk.virtualWrite`, `Blynk.setProperty`, etc.
* Any MQTT publish message
* Any External API request
* Each uplink event in integrations

Each of these actions consumes a message, which contributes to the monthly quota.

### Strategies for Optimizing Message Usage

To reduce message consumption and optimize efficiency, consider the following strategies:

#### 1. Batch Updates for Datastreams

Instead of sending multiple individual updates, batch updates allow you to send multiple datastream values at once, which is counted as a single message. This can be done via:

* [Blynk Cloud MQTT API - Batched Data](blynk.cloud/device-mqtt-api/datastreams.md#send-batched-data-to-blynk)
* [Blynk Cloud HTTP API - Multiple Datastream Updates](blynk.cloud/device-https-api/update-multiple-datastreams-api.md)

**How to do it with the HTTP API:** Instead of sending separate HTTP request for each sensor reading, bundle multiple sensor values into a single batched update. This can be done by passing multiple values in a single HTTP request body call:

```
GET https://blynk.cloud/external/api/batch/update?token={token}&v1=32.5&v2=63
```

This approach allows updating multiple datastreams in one message, reducing message consumption. Each value corresponds to a different datastream, meaning you can efficiently send updates for several readings at once.&#x20;

#### 2. Uploading Historical Data with Timestamps

If your application doesn't stream data in real-time, but collects it over time and needs to send it to Blynk in bulk, use the [Upload Set of Data with Timestamps API](blynk.cloud/device-https-api/upload-set-of-data-with-timestamps-api.md). This method allows sending multiple values for a single datastream, efficiently handling historical data.

**Limitations:**

* Large payloads should be broken into reasonable chunks.
* Historical data must be sent per datastream; if multiple datastreams require updates, multiple requests are needed.

#### 3. Finding the Right Update Frequency

Balance between real-time updates and message efficiency by choosing an optimal update frequency:

* **Real-time applications:** Use batch updates to minimize individual messages.
* **Historical or periodic updates:** Instead of sending continuous real-time data, schedule updates at reasonable intervals to reduce message usage but still have full historical data in between updates.
* **Avoid excessive granularity:** If monitoring trends that do not change rapidly, reduce the update frequency to reflect meaningful variations. For example, sending updates every 15 minutes instead of every second can significantly lower message consumption while still providing useful insights.

### Key Takeaways

* **Batch updates** minimize message count by grouping multiple datastream updates into one request.
* **Timestamped historical data uploads** are best for bulk sending past readings but require separate requests per datastream.
* **Choose optimal update frequencies** to balance real-time needs and message efficiency.
* **Break large data loads** into manageable sizes.

By following these strategies, you can optimize message usage while ensuring your Blynk application remains responsive and cost-effective.

<br>
