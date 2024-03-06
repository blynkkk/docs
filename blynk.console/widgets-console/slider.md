# Slider

{% hint style="warning" %}
_**Note:**_ please remember that web and mobile app widgets are set up separately in the Web Dashboard and Mobile App Dashboard sections correspondingly. They can still use the same datastreams to access the same data (Map widget is an exception – a different codebase is used for Map on mobile and web).
{% endhint %}

A Slider assigns a value to a datastream within a pre-defined range. Usage examples: volume, brightness, RPM, flap position control, etc.

Move slider handle to set the value or use fine control buttons + and – to set the value more precisely.

<figure><img src="https://files.gitbook.com/v0/b/gitbook-legacy-files/o/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MVLXy69EogCOTmSZVul%2F-MVLoTyWUvXLyyyIQZJN%2FSlider.gif?alt=media&#x26;token=cd84f5e7-bf8f-4929-88f6-911fdeb93e06" alt=""><figcaption><p>Slider widget example</p></figcaption></figure>

The step defines the minimum increment of values generated in response to movement of the slider by the user. Note that if an IoT device or a Blynk.App widget changes the datastream value, then that change will be reflected in the slider position and value displayed.&#x20;

The range of values the slider will generate is defined by the datastream [min value](https://docs.blynk.io/en/blynk.console/templates/datastreams/datastreams-common-settings/min-value) and [max value](https://docs.blynk.io/en/blynk.console/templates/datastreams/datastreams-common-settings/max-value) settings. The units displayed will also come from the datastream settings. The slider will be set to the datastream default value every time the IoT device reconnects to the Blynk.Cloud, unless the datastream option ‘Sync with latest server value every time device connects to the cloud’ is enabled. The datastream ‘Invalidate Value’ option will affect the slider’s value when enabled.

### Settings

**Title** - This is the label shown at the top of the widget. The default is the name assigned to the datastream.

**Datastream** - data type integer or double may be assigned.

**Color** - The widget color takes on the assigned datastream color by default.

**Send values on release only** (optimal) - when enabled, the datastream is assigned a value only when the user releases the control (recommended setting). When disabled, all the values set as the user moves the slider will be assigned to the datastream.

**HANDLE STEP** - defines the minimum increment / decrement of the values as the slider position is changed by the user. The step value is a whole integer when the datastream data type is integer, and a decimal value when the datastream data type is double.

**Show fine controls** - adds a ‘-’ and ‘+’ to either side of the slider when enabled. The increment or step for this option is set by the ‘FINE CONTROL STEP’ option.

**FINE CONTROL STEP** - defines the minimum increment / decrement of the values as the ‘-’ and ‘+’ to either of the slider is clicked by the user. This option is only visible when ‘Show fine controls’ is enabled.

**VALUE POSITION** - sets the position of the slider value displayed to either the left or right of the slider handle.

![Slider widget setup demo](../../.gitbook/assets/Slider\_setup.gif)
