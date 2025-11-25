---
description: >-
  Logs are a very powerful tool in the hands of our developers. Using them we
  can find a cause of an issue within a minimum amount of time.
hidden: true
---

# App and board logs. How to send application and board logs correctly

{% hint style="warning" %}
This documentation is for the LEGACY version of Blynk platform which is no longer supported and will be shut down.&#x20;

You can sign up for the current version of Blynk platform [here](http://blynk.cloud/dashboard/register).

The new mobile apps can be downloaded from [App Store](https://apps.apple.com/us/app/blynk-iot/id1559317868) and [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk\&hl=en\&gl=US).

The actual Blynk documentation is [here](https://docs.blynk.io/).
{% endhint %}

### How to prepare and send the logs? <a href="#how-to-prepare-and-send-the-logs" id="how-to-prepare-and-send-the-logs"></a>

#### Mobile app \[Android and iOS] <a href="#mobile-app-android-and-ios" id="mobile-app-android-and-ios"></a>

Please follow these steps:\
1\. Open your standalone application\
2\. Log into your account\
3\. Open device section:

![](https://downloads.intercomcdn.com/i/o/258172665/26676b5e6342ca61cc2ed7dd/image.png)

4\. Click the version button:

![](https://downloads.intercomcdn.com/i/o/258172982/9d1ace4a2817e5ad9529128f/image.png)

5\. Click "Clear logs" button":

![](https://downloads.intercomcdn.com/i/o/258173871/4f823c50267c05e305c17c2e/image.png)

6\. Reproduce the issue again\
7\. Click "Send logs to developer" button:

![](https://downloads.intercomcdn.com/i/o/258174164/87b5aa83103ba655714f6575/image.png)

8\. Choose your Email client \[Gmail, Spark, etc.]\
9\. Add [**issue name**](https://app.intercom.com/a/apps/hhaxrs9k/articles/articles/4558850/show) to the email body

10\. Click "Send" button\
\
In case you have issues logging into the application or connecting to a server you can send logs from the app splash screen. To do this, you need to long click on the logo:

![](https://downloads.intercomcdn.com/i/o/258175773/4acdde237ad7c2fa45bc7d6a/image.png)

#### Hardware <a href="#hardware" id="hardware"></a>

Please follow these steps:\
1\. [Activate](https://docs.blynk.cc/#troubleshooting-enable-debug) the detailed logging \[debug mode]\
2\. Flash the new sketch to your board\
3\. Open Serial Monitor Output:

![](https://downloads.intercomcdn.com/i/o/258176551/319a2a074a5022b49e82eb36/image.png)

4\. Reproduce the issue:

![](https://downloads.intercomcdn.com/i/o/258176954/a46905e024a4e5540bac137b/image.png)

5\. Save board logs as a separate text file\
6\. Attach the file to email with [**issue name**](https://app.intercom.com/a/apps/hhaxrs9k/articles/articles/4558850/show) and description of the issue<br>

#### **Bare-minimum sketch** <a href="#bare-minimum-sketch" id="bare-minimum-sketch"></a>

If an issue is in your code and it is not reproducible with the Sketch Template please send us a bare-minimum sketch. It allows you to reproduce the issue and does not contain unnecessary logic because we will not be able to review all your lines of code.

#### **Other** <a href="#other" id="other"></a>

If your issue is with:\
1\. UI / UX: we will need a screenshot with the issue

2\. Communication with a server: we will need your application logs\
3\. Sending data between board-server-application: we will need your application logs / Serial Monitor Output / bare-minimum sketch\
4\. If a screenshot will not display the issue because it is not static or it is difficult to describe it with the text - we will need a video.<br>
