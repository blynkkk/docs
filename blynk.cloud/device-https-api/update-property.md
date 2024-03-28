# Update Widget/Datastream Property

{% swagger baseUrl="https://{server_address}" path="/external/api/update/property?token={token}&pin={pin}&{property}={value}" method="get" summary="Updates the Datastream Property and all assigned Widgets" %}
{% swagger-description %}
This endpoint allows you to update the Datastream Property value via GET request. All widgets (both web and mobile) that are assigned to this datastream will inherit this property. For example, if you have 2 widgets assigned to the datastream with the pin 10 and use set property "label" to "xxx", both widgets will get this label. The Datastream Property is persistent and will be stored forever until you change it with another value. In order to clear the property you need to clear the device data in device actions menu. 

**Example:**

\




`https://blynk.cloud/external/api/update/property?token=ffujYGgbf805tgsf&pin=v1&isDisabled=true`
{% endswagger-description %}

{% swagger-parameter in="path" name="property" type="string" %}
The property of the widget you want ot update. Possible values: 

`label`

, 

`isDisabled`

, 

`color`
{% endswagger-parameter %}

{% swagger-parameter in="path" name="value" type="string" %}
The desired value of the property
{% endswagger-parameter %}

{% swagger-parameter in="path" name="pin" type="string" %}
Virtual pin number (should start with "v")
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
Wrong pin format
or
Value doesn't match the Datastream data type" %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"Wrong pin format."}}

or

{"error":{"message":"Value doesn't match the Datastream data type"}}
```
{% endswagger-response %}
{% endswagger %}

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
{% endhint %}
