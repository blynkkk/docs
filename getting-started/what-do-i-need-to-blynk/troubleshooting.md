# Troubleshooting

## I C**an’t Sign Up or Log In**

Check that correct hardware and port are used when uploading sketch

**Reason:**

Check that use correct WiFi credentials are

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

**Reason:**

* You entered an incorrect email address  
* The letter got into the spam folder  
* Email server issues  

**Solution:**

* Specify correct email address  
* Check your spam folder  
* Contact you mail server administrator

## **No Connection to Cloud Server**

**Reason:**

* You do not have an internet connection  
* The server is rebooting  
* Intermediate providers issues

**Solution:**

* Check your internet connection  
* You should wait for a while to reboot the server  
* Run traceroute command in your OS terminal, contact your ISP and provide them with this data

## Device is Offline

**Reason:**

* Connectivity issues
* SSID and/or pass were not specified
* Old version of library or even beta version is used
* Outdated ESP core version

**Solution:**

* Check if the device is powered on
* Check your internet connection between the device and Blynk.Cloud \(mind Wi-Fi signal strength and distance\)
* Be sure to use the latest version of library, otherwise re-flash and launch Device Reprovision process
* Check your ESP core version is up to date, otherwise re-flash and launch Device Reprovision process

