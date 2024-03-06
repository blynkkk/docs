# Search Users

{% swagger method="get" path="/api/v1/organization/search/users" baseUrl="https://{server_address}" summary="Search Organization Members (Users)" %}
{% swagger-description %}
`sortBy` query parameter could accept the following values: `User Id`, `Name`, `Email`, `Status`, `Role`, `Organization Name`, `Devices Count` (stands for count of devices, that user own), `Country`, `Registered At`, `Phone Number`.
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="query" type="John" required="true" %}
Search query. Should be up to 255 symbols.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="page" type="0" %}
Page number starting from 0. First page by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="size" type="20" %}
Page size. Should be from 1 to 100. 20 by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="sortBy" type="User Id" %}
Field to sort result by.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="sortOrder" type="ASC" %}
Sorting order. Could be `ASC` (ascending sort order) or `DESC` (descending sort order). `ASC` by default.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization members" %}
```json
{
   "content": [
      {
         "id": 1080,
         "name": "John Doe",
         "email": "john@example.com",
         "roleId": 3,
         "orgId": 704,
         "isDev": false
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/search/users?query=john
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/search/users?query=john
```
