# Update Datastream Value

{% swagger baseUrl="https://{server_address}" path="/external/api/update?token={token}&{pin}={value}" method="get" summary="Update the Datastream value" %}
{% swagger-description %}
This endpoint allows you to update the value of the Datastream value via GET request.

\




**Example:**

\




`https://blynk.cloud/external/api/update?token=ffujYGgbf805tgsf&v1=100`
{% endswagger-description %}

{% swagger-parameter in="path" name="value" type="string" %}
The desired value of the Datastream. Will be parsed based on the Datastream data type (int, double, string) and bounded with min / max values of datastream settings. In case value doesn't match the Datastream type error will be returned.
{% endswagger-parameter %}

{% swagger-parameter in="path" name="pin" type="string" %}
Virtual pin number (should start with "v")
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
{% endswagger-parameter %}

{% swagger-response status="200" description="Success" %}
```
```
{% endswagger-response %}

{% swagger-response status="400" description="Could not find a device token or Wrong pin format or Value doesn't match the Datastream data type or No datastream setup for that pin" %}
```
{"error":{"message":"Invalid token."}}
or
{"error":{"message":"Wrong pin format."}}
or
{"error":{"message":"Value doesn't match the Datastream data type"}}
or
{"error":{"message":"No datastream setup for that pin."}}
```
{% endswagger-response %}
{% endswagger %}

{% swagger baseUrl="https://{server_address}" path="/external/api/update?token={token}&dataStreamId={id}&value={value}" method="get" summary="Update value by Datastream ID" %}
{% swagger-description %}
This endpoint allows you to update the value of the Datastream value via GET request.

\




**Example:**

\




`https://blynk.cloud/external/api/update?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&dataStreamId=1&value=100`
{% endswagger-description %}

{% swagger-parameter in="path" name="value" type="string" %}
The desired value of the Datastream. Will be parsed based on the Datastream data type (int, double, string) and bounded with min / max values of datastream settings. In case value doesn't match the Datastream type error will be returned.
{% endswagger-parameter %}

{% swagger-parameter in="path" name="dataStreamId" type="integer" %}
Datastream Id
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
{% endswagger-parameter %}

{% swagger-response status="200" description="Success" %}
```
```
{% endswagger-response %}

{% swagger-response status="400" description="Could not find a device token
or
Wrong dataStreamId format
or
Value doesn't match the Datastream data type" %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong dataStreamId format."}}

or

{"error":{"message":"Value doesn't match the Datastream data type"}}
```
{% endswagger-response %}
{% endswagger %}
