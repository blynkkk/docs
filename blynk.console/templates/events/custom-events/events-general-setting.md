# Event Settings

### Event Name

Give your event a meaningful name because it will be shown to end-users. \
Use letters, digits, spaces, and underscores only. 50 character limit.&#x20;

{% hint style="info" %}
Use unique Event Names within one template
{% endhint %}

### Event Code

Event code is used in Firmware API and HTTPS API to trigger and render events from the device.\
Use letters, digits, spaces, and underscores only. 50 character limit.&#x20;

{% hint style="info" %}
Use unique event\_codes within one template
{% endhint %}

### Event Type

There are four Event types. Three of them are used for escalation level This setting only affects the category for later filtering and also on "coloring" the events in the apps.

* **Info Event** – low priority general information. Green color is set by default.
* **Warning Event** – ignoring this event may cause the issues. Orange color is set by default.&#x20;
* **Critical Event** – immediate attention or action is required. Red color is set by default.

**Content Event** – special type of event that can provide some extra info (e.g. picture, link, additional text information) and have a designated area.

### Event Description

Use this field to give more context about the event to the end-users. Content description can be sent using Firmware API and HTTPS API.

### Show event on the Timeline

When turned on, will show the event on the Timeline in mobile apps and in Blynk.Console:

<figure><img src="../../../../.gitbook/assets/events.png" alt=""><figcaption></figcaption></figure>

### Apply a Tag

With this feature you can automatically tag a device with a specified tag when Event is logged.&#x20;

Automatically applied Tag can’t be removed manually. It will be removed automatically when the Event is resolved.

### Content Event Settings

Content events are shown in a designated area of the app and provide a richer content.

**Subtitle** – short description of the event nature, e.g. provided content type, category of the event, it's content or action.

**Image Link** – URL (must be accessible to your users) for the image to use.

**Action Title** – copy text for Call-to-action.

**Action Link** – URL for call-to-action. Where users should be taken when they click on the link.
