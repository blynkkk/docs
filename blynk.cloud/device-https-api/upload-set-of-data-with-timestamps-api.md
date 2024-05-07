# Upload a Set of Timestamped Data

You can update a single Datastream with a set of timestamped data points. This can be helpful when you don't stream the data in real-time, but instead, collect it on the device and need to send it periodically as a dataset.

For example, your device can be offline most of the time, but connect periodically and upload a set of data points.

{% hint style="warning" %}
**LIMIT:** You can send a max of 10,000 data points per day per device. No matter if you split it into multiple sets or send all data once.

This limit can vary based on the plan you are using.
{% endhint %}

### Timestamp requirements

When sending the data you would need to provide a timestamp for each value and send the timestamp and value as a single entry, like this: `[[timestamp, value]]`. Where `timestamp` is the time difference between the current time and midnight, January 1, 1970 UTC measured in **milliseconds**.

The timestamp is the same as `Unix epoch` or `Unix timestamp` **multiplied by 1000ms.**

{% hint style="warning" %}
**LIMIT:** timestamps could be only one month in the past. Older timestamps won't be accepted.
{% endhint %}

### Entry Format

The single entry format: `[[timestamp, value]]`\
The full body with multiple entries:`[[timestamp1, value1], [timestamp2, value2]]`

{% hint style="warning" %}
`Content-Type` the header is mandatory and should be set to `application/json`
{% endhint %}

Each entry value should respect datastream value type. Thus you have to pass a string for string datastream, `true` or `false` for boolean datastream, array of two numbers for location datastream.

Example body based on datastream type:

<table><thead><tr><th width="248">DataStream Value Type</th><th>Example</th></tr></thead><tbody><tr><td>String</td><td><code>[[1648054765458,"Some value"],[1648054825459,"Some another value"]]</code></td></tr><tr><td>Integer</td><td><code>[[1648054765458,1],[1648054825459,2]]</code></td></tr><tr><td>Double</td><td><code>[[1648054765458,36.6],[1648054825459,41.2]]</code></td></tr><tr><td>Boolean</td><td><code>[[1648054765458,true],[1648054825459,false]]</code></td></tr><tr><td>Enum</td><td><code>[[1648054765458,1],[1648054825459,2]]</code></td></tr><tr><td>Location</td><td><code>[[1648054765458,[32.123960,49.109466]]]</code></td></tr></tbody></table>

## Upload a Set Of Datapoints With Timestamps

<mark style="color:green;">`POST`</mark> `https://{server_address}/external/api/batch/update?token={token}&pin={pin}`

`Content-Type` header should be set to `application/json`

Example: [`https://blynk.cloud/external/api/batch/update?token=bFFtSHNCZZDWQ__Zs96cP5jLMhLoJofg&pin=v1`](https://blynk.cloud/external/api/batch/update?token=bFFtSHNCZZDWQ\_\_Zs96cP5jLMhLoJofg\&pin=v1)

Post body:

`[[1648054765458,1.0],[1648054825459,2.0],[1648054885460,3.0]]`

#### Query Parameters

| Name  | Type   | Description      |
| ----- | ------ | ---------------- |
| token | String | Device AuthToken |
| pin   | String | Virtual Pin      |

#### Headers

| Name         | Type   | Description      |
| ------------ | ------ | ---------------- |
| Content-Type | String | application/json |

{% tabs %}
{% tab title="200 Success" %}
```
OK
```
{% endtab %}

{% tab title="400: Bad Request Could not find a device token or Wrong pin format or Too much data in batch. Maximum batch size is 10000 points." %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Unknown content type."}}

or

{"error":{"message":"Too much data in batch. Maximum batch size is 10000 points."}}
```
{% endtab %}
{% endtabs %}

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}

### cURL example:

`curl -X POST -H 'Content-Type: application/json' -d '[[1650378744000,0]]' -i 'https://blynk.cloud/external/api/batch/update?token=YOUR_TOKEN&pin=v1'`
