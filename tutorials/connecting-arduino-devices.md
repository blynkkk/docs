---
description: needs updates
---

# Getting Started: Connecting Arduino Devices

## Getting Started With Hardware

### Dynamic provisioning

This new Blynk feature allows configuring the wifi settings via the app without need of flashing the auth token manually.  
  
Here’s the quickstart guide on this process:

1. Download the latest Blynk.Edgent library as zip file.
2. Open Arduino IDE
3. Navigate to Sketch - &gt; Include Library 
4. Select Add .ZIP library

![](https://lh3.googleusercontent.com/i3hKUqAHHOLARrcHd0QaKKhVXjs2BAzFFgonSnaA2JyLWwO5aj7yM8Z0K7QwTpW_sU17pJTyBAx0hLjHPOGceIjdCJhUjYdjukK0sjQTE0EX_xBV3UPpjzWHVvPqhkB2neYdVhkm)

5. Select the downloaded zip file.  
6. After that, it should be visible under the File - Examples  
![](https://lh3.googleusercontent.com/WfHrWEDwJZ-mzHNcy1UVE1nwHDCAODrMkVehACEgsZYc4pS54L4o99Qel706TSEYPqUqNayc8Ur8pM6DCECYFH1hivgwC2O-KHSZgANz4yTkVV99JR-N4-8B2NDCoZXm3GlXm7eD)  
7. Select Blynk.Edgent -&gt; Edgent\_ESP32

Initially it should look like this.   
Note the section marked with the red rectangle, these variables are empty now but they should be replaced with the ones from your template.

![](https://lh6.googleusercontent.com/0Zx4V87T_YZ8upPUktQLuN8gIV3Tnkaf9N_NYOwtkmG1dMxWsSC_iyXuu4w-MvGsgVU_Tm8b1yzS67BXqw2xc3kw6RC6pyfCdw5XYvC7yBU0JML5v-H6rVvE3XG5EqSik1i1_MML)

8. Log in to Blynk.360  
9. Create New template or open existing one.  
10. Copy the configuration strings  
![](https://lh6.googleusercontent.com/x2ZHNOv1TA7jPkQtujqBWmn3_mtQr5yxkgZ-0JZF7T7pIndKZHTu0glkkblS3sEd4XV1KAo0ZaljY3dm73AA8aKghwdALd7rKiELWm3v0xjoCJ1Li6wjzsoOP_oCjMBysQ31QBNp)  
11. Replace them in your sketch so it would look like this  
![](https://lh6.googleusercontent.com/SdEuVasrt4iCFQqVHaHv9cjR-TkjY9_8HWHHQRc2qDOBax7CD5DfKLTwPb6SQ4gXP5DdAOagRdmAvT1JtEkmwebHStD31Xol-Tj4wSofO8Qk7F4MdhazaASaPR-voPgbcthzcN2d)

_**Everything is ready to test the dynamic provisioning now!**_

Connect your device, and press Upload

If the upload process wend successfully you should see something like this in the serial monitor  
  
![](https://lh6.googleusercontent.com/ke-UDlKRqfsgiak0aMEEHVbEU-cAmShbXLAMOS1LEd4_Kd1tktKFw2SajHnWul_b9jT3si85XchMheZlMWy931lPBKUvgw_daFkiYuUVBfVQM9VKePbryxwbD9hvnH4t5lZ2AzFo)  
  
Now open Blynk app 

click Add new device

Select the SSID of the ESP32, in this case it is Blynk Root Template-FAD8F  


App will start the dynamic provision process

After that you should see your device connected

![](https://lh4.googleusercontent.com/Dofpg_nuepVAkVObVJcXsWC0Z9QShoVWHPGgYv8a_WZ9RMD-2G_zAwKHDk6ddp1lrf2KIHNrGCsgJ6Vu0x4UiKZCHgwsv1GUAu9_v819oItUP3vPo_iIVwNveTh3UI_fD6mCOi2B)

That’s it! Now the device is configured to use the WiFi network.  
You can check that the device successfully received the auth token from the app in the serial monitor output  
  
![](https://lh4.googleusercontent.com/P1WcVsuVbygCW8kSggfYwOKf55a1vVDk4KcCYevGbFPhFXGRI7r5s7_B7z2qKCzfLZudWU0nj6NKPkLMBO1Zodc7X8a54z3M51VLHo65pEfFlP93mCKxgJjaa5maOAKWg6HPZ7zv)  




### Static Provision

Install the [1.0.0 beta3 library](https://github.com/blynkkk/blynk-library/releases/tag/v1.0.0-beta.1) and use the ESP32 WiFi example.

In Blynk.360, add a template that's based on an ESP32 board, then create a device based on that template.  
The Template screen will give you two lines of firmware configuration, copy these and add them at the very beginning of your sketch.  
In the [Device &gt; Device Info ](../web-dashboard/for-developers/search/devices-1/device-view/device-info.md)screen you'll find the Auth Token \(left hand column, half way down\) click on the green square to the right to copy this to the clipboard...  
[![image](https://user-images.githubusercontent.com/35718564/112981316-e62d3400-9152-11eb-86b2-8a85806dd860.png)](https://user-images.githubusercontent.com/35718564/112981316-e62d3400-9152-11eb-86b2-8a85806dd860.png)

and paste it into your sketch.

### How To Use an Example Sketch

You should by now have Blynk.Library installed on your computer. If not - [click here](https://docs.blynk.cc/#downloads-blynk-library).  
Example sketches will help you get your hardware online quickly and major Blynk features.  
Open the example sketch according to the hardware model or shield you are using.

![](https://docs.blynk.cc/images/connection_type_sketch.png)

Let’s take a look at the example sketch for an [Arduino UNO + Ethernet shield](https://github.com/blynkkk/blynk-library/blob/master/examples/GettingStarted/BlynkBlink/BlynkBlink.ino)

```text
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

char auth[] = "YourAuthToken";

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth);  // Here your Arduino connects to the Blynk Cloud.
}

void loop()
{
  Blynk.run(); // All the Blynk Magic happens here...
}
```

#### Auth Token <a id="getting-started-getting-started-with-hardware-auth-token"></a>

In this example sketch, find this line:

```text
char auth[] = "YourAuthToken";
```

This is the [Auth Token](https://docs.blynk.cc/#getting-started-getting-started-with-application-4-auth-token) that you emailed yourself. Please check your email and copy it, then paste it inside the quotation marks.

It should look similar to this:

```text
char auth[] = "f45626c103a94983b469637978b0c78a";
```

Upload the sketch to the board and open Serial Terminal. Wait until you see something like this:

```text
Blynk v.X.X.X
Your IP is 192.168.0.11
Connecting...
Blynk connected!
```

**Congrats! You are all set! Now your hardware is connected to the Blynk Cloud!**

