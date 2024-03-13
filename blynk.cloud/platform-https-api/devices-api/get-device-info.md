# Get Device Info

{% swagger method="get" path="/api/v1/organization/device" baseUrl="https://{server_address}" summary="Get Device Info" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="deviceId" type="1" required="true" %}
Device identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Device info" %}
```json
{
   "id": 1,
   "templateId": 353,
   "orgId": 578,
   "name": "My awesome device",
   "token": "ObArJM-PmArETx2gCEQxYqRri8CidcdL",
   "lifecycleStatus": {
      "eventId": 1,
      "name": "Offline",
      "icon": "icon",
      "color": "#334455"
   },
   "activatedAt": 1702480430139,
   "firstConnectTime": 0,
   "firmwareUpdatedAt": 0,
   "connectTime": 0,
   "disconnectTime": 0,
   "ownerUserId": 879,
   "hardwareInfo": {
      "version": "1.0.0",
      "fwType": "TMPL0NqfCLjWX",
      "blynkVersion": "1.0.0",
      "boardType": "ESP8266",
      "build": "1",
      "templateId": "TMPL0NqfCLjWX"
   },
   "ip": "127.0.0.1",
   "isLocked": false,
   "lastReceivedEventAt": 0
}
```
{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Device is not found" %}
```json
{
    "error": {
        "message": "Device with identifier 1 is not found or belong to another organization."
    }
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device?deviceId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device?deviceId=1
```
