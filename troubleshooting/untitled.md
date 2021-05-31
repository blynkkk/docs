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

## There are no devices in Blynk.App Automation

**What could be the reason:**

* there are no templates you can use at the moment
* there are no devices added and available to access
* device template has no datastreams allowed for automations

**What’s the solution:**

* create a template or ask your organization admin for it
* add a device so you can access it from Devices tab
* check for the template to have required datastreams are exposed to automations 

## I press button or move slider and nothing happens to the device

**What could be the reason:**

* connectivity issues
* device issues

**What’s the solution:**

* check your internet connection for both: device and smartphone/PC \(Blynk is a cloud platform, there's no offline support\)
* be sure that device is powered on and has no circuit or physical damage

## I can't download device report

**What could be the reason:**

* connectivity issues
* no data for the selected device
* you have no permissions to do that

**What’s the solution:**

* check your internet connection
* no report can be provided for download if there's no data for it
* contact your organization administrator

