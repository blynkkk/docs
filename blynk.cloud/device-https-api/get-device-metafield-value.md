# Get Device Metadata Value

You can get the value of any single-value (text, number, email, hostspot, device name, list, int, imei, image, iccid, device owner email) device meta field using it **exact name** (case sensitive).

**loc.latlon** is special hardcoded internal meta field to get device location "lat lon".

## Get Device Metafield Value

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/device/meta?token={token}&metaFieldId={metaFieldId}`

\{% swagger-response status="400" description="Could not find a device token or Wrong metaField format or Could not find metaField id" %\}

```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong metaField format."}}

or

{"error":{"message":"MetaField doesn't exist."}}
```

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}
