# Edit Device

{% swagger method="put" path="/api/v1/organization/device" baseUrl="https://{server_address}" summary="Edit Device" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="name" type="My Awesome Device" required="true" %}
Device name. Should be up to 50 symbols in length and may contains only letters, digits, spaces, apostrophes, underscores and hyphens.
{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="deviceId" type="1" required="true" %}
Device identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Updated device info" %}
```json
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
$ curl -X PUT -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"name":"API Test Device"}' \
      https://fra1.blynk.cloud/api/v1/organization/device?deviceId=1

$ curl -X PUT -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"name":"API Test Device"}' \
      https://fra1.blynk.cloud/api/v1/organization/device?deviceId=1
```
