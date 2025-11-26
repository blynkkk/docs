# Delete Organization

<mark style="color:$danger;">`DELETE`</mark> `https://{server_address}/api/v1/organization`

Delete the organization. You can't delete your own, root, "Clients" group, or "Partners" group organizations. Additionally, you can't delete an organization that has sub-organizations or devices.

#### Query Parameters

| Name  | Type | Description                                           |
| ----- | ---- | ----------------------------------------------------- |
| orgId | 1    | Organization's identifier. Should be a valid integer. |

#### Headers

| Name                                            | Type                   | Description |
| ----------------------------------------------- | ---------------------- | ----------- |
| Authorization<mark style="color:red;">\*</mark> | Bearer {access\_token} |             |

{% tabs %}
{% tab title="204: No Content" %}
Organization was successfully deleted
{% endtab %}

{% tab title="404: Not Found Organization is not found" %}
```json
{
    "error": {
        "message": "Organization with identifier 1 is not found or you don't have access to it."
    }
}
```
{% endtab %}
{% endtabs %}

Request examples:

```bash
# curl command example:
$ curl -X DELETE -H "Authorization: Bearer {accessToken}" https://fra1.blynk.cloud/api/v1/organization?orgId={orgId}
$ curl -X DELETE -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" https://fra1.blynk.cloud/api/v1/organization?orgId=1
```
