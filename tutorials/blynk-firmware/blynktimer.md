# BlynkTimer

It’s important to send data in intervals and keep the void loop\(\) as clean as possible.

`BlynkTimer` allows you to send data periodically with given intervals not interfering with Blynk library routines `Blynk Timer` inherits [SimpleTimer Library](http://playground.arduino.cc/Code/SimpleTimer), a well known and widely used library to time multiple events on hardware. `BlynkTimer` is included in Blynk library by default and there is no need to install SimpleTimer separately or include `SimpleTimer.h`

* A single `BlynkTimer` object allows to schedule up to 16 timers
* Improved compatibility with boards like `Arduino 101`, `Intel Galileo`, etc.
* When a timer struggles to run multiple times \(due to a blocked `loop`\), it just skips all the missed intervals, and calls your function only once. This differs from `SimpleTimer`, which could call your function multiple times in this scenario.

For more information on timer usage, please see: [http://playground.arduino.cc/Code/SimpleTimer](http://playground.arduino.cc/Code/SimpleTimer)  
And here is a BlynkTimer [example sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/PushData/PushData.ino#L30).

Please also remember that a single `BlynkTimer` can schedule many timers, so most probably you need only one instance of BlynkTimer in your sketch.

#### BLYNK\_WRITE\(vPIN\) <a id="blynk-firmware-blynktimer-blynk_writevpin"></a>

`BLYNK_WRITE` is a function called every time device gets an update of Virtual Pin value from the server \(or app\):

To read the received data use:

```text
BLYNK_WRITE(V0)
{   
  int value = param.asInt(); // Get value as integer

  // The param can contain multiple values, in such case:
  int x = param[0].asInt();
  int y = param[1].asInt();
}
```

**`BLYNK_WRITE` can’t be used inside of any loop or function. It’s a standalone function.**

**Note:** For virtual pins with numbers &gt; 127, please use `BLYNK_WRITE_DEFAULT()` API

#### BLYNK\_READ\(vPIN\) <a id="blynk-firmware-blynktimer-blynk_readvpin"></a>

`BLYNK_READ` is function called when device is requested to send it’s current value of Virtual Pin to the server. Normally, this function should contain `Blynk.virtualWrite` call\(s\).

```text
BLYNK_READ(V0)
{
  Blynk.virtualWrite(V0, newValue);
}
```

**Note:** For virtual pins with numbers &gt; 127, please use `BLYNK_READ_DEFAULT()` API

#### BLYNK\_WRITE\_DEFAULT\(\) <a id="blynk-firmware-blynktimer-blynk_write_default"></a>

Redefines the handler for all pins that are not covered by custom `BLYNK_WRITE` functions.

```text
BLYNK_WRITE_DEFAULT()
{
  int pin = request.pin;      // Which exactly pin is handled?
  int value = param.asInt();  // Use param as usual.
}
```

#### BLYNK\_READ\_DEFAULT\(\) <a id="blynk-firmware-blynktimer-blynk_read_default"></a>

Redefines the handler for all pins that are not covered by custom `BLYNK_READ` functions.

```text
BLYNK_READ_DEFAULT()
{
  int pin = request.pin;      // Which exactly pin is handled?
  Blynk.virtualWrite(pin, newValue);
}
```

#### BLYNK\_CONNECTED\(\) <a id="blynk-firmware-blynktimer-blynk_connected"></a>

Use this function when you need to run certain routine when hardware connects to Blynk Cloud or private server. It’s common to call sync functions inside of this function.

```text
BLYNK_CONNECTED() {
// Your code here
}
```

#### BLYNK\_APP\_CONNECTED\(\) <a id="blynk-firmware-blynktimer-blynk_app_connected"></a>

This function is called every time Blynk app client connects to Blynk server.

```text
BLYNK_APP_CONNECTED() {
// Your code goes here
}
```

**Note: Enable this feature in Project Settings first:**

![](https://docs.blynk.cc/images/app_connected_setting.png)

[Example](https://github.com/blynkkk/blynk-library/blob/master/examples/More/AppConnectedEvents/AppConnectedEvents.ino)

#### BLYNK\_APP\_DISCONNECTED\(\) <a id="blynk-firmware-blynktimer-blynk_app_disconnected"></a>

This function is called every time the Blynk app disconnects from Blynk Cloud or private server.

```text
BLYNK_APP_DISCONNECTED() {
// Your code here
}
```

**Note: Enable this feature in Project Settings first:**

![](https://docs.blynk.cc/images/app_connected_setting.png)

[Example](https://github.com/blynkkk/blynk-library/blob/master/examples/More/AppConnectedEvents/AppConnectedEvents.ino)

#### Blynk.syncAll\(\) <a id="blynk-firmware-blynktimer-blynksyncall"></a>

Requests all stored on the server latest values for all widgets. All analog/digital/virtual pin values and states will be set to the latest stored value. Every virtual pin will generate BLYNK\_WRITE\(\) event.

```text
BLYNK_CONNECTED() {
    Blynk.syncAll();
}
```

#### Blynk.syncVirtual\(vPin\) <a id="blynk-firmware-blynktimer-blynksyncvirtualvpin"></a>

This command updates individual Virtual Pin to the latest stored value on the server. When it’s used, a corresponding `BLYNK_WRITE` handler is called.

```text
Blynk.syncVirtual(V0);
```

To update multiple pins, use:

```text
Blynk.syncVirtual(V0, V1, V6, V9, V16);
```

#### Blynk.setProperty\(vPin, “property”, value\) <a id="blynk-firmware-blynktimer-blynksetpropertyvpin-property-value"></a>

This command allows [changing widget properties](https://docs.blynk.cc/#blynk-main-operations-change-widget-properties)

