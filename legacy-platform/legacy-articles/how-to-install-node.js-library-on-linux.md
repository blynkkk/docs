---
hidden: true
---

# How to install Node.js library on Linux

{% hint style="warning" %}
This documentation is for the LEGACY version of Blynk platform which is no longer supported and will be shut down.&#x20;

You can sign up for the current version of Blynk platform [here](http://blynk.cloud/dashboard/register).

The new mobile apps can be downloaded from [App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868) and [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk\&hl=en\&gl=US).

The actual Blynk documentation is [here](https://docs.blynk.io/).
{% endhint %}

First of all, you need to install Node.js.

Before updating Node.js, please be sure to remove old versions:

```
sudo apt-get purge node nodejs node.js -y
sudo apt-get autoremove
```

### Automatic Node.js installation <a href="#automatic-nodejs-installation" id="automatic-nodejs-installation"></a>

Add repositories:

```
curl -sL https://deb.nodesource.com/setup_6.x | sudo -E bash -
```

Install Node.js:

```
sudo apt-get update && sudo apt-get upgrade
sudo apt-get install build-essential nodejs -y
```

### Manual Node.js installation <a href="#manual-nodejs-installation" id="manual-nodejs-installation"></a>

Automatic install might not work for you, in this case you can perform manual installation.\
If `uname -m` gives you **armv6l** (on Raspberry Pi, usually), try this:

```
sudo su

cd /opt

wget https://nodejs.org/dist/v6.9.5/node-v6.9.5-linux-armv6l.tar.gz -O - | tar -xz
mv node-v6.9.5-linux-armv6l nodejs

apt-get update && apt-get upgrade
apt-get install build-essential

ln -s /opt/nodejs/bin/node /usr/bin/node
ln -s /opt/nodejs/bin/node /usr/bin/nodejs
ln -s /opt/nodejs/bin/npm /usr/bin/npm

exit

export PATH=$PATH:/opt/nodejs/bin/
```

### Check your Node.js and npm installation <a href="#check-your-nodejs-and-npm-installation" id="check-your-nodejs-and-npm-installation"></a>

```
pi@raspberrypi:/ $ node --version
v6.9.5

pi@raspberrypi:/ $ npm -v
3.10.10
```

### Install Blynk globally <a href="#install-blynk-globally" id="install-blynk-globally"></a>

```
sudo npm install blynk-library -g
sudo npm install onoff -g
```

Run default Blynk client (replace `YourAuthToken`):

```
export PATH=$PATH:/opt/nodejs/bin/
unset NODE_PATH
blynk-client YourAuthToken
```

### Creating a new Node.js project with Blynk <a href="#creating-a-new-nodejs-project-with-blynk" id="creating-a-new-nodejs-project-with-blynk"></a>

Installing Blynk globally may not work or can be undesired.\
In this case, you need to create a new Node.js module with local Blynk library dependency.

```
mkdir my-awesome-project
cd my-awesome-project
npm init
```

It will prompt you for general information about your project and create a `package.json` file (project description). Next, add Blynk to your project:&#x20;

```
npm install blynk-library --save
```

You can also install onoff, if you want (allows direct pin operations):

```
npm install onoff --save
```

Now create your main script file `index.js` (just replace `YourAuthToken`):

```
var Blynk = require('blynk-library');

var AUTH = 'YourAuthToken';

var blynk = new Blynk.Blynk(AUTH);

var v1 = new blynk.VirtualPin(1);
var v9 = new blynk.VirtualPin(9);

v1.on('write', function(param) {
  console.log('V1:', param[0]);
});

v9.on('read', function() {
  v9.write(new Date().getSeconds());
});
```

&#x20;This is it. Run your project:

```
node index.js
```

You should see something like:

```
OnOff mode
Connecting to: blynk-cloud.com 8441
SSL authorization...
Connected
Authorized
```

Write our own script based on [examples](https://github.com/vshymanskyy/blynk-library-js/tree/master/examples)!<br>

### What next? <a href="#what-next" id="what-next"></a>

Read about [**Virtual Pins**](http://help.blynk.cc/blynk-basics/what-is-virtual-pins) concept and unleash full power of Blynk.\
Blynk supports huge amount of board types. [Check if your favourite is on the list!](https://github.com/blynkkk/blynkkk.github.io/blob/master/SupportedHardware.md)\
Our library is Open Source Software. [Give](https://github.com/blynkkk/blynk-library/blob/master/README.md) us a star on GitHub.<br>

### Troubleshooting <a href="#troubleshooting" id="troubleshooting"></a>

If you are trying to connect to Blynk cloud, and get an error like:

```
npm ERR! Error: SSL Error: CERT_NOT_YET_VALID
```

you should use the `date` command to update current system time.<br>

### Further reading <a href="#further-reading" id="further-reading"></a>

[Instructables: Use DHT11/DHT12 sensors with Raspberry Pi and Blynk](http://www.instructables.com/id/Raspberry-Pi-Nodejs-Blynk-App-DHT11DHT22AM2302/?ALLSTEPS)\
[Node.js vs C++ library](http://help.blynk.cc/hardware-and-libraries/nodejs-vs-c-library)<br>
