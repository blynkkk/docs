# Notifications Limit

![](../../../../.gitbook/assets/limit_period.png)

Limits number of notifications to one notification for a specified time period.  
_**Example**_: 1hr 20min range means end-users will only get one notification within 1 hour 20 minutes even if hardware or API sends more.

![](../../../../.gitbook/assets/ignore_treshold.png)

Notification will be sent after a specified number of events was received. After threshold is met, the counter resets.  
_**Example**_: if the threshold is set to 10 and device sends 100 notifications, the user would only get 10 notifications \(each 10th ignoring those 9 in between\)

_Examples above were given for cases when one of the settings is enabled._  
  
You can set Notifications Limits by both settings simultaneously.  
_**Example**_: set Limit Period to 2h 00min and Ignore Threshold to 120. This means that user will get only 120 notifications maximum during those 2 hours \(that makes 1 notification per minute\) even if device or API send notifications each 20 seconds.



