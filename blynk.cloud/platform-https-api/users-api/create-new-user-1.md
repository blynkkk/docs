# Create New User in an Organization

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/users/create-in-org`

This endpoint will create a new user as a member of the provided organization.

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type<mark style="color:red;">\*</mark>  | application/json       |             |

#### Request Body

| Name                                           | Example                                      | Description                                                                                                             |
| ---------------------------------------------- | -------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| email<mark style="color:red;">\*</mark>        | john@example.com                             | String. New user's email                                                                                                |
| passwordHash<mark style="color:red;">\*</mark> | tk++TTJLCEKfWuhQyGAKCSRMop6wyIexGKylaknsUo8= | String. New user's password. See [user password creation notes](create-new-user.md#user-password).                      |
| name<mark style="color:red;">\*</mark>         | John Doe                                     | String. New user's name. May contain up to 50 symbols. Only letters, hyphens, spaces, dots and apostrophes are allowed. |
| orgId<mark style="color:red;">\*</mark>        | 1                                            | Integer. New user's organization identifier.                                                                            |
| roleId<mark style="color:red;">\*</mark>       | 1                                            | Integer. New user's role identifier.                                                                                    |
| title                                          | String                                       | String. New user's title. May contain up to 50 symbols. Only letters, hyphens and spaces are allowed.                   |
| nickName                                       | String                                       | String. New user's nickname. May contain up to 50 symbols. Only letters, digits, hyphens and spaces are allowed.        |
| phoneNumber                                    | +3801234567                                  | String. New user's phone number. Should be prefixed with `+`.                                                           |
| tz                                             | Europe/Kiev                                  | String. New user's timezone.                                                                                            |
| address                                        |                                              | New user's address.                                                                                                     |
| address.fullAddress                            | String                                       | New user's full address. Should be up to 512 symbols.                                                                   |
| address.city                                   | String                                       | New user's city. Should be up to 50 symbols.                                                                            |
| address.country                                | String                                       | New user's country. Should be up to 74 symbols.                                                                         |
| address.state                                  | String                                       | New user's state. Should be up to 40 symbols.                                                                           |
| address.zip                                    | String                                       | New user's zip code. Should be up to 12 symbols.                                                                        |

{% tabs %}
{% tab title="201: Created" %}
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
{% endtabs %}

Request examples:

<pre class="language-bash"><code class="lang-bash"># curl command example:
$ curl -X POST -H "Content-Type: application/json" \
<strong>      -H "Authorization: Bearer {accessToken}" \
</strong>      -d '{"email":"test@example.com","passwordHash":"tk++TTJLCEKfWuhQyGAKCSRMop6wyIexGKylaknsUo8=","name":"Test user","orgId":1,"roleId":1,"address":{"city":"Kyiv","country":"Ukraine"}}' \
      https://fra1.blynk.cloud/api/v1/organization/users/create-in-org

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"email":"test@example.com","passwordHash":"tk++TTJLCEKfWuhQyGAKCSRMop6wyIexGKylaknsUo8=","name":"Test user","orgId":1,"roleId":1,"address":{"city":"Kyiv","country":"Ukraine"}}' \
      https://fra1.blynk.cloud/api/v1/organization/users/create-in-org
</code></pre>
