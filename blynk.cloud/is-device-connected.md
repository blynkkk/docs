# Is Device Connected

{% api-method method="get" host="https://{server\_address}" path="/external/api/isHardwareConnected?token={token}" %}
{% api-method-summary %}
Returns the device online state
{% endapi-method-summary %}

{% api-method-description %}
This API call allows you to get the device online status  
**Example:**  
`https://blynk.cloud/external/api/isHardwareConnected?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L`
{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="token" type="string" required=true %}
Device auth token
{% endapi-method-parameter %}
{% endapi-method-path-parameters %}
{% endapi-method-request %}

{% api-method-response %}
{% api-method-response-example httpCode=200 %}
{% api-method-response-example-description %}
Returns `true` or `false`
{% endapi-method-response-example-description %}

```text
true
```
{% endapi-method-response-example %}

{% api-method-response-example httpCode=400 %}
{% api-method-response-example-description %}
Could not find a device token
{% endapi-method-response-example-description %}

```text
{"error":{"message":"Invalid token."}}
```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}

