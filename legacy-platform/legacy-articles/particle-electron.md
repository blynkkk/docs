# Particle Electron

{% hint style="warning" %}
This documentation is for the LEGACY version of Blynk platform which is no longer supported and will be shut down.&#x20;

You can sign up for the current version of Blynk platform [here](http://blynk.cloud/dashboard/register).

The new mobile apps can be downloaded from [App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868) and [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk\&hl=en\&gl=US).

The actual Blynk documentation is [here](https://docs.blynk.io/).
{% endhint %}



![](https://s3.amazonaws.com/uploads.intercomcdn.com/i/o/20403616/72edd18a5ca2deb701801756/687474703a2f2f7777772e7468656d616b657273776f726b62656e63682e636f6d2f73697465732f64656661756c742f66696c65732f656c656374726f6e2d30333638303464312e6a7067)

### Getting Started <a href="#getting-started" id="getting-started"></a>

To start with Particle Electron, please refer to [this example](https://github.com/vshymanskyy/blynk-library-spark/blob/master/examples/02\_Particle\_Electron/02\_Particle\_Electron.ino).

### Troubleshooting <a href="#troubleshooting" id="troubleshooting"></a>

* If you see the `Device Offline` or `Invalid Auth Token` messages, please check this part of the example:

```
// Run command "ping blynk-cloud.com", and set Blynk IP to the shown address
#define BLYNK_IP IPAddress(45,55,130,102)
```

Note, that this is a temporary measure.

* There were reports that some versions of Electron firmware failed to work with Blynk. Version `0.6.0` is recommended, and `0.5.3` is confirmed to work fine.

### Attention! <a href="#attention" id="attention"></a>

Blynk can consume quite a lot of data! Use carefully not no overpay for the data plan.\
&#x20;Each call to `virtualWrite()`, or `setProperty()`, and most widget API calls will consume some data. Also, Blynk sends "heartbeat" messages with a fixed interval (defaults to 10 seconds), to keep the network connection alive. Each heartbeat uses \~90 bytes of data. You can modify this interval, putting this line on the top of your sketch (before including Blynk headers):

```
// Set Blynk hertbeat interval (in seconds)
#define BLYNK_HEARTBEAT 60
```

Please choose the one that works best for you.\
