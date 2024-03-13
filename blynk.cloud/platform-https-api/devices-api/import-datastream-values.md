# Import Datastream Values

This feature enables you to import historical data for a device's datastream. It's useful for scenarios where data isn't streamed in real-time but is instead collected on the device and sent periodically as a dataset.&#x20;

For instance, if your device is usually offline and only connects intermittently to upload a batch of data points.

{% hint style="warning" %}
A maximum of 10,000 data points per device per day is allowed, regardless of whether the data is sent in multiple sets or in one batch.&#x20;

This limit may vary depending on your subscription plan and is consistent with the [Upload a Set of Timestamped Data](../../device-https-api/upload-set-of-data-with-timestamps-api.md) endpoint in the Device HTTPS API.
{% endhint %}

{% swagger method="post" path="/api/v1/organization/device/import/batch" baseUrl="https://{server_address}" summary="Import DataStream Values" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="deviceId" type="1" required="true" %}
Device identifier.
{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="dataStreamId" type="1" required="true" %}
Device datastream identifier.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="values" type="" required="true" %}
Datastream values to import.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="values[x].value" type="1" required="true" %}
Datastream value.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="values[x].ts" required="true" %}
Unix epoch time in milliseconds representing datastream value creation time.

**Note:** Timestamps could be only one month in the past. Older timestamps won't be accepted.
{% endswagger-parameter %}

{% swagger-response status="204: No Content" description="Device datastream value updated" %}

{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Device is not found" %}
```json
{
    "error": {
        "message": "Device with identifier 1 is not found or belong to another organization."
    }
}
```
{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Datastream is not found" %}
```json
{
    "error": {
        "message": "Data stream with identifier 1 is not found!"
    }
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"deviceId":1,"dataStreamId":1,"values":[{"value":5,"ts":1702656423136},{"value":2,"ts":1702656428136}]}' \
      https://fra1.blynk.cloud/api/v1/organization/device/import/batch

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"dataStreamId":1,"values":[{"value":5,"ts":1702656423136},{"value":2,"ts":1702656428136}]}' \
      https://fra1.blynk.cloud/api/v1/organization/device/import/batch
```
