# Erase All Data

## Erase All Device Data

<mark style="color:red;">`DELETE`</mark> `https://{server_address}/api/v1/organization/device/clear`

#### Query Parameters

| Name                                       | Type | Description                                   |
| ------------------------------------------ | ---- | --------------------------------------------- |
| deviceId<mark style="color:red;">\*</mark> | 1    | Device identifier. Should be a valid integer. |

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |

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

{% tab title="204: No Content Device data deleted" %}

{% endtab %}
{% endtabs %}

Request examples:

```bash
# curl command example:
$ curl -X DELETE -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/clear?deviceId=1
$ curl -X DELETE -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/clear?deviceId=1
```
