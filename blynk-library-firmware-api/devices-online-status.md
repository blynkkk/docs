# Device Online/Offline Status

## Devices Online Status

Blynk always updates the device's online status in realtime. As soon as the device sends the `login` command, online status is sent to the web and mobile apps. So you can always see whether the device is online or offline.

## Devices Offline Status

In the ideal world, when a device closes tcp connection with the code like `connection.close()`- the server will get a notification regarding the closed connection. So you can get instant status update in the UI. However, in the real world this case is rather an exception. In most cases, there is no easy and instant way to find out that connection is not active anymore.

That is why Blynk uses `HEARTBEAT` mechanism. With this approach hardware periodically sends `ping` command with a predefined frequency (every 45 seconds by default, `BLYNK_HEARTBEAT` [property](https://github.com/blynkkk/blynk-library/blob/master/src/Blynk/BlynkConfig.h)). If the hardware doesn't send anything within 45 seconds, the server will wait for additional 103 seconds. After that, the connection is assumed to be broken and closed by server. Therefore, the UI will show the connection status update with a  bit of delay.

You can also change `BLYNK_HEARTBEAT` interval from the hardware side. In that case `newHeartbeatInterval * 2.3` formula will be applied. Example: you set `HEARTBEAT` interval to 5 seconds. The you will get a notification regarding your connection with 11 sec delay at the most.

Keep in mind that decreasing the ping interval will increase the traffic between your hardware and server. For products that are sensitive for data bandwidth (GSM devices), it's recommended to use very high ping intervals.
