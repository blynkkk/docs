# Create Organization

## Create New Organization

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/create`

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type<mark style="color:red;">\*</mark>  | application/json       |             |

#### Request Body

| Name                                   | Type                     | Description                                                                                                                                                                                                                        |
| -------------------------------------- | ------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| name<mark style="color:red;">\*</mark> | My Organization          | New organization's name. Should be from 3 to 100 symbols and can contains only letters, digits, spaces, dots, hyphens and apostrophes.                                                                                             |
| description                            | My friend's organization | New organization's description. Should be up to 1,000 symbols and may **cannot** contains slashes, back slashes, less than and greater than symbols.                                                                               |
| type<mark style="color:red;">\*</mark> | BUSINESS                 | Organization type. Could be: `ROOT`, `BUSINESS`, `PERSONAL`, `BRANCH`, `DISTRIBUTOR`, `CONTRACTOR`, `INSTALLER`, `RESELLER`. If parent organization's type is `PERSONAL`, then new organization's type will be `PERSONAL` as well. |
| tz                                     | Europe/Kyiv              | Organization's timezone.                                                                                                                                                                                                           |
| parentId                               | 1                        | Parent organization's identifier.                                                                                                                                                                                                  |
| phoneNumber                            | +380123456789            | New organization's phone number. Should be prefixed with `+`.                                                                                                                                                                      |
| unitSystem                             | IMPERIAL                 | Organization's unit system. Could be `IMPERIAL` or `METRIC`.                                                                                                                                                                       |

{% tabs %}
{% tab title="404: Not Found Parent organization is not found" %}
```json
{
    "error": {
        "message": "Parent organization is not found or you don't have access to it."
    }
}
```
{% endtab %}

{% tab title="201: Created Created organization" %}
```json
{
   "id": 751,
   "name": "Test Organization",
   "description": "Test Sub Organization",
   "parentOrganizationId": 750,
   "isActive": false,
   "tz": "Europe/Kiev",
   "unitSystem": "METRIC",
   "phoneNumber": "+3801234567",
   "lastModifiedTs": 1703068747351
}
```
{% endtab %}
{% endtabs %}

Request examples:

```bash
# curl command example:
$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"templateId":667622,"orgId":6722,"name":"API Test Device","address":"Test Address","ownerId":11456}' \
      https://fra1.blynk.cloud/api/v1/organization/create

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"templateId":667622,"orgId":6722,"name":"API Test Device","address":"Test Address","ownerId":11456}' \
      https://fra1.blynk.cloud/api/v1/organization/create
```
