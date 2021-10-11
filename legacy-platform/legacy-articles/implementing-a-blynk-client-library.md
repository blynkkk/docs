# Implementing a Blynk client (library)

We provide a reference C++/Arduino implementation of the library. It is very extensible and modular, just look at [the list of supported hardware](http://community.blynk.cc/t/hardware-supported-by-blynk/16). Adding new connection types and Arduino-compatible boards is easy.

But some devices are programmed in other languages and environments, like:

* Vendor-specific SDK and IDE
* JavaScript, Node.JS, Espruino 
*  Python, MicroPython 
* NodeMCU, eLua

This document hints how to write a custom library.

#### Blynk library main functions <a href="blynk-library-main-functions" id="blynk-library-main-functions"></a>

* Provide easy-to use API
* Virtual pin handlers registration
* Provide comfortable wrappers for some widgets
* Manage connection
* Should support different connection type/hardware, if applicable
* Serialize/deserialize Blynk protocol
* Should be portable across similar devices (or same technology/programming language), if possible
* Should detect and notify the user about [troubles](https://github.com/blynkkk/blynk-library/blob/master/extras/docs/Troubleshooting.md) where possible (especially Flood)
* Handle direct pin operations \[optional]\


#### Adding new HW board to the Blynk mobile app <a href="adding-new-hw-board-to-the-blynk-mobile-app" id="adding-new-hw-board-to-the-blynk-mobile-app"></a>

Different boards can be added by creating JSON board description file - look at the examples [here](https://github.com/blynkkk/boards). You can send us your own board description files **for review and App integration**.

There may be a problem that you want to start testing your implementation, but your board is not listed int the Blynk App. We have a **"Generic Board"** specially for such purposes. Or you can just select UNO board and check how it works using just virtual pins. Most digital pins should also work. Analog IO/PWM will not work in general, until we add your board to the App.

#### Blynk protocol <a href="blynk-protocol" id="blynk-protocol"></a>

Blynk transfers binary messages with the following structure:

**Command  Message Id   Length/Status      Body**\
1 byte            2 bytes               2 bytes              Variable 

**Message Id** and **Length** are [big endian](http://en.wikipedia.org/wiki/Endianness#Big-endian). Body has a command-specific format.

Command and Status definitions: [BlynkProtocolDefs.h](https://github.com/blynkkk/blynk-library/blob/master/src/Blynk/BlynkProtocolDefs.h)

Another protocol description can be found [here](https://github.com/blynkkk/blynk-server/blob/master/docs/README_FOR_APP_DEVS.md).

Typical Blynk library knows how to **send**(S) and **process**(P):

```
S   BLYNK_CMD_LOGIN + auth token
SP  BLYNK_CMD_PING
SP  BLYNK_CMD_RESPONSE
SP  BLYNK_CMD_BRIDGE
SP  BLYNK_CMD_HARDWARE
S   BLYNK_CMD_TWEET
S   BLYNK_CMD_EMAIL
S   BLYNK_CMD_PUSH_NOTIFICATION
```

#### HARDWARE/BRIDGE command body <a href="hardwarebridge-command-body" id="hardwarebridge-command-body"></a>

The body of these commands are encoded as a sequence of strings, separated by **'\0'** ([Null character](http://en.wikipedia.org/wiki/Null_character)). Please note that the last value may be not [Null-terminated.In](http://null-terminated.in) the following command examples **'\0'** chars are replaced with spaces.

#### Pin mode <a href="pin-mode" id="pin-mode"></a>

PinMode command is received by library after connection, or when a mobile application starts.

```
pm <pin> <mode>
pm <pin> <mode> <pin> <mode> <pin> <mode> ...
```

Mode:

* in - INPUT
* out - OUTPUT
* pu - INPUT_PULLUP
* pd - INPUT_PULLDOWN

#### Digital pin operations <a href="digital-pin-operations" id="digital-pin-operations"></a>

Digital write:

```
dw <pin> <val>
```

Digital read:

```
dr <pin>
```

#### Analog pin operations <a href="analog-pin-operations" id="analog-pin-operations"></a>

```
aw <pin> <val>

ar <pin>
```

#### Virtual pin operations <a href="virtual-pin-operations" id="virtual-pin-operations"></a>

```
vw <pin> <param0> <param1> <param2> <param3> ...

vr <pin>
```

#### Developer notes <a href="developer-notes" id="developer-notes"></a>

* Values in HW commands are plain text.
* In response to dr/ar command, library should send dw/aw command on the same pin and with the same message id.
* These situations should cause a connection drop or reconnection attempt: Message with ID=0 is received, Message with unknown type is received

#### Example implementations <a href="example-implementations" id="example-implementations"></a>

Use these to play with the protocol and understand the basics:

* [Python + MicroPython ](https://github.com/vshymanskyy/blynk-library-python)
* [Node.js + Espruino](https://github.com/vshymanskyy/blynk-library-js)
* [Arduino](https://github.com/blynkkk/blynk-library)
* [Particle Core/Photon/Electron](https://github.com/vshymanskyy/blynk-library-spark)

#### Adding network interface <a href="adding-network-interface" id="adding-network-interface"></a>

4 entities should be created to add a new network interface to Arduino library:

1 - Select connection interface that will be used for Blynk operation. This should be something like [http://www.arduino.cc/en/Tutorial/WebClient](http://www.arduino.cc/en/Tutorial/WebClient)

Based on the API of the connection, create the Transport. Some examples may be found in the Adapters folder:

* BlynkTransportSerial
* BlynkTransportCC3000
* BlynkArduinoClient **- should be reused, if possible**

2 - Create Blynk representative class, which contains connection-specific helper functions (like begin).Examples:

* BlynkEthernet
* BlynkStream
* BlynkCC3000
* BlynkWildFire
* BlynkYun

3 - Create `BlynkSimple*`  header for your connection. This constructs main Blynk instance, so the user (mostly) doesn't need to get into such details.Examples:

* BlynkSimpleEthernet.h
* BlynkSimpleCC3000.h
* BlynkSimpleWifi.h
* BlynkSimpleUIPEthernet.h

4 - Create a simple example for your platform ;)\
\
