# Controls

### Switch

The Switch widget sends a command to the devices, typically 1 for ON and 0 for OFF. This widget allows you to turn multiple devices on or off with a single click. Additionally, it can interact with other datastreams and perform various operations that involve two states, such as enabling or disabling features, toggling between modes, or setting specific conditions.

{% hint style="info" %}
Please note that the switch does not reflect the current state of devices. It serves as a control for setting the desired state.
{% endhint %}

<div align="left"><figure><img src="../../../.gitbook/assets/switch.png" alt="" width="276"><figcaption><p>Switch</p></figcaption></figure></div>

{% hint style="warning" %}
The value will be sent to all currently online devices. For offline devices, the value will be stored on the server. When any of these offline devices goes online, they may request the latest state via Blynk.sync() if necessary.
{% endhint %}

#### **How to configure**:

1. Select a datastream.
2. Set On/Off values.
3. Narrow down device selection (optional).
4. Design. Navigate to Design tab to adjust widget appearance such as color and labels.<br>

### Slider

The Slider widget sends a value to devices within a defined range. Move the slider handle or use the fine control buttons (+ and -) to set the value precisely. It may be used to adjust temperature setpoint, fan speed, brightness level, etc.

{% hint style="info" %}
Please note that the slider does not reflect the current value on devices. It serves as a control for setting the desired value.
{% endhint %}

<div align="left"><figure><img src="../../../.gitbook/assets/slider (1).png" alt="" width="330"><figcaption><p>Slider</p></figcaption></figure></div>

{% hint style="warning" %}
The value will be sent to all currently online devices. For offline devices, the value will be stored on the server. When any of these offline devices goes online, they may request the latest state via Blynk.sync() if necessary.
{% endhint %}

#### **How to configure**:

1. Select a datastream.
2. Set Values Range. Enter Min and Max values and Handle step value.
3. Narrow down device selection (optional).
4. Design. Navigate to Design tab to edit the name, choose a color, or enable fine controls.
