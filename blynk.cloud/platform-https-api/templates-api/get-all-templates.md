# Get All Templates

{% swagger method="get" path="/api/v1/organization/templates" baseUrl="https://{server_address}" summary="Get Organization Templates" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="page" type="0" %}
Page number starting from 0. First page by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="size" type="20" %}
Page size. Should be from 1 to 100. 20 by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="orgId" type="1" %}
Organization identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization templates" %}
```json
{
   "content": [
      {
         "id": 604,
         "templateIds": ["TMPL84aMXD6vd"],
         "parentId": 603,
         "orgId": 829,
         "name": "Default Product"
      }
   ],
   "totalElements": 1
}
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/templates
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/templates
```
