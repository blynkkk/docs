---
description: This tutorial will help you with creating Events for your Templates
---

# Events Tutorial

Events shows the current status of the device on Devices Timeline in historical order.  
This feature is extra handy for monitoring informational, warning and critical states of the Devices.

## [Create a Template](working-with-templates/) or use an existing one

1. Open Blynk.360
2. navigate to **Templates** 
3. select Template or click New Template
4. click **Edit** button \(if you've selected an existing Template\)

![blank Template section](../.gitbook/assets/create_template.png)

5. provide general information about the Product

![](../.gitbook/assets/create_template2.png)

6. Fill in the necessary field in the [Info tab.](../web-dashboard/products/info/)

![provide additional info and click Save once it&apos;s done ](../.gitbook/assets/create_template3.png)

## [Create the Device](../web-dashboard/search/devices-1/#create-device) that will be used with this Template

![](../.gitbook/assets/create_device.png)

## Create Events 

\(also this could be done at Template creation stage\)

Return to Template settings and open Events tab and click Edit at top right.  
_**Note:**_ there are two default events \(and they can't be edited\): Online and Offline.

![](../.gitbook/assets/default_events.png)

### Let's create 2 events with names Hello and Error

1. click **Add New Event**
2. provide info on ****[**General tab**](../web-dashboard/products/events/general.md)\*\*\*\*
3. name first event with the name Hello
4. click **Create** \(the event will appear in Events tab list\)
5. repeat previous step for second event with the name Error
6. click **Save** to save and apply the changes made \(select Update active device this time\)

![](../.gitbook/assets/add_new_event.png)

![](../.gitbook/assets/2_new_events.png)

![](../.gitbook/assets/apply_events_to_devices.png)

## Check Events to be applied.

We'll do this using [HTTPS API](../https-api/trigger-events.md)

1. navigate to Device yoo've created
2. click on it's name
3. open Device Info tab
4. find Auth Token there and copy it to the clipboard

![Device Info tab](../.gitbook/assets/event_device_info.png)

![Auth Token. Click copy pictogram here](../.gitbook/assets/auth_token%20%281%29.png)

5. create \(paste Auth Token to it's body after token=\) and send API request

{% api-method method="get" host="https://blynk.cloud" path="/external/api/logEvent?token=WD\_ofOivEbt4vpb02CiFPUPHHf0K5q8n&code=hello" %}
{% api-method-summary %}

{% endapi-method-summary %}

{% api-method-description %}

{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="token" type="string" required=true %}
it's taken from Device Info tab
{% endapi-method-parameter %}
{% endapi-method-path-parameters %}

{% api-method-headers %}
{% api-method-parameter name="code" type="string" required=true %}
it's taken from Event Code field
{% endapi-method-parameter %}
{% endapi-method-headers %}
{% endapi-method-request %}

{% api-method-response %}
{% api-method-response-example httpCode=200 %}
{% api-method-response-example-description %}

{% endapi-method-response-example-description %}

```

```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}

6. repeat the same with code=error  
7. check [Device Timeline](../web-dashboard/search/devices-1/device-view/timeline.md)

![](../.gitbook/assets/events_on_timeline.png)

Congratulations! We have 2 events now!

Also we can mark Critical and Warning events as resolved after it's fixed. Please mind to comment this action in the modal window appeared.

![](../.gitbook/assets/mark_as_resolved.png)

From now on this event can be found under Resolved filter tag.

