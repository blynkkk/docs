---
description: How to get historical data from a single device for a specified time range
---

# Get Historical Data From Device

<mark style="color:blue;">`GET`</mark> `https://{server_address}/external/api/data/get?token={token}&period={PERIOD}&granularityType={TYPE}&sourceType={SOURCE_TYPE}&tzName={tzName}&format={FORMAT}&output=FILE&pin={pin}`

#### Path Parameters

| Name                | Type   | Description                                                                                                                               |
| ------------------- | ------ | ----------------------------------------------------------------------------------------------------------------------------------------- |
| period              | string | Is `MONTH` by default. Other possible options: `HOUR`, `DAY`, `WEEK`, `THREE_MONTHS`                                                      |
| granularityType     | string | Is `RAW_DATA` by default. ( `RAW_DATA` is not supported for the `THREE_MONTH` period). Other possible values: `MINUTE`, `HOURLY`, `DAILY` |
| sourceType          | string | Is `AVG` by default. Other possible values: `MIN`, `MAX`, `SUM`, `COUNT`                                                                  |
| tzName              | string | Is `UTC` by defult. Please specify timezones accordingly to `java.time.ZoneId`                                                            |
| format              | string | <p>Is TS by default. Other possible values:<br>ISO_US "04/10/19 11:45:41 AM"<br>ISO_SIMPLE "2018-06-07 22:01:20"</p>                      |
| sendEvents          | string | Is false by default                                                                                                                       |
| dataStreamId or pin | string | Are optional parameteres, which are used to get data for the specific pin                                                                 |
| output              | string | Is FILE by default. Other possible value: JSON                                                                                            |

{% tabs %}
{% tab title="200 Success." %}
```
{"link":"https://server_address/device_data_2592_2021-04-13T02-27-11.zip"}
```
{% endtab %}

{% tab title="400 Could not find a device token or No device token was providedorTypo in parameter or it's valueorWrong pin format" %}
```
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"No token provided."}}

or

{"error":{"message":"Request with incorrect parameters"}}

or

{"error":{"message":"Wrong pin format."}}
```
{% endtab %}

{% tab title="500 Wrong constant is used in parameter (specified in the end of the string)
or
There is no data for specified pin or datastream" %}
```
{"error":{"message":"No enum constant cc.blynk.server.core.model.widgets.outputs.graph.Period.YEAR"}}

or

{"error":{"message":"No data"}}

or

{"error":{"message":"Wrong pin format."}}
```
{% endtab %}
{% endtabs %}

## **Use case example:**

Let's say you live in Sydney, Australia and there is a garage door opener and want to get an exact time you departed today in one file. The accuracy you need is up to 1 minute and it should be in "YYYY-MM-DD HH:MM:SS" format. Your device uses Datastream with ID 20 and virtual pin 6 for open/close commands. Let's say you also need to get the list of all the Events that were recorded during this period.&#x20;

API call will look like this:&#x20;

`` https://blynk.cloud/external/api/data/get?token=HjKjfij84050fege&period=DAY&granularityType=MINUTE&sourceType=AVG&tzName=America/New_York&format=ISO_SIMPLE&sendEvents=true&output=FILE&dataStreamId=20` ``



**JSON Output example:**

```
{
    "meta":
    [
        {
            "name": "data_stream_name",
            "type": "String"
        },
        {
            "name": "ts",
            "type": "UInt32"
        },
        {
            "name": "value",
            "type": "Float64"
        }
    ],

    "data":
    [
        {
            "data_stream_name": "",
            "ts": 2021-05-14 12:25:00,
            "value": 1.6100000000000003
        }
    ],

    "rows": 1,

    "rows_before_limit_at_least": 1
}
```
