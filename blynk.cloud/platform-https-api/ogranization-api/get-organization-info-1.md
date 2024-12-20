# Get Organization Info



{% swagger method="get" path="/api/v1/organization" baseUrl="https://{server_address}" summary="Get Organization Info" %}
{% swagger-description %}
Get organization information by it's identifier.
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="orgId" type="1" required="true" %}
Organization identifier
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization info" %}
```json
{
   "id": 658,
   "name": "My Awesome Organization",
   "description": "Some description",
   "parentOrganizationId": 657,
   "isActive": true,
   "tz": "Europe/Kiev",
   "unitSystem": "IMPERIAL",
   "phoneNumber": "+123456789012"
   "address": {
      "fullAddress": "Khreshchatyk st.",
      "city": "Kyiv",
      "country": "Ukraine",
      "state": "Ukraine",
      "zip": "02000"
   },
   "lastModifiedTs": 1694707051504
}
```
{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Organization is not found" %}
```json
{
    "error": {
        "message": "Organization is not found or you don't have access to it."
    }
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization?orgId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/organization?orgId=1

# httpie command exmaple:
$ https -A bearer -a {accessToken} fra1.blynk.cloud/api/organization?orgId=1
$ https -A bearer -a eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS fra1.blynk.cloud/api/v1/organization?orgId=1
```
