# Debug

## #define BLYNK\_PRINT

## #define BLYNK\_DEBUG

To enable debug prints on the default Serial port add on the top of your sketch **IMPORTANT: This should be the first line in your code**:

```cpp
#define BLYNK_PRINT Serial // Defines the object that is used for printing
#define BLYNK_DEBUG        // Optional, this enables more detailed prints
```

Then enable Serial Output in setup():

```cpp
Serial.begin(9600);
```

Open Serial Monitor and you'll see the debug prints.

You can also use spare Hardware serial ports or SoftwareSerial for debug output (you will need an adapter to connect to it with your PC).

**WARNING:** Enabling `BLYNK_DEBUG` will slowdown your hardware processing speed up to 10 times!

## BLYNK\_LOG()

When `BLYNK_PRINT` is defined, you can use `BLYNK_LOG` to print your logs. The usage is similar to `printf`:

```cpp
BLYNK_LOG("This is my value: %d", 10);
```

On some platforms (like Arduino 101) the `BLYNK_LOG` may be unavailable, or may just use too much resources.\
In this case you can use a set of simpler log functions:

```cpp
BLYNK_LOG1("Hello World"); // Print a string
BLYNK_LOG1(10);      // Print a number
BLYNK_LOG2("This is my value: ", 10); // Print 2 values
BLYNK_LOG4("Temperature: ", 24, " Humidity: ", 55); // Print 4 values
...
```
