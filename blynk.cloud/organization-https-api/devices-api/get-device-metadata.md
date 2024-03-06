# Get Device Metadata

{% swagger method="get" path="/api/v1/organization/device/metafield" baseUrl="https://{server_address}" summary="Get Device Metadata" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="query" name="deviceId" type="1" required="true" %}
Device identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Device Metadata" %}
```json
[
    {
        "id": 1,
        "name": "Device Name",
        "value": "My awesome device"
    },
    {
        "id": 2,
        "name": "Device Owner",
        "value": "user@example.com"
    }   
]
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/metafield?deviceId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/metafield?deviceId=1
```
