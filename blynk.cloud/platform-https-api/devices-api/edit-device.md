# Edit Device

## Edit Device

<mark style="color:orange;">`PUT`</mark> `https://{server_address}/api/v1/organization/device`

#### Query Parameters

| Name                                       | Type | Description                                   |
| ------------------------------------------ | ---- | --------------------------------------------- |
| deviceId<mark style="color:red;">\*</mark> | 1    | Device identifier. Should be a valid integer. |

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type<mark style="color:red;">\*</mark>  | application/json       |             |

#### Request Body

| Name                                   | Type              | Description                                                                                                                            |
| -------------------------------------- | ----------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| name<mark style="color:red;">\*</mark> | My Awesome Device | Device name. Should be up to 50 symbols in length and may contains only letters, digits, spaces, apostrophes, underscores and hyphens. |

{% tabs %}
{% tab title="200: OK Updated device info" %}
```json
{
   "id": 165,
   "templateId": 353,
   "orgId": 577,
   "name": "My awesome device",
   "token": "etAxiiiYlDv4j7WCeb1pKW2Ck7UGWpgl",
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
$ curl -X PUT -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"name":"API Test Device"}' \
      https://fra1.blynk.cloud/api/v1/organization/device?deviceId=1

$ curl -X PUT -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"name":"API Test Device"}' \
      https://fra1.blynk.cloud/api/v1/organization/device?deviceId=1
```
