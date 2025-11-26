---
description: Welcome to Blynk Documentation
---

# Introduction



Blynk is a complete IoT software platform where you can prototype, deploy, and remotely manage connected electronic devices at any scale.&#x20;

Whether it's personal IoT projects or commercial connected products in the millions we empower developers and businesses to connect their hardware to the cloud and create iOS, Android, and web applications, analyze real-time and historical data from devices, remotely control them from anywhere, receive important notifications, and much more.

## Components of the Blynk IoT Platform

### Blynk.Console

<figure><img src=".gitbook/assets/1-Introduction-console 1.png" alt=""><figcaption></figcaption></figure>

**Blynk.Console** is a feature-rich web application catering to different [types of users](concepts/users/). Its key functionalities include:

1. Configuration of connected devices on the platform, including application settings.
2. Device, data, user, organization, and location management.
3. Remote monitoring and control of devices

To get started, simply [register in Blynk.Console](https://blynk.cloud).



### Blynk.Apps

![Blynk.Apps](https://user-images.githubusercontent.com/72824404/119525085-e464a300-bd86-11eb-84dc-a4f3de0f7ec9.png)

**Blynk.Apps** is a versatile native iOS and Android mobile application that serves these major functions:

1. Remote monitoring and control of connected devices that work with Blynk platform.
2. Configuration of mobile UI during prototyping and production stages.
3. Automation of connected device operations.

Applications made with Blynk are ready for the end-users. Whether they are family members, employees, or product purchasers, they can easily download the app, connect their devices, and start using them.

Blynk also offers a white-label solution as part of the [Business Plan](https://blynk.io/pricing/business-plan), allowing you to customize the app with your company logo, app icon, theme, colors, and publish it on App Store and Google Play under your company's name. These customized apps will work seamlessly with your devices.

To use Blynk.Apps, [install Blynk app on your iOS or Android device](downloads/blynk-apps-for-ios-and-android.md). For comprehensive [documentation on Blynk.Apps](/broken/pages/-MboiDVEpd2FL0JGkM9f), refer to the provided link.



### Blynk.Edgent and Blynk Library

Edge + Agent = Edgent

<figure><img src=".gitbook/assets/Device-template 3.png" alt=""><figcaption></figcaption></figure>

**Blynk.Edgent** is a packaged solution designed to simplify the connection of supported devices to the Blynk platform, providing access to all its advanced features without extensive coding.

Key features of Blynk.Edgent include:

1. Device claiming and Wi-Fi provisioning (bringing device online and authenticating them with a certain user).
2. Connectivity management for Wi-Fi, Cellular, and Ethernet.
3. Data transfer between device and the cloud.
4. API integration with Blynk.Apps and Blynk.Cloud features.
5. Over-the-air firmware updates for select hardware models.

For [detailed information on Blynk.Edgent](/broken/pages/-MRNVAWBD4_dg3Alekx9), refer to the provided documentation.

**Blynk Library** is a user-friendly and portable C++ library, that comes pre-configured to work with hundreds of development boards. It implements a streaming connection protocol, allowing for low-latency and bi-directional communication.&#x20;

Explore [Blynk Library documentation](/broken/pages/3N6UZd68hmTb9kGG8ZUT) for further details.



### Blynk.Cloud

**Blynk.Cloud** is a server infrastructure acting as the heart of Blynk IoT platform binding all the components together.

Blynk also offers private servers. See the offerings and prices [here](https://blynk.io/pricing).

Blynk is a [multi-tenant](concepts/users/multi-tenant-tree-structure.md) solution that allows you to configure user access to devices and data by defining roles and permissions.

[Register in Blynk.Console](https://blynk.cloud).



## Blynk Micro-Services

Blynk provides micro-services, which are software modules that work across products and perform  specific functionalities. These micro-services include:

### Blynk.Inject

![Blynk.Inject](https://user-images.githubusercontent.com/72824404/119472455-ef9ddb80-bd52-11eb-9c6a-e54746ae32dd.png)

A micro-service that facilitates:

* Claiming device ownership by users and organizations
* Provisioning devices with WiFi credentials so they can connect to the end-user WiFi networks.
* Managing Authentication Tokens
* UX flow to guide end-users through the process of claiming and provisioning with the help of Blynk.Apps

For a better understanding of Blynk.Inject, you can refer to the [documentation](platform-overview/services.md) and provided videos:

<table data-card-size="large" data-column-title-hidden data-view="cards"><thead><tr><th></th><th data-hidden></th><th data-hidden></th><th data-hidden data-card-target data-type="content-ref"></th><th data-hidden data-card-cover data-type="files"></th></tr></thead><tbody><tr><td></td><td></td><td></td><td><a href="https://www.youtube.com/watch?v=yM-ScI8N04A">https://www.youtube.com/watch?v=yM-ScI8N04A</a></td><td><a href=".gitbook/assets/maxresdefault.webp">maxresdefault.webp</a></td></tr><tr><td></td><td></td><td></td><td><a href="https://www.youtube.com/watch?v=4RGAn0tlrHs">https://www.youtube.com/watch?v=4RGAn0tlrHs</a></td><td><a href=".gitbook/assets/plaato.jpeg">plaato.jpeg</a></td></tr><tr><td></td><td></td><td></td><td><a href="https://www.youtube.com/watch?v=bXPEEmsEtPM">https://www.youtube.com/watch?v=bXPEEmsEtPM</a></td><td><a href=".gitbook/assets/Blynk-inject.jpeg">Blynk-inject.jpeg</a></td></tr><tr><td></td><td></td><td></td><td><a href="https://www.youtube.com/watch?v=GPneDxWvp4U">https://www.youtube.com/watch?v=GPneDxWvp4U</a></td><td><a href=".gitbook/assets/cama-cooler.jpeg">cama-cooler.jpeg</a></td></tr></tbody></table>



### Blynk.**R**

<figure><img src=".gitbook/assets/2-introduction-blynkr 1.png" alt=""><figcaption></figcaption></figure>

A micro-service for user management, covering:

* User registration with invitations
* Roles and permissions management
* Multi-tenancy

## Blynk.Air

<figure><img src=".gitbook/assets/3-introduction-blynk-air 1.png" alt=""><figcaption></figcaption></figure>

A micro-service focused on [Firmware Over-the-Air (OTA) Updates](blynk.edgent/updating-devices-firmwares-ota.md), responsible for:

* Managing OTA firmware update campaigns
* Installing new firmware on edge devices

Please note that additional documentation and resources for each component can be found using the provided links.
