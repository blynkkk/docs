# Update Datastream Property

## Update Device DataStream Property Value

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/device/datastream/property`

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type<mark style="color:red;">\*</mark>  | application/json       |             |

#### Request Body

| Name                                           | Type       | Description                                                                                                 |
| ---------------------------------------------- | ---------- | ----------------------------------------------------------------------------------------------------------- |
| deviceId<mark style="color:red;">\*</mark>     | 1          | Device identifier.                                                                                          |
| dataStreamId<mark style="color:red;">\*</mark> | 1          | Device datastream identifier.                                                                               |
| value<mark style="color:red;">\*</mark>        | Some value | Device datastream value.                                                                                    |
| property<mark style="color:red;">\*</mark>     | color      | DataStream property name. See [Widget Properties](../../../blynk.edgent-firmware-api/widget-properties.md). |

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

{% tab title="204: No Content Device datastream property value updated" %}

{% endtab %}

{% tab title="404: Not Found Datastream is not found" %}
```json
{
    "error": {
        "message": "Data stream with identifier 1 is not found!"
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
      -d '{"deviceId":1,"dataStreamId":1,"property":"color","value":"red"}' \
      https://fra1.blynk.cloud/api/v1/organization/device/datastream/property

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"dataStreamId":1,"property":"color","value":"red"}' \
      https://fra1.blynk.cloud/api/v1/organization/device/datastream/property
```
