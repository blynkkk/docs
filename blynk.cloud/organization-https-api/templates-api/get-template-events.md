# Get Template Events

{% swagger method="get" path="/api/v1/organization/template/events" baseUrl="https://{server_address}" summary="Get Template Events" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="templateId" type="1" required="true" %}
Organization template identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization template Events" %}
```json
[
   {
      "id": 1,
      "type": "INFORMATION",
      "name": "Event 1",
      "eventCode": "event_1"
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/template/events?templateId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/template/events?templateId=1
```
