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

{% hint style="info" %}
For hub/gateway or mesh topologies, you would need to use HTTP API to tunnel messages from the nodes to the Blynk.Cloud. These messages will contain AuthToken of the node and will be identified this way.
{% endhint %}

### 

1. In Blynk.Console generate the number of Tokens you need based on the number of devices you plan to deploy
2. Each token will all come with a corresponding downloadable QR-code
3. After flashing firmware to your devices, you'll be able to add AuthToken to each device
4. Your customers receive the device + printed \(or emailed\) QR code
5. They will download Blynk app and scan the QR code. 
6. After scanning the QR code, device will be claimed by the customer and placed into their organization.

You would still need to make nodes to pair with the gateway and reroute messages

