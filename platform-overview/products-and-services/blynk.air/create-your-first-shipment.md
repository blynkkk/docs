# Create your first shipment

## 

![Blynk.Air icon in the main menu](../../../.gitbook/assets/image%20%2814%29.png)

* Go to Blynk.Air
* Click **Create New Shipment**
* Select a Product / Template 
* Select devices if you want to update certain devices or leave the selection empty. In this case, all devices will be updated including the ones that will be added in the future.
* Upload the binary file. 
* Press **Start Shipping** 

After that, the modal window will appear with the progress bar. You can close it, the shipment will continue working.   


### **Firmware info**

When the binary file is uploaded, the extracted information is shown in this section. It is useful for making sure you have picked the right file.

![](../../../.gitbook/assets/image%20%284%29.png)

### **Other shipment parameters**

**Preferred time**

* **Any** The devices will be updated as soon as they connect to the server. 
* **Night, Morning, Afternoon, Evening**  These are other options if you need to update at a certain time of day.

**Apply Update if the Device has**

* **Lower firmware version** A semantic version is parsed from the binary file and compared against the device's firmware version. This option is the ****default.
* **Earlier build date, Another build date**  A build date of the binary file is parsed from the firmware info and compared against the stored one in the device information.
* **Lower generic version** A Blynk.Edgent library version is compared. 

![](../../../.gitbook/assets/image%20%2815%29.png)

There are a couple of other options:

* **Attempts limit** and **Attempts reset period** If the device has failed to update for N times, the server will stop trying updating it until the attempts reset period will pass \(which is 24 hours by default\).



