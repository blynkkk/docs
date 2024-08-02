# Get Own Organization Info



## Get Own Organization Info

<mark style="color:blue;">`GET`</mark> `https://{server_address}/api/v1/organization/profile`

With this API call, you get information from the organization where the OAuth credentials were created. So, if the OAuth credentials were provided to you by your Account Manager, this call will return you the root organization info.

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
{% endtabs %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/profile
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/organization/profile

# httpie command exmaple:
$ https -A bearer -a {accessToken} fra1.blynk.cloud/api/organization/profile
$ https -A bearer -a eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS fra1.blynk.cloud/api/v1/organization/profile
```
