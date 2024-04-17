# Import Datastream Values

This feature enables you to import historical data for a device's datastream. It's useful for scenarios where data isn't streamed in real-time but is instead collected on the device and sent periodically as a dataset.&#x20;

For instance, if your device is usually offline and only connects intermittently to upload a batch of data points.

{% hint style="warning" %}
A maximum of 10,000 data points per device per day is allowed, regardless of whether the data is sent in multiple sets or in one batch.&#x20;

This limit may vary depending on your subscription plan and is consistent with the [Upload a Set of Timestamped Data](../../device-https-api/upload-set-of-data-with-timestamps-api.md) endpoint in the Device HTTPS API.
{% endhint %}

## Import DataStream Values

<mark style="color:green;">`POST`</mark> `https://{server_address}/api/v1/organization/device/import/batch`

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |
| Content-Type<mark style="color:red;">\*</mark>  | application/json       |             |

#### Request Body

| Name                                               | Type   | Description                                                                                                                                                                                          |
| -------------------------------------------------- | ------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| deviceId<mark style="color:red;">\*</mark>         | 1      | Device identifier.                                                                                                                                                                                   |
| dataStreamId<mark style="color:red;">\*</mark>     | 1      | Device datastream identifier.                                                                                                                                                                        |
| values<mark style="color:red;">\*</mark>           |        | Datastream values to import.                                                                                                                                                                         |
| values\[x].value<mark style="color:red;">\*</mark> | 1      | Datastream value.                                                                                                                                                                                    |
| values\[x].ts<mark style="color:red;">\*</mark>    | String | <p>Unix epoch time in milliseconds representing datastream value creation time.</p><p><strong>Note:</strong> Timestamps could be only one month in the past. Older timestamps won't be accepted.</p> |

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

{% tab title="204: No Content Device datastream value updated" %}

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
      -d '{"deviceId":1,"dataStreamId":1,"values":[{"value":5,"ts":1702656423136},{"value":2,"ts":1702656428136}]}' \
      https://fra1.blynk.cloud/api/v1/organization/device/import/batch

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"dataStreamId":1,"values":[{"value":5,"ts":1702656423136},{"value":2,"ts":1702656428136}]}' \
      https://fra1.blynk.cloud/api/v1/organization/device/import/batch
```
