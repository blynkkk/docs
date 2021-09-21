---
description: Turn your things On / Off or send any data from Blynk app to hardware
---

# How to control anything with Blynk app

Blynk can control any electronics, GPIOs, relays, anything. You just need to know the basics, which are super simple.

☝️ **You need Blynk library installed. Here is the guide how to** [**install Blynk Library**](http://intercom.help/blynk/getting-started/step-by-step/how-to-install-blynk-library)**.**

There are two ways of turning things ON and OFF with Blynk: 

1. **Simple**. Directly controlling Digital I/O pins with **no coding;**
2. **Advanced**, using Virtual Pins and simple code;

In this article we will describe both cases.

  
Let's try turning on/off LED connected to **Digital Pin D3** of your hardware.  


![](https://uploads.intercomcdn.com/i/o/19421463/dfe3e0f06f459c4b9ff06fc0/LED_blink_320.gif)

### Control GPIOs with no extra coding <a id="control-gpios-with-no-extra-coding"></a>

**In Blynk app:**

1. Create a New Project \(new Auth Token will be sent to your email\);
2. Add Button Widget;
3. Go to Widget Settings;
4. Set PIN to **D3** - this where you tell the app that Button will turn ON and OFF something;
5. Set Mode to Switch;

**Preparing the basic code:**

Use our **Blynk Examples Sketch Builder** to create the code for your hardware.

[Open Blynk Examples Builder](https://examples.blynk.cc/)

1. Choose your board;
2. Choose your Connection \(WiFi, Ethernet, Bluetooth, USB, ...\);
3. Browse through examples and choose the one you need;
4. Sketch Builder will create a code for you;
5. Copy the whole code and paste it to Arduino IDE;

![](https://uploads.intercomcdn.com/i/o/19400959/c0c34377e80478a4a02354ca/examples2.gif)

### Input your Auth Token <a id="input-your-auth-token"></a>

In the example sketch find the line:

```text
char auth[] = "YourAuthToken";
```

Change it with your own Auth Token \(it should be in your email inbox after you created the Project in the Blynk app\).

Now this line should look similar to this:

```text
char auth[] = "53e4da8793764b6197fc44a673ce4e21";
```

🔥 Flash the example code to your hardware.

### Advanced. Using Virtual Pins to turn things ON and OFF <a id="advanced-using-virtual-pins-to-turn-things-on-and-off"></a>

Sometimes, triggering single Digital Pin is not enough. Sometimes you need more flexibility. For example, how to control brightness of 3 LEDs using one Slider Widget, or trigger a a whole set of actions with 1 button?

We've got you covered. 

1. In Blynk app add a Slider Widget and set it to use **Virtual Pin V1**;
2. Change [this basic sketch](http://examples.blynk.cc/?board=ESP8266&shield=ESP8266%20WiFi&example=GettingStarted%2FGetData) to match your hardware and connection type;
3. 🔥 Flash the example code to your hardware;

Let's try to understand the code. Look at this block:

```text
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
}
```

This is where we tell the hardware what to do when there is a WRITING command from Blynk app to **Virtual Pin V1.** 

Our Slider widget sends data to V1:

```text
BLYNK_WRITE(V1) //something in Blynk app WRITEs to pin V1 
```

☝️ **BLYNK\_WRITE should be placed OUTSIDE of void loop\(\);**  
  
The next line is to get the actual incoming value:

```text
int pinValue = param.asInt();
```

Where, is how you define the incoming data type:

```text
param.asInt();
```

If you need other variable type, you can also use:

```text
param.asInt();    // get value as an Integer
param.asFloat();  // get value as a Float
param.asDouble(); // get value as a Double
param.asStr();    // get value as a String
```

...and then we just print the slider value to Serial Monitor

```text
Serial.print("V1 Slider value is: ");
Serial.println(pinValue); 
```

This approach gives you endless opportunities on how to use incoming data from the app in a very flexible way.  
  
For example, you can create a set of actions in the function that will be triggered by one click of the Button:

```text
void myMorning(){
  
  // make me coffee
  // prepare breakfast
  // clean my shoes
 
}


BLYNK_WRITE(V5) // Button Widget writes to Virtual Pin V5 
{
  if(param.asInt() == 1) {     // if Button sends 1
    myMorning();             // start the function
  }
}
```

**---**

**If you have questions or something is not working, visit our 👥** [**community**](https://community.blynk.cc/) **page.**

Also, full 📗 documentation is [here](http://docs.blynk.cc/).

