---
description: How to work with Static Tokens in a commercial setup
---

# Deploying Products With Static Tokens

Deployment of commercial IoT products for use by end-customer is a challenging process. Blynk offers tools to simplify this process for developers and end-users. 

Static Tokens are used for non-WiFi devices. The workflow proposed below covers two parts of the process:

1. Preparing your products to deliver to end-customers
2. Claiming products by end-customers



### Supported topologies

Connected products can have various topologies.

1. **Direct communication** with the Blynk.Cloud. Cellular devices can connect to the Internet and authenticate in Blynk.Cloud
2. **Gateway \(hub\)** topology. In this setup, the gateway is connected to the Internet, and nodes are sending the data to the gateway. Gateway then processes the messages and sends them to the Blynk.Cloud
3. **Mesh Network**. Similar to gateway setup above, but in mesh networks, each device can reroute messages from any device to the gateway. 

{% hint style="warning" %}
For hub/gateway or mesh topologies, you would need to use HTTP API to tunnel messages from the nodes to the Blynk.Cloud. These messages will contain AuthToken of the node and will be identified this way.
{% endhint %}

### 

### Preparation 

The process of working with Static Tokens is next:

1. Go to Blynk.Console → Static Tokens
2. Generate the number of Tokens you need based on the number of devices you plan to deploy
3. Each token comes with a corresponding downloadable QR-code image
4. You download the list of Tokens and all QR code images 
5. You flash AuthToken to every device and print the corresponding QR code

Now products are ready for sale/delivery/deployment

### 

### Device activation by end customers

When customers receive your device, they would need to dowload the Blynk app. It's recommended that you include this step into the manual. 

1. Your customers receive the device + printed \(or emailed\) QR code
2. Your customers download the Blynk app and create a new account there. Alternatively, you can create a new sub-organization and invite your customer there. 
3. Your customer scans the QR code. 
4. Device appears in the apps and is ready for use.

At this stage, the device is claimed \(owned\) by the customer and assigned to an organization user belongs to.



