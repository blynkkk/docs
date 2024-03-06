# Get Organization Automations

{% swagger method="get" path="/api/v1/organization/automations" baseUrl="https://{server_address}" summary="Get Automations" %}
{% swagger-description %}
Get a list of Automations for the specified organization
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="orgId" type="1" %}
Organization's identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Automations" %}
```json
[
   {
      "id": 2,
      "name": "My Automation",
      "ownerId": 1133,
      "isActive": true
   }
]
```
{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Organization is not found" %}
```json
{
    "error": {
        "message": "Organization with identifier 1 is not found or you don't have access to it."
    }
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/automations
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/automations
```
