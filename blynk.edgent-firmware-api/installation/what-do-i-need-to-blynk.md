---
description: Step by step guide on how to install Blynk Library
---

# Install Blynk Library in Arduino IDE

#### There are three ways to install Blynk Library for Arduino IDE: <a href="#there-are-few-ways-to-install-blynk-library-for-arduino-ide" id="there-are-few-ways-to-install-blynk-library-for-arduino-ide"></a>

1. Using built-in library manager in Arduino IDE
2. Installing Blynk library as ZIP file in Arduino IDE
3. Manually install Blynk Library

### 1. Install Blynk Library using built-in library manager in Arduino IDE <a href="#1-install-blynk-library-using-built-in-library-manager-in-arduino-ide" id="1-install-blynk-library-using-built-in-library-manager-in-arduino-ide"></a>

To install a new library into your Arduino IDE you can use the Library Manager (available from IDE version 1.6.2). Open the IDE and click to the "Sketch" menu and then Include Library > Manage Libraries.

![](https://blynk.intercom-attachments-1.com/i/o/166433746/acccf446076ff541d782d143/LibraryManager\_1.png)

Then the Library Manager will open and you will find a list of libraries that are already installed or ready for installation. Search for **Blynk** library and in the version selection choose the latest version to date

![](https://downloads.intercomcdn.com/i/o/166428160/2f77559f97b573848291b0b8/Screen+Shot+2019-11-27+at+2.33.38+PM.png)

Finally click on Install and wait for the IDE to install the new library. Downloading may take time depending on your connection speed. Once it has finished, an Installed tag should appear next to the Bridge library. You can close the library manager.

You can now find the new library available in the Sketch > Include Library menu.

### 2. Install Blynk as ZIP file in Arduino IDE <a href="#2-install-blynk-as-zip-file-in-arduino-ide" id="2-install-blynk-as-zip-file-in-arduino-ide"></a>

Blynk library is available as a downloadable ZIP. Starting with Arduino IDE version 1.0.5, you can install 3rd party libraries in the IDE.&#x20;

Download Blynk Library by clicking the button: [Download Blynk Library](https://github.com/blynkkk/blynk-library/releases/latest)

{% hint style="warning" %}
Do not unzip the downloaded library, leave it as is.
{% endhint %}

In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library. At the top of the drop down list, select the option to "Add .ZIP Library''.

1. Return to the Sketch > Include Library menu. menu. You should now see the library at the bottom of the drop-down menu. It is ready to be used in your sketch. The zip file will have been expanded in the libraries folder in your Arduino sketches directory.

The Library will be available to use in sketches, but with older IDE versions examples for the library will not be exposed in the File > Examples until after the IDE has restarted.

### 3. Install Blynk library manually <a href="#3-install-blynk-library-manually" id="3-install-blynk-library-manually"></a>

Download the latest **Blynk\_Release\_vXX.zip** file from the GitHub page:[Download Blynk Library](https://github.com/blynkkk/blynk-library/releases/latest)

1. Unzip the **Blynk\_Release\_vXX.zip** archive. You will notice that archive contains several folders and several libraries.
2. Copy all of these libraries to **your sketchbook folder** of **Arduino IDE**.&#x20;

To find the location of **your sketchbook folder**, go to top menu in Arduino IDE:\
**Windows:** File → Preferences\
**Mac OS:** Arduino → Preferences

The structure of your **your sketchbook folder** should now look like this, along with your other sketches (if you have them):

```
your_sketchbook_folder/libraries/Blynk
your_sketchbook_folder/libraries/BlynkESP8266_Lib
...
your_sketchbook_folder/tools/BlynkUpdater
your_sketchbook_folder/tools/BlynkUsbScript
...
```

**☝️ Note that**&#x20;

* **libraries** should go to **libraries**&#x20;
* **tools** should go to **tools**
* If you don't have **libraries** or **tools** folders, you can create them manually.

### &#x20;<a href="#on-minute-200-of-this-video-you-can-see-the-process-of-installation-for-macos-but-its-very-similar-t" id="on-minute-200-of-this-video-you-can-see-the-process-of-installation-for-macos-but-its-very-similar-t"></a>

Arduino libraries are managed in three different places: inside the IDE installation folder, inside the core folder and in the libraries folder inside your sketchbook. The way libraries are chosen during compilation is designed to allow the update of libraries present in the distribution. This means that placing a library in the “libraries” folder in your sketchbook overrides the other libraries versions.

The same happens for the libraries present in additional cores installations. It is also important to note that the version of the library you put in your sketchbook may be lower than the one in the distribution or core folders, nevertheless it will be the one used during compilation. When you select a specific core for your board, the libraries present in the core’s folder are used instead of the same libraries present in the IDE distribution folder.

Last, but not least important is the way the Arduino Software (IDE) upgrades itself: all the files in Programs/Arduino (or the folder where you installed the IDE) are deleted and a new folder is created with fresh content.

This is why we recommend that you only install libraries to the sketchbook folder so they are not deleted during the Arduino IDE update process.

### 4. Troubleshooting 🚨 <a href="#4-troubleshooting" id="4-troubleshooting"></a>

1. If you have troubles installing Blynk library,  check [Arduino](https://www.arduino.cc/en/guide/libraries) guide for additional information.&#x20;
2. Try deleting and re-installing Blynk Library - it helps in many cases
3. Make sure you don't have any duplicates of Blynk library&#x20;
4. If you have issues - feel free to ask on our [forum](http://community.blynk.cc/). There are many Blynkers who are eager to help.

### &#x20; <a href="#h_d5153c7aee" id="h_d5153c7aee"></a>
