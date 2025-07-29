# Update Device Metadata

## Update Device Metadata

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/device/metafield`

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type                                    | application/json       |             |

#### Request Body

| Name                                          | Type           | Description                 |
| --------------------------------------------- | -------------- | --------------------------- |
| deviceId<mark style="color:red;">\*</mark>    | Integer        | Device identifier.          |
| metaFieldId<mark style="color:red;">\*</mark> | Integer        | MetaField identifier.       |
| newValue<mark style="color:red;">\*</mark>    | Integer/String | New metafield string value. |

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

{% tab title="204: No Content Device metadata updated" %}

{% endtab %}

{% tab title="400: Bad Request Invalid metadata value" %}
```json
{
    "error": {
        "message": "The provided value for metafield is invalid."
    }
}
```
{% endtab %}

{% tab title="404: Not Found Metadata is not found" %}
```json
{
    "error": {
        "message": "Meta field is not found."
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
      -d '{"deviceId":1,"metaFieldId":1,"newValue":5}' \
      https://fra1.blynk.cloud/api/v1/organization/device/metafield

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"metaFieldId":1,"newValue":5}' \
      https://fra1.blynk.cloud/api/v1/organization/device/metafield
```
