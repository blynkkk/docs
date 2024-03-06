# Get Datastream Historical Data

In order to use this API you must enable raw data saving for the datastream.

{% swagger method="get" path="/api/v1/organization/device/datastream/history" baseUrl="https://{server_address}" summary="Get Device DataStream History" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="page" type="0" %}
Page number starting from 0. First page by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="size" type="20" %}
Page size. Should be from 1 to 100. 20 by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="deviceId" type="1" required="true" %}
Device identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="pin" type="v1" required="true" %}
Pin name.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="from" required="false" %}
Filter device data stream history from the specified time. Should be a valid unix epoch time in milliseconds.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="to" %}
Filter device data stream history up to the specified time. Should be a valid unix epoch time in milliseconds.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Device datastream history" %}
```json
{
  "content": [
    {
      "createdAt": 1702483099000,
      "value": 5
    }
  ],
  "totalElements": 1
}
```
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
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/datastream/history?deviceId=1&pin=v1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/datastream/history?deviceId=1&pin=v1
```
