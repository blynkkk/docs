# Device Online/Offline Status

## Devices Online Status

Blynk always updates the device online status in realtime. As soon as device sends the `login` command, online status is sent to the web and mobile apps. So you can always see if the device is online or not.

## Devices Offline Status

In ideal world when device closes tcp connection with the code like `connection.close()`- the server will get notification regarding closed connection. So you can get instant status update on UI. However, in real world this mostly exceptional situation. In the majority of cases there is no easy and instant way to find out that connection is not active anymore.

That's why Blynk uses `HEARTBEAT` mechanism. With this approach hardware periodically sends `ping` command with predefined interval \(45 seconds by default, `BLYNK_HEARTBEAT` [property](https://github.com/blynkkk/blynk-library/blob/master/src/Blynk/BlynkConfig.h)\). In case hardware doesn't send anything within 45 seconds server waits additional 103 seconds. After that connection assumed to be broken and closed by server. So on UI you'll see connection status update with some delay.

You can also change `BLYNK_HEARTBEAT` interval from hardware side. In that case `newHeartbeatInterval * 2.3` formula will be applied. Example: you set `HEARTBEAT` interval to 5 seconds. You'll get notification regarding connection with 11 sec delay in worst case.

Have in mind, that decreasing the ping interval increase the traffic between your hardware and server. For products, that are sensitive for data bandwidth \(GSM devices\), it's recommended to use very high ping intervals.

