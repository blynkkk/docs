# Transfer Device

## Transfer Device

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/device/transfer`

To successfully trasnfer device, you need to fulfil these requirements:



**Choose Either User or Organization ID**

Specify one of two identifiers – either `newUserId` or `newOrgId`. Note that if you provide `newUserId`, the system will ignore `newOrgId`, and the other way around.



**Access to Destination Organization:**

You must have access rights to the organization to which you're transferring the device. If you don't specify an organization, the system will default to using the organization of the new owner.



**Activation of New Owner's Account:** The account of the new device owner must be activated for the transfer to be successful.



#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type<mark style="color:red;">\*</mark>  | application/json       |             |

#### Request Body

| Name                                       | Type | Description                        |
| ------------------------------------------ | ---- | ---------------------------------- |
| deviceId<mark style="color:red;">\*</mark> | 1    | Device identifier.                 |
| newUserId                                  | 1    | New device owner identifier.       |
| newOrgId                                   | 1    | New organization owner identifier. |

{% tabs %}
{% tab title="404: Not Found Device is not found" %}
```json
{
    "error": {
        "message": "Device with identifier 1 is not found or belong to another organization."
    }
}
```
{% endtab %}

{% tab title="204: No Content Device transfered" %}

{% endtab %}

{% tab title="404: Not Found Destination organization is not found" %}
```json
{
    "error": {
        "message": "Destination organization is not found or you don't have access to it."
    }
}
```
{% endtab %}

{% tab title="400: Bad Request Same owner transfer error" %}
```json
{
    "error": {
        "message": "Can't transfer to the same owner"
    }
}
```
{% endtab %}
{% endtabs %}

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
