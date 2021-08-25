# Troubleshooting

## I C**an’t Sign Up or Log In**

Check that correct hardware and port are used when uploading the sketch

**Potential Reasons:**

* Wrong email address  
* The password is incorrect  
* The user with the specified email address is not registered in the system

Check that your device connects to 2.4 WiFi network 

**Solution:**

* Specify correct email address  
* Be sure to type the correct password  
* Reset password  
* Check the specified email inbox to be sure it's registered in the system  
* Register with a different email address

## **No Email Received**

**Potential Reasons:**

* You entered an incorrect email address  
* The email got into the SPAM folder  
* Email server issues  

**Solution:**

* Specify correct email address  
* Check your SPAM folder
* Contact you mail server administrator

## **No Connection to Cloud Server**

**Potential Reasons:**

* You do not have an Internet connection  
* The server is rebooting 
* Intermediate providers issues

**Solution:**

* Check your Internet connection  
* You should wait for a while to reboot the server  
* Run traceroute command in your OS terminal, contact your ISP and provide them with this data

## Device is Offline

**Potential Reasons:**

* Connectivity issues
* Incorrect SSID or password in the sketch code
* SSID or password are not specified in the sketch code
* Old version of library or even beta version is used
* Outdated ESP core version

**Solution:**

* Check if the device is powered on
* Check your Internet connection between the device and Blynk.Cloud \(mind Wi-Fi signal strength and distance\)
* Be sure to use the latest version of library, otherwise re-flash and launch Device Reprovision process
* Check your ESP core version is up to date, otherwise re-flash and launch Device Reprovision process

