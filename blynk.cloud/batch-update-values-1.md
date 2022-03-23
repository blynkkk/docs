---
description: >-
  If you need your values to have the timestamp you can use the following API
---

# Single Datastream batch update with timestamps

{% swagger baseUrl="https://{server_address}" path="/external/api/batch/update?token={token}&pin={pin}" method="post" summary="Batch update with timestamps" %}
{% swagger-description %}
Updates single datastream with multiple values with timestamps using JSON compact format. This API could be used for the use case when the device gathers the data while it has no connection to the server. Currently, you can import in total 100k points per device, you can do it in 1 batch or you can split it into multiple batches (this limit will be changed based on the plans soon).

The single entry format: `[timestamp, value].` Where `timestamp` - the difference, measured in **milliseconds**, between the current time and midnight, January 1, 1970 UTC. It's the same as "Unix Epoch" or "Unix timestamp" **multiplied by 1000 ms**.

The full body is the array of entries: `[[timestamp1, value1], [timestamp2, value2]]`.

`Content-Type` header with `application/json` value is mandatory.

\
**Example:**\
`https://blynk.cloud/external/api/batch/update?token=bFFtSHNCZZDWQ__Zs96cP5jLMhLoJofg&pin=v1`

Post body:

`[`&#x20;

&#x20;     `[1648054765458,1.0],`

&#x20;     `[1648054825459,2.0],`

&#x20;     `[1648054885460,3.0]`

`]`
{% endswagger-description %}

{% swagger-parameter in="header" name="Content-Type" type="String" required="false" %}
application/json
{% endswagger-parameter %}

{% swagger-parameter in="query" name="token" type="String" required="false" %}
Device AuthToken
{% endswagger-parameter %}

{% swagger-parameter in="query" name="pin" type="String" required="false" %}
Virtual Pin
{% endswagger-parameter %}

{% swagger-response status="200" description="Success" %}
```
OK
```
{% endswagger-response %}

{% swagger-response status="400: Bad Request" description="Could not find a device token or Wrong pin format or Too much data in batch. Maximum batch size is 10000 points." %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Too much data in batch. Maximum batch size is 10000 points."}}
```
{% endswagger-response %}
{% endswagger %}
