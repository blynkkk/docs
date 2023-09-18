# Get Organization Info



{% swagger method="get" path="/api/organization/profile" baseUrl="https://{server_address}" summary="Get Organization Info" %}
{% swagger-description %}
Get own organization information.
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-response status="200: OK" description="Organization info" %}
```json
{
   "id": 658,
   "name": "My Awesome Organization",
   "isActive": true,
   "type": "BUSINESS",
   "tz": "Europe/Kiev",
   "logoUrl": "/static/logo.png",
   "lastModifiedTs": 1694707051504,
   "tokenGroup": {
      "serverTokens": [
         {
            "name": "API Token",
            "orgId": 658,
            "clientId": "oa2-client-id_JVnTSCOTc6rXmMFN1ELrj70Cy9fX1-EJ",
            "secret": "s3C5r8-gMHIvr-dnDo5QAcJv3Y1ZyHOxpaHUspD-"
         }
      ]
   },
   // some other fields
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/organization/profile
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/organization/profile

# httpie command exmaple:
$ https -A bearer -a {accessToken} fra1.blynk.cloud/api/organization/profile
$ https -A bearer -a eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS fra1.blynk.cloud/api/organization/profile
```
