# Datastreams

Datastreams are the foundation of how Blynk handles device data. Every value a device sends or receives — a sensor reading, a switch state, a GPS coordinate — flows through a Datastream.

Each Datastream maps to a **Virtual Pin** and defines how that data is typed, stored, displayed, and used across the platform: in dashboards, automations, and reports.

***

### Data Types

Each Datastream has a data type that determines how values are stored and validated.

| Data Type      | Range                                | Typical use                          |
| -------------- | ------------------------------------ | ------------------------------------ |
| **Integer**    | −2,147,483,648 to 2,147,483,647      | Switches, counters, status codes     |
| **Double**     | ±1.7976931348623157 × 10³⁰⁸          | Sensor readings, measurements        |
| **String**     | Up to 255 characters                 | Text labels, timestamps, messages    |
| **Enumerable** | Integer key mapped to display labels | State machines, multi-state controls |
| **Location**   | Longitude + latitude (two doubles)   | GPS coordinates                      |

{% hint style="warning" %}
If the device sends a value that doesn't match the configured data type, the server will ignore it. Out-of-range values are clamped to Min or Max.
{% endhint %}

{% hint style="info" %}
**Need to store static or semi-static device information?** Use [Device Metadata](https://docs.blynk.io/en/blynk.console/templates/metadata) instead. Metadata is better suited for values that rarely change — serial numbers, install locations, configuration parameters — and doesn't consume a Virtual Pin.
{% endhint %}

***

### Managing Datastreams

Open **Template Settings → Datastreams** to see all Datastreams defined for a template.

#### Filtering

Use the filter tabs to narrow the list by data type: **All · Integer · Double · String · Enum · Location**

#### Table columns

The table shows key properties at a glance. Default columns:

| Column                 | Description                                |
| ---------------------- | ------------------------------------------ |
| **Pin**                | Virtual Pin number (sortable)              |
| **Name**               | Datastream name                            |
| **Data type**          | Integer, Double, String, Enum, or Location |
| **Semantics**          | Assigned semantic tags                     |
| **Min / Max**          | Value bounds                               |
| **Default**            | Initial value                              |
| **Units**              | Display unit abbreviation                  |
| **Use in Automations** | Whether exposed as a Condition or Action   |

Use the **column management button** at the top-right of the table to add or remove columns. Additional columns available:

| Column                   | Description                               |
| ------------------------ | ----------------------------------------- |
| **ID**                   | Datastream ID                             |
| **Display Name**         | Name shown to end-users                   |
| **Color**                | Assigned color                            |
| **Notes**                | Notes field content                       |
| **Decimals**             | Display decimal places                    |
| **Appears As**           | How it appears in Automations             |
| **Automation Condition** | Whether exposed as a Condition            |
| **Automation Action**    | Whether exposed as an Action              |
| **Data History**         | Storage mode (Last Value, 1 Min AVG, RAW) |

#### Browse Presets

Click **Browse Presets** to add a pre-configured Datastream from Blynk's library. Presets include common IoT datapoints (temperature, humidity, battery, RSSI, etc.) with sensible defaults already filled in.

***

### Creating a Datastream

Click **New Datastream**. Enter a name or pick from the preset suggestions, then configure the settings in the panel that opens.

See [Datastream Settings](datastreams-common-settings.md) for a full reference of all configuration options.

***

### Firmware Quick Reference

#### Reading a value sent from the app

```cpp
BLYNK_WRITE(V1) {
  int value = param.asInt();      // Integer
  float value = param.asFloat();  // Double
  String value = param.asStr();   // String
}
```

#### Sending a value to the app

```cpp
Blynk.virtualWrite(V1, value);
```

#### Syncing on reconnect

```cpp
BLYNK_CONNECTED() {
  Blynk.syncAll();   // Sync all Datastreams with "sync on reconnect" enabled
  // OR
  Blynk.sync(V1);   // Sync a specific pin (ignores sync setting)
}
```
