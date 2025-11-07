# Provision Device

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/provision?token={token}&templateId={templateId}`

This API call allows you to complete the device provisioning when using the [WiFi provisioning method](../../getting-started/activating-devices/blynk-edgent-wifi-provisioning.md).\
**Example:**\
`https://fra1.blynk.cloud/external/api/provision?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&templateId=TMPL8sRFwcfqL`

`https://fra1.blynk.cloud/external/api/provision?token=Rps15JICmtRVbFyS_95houlLbm6xIQ2L&templateId=TMPL8sRFwcfqL&build=Oct+1&ver=1.0.0&type=MCU&fwType=TMPL8sRFwcfqL&blVer=2.27.2&boType=ESP32`

#### Path Parameters

<table><thead><tr><th width="190">Name</th><th>Description</th></tr></thead><tbody><tr><td>token</td><td>Device auth token.</td></tr><tr><td>templateId</td><td>Template identifier.</td></tr><tr><td>build</td><td>Firmware build date. Optional.</td></tr><tr><td>ver</td><td>Firmware version (e.g. <code>2.5.1</code>). Optional.</td></tr><tr><td>type</td><td>Firmware type: <code>MCU</code> or <code>NCP</code>. Optional.</td></tr><tr><td>fwType</td><td>User-defined firmware type. Optional.</td></tr><tr><td>blVer</td><td>Blynk library version (e.g. <code>2.5.1</code>). Optional.</td></tr><tr><td>boType</td><td>Board type (e.g. <code>ESP32</code>). Optional.</td></tr></tbody></table>

{% tabs %}
{% tab title="200 OK" %}
Successful response
{% endtab %}

{% tab title="400 Could not find a device token" %}
```
{"error":{"message":"Invalid token."}}
```
{% endtab %}
{% endtabs %}
