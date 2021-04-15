# Test your Template

Let's check if everything is up and running!   
  
Firstly, add a [new device](../activating-devices/) that will inherit your new template.  
After adding it, its dashboard should look like this

![](../../.gitbook/assets/file-3-.jpg)

Now try triggering the switch ON / OFF states and you'll see the data appear on the SuperChart \(in Live mode\)

![](../../.gitbook/assets/file-4-.jpg)

Make sure you have set up the same widgets with the same datastreams on the [web dashboard](set-up-web-dashboard.md) and check how all actions and value updates are synced between the web and mobile app.

![](../../.gitbook/assets/image%20%2824%29.png)

When you click the switch on the web dashboard you will see it moved on the mobile app and vice versa.

Try sending some data to the datastream V1 from your device using the [Blynk.virtualWrite\(\)](../using-virtual-pins-to-control-physical-devices.md) or using the [HTTPS API](../../https-api/update-virtual-datastream-value.md).   
  
For example, I have sent some values to the V1 datastream. The latest value is displayed in the label widget as well as historical data is displayed in the chart.  


![](../../.gitbook/assets/image%20%2822%29.png)

As you can see, the mobile dashboard of your device shows the same data as the web dashboard.  


![](../../.gitbook/assets/file-5-.jpg)

