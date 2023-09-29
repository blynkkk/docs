# Static Token

This type of device activation is designed for commercial deployments of non-WiFi IoT devices, such as cellular (3G, 4G, LTE, etc.), Ethernet, and others. Typically these devices don't require any additional parameters from the end customers to connect to the Internet.

The process of working with Statiс Tokens is the following:

1. Go to Blynk.Console -> Static Tokens
2. Generate the number of Tokens you need based on the number of devices you plan to deploy
3. Each token comes with a corresponding downloadable QR-code image
4. You download the list of Tokens and all QR code images&#x20;
5. You flash AuthToken (Device Token in the table) to every device and print the corresponding QR code
6. Your customers receive the device + printed (or emailed) QR code
7. Your customers download the Blynk app and scan the QR code
8. After scanning the QR code, a device will be claimed by the customer and is now ready to use

Read more about this process here:

{% content-ref url="../../commercial-use/deploying-products-with-static-authtokens.md" %}
[deploying-products-with-static-authtokens.md](../../commercial-use/deploying-products-with-static-authtokens.md)
{% endcontent-ref %}
