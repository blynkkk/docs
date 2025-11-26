# Search Organizations

## Search Organizations

<mark style="color:blue;">`GET`</mark> `https://{server_address}/api/v1/organization/search`

`sortBy` query parameter could accept the following values: `Organization Id`, `Name`, `Device Count`, `User Count`, `Sub Organizations` (stands for sub-organizations count).

#### Query Parameters

| Name                                    | Type    | Description                                                                       |
| --------------------------------------- | ------- | --------------------------------------------------------------------------------- |
| query<mark style="color:red;">\*</mark> | string  | Search query. Should be up to 255 symbols.                                        |
| page                                    | integer | Page number starting from 0. First page by default.                               |
| size                                    | integer | Page size. Should be from 1 to 100. 20 by default.                                |
| sortBy                                  | string  | Field to sort result by.                                                          |
| sortOrder                               | string  | Sorting order. Can be `ASC` (ascending) or `DESC` (descending). `ASC` by default. |

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |

{% tabs %}
{% tab title="200: OK Organizations" %}
```json
{
   "content": [
      {
         "id": 751,
         "name": "Test Organization",
         "description": "Test Sub Organization",
         "parentOrganizationId": 750,
         "isActive": false,
         "tz": "Europe/Kiev",
         "unitSystem": "METRIC",
         "phoneNumber": "+3801234567",
         "address": {
            "fullAddress": "Khreschatyk, Kyiv, Ukraine",
            "city": "Kyiv",
            "country": "Ukraine",
            "state": "Kyiv",
            "zip": "02002"
         },
         "lastModifiedTs": 1703068747351
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/search?query=dev+org
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/search?query=dev+org
```
