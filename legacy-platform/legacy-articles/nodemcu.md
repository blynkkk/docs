# NodeMCU



First, follow [this guide](http://help.blynk.cc/hardware-and-libraries/install-esp8266-core-for-arduino-ide) if you haven't set up Arduino Core fore ESP8266 yet.

### Uploading Blynk example to NodeMCU <a id="uploading-blynk-example-to-nodemcu"></a>

Open `File -> Examples -> Blynk -> Boards_WiFi -> NodeMCU` ![](https://uploads.intercomcdn.com/i/o/20865565/ce4c830ed1c8884b0e83e835/nodeMCU_in_menu.png)

Put your auth token from Blynk app and your WiFi credentials in sketch:

```text
 // You should get Auth Token in the Blynk App.
 // Go to the Project Settings (nut icon).
 char auth[] = "YourAuthToken";

 // Your WiFi credentials.
 // Set password to "" for open networks.
 char ssid[] = "YourNetworkName";
 char pass[] = "YourPassword";
```

  
In `Tools -> Board`  menu, select `NodeMCU 1.0 (ESP-12E Module)`![](https://uploads.intercomcdn.com/i/o/20865600/bbc02100531d4fd5ee0fe5cf/nodemcu_board_type.png)

Click on `Verify`  button and make sure that example compiled correctly:![](https://uploads.intercomcdn.com/i/o/20865541/17a6f6d785ba1716ab033de0/verify.png)

Select the port of your board in `Tools -> Port` menu.  
In `Tools -> Upload Speed` , select 115200 \(higher values may also work for you\).  
If you don't know how to select the port check this [troubleshooting section](https://github.com/blynkkk/blynk-library/tree/master/examples/Boards_WiFi/NodeMCU#how-to-pick-the-correct-port) or if you don't see any ports, check this [troubleshooting section](https://github.com/blynkkk/blynk-library/tree/master/examples/Boards_WiFi/NodeMCU#no-ports-appear-when-board-is-plugged-in).

Click the `Upload`  button. \(You should see a progress bar in the console, followed by Done uploading message in the status panel. After this process is finished, LED should start blinking blue: which means the board is waiting for configuration\).

The firmware was successfully loaded and is ready. Now go to app and try to light on board LED \(pin D4\).  


### What next? <a id="what-next"></a>

Read about [**Virtual Pins**](http://help.blynk.cc/blynk-basics/what-is-virtual-pins) concept and unleash full power of Blynk.  
Blynk supports huge amount of board types. [Check if your favourite is on the list!](https://github.com/blynkkk/blynkkk.github.io/blob/master/SupportedHardware.md)  
Our library is Open Source Software. [Give](https://github.com/blynkkk/blynk-library/blob/master/README.md) us a star on GitHub. 

### Troubleshooting <a id="troubleshooting"></a>

#### Arduino IDE upload issue <a id="arduino-ide-upload-issue"></a>

During sketch upload you may see next errors :

```text
error: espcomm_open failed
error: espcomm_upload_mem failed
```

This means you have no drivers installed. Please follow next section.

#### No ports appear, when board is plugged in <a id="no-ports-appear-when-board-is-plugged-in"></a>

For Windows or OS X you may need to install drivers for your USB to Serial chipset:

* [СP210x \(all systems\)](https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx)
* [FTDI \(all systems\)](http://www.ftdichip.com/Drivers/VCP.htm)
* [CH34x for Windows](http://www.arduined.eu/ch340-windows-8-driver-download/)
* [CH34x for OSX](https://blog.sengotta.net/signed-mac-os-driver-for-winchiphead-ch340-serial-bridge/)

For Ubuntu / linux the drivers should be already there \(the board is detected\), but it may happen that when you try flashing the board, an error appears: `Error opening serial port...` If you get this error, you need to set serial port permission.  
Open terminal, and run command:

```text
sudo usermod -a -G dialout $USER
```

**Note:** You will need to reboot \(or just log out and log in\) for this change to take effect.

If drivers are installed and you still don't see the port, please try to unplug and plug your NodeMCU board.  


#### How to pick the correct port? <a id="how-to-pick-the-correct-port"></a>

1. Ensure that your board is disconnected;
2. Remember which ports are available in your **Tools -&gt; Board** menu;
3. Connect your board and wait 30 seconds;
4. Select the new port that appeared in **Tools -&gt; Board** menu \(the one that was missing before\);

