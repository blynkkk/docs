# Blynk and Raspberry Pi: Tips & Tricks

#### Autostart <a id="autostart"></a>

To enable Blynk autostart for Pi, find `/etc/rc.local` file and add there:

```text
node full_path_to_your_script.js <YourAuthToken> &
```

#### Run forever <a id="run-forever"></a>

Use  `forever` utility to auto-restart your script. 

```text
npm install -g forever
```

#### Run external scripts/utilities from Blynk  <a id="run-external-scriptsutilities-from-blynk"></a>

You can run external python, batch, or just anything executable from Node.js using `child_process` module:

```text
var exec = require('child_process').exec;
exec('command', function callback(error, stdout, stderr){
    // result
});
```

#### PiBakery <a id="pibakery"></a>

[PiBakery](http://www.pibakery.org/) allows you to pre-configure Raspberry Pi, while creating SD Card.

