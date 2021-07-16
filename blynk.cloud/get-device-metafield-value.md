# Get Device MetaField Value

{% api-method method="get" host="https://{server\_address}" path="/external/api/device/meta?token={token}&metaFieldId={metaFieldId}" %}
{% api-method-summary %}
Get Device Metafield Value
{% endapi-method-summary %}

{% api-method-description %}
This endpoint allows you to get the device metaField value by its id.  
**Example:**  
`https://blynk.cloud/external/api/device/meta?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&metaFieldId=1`
{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="metaFieldId" type="string" required=true %}
MetaField id.
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
{"type":"Text","value":"device value"}
```
{% endapi-method-response-example %}

{% api-method-response-example httpCode=400 %}
{% api-method-response-example-description %}
Could not find a device token  
or  
Wrong metaField format
or
Could not find metaField id 
{% endapi-method-response-example-description %}

```text
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong metaField format."}}

or

{"error":{"message":"MetaField doesn't exist."}}
```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}
