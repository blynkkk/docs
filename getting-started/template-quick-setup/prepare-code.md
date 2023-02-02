# Prepare Your Code

A code example for ESP32/ ESP8266 / Arduino boards

{% tabs %}
{% tab title="ESP32 or ESP8266" %}
### 4 simple steps to configure your code:

1. Open [Arduino IDE ](https://www.arduino.cc/en/software)and install [Blynk library](https://github.com/blynkkk/blynk-library/releases/latest)
2. Define Template ID and Device Name on top of your firmware, before any includes
3. Define your [physical button and LED](https://docs.blynk.io/en/getting-started/template-quick-setup/prepare-code#defining-your-physical-button-and-led) if needed
4. Upload this sketch into your test board

**Final step:** [Provision your board via Dynamic Provisioning](https://docs.blynk.io/en/getting-started/activating-devices/blynk-edgent-wifi-provisioning) flow and add it to your account using Blynk app

### **Defining your physical button and LED**

To enhance the user experience it's recommended that you plan these things into your electrical design:

1. A physical button which will allow resetting the device to its default settings. E.g.: Holding this button for N seconds will erase the AuthToken and WiFi credentials.
2. An LED to indicate different statuses of device (AP, connected, etc.). It can be RGB or one-color LED.

Depending on your board there can be different variants of the setup, we'll provide some examples for you to get an idea of how it can work.

Here we use the Edgent\_ESP8266 sketch as an example, but the same principles apply to the ESP32 sketch as well. The Edgent\_ESP8266.ino file (the first tab in the Arduino IDE) contains the following lines of code:

```
// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI
```

Notice that all of these board types are commented-out by default so you’ll have to un-comment the board you are using.

If the board you are using isn’t listed here then leaving all of the board types commented out will cause the sketch to use the “Custom board configuration” from the Settings.h tab, and you need to edit this custom configuration to suit your hardware.

This is what the relevant parts of the standard Settings.h file look like:

```
/*
 * Board configuration (see examples below).
 */

#if defined(USE_NODE_MCU_BOARD) || defined(USE_WEMOS_D1_MINI)

  #define BOARD_BUTTON_PIN            0
  #define BOARD_BUTTON_ACTIVE_LOW     true

  #define BOARD_LED_PIN               2
  #define BOARD_LED_INVERSE           true
  #define BOARD_LED_BRIGHTNESS        255

#elif defined(USE_SPARKFUN_BLYNK_BOARD)

  #define BOARD_BUTTON_PIN            0
  #define BOARD_BUTTON_ACTIVE_LOW     true

  #define BOARD_LED_PIN_WS2812        4
  #define BOARD_LED_BRIGHTNESS        64

#elif defined(USE_WITTY_CLOUD_BOARD)

  #define BOARD_BUTTON_PIN            4
  #define BOARD_BUTTON_ACTIVE_LOW     true

  #define BOARD_LED_PIN_R             15
  #define BOARD_LED_PIN_G             12
  #define BOARD_LED_PIN_B             13
  #define BOARD_LED_INVERSE           false
  #define BOARD_LED_BRIGHTNESS        64

#else

  #warning "Custom board configuration is used"

  #define BOARD_BUTTON_PIN            0                     // Pin where user button is attached
  #define BOARD_BUTTON_ACTIVE_LOW     true                  // true if button is "active-low"

  #define BOARD_LED_PIN               4                     // Set LED pin - if you have a single-color LED attached
  //#define BOARD_LED_PIN_R           15                    // Set R,G,B pins - if your LED is PWM RGB
  //#define BOARD_LED_PIN_G           12
  //#define BOARD_LED_PIN_B           13
  //#define BOARD_LED_PIN_WS2812      4                     // Set if your LED is WS2812 RGB
  #define BOARD_LED_INVERSE           false                 // true if LED is common anode, false if common cathode
  #define BOARD_LED_BRIGHTNESS        64                    // 0..255 brightness control

#endif
```

The first section starts with #if defined(USE\_NODE\_MCU\_BOARD) || defined(USE\_WEMOS\_D1\_MINI).

In plain English, this means, “If you’ve uncommented either the #define USE\_NODE\_MCU\_BOARD or #define USE\_WEMOS\_D1\_MINI lines of code in the first tab of the sketch, then the following settings will be used for the physical button and LED”.

The NodeMCU board has 2 physical buttons:

![Image credits to RandomNerdTutorials](../../.gitbook/assets/NodeMCU.webp)

The button on the bottom left is labeled RST and the one on the bottom right is labeled FLASH.

The FLASH button is connected to GPIO0 (the pin labeled D3 on the board). When the button is pressed, GPIO0 is connected to GND (LOW).

Most NodeMCUs also have a built-in LED (located up near the top right of the board) which is connected to GPIO2 (the pin labeled D4). This LED lights up when GPIO2 is pulled LOW, so has what is known as inverse logic.

Below the comments are added explaining the standard settings for the NodeMCU/Wemos D1 Mini board:

```
#if defined(USE_NODE_MCU_BOARD) || defined(USE_WEMOS_D1_MINI)
#define BOARD_BUTTON_PIN 0 <<<< The FLASH Button 
#define BOARD_BUTTON_ACTIVE_LOW true <<<< Pressing the button pulls the pin LOW
#define BOARD_LED_PIN 2 <<<< The LED is connected to GPIO2 (D4) 
#define BOARD_LED_INVERSE true <<<< The LED lights when the pin is LOW 
#define BOARD_LED_BRIGHTNESS 255 <<<< Make the LED shine at max brightness when lit
```

If you’re using the Wemos D1 mini, it is very similar but you’ll notice that it only has one button labeled RESET (same as the RST button on the NodeMCU).

![Image credits to RandomNerdTutorials](../../.gitbook/assets/Wemos\_D1\_mini.webp)

It doesn’t have the FLASH button, so you’ll need to add a physical momentary push to make a button in order to be able to clear the stored credentials if ever you need to re-provision the board.

One side of the physical push button will connect to the pin labeled D3 and the other side to GND (because we have this line set to true: #define BOARD\_BUTTON\_ACTIVE\_LOW true which means that when the button is pressed the GPIO0 (D3) pin is pulled LOW).

Of course, if you wanted to, you could simply use a jumper wire, bent paperclip, or anything else that’s conductive to short-out pin D3 and GND for 10 seconds.

**So, if you don’t un-comment one of the pre-defined board types, the custom board type configuration will be used. That looks like this:**

```
#warning "Custom board configuration is used"

  #define BOARD_BUTTON_PIN            0                     // Pin where user button is attached
  #define BOARD_BUTTON_ACTIVE_LOW     true                  // true if button is "active-low"

  #define BOARD_LED_PIN               4                     // Set LED pin - if you have a single-color LED attached
  //#define BOARD_LED_PIN_R           15                    // Set R,G,B pins - if your LED is PWM RGB
  //#define BOARD_LED_PIN_G           12
  //#define BOARD_LED_PIN_B           13
  //#define BOARD_LED_PIN_WS2812      4                     // Set if your LED is WS2812 RGB
  #define BOARD_LED_INVERSE           false                 // true if LED is common anode, false if common cathode
  #define BOARD_LED_BRIGHTNESS        64                    // 0..255 brightness control
```

As you can see, this uses GPIO0 (Pin D3) for the physical pushbutton switch, but GPIO4 (pin D2) for the LED. It also has the option to un-comment additional lines of code that allow an RGB or WS2812 RGB LED to be used.

If you didn’t un-comment any board types and allowed the custom board configuration to be used, then with a NodeMCU the built-in LED wouldn’t flash to indicate provisioning or pulse to indicate normal running. But, pin GPIO4 would still be receiving these pulses from the sketch, and if you had a sensor or relay attached to GPIO4 then this could provide unexpected results.

Make sure you check these before starting device provisioning:

* Un-comment the correct board type
* Check the Settings.h file to ensure that the selected board type does actually match your hardware setup
* Add a physical button to the Wemos D1 mini if needed
* Use the custom board configuration if you have an unusual type of board, but edit the custom section of Settinsg.h to make it match your hardware
* Ensure that you don’t use the GPIOs assigned to the button or LED pins for anything else in your sketch.
{% endtab %}

{% tab title="Arduino (static provisioning)" %}
{% hint style="info" %}
Instructions and code for Static AuthToken is used when you are working with hardware that doesn't support Blynk.Edgent WiFi provisioning. For example when you are using Ethernet shield, or work with hardware that connects to the Internet over cellular (3G, LTE, etc) network.
{% endhint %}

1. Download [the latest release of Blynk.Edgent](https://github.com/blynkkk/blynk-library/releases/latest) as a **Source code .zip** file
2. Open [Arduino IDE](https://www.arduino.cc/en/software)
3. In Arduino IDE menu go to Sketch - > **Include Library**
4. Select Add **.ZIP library**

![](<../../.gitbook/assets/pasted image 0.png>)

1. Select the downloaded .zip archive. Press **Choose** to continue.
2. After that, you should see Blynk folder under the **File > Examples**

![](<../../.gitbook/assets/pasted image 1.png>)

Select the example for the hardware you use. We will use the one for Arduino UNO + Ethernet shield

```
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID      "TMPL••••••••"
#define BLYNK_TEMPLATE_NAME    "My First Device"
#define BLYNK_AUTH_TOKEN       "••••••••••••••••••••••••"

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN);
}

void loop()
{
  Blynk.run();
}
```

Pay attention to these 3 lines: you would need to fill them.

```cpp
#define BLYNK_TEMPLATE_ID      "TMPL••••••••"
#define BLYNK_TEMPLATE_NAME    "My First Device"
#define BLYNK_AUTH_TOKEN       "••••••••••••••••••••••••"
```

#### Getting Template ID and Auth Token for device

**Template ID and Device Name**

1. Log in to your [Blynk.Console](https://blynk.cloud/) developer account
2. If you don't have a Device Templates -> [Create New Template](./#create-a-template) or open an existing one
3. Copy the contents of this section and paste them on top of your firmware, before any includes

![](<../../.gitbook/assets/image (2) (1) (1).png>)

**Getting Auth Token**

When the Template is ready, go to Search -> Devices - **Create new device**

![](<../../.gitbook/assets/image (4) (1).png>)

Choose a Template and give your new device a name

![](<../../.gitbook/assets/image (18) (1).png>)

After the device was created, open its dashboard, go to the Device Info tab. There you will find a field: Auth Token.

![](<../../.gitbook/assets/image (17).png>)

Now you have all the information you need to update your sketch:

```cpp
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID      "TMPL••••••••"
#define BLYNK_TEMPLATE_NAME    "My First Device"
#define BLYNK_AUTH_TOKEN       "••••••••••••••••••••••••"

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN);
}

void loop()
{
  Blynk.run();
}
```

1. Upload the sketch to your device
2. Open Serial Monitor. Wait until you see something like this:

```bash
Blynk v.X.X.X
Your IP is 192.168.0.11
Connecting...
Blynk connected!
```
{% endtab %}
{% endtabs %}
