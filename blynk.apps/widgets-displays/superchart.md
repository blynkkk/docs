# SuperChart

Visualize live and historical data in a chart from one or more datastreams. Applications include sensor data and binary event logging. The widget can handle multiple datastreams, shows the Y axis values, and supports the chart types of line, step, area, bar and state.

Also, see the [Simple Chart widget](simple-chart.md) that supports data aggregation options of average and sum.



### Datastream

Select or create a datastream of [data type](https://docs.blynk.io/en/blynk.console/templates/datastreams/datastreams-common-settings/data-type) integer or double.



### Widget Controls

The widget has the following controls:

1. **Time Ranges**: tap to select a time range. These are configurable under the widget settings.
2. **Full Screen**: when enabled, the full screen icon will be displayed at the lower right of the widget. Tap to zoom the chart to the full screen.

### Widget Settings

The widget has extensive charting display options that are easily explored interactively with the preview. Chart types of line, step, area, bar, and binary are configurable for each datastream assigned.



### How to process widget with the hardware



#### Reading the widget value(s)

You can read the latest values from the datastreams assigned to the widget. For datastream V1 of data type double:

```cpp
BLYNK_WRITE(V1) {
// Called when the datastream V1 value changes

double pinValue = param.asDouble();
Serial.print(“V1: “);
Serial.println(pinValue, 3);

}
```

To get the latest datastream value assigned to V1:

```
https://{server_address}/external/api/get/?token={your 32 char token}&V1
```

To get the historical values assigned to datastream V1:

```
https://{server_address}/external/api/data/get/?token={your 32 char token}&period={PERIOD}&granularityType={TYPE}&sourceType={SOURCE_TYPE}&tzName={tzName}&format={FORMAT}&output=FILE&pin={pin}

https://{server_address}/external/api/data/get/?token={your 32 char token}&period=WEEK&granularityType=RAW_DATA&sourceType=MAX&tzName=America/New_York&format=ISO_SIMPLE&sendEvents=true&output=FILE&pin=V1
```

#### Changing the datastream value(s)

You can change the value of the datastream assigned to the widget with the hardware or HTTP API. The widget works best with historical data sent on a constant interval.

For a datastream V1 assigned the data type of double.

**Hardware:**

```cpp
Blynk.virtualWrite(V1, 3.14159);
```

**HTTP API:**

```
https://{server_address}/external/api/update/?token={your 32 char token}&V1=3.14159
```

{% hint style="danger" %}
Don't put **`Blynk.virtualWrite()`**&#x69;nto the **`void loop()`** as it can cause a flood of messages and your hardware will be disconnected. Send such updates only when necessary, use flags, or [timers](../../blynk.edgent-firmware-api/blynk-timer.md).
{% endhint %}



### Change Widget Properties

The widget does not support any properties.



### **Sync to the latest known state**&#x20;

You can update your hardware to the latest datastream value from Blynk.Cloud after your hardware went offline, and then came online again. Use `Blynk.syncVirtual()` to update a single virtual pin, or `Blynk.syncAll()` to update all virtual pins. See [State Syncing](../../blynk.edgent-firmware-api/state-syncing.md) for more details.

```cpp
BLYNK_CONNECTED() { 
  // Called when hardware is connected to Blynk.Cloud  

  // get the latest value for V1
  Blynk.syncVirtual(V1); 

  // Request Blynk server to re-send latest values for all pins
  Blynk.syncAll()
}
```
