# Update Multiple Datastreams Simultaneously

Update multiple Datastreams of a single device with one GET request. It can help with saving the data volume for cellular devices.

{% hint style="warning" %}
Use such update for Map Widget in Blynk.Console so that all datapoints have same timestamp for data and coordinates.
{% endhint %}

{% swagger baseUrl="https://{server_address}" path="/external/api/batch/update?token={token}&{pin1}={value1}&{pin2}={value2}" method="get" summary="Batch update" %}
{% swagger-description %}
This operation updates multiple Datastreams of a single device with one GET request.

\




\




**Example:**

\




`https://blynk.cloud/external/api/batch/update?token=bFFtSHNCZZDWQ__Zs96cP5jLMhLoJofg&v1=33&v2=44`
{% endswagger-description %}

{% swagger-parameter in="path" name="token" type="string" %}
Device AuthToken
{% endswagger-parameter %}

{% swagger-parameter in="path" name="pin" type="string" %}
Virtual Pin
{% endswagger-parameter %}

{% swagger-parameter in="path" name="value" type="string" %}
The desired value of the Datastream. Will be parsed based on the Datastream data type (int, double, string) and bounded with min / max values of datastream settings. In case value doesn't match the Datastream type error will be returned.
{% endswagger-parameter %}

{% swagger-response status="200" description="Success" %}
```
OK
```
{% endswagger-response %}

{% swagger-response status="400" description="Could not find a device token
or
Wrong pin format
or
Value doesn't match the Datastream data type" %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Value doesn't match the Datastream data type"}}
```
{% endswagger-response %}
{% endswagger %}

{% hint style="info" %}
You can get the **Device auth token** in [Device info](../../getting-started/activating-devices/manual-device-activation.md#step-3-getting-auth-token).
{% endhint %}

You can also use Blynk.Edgent API to [send data with the same timestamp](../../blynk-library-firmware-api/virtual-pins.md#blynk.begingroup-blynk.endgroup).
