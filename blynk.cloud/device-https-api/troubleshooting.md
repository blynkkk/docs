# HTTPS API Troubleshooting

* All HTTPS API are case-sensitive. Request path and query parameters letter-case shouldn't be changed.
*   In case you're getting the `Invalid token.` response from the HTTPS API,

    and you're sure the device auth token is correct - it could be a GEO DNS issue.

{% hint style="info" %}
You can get the **Device auth token** in [Device info](https://bit.ly/BlynkSimpleAuth).
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

Using the wrong region will result in an HTTP status of `308 Permanent Redirect` with the correct URL in the `Location` header value in the response. The device must repeat the request with the correct URL and save the correct region for future requests.\
Example HTTP redirect response:

```http
HTTP/1.1 308 Permanent Redirect
Content-Length: 0
Location: https://ny3.blynk.cloud/external/api/isHardwareConnected?token=P-0ekUL3EjrEkE_UnIIzsIggqyQXYd0z
```
