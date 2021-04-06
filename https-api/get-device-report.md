# Get Device Report



* ```text
  https://blynk.cloud/external/api/data/get?token={token}&period={PERIOD}&granularityType={TYPE}
     &sourceType={SOURCE_TYPE}&tzName={tzName}&format={FORMAT}&sendEvents=true&output=FILE
     &dataStreamId={id}
     &pin={pin}
  ```

  * `period` is `MONTH` by default, other possible values: `HOUR`, `DAY, WEEK, THREE_MONTHS`
  * `granularityType` is `RAW_DATA` by default (`RAW_DATA` is not supported for the `THREE_MONTHS` period),
     other possible values: `MINUTE, HOURLY, DAILY`
  * `sourceType` is `AVG` by default, other possible values: `MIN, MAX, SUM, COUNT`
  * `tzName` is `UTC` by default
  * `format` is `TS` by default, other possible values:
    * `ISO_US` "04/10/19 11:45:41 AM"
    * `ISO_SIMPLE` "2018-06-07 22:01:20"
  * `sendEvents` is `false` by default
  * `dataStreamId` or `pin` are optional parameters, which are used to get data for the specific pin
  * `output` is `FILE` by default, other possible value: `JSON`

**Output example:**

```text
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
            "ts": 1598011200,
            "value": 1.6100000000000003
        }
    ],

    "rows": 1,

    "rows_before_limit_at_least": 1
}
```

