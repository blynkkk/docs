# Log Event

# Get Virtual Datastream value

{% api-method method="get" host="https://blynk.cloud" path="/external/api/get?token={token}&pin={pin}" %}
{% api-method-summary %}
Get Datastream value by Virtual Pin
{% endapi-method-summary %}

{% api-method-description %}
This endpoint allows you to get the stored value or the Virtual Pin  
  
**Example:**  
`https://blynk.cloud/external/api/get?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&pin=v23`  
  
{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="pin" type="string" required=false %}
virtual pin number \(should start with "v"\)
{% endapi-method-parameter %}

{% api-method-parameter name="token" type="string" required=true %}
device auth token
{% endapi-method-parameter %}
{% endapi-method-path-parameters %}
{% endapi-method-request %}

{% api-method-response %}
{% api-method-response-example httpCode=200 %}
{% api-method-response-example-description %}
Value successfully retrieved.
{% endapi-method-response-example-description %}

```
3.14
```
{% endapi-method-response-example %}

{% api-method-response-example httpCode=400 %}
{% api-method-response-example-description %}
Could not find a device token
{% endapi-method-response-example-description %}

```
{"error":{"message":"Invalid token."}}
```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}

