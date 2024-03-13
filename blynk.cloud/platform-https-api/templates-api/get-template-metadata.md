# Get Template Metadata

{% swagger method="get" path="/api/v1/organization/template/metafields" baseUrl="https://{server_address}" summary="Get Template Metadata" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="templateId" type="1" required="true" %}
Organization template identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization template metafields" %}
```json
[
   {
      "id": 1,
      "name": "Device Name",
      "type": "DeviceName",
      "description": "Device name",
      "hint": "Default metafield",
      "icon": "icon_name"
   },
   {
      "id": 2,
      "name": "Device Owner",
      "type": "DeviceOwner",
      "description": "Device Owner Email"
   },
   {
      "id": 3,
      "name": "Custom Meta Field",
      "type": "Text",
      "description": "Some custom meta field"
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/template/metafields?templateId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/template/metafields?templateId=1
```
