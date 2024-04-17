# Update Multiple Datastreams Values

## Update Multiple Datastreams Values

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/device/datastreams`

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type<mark style="color:red;">\*</mark>  | application/json       |             |

#### Request Body

| Name                                       | Type    | Description                                                              |
| ------------------------------------------ | ------- | ------------------------------------------------------------------------ |
| deviceId<mark style="color:red;">\*</mark> | 1       | Device identifier.                                                       |
| values<mark style="color:red;">\*</mark>   | {"1":5} | Map with datastream identifier as a key and datastream value as a value. |

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

{% tab title="204: No Content Device datastream values updated" %}

{% endtab %}
{% endtabs %}

Request examples:

```bash
# curl command example:
$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"deviceId":1,"values":{"1":5,"2":"new value"}}' \
      https://fra1.blynk.cloud/api/v1/organization/device/datastreams

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"values":{"1":5,"2":"new value"}}' \
      https://fra1.blynk.cloud/api/v1/organization/device/datastreams
```
