# Firmware Over-The-Air

## Compile a Firmware binary file

To send the firmware over the air, you need to compile it into a binary file that has `.bin` file extension.

{% tabs %}
{% tab title="Arduino IDE" %}
1. Launch Arduino IDE  
2. Open your sketch file which is working with Blynk application

![image](https://user-images.githubusercontent.com/65705128/115250112-f0c76180-a131-11eb-96b3-8f3156c7a136.png)

1. Make sure you have **Template ID** specified in the sketch. You can find it in Template -&gt; Info in Blynk.Console

![image](https://user-images.githubusercontent.com/65705128/115251088-dcd02f80-a132-11eb-9ae6-c657c429b4a1.png)

![image](https://user-images.githubusercontent.com/65705128/115254884-75b47a00-a136-11eb-8fc4-e4305b7f68b3.png)

![image](https://user-images.githubusercontent.com/65705128/115254884-75b47a00-a136-11eb-8fc4-e4305b7f68b3.png)

1. Go to File -&gt; Save

![image](https://user-images.githubusercontent.com/65705128/115255420-ebb8e100-a136-11eb-8fff-ab3e901f59f2.png)

1. Now go to Sketch -&gt; Export compiled Binary

![image](https://user-images.githubusercontent.com/65705128/115255779-46523d00-a137-11eb-8420-1ab24f465265.png)

You can fild a `.bin` file in the sketch folder. It's ready to be used with Blynk.Air over-the-air updates

![image](https://user-images.githubusercontent.com/65705128/115256352-d09aa100-a137-11eb-91f5-cb8024c17222.png)
{% endtab %}

{% tab title="Platformio" %}

{% endtab %}
{% endtabs %}

## Create Shipping

1. Go to [**Blynk.Air**](https://github.com/blynkkk/docs/tree/874cbfc84deeb7af25fc16dc69cc0aabc984189c/blynk.console/blynk.air) in Left Menu
2. Click **New Shipping** button
3. Specify Target Selection 

![](../.gitbook/assets/target-selection.png)

3.1 Select a **Template** available in the dropdown menu  
3.2 Set **Preferred Time** when the Shipment will be delievering  
3.3 Set Shipping appliance condition by selecting an option available in **Apply Update if the Device has** dropdown menu  
3.4 _Select Devices available_ in the **Devices list** if you want to update certain devices.  
Otherwise _leave the selection empty_ – in this case, all of the selected Template's devices will be updated including these that will be added in the future.

1. **Upload** **Firmware** file. Click the area with cloud pictogram and select .bin, .tar binary file in your PC file explorer. Drag'n'drop is supported.  
2. Check **Firmware info**

![](../.gitbook/assets/firmware.png)

1. Check for **Optional Settings** under Template selection field and in \_\*\*\_Review and start area  
2. Press **Start Shipping** 

![](../.gitbook/assets/review_and_start.png)

Done!  
After that, the modal window will appear with the progress bar. You can close it, the Shipping will continue working.

![](../.gitbook/assets/shipping_in_progress.png)

You can always check your Shippings status and progress accessing Blynk.Air table:

![](../.gitbook/assets/shipments_tab.png)

For more details follow the link below:

{% page-ref page="../blynk.console/blynk.air/shipment-management/new-shipping.md" %}

