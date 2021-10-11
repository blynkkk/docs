---
description: >-
  If you need your values to have the same timestamp you can use the following
  format
---

# Batch Update of the Datastreams

{% swagger baseUrl="https://{server_address}" path="/external/api/batch/update?token={token}&{pin1}={value1}&{pin2}={value2}" method="get" summary="Batch update" %}
{% swagger-description %}
Updates multiple datastreams with one GET request. It could be used to save network bandwidth. Also, the batch update is required to show multiple datastreams in the map widget popup.

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
