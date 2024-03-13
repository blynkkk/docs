# Invite User

{% swagger method="post" path="/api/v1/organization/users/register" baseUrl="https://{server_address}" summary="Register User" %}
{% swagger-description %}
This endpoint functions similarly to the [Create User](create-new-user.md) endpoint. However, instead of creating a user account directly, it sends an email to the user. The users must then follow the verification link in the email and enter their data personally.
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="email" type="john@example.com" required="true" %}
New user's email
{% endswagger-parameter %}

{% swagger-parameter in="body" name="locale" type="en_US" %}
New user's locale. The locale is consist of two-letter language code defined by ISO 639-1 (e.g., "en" for English) and a two-letter country code defined by ISO 3166-1 alpha-2 (e.g., "US" for the United States) separated by underscore.
{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" required="true" %}

{% endswagger-parameter %}

{% swagger-response status="204: No Content" description="Registration email sent" %}

{% endswagger-response %}
{% endswagger %}

Request examples:

<pre class="language-bash"><code class="lang-bash"># curl command example:
$ curl -X POST -H "Content-Type: application/json" \
<strong>      -H "Authorization: Bearer {accessToken}" \
</strong>      -d '{"email":"test@example.com","locale":"en_US"}' \
      https://fra1.blynk.cloud/api/v1/organization/users/register

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"email":"test@example.com","locale":"en_US"}' \
      https://fra1.blynk.cloud/api/v1/organization/users/register
</code></pre>
