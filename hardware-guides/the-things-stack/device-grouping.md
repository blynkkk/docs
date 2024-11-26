# Device Grouping

It is recommended to create a separate The Things Stack application for each Blynk template. Configuring a payload formatter at the application level ensures that all devices within the application use the same formatter. This avoids mixing devices of different types in a single application and ensures Blynk can correctly associate devices with the appropriate template during importing.

1. **Common Payload Formatter**: Configure a shared payload formatter at the application level, which helps prevent potential bugs and simplifies maintenance.
2. **Simplified Management**: Easier to manage multiple devices under one application.

{% hint style="warning" %}
When connecting multiple templates on Blynk to a single The Things Stack application, **Device Provisioning from The Things Stack will be disabled for both applications**.
{% endhint %}

<figure><img src="../../.gitbook/assets/the-things-network-device-onboarding-warning (1).png" alt="" width="563"><figcaption><p>Device Provisioning is disabled warning</p></figcaption></figure>
