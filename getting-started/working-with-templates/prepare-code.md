# Prepare Your Code

A code example for ESP32/ ESP 8266 / Arduiono 

{% tabs %}
{% tab title="ESP32" %}
You would need a Template ID and Template Name. 

Link to how to install library, etc. 

Go to .... here... there... and copy to clipboard



This sketch should: 

1. Generate random data between 20 and 30 and store it to V0 every 1 second. Add comments about how important the timer is. 
2. Accept the incoming value from Switch Widget to V1
3. When V1 is ON, add 70 to V0 value \(so that users see that values were affected by the switch

```cpp
#define BLYNK_TEMPLATE_ID             ""
#define BLYNK_DEVICE_NAME             ""

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD

#include "BlynkEdgent.h"

int randomValue;  //This variable stores random values
int buttonStatus  //This variable stores the button click

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  timer.setInterval(1000L, myTimerEvent);  //This code sets Timer that will start every second myTimerEvent() function
}

void loop() {
  BlynkEdgent.run();
}

void myTimerEvent() //Timer will run this function every second
{
  randomValue = random(20,30);  //Generate random values and store them in the appropriate variable
  Serial.println(String("Value: ") + randomValue);   //The generated random value will be printed to Serial Monitor output
  Blynk.virtualWrite(V0, randomValue);  //Send the generated value to blynk.cloud
}

BLYNK_WRITE(V1) //This function reads the status of Button. It will start every time you click this Button.
{
  int buttonStatus = param.asInt(); //Reading the current state and saving it to the corresponding variable
  Serial.println(String("Button Status: ") + buttonStatus); //The current Button status will be printed to Serial Monitor output
  if (buttonStatus == 1){ //Button click handling
    Blynk.virtualWrite(V0, 70); //Reaction of the system to the click of Button
  }
}

```
{% endtab %}

{% tab title="ESP8266" %}
Add a code for ESP8266
{% endtab %}

{% tab title="Arduino \(or any other supported hardware\)" %}
Instructions and code for Static Token
{% endtab %}

{% tab title="Any Raspberry Pi" %}
JS code \(can be added later\)
{% endtab %}
{% endtabs %}



