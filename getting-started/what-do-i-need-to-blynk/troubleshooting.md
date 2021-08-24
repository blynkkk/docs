---
description: Work In Progress
---

# Troubleshooting

## I c**an’t sign up or log in**

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

## Device is offline

**What could be the reason:**

* connectivity issues
* auth token was changed
* Wi-Fi network SSID or password was changed
* old version of library or even beta version is used
* outdated ESP core version

**What’s the solution:**

* check if the device is powered on
* check your internet connection between the device and Blynk.Cloud \(mind Wi-Fi signal strength and distance\)
* connect to your device and check if it's auth token matches one in Blynk.Cloud
* be sure to use the latest version of library, otherwise re-flash and launch Device Reprovision process
* check your ESP core version is up to date, otherwise re-flash and launch Device Reprovision process

