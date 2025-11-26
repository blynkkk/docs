# Get Devices in user organization

<mark style="color:blue;">`GET`</mark> `https://{server_address}/api/v1/organization/device/by-user-org`

Use this API to search for devices placed in the same organization in which the specified user is placed.

#### Query Parameters

| Name                                        | Type                 | Description                                         |
| ------------------------------------------- | -------------------- | --------------------------------------------------- |
| userEmail<mark style="color:red;">\*</mark> | Email address string | Email address of the user.                          |
| page                                        | Number               | Page number starting from 0. First page by default. |
| size                                        | Number               | Page size. Should be from 1 to 100. 20 by default.  |

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |

{% tabs %}
{% tab title="200: OK Organization devices" %}
```json
{
   "content": [
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
   ],
   "totalElements": 1
}
```
{% endtab %}
{% endtabs %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/by-owner?ownerEmail=email%40example.com
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/by-owner?ownerEmail=email%40example.com
```
