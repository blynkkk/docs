# Where Semantic Tags Are Used

Once a Semantic Tag is assigned to a datastream in a Template, Blynk uses that
tag across several product areas to provide smarter default behaviors —
grouping, filtering, column management, and pre-populated panels — without
requiring manual configuration per device.

---

### Automations

<figure><img src="../../.gitbook/assets/automation-control-segment-semantic-group.png" alt=""><figcaption><p>Use Semantic Tags in Automations</p></figcaption></figure>

When building an Automation with a **Control Segment** action, you can choose
which device properties to include. The property picker offers three views:

- **Property Group** — groups datastreams by their semantic tag combination,
  enabling cross-product selections that work across different device types.
- **Property** — lists datastreams by their names, merged across templates.
- **Virtual Pin** — lists datastreams by their virtual pin, merged across
  templates (available to developers only).

{% hint style="info" %}
**Note:** Semantic grouping is only relevant to **Control Segment** actions —
it is not used in Automation conditions.
{% endhint %}

**Behavior when datastreams change:**

| Scenario | What happens |
|---|---|
| A new datastream with the same semantic tags is added to the template | It is **not** automatically included in existing automations. Open the automation and re-add the relevant Property Group — the new datastream will then be merged into the action if it shares the same automation type, min/max, units, and decimals. |
| Two datastreams share the same automation type settings | They are grouped into a single automation action. |

---

### Dashboard Widgets

<figure><img src="../../.gitbook/assets/dashboard-widget-settings-semantic-group.png" alt=""><figcaption><p>Use Semantic Tags in Dashboard Widgets</p></figcaption></figure>

When configuring a dashboard widget, the datastream picker includes a
**Property Group (Semantics)** view. This lets you bind the widget to a
semantic meaning rather than a specific virtual pin — so the same widget
configuration works correctly across all devices in an organization, regardless
of which exact pin holds the relevant data on each device.

---

### Column Management (Devices List)

<figure><img src="../../.gitbook/assets/column-management-semantic-groups.png" alt=""><figcaption><p>Use Semantic Tags in Column Management</p></figcaption></figure>

In the **Devices List**, column management lets you add columns driven by
semantic tags. When adding a new column, you can select:

- **Datastream** — binds the column to a specific datastream by name.
- **Semantic Group** — binds the column to a semantic tag combination, so
  the correct datastream is resolved automatically for each device, even
  if different devices use different datastream names for the same measurement.

{% hint style="info" %}
**Note:** Each Semantic Group column can display data from only **one
datastream per template**. This is why each datastream's tag combination must
be unique — a column bound to a Semantic Group must be able to resolve a
single, unambiguous datastream for every device.
{% endhint %}

---

### Developer Tools

<figure><img src="../../.gitbook/assets/developer-tools-semantic-tags.png" alt=""><figcaption><p>Use Semantic Tags for pre-defined device metrics in Developer Tools</p></figcaption></figure>

The **Developer Tools** section of a device automatically surfaces datastreams
tagged with specific System Tags — no additional configuration is needed:

| Developer Tools panel | System Tag required |
|---|---|
| Uptime | Uptime |
| Free Memory | Free Memory |
| Mode (Display) | Mode Display |
| Battery | Battery Level |
| MAC Address (Hardware Info) | MAC Address |

If the template's datastreams include these System Tags, the corresponding
panels are populated automatically. If the tag is absent, the panel is hidden.

---

### Device Filters (Dashboard Widgets)

<figure><img src="../../.gitbook/assets/dashboard-widget-filter-by-semantic-group.png" alt=""><figcaption><p>Filter by Semantic Tags in Dashboard Widgets</p></figcaption></figure>

In dashboard widgets that support device-level filtering, the
**Filter by Datastream Value** option uses a multi-level cascader picker:

1. **Level 1** — Select a datastream category or semantic group.
2. **Level 2** — Narrow by semantic tag.
3. **Level 3** — Select the specific datastream or tag variant.
4. **Level 4** — Set the value condition (operator + threshold).

Using semantic tags in filters means the filter applies correctly across all
device types in an organization — even when different templates use different
virtual pins for the same measurement.

---

### Related

- [Semantic Tags — Overview & Reference](https://docs.blynk.io/en/blynk.console/templates/datastreams/semantic-tags)
- [Automations](https://docs.blynk.io/en/concepts/automations)
- [Dashboard Widgets](https://docs.blynk.io/en/blynk.console/dashboards)
- [Devices List](https://docs.blynk.io/en/blynk.console/devices)
- [Developer Tools](https://docs.blynk.io/en/blynk.console/devices/developer-tools)
