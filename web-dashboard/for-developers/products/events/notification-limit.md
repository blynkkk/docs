# Notifications Limit

## Limit period

![](../../../../.gitbook/assets/limit_period.png)

Limits number of notifications to one notification for a specified time period.  
Example: 1hr 20min range means end-users will only get one notification within 1 hour 20 minutes even if hardware or API sends more.

## Ignore treshold\|

![](../../../../.gitbook/assets/ignore_treshold.png)

Notification will be sent after a specified number of events was received. After treshold is met, the counter resets.  
Example: if the treshold is set to 10 and device sends 100 notifications, the user would only get 10 notifications.

