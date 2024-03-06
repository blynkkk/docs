---
description: Use this endpoint to get events, that has been triggered by device.
---

# Get Device Timeline Log

{% swagger method="get" path="/api/v1/organization/device/timeline" baseUrl="https://{server_address}" summary="Get Device Timeline" %}
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

{% swagger-parameter in="query" name="eventType" type="INFORMATION" required="false" %}
Event type name to filter timeline by. All event types will be included, if not specified.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Device Timeline" %}
```json
{
   "content": [
      {
         "id": 1,
         "eventId": 1,
         "orgId": 577,
         "eventType": "INFORMATION",
         "description": "A simple information event",
         "ts": 879,
         "isResolved": false,
         "resolvedAt": 1702480430139,
         "resolvedComment": null
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/timeline?deviceId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/timeline?deviceId=1
```
