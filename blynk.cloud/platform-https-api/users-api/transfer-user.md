# Transfer User

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/users/transfer`

Transfer the user to a specific organization.

#### Headers

| Name                                            | Value                  |
| ----------------------------------------------- | ---------------------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |
| Content-Type<mark style="color:red;">\*</mark>  | application/json       |

#### Request Body

| Name                                          | Example | Description                                                       |
| --------------------------------------------- | ------- | ----------------------------------------------------------------- |
| userId<mark style="color:red;">\*</mark>      | 1       | The identifier of the user, which should be transferred, integer. |
| targetOrgId<mark style="color:red;">\*</mark> | 2       | The identifier of the destination organization, integer.          |
| roleId<mark style="color:red;">\*</mark>      | 3       | New user's role identifier, integer.                              |

{% tabs %}
{% tab title="201: User transfered" %}
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

{% tab title="404: Organisation is not found" %}
```json
{
  "error": {
    "message": "Target organization is not found."
  }
}
```
{% endtab %}

{% tab title="400: Role is not found" %}
```json
{
 "error": {
    "message": "Request with incorrect parameters"
  }
}
```
{% endtab %}

{% tab title="400: User is not found" %}
```json
{
 "error": {
    "message": "User with identifier 1 is not found."
  }
}
```
{% endtab %}
{% endtabs %}

Request examples:

<pre class="language-bash"><code class="lang-bash"># curl command example:
$ curl -X POST -H "Content-Type: application/json" \
<strong>      -H "Authorization: Bearer {accessToken}" \
</strong>      -d '{"userId":1,"targetOrgId":1,"roleId":1}' \
      https://fra1.blynk.cloud/api/v1/organization/users/transfer

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"userId":1,"targetOrgId":1,"roleId":1}' \
      https://fra1.blynk.cloud/api/v1/organization/users/transfer
</code></pre>
