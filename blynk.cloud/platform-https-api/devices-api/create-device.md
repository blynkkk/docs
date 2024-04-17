# Create Device

## Create Device

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/device/create`

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type<mark style="color:red;">\*</mark>  | application/json       |             |

#### Request Body

| Name                                         | Type              | Description                                                                                                                            |
| -------------------------------------------- | ----------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| templateId<mark style="color:red;">\*</mark> | TMPL84aMXD6vd     | Template identifier.                                                                                                                   |
| orgId                                        | 1                 | Organization identifier.                                                                                                               |
| name<mark style="color:red;">\*</mark>       | My Awesome Device | Device name. Should be up to 50 symbols in length and may contains only letters, digits, spaces, apostrophes, underscores and hyphens. |
| onwerId<mark style="color:red;">\*</mark>    | 1                 | User identifier, that will own this device.                                                                                            |

{% tabs %}
{% tab title="404: Not Found User is not found" %}
```json
{
    "error": {
        "message": "User is not found or you don't have access to him."
    }
}
```
{% endtab %}

{% tab title="404: Not Found Template is not found" %}
```json
{
    "error": {
        "message": "Template is not found."
    }
}
```
{% endtab %}

{% tab title="404: Not Found Organization is not found" %}
```json
{
    "error": {
        "message": "Organization is not found or you don't have access to it."
    }
}
```
{% endtab %}

{% tab title="201: Created Created device info" %}
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
{% endtab %}
{% endtabs %}

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
