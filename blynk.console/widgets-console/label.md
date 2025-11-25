# Label

{% hint style="warning" %}
_**Note:**_ please remember that web and mobile app widgets are set up separately in the Web Dashboard and Mobile App Dashboard sections correspondingly. They can still use the same datastreams to access the same data (Map widget is an exception – a different codebase is used for Map on mobile and web).
{% endhint %}

Label is used to show value of Virtual Pin e.g. length/distance, mass, duration, volume, temperature and other data types including strings. Also it can show level/progress bar (horizontal or vertical) and/or have widget colors changes based on getting different predefined values.

![](../../.gitbook/assets/label.PNG)

### **Settings**

* **Label** – name a Label widget so you or your client understand what it's about    <br>
* **Datastream** - select or create the data stream that will be the source of the data for the widget<br>
* **Content Alignment** – 2 options are available: Left, Right<br>
* **Background** <br>
  * With disabled option **Change color based on value** pick your own Background colour from palette
  *   With enabled **Change color based on value** select the gradient scheme or set up your own one based on the **MIN** and **MAX** values of your choice and Background color


* **Level** – enable it by switching **Show level** on to visualize accordingly to values set in **MIN and MAX Value** fields below. Select position (vertical or horizontal) and level color.

![Label widget setup demo](../../.gitbook/assets/label_setup.gif)

