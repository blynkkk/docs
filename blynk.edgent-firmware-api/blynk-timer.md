# Timer

It's important to send data in intervals and keep the void loop\(\) as clean as possible.

`BlynkTimer` allows you to send data periodically with given intervals not interfering with Blynk library routines `Blynk Timer` inherits [SimpleTimer Library](http://playground.arduino.cc/Code/SimpleTimer), a well-known and widely used library to time multiple events on hardware. `BlynkTimer` is included in Blynk library by default and there is no need to install SimpleTimer separately or include `SimpleTimer.h`

* A single `BlynkTimer` object allows to schedule up to 16 timers
* Improved compatibility with boards like `Arduino 101`, `Intel Galileo`, etc.
* When a timer struggles to run multiple times \(due to a blocked `loop`\), it just skips all the missed intervals and calls your function only once. This differs from `SimpleTimer`, which could call your function multiple times in this scenario.

For more information on timer usage, please see: [http://playground.arduino.cc/Code/SimpleTimer](http://playground.arduino.cc/Code/SimpleTimer)  
And here is a BlynkTimer [example sketch](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/PushData/PushData.ino#L30).

Please also remember that a single `BlynkTimer` can schedule many timers, so most probably you need only one instance of BlynkTimer in your sketch.

