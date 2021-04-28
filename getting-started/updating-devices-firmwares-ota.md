# Updating Firmware Over-The-Air

### Create the Frimware file

First you need is to create the .bin file of your sketch.  
  
1. Launch Arduino IDE  
2. open the sketch file \(select it depending on the HARDWARE hardware ESP32 or ESP8266\)

![image](https://user-images.githubusercontent.com/65705128/115250112-f0c76180-a131-11eb-96b3-8f3156c7a136.png)

3. launch your web browser and open Blynk.360   
4. open the **Template** you want to be used   
5. copy the code

![image](https://user-images.githubusercontent.com/65705128/115251088-dcd02f80-a132-11eb-9ae6-c657c429b4a1.png)

6. return to your sketch in Arduino IDE  
7. paste the code into Edgent\_ESP32 tab 

![image](https://user-images.githubusercontent.com/65705128/115254884-75b47a00-a136-11eb-8fc4-e4305b7f68b3.png)

8. save the firmware file to the directory  


![image](https://user-images.githubusercontent.com/65705128/115255420-ebb8e100-a136-11eb-8fff-ab3e901f59f2.png)

9. export the sketch in .bin format

![image](https://user-images.githubusercontent.com/65705128/115255779-46523d00-a137-11eb-8420-1ab24f465265.png)

Congratulations! The .bin file will is saved to the sketch folder and now you can use it in Blynk.Air  


![image](https://user-images.githubusercontent.com/65705128/115256352-d09aa100-a137-11eb-91f5-cb8024c17222.png)



### Create Shipping

![Blynk.Air icon in the main menu](../.gitbook/assets/image%20%2814%29.png)

1. Go to [**Blynk.Air**](../web-dashboard/blynk.air/) in Navigation Menu
2. Click **New Shipping** button
3. Specify Target Selection 

![](../.gitbook/assets/target-selection.png)

3.1 Select a **Template** available in the dropdown menu  
3.2 Set **Preferred Time** when the Shipment will be delievering  
3.3 Set Shipping appliance condition by selecting an option available in **Apply Update if the Device has** dropdown menu  
3.4 _Select Devices available_ in the **Devices list** if you want to update certain devices.   
Otherwise _leave the selection empty_ – in this case, all of the selected Template's devices will be updated including these that will be added in the future. 

4. **Upload** **Firmware** file. Click the area with cloud pictogram and select .bin, .tar binary file in your PC file explorer. Drag'n'drop is supported.  
5. Check **Firmware info**

![](../.gitbook/assets/firmware.png)

6. Check for **Optional Settings** under Template selection field and in ****Review and start area  
7. Press **Start Shipping** 

![](../.gitbook/assets/review_and_start.png)

Done!  
After that, the modal window will appear with the progress bar. You can close it, the Shipping will continue working.

![](../.gitbook/assets/shipping_in_progress.png)

You can always check your Shippings status and progress accessing Blynk.Air table:

![](../.gitbook/assets/shipments_tab.png)

For more details follow the link below:

{% page-ref page="../web-dashboard/blynk.air/shipment-management/new-shipping.md" %}



