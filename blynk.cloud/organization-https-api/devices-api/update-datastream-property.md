# Update Datastream Property

{% swagger method="post" path="/api/v1/organization/device/datastream/property" baseUrl="https://{server_address}" summary="Update Device DataStream Property Value" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="deviceId" type="1" required="true" %}
Device identifier.
{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="dataStreamId" type="1" required="true" %}
Device datastream identifier.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="property" type="color" required="true" %}
DataStream property name. See [Widget Properties](../../../blynk-library-firmware-api/widget-properties.md).
{% endswagger-parameter %}

{% swagger-parameter in="body" name="value" type="Some value" required="true" %}
Device datastream value.
{% endswagger-parameter %}

{% swagger-response status="204: No Content" description="Device datastream property value updated" %}

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

{% swagger-response status="404: Not Found" description="Datastream is not found" %}
```json
{
    "error": {
        "message": "Data stream with identifier 1 is not found!"
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
      -d '{"deviceId":1,"dataStreamId":1,"property":"color","value":"red"}' \
      https://fra1.blynk.cloud/api/v1/organization/device/datastream/property

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"dataStreamId":1,"property":"color","value":"red"}' \
      https://fra1.blynk.cloud/api/v1/organization/device/datastream/property
```
