# Control Segment

The **Control Segment** action allows you to control multiple devices grouped in a segment with a single automation. This makes it easy to apply the same action across many devices without configuring them individually.&#x20;

Use Control Segment when you want to manage groups of devices at scale — for example, switching off all air conditioners in one office segment at 6:00 PM.

{% hint style="info" %}
Available for **Pro and Enterprise plans.**
{% endhint %}

#### Adding a Control Segment Action

1. In the **Actions (Do this)** step, select **Control Segment**.
2. Choose a segment from the dropdown list.

{% hint style="info" %}
The automation applies to all devices in that segment, including devices from sub-organizations (if they are accessible).
{% endhint %}

<figure><img src="../../.gitbook/assets/control segment action.png" alt=""><figcaption></figcaption></figure>

#### Choosing Properties

After selecting a segment, configure which device properties (datastreams) the automation should control:

* Click **Add property**.
* The list will show:
  * All datastreams across templates where **Automation Action** is enabled.
  * Virtual pins (e.g., V1, V2), which let you select multiple datastreams at once if they are aligned by the same virtual pin.

<figure><img src="../../.gitbook/assets/control segment property.png" alt=""><figcaption></figcaption></figure>

{% hint style="info" %}
You can only set values for datastreams that have been enabled for Automations as an **Action** in the Datastream Settings. If a datastream is not enabled, it will not appear in the list.\
To enable this, go to **Datastream Settings → Expose to Automation** in your device template and switch on **Action**.
{% endhint %}

#### Property Settings

Each selected property (datastream) appears in the list, showing the Control element (switch, input, dropdown, etc.). Set the desired value for each selected property

<figure><img src="../../.gitbook/assets/control segment enter property.png" alt=""><figcaption></figcaption></figure>

#### Which Devices the Automation Will Apply To

When the automation is triggered, Blynk checks which devices currently belong to the segment and applies the action to them.

You can see exactly which devices the automation was executed on in the **Automation Logs**.

<figure><img src="../../.gitbook/assets/automations log.png" alt=""><figcaption></figcaption></figure>
