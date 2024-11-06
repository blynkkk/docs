# Set Up Web Dashboard

Now we need to set up a dashboard template to interact with our device and visualize data from it.

Go to [Web Dashboard](../../blynk.console/templates/dashboard/) **Tab**, click Edit button in the top right corner and drag-n-drop these widgets to the canvas:

* [Switch](../../blynk.console/widgets-console/switch.md)
* [Label](../../blynk.console/widgets-console/label.md)
* [Chart](../../blynk.console/widgets-console/chart.md)

Drag and drop them to the Dashboard Preview window:

![](https://gblobscdn.gitbook.com/assets/-MBFTVMf7L6S67HOuqVC/-MVMYDq0TRdqW29XdjDl/-MVN7FVW7Np3NfDOn3a3/add_widgets.gif?alt=media&token=b1f61faa-acc1-46a8-ad65-5dff6b4039bc)

After widgets are added you can apply the following **actions**.

* **Arrange** – drag the widgets to an area you want so you can form the desired dashboard view
* **Resize** – hover widget's bottom right corner until cursor changes to resize pictogram, hold left mouse button so you can change widget's size and/or shape
* **Delete** – permanently deletes the widget. Hover the widget and navigate to top right, click bin pictogram.
* **Clone** – clones the selected widget (also it can be applied to a configured widget). Hover the widget and navigate to top right, click clone pictogram.
* **Configure** – opens widget configuration window.

![](https://gblobscdn.gitbook.com/assets/-MBFTVMf7L6S67HOuqVC/-MVYDq0TRdqW29XdjDl/-MVGNG7AC55GueGyh3LsB/widget_ext_actions.gif?alt=media&token=b3652d5e-eff2-4187-97fd-58a588151e3b)

You'll get a Dashboard view like this one as result:

<figure><img src="../../.gitbook/assets/12-templat quick setup-web dashboard 1.png" alt=""><figcaption></figcaption></figure>

{% hint style="warning" %}
**IMPORTANT!** At this stage you have set up a dashboard template only, and it will not yet connect to your actual devices. You will need to save the template and apply it to your actual devices.
{% endhint %}

In order to see actual data and interact with your device, you need to go to your devices: Search → My Devices → Device%2F

## Switch widget settings

Hover on the widget and you will see a **Configure** (gear) button. Click it and it will open widget settings. Set up the widget as in the picture below:

<figure><img src="../../.gitbook/assets/13-templ quick setup-web dash-switch set 1.png" alt=""><figcaption></figcaption></figure>

## Label Widget Settings

On this widget, we will be showing data from the device in real-time from the `V0` Datastream.

<figure><img src="../../.gitbook/assets/14-templat-quick-set-web-dash-label-set-1.png" alt=""><figcaption></figcaption></figure>

## Chart Widget Settings

On this widget, we will be showing historical data from the device from the `V0` Datastream.

<figure><img src="../../.gitbook/assets/15-templat Quick Set-Web Dash Chart Set 1.png" alt=""><figcaption></figcaption></figure>

Click **Save** button at the top right of the screen to save all the changes made to the template.

{% hint style="warning" %}
**Important!** At this stage, you have set up a dashboard template only and it will not yet connect to your devices. You will need to save the template and apply it to actual devices.
{% endhint %}

In order to see actual data and interact with your device, you need to go to your devices: Search → My Devices → Device%2F

A more detailed guide on how to configure/manage a more robust web dashboard for your device you can find here:

{% content-ref url="../../blynk.console/templates/dashboard/" %}
[dashboard](../../blynk.console/templates/dashboard/)
{% endcontent-ref %}

Now you can proceed to [Blynk.Apps dashboard setup](set-up-mobile-app-dashboard.md) or [Prepare Your Code](prepare-code.md)