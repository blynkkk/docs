# HTML Widget Developer Guide

HTML lets you embed a fully custom HTML + JavaScript page inside the Blynk dashboard as a first-class widget. The page runs in a Blynk WebView that exposes a native bridge (`BlynkBridge`) so your HTML can read datastream values, push values back to the server, react to real-time updates, pick up app theme colours, query device metadata, fetch historical datastream data, and navigate between dashboard pages - all without any server-side code.

***

### How It Works

```
HTML <script>                    Blynk WebView bridge
  BlynkBridge.getValue(index)  ─► read current value of a single datastream (0-based)
  BlynkBridge.getValues()      ─► read current values of all assigned datastreams
                                   On Web, every resolved value object always carries the FULL
                                   field set { index, value, lastUpdated, type, label, pinType, color,
                                               min, max, unit, suffix, decimalFormat,
                                               mappings, enumFallbackValue }
                                   — fields that don't apply to the stream's type are present with
                                   default values (null / '' / []), not omitted.
  BlynkBridge.sendValue()      ─► write a value to a datastream
  BlynkBridge.sendError()      ─► display an error toast notification in the Dashboard
  BlynkBridge.getTheme()       ─► theme colors and optional font-family names for current mode
  BlynkBridge.getDeviceInfo()  ─► device name, status, and metadata
  BlynkBridge.isExternalRequestsAllowed() ─► boolean — whether outbound HTTP/fetch calls are permitted
  BlynkBridge.isRangePickerSupported()   ─► boolean — whether RANGE_PICKER period is available
  BlynkBridge.getHistoricalData(options) ─► historical datastream values for a given period
                                            resolves with { streams: [{ index, granularity, values: [{x,y}] }] }
                                            granularity is null when sourceType was RAW_DATA
  BlynkBridge.isPageActionsSupported()   ─► boolean — whether page navigation calls are available

  // Real-time updates — register once after constructing the bridge:
  bridge.setCallbacks({
    onValueUpdated: ({ index, value, ... }) => { /* update your UI */ },
    onThemeUpdated: (theme) => { /* re-apply theme on light/dark switch */ },
    onError: (message) => { /* handle platform/validation errors */ }
  });
  // The Blynk WebView calls these handlers whenever the server pushes
  // new data, the app theme changes, or an error occurs.
```

The `BlynkBridge` JavaScript class (injected before your page's own scripts) wraps all platform calls and keeps things consistent.

***

### Minimal HTML Skeleton

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport"
        content="width=device-width, initial-scale=1.0, maximum-scale=1.0,
                 user-scalable=no, viewport-fit=cover">

  <title>My Widget</title>
  <style>/* your styles */</style>
</head>
<body>
  <!-- your markup -->

<script>
(function () {
  'use strict';

  // ① Create bridge (falls back gracefully in browser / editor)
  const bridge = (typeof BlynkBridge !== 'undefined')
    ? new BlynkBridge({ logEnabled: true, isOnErrorEnabled: true })
    : {
        isBridgeAvailable: false,
        sendValue: () => {}, sendError: () => {}, log: () => {},
        setCallbacks: () => {}, setOnErrorEnabled: () => {}, setLogging: () => {},
        isExternalRequestsAllowed: () => false,
        getValue:               () => Promise.reject('no bridge'),
        getValues:              () => Promise.reject('no bridge'),
        getDeviceInfo:          () => Promise.reject('no bridge'),
        getTheme:               () => Promise.reject('no bridge'),
        isRangePickerSupported: () => false,
        getHistoricalData:      () => Promise.reject('no bridge'),
        isPageActionsSupported: () => false,
        showPage:               () => {},
        closePage:              () => {},
        closeAllPages:          () => {},
      };

  // ② Register callbacks
  bridge.setCallbacks({
    onValueUpdated: ({ index, value, type, label, pinType,
                       min, max, unit, suffix, decimalFormat,
                       mappings, enumFallbackValue }) => {
      // called whenever the server pushes a new value for one of the datastreams
      // — see "Reading Values" section for full field descriptions per type
    },
    onError: (message) => {
      // called when the platform reports an error (validation failures, timeouts, etc.)
      bridge.log('onError: ' + message);
    }
  });

  // ③ Boot
  async function init() {
    const theme = await bridge.getTheme().catch(() => null);
    if (theme) applyTheme(theme);

    const values = await bridge.getValues().catch(() => []);
    // render your UI
  }

  init();
})();
</script>
</body>
</html>
```

***

### BlynkBridge JavaScript API

The `BlynkBridge` class is **injected by the Blynk WebView before your page scripts run**. Always guard against it being absent (browser / editor preview):

```js
const bridge = (typeof BlynkBridge !== 'undefined')
  ? new BlynkBridge()
  : { /* stub */ };
```

#### Initialization

```js
const bridge = new BlynkBridge({
  logEnabled:       true,  // default true — forwards log() calls to the Blynk platform logger
  isOnErrorEnabled: true   // default true — enables the onError callback and sendError()
});
```

Constructing `BlynkBridge` also exposes:

* `window.blynkWidgetUpdate(json)` — called by the Blynk WebView with real-time push payloads
* `window.blynkOnError(message)` — called by the Blynk WebView when a platform error occurs

#### Checking Bridge Availability

```js
bridge.isBridgeAvailable()  // → boolean
```

Returns `true` when running inside the Blynk WebView. Returns `false` in a browser or during the HTML editor preview.

***

#### Checking External Request Permission

```js
bridge.isExternalRequestsAllowed()  // → boolean
```

Returns `true` when the host platform permits the widget to make outbound HTTP/HTTPS requests (e.g. calling the Blynk Platform REST API or any third-party endpoint) directly from widget JavaScript.

> **Important:** Even when this returns `true`, individual requests may still be blocked by CORS policy or other network-level restrictions. Always handle `fetch()` rejections gracefully.

Recommended guard before making any external network request:

```js
if (bridge.isExternalRequestsAllowed()) {
  fetch('https://api.example.com/data')
    .then(r => r.json())
    .then(data => renderData(data))
    .catch(err => bridge.log('Fetch failed: ' + err));
} else {
  bridge.log('External requests not allowed on this platform');
}
```

***

#### Reading Values

**`getValue(index)` — single datastream**

```js
bridge.getValue(0)  // → Promise<ValueObject>
```

`index` is 0-based. Rejects when the index is missing (`Error: 'getValue() has no index'`) or refers to a datastream that isn't configured on the widget (`` Error: `Datastream index ${index} is not configured` `` ).

**All fields below are always present on the resolved object**, even ones that don't apply to the current stream's type — in that case they default to `null`, `''`, or `[]` rather than being left out. Use the `type` field to decide which ones are meaningful:

| Field               | Type       | Description                                                        |
| ------------------- | ---------- | ------------------------------------------------------------------ |
| `index`             | `number`   | 0-based datastream index (mirrors the position in widget settings) |
| `value`             | `string`   | Current datastream value as a string                               |
| `lastUpdated`       | \`number   | null\`                                                             |
| `type`              | `string`   | Datastream type:`"INT"`, `"DOUBLE"`, `"STRING"`, `"ENUM"`, …       |
| `label`             | `string`   | Datastream label if configured, otherwise`''`                      |
| `pinType`           | `string`   | Pin type name, e.g.`"VIRTUAL"`, or `''`                            |
| `color`             | `string`   | Datastream accent color configured in widget settings, or`''`      |
| `min`               | \`number   | null\`                                                             |
| `max`               | \`number   | null\`                                                             |
| `unit`              | `string`   | Measurement unit name, or`''`                                      |
| `suffix`            | `string`   | Unit suffix for display, or`''`                                    |
| `decimalFormat`     | `string`   | Decimal format pattern, e.g.`"#.##"`, or `''`                      |
| `mappings`          | `string[]` | Enum option labels;`[]` for non-enum streams                       |
| `enumFallbackValue` | \`string   | null\`                                                             |

Example resolved object for an integer temperature datastream:

```js
{
  index:             0,
  value:             "23",
  lastUpdated:       1737654321000,
  type:              "INT",
  label:             "Temperature",
  pinType:           "VIRTUAL",
  color:             "#22c55e",
  min:               -40,
  max:               85,
  unit:              "Celsius",
  suffix:            "°C",
  decimalFormat:     "",
  mappings:          [],
  enumFallbackValue: null
}
```

Example for a double speed datastream:

```js
{
  index:             1,
  value:             "1.25",
  lastUpdated:       1737654321500,
  type:              "DOUBLE",
  label:             "Speed",
  pinType:           "VIRTUAL",
  color:             "#3b82f6",
  min:               0.0,
  max:               10.0,
  unit:              "Meters per second",
  suffix:            "m/s",
  decimalFormat:     "#.##",
  mappings:          [],
  enumFallbackValue: null
}
```

Usage pattern — rendering a human-readable value:

```js
bridge.getValue(0).then(v => {
  const num = parseFloat(v.value);
  const display = v.decimalFormat
    ? num.toFixed(v.decimalFormat.split('.')[1]?.length ?? 0)
    : String(num);
  valueEl.textContent = v.suffix ? `${display} ${v.suffix}` : display;
});
```

***

**Enum value model (`"ENUM"`)**

For `"ENUM"` streams, `mappings` and `enumFallbackValue` are the fields that matter:

| Field               | Type       | Description                                                                                  |
| ------------------- | ---------- | -------------------------------------------------------------------------------------------- |
| `mappings`          | `string[]` | Array of option labels indexed from`0`. The raw numeric `value` is an index into this array. |
| `enumFallbackValue` | \`string   | null\`                                                                                       |

The `value` field holds the **numeric index** of the currently selected option as a string (`"0"`, `"1"`, …). Use `mappings[parseInt(v.value)]` to get the human-readable label.

Example resolved object for a mode selector with three options:

```js
{
  index:              0,
  value:              "1",
  lastUpdated:        1737654321000,
  type:               "ENUM",
  label:              "Mode",
  pinType:            "VIRTUAL",
  color:              "#a855f7",
  min:                null,
  max:                null,
  unit:               "",
  suffix:             "",
  decimalFormat:      "",
  mappings:           ["Off", "Eco", "Turbo"],
  enumFallbackValue:  "Unknown"   // null if not configured
}
```

Usage pattern — rendering the selected label:

```js
bridge.getValue(0).then(v => {
  if (v.type === 'ENUM') {
    const idx = parseInt(v.value, 10);
    const label = v.mappings?.[idx] ?? v.enumFallbackValue ?? v.value;
    modeEl.textContent = label;
  }
});
```

Usage pattern — building a dropdown from enum options:

```js
bridge.getValue(0).then(v => {
  if (v.type !== 'ENUM') return;
  const currentIdx = parseInt(v.value, 10);
  v.mappings.forEach((optLabel, idx) => {
    const opt = document.createElement('option');
    opt.value  = String(idx);
    opt.text   = optLabel;
    opt.selected = idx === currentIdx;
    selectEl.appendChild(opt);
  });
  selectEl.addEventListener('change', () => {
    bridge.sendValue(0, selectEl.value);
  });
});
```

***

**`getValues()` — all datastreams**

```js
bridge.getValues()  // → Promise<ValueObject[]>
```

Returns an array of `ValueObject` (same shape as above), one per assigned datastream, in the same order as the datastreams appear in widget settings. The `index` field on each object reflects its 0-based position in that ordering. The array length equals the number of assigned datastreams. An empty array means no datastreams are configured.

Usage pattern — handling mixed stream types:

```js
bridge.getValues().then(values => {
  values.forEach(v => {
    if (v.type === 'ENUM') {
      const idx = parseInt(v.value, 10);
      renderEnum(v.index, v.mappings?.[idx] ?? v.value);
    } else {
      const num = parseFloat(v.value);
      renderNumeric(v.index, num, v.suffix, v.decimalFormat);
    }
  });
});
```

***

#### Sending Values

```js
bridge.sendValue(index, value)
```

| Parameter | Type     | Description              |
| --------- | -------- | ------------------------ |
| `index`   | `number` | 0-based datastream index |
| `value`   | \`string | number\`                 |

Example:

```js
bridge.sendValue(0, '23.5');
bridge.sendValue(1, 'ON');
```

`sendValue` is fire-and-forget — it doesn't return a Promise. If `index` refers to a datastream that isn't configured on the widget, you'll see `` `Datastream index ${index} is not configured` `` come through `onError` (or as a toast, if `sendError`-driven UI is enabled) instead of a thrown exception.

***

#### Error Handling

**`sendError(message)` — push an error toast to the Dashboard**

```js
bridge.sendError(message)
```

Displays `message` as an error toast notification in the Blynk Dashboard UI. Use this to surface widget errors to the user (e.g. a failed external fetch, invalid input, or unsupported configuration).

| Parameter | Type     | Description                        |
| --------- | -------- | ---------------------------------- |
| `message` | `string` | Non-empty error message to display |

* Does nothing if `message` is empty or not a string.
* Does nothing when `isOnErrorEnabled` is `false`.
* Does nothing when the bridge is not available.

```js
if (bridge.isExternalRequestsAllowed()) {
  fetch('https://api.example.com/data')
    .then(r => r.json())
    .then(renderData)
    .catch(err => bridge.sendError('Data fetch failed: ' + err));
} else {
  bridge.sendError('External requests are not allowed on this platform');
}
```

***

**`setOnErrorEnabled(enabled)` — enable/disable error delivery**

```js
bridge.setOnErrorEnabled(false)  // suppress both sendError() and the onError callback
bridge.setOnErrorEnabled(true)   // re-enable (default)
```

When `false`:

* `sendError()` calls are silently dropped.
* The `onError` callback registered via `setCallbacks` is not invoked.

***

**`onError` callback — receive platform errors**

Register via `setCallbacks`:

```js
bridge.setCallbacks({
  onError: (message) => {
    // Called by the platform for validation failures, timeouts, or other
    // internal errors (e.g. a getHistoricalData timeout, or writing/reading
    // an index that isn't configured on the widget).
    // Only invoked when isOnErrorEnabled is true (the default).
    showErrorBanner(message);
  }
});
```

The platform calls `window.blynkOnError(message)` directly; `BlynkBridge` forwards it to your registered handler.

**Platform behaviour:**

| Platform            | `sendError` | `onError` callback  |
| ------------------- | ----------- | ------------------- |
| Web (Blynk Console) | No-op       | Fires via JS bridge |

***

#### Real-time Updates

```js
bridge.setCallbacks({
  onValueUpdated: ({ index, value, lastUpdated, type, label, pinType, color,
                     min, max, unit, suffix, decimalFormat,
                     mappings, enumFallbackValue }) => {
    // index              — 0-based datastream index
    // value              — new value as a string
    // lastUpdated        — Unix timestamp (ms) of this push, or null
    // type               — datastream type: 'INT', 'DOUBLE', 'STRING', 'ENUM', …
    // label / pinType    — stream label and pin type name ('' when not set)
    // color              — datastream accent color from widget settings ('' when not set)
    //
    // The full field set above is always present, regardless of `type` — fields
    // that don't apply to the current stream are included with default values:
    //   min / max        — range bounds (null for non-numeric streams)
    //   unit             — measurement unit name string ('' when not set)
    //   suffix           — unit suffix for display ('' when not set)
    //   decimalFormat    — format pattern, e.g. '#.##' ('' when not set)
    //   mappings         — string[] of option labels ([] for non-enum streams);
    //                      value is the index string into this array for ENUM streams
    //   enumFallbackValue— label used when value index falls outside mappings (null for non-enum streams)
  },

  onThemeUpdated: (theme) => {
    // Called whenever the dashboard theme changes (light/dark toggle, org branding
    // change). theme has the same shape getTheme() resolves with — re-apply it to
    // your CSS custom properties so the widget updates live without a reload.
  },

  onError: (message) => {
    // Called when the platform reports an error — same trigger as window.blynkOnError().
    // Fires only when isOnErrorEnabled is true (the default).
    // message: string — human-readable error description
  },

  onHistoricalDataUpdated: (data) => {
    // Called automatically whenever the user adjusts the dashboard's global time-range
    // picker (only fires when subscribed via getHistoricalData({ period: 'RANGE_PICKER' })
    // — see "RANGE_PICKER period" below).
    // data: HistoricalDataResult — same shape as getHistoricalData() resolves with:
    //   { streams: [{ index, granularity, values: [{ x, y }, ...] }, ...] }
    //   granularity is null when sourceType was RAW_DATA
  }
});
```

`BlynkBridge` dispatches new values, theme changes, and range-picker updates to `onValueUpdated`, `onThemeUpdated`, and `onHistoricalDataUpdated` respectively, as they happen.

***

#### Device Info

```js
bridge.getDeviceInfo()  // → Promise<DeviceInfo>
```

On Web, this **never resolves with a bare `null`.**

* It **rejects** when the bridge isn't available, or after a 10-second timeout (`Error: 'Device info request timeout (10s)'`).
* Otherwise it **resolves** with an object — when there's no device linked to the widget, the individual fields fall back to `null`/`''` instead.

```ts
{
  id:             number | null,   // internal device ID; null if no device is linked
  orgId:          number | null,   // organisation ID; null if no device is linked
  name:           string,          // device display name; '' if no device is linked
  status:         string,          // 'ONLINE' | 'OFFLINE' | a custom status string; '' if unset
  lastReportedAt: number | null    // Unix timestamp (ms) of last server activity; null if unknown
}
```

**Field notes:**

| Field            | Type     | Notes                                                               |
| ---------------- | -------- | ------------------------------------------------------------------- |
| `id`             | \`number | null\`                                                              |
| `orgId`          | \`number | null\`                                                              |
| `name`           | `string` | Device display name;`''` when there's no linked device              |
| `status`         | `string` | `'ONLINE'`, `'OFFLINE'`, or a custom status string; `''` when unset |
| `lastReportedAt` | \`number | null\`                                                              |

Example — showing an online/offline badge:

```js
bridge.getDeviceInfo().then(info => {
  if (!info.id) return; // no device linked to this widget

  nameEl.textContent = info.name;
  badge.style.display = 'flex';

  if (info.status === 'ONLINE') {
    dot.className = 'dot online';
  } else if (info.status === 'OFFLINE') {
    dot.className = 'dot offline';
  } else if (info.status) {
    // Custom status string
    dot.className = 'dot custom';
  }
});
```

Example — safe guard pattern (recommended):

```js
bridge.getDeviceInfo()
  .then(info => {
    if (!info.id) {
      showNoDevice();
      return;
    }
    renderDevice(info);
  })
  .catch(() => showNoDevice());
```

***

#### App Theme

```js
bridge.getTheme()  // → Promise<Theme>
```

On Web, `getTheme()` **rejects** (does not resolve `null`) when the bridge isn't available (`Error: 'Blynk bridge is not available'`) or after a 10-second response timeout (`Error: 'Theme request timeout (10s)'`). Otherwise it resolves with an object whose color fields are CSS hex strings **already resolved for the current light/dark mode** — no `prefers-color-scheme` adaptation needed — plus optional font-family strings supplied by the host app:

**Color fields**

| Field         | Maps to attribute       | Typical use                          |
| ------------- | ----------------------- | ------------------------------------ |
| `brand`       | `blynkBrandColor6`      | Primary accent, buttons, focus rings |
| `primary`     | `blynkPrimaryColor6`    | Secondary accent                     |
| `positive`    | `blynkPositiveColor6`   | Success / online status              |
| `warning`     | `blynkWarningColor6`    | Warning badges                       |
| `critical`    | `blynkCriticalColor6`   | Errors / offline status              |
| `background`  | `blynkBackgroundColor`  | Page / widget background             |
| `textPrimary` | `blynkTextPrimaryColor` | Body text                            |
| `onPrimary`   | `blynkOnPrimaryColor`   | Text on primary-colored surfaces     |
| `onBrand`     | `blynkOnBrandColor`     | Text on brand-colored surfaces       |
| `neutral`     | `blynkNeutralColor9`    | Muted text, borders                  |

**Font fields**

These are `string | null` — present only when the host app has configured custom typography. Use them as CSS `font-family` values; keep a reasonable system-font fallback for when they are absent.

| Field              | Typical use                         |
| ------------------ | ----------------------------------- |
| `primaryFont`      | Body text and general labels        |
| `secondaryFont`    | Sub-labels, captions, helper text   |
| `buttonsFont`      | Button and interactive-element text |
| `widgetValuesFont` | Numeric / data-value display        |

Custom theme fonts (`primaryFont`, `secondaryFont`, `buttonsFont`, `widgetValuesFont`) render correctly inside your widget automatically — you don't need to load or declare your own `@font-face` rules for them.

**Recommended pattern**

Apply all theme properties as CSS custom properties so the whole page updates atomically:

```js
bridge.getTheme().then(theme => {
  if (!theme) return;
  const r = document.documentElement.style;

  // Colors
  r.setProperty('--accent',        theme.brand);
  r.setProperty('--accent-ghost',  theme.brand + '26');   // 15 % opacity
  r.setProperty('--bg',            theme.background);
  r.setProperty('--text',          theme.textPrimary);
  r.setProperty('--color-online',  theme.positive);
  r.setProperty('--color-offline', theme.critical);
  r.setProperty('--color-warning', theme.warning);
  r.setProperty('--color-neutral', theme.neutral);

  // Fonts (only override when provided by the host app)
  if (theme.primaryFont)      r.setProperty('--font-primary',       theme.primaryFont);
  if (theme.secondaryFont)    r.setProperty('--font-secondary',     theme.secondaryFont);
  if (theme.buttonsFont)      r.setProperty('--font-buttons',       theme.buttonsFont);
  if (theme.widgetValuesFont) r.setProperty('--font-widget-values', theme.widgetValuesFont);
});
```

And reference them in your CSS:

```css
:root {
  /* Color fallbacks (overridden by getTheme()) */
  --bg:            #f7f7f8;
  --text:          #111114;
  --accent:        #22c55e;

  /* Font fallbacks (overridden by getTheme() when the host app supplies custom fonts) */
  --font-primary:       system-ui, sans-serif;
  --font-secondary:     system-ui, sans-serif;
  --font-buttons:       system-ui, sans-serif;
  --font-widget-values: system-ui, monospace;
}

body        { font-family: var(--font-primary); }
.value      { font-family: var(--font-widget-values); }
button      { font-family: var(--font-buttons); }
.sub-label  { font-family: var(--font-secondary); }
```

> **Note:** Always keep CSS fallback values in `:root` so the widget looks correct in the browser/editor before `getTheme()` resolves.

***

#### Historical Data

**Checking Range Picker Support**

```js
bridge.isRangePickerSupported()  // → boolean
```

Returns `true` when the host platform supports the `RANGE_PICKER` period mode (an interactive date-range picker driven by the native UI). |

***

**`getHistoricalData(options)`**

```js
bridge.getHistoricalData(options)  // → Promise<HistoricalDataMap>
```

Fetches historical datastream values for the widget's assigned datastreams.

**Parameters**

| Parameter                          | Type     | Required    | Description                                                                                                                                                                                                                                                                                                               |
| ---------------------------------- | -------- | ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `options`                          | `object` | yes         | Request options object                                                                                                                                                                                                                                                                                                    |
| `options.period`                   | `string` | yes         | One of:`'ONE_HOUR'`, `'SIX_HOURS'`, `'DAY'`, `'WEEK'`, `'MONTH'`, `'THREE_MONTHS'`, `'SIX_MONTHS'`, `'ONE_YEAR'`, `'CUSTOM'`                                                                                                                                                                                              |
| `options.from`                     | `number` | CUSTOM only | Start of the custom range — Unix timestamp in**milliseconds**                                                                                                                                                                                                                                                             |
| `options.to`                       | `number` | CUSTOM only | End of the custom range — Unix timestamp in**milliseconds**. The range `to - from` must not exceed 365 days.                                                                                                                                                                                                              |
| `options.offset`                   | `number` | no          | Number of data points to**skip** from the start of the result. Only meaningful with `sourceType: 'RAW_DATA'` (which can return a very large number of points). Use it to paginate: fetch with `offset: 0`, then increment by the number of points received. Must be a non-negative integer; defaults to `0` when omitted. |
| `options.dataStreams`              | `array`  | yes         | Non-empty array of datastream descriptors                                                                                                                                                                                                                                                                                 |
| `options.dataStreams[].index`      | `number` | yes         | **0-based** datastream index (must be within the number of datastreams configured in widget settings)                                                                                                                                                                                                                     |
| `options.dataStreams[].sourceType` | `string` | yes         | Aggregation function — one of:`'RAW_DATA'`, `'MIN'`, `'MAX'`, `'AVG'`, `'SUM'`, `'COUNT'`                                                                                                                                                                                                                                 |

**`sourceType` values:**

| Value      | Description                                                                                                |
| ---------- | ---------------------------------------------------------------------------------------------------------- |
| `RAW_DATA` | No aggregation — individual raw data points.`granularity` is **`null`** in the response for these streams. |
| `MIN`      | Minimum value per time bucket                                                                              |
| `MAX`      | Maximum value per time bucket                                                                              |
| `AVG`      | Average value per time bucket                                                                              |
| `SUM`      | Sum of values per time bucket                                                                              |
| `COUNT`    | Number of data points per time bucket                                                                      |

**Return value**

Resolves with a `HistoricalDataResult` object containing a `streams` array:

```ts
{
  streams: Array<{
    index:       number,   // 0-based datastream index in the widget's stream list
    granularity: string | null,   // time-bucket size chosen by the server — one of:
                           //   'MINUTE' | 'FIFTEEN_MINUTES' | 'HOURLY' 
                           //   | 'DAILY' | 'WEEKLY' | 'MONTHLY'
                           // null when sourceType was RAW_DATA (individual raw points,
                           //   no time-bucket aggregation)
    values: Array<{
      x: number,           // Unix timestamp in milliseconds
      y: number            // the value at this point — an aggregated value per time bucket
                           // for AVG/MIN/MAX/SUM/COUNT sourceTypes, or the raw recorded
                           // value at that exact timestamp for RAW_DATA
    }>
  }>
}
```

> **Note on `granularity`:** The server automatically picks the appropriate bucket size based on the requested period and `sourceType`. `RAW_DATA` requests return individual raw points and the `granularity` field is **`null`** for those streams. Aggregated source types (`AVG`, `MIN`, `MAX`, `SUM`, `COUNT`) use time-bucket aggregation and always return a non-null `granularity` string. Always null-check `stream.granularity` before displaying or comparing it.

**Validation rules**

The following conditions are checked **before** the native call is made; the Promise is rejected immediately if any fail:

**Period validation:**

| Condition                                                      | Error message                                                                                                  |
| -------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------- |
| `options` is absent or `options.period` is `null`/`undefined`  | `"'period' is required"`                                                                                       |
| `period` is not in the supported list                          | `"'period' must be one of: ONE_HOUR, SIX_HOURS, DAY, WEEK, MONTH, THREE_MONTHS, SIX_MONTHS, ONE_YEAR, CUSTOM"` |
| `period === 'CUSTOM'` and `from` or `to` is `null`/`undefined` | `"CUSTOM period requires 'from' and 'to' timestamps"`                                                          |
| `from` or `to` is not a finite number (`NaN`, `Infinity`)      | `"'from' and 'to' must be finite numbers"`                                                                     |
| `from > to`                                                    | `"'from' must be less than or equal to 'to'"`                                                                  |
| `to - from` exceeds 365 days                                   | `"'to' - 'from' must not exceed one year (365 days)"`                                                          |

**`offset` validation:**

| Condition                                                      | Error message                               |
| -------------------------------------------------------------- | ------------------------------------------- |
| `options.offset` is provided but is not a non-negative integer | `"'offset' must be a non-negative integer"` |

**`dataStreams` validation:**

| Condition                                                  | Error message                                                                     |
| ---------------------------------------------------------- | --------------------------------------------------------------------------------- |
| `options.dataStreams` is not an array                      | `"'dataStreams' must be an array"`                                                |
| `dataStreams[N]` is not an object                          | `'dataStreams[N] must be an object'`                                              |
| `dataStreams[N].index` is missing or non-numeric           | `'dataStreams[N].index must be a number'`                                         |
| `dataStreams[N].sourceType` is not one of the valid values | `'dataStreams[N].sourceType must be one of: RAW_DATA, MIN, MAX, AVG, SUM, COUNT'` |

**Out-of-range `dataStreams[].index` on Web:** unlike `getValue`/`sendValue`, an out-of-range index here does **not** produce an error. If _every_ entry in `dataStreams` is out of range, the whole call rejects with `Error: 'No valid datastream indexes'`. If only _some_ entries are invalid, the call still resolves — just without streams for the invalid indexes, with no error at all. Validate indexes yourself against the count from `getValues()` if you need to detect this case.

**Timeout on Web:** requests time out after **30 seconds**, rejecting with `Error: 'Historical data request timeout (30s)'`.

**Examples**

```js
// Named period with datastreams and aggregation
bridge.getHistoricalData({
  period: 'DAY',
  dataStreams: [
    { index: 0, sourceType: 'AVG' },   // 0-based index
    { index: 1, sourceType: 'MIN' },
  ]
})
  .then(({ streams }) => {
    streams.forEach(stream => {
      console.log(`Stream index ${stream.index}, granularity: ${stream.granularity ?? 'RAW_DATA'}`);  // granularity is null for RAW_DATA
      stream.values.forEach(({ x, y }) => {
        console.log(`  ${new Date(x).toISOString()} → ${y}`);
      });
    });
  })
  .catch(err => bridge.log('History error: ' + err));

// Raw data (no aggregation)
bridge.getHistoricalData({
  period: 'ONE_HOUR',
  dataStreams: [{ index: 1, sourceType: 'RAW_DATA' }]
}).then(({ streams }) => renderChart(streams));

// Raw data pagination — skip the first 500 points to fetch the next batch
bridge.getHistoricalData({
  period: 'ONE_HOUR',
  offset: 500,
  dataStreams: [{ index: 1, sourceType: 'RAW_DATA' }]
}).then(({ streams }) => appendChart(streams));

// Custom date range
const from = Date.now() - 7 * 24 * 60 * 60 * 1000; // 7 days ago
const to   = Date.now();
bridge.getHistoricalData({
  period: 'CUSTOM',
  from,
  to,
  dataStreams: [{ index: 1, sourceType: 'AVG' }]
})
  .then(({ streams }) => renderChart(streams))
  .catch(err => bridge.log('History error: ' + err));
```

**RANGE\_PICKER period**

`RANGE_PICKER` is a special period that delegates range selection to the **native date-range picker UI** provided by the host app rather than using a fixed window or explicit timestamps. It is only available on platforms where `bridge.isRangePickerSupported()` returns `true`.

**How it works (subscription model):**

1. **Initial call** — `getHistoricalData({ period: 'RANGE_PICKER' })` registers the widget as a subscriber and resolves with the data for whatever range the picker currently shows.
2. **Automatic updates** — from that point on, whenever the user moves the range picker, the platform pushes a fresh `HistoricalDataMap` directly to the `onHistoricalDataUpdated` callback registered via `setCallbacks`. These are **not** new Promise resolutions — they arrive asynchronously outside the Promise chain.

```js
// 1. Register the onHistoricalDataUpdated callback first
bridge.setCallbacks({
  onHistoricalDataUpdated({ streams }) {
    // Called automatically on every range picker change — NOT a Promise resolution.
    // streams: [{ index, granularity, values: [{ x, y }, ...] }]
    //   granularity is null when sourceType was RAW_DATA
    renderChart(streams);
  }
});

// 2. Make the explicit initial request — this registers the subscription
//    and resolves with the data for the currently selected range.
if (bridge.isRangePickerSupported()) {
  bridge.getHistoricalData({ period: 'RANGE_PICKER' })
    .then(({ streams }) => renderChart(streams))
    .catch(err => bridge.log('RANGE_PICKER error: ' + err));
} else {
  // Fall back to a fixed period or custom date inputs
  bridge.getHistoricalData({ period: 'DAY', dataStreams: [{ index: 1, sourceType: 'AVG' }] })
    .then(({ streams }) => renderChart(streams));
}
```

> **Note:** Register `onHistoricalDataUpdated` in `setCallbacks` **before** calling `getHistoricalData({ period: 'RANGE_PICKER' })` to avoid missing the first automatic push that may arrive immediately after subscription.

> **Note:** `getHistoricalData` times out after after 30 seconds on web (see above).

***

#### Logging

```js
bridge.log('my message')
bridge.setLogging(false)   // silence all bridge.log() calls
```

Messages are forwarded to the Blynk platform logger.

***

### CSS Custom Properties & Theming

Define all theme-sensitive values as CSS custom properties in `:root` with sensible defaults; override them from `getTheme()` at runtime:

```css
:root {
  /* — updated by getTheme() — */
  --bg:             #f7f7f8;
  --text:           #111114;
  --accent:         #22c55e;
  --accent-ghost:   rgba(34, 197, 94, 0.14);
  --color-online:   #22c55e;
  --color-offline:  #ef4444;

  /* — static — */
  --surface:        #ffffff;
  --text-muted:     #74747a;
  --border:         #e5e5ea;
  --radius:         10px;
}

@media (prefers-color-scheme: dark) {
  :root {
    --bg:            #0f0f11;
    --text:          #f4f4f5;
    --surface:       #18181b;
    --text-muted:    #8a8a92;
    --border:        #2a2a2f;
  }
}
```

The `@media (prefers-color-scheme: dark)` block serves as a fallback for the editor/browser. Inside the Blynk WebView `getTheme()` returns colors already matched to the current Blynk theme (which may differ from the OS preference), so always call `getTheme()` and apply its values.

***

### Responsive Layout with Container Queries

The WebView uses a fixed pixel canvas, but the widget tile can be any size. Use CSS Container Queries to adapt:

```css
.stage {
  container-type: size;
  container-name: widget;
  height: 100%;
  width: 100%;
  display: flex;
}

/* compact tile */
@container widget (max-width: 220px) {
  .widget { padding: 8px; font-size: 11px; }
}

/* wide/tall tile */
@container widget (min-width: 420px) and (min-height: 320px) {
  .widget { padding: 16px; gap: 14px; }
}
```

Use `clamp()` for fluid type:

```css
font-size: clamp(12px, 3cqmin, 15px);
```

Container query units (`cqw`, `cqh`, `cqmin`, `cqmax`) are fully supported in Blynk WebViews.

***

### Initialization Flow

The recommended boot sequence:

```js
async function init() {
  // 1. Apply theme first so there's no flash of wrong colors
  const theme = await bridge.getTheme().catch(() => null);
  if (theme) applyTheme(theme);

  // 2. Fetch current datastream values
  let values = [];
  try { values = await bridge.getValues(); } catch (_) {}

  // 3. Show "not configured" state when no datastreams are assigned
  if (!Array.isArray(values) || values.length === 0) {
    showNotConfigured();
    return;
  }

  // 4. Build UI, populate initial values
  buildUI(values.length);
  values.forEach((v, i) => applyValue(i, v));

  // 5. Load device info badge
  const info = await bridge.getDeviceInfo().catch(() => null);
  if (info) showDeviceBadge(info);
}

// 6. React to live pushes and errors
bridge.setCallbacks({
  onValueUpdated: ({ index, value, ...rest }) => applyValue(index, { value, ...rest }),
  onError: (message) => showErrorBanner(message)
});
```

> **Important:** All bridge calls return a `Promise`. Always chain `.catch()` on every call to handle the no-bridge and timeout cases.

***

### Complete Annotated Example

The built-in sample HTML is a production-quality example that demonstrates all of the above patterns:

* Four input fields, dynamically built from `getValues()` count
* `buildFields(n)` / `showNotConfigured()` state management
* `initTheme()` → applies brand/bg/text/online/offline colors
* `initDeviceInfo()` → shows device name + status dot badge
* Real-time updates via `bridge.setCallbacks({ onValueUpdated, onError })`
* Numeric validation, decimal formatting, dirty-state tracking
* Send button with animated confirmation dot
* Container-query responsive layout + `clamp()` fluid typography
* Full CSS custom property system with dark-mode fallbacks

***

### Tips & Gotchas

| Topic                                                         | Guidance                                                                                                                                                                                                                                                                                                                                                                    |
| ------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **`isExternalRequestsAllowed()`**                             | Returns `false` on Blynk Console (Web). Always check this before calling `fetch()` and handle rejections — CORS may still block individual requests.                                                                                                                                                                                                                        |
| **No external scripts in production**                         | Fonts and icon libraries loaded from CDN add latency. Bundle assets inline or use system fonts when file size matters.                                                                                                                                                                                                                                                      |
| **`getValue` index is 0-based**                               | `bridge.getValue(0)` reads the first assigned datastream, `bridge.getValue(1)` the second, etc. On Web, an index that isn't configured on the widget rejects with `` `Datastream index ${index} is not configured` `` (not an `index_out_of_bounds`-style message); a missing index rejects with `'getValue() has no index'`.                                               |
| **`getValues()` returns `[]` when not configured**            | Always check`values.length === 0` and show a "not configured" state.                                                                                                                                                                                                                                                                                                        |
| **`getValue`/`getValues` always return the full field set**   | `min`, `max`, `unit`, `suffix`, `decimalFormat`, `mappings`, `enumFallbackValue`, etc. are always present, defaulting to `null`/`''`/`[]` when not applicable to the stream's `type`. Don't rely on field _presence_ to detect type — check the `type` field itself.                                                                                                        |
| **`lastUpdated` and `color` fields**                          | Every`ValueObject` (from `getValue`, `getValues`, and `onValueUpdated`) also carries `lastUpdated` (Unix ms timestamp of the last push, or `null`) and `color` (the datastream's configured accent color, or `''`) — easy to miss since they weren't part of earlier examples.                                                                                              |
| **Color values from `getTheme()`**                            | Color fields are CSS hex color strings already resolved for the current light/dark theme.                                                                                                                                                                                                                                                                                   |
| **Font values from `getTheme()`**                             | `primaryFont`, `secondaryFont`, `buttonsFont`, `widgetValuesFont` are \`string                                                                                                                                                                                                                                                                                              |
| **Custom theme fonts just work**                              | Font names from`getTheme()` (e.g. an org's branded font) render correctly in your widget automatically — no extra setup needed.                                                                                                                                                                                                                                             |
| **`onThemeUpdated` callback**                                 | Register it via`setCallbacks({ onThemeUpdated })` to react live when the user flips light/dark mode or an org's branding changes, without a page reload. Not covered by `onValueUpdated`/`onError` alone.                                                                                                                                                                   |
| **`getDeviceInfo()`/`getTheme()` do not resolve `null`**      | Both**reject** (bridge unavailable, or a 10-second timeout) instead of ever resolving to a bare `null`. When there's no device linked, `getDeviceInfo()` still resolves — just with `id`/`orgId`/`lastReportedAt` as `null` and `name`/`status` as `''`. Guard on `info.id`, not on `info` itself.                                                                          |
| **`getDeviceInfo()` has a flat `status` field**               | `status` is a plain string (`'ONLINE'`, `'OFFLINE'`, a custom value, or `''` when unset) — not a nested object.                                                                                                                                                                                                                                                             |
| **`value` field is always a string**                          | Even for`INT` and `DOUBLE` streams, `value` is returned as a string. Parse it with `parseFloat()` / `parseInt()` before arithmetic.                                                                                                                                                                                                                                         |
| **ENUM `value` is an index string**                           | For`type === 'ENUM'` streams, `value` holds the numeric index of the selected option (e.g. `"1"`), not the label. Resolve it via `mappings[parseInt(v.value)]`. Always guard with `v.mappings?.[idx] ?? v.enumFallbackValue ?? v.value` in case the index is out of range.                                                                                                  |
| **`suffix`/`unit`/`decimalFormat` are always present**        | These fields are always in the object, defaulting to`''` when not set — check for an empty string, not for the field's existence.                                                                                                                                                                                                                                           |
| **`sendError(message)`**                                      | Displays an error toast in the Dashboard. No-op when`isOnErrorEnabled` is `false`, when `message` is empty, or when the bridge is unavailable.                                                                                                                                                                                                                              |
| **`onError` callback**                                        | Registered via`setCallbacks({ onError })`. Fired for timeouts, server errors, and misconfigured-index errors from `getValue`/`sendValue`/`getHistoricalData`. Only invoked when `isOnErrorEnabled` is `true`.                                                                                                                                                               |
| **`setOnErrorEnabled(false)`**                                | Suppresses both`sendError()` and the `onError` callback. Useful during init or when you want to handle errors silently without surfacing them to the user.                                                                                                                                                                                                                  |
| **`getHistoricalData` period is required**                    | `period` must be provided and must be one of the exact supported strings. Passing an unrecognised value (or omitting `period`) rejects immediately with a client-side error before any request is sent.                                                                                                                                                                     |
| **`getHistoricalData`** **`dataStreams` is required**         | A non-array`dataStreams` rejects with `"'dataStreams' must be an array"`. Each entry must supply a numeric `index` and a valid `sourceType`, or the specific `dataStreams[N]...` message is thrown.                                                                                                                                                                         |
| **`getHistoricalData` out-of-range `dataStreams[].index`**    | Unlike`getValue`/`sendValue`, an out-of-range index here doesn't error per-entry — it's just missing from the response. If none of the requested indexes are valid, the call rejects with `'No valid datastream indexes'`. See "Historical Data" above.                                                                                                                     |
| **`getHistoricalData` CUSTOM range**                          | Both`from` and `to` must be finite millisecond timestamps with `from ≤ to` and `to - from ≤ 365 days`. The Promise rejects immediately otherwise — no request is sent.                                                                                                                                                                                                      |
| **`getHistoricalData`** **`offset` for RAW\_DATA pagination** | `offset` skips N data points from the beginning of the result. Only meaningful with `sourceType: 'RAW_DATA'`. Paginate by keeping the same `period`/`from`/`to` and incrementing `offset` by the number of points received in each batch. Must be a non-negative integer; omit or pass `0` for the first batch.                                                             |
| **`getHistoricalData` timeout on Web**                        | The Web bridge enforces its own 30-second client-side timeout regardless of any backend timeout — rejects with`'Historical data request timeout (30s)'`. Plan your UI for a loading / timeout state.                                                                                                                                                                        |
| **`isRangePickerSupported()`**                                | Returns`true` on Web (the Dashboard's global time-range picker).                                                                                                                                                                                                                                                                                                            |
| **`RANGE_PICKER` subscription order**                         | Register`onHistoricalDataUpdated` via `setCallbacks` **before** calling `getHistoricalData({ period: 'RANGE_PICKER' })`. The first push may arrive immediately after subscription and would be missed otherwise.                                                                                                                                                            |
| **`onHistoricalDataUpdated` is not a Promise**                | It is a callback invoked by the platform on each range change. Do not`await` it — handle it only inside `setCallbacks`.                                                                                                                                                                                                                                                     |
| **`overscroll-behavior: none`**                               | Always set this on`html, body` to prevent the WebView from hijacking swipe gestures in the dashboard scroll.                                                                                                                                                                                                                                                                |
| **`touch-action: manipulation`**                              | Eliminates the 300 ms tap delay without disabling pinch-zoom declarations.                                                                                                                                                                                                                                                                                                  |
| **`-webkit-user-select: none`**                               | Prevents accidental text selection when the user is trying to scroll the dashboard.                                                                                                                                                                                                                                                                                         |
| **No `innerHTML` with user data**                             | Never insert untrusted strings via`innerHTML`. Use `textContent` / `setAttribute` / DOM APIs for values coming from the bridge.                                                                                                                                                                                                                                             |
| **`window.blynkWidgetUpdate`**                                | Blynk calls this global directly. Do not delete or replace it after`BlynkBridge` is constructed.                                                                                                                                                                                                                                                                            |
| **Preview / editor mode**                                     | When`bridge.isBridgeAvailable()` is `false`, show `MAX_INPUTS` fields with placeholder content so the widget looks meaningful in the editor.                                                                                                                                                                                                                                |
| **Per-plan limit on HTML Widgets per template**               | Each plan allows only a limited number of HTML Widget instances per template (shown to users as\*"HTML Widget limit reached. Your plan allows \{{count\}} per template."\*). Once reached, the dashboard editor shows an "Upgrade" prompt and blocks adding more — this is a platform/billing constraint, not something your widget's JavaScript can detect or work around. |
