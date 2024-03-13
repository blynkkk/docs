# Get User Info

{% swagger method="get" path="/api/v1/organization/user" baseUrl="https://{server_address}" summary="Get User Info" %}
{% swagger-description %}

{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="query" name="userId" type="1" required="true" %}
User identifier. Should be a valid integer.
{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization user" %}
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
{% endswagger-response %}

{% swagger-response status="404: Not Found" description="User is not found" %}
```json
{
    "error": {
        "message": "User with identifier 1 is not found or belong to another organization."
    }
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/user?userId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/user?userId=1
```
