# Get Multiple Datastream Values

## Get Multiple Datastream values

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/get?token={token}&{pin}&{pinX}`

\{% swagger-response status="400" description="Could not find a device token or Wrong pin format" %\}

```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}
```

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}

## Get All Datastreams values

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/getAll?token={token}`

This endpoint allows you to get stored values of the all Datastreams by device token. The value(s) will be displayed in the response if the Datastream has a value.

**Example:**\
`https://blynk.cloud/external/api/getAll?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L`

#### Path Parameters

| Name                                               | Type   | Description                                                                              |
| -------------------------------------------------- | ------ | ---------------------------------------------------------------------------------------- |
| {server address}<mark style="color:red;">\*</mark> | string | Get from the bottom right of your Blynk console. [More information](troubleshooting.md). |

#### Query Parameters

| Name                                    | Type   | Description                                                              |
| --------------------------------------- | ------ | ------------------------------------------------------------------------ |
| token<mark style="color:red;">\*</mark> | string | Device [auth token](../../concepts/device.md#authtoken) from Device info |

{% tabs %}
{% tab title="200 Value successfully retrieved." %}
```
{
    "a0": 1,
    "a1": 1,
    "a2": 1,
    "a3": 1,
    "d0": 1,
    "d1": 1,
    "d2": 1,
    "d3": 0,
    "v0": 1,
    "v1": 1.0,
    "v2": "string",
    "v3": 1,
    "v4": [
        12.0,
        11.0
    ]
}
```
{% endtab %}

{% tab title="400 Could not find a device token" %}
```
{"error":{"message":"Invalid token."}}
```
{% endtab %}
{% endtabs %}
