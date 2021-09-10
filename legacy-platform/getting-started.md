---
description: >-
  Does my hardware work with Blynk? Which example code should I use with my
  hardware?
---

# How to find code for my hardware?

Blynk works with hundreds of hardware models and connection types. We prepared **Blynk Examples Sketch Builder** that allows you to create example code for your hardware.

### ⚙️ Find a full list of all supported hardware [here](https://github.com/blynkkk/blynkkk.github.io/blob/master/SupportedHardware.md) <a id="-find-a-full-list-of-all-supported-hardware-here"></a>

☝️ **Before moving forward, make sure you have Blynk Library properly installed.**  


### Find the example code for your hardware <a id="find-the-example-code-for-your-hardware"></a>

[Open Blynk Examples Builder](http://examples.blynk.cc/)![](https://uploads.intercomcdn.com/i/o/19400959/c0c34377e80478a4a02354ca/examples2.gif)

1. Choose your board
2. Choose your Connection \(WiFi, Ethernet, Bluetooth, USB...\)
3. Browse through examples and choose the one you need
4. Sketch Builder will create a sketch for you.
5. Copy the whole code and paste it to Arduino IDE

![](https://uploads.intercomcdn.com/i/o/19400959/c0c34377e80478a4a02354ca/examples2.gif)

### Input your Auth Token <a id="input-your-auth-token"></a>

In the example sketch find the line:

```text
char auth[] = "YourAuthToken";
```

Change it with your own Auth Token \(it should be in your email inbox after you created the Project in the Blynk app.

Now this line should look similar to this:

```text
char auth[] = "53e4da8793764b6197fc44a673ce4e21";
```

🔥 Flash the example code to your hardware

### Done! Now go and try other examples: <a id="done-now-go-and-try-other-examples"></a>

### Find the example code for your hardware <a id="find-the-example-code-for-your-hardware"></a>

