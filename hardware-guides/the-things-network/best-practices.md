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

## System DataStreams

Blynk will automatically populate datastreams named "_RSSI_" and "_SNR_" with values sourced from the antenna of the gateway that has the best SNR. Make sure to create these datastreams with the correct settings. We recommend using the following configuration for the datastreams:

<table><thead><tr><th>Name</th><th>Type</th><th data-type="number">Min</th><th data-type="number">Max</th></tr></thead><tbody><tr><td>RSSI</td><td>Integer</td><td>-110</td><td>0</td></tr><tr><td>SNR</td><td>Double</td><td>1</td><td>30</td></tr></tbody></table>

Additionally, you can provide the firmware version by adding a field named "Blynk Firmware Version" in your decoder. This value will then be accessible on the device page under the "Info & Metadata" and "Developer Tools" tabs.

<figure><img src="../../.gitbook/assets/Снимок экрана 2024-08-20 в 13.44.17.png" alt=""><figcaption></figcaption></figure>
