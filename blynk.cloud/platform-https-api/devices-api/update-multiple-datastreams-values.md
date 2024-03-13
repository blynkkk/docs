# Update Multiple Datastreams Values

{% swagger method="post" path="/api/v1/organization/device/datastreams" baseUrl="https://{server_address}" summary="Update Multiple Datastreams Values" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="deviceId" type="1" required="true" %}
Device identifier.
{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="values" type="{"1":5}" required="true" %}
Map with datastream identifier as a key and datastream value as a value.
{% endswagger-parameter %}

{% swagger-response status="204: No Content" description="Device datastream values updated" %}

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
$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"deviceId":1,"values":{"1":5,"2":"new value"}}' \
      https://fra1.blynk.cloud/api/v1/organization/device/datastreams

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"values":{"1":5,"2":"new value"}}' \
      https://fra1.blynk.cloud/api/v1/organization/device/datastreams
```
