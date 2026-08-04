# Datastream Settings

## Datastream Settings

Each Datastream is configured through a settings panel with a left-side navigation. This page covers all available settings.

***

### General

**Datastream Name**\
The internal name used for your reference and as the MQTT topic suffix. Duplicate names are not allowed.

**Display Name**\
The label shown in dashboards and reports. Defaults to the Datastream Name but can be changed independently. This is what end-users see.

**Virtual Pin**\
The Virtual Pin assigned in firmware (`V0`–`V255`). Must match the pin used in `BLYNK_WRITE(Vx)` and `Blynk.virtualWrite(Vx, ...)` calls.

**Color**\
A color used to identify the Datastream in lists and charts.

**Icon**\
An icon used to identify the Datastream.

**Data Type**\
See Data Types for the full reference. For Enumerable-specific settings, see Enumerable below.

**Min Value**\
The minimum allowed value. Any incoming value below this threshold is replaced with `Min`.

**Max Value**\
The maximum allowed value. Any incoming value above this threshold is replaced with `Max`.

**Decimals**\
Controls how many decimal places are shown in displays. Does not affect stored precision. Options: `#` · `#.#` · `#.##` · `#.###`.

**Default Value**\
The initial value used when a device first connects. The device can call `Blynk.sync(Vx)` on connect to receive this value and set its initial state.

```cpp
BLYNK_CONNECTED() {
  // On first connect, receives the configured Default Value
  Blynk.sync(V1);
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  // handle initial state
}
```

***

### Semantic Tags

Semantic tags tell Blynk what your data _means_, enabling smarter aggregations, dashboards, and automations.

**From presets** — Browse Blynk's library of standard semantic tags (e.g., `temperature`, `battery`, `RSSI`, `humidity`).

**New semantic tag** — Define a custom tag for your data type.

See [Semantic Tags](https://docs.blynk.io/en/blynk.console/templates/datastreams/semantic-tags) for the full reference.

***

### Units

Configure the measurement unit displayed with this Datastream's value.

**Unit** — Select from a searchable list of standard units (e.g., Celsius, mph, %, lux). The unit abbreviation appears alongside values in dashboards.

You can also create **custom units**. Custom units are shared across templates, dashboards, and sub-organizations. Note that Unit Conversion is not supported for custom units.

Unit conversion lets Blynk automatically display sensor values in a different unit than what your device reports — without changing the data your device sends or how it's stored.

For example, a device that reports temperature in °C can show values to users in °F. A flow sensor reporting in l/min can display readings in CFM. No firmware changes needed.

See Unit Conversion for configuration details.

***

### History

Controls how Blynk stores incoming values over time.

| Option                    | Storage behavior                                                                                                                                                    |
| ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Last Value**            | Stores only the most recent value. No historical chart data.                                                                                                        |
| **1 Minute AVG**          | Averages all values received within each 1-minute window. One data point per minute. Suitable for most sensors.                                                     |
| **High-Resolution (RAW)** | Stores every individual value without compression. If your device sends 10 readings per minute, all 10 are stored. Required for Custom Chart widgets with raw data. |

{% hint style="info" %}
High-Resolution (RAW) storage for **String** data type is available on the Enterprise plan only.
{% endhint %}

***

### Expiration

Defines what widgets show when a Datastream stops receiving updates.

**Invalidate after** — Enable the toggle and set a time window (e.g., `1 Hr`). If no new value arrives within that window, the Datastream value is replaced with the selected fallback.

**Then set to** — Choose what to display when the value expires:

| Option               | What's shown                              |
| -------------------- | ----------------------------------------- |
| **Blank**            | Shows a blank/empty state                 |
| **Default value**    | The Datastream's configured Default Value |
| **"No data" string** | Shows a "No data" label                   |
| **"Empty" string**   | Shows an empty string                     |
| **– (dash)**         | Shows a dash                              |

**Example use case:** A temperature sensor goes offline. After 1 hour of silence, the gauge widget shows "–" instead of the last (now stale) reading.

***

### Sync

Controls device synchronization behavior for this Datastream.

**Wait for confirmation from device** — When enabled and a user sends a value, Blynk waits for the device to confirm it received and applied the value. Set the maximum wait time in seconds. If the device doesn't confirm within that window, the Datastream value reverts to its previous state.

```cpp
BLYNK_WRITE(V1) {
  int value = param.asInt();
  if (value == 1) {
    if (openDoor()) {
      Blynk.virtualWrite(V1, 1); // Confirm success
    } else {
      Blynk.virtualWrite(V1, 0); // Confirm failure — value reverts to previous
    }
  }
}
```

**Sync with the latest server value on reconnect** — When the device reconnects after going offline, it requests the latest value from the server and applies it. Useful for controlling devices where the user may have changed state while the device was offline.

```cpp
BLYNK_CONNECTED() {
  Blynk.syncAll(); // Syncs all Datastreams with "sync on reconnect" enabled
}
```

Use `Blynk.sync(Vx)` to sync a specific pin regardless of the sync setting.

***

### Automations

Controls whether and how this Datastream appears in the Automations builder.

**Use as Condition** — Makes this Datastream available as a trigger in Automations. Users can create rules like "When Speed > 100 mph, send notification."

**Use as Action** — Makes this Datastream available as an action target. Users can create rules like "When motion detected, set V1 to 1."

**Appears As** — Controls how the Datastream is presented in the Automations UI:

| Option     | Description                                                     |
| ---------- | --------------------------------------------------------------- |
| **Value**  | Read-only value.                                                |
| **Switch** | On/Off toggle that maps to the Datastream's Min and Max values. |
| **Range**  | Numeric slider or input within Min/Max bounds.                  |
| **Text**   | Free-text string input.                                         |
| **Color**  | Color picker that maps to a hex/RGB value.                      |
| **State**  | Dropdown of named states (for Enumerable Datastreams).          |

{% hint style="info" %}
**Location** Datastreams are read-only in Automations — they can be used as Conditions only, not Actions.
{% endhint %}

***

### Visibility

Controls where this Datastream surfaces across the Blynk platform.

| Setting               | Default            | Description                                                                                                                             |
| --------------------- | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------- |
| **Show to end-users** | On                 | Makes the Datastream visible in dashboards, charts, automations, and reports for end-users. Disable to hide developer-only Datastreams. |
| **Custom charts**     | On                 | Allows this Datastream to be selected in Custom Chart widgets.                                                                          |
| **Show in Reports**   | On                 | Includes this Datastream in Data Reports.                                                                                               |
| **Web API**           | On _(coming soon)_ | Exposes this Datastream through the REST API.                                                                                           |

***

### Notes

Internal documentation field for developer notes.

Add notes about this Datastream's purpose, firmware behavior, or integration details. **Visible to developers only** — not shown to end-users.

***

### API Reference

Quick-access code snippets and endpoint references for this specific Datastream.

Provides ready-to-use examples across three interfaces:

* **C++** — Firmware code for reading and writing values via the Blynk library
* **HTTP** — REST API endpoints for reading and writing values
* **MQTT** — MQTT topic and payload format for this Datastream

For complete documentation, see the [firmware API reference](https://docs.blynk.io/en/blynk-library-firmware-api/virtual-pins).

***

### Enumerable Data Type Reference

The Enumerable data type maps integer keys received from a device to human-readable labels. Used for multi-state values like operating modes, alert levels, or device statuses.

**Incoming Values (key → label mapping)**

Define what each integer key means. The device always sends and receives integer values.

```
0 → "Off"
1 → "On"
2 → "Fault"
```

Each key can be assigned a color. This color is reflected in widgets that support color-by-state, such as the LED widget.

**Outcome Values**

Outcome labels are the string representations displayed in the UI. The device always communicates using the integer key — outcome strings are display-only and are not sent to the device.

**Fallback value**

The label shown when the device sends an integer key that isn't mapped.

**Firmware example:**

```cpp
// Send state to Blynk
Blynk.virtualWrite(V3, 1); // Displays "On" in the UI

// Receive state from Blynk
BLYNK_WRITE(V3) {
  int state = param.asInt();
  // state is 0, 1, or 2
}
```

***

### Location Data Type Reference

The Location data type stores a GPS coordinate pair. Used with Map widgets to show device position.

Values are two doubles: **longitude** and **latitude** sent as a comma-separated pair.

**Firmware example:**

```cpp
// Send GPS coordinates (longitude, latitude)
Blynk.virtualWrite(V3, 30.5234, 50.4501);
```

{% hint style="info" %}
Note the order: **longitude first, latitude second.** This is the opposite of the common "lat/lon" convention.
{% endhint %}
