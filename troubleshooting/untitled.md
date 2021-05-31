# General issues

## **Can’t log in**

**What could be the reason:**

* wrong email address  
* the password is incorrect  
* the user with the specified email address is not registered in the system

**What’s the solution:**

* specify correct email address  
* be sure to type the correct password  
* reset password  
* check the specified email inbox to be sure it's registered in the system  
* register with a different email address

## **No email received**

**What could be the reason:**

* you entered an incorrect email address  
* the letter got into the spam folder  
* email server issues  

**What’s the solution:**

* specify correct email address  
* check your spam folder  
* contact you mail server administrator

## **No connection to server**

**What could be the reason:**

* you do not have an internet connection  
* the server is rebooting  
* intermediate providers issues

**What’s the solution:**

* check your internet connection  
* you should wait for a while to reboot the server  
* run traceroute command in your OS terminal, contact your ISP and provide them with this data

## I can't see all metadata in Blynk.App 

**What could be the reason:**

* not all metadata can be viewed now due to it's not implemented yet

**What’s the solution:**

* view full metadata list in Blynk.360
* wait for Blynk.App full metadata support and update Blynk.App regularly

## Device is offline

**What could be the reason:**

* connectivity issues
* auth token was changed
* Wi-Fi network SSID or password was changed

**What’s the solution:**

* check if the device is powered on
* check your internet connection between the device and Blynk.Cloud
* connect to your device and check if it's auth token matches one in Blynk.Cloud
* launch Device Reprovision

## "Not correct device" during add device

**What could be the reason:**

* device board hardware is not supported by the Template
* device Template ID mismatch
* wrong Product Name 

**What’s the solution:**

* be sure to use the hardware that is mentioned in Template's Info page
* be sure you paste correct BLYNK\_TEMPLATE\_ID to the sketch
* be sure you paste correct BLYNK\_DEVICE\_NAME to the sketch

## I can't erase data from a device

**What could be the reason:**

* some time is required to erase all device data
* there was network disconnection during the command send

**What’s the solution:**

* wait for up to 5 minutes and re-check device's data
* check your network connection, re-send the command

