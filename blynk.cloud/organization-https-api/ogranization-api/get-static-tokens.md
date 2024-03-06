# Get Static Tokens

{% swagger method="get" path="/api/v1/organization/static-tokens" baseUrl="https://{server_address}" summary="Get Static Tokens" %}
{% swagger-description %}
Get a list of Static Tokens for the specified organization
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
Organization's identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Static tokens" %}
```json
{
   "content": [
      {
         "token": "sqr_yxzhvS6cuVTloK-7s1XIFb2ioAxh0Ofw",
         "orgId": 749,
         "productId": 525,
         "deviceToken": "32x_7Imf3kw8FDZwsMwJDy93dHGJ_iNq",
         "createdAt": 1703069573574,
         "status": "UNCLAIMED",
         "ownerId": 0,
         "deviceId": 0,
         "claimedOrgId": 0
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/static-tokens
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/static-tokens
```
