# Transfer Device

{% swagger method="post" path="/api/v1/organization/device/transfer" baseUrl="https://{server_address}" summary="Transfer Device" %}
{% swagger-description %}
To successfully trasnfer device, you need to fulfil these requirements:



**Choose Either User or Organization ID**

Specify one of two identifiers – either `newUserId` or `newOrgId`. Note that if you provide `newUserId`, the system will ignore `newOrgId`, and the other way around.



**Access to Destination Organization:**

You must have access rights to the organization to which you're transferring the device. If you don't specify an organization, the system will default to using the organization of the new owner.



**Activation of New Owner's Account:** The account of the new device owner must be activated for the transfer to be successful.


{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="deviceId" type="1" required="true" %}
Device identifier.
{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="newUserId" type="1" required="false" %}
New device owner identifier.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="newOrgId" type="1" required="false" %}
New organization owner identifier.
{% endswagger-parameter %}

{% swagger-response status="204: No Content" description="Device transfered" %}

{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Device is not found" %}
```json
{
    "error": {
        "message": "Device with identifier 1 is not found or belong to another organization."
    }
}
```
{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Destination organization is not found" %}
```json
{
    "error": {
        "message": "Destination organization is not found or you don't have access to it."
    }
}
```
{% endswagger-response %}

{% swagger-response status="400: Bad Request" description="Same owner transfer error" %}
```json
{
    "error": {
        "message": "Can't transfer to the same owner"
    }
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"deviceId":1,"newUserId":1}' \
      https://fra1.blynk.cloud/api/v1/organization/device/transfer

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"newUserId":1}' \
      https://fra1.blynk.cloud/api/v1/organization/device/transfer
```
