# Platform API

The Platform API provides comprehensive access to all features of the Blynk IoT Platform through a secure HTTPS API. It enables you to perform Create, Read, Update, and Delete (CRUD) operations on a wide range of entities. These entities include devices, users, organizations, automations, webhooks, tags, templates, and more, giving you extensive control and flexibility.

{% hint style="info" %}
Platform API is exclusively available to[ Enterprise Plan](https://blynk.io/iot-platform-for-business) clients. If you're interested in utilizing this API for your business needs, consider upgrading. If you are already an Enterprise Plan customer, please reach out to your Launch Support Engineer.&#x20;
{% endhint %}

### Authentication

The API uses OAuth2 for authentication. Obtain an access token via the `POST /oauth2/token` endpoint using your OAuth2 client credentials, then include it as a Bearer token in the `Authorization` header of every API request:

```
Authorization: Bearer {access_token}
```

See the [**Authentication**](/broken/pages/f8e96e44e05b776f5094809b107bb591bd994393) section for the available grant types and detailed usage.

### Rate Limiting

The API enforces rate limiting of **10,000 requests per minute** per organization. Exceeding this limit returns a `429 Too Many Requests` response.

### Pagination

List endpoints support pagination via `page` (0-indexed) and `size` (max 1000) query parameters.

### Parameter Passing

All resource identifiers (deviceId, organizationId, userId, templateId, etc.) are passed as **query parameters**.
