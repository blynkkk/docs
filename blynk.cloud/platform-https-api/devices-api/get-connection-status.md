# Get Connection Status

{% swagger method="get" path="/api/v1/organization/device/online" baseUrl="https://{server_address}" summary="Get Device Connection Status" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="deviceId" type="1" required="true" %}
Device identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Device status" %}
```json
{
  "connected": true
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/online?deviceId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/online?deviceId=1
```
