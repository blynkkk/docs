# Get Base Device Info

<mark style="color:blue;">`GET`</mark> `https://{server_address}/api/v1/organization/device/baseInfo`

Same as [Get Device Info](get-device-info.md), but with the minimized API response.

#### Query Parameters

| Name                                       | Example | Description                                   |
| ------------------------------------------ | ------- | --------------------------------------------- |
| deviceId<mark style="color:red;">\*</mark> | 1       | Device identifier. Should be a valid integer. |

#### Headers

| Name                                            | Format                 |
| ----------------------------------------------- | ---------------------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |

{% tabs %}
{% tab title="200: OK Device info" %}
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
{% endtab %}

{% tab title="404: Not Found Device is not found" %}
```json
{
    "error": {
        "message": "Device with identifier 1 is not found or belong to another organization."
    }
}
```
{% endtab %}
{% endtabs %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/baseInfo?deviceId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/baseInfo?deviceId=1
```
