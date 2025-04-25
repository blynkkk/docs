# Send/Log An Event

[HTTPS API ](broken-reference/)-> Send/Log An Event

1. Check this [article](../../getting-started/events-tutorial.md) on setting up an event
2. Use the GET call below to send event

## Trigger the event by event code

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/logEvent?token={token}&code={event_code}&description={event_description}`

\{% swagger-response status="400" description="Could not find a device token or Typo in code or Could not find event code" %\}

```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Event code is not provided."}}

or

{"error":{"message":"Can't find Event with this code in Product template"}}
```

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}
