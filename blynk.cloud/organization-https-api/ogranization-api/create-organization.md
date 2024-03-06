# Create Organization

{% swagger method="post" path="/api/v1/organization/create" baseUrl="https://{server_address}" summary="Create New Organization" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="name" type="My Organization" required="true" %}
New organization's name. Should be from 3 to 100 symbols and can contains only letters, digits, spaces, dots, hyphens and apostrophes.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="description" type="My friend's organization" required="false" %}
New organization's description. Should be up to 1,000 symbols and may **cannot** contains slashes, back slashes, less than and greater than symbols.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="type" type="BUSINESS" required="true" %}
Organization type. Could be: `ROOT`, `BUSINESS`, `PERSONAL`, `BRANCH`, `DISTRIBUTOR`, `CONTRACTOR`, `INSTALLER`, `RESELLER`. If parent organization's type is `PERSONAL`, then new organization's type will be `PERSONAL` as well.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="tz" type="Europe/Kyiv" %}
Organization's timezone.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="parentId" type="1" required="false" %}
Parent organization's identifier.
{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="phoneNumber" type="+380123456789" %}
New organization's phone number. Should be prefixed with `+`.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="unitSystem" type="IMPERIAL" %}
Organization's unit system. Could be `IMPERIAL` or `METRIC`.
{% endswagger-parameter %}

{% swagger-response status="201: Created" description="Created organization" %}
```json
{
   "id": 751,
   "name": "Test Organization",
   "description": "Test Sub Organization",
   "parentOrganizationId": 750,
   "isActive": false,
   "tz": "Europe/Kiev",
   "unitSystem": "METRIC",
   "phoneNumber": "+3801234567",
   "lastModifiedTs": 1703068747351
}
```
{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Parent organization is not found" %}
```json
{
    "error": {
        "message": "Parent organization is not found or you don't have access to it."
    }
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"templateId":667622,"orgId":6722,"name":"API Test Device","address":"Test Address","ownerId":11456}' \
      https://fra1.blynk.cloud/api/v1/organization/create

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"templateId":667622,"orgId":6722,"name":"API Test Device","address":"Test Address","ownerId":11456}' \
      https://fra1.blynk.cloud/api/v1/organization/create
```
