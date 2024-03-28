# Send/Log An Event

[HTTPS API ](broken-reference)-> Send/Log An Event

1. Check this [article](../../getting-started/events-tutorial.md) on setting up an event
2. Use the GET call below to send event&#x20;

{% swagger baseUrl="https://{server_address}" path="/external/api/logEvent?token={token}&code={event_code}&description={event_description}" method="get" summary="Trigger the event by event code" %}
{% swagger-description %}
This endpoint allows you to trigger the event.\


**Example:**\
`https://blynk.cloud/external/api/logEvent?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&code=firmware_update&description=test`
{% endswagger-description %}

{% swagger-parameter in="path" name="description" type="string" %}
Event description
{% endswagger-parameter %}

{% swagger-parameter in="path" name="code" type="string" %}
Event code
{% endswagger-parameter %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
{% endswagger-parameter %}

{% swagger-response status="200" description="Success" %}
```
```
{% endswagger-response %}

{% swagger-response status="400" description="Could not find a device token
or
Typo in code
or
Could not find event code" %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Event code is not provided."}}

or

{"error":{"message":"Can't find Event with this code in Product template"}}
```
{% endswagger-response %}
{% endswagger %}

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}
