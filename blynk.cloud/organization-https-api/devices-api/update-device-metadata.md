# Update Device Metadata

{% swagger method="post" path="/api/v1/organization/device/metafield" baseUrl="https://{server_address}" summary="Update Device Metadata" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="deviceId" type="1" required="true" %}
Device identifier.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="metaFieldId" type="1" required="true" %}
MetaField identifier.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="newValue" type="New Value" required="true" %}
New metafield string value.
{% endswagger-parameter %}

{% swagger-response status="204: No Content" description="Device metadata updated" %}

{% endswagger-response %}

{% swagger-response status="400: Bad Request" description="Invalid metadata value" %}
```json
{
    "error": {
        "message": "The provided value for metafield is invalid."
    }
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

{% swagger-response status="404: Not Found" description="Metadata is not found" %}
```json
{
    "error": {
        "message": "Meta field is not found."
    }
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"deviceId":1,"metaFieldId":1,"newValue":5}' \
      https://fra1.blynk.cloud/api/v1/organization/device/metafield

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"metaFieldId":1,"newValue":5}' \
      https://fra1.blynk.cloud/api/v1/organization/device/metafield
```
