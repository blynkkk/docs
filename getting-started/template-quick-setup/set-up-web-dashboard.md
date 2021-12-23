# Set Up Web Dashboard

Now we need to to setup a dashboard template to interact with our device and visualize data from it.

Go to [Dashboard ](../../blynk.console/devices/device-profile/dashboard.md)Tab and drag-n-drop these widgets to the canvas:

* [Switch](../../blynk.console/templates/dashboard/switch.md)
* [Label](../../blynk.console/templates/dashboard/label.md)
* [Chart](../../blynk.console/templates/dashboard/chart.md)

Drag and drop them to Dashboard Preview window:

![](https://gblobscdn.gitbook.com/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MVMYDq0TRdqW29XdjDl%2F-MVN7FVW7Np3NfDOn3a3%2Fadd\_widgets.gif?alt=media\&token=b1f61faa-acc1-46a8-ad65-5dff6b4039bc)

After widgets are added you can apply the following **actions**:

* **Arrange** – drag the widgets to an areas you want so you can form desired dashboard view
* **Resize** – hover widget's bottom right corner until cursor changes to resize pictogram, hold left mouse button so you can change widget's size and/or shape
* **Delete** – permanently deletes the widget. Hover the widget and navigate to top right, click bin pictogram.
* **Clone** – clones the selected widget (also it can be applied to configured widget). Hover the widget and navigate to top right, click clone pictogram.
* **Configure** – opens widget configuration window.

![](https://gblobscdn.gitbook.com/assets%2F-MBFTVMf7L6S67HOuqVC%2F-MVMYDq0TRdqW29XdjDl%2F-MVNG7AC55GueGyh3LsB%2Fwidget\_ext\_actions.gif?alt=media\&token=b3652d5e-eff2-4187-97fd-58a588151e3b)

You'll get a Dashbord view like this one as result:

![](https://user-images.githubusercontent.com/72824404/119656472-690cfb00-be33-11eb-9f1e-668f0ebcf060.png)

{% hint style="warning" %}
**IMPORTANT!** At this stage you have set up a dashboard _template_ only and it will not yet connect to your actual devices. You will need to save the template and apply it to actual devices.

In order to see actual data and interact with your device, you need to go to your devices: Search -> My Devices -> Device&#x20;
{% endhint %}

## Switch Widget Settings

Hover on the widget and you will see a **Configure** (gear) button. Click it and it will open widget settings. Set up widget as in the picture below:

![](https://user-images.githubusercontent.com/72824404/119656543-7cb86180-be33-11eb-8e90-0aae4545a06f.png)

## Label Widget Settings

On this widget, we will be showing data from the device in real-time from the `V0` Datastream

![](https://user-images.githubusercontent.com/72824404/119656739-b2f5e100-be33-11eb-8816-5a013bb8d17e.png)

## Chart Widget Settings

On this widget, we will be showing historical data from the device from the `V0` Datastream

![](https://user-images.githubusercontent.com/72824404/119656767-bd17df80-be33-11eb-948d-93371e5afefd.png)

Click **Save** button at top right of the screen to save all the changes made to the Template.

{% hint style="warning" %}
**IMPORTANT!** At this stage you have set up a dashboard _template_ only and it will not yet connect to your devices. You will need to save the template and apply it to actual devices.

In order to see actual data and interact with your device, you need to go to your devices: Search -> My Devices -> Device&#x20;
{% endhint %}



Now you can proceed to [Blynk.Apps dashboard setup](set-up-mobile-app-dashboard.md) or [Prepare Your Code](prepare-code.md)
