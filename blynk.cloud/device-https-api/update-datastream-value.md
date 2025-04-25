# Update Datastream Value

## Update the Datastream value

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/update?token={token}&{pin}={value}`

This endpoint allows you to update the value of the Datastream value via GET request.\
**Example:**\
`https://blynk.cloud/external/api/update?token=ffujYGgbf805tgsf&v1=100`

#### Path Parameters

| Name  | Type   | Description                                                                                                                                                                                                                                   |
| ----- | ------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| value | string | The desired value of the Datastream. Will be parsed based on the Datastream data type (int, double, string) and bounded with min / max values of datastream settings. In case value doesn't match the Datastream type error will be returned. |
| pin   | string | Virtual pin number (should start with "v")                                                                                                                                                                                                    |
| token | string | Device auth token                                                                                                                                                                                                                             |

{% tabs %}
{% tab title="200 Success" %}
```
```
{% endtab %}

{% tab title="400 " %}
```
{"error":{"message":"Invalid token."}}
or
{"error":{"message":"Wrong pin format."}}
or
{"error":{"message":"Value doesn't match the Datastream data type."}}
or
{"error":{"message":"No datastream setup for that pin."}}
```
{% endtab %}
{% endtabs %}

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}

## Update value by Datastream ID

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/update?token={token}&dataStreamId={id}&value={value}`

\{% swagger-response status="400" description="Could not find a device token or Wrong dataStreamId format or Value doesn't match the Datastream data type" %\}

```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong dataStreamId format."}}

or

{"error":{"message":"Value doesn't match the Datastream data type"}}
```

To update Datastreams that have 2 values, for example Location Datastream, use this call:

```
/external/api/update?token={token}&dataStreamId={id}&value=lon&value=lat
```

or

```
/external/api/update?token={token}&pin=V1&value=lon&value=lat
```
