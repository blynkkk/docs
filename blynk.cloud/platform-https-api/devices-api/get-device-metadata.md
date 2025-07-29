# Get Device Metadata

## Get Device Metadata

<mark style="color:blue;">`GET`</mark> `https://{server_address}/api/v1/organization/device/metafield`

#### Query Parameters

| Name                                       | Type    | Description                                   |
| ------------------------------------------ | ------- | --------------------------------------------- |
| deviceId<mark style="color:red;">\*</mark> | Integer | Device identifier. Should be a valid integer. |

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |

{% tabs %}
{% tab title="200: OK Device Metadata" %}
```json
[
    {
        "id": 1,
        "name": "Device Name",
        "value": "My awesome device"
    },
    {
        "id": 2,
        "name": "Device Owner",
        "value": "user@example.com"
    }   
]
```
{% endtab %}

{% tab title="404: Not Found Device is not found" %}
```json
{
    "error": {
        "message": "Device with identifier 1 is not found or belong to another organization."
    }
}
```
{% endtab %}
{% endtabs %}

Request examples:

```bash
# curl command example:
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/metafield?deviceId=1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/metafield?deviceId=1
```
