# Get Organization Tags

{% swagger method="get" path="/api/v1/organization/tags" baseUrl="https://{server_address}" summary="Get Tags" %}
{% swagger-description %}
Get a list of tags for specified organization
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="orgId" type="1" %}
Organization's identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Tags" %}
```json
[
   {
      "id": 14,
      "name": "My Tag Name",
      "ownerUserId": 1133
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/tags
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/tags
```
