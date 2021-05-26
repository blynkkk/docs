# Get Virtual Datastream Value

{% hint style="warning" %}
Due to current GeoDNS settings you need to put server address with suffix manually depending on your region:  
[https://fra1.blynk.cloud/](https://fra1.blynk.cloud/)   – Frankfurt  
[https://lon1.blynk.cloud/](https://lon1.blynk.cloud/)  – London  
[https://ny3.blynk.cloud/](https://ny3.blynk.cloud/)    – New York  
[https://sgp1.blynk.cloud/](https://sgp1.blynk.cloud/)  – Singapore  
[https://blr1.blynk.cloud/](https://blr1.blynk.cloud/)    – Bangalore  
  
Sorry for the inconvenience. This will be fixed soon!
{% endhint %}

{% api-method method="get" host="https://{server\_address}" path="/external/api/get?token={token}&{pin}" %}
{% api-method-summary %}
Get Datastream value by Virtual Pin
{% endapi-method-summary %}

{% api-method-description %}
This endpoint allows you to get the stored value of the Virtual Datastream by pin type and pin   
  
  
**Example:**  
`https://blynk.cloud/external/api/get?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&v1`
{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
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
Value successfully retrieved.
{% endapi-method-response-example-description %}

```text
100.00000
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

{% api-method method="get" host="https://{server\_address}" path="/external/api/get?token={token}&dataStreamId={id}" %}
{% api-method-summary %}
Get value by Datastream ID
{% endapi-method-summary %}

{% api-method-description %}
This endpoint allows you to get the stored value of the Datastream by id   
**Example:**  
`https://blynk.cloud/external/api/get?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&dataStreamId=1`
{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
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
Value successfully retrieved.
{% endapi-method-response-example-description %}

```text
100.00000
```
{% endapi-method-response-example %}

{% api-method-response-example httpCode=400 %}
{% api-method-response-example-description %}
Could not find a device token  
or  
Typo in dataStreamID  
or  
Requested dataStream doesn't exist in the product ESP32 QA
{% endapi-method-response-example-description %}

```text
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Requested dataStream doesn't exist in the product ESP32 QA"}}
```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}

