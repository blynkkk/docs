# Invite User

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/users/invite`

Invite a new user to a specific organization. This endpoint will send the invitation email to the specified email address.

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type<mark style="color:red;">\*</mark>  | application/json       |             |

#### Request Body

| Name                                     | Example          | Description                                                                                                                                                                                                                                        |
| ---------------------------------------- | ---------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| email<mark style="color:red;">\*</mark>  | john@example.com | New user's email, string.                                                                                                                                                                                                                          |
| name<mark style="color:red;">\*</mark>   | John             | New user's name, string.                                                                                                                                                                                                                           |
| roleId<mark style="color:red;">\*</mark> | 3                | New user's role identifier, integer.                                                                                                                                                                                                               |
| orgId                                    | 1                | Organization, where user should be invited to, integer. The OAuth Client organization is used by default.                                                                                                                                          |
| locale                                   | en\_US           | New user's locale, string. The locale is consist of two-letter language code defined by ISO 639-1 (e.g., "en" for English) and a two-letter country code defined by ISO 3166-1 alpha-2 (e.g., "US" for the United States) separated by underscore. |

{% tabs %}
{% tab title="201: User invited" %}
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
    "message": "Organization is not found or you don't have access to it."
  }
}
```
{% endtab %}

{% tab title="400: Role is not found" %}
```json
{
 "error": {
    "message": "You don't have permissions to access this Role. Contact administrator for details."
  }
}
```
{% endtab %}

{% tab title="400: Email already used" %}
```json
{
 "error": {
    "message": "john@example.com is already in use"
  }
}
```
{% endtab %}
{% endtabs %}

Request examples:

<pre class="language-bash"><code class="lang-bash"># curl command example:
$ curl -X POST -H "Content-Type: application/json" \
<strong>      -H "Authorization: Bearer {accessToken}" \
</strong>      -d '{"email":"test@example.com","name":"Test User","roleId":1,"locale":"en_US"}' \
      https://fra1.blynk.cloud/api/v1/organization/users/invite

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"email":"test@example.com","name":"Test User","roleId":1,"locale":"en_US"}' \
      https://fra1.blynk.cloud/api/v1/organization/users/invite
</code></pre>
