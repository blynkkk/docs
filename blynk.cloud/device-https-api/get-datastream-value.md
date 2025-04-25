# Get Datastream Value

## Get Datastream value

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/get?token={token}&{pin}`

\{% swagger-response status="400" description="Could not find a device token or Wrong pin format" %\}

```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}
```

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}

## Get Datastream value by Datastream ID

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/get?token={token}&dataStreamId={id}`

\{% swagger-response status="400" description="Could not find a device token or Typo in dataStreamID or Requested dataStream doesn't exist in the product ESP32 QA" %\}

```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Requested dataStream doesn't exist in the product ESP32 QA"}}
```
