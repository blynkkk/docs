---
description: How to work with Static Tokens in a commercial setup
---

# Deploying Products With Static AuthTokens

Deployment of commercial IoT products for use by end-customer is a challenging process. Blynk offers tools to simplify this process for developers and end-users. 

Static Auth tokens are used for non-wi-fi devices. The workflow proposed below covers two parts of the process:

1. Preparing your products to deliver to end-customers
2. Claiming products by end-customers

{% hint style="info" %}
This workflow will be updated and improved once Blynk introduces AuthTokens management. Delivery is planned for Q3, 2021.
{% endhint %}

### 

### Supported topologies

Connected products can have various topology.

1. **Direct communication** with the Blynk.Cloud. Cellular devices can connect to the Internet and authenticate in Blynk.Cloud
2. **Gateway \(hub\)** topology. In this setup, gateway is connected to the Internet, and nodes are sending the data to the gateway. Gateway then processes the messages and sends them to the Blynk.Cloud
3. **Mesh Network**. Similar to gateway setup above, but in mesh networks, each device can reroute messages from any device to the gateway. 

\*\*\*\*

### Manual Management

For example, you need to deploy 10 devices for your client. Devices are using cellular connection. 

#### Preparation

1. Manually create 10 devices in Blynk.Console. Go to Search -&gt; Create new device. These devices will be created under your organization. You can also do it under client's organization.
2. When you create device, they are created with an AuthToken
3. When devices are created, you can either go to each Device - Device Info Tab and copy the token, or you can export all devices as CSV file. All AuthTokens will be there.
4. When you have the tokens, you would need to flash them to the devices. This process is not covered by Blynk, so you would need to define what's the best way to flash firmware to a fleet of device. 

Once the tokens were flashed to the hardware, devices can connect to the Internet and authenticate in Blynk.Cloud

{% hint style="info" %}
For hub/gateway topology you can use HTTP API to tunnel messages from the nodes to the Blynk.Cloud. These messages will contain AuthToken of the node and will be identified this way.
{% endhint %}

#### Delivering devices to the client

Since devices already exist in Blynk.Console, all you need to do is to change their ownership. This can be done in a couple of ways:

1. If you created devices under your organization, you would need to transfer them to the client's organization. Go to Search -&gt; Organizations -&gt; Create New Organization. Then invite your client there by using their email address. They will get an email and will be able to create an account
2. When clients' organizaiton is created, you can transfer devices by selecting them and choosing Transfer from Bulk Actions Menu near selection. You can also transfer devices one by one from Device -&gt; Actions Menu -&gt; Transfer 

### 

### AuthToken Management \(planned for Q3 2021\)

We are working on a better way to manage tokens + provision devices with static tokens by end customers.

The planned workflow is next:

1. In Blynk.Console you will be able to generate AuthTokens you need \(not devices as currently\)
2. Each token will all come with a corresponding downloadable QR-code
3. You would flash the tokens to the devices
4. When your customer purchases a device, you will send them the device + printed \(or emailed\) QR code
5. They will download Blynk app and scan the QR code. 
6. After scanning the QR code, device will be claimed by the customer and placed into their organization.

Additionally, you will be able to choose the unique identifer for claiming process. For example, if your devices already have unique number \(e.g. MAC address, Serial Number\), then this number will be mapped to the generated AuthTokens. In this case you won't need to flash the AuthTokens to your hardware.  

You would still need to make nodes to pair with the gateway and reroute messages

