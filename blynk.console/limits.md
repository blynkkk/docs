---
description: What are the limits to use Blynk platform features
---

# Limits

{% hint style="success" %}
If you are using [Business or Enterprise Plan](https://blynk.io/pricing/business-plan), the limits below can be increased. Contact your support engineer.
{% endhint %}



### HTTPS API Limits

Max request size: 2 MB (headers + request body)

Max number of file uploads (product/organization logos) per user per day: 0 Free / 50 PRO

Max number of **Export Data** calls (`/external/api/data/get`) per device per day (both UI and HTTPS API export): 10

Max number of the **Update** requests (`/external/api/update`) per device per day: 500,000



### Device Template Limits

These are limits that apply to a each device template:

<table><thead><tr><th width="325">Feature</th><th width="125" align="center">FREE</th><th align="center">PRO</th></tr></thead><tbody><tr><td><a href="templates/datastreams/">Datastreams</a></td><td align="center">20</td><td align="center">200</td></tr><tr><td>Events</td><td align="center">5</td><td align="center">100</td></tr><tr><td>Metadata fields</td><td align="center">5</td><td align="center">20</td></tr><tr><td>Additional device dashboard pages in Blynk.Console</td><td align="center">-</td><td align="center">3</td></tr><tr><td>Additional <a href="https://docs.blynk.io/en/blynk.apps/pages">pages</a> in Blynk.apps </td><td align="center">-</td><td align="center">20 pages total (among them max 7 device Info tabs, 1 welcome page)</td></tr><tr><td>Tabs in Tabs widget in Blynk.apps</td><td align="center">-</td><td align="center">20</td></tr></tbody></table>

```
Limitations
```

### Assets

| Feature                    | Details                         |
| -------------------------- | ------------------------------- |
| **Supported formats**      | `.png`, `.jpg`, `.jpeg`, `.ico` |
| **Max files per upload**   | 50 files                        |
| **Max file size**          | 5 MB per file                   |
| **Storage per template**   | 200 MB                          |
| **Max files per template** | 1,000 files                     |
| **Max file name length**   | 1,000 characters                |



### Organization Limits

These are limits that apply to any organization (that includes all it's sub-organizations):

<table><thead><tr><th width="342">Feature</th><th width="134" align="center">FREE</th><th align="center">PRO</th></tr></thead><tbody><tr><td>Templates</td><td align="center">10</td><td align="center">50</td></tr><tr><td>Devices</td><td align="center">10</td><td align="center">50, 200, or 500</td></tr><tr><td>Devices per template</td><td align="center">1</td><td align="center">Multiple</td></tr><tr><td>Device messages</td><td align="center">30,000</td><td align="center">Unlimited</td></tr><tr><td><a href="../concepts/automations.md">Automations</a> per sub-organization</td><td align="center">5</td><td align="center">50</td></tr><tr><td><a href="https://docs.blynk.io/en/concepts/automations#actions">Actions</a> per automation</td><td align="center">5</td><td align="center">50</td></tr><tr><td>Automation push/emails per hour</td><td align="center">20</td><td align="center">20</td></tr><tr><td>Users</td><td align="center">1</td><td align="center">50, 200, or 500</td></tr><tr><td>Sub-organizations</td><td align="center">-</td><td align="center">200</td></tr><tr><td>Levels of sub-organizations hierarchy</td><td align="center">-</td><td align="center">4</td></tr><tr><td>Blynk.Air shipments (campaigns)</td><td align="center">2</td><td align="center">25</td></tr><tr><td>Locations</td><td align="center">2</td><td align="center">50</td></tr><tr><td>Webhooks</td><td align="center">1</td><td align="center">100</td></tr><tr><td>Total file uploads (logos, etc.)</td><td align="center">0</td><td align="center">50</td></tr></tbody></table>



Max logo image size: 4096x2048 pixels

Report file expiration time: 45 days

Max user invites per day: 25 invites



### Tags Limits

Max number of tags per organization: 20

Max number of tags per device: 5

Max number of tags per user: 5



### Webhooks Limits

Max response size: 16 KB

Max URL length: 1024 chars

Max body size: 5 KB

Max number of Webhooks per organization: 1 for Free, 100 for PRO plan.

Limit rate: 10 request per minute per webhook



### Hardware

Max number of events per day per device (`Blynk.logEvent`): 100 events

Min interval between events of the same type: 1 second

Min interval between notification messages (push notifications/emails/SMS): 5 seconds

Max number of requests per device: 50 requests/second

Max number of data points per device per day you can import into the device: 10,000 points

Max length of the string value: 1024 bytes



## UI

The maximum number of real-time updates on the web/app can accept - 20 commands per second

