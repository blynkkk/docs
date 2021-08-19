# Common Widget Settings

_**Note:**_ please remember that web and apps widgets are set up separately and may have same datastreams set to view the same data \(excepts Map widgets – those two use different codebase now\).

  
**Title** \(name + alignment\)

**Datastream Selector**  
This is one of the main parameters you need to set. It defines which pin to control or to read from.

**Mode** \(Push/Switch\)

**Send On Release**  
This option allows you to optimize data traffic on your hardware.  
For example, when you move joystick widget, commands are streamed to the hardware, during a single joystick move you can send dozens of commands. There are use-cases where it’s needed, however creating such a load may lead to hardware overload and reset. **Send On Release** is a recommended setting for majority of applications. This is also a default setting.

**Write Interval**  
Similar to “Send on Release” option. However, it allows you to stream values to your hardware within certain interval. For example, setting **write interval** to 100 ms means that while you move the slider, only 1 value will be sent to hardware within 100 ms period. This option is also used to optimize data traffic flow to your hardware.

**Show Value**

**Progress Gradient**  
When you choose gradient, it affects the color of widget elements based on incoming values. For example: You set Gauge Widget with Min and Max parameters of 0-100, and choose green-yellow-red gradient. When hardware sends: - `10`, Gauge will change it’s color to green color - `50` will change Gauge to yellow color - `80` will change Gauge to red color  
There are 2 types of gradients you can choose from: - Warm: Green - Orange - Red; - Cold: Green - Blue - Violet;

**ON/OFF States**

**ON/OFF Labels**

**Edges**  
Rounded/Sharp/Pill/Custom

**Design**  
Font size, Text color, Progress, Button, Handle

