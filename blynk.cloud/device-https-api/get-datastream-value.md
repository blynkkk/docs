# Get Datastream Value

{% swagger baseUrl="https://{server_address}" path="/external/api/get?token={token}&{pin}" method="get" summary="Get Datastream value" %}
{% swagger-description %}
This endpoint allows you to get the stored value of the Datastream by pin type and pin.

\




**Example:**

\




`https://blynk.cloud/external/api/get?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&v1`
{% endswagger-description %}

{% swagger-parameter in="path" name="pin" type="string" %}
Virtual pin number (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
{% endswagger-parameter %}

{% swagger-response status="200" description="Value successfully retrieved." %}
```
100.00000
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
You can get the **Device auth token** in [Device info](../../getting-started/activating-devices/manual-device-activation.md#step-3-getting-auth-token).
{% endhint %}

{% swagger baseUrl="https://{server_address}" path="/external/api/get?token={token}&dataStreamId={id}" method="get" summary="Get Datastream value by Datastream ID" %}
{% swagger-description %}
This endpoint allows you to get the stored value of the Datastream by id.

\




**Example:**

\




`https://blynk.cloud/external/api/get?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&dataStreamId=1`
{% endswagger-description %}

{% swagger-parameter in="path" name="dataStreamId" type="integer" %}
Datastream Id
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
{% endswagger-parameter %}

{% swagger-response status="200" description="Value successfully retrieved." %}
```
100.00000
```
{% endswagger-response %}

{% swagger-response status="400" description="Could not find a device token
or
Typo in dataStreamID
or
Requested dataStream doesn't exist in the product ESP32 QA" %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Requested dataStream doesn't exist in the product ESP32 QA"}}
```
{% endswagger-response %}
{% endswagger %}
