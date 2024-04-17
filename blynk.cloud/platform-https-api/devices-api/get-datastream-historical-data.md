# Get Datastream Historical Data

In order to use this API you must enable raw data saving for the datastream.

## Get Device DataStream History

<mark style="color:blue;">`GET`</mark> `https://{server_address}/api/v1/organization/device/datastream/history`

#### Query Parameters

| Name                                       | Type   | Description                                                                                                    |
| ------------------------------------------ | ------ | -------------------------------------------------------------------------------------------------------------- |
| deviceId<mark style="color:red;">\*</mark> | 1      | Device identifier. Should be a valid integer.                                                                  |
| page                                       | 0      | Page number starting from 0. First page by default.                                                            |
| size                                       | 20     | Page size. Should be from 1 to 100. 20 by default.                                                             |
| pin<mark style="color:red;">\*</mark>      | v1     | Pin name.                                                                                                      |
| from                                       | String | Filter device data stream history from the specified time. Should be a valid unix epoch time in milliseconds.  |
| to                                         | String | Filter device data stream history up to the specified time. Should be a valid unix epoch time in milliseconds. |

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |

{% tabs %}
{% tab title="200: OK Device datastream history" %}
```json
{
  "content": [
    {
      "createdAt": 1702483099000,
      "value": 5
    }
  ],
  "totalElements": 1
}
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
$ curl -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization/device/datastream/history?deviceId=1&pin=v1
$ curl -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization/device/datastream/history?deviceId=1&pin=v1
```
