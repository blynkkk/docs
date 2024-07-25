# Best Practices

## Group Individual Devices in a Single The Things Network Application

Grouping multiple devices under a single The Things Network application offers several benefits:

1. **Common Payload Formatter**: Configure a shared payload formatter at the application level, which helps prevent potential bugs and simplifies maintenance.
2. **Simplified Management**: Easier to manage multiple devices under one application.

{% hint style="warning" %}
When connecting multiple templates on Blynk to a single The Things Network application, **Device Provisioning from The Things Network will be disabled for both applications**.
{% endhint %}

<figure><img src="../../.gitbook/assets/the-things-network-device-onboarding-warning (1).png" alt="" width="563"><figcaption><p>Device Provisioning is disabled warning</p></figcaption></figure>

## Prefer Device Provisioning through Blynk

For easier maintenance and to avoid potential errors, it is recommended to prefer device provisioning through Blynk rather than The Things Network. This approach also simplifies the device activation process, making it more user-friendly.
