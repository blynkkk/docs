# Install ESP8266 core for Arduino IDE



1. Install latest [Arduino IDE](https://www.arduino.cc/en/Main/Software).
2. Download and install Blynk library\
   (follow instructions of the latest [release package](https://github.com/blynkkk/blynk-library/releases/latest)).

Then, open the Arduino IDE, then select in the menu: `File -> Preferences`\
(`Arduino -> Preferences`  for Mac).

Click on **Additional Boards Manager URLs** button and add this link:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

![](https://uploads.intercomcdn.com/i/o/20866093/60ae89223dd38335c61e0f68/file\_preferences.png)

In the Arduino IDE open: `Tools -> Board -> Boards Manager` .\
Search for `esp8266` , and install it:

![](https://uploads.intercomcdn.com/i/o/20866111/4bfaa4bd6bb2547a890ccfd3/boards\_manager.png)

### Troubleshooting <a href="#troubleshooting" id="troubleshooting"></a>

In case you see Error downloading [http://downloads.arduino.cc/packages/package\_index.json](http://downloads.arduino.cc/packages/package\_index.json) like this:

![](https://uploads.intercomcdn.com/i/o/20866154/50e8eefe4218e5a69fb62f03/error\_download\_mac.png)

You need to find folder `Arduino15`  or `.Arduino15`  and remove all files inside with package word in name.\
