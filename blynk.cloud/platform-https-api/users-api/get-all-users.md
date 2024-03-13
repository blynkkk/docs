# Get All Users

{% swagger method="get" path="/api/v1/organization/users" baseUrl="https://{server_address}" summary="Get All Organization Members (Users)" %}
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

{% swagger-parameter in="query" name="includeSubOrgUsers" type="false" %}
If specified, we will also include users, that belong to sub-organizations.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization members" %}
<pre class="language-json"><code class="lang-json"><strong>{
</strong>   "content": [
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
</code></pre>
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/users
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/users
```
