# Devices Online Status

In ideal world when device closes tcp connection with some `connection.close()` - connected server will get notification regarding closed connection. So you can get instant status update on UI. However in real world this mostly exceptional situation. In majority of cases there is no easy and instant way to find out that connection is not active anymore.

That's why Blynk uses `HEARTBEAT` mechanism. With this approach hardware periodically sends `ping` command with predefined interval \(50 seconds by default, `BLYNK_HEARTBEAT` [property](https://github.com/blynkkk/blynk-library/blob/master/src/Blynk/BlynkConfig.h)\). In case hardware don't send anything within 50 seconds server waits additional 25 seconds and after that connection assumed to be broken and closed by server. So on UI you'll see connection status update with some delay.

You can also change `BLYNK_HEARTBEAT` interval from hardware side. In that case `newHeartbeatInterval * 2.3` formula will be applied. Example: you set `HEARTBEAT` interval to 5 seconds. You'll get notification regarding connection with 11 sec delay in worst case.

