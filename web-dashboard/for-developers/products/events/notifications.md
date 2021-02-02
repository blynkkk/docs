# Notifications tab

## Notification

Every event can additionally trigger notifications.

You can:

* Send Emails
* Send Push Notification on a smartphone/tablet
* Send SMS \(additional charges apply\)

### Recipients

You can assign different recipients to each event.

For example, some notifications should be sent to the end-customers, while others should be sent to the technical support team \(for internal review only\).

You need to define the recipient of notifications in Product Metadata before they become available as a selection.

When you add any of the following Metadata fields, they will be available as a recipient in notifications:

* `Device owner` is available as a recipient by default \(no need to add such field\)
* Contact metadata
* Email metadata

Example: You would like your technical support team to be notified every time the vibration sensor is over the defined threshold.

1. In Products -&gt; Your Product -&gt; Metadata:

   Create a new Metadata field of type `Email` or `Contact`.

   Name it "Technical Support" and specify a default value \(for example `support@yourcompany.com`\)

2. In Products -&gt; Your Product -&gt; Events:

   Create a new Event and set a recipient of email notification as `Technical Support`

## Notification Limit

Notification Limit defines how often notifications are sent for this particular event.

For example, a 1 minute period means end-users won't get more than one notification per 1 minute, even if hardware or API sends more. After 1 minute since the last posted notification expires, new notifications will get in.

Notification Limit is applied per event per device. If you have two events with different notification periods set up within the same device, they will be processed independently and end-users will get both notifications with different periods.





