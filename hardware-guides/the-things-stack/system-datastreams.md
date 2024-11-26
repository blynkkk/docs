# System DataStreams

Blynk will automatically populate datastreams named "_RSSI_" and "_SNR_" with values sourced from the antenna of the gateway that has the best SNR. Make sure to create these datastreams with the correct settings. We recommend using the following configuration for the datastreams:

<table><thead><tr><th>Name</th><th>Type</th><th data-type="number">Min</th><th data-type="number">Max</th></tr></thead><tbody><tr><td>RSSI</td><td>Integer</td><td>-110</td><td>0</td></tr><tr><td>SNR</td><td>Double</td><td>1</td><td>30</td></tr></tbody></table>

Additionally, you can provide the firmware version by adding a field named "Blynk Firmware Version" in your decoder. This value will then be accessible on the device page under the "Info & Metadata" and "Developer Tools" tabs.

<figure><img src="../../.gitbook/assets/Снимок экрана 2024-08-20 в 13.44.17.png" alt=""><figcaption></figcaption></figure>
