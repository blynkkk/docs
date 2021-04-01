---
description: Here's an instruction on how to create and test Content Events
---

# Content Events testing

{% hint style="info" %}
Events content can be created by the user with the permissions of the Super admin.
{% endhint %}

## Create Content Event

1. Open Blynk.360
2. navigate to **Templates** 
3. select Template
4. click **Edit** button
5. switch to **Events tab**
6. click **Add New Event**
7. select the type of event: **Content**
8. fill the fields:
   1. **Name** – name of the Event
   2. **Subtitle** – \(e.g. category name, content type\)
   3. **Image Link** – URL to a suitable picture that will be shown once the Event occurs 
   4. **Description** – event's reason and/or purpose, other information 
   5. **Action Title** – description or appeal \(e.g. “Get update”, “Proceed to the shop”\) to Action Link
   6. **Action Link** – URL to new library, firmware, application version, your/partner's website, etc.
9. **Apply Tag** options – enable to
10. Switch to Notifications tab 
11. Enable Notifications 
12. Select the type of notification \(email, push, sms\) and recipients
13. Set [Notifications Limit](../web-dashboard/for-developers/products/events/notification-limit.md) if necessary and turn on [Notifications management](notification-management.md)
14. Click **Create** button 
15. **Save** Template 

## **Send API request**

The event content can be sent using the API by placing a request in the browser line now:

HTTPS API for Log event testing:

`https://{server_address}/external/api/logEvent?{token}&code={event_name}`

`https://{server_address}/external/api/logevent?{token}&code={event_name}&description={event_description}`

Tap keyboard **Enter**

## **Check Content Event**

### **Check E-mails inboxes you've set as recipients**

### **Check your Device's Timeline:**

**Web application**

Go to the device which token you've specified in the request,

Switch to Timeline tab 

Specify the time period you want to view and select the Content type of event 

Follow this link 

And you will see all the content of this notification 

**Mobile app:**

Sign in to the mobile app

Go to the Alerts tab \(29\)

Follow this link \(30\)

And you will see all the content of this notification \(31\)

**Check for the Tag to be applied**

1. 2. 
