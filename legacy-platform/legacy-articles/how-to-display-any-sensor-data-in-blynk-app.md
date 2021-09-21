---
description: With Blynk you can visualize data from any sensor
---

# How to display ANY sensor data in Blynk app

### First of all, you should know that Blynk can work with ANY sensor.  <a id="first-of-all-you-should-know-that-blynk-can-work-with-any-sensor"></a>

All you need to do is:

1. Read the sensor;
2. Send the data to Blynk App;

### ⚠️ Make sure you can read your sensor without Blynk. <a id="-make-sure-you-can-read-your-sensor-without-blynk"></a>

There are thousands of different sensors in the world. Some of them can be read simply from Analog Pins, others would need special libraries.

Before you try to visualize the sensor data in Blynk app, you should be able to at least print the sensor reading to Serial Monitor.

☝️ **Make it work without Blynk:**

1. Search Google for tutorials on how to read your sensor;
2. Find a library that works with your sensor;
3. Install the library for your sensor to Arduino IDE;
4. Print the sensor data to Serial;

After you have a code that can successfully read the sensor, you can start sending it to Blynk App. 

**If you can't get readings from the sensor without Blynk, you won't be able to send it to Blynk app** 😕.  


### Let's get started. <a id="lets-get-started"></a>

There are two major ways of displaying sensor data in the app:

* **PULL**. In this case, Blynk app will request the data only when the app is open;
* **PUSH**. In this case your hardware will be constantly sending data to the Blynk Cloud. And when you open the app, it will be there waiting;

Depending on the project you are working on, decide what is better for you.  


### PULL sensor data when Blynk app is running over Virtual Pins. <a id="pull-sensor-data-when-blynk-app-is-running-over-virtual-pins"></a>

Read this article on [Virtual Pins](http://help.blynk.cc/getting-started/blynk-basics/what-is-virtual-pins) if you don't know what it is.  
  
This might be the simplest way of displaying the data in the app. 

Blynk app can "ask" your hardware for the data when the app is open. When Blynk app is closed or is running in background, data is not requested.

This is useful, when you don't need to store the data, if you just want to open the app, check it, and forget.

This way of sending data has it's own **Pros** and **Cons**. Consider them when building applications.

**👍 Pros:**  
Less or no coding. No need to deal with timer.

👎 **Cons:**  
Data is not stored on the server. For example, you won't see it in History Graph.  


**In Blynk app:**

1. Create a New Project \(new Auth Token will be sent to your email\);
2. Add Value Display Widget;
3. Go to Widget Settings ;
4. Set PIN to Virtual Pin **V5**;
5. Set Frequency to **3 seconds**; 

It means that Blynk app will request the data from Virtual Pin V5 every 3 seconds \(when app is open, of course\).

**🙌 If you want to simply read Analog Pin, you don't have to write the code.** 

**Preparing the code:**

1. Open this [example sketch](https://examples.blynk.cc/?board=ESP8266&shield=ESP8266%20WiFi&example=GettingStarted%2FPushDataOnRequest). Just change it to your hardware and connection;
2. Check your email inbox for Auth Token;
3. Insert your Auth Token in the sketch;
4. ⚡️ Flash the code to your hardware;
5. In the Blynk app - press Play button;
6. You should see the data coming;

Let's look at the code so you better understand it. Here is the block of code you might be interested in:

```text
BLYNK_READ(V5) //Blynk app has something on V5
{
  sensorData = analogRead(A0); //reading the sensor on A0
  Blynk.virtualWrite(V5, sensorData); //sending to Blynk
}
```

This code is telling your hardware that every time Blynk app sends a \_READ request on Virtual Pin V5...

```text
BLYNK_READ(V5)
```

... your hardware will read the sensor...

```text
sensorData = analogRead(A0);
```

and then write the sensor reading back to Blynk app to Virtual Pin V5

```text
Blynk.virtualWrite(V5, sensorData);
```

### PUSH. Send sensor data from hardware in intervals over Virtual Pins <a id="push-send-sensor-data-from-hardware-in-intervals-over-virtual-pins"></a>

![](https://uploads.intercomcdn.com/i/o/19867082/18c2a246b7d2afc4cca3ef2f/Sensor+2.png)

####  Avoiding the void  <a id="avoiding-the-void"></a>

**☝️ 🔥 ⚠️ VERY IMPORTANT: You can't send sensor data in your** `void loop()` 

– Why?  
– Because Blynk sends data over the Internet, and when you put something into void loop\(\), your microcontroller will execute it 🙀 gazillion number of times. Which means that Blynk Cloud will be **flooded** with gazillion messages from your hardware.

And when Blynk Cloud notices that, it automatically ✂︎ cuts your connection. Sorry...

– OK, what should I do then?  
– Send sensor data in intervals!  


#### Using timers to send sensor data in intervals <a id="using-timers-to-send-sensor-data-in-intervals"></a>

There are lots of ways to send data in intervals, but here is a simple one. We recommend using a **BlynkTimer** for that. It's included in Blynk Library Package, so if you installed Library correctly, you are all set.

  
**Open Blynk app:**

1. Create a New Project \(new Auth Token will be sent to your email\)
2. Add Value Display Widget
3. Go to Widget Settings 
4. Set PIN to **V5**
5. Set Frequency to **PUSH** 

It means that Blynk app will be waiting for the data whenever your hardware sends it.

**Preparing the code:**

1. Open this [example sketch](https://examples.blynk.cc/?board=ESP8266&shield=ESP8266%20WiFi&example=GettingStarted%2FPushData). Just change it to your hardware and connection;
2. Check your email inbox for Auth Token;
3. Insert your Auth Token in the sketch;
4. ⚡️ Flash the code to your hardware;
5. In the Blynk app - press **Play** button;
6. You should see the data coming;

Let's look at the code so you better understand it for your next projects.

We create a BlynkTimer object, called.... timer:

```text
BlynkTimer timer; // Announcing the timer
```

Then we are creating a function that should be performed in intervals. We will read the sensor connected to A0, and then send it to Virtual Pin V5:

```text
void myTimerEvent()
{
  sensorData = analogRead(A0);
  Blynk.virtualWrite(V5, sensorData);
}
```

In setup, we declare that our function myTimerEvent\(\) should run every 1000 milliseconds, which is 1 second. 

```text
void setup()
{
  ...
  ...
  ...
  timer.setInterval(1000L, myTimerEvent);
}
```

And now look at our beautiful void loop\(\)

```text
void loop()
{
  Blynk.run();
  timer.run(); // running timer every second
}
```

  
Hope this article helped you to understand one of the fundamentals of IOT.

**---**

**If you have questions or something is not working,  
visit our 👥** [**community**](https://community.blynk.cc/) **page.**

Also, full 📗 documentation is [here](http://docs.blynk.cc/).

