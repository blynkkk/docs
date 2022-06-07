# USB Serial

{% hint style="warning" %}
This documentation is for the LEGACY version of Blynk platform which is no longer supported and will be shut down.&#x20;

You can sign up for the current version of Blynk platform [here](http://blynk.cloud/dashboard/register).

The new mobile apps can be downloaded from [App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868) and [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk\&hl=en\&gl=US).

The actual Blynk documentation is [here](https://docs.blynk.io/).
{% endhint %}

If you don't have any shield and your hardware doesn't have any connectivity, you can still use Blynk – directly over USB.![](https://camo.githubusercontent.com/045888bbf8448f490567570ee13e99a9324e7157/68747470733a2f2f696d616765732e696e646965676f676f2e636f6d2f66696c655f6174746163686d656e74732f3936383239392f66696c65732f32303134313032393036333834312d706c75672e706e673f31343134353839393231)

#### Getting Started <a href="#getting-started" id="getting-started"></a>

1. Optional, but recommended.Connect additional USB-Serial adapter to your device to see the debug prints.
2. Open [Arduino Serial USB example](https://github.com/blynkkk/blynk-library/blob/master/examples/Boards\_USB\_Serial/Arduino\_Serial\_USB/Arduino\_Serial\_USB.ino) and change [Auth Token](http://docs.blynk.cc/#getting-started-getting-started-with-application-4-auth-token)
3. Run the blynk-ser script, located in scripts folder:

* Windows: My Documents\Arduino\libraries\Blynk\scripts
* Mac: \~/Documents/Arduino/libraries/Blynk/scripts
* Linux: \~/Arduino/libraries/Blynk/scripts

The script is simply redirecting traffic to Blynk Cloud.

You can specify port, baud rate, and server endpoint like this:\
`./blynk-ser.sh -c <serial port> -b <baud rate> -s <server address> -p <server port>`

For instance:\
`./blynk-ser.sh -c /dev/ttyACM0 -b 9600 -s blynk-cloud.com -p 8442`

Run `blynk-ser.sh -h` for more information

Be sure to select the right serial port (there may be multiple).\
\
**Attention!** Arduino IDE may complain with "programmer is not responding". You need to terminate script before uploading new sketch.&#x20;

#### On Windows <a href="#on-windows" id="on-windows"></a>

Open `cmd.exe` (you may need to "Run as Administrator")\
Navigate to scripts folder:

```
cd C:\...\libraries\Blynk\scripts
```

Run `blynk-ser.bat` file. For example : `blynk-ser.bat -c COM4` (where COM4 is port with your Arduino)And press "Enter", press "Enter" and press "Enter"

#### On Linux and Mac <a href="#on-linux-and-mac" id="on-linux-and-mac"></a>

Navigate to scripts folder:

```
cd User$/Documents/Arduino/libraries/Blynk/scripts
```

When inside this folder, run:

```
user:scripts User$ ./blynk-ser.sh
```

You may need to run it with `sudo`:

```
user:scripts User$ sudo ./blynk-ser.sh
```

This is what you'll see in Terminal app on Mac (usbmodem address can be different):

```
[ Press Ctrl+C to exit ]
/dev/tty.usbmodem not found.
Select serial port [ /dev/tty.usbmodem1451 ]: 
```

Copy the serial port address: `/dev/tty.usbmodem1451` and paste it back:

```
Select serial port [ /dev/tty.usbmodem1451 ]: /dev/tty.usbmodem1451
```

After you press Enter, you should see an output similar to this:

```
Resetting device /dev/tty.usbmodem1451...
Connecting: GOPEN:/dev/tty.usbmodem1451,raw,echo=0,clocal=1,cs8,nonblock=1,ixoff=0,ixon=0,ispeed=9600,ospeed=9600,crtscts=0 <-> openssl-connect:blynk-cloud.com:8441,cafile=/Users/.../server.crt,nodelay
2015/10/03 00:29:45 socat[30438.2046857984] N opening character device "/dev/tty.usbmodem1451" for reading and writing
2015/10/03 00:29:45 socat[30438.2046857984] N opening connection to LEN=16 AF=2 45.55.195.102:8441
2015/10/03 00:29:45 socat[30438.2046857984] N successfully connected from local address LEN=16 AF=2 192.168.0.2:56821
2015/10/03 00:29:45 socat[30438.2046857984] N SSL connection using AES128-SHA
2015/10/03 00:29:45 socat[30438.2046857984] N starting data transfer loop with FDs [3,3] and [4,4]
```

#### Additional materials: <a href="#additional-materials" id="additional-materials"></a>

* [Instructables: Control Arduino with Blynk over USB](http://www.instructables.com/id/Control-arduino-using-Blynk-over-usb/)

**Video tutorials :** \
[https://www.youtube.com/watch?v=fgzvoan\_3\_w](https://www.youtube.com/watch?v=fgzvoan\_3\_w)

[https://www.youtube.com/watch?v=I\_hgIj2FdPI](https://www.youtube.com/watch?v=I\_hgIj2FdPI)
