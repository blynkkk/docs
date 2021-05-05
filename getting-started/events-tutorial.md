---
description: This tutorial will help you with creating Events for your Templates
---

# Events Tutorial

Events show the current status of the device on the [Timeline](../web-dashboard/search/devices-1/device-view/timeline.md) in historical order.  
This feature is extra handy for monitoring informational, warning, and critical states of the Devices.

### 1. [Create a Template](working-with-templates/) or use an existing one

### 2. [Create the Device](../web-dashboard/search/devices-1/#create-device) that will be used with this Template

![](../.gitbook/assets/create_device.png)

### 3. Create Events 

\(also this could be done at Template creation stage\)

Return to Template settings and open Events tab and click Edit at top right.  
_**Note:**_ there are two default events \(and they can't be edited\): Online and Offline.

![](../.gitbook/assets/default_events.png)

#### Let's create 2 events with names Hello and Error

1. Click **Add New Event**
2. Provide information on the ****[**General tab**](../web-dashboard/products/events/general.md)\*\*\*\*
3. Name the first event with the name Hello
4. Click **Create** \(the event will appear in the Events tab list\)
5. Repeat the previous step for the second event with the name Error
6. Click **Save** to save and apply the changes made \(select Update active device this time\)

![](../.gitbook/assets/add_new_event.png)

![](../.gitbook/assets/2_new_events.png)

![](../.gitbook/assets/apply_events_to_devices.png)

### 4. Check Events to be applied.

There are 2 ways to trigger events, we'll cover both ways.

#### Blynk.logEvent\(\) hardware command. 

Just call the function in the corresponding place of your sketch like this:

```text
Blynk.logEvent("hello");
```

There is also a way to send a description along with events:

```text
Blynk.logEvent("error","something went wrong");
```

#### Another way to send events is to use the HTTPS API

1. Navigate to the Device you've created
2. Click on its name
3. Open Device Info tab
4. Find Auth Token there and copy it to the clipboard

![Device Info tab](../.gitbook/assets/event_device_info.png)

![Auth Token. Click copy pictogram here](../.gitbook/assets/auth_token%20%281%29.png)

### 5. Paste Auth Token into the request body and send a request using a browser

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

