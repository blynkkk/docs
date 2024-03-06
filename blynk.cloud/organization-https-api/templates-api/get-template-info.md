# Get Template Info

{% swagger method="get" path="/api/v1/organization/template" baseUrl="https://{server_address}" summary="Get Organization Template" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="templateId" type="1" required="true" %}
Organization template identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization template" %}
```json
{
   "id": 605,
   "templateIds": ["TMPL84aMXD6vd"],
   "parentId": 604,
   "orgId": 830,
   "name": "Dev tempalte",
   "boardType": "ESP8266",
   "connectionType": "WI_FI",
   "description": "Template, that is being used for development",
   "logoUrl": "https://blynk.cloud/tempalte_image.png",
   "createdAt": 1703082519534
}
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/template?templateId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/template?templateId=1
```
