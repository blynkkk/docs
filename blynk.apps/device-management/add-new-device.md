# Add New Device

### Connect the device with Blynk.Apps

Tap **Add New Device** from the Devices tab.

If the app doesn't already have the permissions it needs (e.g. Bluetooth, Local Network, Location), it will ask for them at this point.

{% hint style="info" %}
On iOS 18 and later, Blynk uses Apple's **AccessorySetupKit** for device discovery and pairing. Because AccessorySetupKit handles this natively, the permissions screen is skipped entirely on those devices — the system handles access grants as part of the native pairing sheet instead (see below).
{% endhint %}

#### Prepare Your Device

Before searching for the device, the app shows preparation instructions. What's shown here depends on how the device's template is configured:

* **Multiple templates with their own guides** — you're first asked which template the device belongs to, then shown that template's specific instructions.
* **A single template with an installation guide** — an **Install \[Product Name]** link opens the full guide.
* **No guides configured** — generic preparation instructions are shown.

{% hint style="warning" %}
Per-template installation/activation guides are an **Enterprise plan** feature. On other plans, this screen always shows generic preparation instructions, regardless of how many templates a device could match.
{% endhint %}

{% hint style="info" %}
Template owners configure these per-template instructions (Installation Guide, Activation Guide, Troubleshooting link) under User Guides in the template settings. See the full guide-authoring reference here: [https://docs.blynk.io/en/blynk.console/templates/user-guides#device-activation-guide](https://docs.blynk.io/en/blynk.console/templates/user-guides#device-activation-guide).
{% endhint %}

Read the instructions, make sure your device is powered on and in pairing mode, then tap **Find Devices**.

#### Finding your device

**On iOS**, the system's own AccessorySetupKit window takes over to search for and pair the device — you won't see Blynk's own search screen.

**On Android** (and pre-iOS 18 devices), the system shows its own dialog listing the device's access points found nearby — tap the one you want to connect to, and the app proceeds straight to connecting.

{% hint style="info" %}
If several similar devices might be nearby, set a **Broadcast Name** for the template — the device advertises as `Blynk {broadcast-name}-XXXX` instead of a generic name, so both the AccessorySetupKit sheet and the Android picker above can identify it faster and show its product image and name from this very first step. Configure it under **Template → Template Settings → Device activation & provisioning → Dynamic provisioning**.
{% endhint %}

#### Firmware update, if required

If the device needs a firmware update before it can be provisioned, the standard OTA update screens are shown at this point, before the connection step continues.

#### Connecting

Once a device is selected, the app connects to it and reads its details. If your device supports more than one connection type (e.g. Wi-Fi and Ethernet), you'll be asked to pick one at this point.

Closing the flow at any point from here on prompts a confirmation — exiting counts as a Canceled session, and you'll need to start over.

### Connect your device to a network

#### Wi-Fi

1. If you've previously saved Wi-Fi credentials on this app (via **Remember this network**), you're offered that saved network directly. Otherwise, the app fetches the list of networks visible to the device and shows them for you to pick from. Only networks compatible with the device are listed — 2.4 GHz, 5 GHz, or both, depending on what the device supports.
2. Networks with a weak signal are marked **Weak signal**; selecting one asks you to confirm you want to proceed (or move closer to the router, or pick a different network).
3. Enter the network password. Advanced connection settings (static IP, etc.) are available here if your device supports them.

Once submitted, credentials are sent to the device, the device reports back whether it connected successfully, and the app waits for cloud confirmation that the device is online before showing the success screen.

#### Cellular

Cellular devices may offer a **Configure APN** step if your carrier requires a custom access point name.

#### Ethernet

The app checks for an active Ethernet connection and proceeds automatically once confirmed.

### Success screen

What you see once the device is online depends on what's already known about this template:

1. **Apply saved configuration** — if a device from the same template was provisioned before with metadata, you're offered a button to open a drawer of recent configurations and apply one directly to the new device.
2. **Configure device** — first device from this template with provisioning [metadata](https://docs.blynk.io/en/blynk.console/templates/metadata) enabled: continues into the device profiling flow below.
3. **Nothing further to configure** — if the template has no provisioning metadata enabled, you're done: continue to the device dashboard, or add another device.

### Device profiling

If the template has provisioning metadata enabled, you'll be guided through a short setup wizard for that device (name, location, contact info, unit preferences, or whatever fields the template defines), then a **Review** screen to confirm everything before finishing.

If you've provisioned devices on this template before, you can skip re-entering the same details: press **Apply saved configuration**, choose a previous configuration, and tap **Review and Apply**.

### Error handling

Provisioning is one of the trickiest moments for a new IoT product, so the app tries to be as specific as possible about what went wrong and what to do next. For the full list of error codes and what each one means, see Provisioning Error IDs in Provisioning Sessions.

#### Devices with a live (BLE-assisted) connection

Some devices keep their Bluetooth connection to the phone alive throughout setup. For these, the app can show the _exact_ error the device reported, plus recovery instructions, and lets you resume from the failed step instead of starting over.

The recovery instructions and the **See Troubleshooting** link come from the template's User Guides troubleshooting link, if one is configured, or a generic Blynk documentation link otherwise.

Two additional fields appear below the instructions, visible only in **Developer Mode** — regular end users don't see these:

* **Reason** — the specific error identifier.
* **Session ID** — developers can look this up in Provisioning Sessions in the console to see the full step-by-step timeline for that attempt.

{% hint style="success" %}
BLE-assisted provisioning is supported by the basic Blynk.Edgent examples found in the Blynk.Edgent overview — exact support depends on your hardware type.
{% endhint %}

**Wi-Fi-specific errors** send you straight back to the relevant step — the network list if it was the wrong network, or the password screen (with the previously entered password still visible) if it was a wrong password.

#### Devices without a live connection

If the device isn't BLE-assisted, the connection is simply lost on error and the cause isn't known right away. On your next attempt, the device reports whatever error it last hit, and it's surfaced as a snackbar on the Wi-Fi screen with a link to details.

#### Proximity warnings

The app can detect a weak connection between your phone and the device, or between the device and your router, and will warn you to move closer. The warning clears automatically once the connection improves.

#### Escalation

If the same error happens on the same device three times in a row, the app stops suggesting you just try again and instead opens an escalation drawer:

From here you can **Contact Support**, **Send Logs** (attaches app logs, if logging is enabled), or **Try Again**.

### Claiming a device with a Static Token

Devices that ship with a pre-flashed **Static Token** (cellular, Ethernet, or other non-Wi-Fi hardware) are added the same way — tap **Add New Device** — but instead of Wi-Fi setup you'll claim the device using its QR code:

1. On the same template-driven **Prepare Your Device** screen described above, choose **Scan QR Code**, or **Enter Manually** if the code is printed as text instead of (or alongside) a QR code.
2. Scanning opens a QR scanner in a bottom drawer; manual entry validates the code length as you type and flags it if it's incomplete.
3. Once accepted, the device is claimed to your account and ready to use.

See Static Token for how these tokens are generated and deployed by manufacturers.

### Reconfiguring an existing device

Use **Reconfigure** from the device's actions menu when a device needs new network credentials — the most common reasons are moving it to a new place or updating your Wi-Fi setup (new router, new password, switching networks). It also works for connecting a new or factory-reset device while keeping the data and settings of a previously set-up device. Either way, this starts the provisioning flow described at the top of this page again for that device slot. For the physical button/LED behavior used to reset a device before reconfiguring it, see Re-provisioning new WiFi credentials.
