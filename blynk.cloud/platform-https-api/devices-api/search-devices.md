# Search Devices

## Search Organization Devices

<mark style="color:blue;">`GET`</mark> `https://{server_address}/api/v1/organization/search/devices`

`sortBy` query parameter could accept the following values: `Device Id`, `Name` (stands for device's name), `Auth Token`, `Owner Id` (stands for device's owner name), `Device Owner Name`, `Device Owner` (stands for device's owner email), `Last Reported At`, `Activated At`, `Activated By` (stands for email of user, that activated device), `Model` (stands for device's model), `Template Name`, `Template Id`, `Firmware Version`, `Organization Id`, `Status` (stands for device's status).

#### Query Parameters

| Name                                    | Type        | Description                                                                                               |
| --------------------------------------- | ----------- | --------------------------------------------------------------------------------------------------------- |
| query<mark style="color:red;">\*</mark> | Device name | Search query. Should be up to 255 symbols.                                                                |
| page                                    | 0           | Page number starting from 0. First page by default.                                                       |
| size                                    | 20          | Page size. Should be from 1 to 100. 20 by default.                                                        |
| sortBy                                  | Device Id   | Field to sort result by.                                                                                  |
| sortOrder                               | ASC         | Sorting order. Could be `ASC` (ascending sort order) or `DESC` (descending sort order). `ASC` by default. |

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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/search/devices?query=my+device+name
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/search/devices?query=my+device+name
```
