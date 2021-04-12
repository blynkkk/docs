# Get Device Report

{% api-method method="get" host="https://{server\_address}" path="/external/api/data/get?token={token}&period={PERIOD}&granularityType={TYPE}&sourceType={SOURCE\_TYPE}&tzName={tzName}&format={FORMAT}&sendEvents=true&output=FILE&dataStreamId={id}&pin={pin}" %}
{% api-method-summary %}

{% endapi-method-summary %}

{% api-method-description %}

{% endapi-method-description %}

{% api-method-spec %}
{% api-method-request %}
{% api-method-path-parameters %}
{% api-method-parameter name="period" type="string" required=true %}
is `MONTH` by default. Other possible options: `HOUR`, `DAY`, `WEEK`, `THREE_MONTHS`
{% endapi-method-parameter %}

{% api-method-parameter name="granularityType" type="string" required=true %}
is `RAW_DATA` by default. \( `RAW_DATA` is not supported for the `THREE_MONTH` period! \). Other possible values: `MINUTE`, `HOURLY`, `DAILY`
{% endapi-method-parameter %}

{% api-method-parameter name="sourceType" type="string" required=true %}
is `AVG` by default. Other possible values: `MIN`, `MAX`, `SUM`, `COUNT`
{% endapi-method-parameter %}

{% api-method-parameter name="tzName" type="string" required=true %}
is `UTC` by defult
{% endapi-method-parameter %}

{% api-method-parameter name="format" type="string" required=true %}
is TS by default. Other possible values:   
ISO\_US "04/10/19 11:45:41 AM"  
ISO\_SIMPLE "2018-06-07 22:01:20"
{% endapi-method-parameter %}

{% api-method-parameter name="sendEvents" type="string" required=true %}
is false by default
{% endapi-method-parameter %}

{% api-method-parameter name="dataStreamId or pin" type="string" required=false %}
are optional parameteres, which are used to get data for the specific pin
{% endapi-method-parameter %}

{% api-method-parameter name="output" type="string" required=true %}
is FILE by default. Other posible value: JSON
{% endapi-method-parameter %}
{% endapi-method-path-parameters %}
{% endapi-method-request %}

{% api-method-response %}
{% api-method-response-example httpCode=200 %}
{% api-method-response-example-description %}

{% endapi-method-response-example-description %}

```
JSON
```
{% endapi-method-response-example %}
{% endapi-method-response %}
{% endapi-method-spec %}
{% endapi-method %}

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
			"ts": 1598011200,
			"value": 1.6100000000000003
		}
	],

	"rows": 1,

	"rows_before_limit_at_least": 1
}
```

