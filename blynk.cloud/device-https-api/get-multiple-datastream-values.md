# Get Multiple Datastream Values

{% swagger baseUrl="https://{server_address}" path="/external/api/get?token={token}&{pin}&{pinX}" method="get" summary="Get Multiple Datastream values" %}
{% swagger-description %}
In some cases it's important to get the datastream values with one call. This endpoint allows you to get the stored values of the multiple Datastreams. Returned type depends on the datastream type. **Example:**\
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
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}

{% swagger baseUrl="https://{server_address}" path="/external/api/getAll?token={token}" method="get" summary="Get All Datastreams values" %}
{% swagger-description %}
This endpoint allows you to get stored values of the all Datastreams by device token. The value(s) will be displayed in the response if the Datastream has a value.

**Example:**\
`https://blynk.cloud/external/api/getAll?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L`
{% endswagger-description %}

{% swagger-parameter in="query" name="token" type="string" required="true" %}
Device [auth token](../../concepts/device.md#authtoken) from Device info
{% endswagger-parameter %}

{% swagger-parameter in="path" name="{server address}" type="string" required="true" %}
Get from the bottom right of your Blynk console. [More information](troubleshooting.md).
{% endswagger-parameter %}

{% swagger-response status="200" description="Value successfully retrieved." %}
```
{
    "a0": 1,
    "a1": 1,
    "a2": 1,
    "a3": 1,
    "d0": 1,
    "d1": 1,
    "d2": 1,
    "d3": 0,
    "v0": 1,
    "v1": 1.0,
    "v2": "string",
    "v3": 1,
    "v4": [
        12.0,
        11.0
    ]
}
```
{% endswagger-response %}

{% swagger-response status="400" description="Could not find a device token" %}
```
{"error":{"message":"Invalid token."}}
```
{% endswagger-response %}
{% endswagger %}
