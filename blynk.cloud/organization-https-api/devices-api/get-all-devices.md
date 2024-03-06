# Get All Devices

{% swagger method="get" path="/api/v1/organization/devices" baseUrl="https://{server_address}" summary="Get Organization Devices" %}
{% swagger-description %}
Get a list of devices in your organization
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="page" type="0" %}
Page number starting from 0. First page by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="size" type="20" %}
Page size. Should be from 1 to 100. 20 by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="includeSubOrgDevices" type="false" %}
If specified, we will also include devices, that belong to sub-organizations.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization devices" %}
```json
{
   "content": [
      {
         "id": 165,
         "templateId": 353,
         "orgId": 577,
         "name": "My awesome device",
         "activatedAt": 1702480139859,
         "ownerUserId": 879,
         "hardwareInfo": {
            "version": "1.0.0",
            "fwType": "TMPL0NqfCLjWX",
            "blynkVersion": "1.0.0",
            "boardType": "ESP8266",
            "build": "1",
            "templateId": "TMPL0NqfCLjWX"
         }
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/devices
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/devices
```
