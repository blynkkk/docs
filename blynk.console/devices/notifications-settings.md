# Notifications Settings

Blynk offers a very flexible way to send notifications. Users can specify who gets notifications, which events will trigger notifications, and which channel should be used.

Currently, Blynk offers 3 channels to deliver notifications: 

* E-mail
* Push notifications - a push notification is a message that pops up on a mobile device. Users don't have to be in the app to get them
* SMS - notification will be delivered as a text message using mobile operator

{% hint style="info" %}
SMS are currently only available in white-label solution
{% endhint %}

##  Managing notifications

1. Select single or multiple devices \(1\)
2. Hover over the **Actions menu \[...\]** \(2\)
3. Click **Notification Settings** \(3\)

![](https://user-images.githubusercontent.com/72824404/120806266-4ffcfc00-c54f-11eb-9cc0-d0c53cf7efcf.png)

4. In the opened drawer you will see a list of all Event available for notifications \(4\) . To specify Events available in Notifications settings, a Developer needs to set it up in the device template.
5. Click **Edit Settings** \(5\)

{% hint style="info" %}
If you don't see the Edit Settings button, or list of Events is empty, check that you made events available for notifications.
{% endhint %}

![](https://user-images.githubusercontent.com/72824404/120807574-c6e6c480-c550-11eb-8965-6a979c147122.png)

6. Turn on the desired channels \(Email, Push, or SMS\) and add recipients. If the recipient is not on the list you can search by typing the name or the email.

Optionally you can choose  "All members". In this case all members of current organization will receive the notification through the selected channel.

![](https://user-images.githubusercontent.com/72824404/120807610-cfd79600-c550-11eb-82ea-969884f21cf9.png)

Press **Apply** and you'll see the event status and channels updated.

![](https://user-images.githubusercontent.com/72824404/120807644-d8c86780-c550-11eb-927c-d73b24a638a7.png)



### Muting notifications

Notifications can be muted for a specified period of time. Click on the switch near the Event status and you will get a dropdown menu with the mute period options.

Notifications will be automatically unmuted after the specified period. 

_❇️ This feature is useful when you need to temporarily mute notifications. For example during deployment, testing, or maintenance at job site._

\_\_

