# How to install Node.js library on Linux

First of all, you need to install Node.js.

Before updating Node.js, please be sure to remove old versions:

```text
sudo apt-get purge node nodejs node.js -y
sudo apt-get autoremove
```

### Automatic Node.js installation <a id="automatic-nodejs-installation"></a>

Add repositories:

```text
curl -sL https://deb.nodesource.com/setup_6.x | sudo -E bash -
```

Install Node.js:

```text
sudo apt-get update && sudo apt-get upgrade
sudo apt-get install build-essential nodejs -y
```

### Manual Node.js installation <a id="manual-nodejs-installation"></a>

Automatic install might not work for you, in this case you can perform manual installation.  
If `uname -m` gives you **armv6l** \(on Raspberry Pi, usually\), try this:

```text
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

### Check your Node.js and npm installation <a id="check-your-nodejs-and-npm-installation"></a>

```text
pi@raspberrypi:/ $ node --version
v6.9.5

pi@raspberrypi:/ $ npm -v
3.10.10
```

### Install Blynk globally <a id="install-blynk-globally"></a>

```text
sudo npm install blynk-library -g
sudo npm install onoff -g
```

Run default Blynk client \(replace `YourAuthToken`\):

```text
export PATH=$PATH:/opt/nodejs/bin/
unset NODE_PATH
blynk-client YourAuthToken
```

### Creating a new Node.js project with Blynk <a id="creating-a-new-nodejs-project-with-blynk"></a>

Installing Blynk globally may not work or can be undesired.  
In this case, you need to create a new Node.js module with local Blynk library dependency.

```text
mkdir my-awesome-project
cd my-awesome-project
npm init
```

It will prompt you for general information about your project and create a `package.json` file \(project description\). Next, add Blynk to your project: 

```text
npm install blynk-library --save
```

You can also install onoff, if you want \(allows direct pin operations\):

```text
npm install onoff --save
```

Now create your main script file `index.js` \(just replace `YourAuthToken`\):

```text
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

 This is it. Run your project:

```text
node index.js
```

You should see something like:

```text
OnOff mode
Connecting to: blynk-cloud.com 8441
SSL authorization...
Connected
Authorized
```

Write our own script based on [examples](https://github.com/vshymanskyy/blynk-library-js/tree/master/examples)!  


### What next? <a id="what-next"></a>

Read about [**Virtual Pins**](http://help.blynk.cc/blynk-basics/what-is-virtual-pins) concept and unleash full power of Blynk.  
Blynk supports huge amount of board types. [Check if your favourite is on the list!](https://github.com/blynkkk/blynkkk.github.io/blob/master/SupportedHardware.md)  
Our library is Open Source Software. [Give](https://github.com/blynkkk/blynk-library/blob/master/README.md) us a star on GitHub.  


### Troubleshooting <a id="troubleshooting"></a>

If you are trying to connect to Blynk cloud, and get an error like:

```text
npm ERR! Error: SSL Error: CERT_NOT_YET_VALID
```

you should use the `date` command to update current system time.  


### Further reading <a id="further-reading"></a>

[Instructables: Use DHT11/DHT12 sensors with Raspberry Pi and Blynk](http://www.instructables.com/id/Raspberry-Pi-Nodejs-Blynk-App-DHT11DHT22AM2302/?ALLSTEPS)  
[Node.js vs C++ library](http://help.blynk.cc/hardware-and-libraries/nodejs-vs-c-library)  


