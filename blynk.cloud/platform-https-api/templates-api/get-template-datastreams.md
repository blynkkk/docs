# Get Template Datastreams

{% swagger method="get" path="/api/v1/organization/template/datastreams" baseUrl="https://{server_address}" summary="Get Template Datastreams" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="templateId" type="1" required="true" %}
Organization template identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization template datastreams" %}
```json
[
   {
      "id": 1,
      "label": "DS 1",
      "alias": "DS 1",
      "units": "Celsius",
      "type": "INT",
      "defaultValue": 5,
      "pin": 1,
      "pinType": "VIRTUAL"
   }
]
```
{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Organization template is not found" %}
```json
{
    "error": {
        "message": "Template is not found or you don't have access to it."
    }
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/template/datastreams?templateId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/template/datastreams?templateId=1
```
