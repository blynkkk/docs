# Unit Conversion

Unit conversion lets Blynk automatically display sensor values in a different unit than what your device reports — without changing the data your device sends or how it's stored.

For example, a device that reports temperature in _°C_ can show values to users in _°F._ A flow sensor reporting in _l/min_ can display readings in _CFM_. No firmware changes needed.

***

### How it works

Each datastream has a **base unit** — the unit your device sends. When conversion is enabled, Blynk shows that value in the user's preferred unit using one of two methods:

* **Formula** — Blynk applies a conversion formula to the value (for example, °C → °F). This is the default.
* **Paired datastream** — if the device already streams the same measurement in two units on separate pins (for example, V1 = °C, V2 = °F), Blynk reads the matching datastream directly instead of calculating.

{% hint style="info" %}
Note: Conversion changes only how values are displayed. The raw value stored on server is always the value your device sent, so historical data, the API, and exported reports remain in the device's original (base) unit.
{% endhint %}

### Enabling conversion per datastream

Conversion can be turned off for an individual datastream in the Units tab of Datastream Settings. The toggle appears only when the selected unit is convertible, and is on by default. When off, that datastream always displays in its base unit regardless of the user's unit system.

<figure><img src="../../../.gitbook/assets/1_unit_conversion_settings.png" alt=""><figcaption></figcaption></figure>

### Unit conversion levels

Unit preferences can be set at multiple levels: per user, per device, per organization, or per template — with more specific settings taking priority.

| Priority                                             | Level                                    | Set by       | Purpose                                                      |
| ---------------------------------------------------- | ---------------------------------------- | ------------ | ------------------------------------------------------------ |
| 1 (highest, if added will override all other levels) | Unit Conversion Switch (device metadata) | Manufacturer | Keep the app in sync with a unit toggle on the device itself |
| 2                                                    | User preference                          | End user     | "I prefer Imperial"                                          |
| 3                                                    | Organization                             | Org admin    | Company-wide default                                         |
| 4 (lowest)                                           | Template default                         | Manufacturer | The unit a product ships with                                |

### Smart Unit Scaling

Beyond converting between systems, Blynk can automatically scale a value to the most readable unit within the same system — showing `2.5 kg` instead of `2500 g`, or `45 kW` instead of `45000 W`. Some quantities scale as a single decimal value; others that read more naturally in two parts (time, imperial length and mass) display as a composite, like `2 days 19 hr` or `5 ft 8 in`.

Smart scaling is a display-only convenience and never changes the stored value. It can be toggled on the Units tab of Datastream Settings. The toggle appears only when the selected unit supports smart scaling, and is **enabled** by default.

<figure><img src="../../../.gitbook/assets/2_unit_conversion_smart_scaling.png" alt=""><figcaption></figcaption></figure>
