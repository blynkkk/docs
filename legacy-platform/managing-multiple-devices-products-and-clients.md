---
description: >-
  Blynk.Faces, Device Tiles and other techniques to manage variety of Products,
  Devices, and Customers
---

# Managing multiple Devices, Products, and Clients

Blynk offers a variety of options when it comes to managing devices, products, and customers in your own business app. 

When building such a solution using Blynk platform, you would need to prepare the Projects accordingly to your business needs. 

Let's catch up on terms first.

**• 📱Blynk App** – an app for iOS and Android where you build Projects. Think of it as a development environment. Every Project inside of a Blynk app can be [exported](http://help.blynk.cc/publishing-apps-made-with-blynk/export-project-made-with-blynk-into-a-standalone-app) into a Business App.  


**• 📱Business App** – your own exported Android and iOS app with your own logo, icon, branding etc. ready to be published to App Store and Google Play  


**• 💡Product** – a certain type of device, a template. For example, you can manufacture 3 products: a smart lightbulb, a smart switch, and a Thermostat. They are all different Products.  


**• 🎛Project** – layout of widgets in Blynk app to monitor and control devices. Projects have various settings and configurations.  


**• 🗿Face** –  ****a **Project** becomes a Face when the app is exported.  
Read more about Blynk.Faces [here](http://help.blynk.cc/publishing-apps-made-with-blynk/updating-the-apps-made-with-blynk).  


• **👫Client \(or customer\)** - a person or a company who downloads your app from app stores, connects the device and uses the app together with your devices.

### Managing multiple Devices inside of your app <a id="managing-multiple-devices-inside-of-your-app"></a>

  
Every app made with Blynk supports working with multiple devices. Depending on [Device provisioning type](http://help.blynk.cc/publishing-apps-made-with-blynk/1240196-provisioning-products-with-auth-tokens/provisioning-products-with-auth-tokens) you choose, your customers will be able to add multiple devices. 

**🛠Development**  
To enable multiple devices management, your project should have Device Tiles or Device Selector widget installed. Check [documentation](http://docs.blynk.cc/) on how to use them.

![](https://downloads.intercomcdn.com/i/o/80233684/d9c6caee769b47f3320272f5/device+Tiles+image.png)

  
**👫Customer's experience**  
After the app is exported your customers will be able to add multiple devices using a [provisioning flow.](http://help.blynk.cc/publishing-apps-made-with-blynk#1240196-provisioning-products-with-auth-tokens)

![](https://downloads.intercomcdn.com/i/o/80248975/0e44bf8c492ebb93311652ea/wi-fi-wizard.png)

### Managing multiple Products inside of your app <a id="managing-multiple-products-inside-of-your-app"></a>

**🛠Development**  
To manage multiple Products, you need to install Device Tiles widget first.

With the help of Device Tiles widget you can create templates for each Product you have. Each template consists of 2 parts:

1. Tile – How device is shown in the list of devices 
2. Product Page - a set of widgets that will control every device of this type

![](https://downloads.intercomcdn.com/i/o/80236851/e51623f9cc977a53d925b53a/Device+Tiles++Templates.png)

Each template has a generated template ID. You would need to specify the generated Template ID in the firmware file called `Settings.h`  

![](https://downloads.intercomcdn.com/i/o/80231471/d2d7aad203fee3446b4fb925/terminal.png)

**👫Customer's experience**  
Your customers can add multiple devices of different types and they all will be displayed in the app.

![](https://downloads.intercomcdn.com/i/o/80240543/63a904202635d2b2ebb29869/temperature-monitoring-with-blynk-iot.png)

List of devices on location. Devices can be deleted, renamed, reconfigured from **Device Info** section by your customers.

### Managing Projects for multiple customers inside of your app.  <a id="managing-projects-for-multiple-customers-inside-of-your-app"></a>

One of the scenarios of Blynk platform use is when you need to deliver a custom project for each client you have.

Client A ↦ Project A  
Client B ↦ Project B  
Client C ↦ Project C

There are two ways of doing that: 

**1. Create a separate application for each client.** 

This is useful when your clients need their own branded apps. For that you would need to create a separate publishing request and enroll into additional subscription

**2. Publish your own app which will host Face \(Project\) for every client of yours.** 

This will be your branded app, and using Blynk.Faces you will be able to manage and deliver specific Faces to specific clients.

Blynk.Faces also allows you to update interface for every client without re-publishing the app. Read this [article](http://help.blynk.cc/publishing-apps-made-with-blynk/updating-the-apps-made-with-blynk) about app updates.  


![](https://downloads.intercomcdn.com/i/o/80248454/6829136673d1287563f8207d/Blynk-Information-architecture+2.png)

