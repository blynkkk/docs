# Search Organizations

{% swagger method="get" path="/api/v1/organization/search" baseUrl="https://{server_address}" summary="Search Organizations" %}
{% swagger-description %}
`sortBy` query parameter could accept the following values: `Organization Id`, `Name`, `Device Count`, `User Count`, `Sub Organizations` (stands for sub-organizations count).
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="query" type="string" required="true" %}
Search query. Should be up to 255 symbols.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="page" type="integer" %}
Page number starting from 0. First page by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="size" type="integer" %}
Page size. Should be from 1 to 100. 20 by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="sortBy" type="string" %}
Field to sort result by.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="sortOrder" type="string" %}
Sorting order. Can be `ASC` (ascending) or `DESC` (descending). `ASC` by default.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organizations" %}
```json
{
   "content": [
      {
         "id": 751,
         "name": "Test Organization",
         "description": "Test Sub Organization",
         "parentOrganizationId": 750,
         "isActive": false,
         "tz": "Europe/Kiev",
         "unitSystem": "METRIC",
         "phoneNumber": "+3801234567",
         "address": {
            "fullAddress": "Khreschatyk, Kyiv, Ukraine",
            "city": "Kyiv",
            "country": "Ukraine",
            "state": "Kyiv",
            "zip": "02002"
         },
         "lastModifiedTs": 1703068747351
      }
   ],
   "totalElements": 1
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/search?query=dev+org
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/search?query=dev+org
```
