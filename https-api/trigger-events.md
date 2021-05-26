# Log Event

{% hint style="warning" %}
Due to current GeoDNS settings you need to put server address with suffix manually depending on your region:  
[https://fra1.blynk.cloud/](https://fra1.blynk.cloud/)   – Frankfurt  
[https://lon1.blynk.cloud/](https://lon1.blynk.cloud/)  – London  
[https://ny3.blynk.cloud/](https://ny3.blynk.cloud/)    – New York  
[https://sgp1.blynk.cloud/](https://sgp1.blynk.cloud/)  – Singapore  
[https://blr1.blynk.cloud/](https://blr1.blynk.cloud/)    – Bangalore  
  
Sorry for the inconvenience. This will be fixed soon!
{% endhint %}

### Get an Event code

1. Open Device Template
2. Switch to Events tab
3. Hover Code column across from Event name
4. Once "Click to copy Event Code" hint appears, click it and Event Code will be coped to you buffer

![](../.gitbook/assets/copy_event_code.png)

{% api-method method="get" host="https://blynk.cloud" path="/external/api/logEvent?token={token}&code={event\_name}&description={event\_desciption}" %}
{% api-method-summary %}
Trigger the event by event code
{% endapi-method-summary %}

{% api-method-description %}
This endpoint allows you to trigger the event  
  
**Example:**  
**`https://blynk.cloud/external/api/logEvent?token=GVki9IC70vb3IqvsV0YD3el4y0OpneL1&code=firmware_update&description=test`**
{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="description" type="string" required=false %}
event description
{% endapi-method-parameter %}

{% api-method-parameter name="code" type="string" required=true %}
event code
{% endapi-method-parameter %}

{% api-method-parameter name="token" type="string" required=true %}
device auth token
{% endapi-method-parameter %}
{% endapi-method-path-parameters %}
{% endapi-method-request %}

{% api-method-response %}
{% api-method-response-example httpCode=200 %}
{% api-method-response-example-description %}
Success
{% endapi-method-response-example-description %}

```text

```
{% endapi-method-response-example %}

{% api-method-response-example httpCode=400 %}
{% api-method-response-example-description %}
Could not find a device token  
or  
Typo in code  
or  
Could not find event code
{% endapi-method-response-example-description %}

```text
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Event code is not provided."}}

or

{"error":{"message":"Can't find Event with this code in Product template"}}
```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}



