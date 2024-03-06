# HTTPS API Troubleshooting

* All HTTPS API are case-sensitive. Request path and query parameters letter-case shouldn't be changed.
* Make sure you're using the correct server. The correct host should be `blynk.cloud`
*   In case you're getting the `Invalid token.` response from the HTTPS API,

    and you're sure the device auth token is correct - it could be a GEO DNS issue.&#x20;

{% hint style="info" %}
You can get the **Device auth token** in [Device info](../../getting-started/activating-devices/manual-device-activation.md#step-3-getting-auth-token).
{% endhint %}

{% hint style="warning" %}
Due to current GeoDNS settings you need to put server address with suffix manually depending on your region:\
[https://fra1.blynk.cloud/](https://fra1.blynk.cloud/) – Frankfurt\
[https://lon1.blynk.cloud/](https://lon1.blynk.cloud/) – London\
[https://ny3.blynk.cloud/](https://ny3.blynk.cloud/) – New York\
[https://sgp1.blynk.cloud/](https://sgp1.blynk.cloud/) – Singapore\
[https://blr1.blynk.cloud/](https://blr1.blynk.cloud/) – Bangalore

The server region can be found in the right bottom corner of the web interface.
{% endhint %}

