# Get Multiple Datastream Values

{% swagger baseUrl="https://{server_address}" path="/external/api/get?token={token}&{pin}&{pinX}" method="get" summary="Get Multiple Datastream values" %}
{% swagger-description %}
In some cases it's important to get the datastream values with one call. This endpoint allows you to get the stored values of the multiple Datastreams. Returned type depends on the datastream type. 

**Example:**

\




`https://blynk.cloud/external/api/get?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&v1&v2&v3&v4`
{% endswagger-description %}

{% swagger-parameter in="path" name="pin" type="string" %}
Virtual pin number (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
{% endswagger-parameter %}

{% swagger-response status="200" description="Value successfully retrieved." %}
```
{"v1":1.0,"v2":2,"v3":3,"v4":"string pin"}
```
{% endswagger-response %}

{% swagger-response status="400" description="Could not find a device token
or
Wrong pin format" %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}
```
{% endswagger-response %}
{% endswagger %}

{% hint style="info" %}
You can get the **Device auth token** in [Device info](../getting-started/activating-devices/manual-device-activation.md#step-3-getting-auth-token).
{% endhint %}
