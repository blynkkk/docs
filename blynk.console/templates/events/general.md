# General Settings

![](../../../.gitbook/assets/new_ev_gen.png)

### Event Name

Give your event a meaningful name because it will be shown to end-users.   
Use letters, digits, spaces, and underscores only. 50 character limit. 

**IMPORTANT:** Event name should be unique within the product.

### Event Code

Event code is used in firmware API to trigger and render events from the device.  
Use letters, digits, spaces, and underscores only. 50 character limit. 

**IMPORTANT:** Event code should be unique within the product.

### Type

There are 3 types of Events which help you to set the importance level to an events:

* **Info** – low priority general information. Green color is set by default.
* **Warning** – ignoring this event may cause the issues. Orange color is set by default. 
* **Critical** – immediate attention or action is required. Red color is set by default.
* **Content** – special type of events that can provide some extra info \(e.g. picture, link, additional text information\)

**IMPORTANT:** Events' colors are used in Analytics

### Description

Optional field that can contain a description of an event. 250 character limit. 

### Content type specific fields

**Subtitle** – short description of the event nature, e.g. provided content type, category of the event, it's content or action

**Image Link** – URL \(must be accessible to your users\) to picture you want to show

**Action Title** – description or invitation to perform Action Link transition   

**Action Link** – URL to new library, firmware, application version or your/partner's web page

### Show event on the Timeline

This option is set to disabled during Create Event procedure to avoid false entries in Devices' Timeline.  
Once you've finished with Event setup and sure everything is fine about it enable this option so that Event will appear in Timeline once it's triggered.

### Apply a Tag

Device will be tagged when this Event is recorded. This tag can’t be removed manually. When event is resolved, the tag will be removed automatically.



