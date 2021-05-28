# General issues

{% hint style="warning" %}
There are certain connectivity and HTTP API send issues due to GeoDNS settings changes.  
We feel sorry for the inconvinience you may expirience. It'll be fixed soon!  
Keep your Blynk.App up to date please.
{% endhint %}

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

## **My API request doesn't work**

**What could be the reason:**

* request with incorrect parameters  
* the device token is specified incorrectly  
* wrong pin format input  
* value doesn't match the datastream type  
* requested datastream doesn't exist in the product  
* event code is not provided  
* there's no event with code provided in the product

**What’s the solution:**

* follow [HTTPS guides](https://docs.blynk.io/en/https-api/update-virtual-datastream-value) attentively  
* be sure to send the requests to the correct server  
* check all the inputs to be corrent in the request and to be present in the template _\(also there's a hint on what exactly went wrong in a result field of Postman or web page body\)_

## I can't see all metadata in Blynk.App 

**What could be the reason:**

* not all metadata can be viewed now due to it's not implemented yet

**What’s the solution:**

* view full metadata list in Blynk.360
* wait for Blynk.App full metadata support and update it regularly

## I can't see enumerable datastreams in Blynk.App

**What could be the reason:**

* not supported by every widget at the moment

**What’s the solution:**

* view full metadata list in Blynk.360
* wait for Blynk.App list of widgets that support enumerable datastreams to expand 
* keep Blynk.App up to date
