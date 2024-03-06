# Log a Device Event

{% swagger method="post" path="/api/v1/organization/device/trigger-event" baseUrl="https://{server_address}" summary="Trigger Device Event" %}
{% swagger-description %}
Note: The combined length of the event code and description must not exceed 1024 symbols
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="deviceId" type="1" required="true" %}
Device identifier.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="eventCode" type="high_temp" required="true" %}
Event code.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="eventDescription" type="Temperature is over 20°" required="false" %}
Triggered event description. Should be up to 300 symbols in length (may be increased for enterprise clients).
{% endswagger-parameter %}

{% swagger-response status="204: No Content" description="Event triggered" %}

{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Device is not found" %}
```json
{
    "error": {
        "message": "Device with identifier 1 is not found or belong to another organization."
    }
}
```
{% endswagger-response %}

{% swagger-response status="404: Not Found" description="Event is not found" %}
```json
{
    "error": {
        "message": "Event with provided code is not found."
    }
}
```
{% endswagger-response %}
{% endswagger %}

Request examples:

```bash
# curl command example:
$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer {accessToken}" \
      -d '{"deviceId":1,"eventCode":"high_temp"}' \
      https://fra1.blynk.cloud/api/v1/organization/device/trigger-event

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"deviceId":1,"eventCode":"high_temp"}' \
      https://fra1.blynk.cloud/api/v1/organization/device/trigger-event
```
