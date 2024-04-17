# Log a Device Event

## Trigger Device Event

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/device/trigger-event`

Note: The combined length of the event code and description must not exceed 1024 symbols

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type                                    | application/json       |             |

#### Request Body

| Name                                        | Type                    | Description                                                                                                   |
| ------------------------------------------- | ----------------------- | ------------------------------------------------------------------------------------------------------------- |
| deviceId<mark style="color:red;">\*</mark>  | 1                       | Device identifier.                                                                                            |
| eventCode<mark style="color:red;">\*</mark> | high\_temp              | Event code.                                                                                                   |
| eventDescription                            | Temperature is over 20° | Triggered event description. Should be up to 300 symbols in length (may be increased for enterprise clients). |

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

{% tab title="204: No Content Event triggered" %}

{% endtab %}

{% tab title="404: Not Found Event is not found" %}
```json
{
    "error": {
        "message": "Event with provided code is not found."
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
      -d '{"deviceId":1,"eventCode":"high_temp"}' \
      https://fra1.blynk.cloud/api/v1/organization/device/trigger-event

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"eventCode":"high_temp"}' \
      https://fra1.blynk.cloud/api/v1/organization/device/trigger-event
```
