# Update Multiple Datastreams Simultaneously

Update multiple Datastreams of a single device with one GET request. It can help with saving the data volume for cellular devices.

{% hint style="warning" %}
Use such update for Map Widget in Blynk.Console so that all datapoints have same timestamp for data and coordinates.
{% endhint %}

## Batch update

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/batch/update?token={token}&{pin1}={value1}&{pin2}={value2}`

\{% swagger-response status="400" description="Could not find a device token or Wrong pin format or Value doesn't match the Datastream data type" %\}

```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Value doesn't match the Datastream data type"}}
```

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}

You can also use Blynk.Edgent API to [send data with the same timestamp](../../blynk-library-firmware-api/virtual-pins.md#blynk.begingroup-blynk.endgroup).
