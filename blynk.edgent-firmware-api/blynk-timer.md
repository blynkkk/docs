---
description: How to use timers in code
---

# Timers

{% hint style="warning" %}
If you are looking for a Timer Widget (from Blynk Legacy), it's not here. Timer Widget was replaced with "Wait" action in [Automations](https://docs.blynk.io/en/concepts/automations#actions)
{% endhint %}

As you may already know, hardware can send various data types to the Widgets over the Virtual Pin like this:

```cpp
sensorData = analogRead(A0); // this is an example of reading sensor data
Blynk.virtualWrite(V5, sensorData);
```

<mark style="color:red;">**Don't put**</mark><mark style="color:red;">** **</mark><mark style="color:red;">**`Blynk.virtualWrite(V5, sensorData);`**</mark><mark style="color:red;">** **</mark><mark style="color:red;">**in the**</mark><mark style="color:red;">** **</mark><mark style="color:red;">**`void loop ()`**</mark><mark style="color:red;">!</mark>

If you put it code into a `void loop()` it will execute "gazillion" times. This will spam the Blynk.Cloud with thousands of messages from your hardware. When it happens, **Blynk.Cloud will cut off** the connection between your hardware and server.

### Use Timers

Blynk Library offers a built-in Blynk.Timer feature to send data in intervals. It allows you to send data periodically with given intervals and not interfere with other Blynk library routines.

`Blynk Timer` is based upon [SimpleTimer Library](http://playground.arduino.cc/Code/SimpleTimer), a well-known and widely used library to time multiple events on hardware.&#x20;

* `BlynkTimer` is included in Blynk library by default and there is no need to install SimpleTimer separately or include `SimpleTimer.h` separately.
* A single `BlynkTimer` object allows to schedule up to 16 timers
* Improved compatibility with boards like `Arduino 101`, `Intel Galileo`, etc.
* When a timer struggles to run multiple times (due to a blocked `loop`), it just skips all the missed intervals and calls your function only once. This differs from `SimpleTimer`, which could call your function multiple times in this scenario.

For more information on timer usage, please see: [http://playground.arduino.cc/Code/SimpleTimer](http://playground.arduino.cc/Code/SimpleTimer)



This is an example code on how to send data every second with a timer. Check full example sketch [here](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/PushData/PushData.ino#L30).

```cpp
// Declaring a global variabl for sensor data
int sensorVal; 

// This function creates the timer object. It's part of Blynk library 
BlynkTimer timer; 

void myTimer() 
{
  // This function describes what will happen with each timer tick
  // e.g. writing sensor value to datastream V5
  Blynk.virtualWrite(V5, sensorVal);  
}

void setup()
{
  //Connecting to Blynk Cloud
  Blynk.begin(auth, ssid, pass); 
  
  // Setting interval to send data to Blynk Cloud to 1000ms. 
  // It means that data will be sent every second
  timer.setInterval(1000L, myTimer); 
}

void loop()
{
  // Reading sensor from hardware analog pin A0
  sensorVal = analogRead(A0); 
  
  // Runs all Blynk stuff
  Blynk.run(); 
  
  // runs BlynkTimer
  timer.run(); 
}
```



{% hint style="info" %}
A single `BlynkTimer` instance **can schedule many timers**, so most likely you will only need one BlynkTimer in your sketch.
{% endhint %}



