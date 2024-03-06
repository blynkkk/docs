# Disconnections And Heartbeat

Blynk always tracks the device's online status in real-time. As soon as the device connects to the server or sends data, the server sets the device status to Online. However, tracking disconnections is more complex.



## Graceful And Non-Graceful Disconnect

When a device closes a TCP connection with commands like `connection.close()` / `socket.close()` / `Blynk.disconnect()` - the server gets almost real-time notification regarding the closed connection.&#x20;

This is called **graceful** disconnection. This might be common when devices work over the cellular network and the developer intentionally chooses to close the connection to control traffic amount.&#x20;

However, with WiFi or Ethernet connection, the controlled graceful disconnect is rather an exception: devices are assumed to be always online, but can lose connection for various reasons ( WiFi drop, router reboot, etc.) This is called **non-graceful** disconnection and Blynk uses Heartbeat to find out about it.



## Heartbeat

The hardware periodically sends a `ping` command to the server (every 45 seconds by default). If there is no ping from the device, the server waits for 22 seconds more (half of the heartbeat interval) and after that assumes that the connection was lost. The status change will be applied in 67 seconds ( 45 + 45\*0.5).&#x20;

This is why you won't immediately see the device going Offline even if you set up the Wait period between Connection Lifecycle Events to 0 minutes.&#x20;

If there is a Wait period configured in Connection Lifecycle Events, the server will wait for the heartbeat as explained above, and then start the wait period (the 67 seconds will be subtracted from the period).



Heartbeat can be set in the firmware with `BLYNK_HEARTBEAT` [property](https://github.com/blynkkk/blynk-library/blob/master/src/Blynk/BlynkConfig.h). It can also be updated if/when needed from the device.

{% hint style="info" %}
When changing `BLYNK_HEARTBEAT,`keep in mind that it will be multiplied by 1.5. For example: if you configure 10 second heartbeat, the device status will be changed in 15 seconds after not getting a reply.&#x20;
{% endhint %}

{% hint style="warning" %}
Keep in mind that decreasing the ping interval will increase the traffic amount between your device and server. For products that are sensitive to data bandwidth (GSM devices), it's recommended to use very long ping intervals.
{% endhint %}





## Examples

Since some of the scenarios are non-trivial, we've prepared a few examples to better explain them:

### 1. Device disconnects. (Graceful)

**Setup:** Connection Lifecycle has Online and Offline statuses with 5 minutes of wait time in-between. Let's check the timeline

{% code overflow="wrap" %}
```
10:50:00 Device disconnects from server
The server starts 5-minute timer according to settings. Device status is ONLINE

There is no new connection from the Device

10:55:00 Server sets device status to OFFLINE
```
{% endcode %}

### 2. Device disconnects, then reconnects. (Graceful)&#x20;

**Setup:** Connection Lifecycle has Online and Offline statuses with 5 minutes of wait time in-between.

{% code overflow="wrap" %}
```
10:50:00 Device disconnects from server
The server starts 5-minute timer according to settings. Device status is ONLINE

10:51:59 Device connects to the server again. Device status remains ONLINE 
```
{% endcode %}

### 3. Device disconnects, reconnects, and disconnects again. (Graceful)&#x20;

**Setup:** Connection Lifecycle has Online and Offline statuses with 5 minutes of wait time in-between.

{% code overflow="wrap" %}
```
10:50:00 Device disconnects from server
The server starts 5-minute timer according to settings. Device status is ONLINE

10:51:59 Device connects to the server again. Device status remains ONLINE

10:52:00 Device disconnects from server

10:57:00 Server sets device status to OFFLINE because timer 
started at initial device disconnection time (at 10:50:00) was reset when the device connected back again at 10:52:00
```
{% endcode %}

### 4. Device disconnects. (Non-graceful)

**Setup:** Connection Lifecycle has Online and Offline statuses with 2 minutes of wait time in-between. Heartbeat is 45 sec.

{% code overflow="wrap" %}
```
10:50:00 Device sends a message to the server

10:50:01 Device loses WiFI connection. The server is unaware of this disconnection.
The device is considered to be ONLINE.

The server waits for the heartbeatInterval (45 seconds) * 1.5 = 67 seconds. 

10:51:08 The Server closes the connection since there is no heartbeat.
The server initiates wait time between statuses. However, since the server already waited for 67sec, the server will only wait for 53sec more (120sec – 67sec = 53sec).

...no new connections from the device

10:52:01 Server applies the OFFLINE status.
```
{% endcode %}

### 5. Device disconnects, reconnects, and disconnects again, (Non-graceful)&#x20;

**Setup:** Connection Lifecycle has Online and Offline statuses with 1 minute of wait time in-between. Heartbeat is 45 sec.

{% code overflow="wrap" %}
```
10:50:00 Device sends a message to the server

10:50:01 Device loses WiFI connection. The server is unaware of this disconnection.
The device is considered to be ONLINE.

The server waits for the heartbeatInterval * 1.5 seconds = 67 seconds. 

10:51:08 The Server closes the connection since there is no heartbeat.
The server checks for wait time between statuses. It has already waited longer than 1 min, so OFFLINE status is applied immediately.
```
{% endcode %}

