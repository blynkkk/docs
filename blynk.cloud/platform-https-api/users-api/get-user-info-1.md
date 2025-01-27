# Update User Role

## Get User Info

<mark style="color:blue;">`PUT`</mark> `https://{server_address}/api/v1/organization/users/role`

#### Query Parameters

| Name                                     | Type | Description                                 |
| ---------------------------------------- | ---- | ------------------------------------------- |
| userId<mark style="color:red;">\*</mark> | 1    | User identifier. Should be a valid integer. |
| roleId<mark style="color:red;">\*</mark> | 1    | Role identifier. Should be a valid integer. |

Role IDs are predefined and should be used as follows:

| Role ID | Role name |
| ------- | --------- |
| **1**   | Admin     |
| **2**   | Staff     |
| **3**   | User      |

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |

{% tabs %}
{% tab title="200: Organization user" %}
```json
{
   "id": 1078,
   "name": "John Doe",
   "email": "john@example.com",
   "title": "John",
   "nickName": "john",
   "phoneNumber": "+3801234567",
   "roleId": 3,
   "orgId": 703,
   "tz": "Europe/Kiev",
   "locale": "en_US",
   "status": "Active",
   "lastModifiedTs": 1702985292062,
   "lastLoggedAt": 1702985292062,
   "registeredAt": 1702985292062,
   "isDev": false
}
```
{% endtab %}

{% tab title="404: User is not found" %}
```json
{
    "error": {
        "message": "User with identifier 1 is not found or belong to another organization."
    }
}
```
{% endtab %}

{% tab title="404: Role is not found" %}
```json
{
    "error": {
        "message": "Role is not found."
    }
}
```
{% endtab %}
{% endtabs %}

Request examples:

```bash
# curl command example:
$ curl -X PUT -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/users/role?userId=1&roleId=2
$ curl -X PUT -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/users/role?userId=1&roleId=2
```
