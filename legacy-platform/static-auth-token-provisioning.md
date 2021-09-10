---
description: How to include Static Auth Token Provisioning to your App
---

# Static Auth Token Provisioning

Static Auth Token Provisioning is used for devices that connect to the Internet over the Ethernet, cellular networks and other connectivity types.

**☝️** In this workflow, **every product you deliver to the customer will be pre-flashed with Auth Token**.

#### How it works for your customers: <a id="how-it-works-for-your-customers"></a>

1. Your happy customers open the box with your product;
2. Every product comes with the QR code. It can be printed and put into the box, or can be sent over email as a .png image;
3. After your customers downloaded your app from App Store or Google Play, they create new account and log into your app;
4. From there they can scan the QR code;
5. Your app scans the code and saves the Auth Token on the smartphone;
6. Now smartphone talks to the device with the same Auth Token;

#### How to include Static Auth Token Provisioning to your App <a id="how-to-include-static-auth-token-provisioning-to-your-app"></a>

1. You use regular Blynk code and library to develop firmware;
2. You request a number of Auth Tokens from Blynk. Contact us at [blynk.io](http://blynk.io/). Let's say you have 1,000 devices. Then you would need to request 1,000 Auth Tokens;
3. We provide you with a list of Auth Tokens. Every Auth Token is associated with the QR code image. You get an archive with PNG images of QR Codes + Auth Tokens;
4. You would need to flash every new hardware with the Auth Token from the list we provided;
5. Before you send the product to your customers, print QR codes and place them in the package box, or send them over email. Whatever is more convenient for you;

---

#### If you have any questions - [contact us](mailto://iot@blynk.cc) or post to our [forum](https://community.blynk.cc/). <a id="if-you-have-any-questions---contact-us-or-post-to-our-forum"></a>

