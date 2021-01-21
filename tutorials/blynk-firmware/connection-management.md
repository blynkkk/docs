# Connection Management

There are several functions to help with connection management:

#### Blynk.connect\(\) <a id="blynk-firmware-connection-management-blynkconnect"></a>

This functions will continue trying to connect to Blynk server. Returns `true` when connected, `false` if timeout have been reached. Default timeout is 30 seconds.

```text
bool result = Blynk.connect();
bool result = Blynk.connect(timeout);
```

#### Blynk.disconnect\(\) <a id="blynk-firmware-connection-management-blynkdisconnect"></a>

Disconnects hardware from Blynk server:

```text
Blynk.disconnect();
```

#### Blynk.connected\(\) <a id="blynk-firmware-connection-management-blynkconnected"></a>

Returns `true` when hardware is connected to Blynk Server, `false` if there is no active connection to Blynk server.

```text
bool result = Blynk.connected();
```

#### Blynk.run\(\) <a id="blynk-firmware-connection-management-blynkrun"></a>

This function should be called frequently to process incoming commands and perform housekeeping of Blynk connection. It is usually called in `void loop() {}`.

This command can be initiated it in other places of your code unless you run out of heap memory \(in the cascaded functions with local memory\).

For example, it is not recommended to call `Blynk.run()` inside of the `BLYNK_READ` and `BLYNK_WRITE` functions on low-RAM devices.

