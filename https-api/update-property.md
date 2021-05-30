# Update Widget Property

{% api-method method="get" host="https://{server_address}" path="/external/api/update/property?token={token}&pin={pin}&{property}={value}" %}
{% api-method-summary %}
Update the Widget with assigned pin
{% endapi-method-summary %}

{% api-method-description %}
This endpoint allows you to update the widget value with assigned pin via GET request.  
**Example:**  
`https://blynk.cloud/external/api/update/property?token=ffujYGgbf805tgsf&pin=v1&isDisabled=true`
{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="property" type="string" required=true %}
The property of the widget you want ot update. Possible values: `label`, `isDisabled`, `color`
{% api-method-parameter name="value" type="string" required=true %}
The desired value of the property
{% endapi-method-parameter %}

{% api-method-parameter name="pin" type="string" required=true %}
Virtual pin number \(should start with "v"\)
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
Wrong pin format  
or  
Value doesn't match the Datastream data type
{% endapi-method-response-example-description %}

```text
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Value doesn't match the Datastream data type"}}
```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}

