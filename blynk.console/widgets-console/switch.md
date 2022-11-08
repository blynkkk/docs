# Switch

{% hint style="warning" %}
_**Note:**_ please remember that web and mobile app widgets are set up separately in the Web Dashboard and Mobile App Dashboard sections correspondingly. They can still use the same datastreams to access the same data (Map widget is an exception – a different codebase is used for Map on mobile and web).
{% endhint %}

The Switch widget sends a command and displays the binary status of the device, typically 1 for ON, and 0 for OFF.

<figure><img src="https://files.gitbook.com/v0/b/gitbook-legacy-files/o/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MVLXy69EogCOTmSZVul%2F-MVLrS5w1PFM9F5m44di%2FSwitch.gif?alt=media&#x26;token=50227417-a0a4-4f61-aa7e-182db9df72b4" alt=""><figcaption></figcaption></figure>

### Settings

**Title** - the label shown at the top of the widget when the option ‘Hide widget name’ is not enabled.

**Datastream** - [data type](../templates/datastreams/datastreams-common-settings/data-type.md) integer or double may be assigned.

**ON VALUE** - the numeric value you want the datastream value set to when the switch is turned on. Typically the value one (1). The range of values are constrained by the datastream [min value](../templates/datastreams/datastreams-common-settings/min-value.md) and [max value](../templates/datastreams/datastreams-common-settings/max-value.md) settings.

**OFF VALUE** - the numeric value you want the datastream value set to when the switch is turned off. Typically the value is zero (0). The range of values are constrained by the datastream [min value](../templates/datastreams/datastreams-common-settings/min-value.md) and [max value](../templates/datastreams/datastreams-common-settings/max-value.md) settings.

**Color** - The widget color takes on the assigned datastream color by default.

**Show on/off labels** - adds custom labels to identify the on/off state of the switch. When enabled, you may also right or left justify the label with the ‘LABEL POSITION’ option. The ‘Hide widget name’ hides the display of the ‘Title’ label when enabled.

**ON LABEL** - When the ‘Show on/off labels’ option is enabled, then the ‘ON LABEL’ text assigned will be displayed when the switch widget value equals the ‘ON VALUE’.

**OFF LABEL** - When the ‘Show on/off labels’ option is enabled, then the ‘OFF LABEL’ text assigned will be displayed when the switch widget value equals the ‘OFF VALUE’.

**LABEL POSITION** - When the ‘Show on/off labels’ option is enabled, this option aligns the ‘ON LABEL’ and ‘OFF LABEL’ either to the left or right of the switch.

**Hide widget name** - when enabled, hides the display of the ‘TITLE’ at the top of the widget.

![Switch widget setup demo](../../.gitbook/assets/switch\_setup.gif)
