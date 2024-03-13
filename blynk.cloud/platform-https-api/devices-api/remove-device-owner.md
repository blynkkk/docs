# Remove Device Owner

{% swagger method="delete" path="/api/v1/organization/device/owner" baseUrl="https://{server_address}" summary="Remove Device Owner" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="deviceId" type="1" required="true" %}
Device identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="204: No Content" description="Device deleted" %}

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
$ curl -X DELETE -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/owner?deviceId=1
$ curl -X DELETE -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/owner?deviceId=1
```
