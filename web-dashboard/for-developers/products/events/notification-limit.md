# Notifications Limit

![](https://raw.githubusercontent.com/blynkkk/docs/main/.gitbook/assets/limit_period.png)

Limits number of notifications to one notification for a specified time period.  
_**Example**_: 1hr 20min range means end-users will only get one notification within 1 hour 20 minutes even if hardware or API sends more.

![](../../../../.gitbook/assets/event_counter.png)

Notification will be sent after a specified number of events was received. After threshold is met, the counter resets.  
_**Example**_: if the threshold is set to 10 and device sends 100 notifications, the user would only get 10 notifications \(each 10th ignoring those 9 in between\)

_Examples above were given for cases when one of the settings is enabled._

You can set Notifications Limits by both settings simultaneously.  
_**Example**_: set Limit Period to 2h 00min and Event Counter to 120. This means that the user will get only 1 notification after the first 119 notifications during the period of 2 hours. When the period of 2 hours is passed you'll get an additional notification after 119 events were sent.

