# Update Widget/Datastream Property

## Updates the Datastream Property and all assigned Widgets

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/update/property?token={token}&pin={pin}&{property}={value}`

\{% swagger-response status="400" description="Could not find a device token or Wrong pin format or Value doesn't match the Datastream data type" %\}

```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Value doesn't match the Datastream data type"}}
```

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}
