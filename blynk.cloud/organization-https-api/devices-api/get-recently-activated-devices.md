# Get Recently Activated Devices

{% swagger method="get" path="/api/v1/organization/device/last-activated" baseUrl="https://{server_address}" summary="Get Recently Activated Devices" %}
{% swagger-description %}
Fetch devices activated within the last N minutes, excluding devices from sub-organizations.
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="orgId" type="1" required="false" %}
Identifier organization, that hold devices.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="minutes" type="5" %}
5 minutes is used by default. Should be a valid integer from 1 to 60.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Devices info" %}
```json
{
   "id": 1,
   "templateId": 353,
   "orgId": 578,
   "ownerUserId": 879,
   "activationTime": 1702480430139
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/last-activated
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/last-activated
```
