# Get Device Report

{% api-method method="get" host="https://{server\_address}" path="/external/api/data/get?token={token}&period={PERIOD}&granularityType={TYPE}&sourceType={SOURCE\_TYPE}&tzName={tzName}&format={FORMAT}&output=FILE&pin={pin}" %}
{% api-method-summary %}

{% endapi-method-summary %}

{% api-method-description %}

{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="period" type="string" required=true %}
Is `MONTH` by default. Other possible options: `HOUR`, `DAY`, `WEEK`, `THREE_MONTHS`
{% endapi-method-parameter %}

{% api-method-parameter name="granularityType" type="string" required=false %}
Is `RAW_DATA` by default. \( `RAW_DATA` is not supported for the `THREE_MONTH` period! \). Other possible values: `MINUTE`, `HOURLY`, `DAILY`
{% endapi-method-parameter %}

{% api-method-parameter name="sourceType" type="string" required=false %}
Is `AVG` by default. Other possible values: `MIN`, `MAX`, `SUM`, `COUNT`
{% endapi-method-parameter %}

{% api-method-parameter name="tzName" type="string" required=false %}
Is `UTC` by defult. Please specify timezones accordingly to `java.time.ZoneId`
{% endapi-method-parameter %}

{% api-method-parameter name="format" type="string" required=false %}
Is TS by default. Other possible values:  
ISO\_US "04/10/19 11:45:41 AM"  
ISO\_SIMPLE "2018-06-07 22:01:20"
{% endapi-method-parameter %}

{% api-method-parameter name="sendEvents" type="string" required=false %}
Is false by default
{% endapi-method-parameter %}

{% api-method-parameter name="dataStreamId or pin" type="string" required=false %}
Are optional parameteres, which are used to get data for the specific pin
{% endapi-method-parameter %}

{% api-method-parameter name="output" type="string" required=false %}
Is FILE by default. Other possible value: JSON
{% endapi-method-parameter %}
{% endapi-method-path-parameters %}
{% endapi-method-request %}

{% api-method-response %}
{% api-method-response-example httpCode=200 %}
{% api-method-response-example-description %}
Success.
{% endapi-method-response-example-description %}

```text
{"link":"https://server_address/device_data_2592_2021-04-13T02-27-11.zip"}
```
{% endapi-method-response-example %}

{% api-method-response-example httpCode=400 %}
{% api-method-response-example-description %}
Could not find a device token  
or  
No device token was provided  
or  
Typo in parameter or it's value  
or  
Wrong pin format
{% endapi-method-response-example-description %}

```text
{"error":{"message":"Invalid token."}}

or

{"error":{"message":"No token provided."}}

or

{"error":{"message":"Request with incorrect parameters"}}

or

{"error":{"message":"Wrong pin format."}}
```
{% endapi-method-response-example %}

{% api-method-response-example httpCode=500 %}
{% api-method-response-example-description %}
Wrong constant is used in parameter \(specified in the end of the string\)  
or  
There is no data for specified pin or datastream
{% endapi-method-response-example-description %}

```text
{"error":{"message":"No enum constant cc.blynk.server.core.model.widgets.outputs.graph.Period.YEAR"}}

or

{"error":{"message":"No data"}}

or

{"error":{"message":"Wrong pin format."}}
```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}

## **Use case example:**

You live in Sydney and have garage door opener and want to get an exact time you departed today in one file. The accuracy you need is up to 1 minute and it should be in "YYYY-MM-DD HH:MM:SS" format.  
Garage door opener is Blynked and it uses Datastream with ID 20 and virtual pin 6 for open/close commands. Also you want to get the list of all the events occured during this period. So API request for this case looks like:

`https://blynk.cloud/external/api/data/get?token=HjKjfij84050fege&period=DAY&granularityType=MINUTE&sourceType=AVG&tzName=America/New_York&format=ISO_SIMPLE&sendEvents=true&output=FILE&dataStreamId=20`

**JSON Output example:**

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
            "ts": 2021-05-14 12:25:00,
            "value": 1.6100000000000003
        }
    ],

    "rows": 1,

    "rows_before_limit_at_least": 1
}
```

