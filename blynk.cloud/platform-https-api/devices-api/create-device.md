# Create Device

{% swagger method="post" path="/api/v1/organization/device/create" baseUrl="https://{server_address}" summary="Create Device" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="templateId" type="TMPL84aMXD6vd" required="true" %}
Template identifier.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="orgId" type="1" required="false" %}
Organization identifier.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="name" type="My Awesome Device" required="true" %}
Device name. Should be up to 50 symbols in length and may contains only letters, digits, spaces, apostrophes, underscores and hyphens.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="onwerId" type="1" required="true" %}
User identifier, that will own this device.
{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" required="true" %}

{% endswagger-parameter %}

{% swagger-response status="201: Created" description="Created device info" %}
```json
{
   "id": 1,
   "templateId": 353,
   "orgId": 578,
   "name": "My awesome device",
   "token": "ObArJM-PmArETx2gCEQxYqRri8CidcdL",
   "lifecycleStatus": {
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

{% swagger-response status="404: Not Found" description="User is not found" %}
```json
{
    "error": {
        "message": "User is not found or you don't have access to him."
    }
}
```
{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Template is not found" %}
```json
{
    "error": {
        "message": "Template is not found."
    }
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
$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"templateId":"TMPL84aMXD6vd","orgId":6722,"name":"API Test Device","ownerId":11456}' \
      https://fra1.blynk.cloud/api/v1/organization/device/create

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"templateId":"TMPL84aMXD6vd","orgId":6722,"name":"API Test Device","ownerId":11456}' \
      https://fra1.blynk.cloud/api/v1/organization/device/create
```
