# Supported topologies

Connected products can have various topologies.

1. **Direct communication** with the Blynk.Cloud. Cellular or Ethernet devices can connect to the Internet and authenticate in Blynk.Cloud
2. **Gateway (hub)** topology. In this setup, the gateway is connected to the Internet, and nodes are sending the data to the gateway. The gateway then processes the messages and sends them to the Blynk.Cloud
3. **Mesh Network**. This is similar to the gateway setup above, but in mesh networks, each device can reroute messages from any device to the gateway&#x20;

{% hint style="warning" %}
For hub/gateway or mesh topologies, you would need to use HTTP API to tunnel messages from the nodes to the Blynk.Cloud. These messages will contain AuthToken of the node and will be identified this way.
{% endhint %}
