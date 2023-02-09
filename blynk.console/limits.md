---
description: What are the limits to use Blynk platform features
---

# Limits

{% hint style="success" %}
If you are using [Business Plan](https://blynk.io/pricing/business-plan), the limits below can be increased. Contact your support engineer.
{% endhint %}

###

### HTTPS API Limits

Max request size: 2 MB (headers + request body)

Max number of file uploads (product/organization logos, firmware for shipment, data import) per user per day: 25

Max number of **Export Data** calls (`/external/api/data/get`) per device per day (both UI and HTTPS API export): 10

Max number of the **Update** requests (`/external/api/update`) per device per day: 500,000





### Device Template Limits

These are limits that apply to a each device template:

|                                                 Feature                                                 | FREE | PLUS | PRO |
| :-----------------------------------------------------------------------------------------------------: | :--: | :--: | --- |
|                                  [Datastreams](templates/datastreams/)                                  |  30  |  80  | 200 |
|                                    Widgets per page in Blynk.Console                                    |  30  |  80  | 255 |
|                                      Widgets per page in Blynk.Apps                                     |  30  |  80  | 255 |
|                                                  Events                                                 |   5  |  10  | 50  |
|                                             Metadata fields                                             |  10  |  10  | 10  |
|                            Additional device dashboard pages in Blynk.Console                           |   0  |   1  | 3   |
|      Additional device dashboard [pages](https://docs.blynk.io/en/blynk.apps/pages) in Blynk.apps       |   0  |   1  | 10  |
| Additional [device info tabs](https://docs.blynk.io/en/blynk.apps/pages#device-info-tabs) in Blynk.apps |   0  |   1  | 5   |



### Organization Limits

These are limits that apply to any organization (that includes all it's sub-organizations):

|                                     Feature                                     | FREE |   PLUS   | PRO            |
| :-----------------------------------------------------------------------------: | :--: | :------: | -------------- |
|                                    Templates                                    |   3  |    10    | 50             |
|                                     Devices                                     |   2  | 10 or 20 | 40, 100 or 500 |
|          [Automations](../concepts/automations.md) per sub-organization         |   5  |    25    | 50             |
| [Actions](https://docs.blynk.io/en/concepts/automations#actions) per automation |   5  |    25    | 50             |
|                         Automation push/emails per hour                         |  20  |    20    | 20             |
|                                      Users                                      |   5  |    10    | 100            |
|                                Sub-organizations                                |   0  |     0    | 200            |
|                      Levels of sub-organizations hierarchy                      |   0  |     0    | 4              |
|                         Blynk.Air shipments (campaigns)                         |   2  |    10    | 25             |
|                                    Locations                                    |  50  |    50    | 50             |
|                                     Webhooks                                    |   1  |     5    | 20             |



Max logo image size: 4096x2048 pixels

Report file expiration time: 45 days

Max user invites per day: 25 invites



### Tags Limits

Max number of tags per organization: 25

Max number of tags per device: 5

Max number of tags per user: 5



### Webhooks Limits

Max response size: 16 KB

Max URL length: 1024 chars

Max body size: 5 KB

Max number of Webhooks per organization: 1 for Free, 5 for Plus, 20 for Pro plan

Limit rate: 1 request per minute per webhook



### Hardware

Max number of events per day per device (`Blynk.logEvent`): 100 events

Min interval between events of the same type: 1 second

Min interval between notification messages (push notifications/emails/SMS): 5 seconds

Max number of requests per device: 50 requests/second

Max number of data points per device per day you can import into the device: 10,000 points

Max length of the string value: 1024 bytes

























