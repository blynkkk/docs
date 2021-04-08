# Virtual Pin

Virtual Pin is a concept invented to provide exchange of any data between hardware, web and mobile app. Virtual pins allow you to interface with any sensor, any library, any actuator.

Think about Virtual Pins as a box where you can put any value, and everyone who has access to this box can see this value.  
You can set **UNITS** that will be viewed in the Widget by selecting them from the dropdown menu.

It's a very powerful feature to display and send any data from your hardware to the application.

Please make sure you differentiate Virtual Pins from physical GPIO pins on your hardware.

Use example: you can read a value in Celsius from a temperature sensor like DHT11 \(using a physical pin on your hardware\), then convert this temperature to Fahrenheit and save the processed value to a Virtual Pin 01.

void temperatureSend\(\) // a function that is called by some timer { temperatureCelsius = analogRead\(A0\); // Reading sensor data in Celsius toFarenheit = temperatureCelsius\*1.8 + 32; // Converting Celsius to Farenheit

Blynk.virtualWrite\(V0, toFarenheit\); // Writing temperature in Farenheit to Virtual Pin V0 // Now it can be used by widgets in the apps } Or you can send a command from the app to a Virtual Pin, and run a function inside a Virtual Pin handler.

BLYNK\_WRITE\(V1\) // Device is waiting for incoming value on Virtual Pin V1. { pinValue = param.asInt\(\); // creating a variable that will store incoming value

if \(pinValue == 1\) // checking if incoming value is 1 { doThis\(\); // trigger some function in your code doThat\(\); // trigger another function in your code } }

![](../../../.gitbook/assets/vpin_ds.png)

