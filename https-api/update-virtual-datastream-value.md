# Update Virtual Datastream Value

{% api-method method="get" host="https://blynk.cloud" path="/external/api/update?token={token}&pin={pin}&value={value}" %}
{% api-method-summary %}
Update Datastream value by Virtual Pin
{% endapi-method-summary %}

{% api-method-description %}
This endpoint allows you to update the value or the Virtual Pin  
**Example:**  
`https://blynk.cloud/external/api/update?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&pin=v23&value=3.14`
{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="value" type="string" required=true %}
the value will be parsed as the  
Datastream data type \(int, double, string\)
{% endapi-method-parameter %}

{% api-method-parameter name="pin" type="string" required=true %}
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
Success
{% endapi-method-response-example-description %}

```text

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

{% api-method method="get" host="https://blynk.cloud" path="/external/api/update?token={token}&dataStreamId={id}&value={value}" %}
{% api-method-summary %}
Update value by Datastream ID
{% endapi-method-summary %}

{% api-method-description %}
This endpoint allows you to update the value or the Datastream  
**Example:**  
`https://blynk.cloud/external/api/update?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&dataStreamId=1&value=3.14`
{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="value" type="string" required=true %}
the value will be parsed as the Datastream data type  
\(int, double, string\)
{% endapi-method-parameter %}

{% api-method-parameter name="dataStreamId" type="integer" required=true %}
Datastream Id
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
{% endapi-method-response-example-description %}

```text
{"error":{"message":"Invalid token."}}
```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}

