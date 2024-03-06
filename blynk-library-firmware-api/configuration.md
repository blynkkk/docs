# Configuration

## Blynk.begin()

The easiest way to configure Blynk is to use `Blynk.begin()`:

```cpp
Blynk.begin(auth, ...);
```

It has multiple parameters for different hardware models and it also depends on the type of connection. Follow the example sketches for your specific hardware model.

What happens inside of `Blynk.begin()` function:

1. Connection to the network (WiFi, Ethernet, ...)
2. Call of `Blynk.config(...)` to set Auth Token, Server Address, etc.
3. Attempts to connect to the server once (can block for more than 30s)

If your shield/connection type is not supported yet - you can implement it by yourself. [Here are some examples](https://github.com/blynkkk/blynk-library/tree/master/examples).

## Blynk.config()

`config()` allows you to manage network connection. You can set up your connection type (WiFi, Ethernet, ...) by yourself, and then call:

```cpp
Blynk.config(auth, server, port);
```

or just

```cpp
Blynk.config(auth);
```

**NOTE: After `Blynk.config(...)` is called, your hardware is not yet connected to the server.** It will try to connect while until it hits first instance of `Blynk.run()` or `Blynk.connect()`routine.\
To skip connecting to the server or to disconnect manually, call `Blynk.disconnect()` after configuration.

Use `connectWiFi` to conveniently set up WiFi connection:

```cpp
Blynk.connectWiFi(ssid, pass);
```

To connect to open WiFi networks, set pass to an empty string (`""`).
