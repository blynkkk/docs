# Is Device Connected

{% swagger baseUrl="https://{server_address}" path="/external/api/isHardwareConnected?token={token}" method="get" summary="Returns the device online state" %}
{% swagger-description %}
This API call allows you to get the device online status\
**Example:**\
`https://blynk.cloud/external/api/isHardwareConnected?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L`
{% endswagger-description %}

{% swagger-parameter in="path" name="token" type="string" %}
Device auth token
{% endswagger-parameter %}

{% swagger-response status="200" description="Returns true or false" %}
```
true
```
{% endswagger-response %}

{% swagger-response status="400" description="Could not find a device token" %}
```
{"error":{"message":"Invalid token."}}
```
{% endswagger-response %}
{% endswagger %}

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}
