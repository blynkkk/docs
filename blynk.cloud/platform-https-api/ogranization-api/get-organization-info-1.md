# Get Organization Info



## Get Organization Info

<mark style="color:blue;">`GET`</mark> `https://{server_address}/api/v1/organization`

Get organization information by its identifier.

#### Query Parameters

| Name                                    | Type | Description             |
| --------------------------------------- | ---- | ----------------------- |
| orgId<mark style="color:red;">\*</mark> | 1    | Organization identifier |

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |

{% tabs %}
{% tab title="200: OK Organization info" %}
```json
{
   "id": 658,
   "name": "My Awesome Organization",
   "description": "Some description",
   "parentOrganizationId": 657,
   "isActive": true,
   "tz": "Europe/Kiev",
   "unitSystem": "IMPERIAL",
   "phoneNumber": "+123456789012"
   "address": {
      "fullAddress": "Khreshchatyk st.",
      "city": "Kyiv",
      "country": "Ukraine",
      "state": "Ukraine",
      "zip": "02000"
   },
   "lastModifiedTs": 1694707051504
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
{% endtabs %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization?orgId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization?orgId=1

# httpie command example:
$ https -A bearer -a {accessToken} fra1.blynk.cloud/api/v1/organization?orgId=1
$ https -A bearer -a eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS fra1.blynk.cloud/api/v1/organization?orgId=1
```
