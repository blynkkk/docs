# Upload a Set of Timestamped Data

You can update a single Datastream with a set of timestamped data points. This can be helpful when you don't stream the data in real-time, but instead, collect it on the device and need to send it periodically as a dataset.&#x20;

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
The full body with multiple entries:`[[timestamp1, value1], [timestamp2, value2]]`\


{% hint style="warning" %}
`Content-Type` the header is mandatory and should be set to `application/json`
{% endhint %}

{% swagger baseUrl="https://{server_address}" path="/external/api/batch/update?token={token}&pin={pin}" method="post" summary="Upload a Set Of Datapoints With Timestamps" %}
{% swagger-description %}
`Content-Type` header should be set to `application/json`

Example: [`https://blynk.cloud/external/api/batch/update?token=bFFtSHNCZZDWQ__Zs96cP5jLMhLoJofg&pin=v1`](https://blynk.cloud/external/api/batch/update?token=bFFtSHNCZZDWQ\_\_Zs96cP5jLMhLoJofg\&pin=v1)``

Post body:

`[[1648054765458,1.0],[1648054825459,2.0],[1648054885460,3.0]]`
{% endswagger-description %}

{% swagger-parameter in="header" name="Content-Type" type="String" required="false" %}
application/json
{% endswagger-parameter %}

{% swagger-parameter in="query" name="token" type="String" required="false" %}
Device AuthToken
{% endswagger-parameter %}

{% swagger-parameter in="query" name="pin" type="String" required="false" %}
Virtual Pin
{% endswagger-parameter %}

{% swagger-response status="200" description="Success" %}
```
OK
```
{% endswagger-response %}

{% swagger-response status="400: Bad Request" description="Could not find a device token or Wrong pin format or Too much data in batch. Maximum batch size is 10000 points." %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Unknown content type."}}

or

{"error":{"message":"Too much data in batch. Maximum batch size is 10000 points."}}
```
{% endswagger-response %}
{% endswagger %}
