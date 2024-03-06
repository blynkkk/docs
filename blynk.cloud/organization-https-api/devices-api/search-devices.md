# Search Devices

{% swagger method="get" path="/api/v1/organization/search/devices" baseUrl="https://{server_address}" summary="Search Organization Devices" %}
{% swagger-description %}
`sortBy` query parameter could accept the following values: `Device Id`, `Name` (stands for device's name), `Auth Token`, `Owner Id` (stands for device's owner name), `Device Owner Name`, `Device Owner` (stands for device's owner email), `Last Reported At`, `Activated At`, `Activated By` (stands for email of user, that activated device), `Model` (stands for device's model), `Template Name`, `Template Id`, `Firmware Version`, `Organization Id`, `Status` (stands for device's status).
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="query" type="Device name" required="true" %}
Search query. Should be up to 255 symbols.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="page" type="0" %}
Page number starting from 0. First page by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="size" type="20" %}
Page size. Should be from 1 to 100. 20 by default.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="sortBy" type="Device Id" %}
Field to sort result by.
{% endswagger-parameter %}

{% swagger-parameter in="query" name="sortOrder" type="ASC" %}
Sorting order. Could be `ASC` (ascending sort order) or `DESC` (descending sort order). `ASC` by default.
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/search/devices?query=my+device+name
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/search/devices?query=my+device+name
```
