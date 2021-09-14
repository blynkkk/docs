---
description: Troubleshooting of one of the most popular mistakes of newbie Blynk users.
---

# Keep your void loop\(\) clean

### Getting "Device is Offline" message? Not seeing your data in Blynk app?  Getting "Flood Error"? <a id="getting-device-is-offline-message"></a>

Most likely you are making an error by sending data to Blynk incorrectly. This article will help you to understand and troubleshoot this issue.

### Intro <a id="intro"></a>

The code should be familiar to anyone who have ever tinkered with MCUs like Arduino and the likes: 

```text
void loop() 
{
  sensorValue = analogRead(A5);  // reading sensor analog pin value
  Serial.println(sensorValue);   // printing value to Serial Monitor
}
```

  
Accordingly to this [article](https://learn.sparkfun.com/blog/1687), this loop will execute at a speed of about **117 kHz.**  This means that everything you put into `void loop()`, your Arduino will execute about **117,000** times/ second.

To time out Serial Prints you would just add a `delay()` , right?

```text
void loop() 
{
  sensorValue = analogRead(A5);  // reading sensor analog pin value
  Serial.println(sensorValue);   // printing value to Serial Monitor
 👉delay(1000);                  // stop the code for 1 second
}
```

`delay()`  is a blocking function that completely stops your MCU for a specified time before resuming the loop execution.

It would work for a regular application, but not for the Internet Of Things applications like Blynk. See below why.

### Problem <a id="problem"></a>

Imagine you want to send `sensorValue`  to Blynk app and write such code:  

```text
void loop() 
{
  sensorValue = analogRead(A5);         // reading sensor analog pin value
  Serial.println(sensorValue);          // printing value to Serial Monitor 

 👉Blynk.run();                         // run Blynk magic  
 👉Blynk.virtualWrite(V1, sensorValue); // sending value to Blynk app
}
```

This would work for a regular electronics project, but not for the Internet of Things, and not for Blynk, because:

#### ⚠️You are spamming Blynk Cloud <a id="you-are-spamming-blynk-cloud"></a>

As it was described above, everything in the `void loop()`  will be executed many times per second. 

So if you use `Blynk.virtualWrite(V1, sensorValue)` in the loop, you send gazillion messages to Blynk Cloud from your hardware. When it happens, Blynk automatically **disconnects** your device for spamming. Sorry.

  
   
A logical step would be to add a `delay()` ...

```text
void loop() 
{
  sensorValue = analogRead(A5);        // reading sensor analog pin value
  Serial.println(sensorValue);         // printing value to Serial Monitor 

  Blynk.run();                         // run Blynk magic  
  Blynk.virtualWrite(V1, sensorValue); // sending value to Blynk app
  
 👉delay(1000);                        // stop the code for 1 second
}
```

But it will not help because:

#### ⚠️You will block Blynk.run with a delay\(\)  <a id="you-will-block-blynkrun-with-a-delay"></a>

`Blynk.run()`  is a main Blynk routine responsible for keeping connection alive, sending data, receiving data, etc. When you use a `delay()` , you most likely are breaking a connection to Blynk Cloud or blocking some functions of Blynk library.

Basically, your `sensorValue` will never get to the Cloud.

### Solution. What should I do then?  <a id="solution-what-should-i-do-then"></a>

#### 1. Keep the void loop\(\) clean <a id="1-keep-the-void-loop-clean"></a>

When using Blynk, try to keep `void loop()`  as clean as possible and move all the other routines \(e.g. sensor reading\) into **timers** and separate functions.

So, an ideal Blynk `void loop()` should look like that: 

```text
void loop() 
{
  Blynk.run();
}
```

  
But you still need to send the data, right?  
 

#### 2. Use BlynkTimer to send data in intervals <a id="2-use-blynktimer-to-send-data-in-intervals"></a>

In most of the cases, you would need to send data periodically in certain intervals.  
A very simple way of doing that is to use **BlynkTimer**, included in Blynk Library.  
 

👉First you would need to create a new Timer object:

```text
BlynkTimer timer; // Announcing the timer
```

👉In `void setup()` you need to declare that your function `sensorDataSend()`  should run every 1000 milliseconds, \(which is 1 second\). 

```text
void setup()
{
  timer.setInterval(1000L, sensorDataSend); //timer will run every sec 
}
```

👉Next, you create a function describing what should actually happen every second:  
We will read a sensor connected to A5, and then send it to Blynk app to Virtual Pin V1:

```text
void sensorDataSend()
{
  sensorValue = analogRead(A5);         // reading sensor from analog pin
  Blynk.virtualWrite(V1, sensorValue);  // sending sensor value to Blynk app
}
```

  
   
👉And then you run timer in your new and beautiful `void loop()` 

```text
void loop()
{
  Blynk.run();        // run Blynk magic
  timer.run();        // run timer every second
}
```

   
With such a minimal `void loop()` you will never block a connection to Blynk Cloud and will never spam it.

You can create multiple timers, stop/start them, add and delete. Read more about advanced usage of BlynkTimer [here](https://playground.arduino.cc/Code/SimpleTimer).  


### Check BlynkTimer example sketch for your hardware: <a id="check-blynktimer-example-sketch-for-your-hardware"></a>

[Sketch to send Data to Blynk app](https://examples.blynk.cc/?board=NodeMCU&shield=ESP8266%20WiFi&example=GettingStarted%2FPushData)

**---**

**If you have questions or something is not working, visit our 👥** [**community**](https://community.blynk.cc/) **page.**

Also, full 📗 documentation is [here](http://docs.blynk.cc/).
