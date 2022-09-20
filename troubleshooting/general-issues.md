# General Issues

## **Can’t log in**

**What could be the reason:**

* wrong email address &#x20;
* the password is incorrect &#x20;
* the user with the specified email address is not registered in the system

**What’s the solution:**

* specify correct email address &#x20;
* be sure to type the correct password &#x20;
* reset password &#x20;
* check the specified email inbox to be sure it's registered in the system &#x20;
* register with a different email address

## **No email received**

**What could be the reason:**

* you entered an incorrect email address &#x20;
* the letter got into the spam folder &#x20;
* email server issues &#x20;

**What’s the solution:**

* specify correct email address &#x20;
* check your spam folder &#x20;
* contact you mail server administrator

## **No connection to server**

**What could be the reason:**

* you do not have an internet connection &#x20;
* the server is rebooting &#x20;
* intermediate providers issues

**What’s the solution:**

* check your internet connection &#x20;
* you should wait for a while to reboot the server &#x20;
* run traceroute command in your OS terminal, contact your ISP and provide them with this data

## I can't see all metadata in Blynk.Apps

**What could be the reason:**

* not all metadata can be viewed now due to it's not implemented yet

**What’s the solution:**

* view full metadata list in Blynk.Console
* wait for Blynk.Apps full metadata support and update Blynk.Apps regularly

## Device is offline

**What could be the reason:**

* connectivity issues
* auth token was changed
* Wi-Fi network SSID or password was changed
* old version of library or even beta version is used
* outdated ESP core version

**What’s the solution:**

* check if the device is powered on
* check your internet connection between the device and Blynk.Cloud (mind Wi-Fi signal strength and distance)
* connect to your device and check if it's auth token matches one in Blynk.Cloud
* be sure to use the latest version of library, otherwise re-flash and launch Device Reprovision process
* check your ESP core version is up to date, otherwise re-flash and launch Device Reprovision process

## "Not correct device" during add device

**What could be the reason:**

* device board hardware is not supported by the Template
* device Template ID mismatch
* wrong Product Name&#x20;

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

## There are no devices in Blynk.Apps [Automation](../concepts/automations/)

**What could be the reason:**

* there are no templates you can use at the moment
* there are no devices added and available to access
* device template has no datastreams allowed for automations

**What’s the solution:**

* create a template or ask your organization admin for it
* add a device so you can access it from Devices tab
* check for the template to have required datastreams are exposed to automations&#x20;

## I press button or move slider and nothing happens to the device

**What could be the reason:**

* connectivity issues
* device issues

**What’s the solution:**

* check your internet connection for both: device and smartphone/PC (Blynk is a cloud platform, there's no offline support)
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

## My hardware constantly disconnected

There are multiple reasons why your hardware could be disconnected. In order to eliminate some obvious reasons, please do the next:

* Run `ping blynk.cloud`. If your connection is good you should see the ping less than 200ms. If you see the higher ping it could be a reason for disconnections
* In case your hardware uses Wi-Fi - check your Wi-Fi signal strength, and make sure there is no other noise that case decrease the signal level
* Make sure you don't use `delay()` instructions in your firmware, long delay in your sketch can break the persistent connection with Blynk Cloud
* Checkout your serial console output, make sure it doesn't contain crashes or other error that may lead to connection interrupts
* Make sure you don't send a huge number of virtualWrite commands per seconds. Blynk Cloud doesn't allow to send more than 20 requests per seconds. Connections that exceeds the limit are closed
