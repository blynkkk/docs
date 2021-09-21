# ESP8266 standalone

![](https://camo.githubusercontent.com/38e041c5e75007dc2b15300d41d13d364cd6695a/68747470733a2f2f73746174696373332e736565656473747564696f2e636f6d2f696d616765732f313133393930313035253230312e6a7067)

ESP8266-based boards, like `NodeMCU, Huzzah, WeMos D1, Seeed Wio Link, ...` can run Blynk directly on the chip, using this board support package: [https://github.com/esp8266/Arduino](https://github.com/esp8266/Arduino)

### Tutorials <a id="tutorials"></a>

* Getting started with Blynk: [https://learn.sparkfun.com/tutorials/esp8266-thing-development-board-hookup-guide/example-sketch-blink-with-blynk](https://learn.sparkfun.com/tutorials/esp8266-thing-development-board-hookup-guide/example-sketch-blink-with-blynk)
* Getting started with ESP8266: [http://www.esp8266.com/wiki/doku.php?id=getting-started-with-the-esp8266](http://www.esp8266.com/wiki/doku.php?id=getting-started-with-the-esp8266)

### Troubleshooting <a id="troubleshooting"></a>

* ESP8266 can't be powered directly from 3v3 pin on most Arduinos, as it requires more than 400 mA current supply. 
* ESP8266 flash might get broken. The code executes without problem right after flashing, but stops working after first reboot.
* This WiFi module can somehow interfere with PIR sensors -&gt; PIR sensor starts producing random values ;\)
* ESP8266 currently has troubles with connecting to **WPA2-Enterprise** networks, and WiFi hotspots that have **Captive Portal** \(webpage that requires you to sign-in to get Internet access\). 

### Low level debugging <a id="low-level-debugging"></a>

1. In the IDE switch to **Generic ESP8266** board.
2. In setup\(\) add the following as the first line:     `Serial.setDebugOutput(true);`
3. In the IDE set **Debug port** to `Serial`  and **Debug level** to `All` .

You will see a huge amount of debugging information in Serial Monitor.

