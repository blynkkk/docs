# Automated Device Onboarding

{% hint style="success" %}
**Use Device Provisioning through Blynk Where Possible**

For easier maintenance and to minimize potential errors, device provisioning through Blynk is strongly recommended over The Things Stack. This approach streamlines the device activation process, making it more efficient and user-friendly.
{% endhint %}

To enable the Automated Device Onboarding through Blynk, follow these steps:

1. Open the advanced settings of the application on Blynk.
2. Turn on the "Enable automated device onboarding" switch.
3. Specify the LoRaWAN version, Frequency plan, and Regional Parameter Version. Also, enable the "Support class B" and/or "Support class C" checkboxes if required.
4. Specify the addresses of The Things Stack components, which can be found by navigating to **Home -> Admin panel -> Network information** at the bottom of the page. If you are using The Things Stack Sandbox, all components share the same regional domain.
5. Save the changes.

<figure><img src="../../.gitbook/assets/the-things-network-advanced-settings.png" alt="" width="563"><figcaption><p>The Things Stack Application Advanced Settings</p></figcaption></figure>

{% hint style="info" %}
At this point, Blynk creates three new metadata fields in the device template: _Device EUI_, _Join EUI_ (same as App EUI), and _Application Key_.
{% endhint %}

Additionally, Blynk requires the "**View device keys in application**", "**Create devices in application**" and "**Edit device keys in application**" permissions. To provide this, generate a new API key or edit the existing one that you were using with Blynk.

<figure><img src="../../.gitbook/assets/Снимок экрана 2024-07-18 в 16.43.01.png" alt=""><figcaption><p>API Key settings on The Things Network Application page</p></figcaption></figure>

Now that automated device onboarding is enabled and configured, you can onboard your first device. Blynk supports three ways to onboard a device on The Things Stack. Let's cover them separately.

{% hint style="info" %}
Sometimes, a device requires a reboot to initiate the onboarding flow. Make sure to restart the device if it doesn't automatically start the onboarding process after following the setup steps. This can help ensure the device properly connects and begins the necessary communication with Blynk and The Things Stack.
{% endhint %}

## Manually configure the tokens

This is the easiest, but least scalable way to onboard the device:

1. Start by [creating the device from the template](../../blynk.console/devices/actions-with-devices.md#create-device) on the web dashboard.
2. Open "**Info & Metadata**" and fill out the three metadata fields: Device EUI, Join EUI (same as App EUI), and Application Key.

<figure><img src="../../.gitbook/assets/Снимок экрана 2024-07-18 в 16.47.08.png" alt=""><figcaption><p>Device Info &#x26; Metadata Settings</p></figcaption></figure>

Once these three metadata fields are specified, Blynk will automatically create the device in The Things Stack application.

## Onboard using Static Tokens

The preferred method for device provisioning is using [Static Tokens](../../commercial-use/deploying-products-with-static-authtokens.md). Here’s how to do it:

1. Create a CSV file listing the Device EUI, Join EUI (same as App EUI), and Application Key for each device.
2. Use this CSV file to [create static tokens](../../getting-started/activating-devices/blynk-edgent-static-authtoken.md): open the **Developer Zone** -> **Static Tokens** -> **Generate Static Tokens** -> **Create From File**. Then select the device template and upload the file.
3. This process will generate a unique QR code for each device.
4. These QR codes can be scanned via the mobile application or on the web dashboard.
5. Once a QR code is scanned and the device is created, it will be automatically created on The Things Stack.

Here is an example of a CSV file that could be used for creating static tokens:

```csv
Device EUI,Join EUI,Application Key
0018B20000000101,70B3D57ED0000010,2B7E151628AED2A6ABF7158809CF4F3C
0018B20000000102,70B3D57ED0000011,3B7E151628AED2A6ABF7158809CF4F3D
0018B20000000103,70B3D57ED0000012,4B7E151628AED2A6ABF7158809CF4F3E
```

## Onboard using LoRaWAN QR Code

Blynk also supports [LoRaWAN® Device Identification QR Codes for Automated Onboarding](https://lora-alliance.org/wp-content/uploads/2020/11/TR005_LoRaWAN_Device_Identification_QR_Codes.pdf). To use them, follow these steps:

1. First, create the static tokens as described in the "[Onboard using Static Tokens](automated-device-onboarding.md#onboard-using-static-tokens)" section.
2. Construct the QR code in the LoRaWAN format using the Profile ID specified in the advanced settings of The Things Stack integration application card.

Additionally, you can change the Profile ID used in the QR code body. To do so, open the application settings on Blynk, locate to the advanced settings and edit the Profile ID field.

<figure><img src="../../.gitbook/assets/the-things-network-lorawan-profile-id.png" alt="" width="563"><figcaption><p>Application Profile ID Field</p></figcaption></figure>

For LoRaWAN QR codes, Blynk requires the following:

1. The code must start with `LW:D0`.
2. It must contain the Join EUI (same as App EUI), Device EUI, and the Profile ID.
3. Optionally, it may contain a checksum.
4. Any other parts of the QR code are ignored.

Here is an example of how the QR code data should be structured:

```php-template
LW:D0:<Join EUI>:<Device EUI>:<Profile ID>:<Optional CheckSum>
```

Here is an example of the QR code body with `Join EUI = 70B3D57ED0000010`, `Device EUI = 0018B20000000101` and `Profile ID = 000AF8BE`:

```
LW:D0:70B3D57ED0000010:0018B20000000101:000AF8BE
```

Then this QR code can be scanned in the same way as Static Tokens in the mobile application or on the console. Once the device is created, it will be automatically onboarded on The Things Stack.

## Re-provisioning

If you've changed your hardware or updated any LoRaWAN connection parameters (such as DevEUI, AppEUI/JoinEUI, or Application Key), you will need to create a new device in The Things Stack.

To retain the historical data, settings, or any other details for the old device in Blynk, follow these steps:

1. Navigate to the **Device Information & Metadata** tab for the old device in Blynk.
2. Update the **TheThingsNetwork Device ID** metafield.
3. Optionally, you can also update other related metafields like **DevEUI**, **JoinEUI**, and **Application Key**.

{% hint style="danger" %}
If the new device goes online in The Things Stack before updating the metafields in Blynk, it may be automatically imported into Blynk. In case of a **TheThingsNetwork Device ID** collision (where two devices have the same ID), Blynk will randomly select one device.\
To resolve this, simply delete the automatically imported device to ensure the correct one is used.
{% endhint %}
