---
description: Welcome to Blynk Documentation
---

# Introduction

{% hint style="success" %}
This documentation covers the **latest generation** of the Blynk IoT Platform.
{% endhint %}

Blynk is a full suite of software required to prototype, deploy, and remotely manage connected electronic devices at any scale: from personal IoT projects to millions of commercial connected products.

With Blynk anyone can connect their hardware to the cloud and build a no-code iOS, Android, and web applications to analyze real-time and historical data coming from devices, control them remotely from anywhere in the world, receive important notifications, and much more…

## Products that Blynk IoT Platform consists of

### Blynk.Console

![Blynk.Console](https://user-images.githubusercontent.com/72824404/119524638-8041df00-bd86-11eb-831a-0d38fc6c07d3.png)

**Blynk.Console** is a feature-rich web application that can be used by different [types of users](concepts/users/). Major functionality of this product is:

1. Configuration of how connected devices work on the platform + application settings.
2. Management of devices, their data, users, organizations and locations&#x20;
3. Remote monitoring and control of devices

[Register in Blynk.Console](https://blynk.cloud)

### Blynk.Apps

![Blynk.Apps](https://user-images.githubusercontent.com/72824404/119525085-e464a300-bd86-11eb-84dc-a4f3de0f7ec9.png)

**Blynk.Apps** is a multi-functional native iOS and Android mobile application that serves these major functions:

1. Remote monitoring and control of connected devices that work with Blynk platform
2. Configuration of mobile UI during prototyping and production stages
3. Automate work of connected devices

Applications made with Blynk are ready for the end-users. Whether it is your family member, an employee, or someone who has purchased your product, they will be able to download the app, connect the device and start using it.

Blynk also offers a white-label solution (part of the Business Plan), which means that you can add your company logo, app icon, choose the theme, colors, and publish the app to App Store and Google Play under your company name. These apps will work with your devices.

[Install Blynk app for iOS or Android](downloads/blynk-apps-for-ios-and-android.md)

Full documentation on Blynk.Apps is [here](blynk.apps/overview.md)

### Blynk.Edgent

Edge + Agent = Edgent

<figure><img src=".gitbook/assets/Device-template 3.png" alt=""><figcaption></figcaption></figure>

**Blynk.Edgent** is a packaged solution that allows developers to easily connect supported devices to the platform and take advantage of all its advanced features without the need for extensive coding.

Main functions of Blynk.Edgent are:

1. Device claiming and Wi-Fi provisioning (bringing device online and authenticating them with a certain user)
2. Connectivity management (WiFi, Cellular, Ethernet)
3. Data transfer between the device and cloud&#x20;
4. API to work with specific Blynk.Apps and Blynk.cloud features
5. Over-the-air firmware updates (for selected hardware models)

Full documentation on Blynk.Edgent is [here](blynk.edgent/overview.md).

### Blynk.Cloud

**Blynk.Cloud** is a server infrastructure – heart of Blynk IoT platform. Cloud is responsible for binding all the platform components together.

Blynk also offers private servers. See the offerings and prices [here](https://blynk.io/pricing).

[Register in Blynk.Console](https://blynk.cloud)

Blynk is a [multi-tenant](concepts/users/multi-tenant-tree-structure.md) solution. You can configure how users get access to the data by setting roles and configuring permissions.

Blynk services (or micro-services) are software modules that work across products and perform a certain set of functionality.

## Blynk.Inject

![Blynk.Inject](https://user-images.githubusercontent.com/72824404/119472455-ef9ddb80-bd52-11eb-9c6a-e54746ae32dd.png)

A micro-service for:

* Claiming device ownership by users and organizations
* Provisioning devices with WiFi credentials so they can connect to the end-user WiFi networks.
* Managing Authentication Tokens
* UX flow to guide end-users through the process of claiming and provisioning with the help of Blynk.Apps

To get understanding of the Blynk Inject take a look at the below videos:

[![Blynk Inject flow. Blynk](http://img.youtube.com/vi/bXPEEmsEtPM/0.jpg)](http://www.youtube.com/watch?v=bXPEEmsEtPM)

[![Blynk Inject flow. Plaato](http://img.youtube.com/vi/4RGAn0tlrHs/0.jpg)](http://www.youtube.com/watch?v=4RGAn0tlrHs)

[![Blynk Inject flow. Cama Cooler](http://img.youtube.com/vi/GPneDxWvp4U/0.jpg)](http://www.youtube.com/watch?v=GPneDxWvp4U)

## Blynk.**R**

![Roles and permissions](https://user-images.githubusercontent.com/72824404/119471708-3808c980-bd52-11eb-89bd-7b003fc94da1.png)

A micro-service for user management, covering

* User registration with invitations
* Roles and permissions management
* Multi-tenancy

## Blynk.Air

![Blynk.Air](https://user-images.githubusercontent.com/72824404/119467722-72706780-bd4e-11eb-809c-eebfe3078bb1.png)

A micro-service for Firmware Over-the-Air Updates responsible for:

* Managing Firmware Over-the-Air Updates shipping campaigns
* Installing new firmware on the edge devices
