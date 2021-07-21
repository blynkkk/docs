# Get Multiple Datastream Values

{% api-method method="get" host="https://{server\_address}" path="/external/api/get?token={token}&{pin}&{pinX}" %}
{% api-method-summary %}
Get Multiple Datastream values
{% endapi-method-summary %}

{% api-method-description %}
In some cases it's important to get the datastream values with one call. This endpoint allows you to get the stored values of the multiple Datastreams. Returned type depends on the datastream type. **Example:**  
`https://blynk.cloud/external/api/get?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&v1&v2&v3&v4`
{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="pin" type="string" required=true %}
Virtual pin number \(should start with "v"\)
{% endapi-method-parameter %}

{% api-method-parameter name="token" type="string" required=true %}
Device auth token
{% endapi-method-parameter %}
{% endapi-method-path-parameters %}
{% endapi-method-request %}

{% api-method-response %}
{% api-method-response-example httpCode=200 %}
{% api-method-response-example-description %}
Value successfully retrieved.
{% endapi-method-response-example-description %}

```text
{"v1":1.0,"v2":2,"v3":3,"v4":"string pin"}
```
{% endapi-method-response-example %}

{% api-method-response-example httpCode=400 %}
{% api-method-response-example-description %}
Could not find a device token  
or  
Wrong pin format
{% endapi-method-response-example-description %}

```text
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}
```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}

