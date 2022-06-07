# Blynk and Raspberry Pi: Tips & Tricks

{% hint style="warning" %}
This documentation is for the LEGACY version of Blynk platform which is no longer supported and will be shut down.&#x20;

You can sign up for the current version of Blynk platform [here](http://blynk.cloud/dashboard/register).

The new mobile apps can be downloaded from [App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868) and [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk\&hl=en\&gl=US).

The actual Blynk documentation is [here](https://docs.blynk.io/).
{% endhint %}

#### Autostart <a href="#autostart" id="autostart"></a>

To enable Blynk autostart for Pi, find `/etc/rc.local` file and add there:

```
node full_path_to_your_script.js <YourAuthToken> &
```

#### Run forever <a href="#run-forever" id="run-forever"></a>

Use  `forever` utility to auto-restart your script.&#x20;

```
npm install -g forever
```

#### Run external scripts/utilities from Blynk  <a href="#run-external-scriptsutilities-from-blynk" id="run-external-scriptsutilities-from-blynk"></a>

You can run external python, batch, or just anything executable from Node.js using `child_process` module:

```
var exec = require('child_process').exec;
exec('command', function callback(error, stdout, stderr){
    // result
});
```

#### PiBakery <a href="#pibakery" id="pibakery"></a>

[PiBakery](http://www.pibakery.org/) allows you to pre-configure Raspberry Pi, while creating SD Card.
