# Developer Mode

## I can't enable Developer Mode

**What could be the reason:**

* Organization can have only one developer account. That is done to avoid sync issues.

**What’s the solution:**

* Contact other users with admin role and ask them to disable Developer Mode on their side so you could enable it on yours.
* This limit can be changed in the future.

## Changes made to Device Template are not applied

**What could be the reason:**

* there was no Save action confirmation
* Save command was sent during the server disconnect

**What’s the solution:**

* be sure to click Save button on the top right after you made changes that you want to keep
* check your internet connection please.
* keep the page open, click Save once you'll get "Connection has been restored" 

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

* follow [HTTPS guides](https://docs.blynk.io/en/https-api/update-datastream-value) attentively  
* be sure to send the requests to the correct server  
* check all the inputs to be corrent in the request and to be present in the template _\(also there's a hint on what exactly went wrong in a result field of Postman or web page body\)_

## I can't see enumerable datastreams in Blynk.App

**What could be the reason:**

* not supported by every widget at the moment

**What’s the solution:**

* view full metadata list in Blynk.360
* wait for Blynk.App list of widgets that support enumerable datastreams to expand 
* keep Blynk.App up to date

