# Get Actions Log

Use this endpoint to retrieve actions performed by users through the Blynk Dashboard, mobile application, Google Home, or Alexa. These actions can include controlling hardware or altering DataStream property values

{% swagger method="get" path="/api/v1/organization/device/logs" baseUrl="https://{server_address}" summary="Get Actions Log" %}
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

{% swagger-response status="200: OK" description="Device logs" %}
```json
{
  "content": [
    {
      "triggerUserEmail": "email@example.com",
      "value": 5.0,
      "pin": 1,
      "pinType": "VIRTUAL",
      "isOnline": false,
      "createdAt": 1702483099000
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/logs?deviceId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/logs?deviceId=1
```
