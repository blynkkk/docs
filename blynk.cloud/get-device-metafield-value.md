# Get Device Metadata Value

You can get the value of any single-value (text, number, email, hostspot, device name, list, int, imei, image, iccid, device owner email) device meta field using it **exact name** (case sensitive).

**loc.latlon** is special hardcoded internal meta field to get device location "lat lon".

{% swagger baseUrl="https://{server_address}" path="/external/api/device/meta?token={token}&metaFieldId={metaFieldId}" method="get" summary="Get Device Metafield Value" %}
{% swagger-description %}
This endpoint allows you to get the device metaField value by its id.

\




**Example:**

\




`https://blynk.cloud/external/api/device/meta?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&metaFieldId=1`
{% endswagger-description %}

{% swagger-parameter in="path" name="metaFieldId" type="string" %}
MetaField id.
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
{% endswagger-parameter %}

{% swagger-response status="200" description="Value successfully retrieved." %}
```
{"type":"Text","value":"device value"}
```
{% endswagger-response %}

{% swagger-response status="400" description="Could not find a device token
or
Wrong metaField format or Could not find metaField id" %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong metaField format."}}

or

{"error":{"message":"MetaField doesn't exist."}}
```
{% endswagger-response %}
{% endswagger %}

{% hint style="info" %}
You can get the **Device auth token** in [Device info](../getting-started/activating-devices/manual-device-activation.md#step-3-getting-auth-token).
{% endhint %}
