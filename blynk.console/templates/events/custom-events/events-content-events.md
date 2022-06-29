---
description: Here's an instruction on how to create and test Content Events
---

# Content Events

{% hint style="info" %}
Events content can be created by the user with the permissions of the Super admin.
{% endhint %}

## Create Content Event

1. Open Blynk.Console
2. Navigate to **Templates** -> Your Template
3. Click **Edit** button
4. Switch to **Events tab**
5. Click **Add New Event**
6. Select the type of event: **Content**
7. Fill in the fields:
   1. **Name** – name of the Event
   2. **Subtitle** – (e.g. category name, content type)
   3. **Image Link** – URL to an image that will be shown on the event card&#x20;
   4. **Description** – event's reason and/or purpose, other information&#x20;
   5. **Action Title** – description or appeal (e.g. “Get update”, “Proceed to the shop”) to Action Link
   6. **Action Link** – URL to new library, firmware, application version, your/partner's website, etc.
8. **Apply Tag** – enable for the Device to be tagged when this Event is recorded. The tag can’t be removed manually. When event is resolved, the tag will be removed automatically.
9. Switch to Notifications tab&#x20;
10. Enable Notifications – lets you set notifications about events occured to Devices so you get them via SMS, Push or E-mail&#x20;
11. Select the type of notification (email, push, sms) and recipients
12. Set [Notifications Limit](events-content-events.md) if necessary and turn on [Notifications management](../../../../getting-started/notification-management.md)
13. Click **Create** button&#x20;
14. **Save** Template

## **Send API request**

The event content can be sent using the API by placing a request in the browser line now:

HTTPS API for Log event testing:

`https://{server_address}/external/api/logEvent?token={token}&code={event_name}`

`https://{server_address}/external/api/logevent?token={token}&code={event_name}&description={event_description}`



## **Check Content Event**

#### **Email: Check specified email**

### **Check your Device's Timeline:**

**Web application**

1. Navigate to the Device which token you've specified in the request,
2. switch to Timeline tab&#x20;
3. specify the time period you want to view and select the Content type of event&#x20;
4. click Action Link&#x20;

You will see all the content of this notification

**Mobile app:**

1. Sign in to Blynk.Apps
2. Go to the Notifications tab (29)
3. Follow this link (30)

You will see all the content of this notification
