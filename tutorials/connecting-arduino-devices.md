---
description: needs updates
---

# Getting Started: Connecting Arduino Devices

## Getting Started With Hardware

### Dynamic provisioning

This Blynk feature allows configuring the WiFi settings via the app, without need of flashing the auth token manually.  
  
Here’s the QuickStart guide on this process:

#### Sketch setup

1. Download [the latest Blynk library](https://github.com/blynkkk/blynk-library/releases/tag/v1.0.0-beta.3) as zip file.
2. Open [Arduino IDE](https://www.arduino.cc/en/guide/windows)
3. Navigate to Sketch - &gt; Include Library 
4. Select Add .ZIP library

![](https://lh3.googleusercontent.com/i3hKUqAHHOLARrcHd0QaKKhVXjs2BAzFFgonSnaA2JyLWwO5aj7yM8Z0K7QwTpW_sU17pJTyBAx0hLjHPOGceIjdCJhUjYdjukK0sjQTE0EX_xBV3UPpjzWHVvPqhkB2neYdVhkm)

5. Select the downloaded zip file.  
6. After that, it should be visible under the **File &gt; Examples**  
![](https://lh3.googleusercontent.com/WfHrWEDwJZ-mzHNcy1UVE1nwHDCAODrMkVehACEgsZYc4pS54L4o99Qel706TSEYPqUqNayc8Ur8pM6DCECYFH1hivgwC2O-KHSZgANz4yTkVV99JR-N4-8B2NDCoZXm3GlXm7eD)  
7. Select **Blynk.Edgent &gt; Edgent\_ESP32**

Initially it should look like this.   
_**Note:**_ the section marked with the red rectangle, these variables are empty now but they should be replaced with the ones from your template.

![](https://lh6.googleusercontent.com/0Zx4V87T_YZ8upPUktQLuN8gIV3Tnkaf9N_NYOwtkmG1dMxWsSC_iyXuu4w-MvGsgVU_Tm8b1yzS67BXqw2xc3kw6RC6pyfCdw5XYvC7yBU0JML5v-H6rVvE3XG5EqSik1i1_MML)

8. Log in to [Blynk.360](https://blynk.cloud/)  
9. [Create New Template](building-a-commercial-product-a-z.md#create-a-template) or open existing one.  
10. Copy the configuration strings  
![](https://lh6.googleusercontent.com/x2ZHNOv1TA7jPkQtujqBWmn3_mtQr5yxkgZ-0JZF7T7pIndKZHTu0glkkblS3sEd4XV1KAo0ZaljY3dm73AA8aKghwdALd7rKiELWm3v0xjoCJ1Li6wjzsoOP_oCjMBysQ31QBNp)  
11. Replace them in your sketch so it would look like this  
![](https://lh6.googleusercontent.com/SdEuVasrt4iCFQqVHaHv9cjR-TkjY9_8HWHHQRc2qDOBax7CD5DfKLTwPb6SQ4gXP5DdAOagRdmAvT1JtEkmwebHStD31Xol-Tj4wSofO8Qk7F4MdhazaASaPR-voPgbcthzcN2d)

_**Everything is ready to test the dynamic provisioning now!**_

Connect your device, and press **Upload**

If the upload process wend successfully you should see something like this in the serial monitor  
  
![](https://lh6.googleusercontent.com/ke-UDlKRqfsgiak0aMEEHVbEU-cAmShbXLAMOS1LEd4_Kd1tktKFw2SajHnWul_b9jT3si85XchMheZlMWy931lPBKUvgw_daFkiYuUVBfVQM9VKePbryxwbD9hvnH4t5lZ2AzFo)  


#### [Add Device](../mobile-applications/device-management/add-new-device.md)

1. Open Blynk App 
2. Tap Add New Device
3. Select the SSID of the ESP32, in this case it is Blynk Root Template-FAD8F
4. App will start the dynamic provision process

After that you should see your device connected:

![](https://lh4.googleusercontent.com/Dofpg_nuepVAkVObVJcXsWC0Z9QShoVWHPGgYv8a_WZ9RMD-2G_zAwKHDk6ddp1lrf2KIHNrGCsgJ6Vu0x4UiKZCHgwsv1GUAu9_v819oItUP3vPo_iIVwNveTh3UI_fD6mCOi2B)

_**That’s it! Now the device is configured to use the WiFi network.**_  
You can check that the device successfully received the auth token from the app in the serial monitor output:

![](https://lh4.googleusercontent.com/P1WcVsuVbygCW8kSggfYwOKf55a1vVDk4KcCYevGbFPhFXGRI7r5s7_B7z2qKCzfLZudWU0nj6NKPkLMBO1Zodc7X8a54z3M51VLHo65pEfFlP93mCKxgJjaa5maOAKWg6HPZ7zv)



### Static Provisioning

Static provisioning is useful, if you're adding a device that doesn't support Blynk.Edgent WiFi provisioning. For example, it could be an Arduino Uno + Ethernet Shield.

Install the [latest Blynk library](https://github.com/blynkkk/blynk-library/releases/tag/v1.0.0-beta.1) and use the ESP32 WiFi example.

**In** [**Blynk.360**](https://blynk.cloud/)**, add a new template.**  
The Template screen will give you two lines of firmware configuration. You'll have to add them at the very beginning of your sketch.

**In** [**Blynk.360**](https://blynk.cloud/)**, create a new device based on your new template.**  
In the [Device &gt; Device Info ](../web-dashboard/for-developers/search/devices-1/device-view/device-info.md)screen you'll find the **Auth Token** \(left hand column, half way down\):  
[![image](https://user-images.githubusercontent.com/35718564/112981316-e62d3400-9152-11eb-86b2-8a85806dd860.png)](https://user-images.githubusercontent.com/35718564/112981316-e62d3400-9152-11eb-86b2-8a85806dd860.png)

You'll also have to update it in your sketch file, so copy it to the clipboard.

### How To Use an Example Sketch

You should by now have Blynk.Library installed on your computer. If not - [click here](https://docs.blynk.cc/#downloads-blynk-library).  
Example sketches will help you get your hardware online quickly and major Blynk features.  
Open the example sketch according to the hardware model or shield you are using.

Let’s take a look at the example sketch for an UNO + Ethernet Shield:

```text
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth);
}

void loop()
{
  Blynk.run();
}
```

You can find it in your Arduino IDE:

1. Open **File &gt; Examples &gt; Blynk &gt; Boards\_Ethernet &gt; Arduino\_Ethernet.**
2. Update **Auth Token** and **Template ID**
3. Upload the sketch to the board
4.  Open Serial Terminal. Wait until you see something like this:

```text
Blynk v.X.X.X
Your IP is 192.168.0.11
Connecting...
Blynk connected!
```

**Congrats! You are all set! Now your hardware is connected to the Blynk Cloud!**

