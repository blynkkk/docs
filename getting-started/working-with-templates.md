# Create Device Template

## What is Device Template

Device Template is a set of configurations inherited by devices of a similar type. 

Think about smart home switches. They all perform a similar function and it's safe to assume that they should have the same data model, GPIOs, firmware code, etc. If you would need to introduce changes to all these devices, instead of editing each of them you could just edit a Device Template and all devices will be updated.

Every Device Template has a **Template ID** – ****a unique template identifier that helps Blynk to recognize the type of added device and attach all other template elements:

**General Settings:**  general settings of the device

**Metadata**: a table of `key:value` data attached to every device. `Keys` are static, and `values` can be different for each device. For example Serial Number. 

**Datastreams:**  channels for any time-stamped data that flows in and out from the device to the cloud. For example sensor data should go through a Datastream. If you used the first version of Blynk platform, these are Virtual Pins. 

**Events:**  important events in the life of the device that should be logged and, if needed, used for notifications. Events can be triggered from the device itself or externally using HTTP API

Template also includes 2 dashboards: one in the mobile app and the second one on the web.

**Web Dashboard:**  a set of UI elements \(widgets\) to visualize the data from the device accessible for the users in Blynk.360 – a web-based application.

**Mobile Dashboard:**  a set of UI elements \(widgets\) to visualize the data in Blynk mobile apps for iOS and Android. Mobile apps also contain a template of how device is represented in the list of devices \(tiles\) 



## Create a Template

1. Open [Templates](https://docs.blynk.io/en/web-dashboard/for-developers/products) section

![](https://lh4.googleusercontent.com/W0PX2U7dcqhJHNzVAu1zkr9vqT8hJVT9g-ZUp-Ql7g9WzY6GMxQ4TEcLpJf-72AGTH9A0keen7X4p7DLWjlvbaI_IKDGzrgW-FUECGMzbMqlBZdtBfTTocol5JpYBJPl8n44uHn1)

2. Click **+ New Template** button to start configuring your product Template

![](https://lh5.googleusercontent.com/HsUTKiaQoHNkxKd7Bi9u0LhOPau987ATLF-2oYPJlwQOfwz1tWH2cpI55dl5nhgyWEFZ-xP9FpKLt3WOutFuq5b5x1IFTeSgS059e37oJnvs8T9WKUvJDiRlM7egSZm0EkIldAnI)

3. Provide basic information about your Product in Create New Template modal window

![](../.gitbook/assets/create_new_template_modal.png)

4. Provide basic [Information](https://docs.blynk.io/en/web-dashboard/for-developers/products/info) about the product you want to create:

![](https://lh3.googleusercontent.com/1iE8NoNVTJYhrB04e5ufTMNLoNy459h_5Ds0h6THt0IhIHsbTvcNujZKShuqTyKXVjHiX1uapd7Qbne09d6TGpi7CsLmqGk23uKSLcwtwJhdVaucfD2Ey678Xge4ksBzJeMjKHyP)

5. Set up your product's [Metadata](https://docs.blynk.io/en/web-dashboard/for-developers/products/metadata) that will describe user's device or environment settings.

![](https://lh3.googleusercontent.com/q2tUJ1bbLclISMu2QRItpT3WVg1prd5RT6nECoeUymKW8MZVugC3jR4Mc8Hfg7Qmw_YYi2-7sWu29QI0nWDoi4YqCx110BAvXdQ_XEHIcyjQycGToMTWeSRUOJGhU_fxZB6ugsuT)



6. Configure [Datastreams](../web-dashboard/products/datastreams/) that you would like to use with your product Devices.

![](https://lh5.googleusercontent.com/V3BzYP__ze9sdfXMxFxhKUzky6DpYlc4cvb_sLrjMSmjTwSaTJA_0OxnBQ1aSABh6ITpZ37I6ABxPNaN0eJ2qFwU_kqd_K9jBonH9JuPNnOCK_BTVtjfunhod82vRwCJOSrfUThJ)

7. Create [Events](https://docs.blynk.io/en/web-dashboard/for-developers/products/events) for your product if you want to monitor devices current status and inform about important events.

![](https://lh3.googleusercontent.com/MBvKHipg7K7Ee3Ashup4Ct7IfRYMQtKQ38qyGBA0mbStoCxzclQnFDk5NduRoLD6eBtak-0yO4PgWADIHL8wah_ScJKBHLAXGf_5UmPfkdO431mw0zctVko2HgaXTrPBlmwIrJRP)

8. Set up [Dashboard](https://docs.blynk.io/en/web-dashboard/for-developers/products/dashboard) for your product that will ease your devices interaction for users

![](https://lh3.googleusercontent.com/d1P5i2hHBaqWVwG5dx1ozOpajNagRFFt4nKR1KdtXTULRpdvcKJ-K2WzQ_iqbkcEuFjyo-9mZAQYAeYc-EovGluPXGPRYnMAZRf2xEfTfNKDc6tHCrUTfP7OSSVZjVcriuFa8cYu)

## Link mobile dashboard with your product:

1. Open [Blynk.App](../mobile-applications/overview.md)
2. Log In to your account
3. Switch to [Developer Mode](developer-mode/)
4. Add a new Template 
5. Link it to your Product 
6. Add the widgets you need and assign them Datastreams
7. Publish the changes 

## Configure your board:

1. Open Dynamic Provisioning Template: - [ESP8266 ](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Inject/Template_ESP8266)- [ESP32 ](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Inject/Template_ESP32)- [MKR1000 ](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Inject/Template_MKR1000)- [MKR1010](https://github.com/blynkkk/blynk-library/tree/master/examples/Blynk.Inject/Template_MKR1010) 
2. Specify [TMPLID](https://docs.blynk.io/en/web-dashboard/for-developers/products/info/template-ids), [SSID WiFi](../web-dashboard/products/info/hotspot-prefix.md) and Board Name in the [sketch](activating-devices/)
3. Flash this template to your board

### Congratulations, you have configured your Product and it is ready to use!

Now all that remains is to [add your test board using Blynk.App](../mobile-applications/device-management/add-new-device.md), make sure it works as you expect, and integrate your code.  
****

