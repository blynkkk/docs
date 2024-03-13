# Create New User

{% swagger method="post" path="/api/v1/organization/users/create" baseUrl="https://{server_address}" summary="Create Members (Users)" %}
{% swagger-description %}
This endpoint will first create new organization under "Clients organizations" and then create a new user as a member of previously created organization.
{% endswagger-description %}

{% swagger-parameter in="header" name="Authorization" type="Bearer {access_token}" required="true" %}

{% endswagger-parameter %}

{% swagger-parameter in="body" name="email" type="john@example.com" required="true" %}
New user's email
{% endswagger-parameter %}

{% swagger-parameter in="body" name="passwordHash" type="tk++TTJLCEKfWuhQyGAKCSRMop6wyIexGKylaknsUo8=" required="true" %}
New user's password. See [user password creation notes](create-new-user.md#user-password).
{% endswagger-parameter %}

{% swagger-parameter in="body" name="name" type="John Doe" required="true" %}
New user's name. May contain up to 50 symbols. Only letters, hyphens, spaces, dots and apostrophes are allowed.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="title" %}
New user's title. May contain up to 50 symbols. Only letters, hyphens and spaces are allowed.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="nickName" %}
New user's nickname. May contain up to 50 symbols. Only letters, digits, hyphens and spaces are allowed.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="phoneNumber" type="+3801234567" %}
New user's phone number. Should be prefixed with `+`.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="organizationName" type="My Organization" %}
New user's organization name. Should be from 3 to 100 symbols. Only letters, digits, dots, apostrophe, hyphens and spaces are allowed.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="timeZone" type="Europe/Kiev" %}
New user's timezone.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="address" %}
New user's address.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="address.fullAddress" %}
New user's full address. Should be up to 512 symbols.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="address.city" %}
New user's city. Should be up to 50 symbols.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="address.country" %}
New user's country. Should be up to 74 symbols.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="address.state" %}
New user's state. Should be up to 40 symbols.
{% endswagger-parameter %}

{% swagger-parameter in="body" name="address.zip" %}
New user's zip code. Should be up to 12 symbols.
{% endswagger-parameter %}

{% swagger-parameter in="header" name="Content-Type" type="application/json" required="true" %}

{% endswagger-parameter %}

{% swagger-response status="204: No Content" description="User created or already exists" %}

{% endswagger-response %}
{% endswagger %}

Request examples:

<pre class="language-bash"><code class="lang-bash"># curl command example:
$ curl -X POST -H "Content-Type: application/json" \
<strong>      -H "Authorization: Bearer {accessToken}" \
</strong>      -d '{"email":"test@example.com","passwordHash":"tk++TTJLCEKfWuhQyGAKCSRMop6wyIexGKylaknsUo8=","name":"Test user","address":{"city":"Kyiv","country":"Ukraine"}}' \
      https://fra1.blynk.cloud/api/v1/organization/users/create

$ curl -X POST -H "Content-Type: application/json" \
      -H "Authorization: Bearer eIdWHQqRfFmvP5LDDh-IGxPUzi7I27HthzCPAVmS" \
      -d '{"email":"test@example.com","passwordHash":"tk++TTJLCEKfWuhQyGAKCSRMop6wyIexGKylaknsUo8=","name":"Test user","address":{"city":"Kyiv","country":"Ukraine"}}' \
      https://fra1.blynk.cloud/api/v1/organization/users/create
</code></pre>

### User password

Blynk using SHA-256 algorithm to encrypt user's password. Blynk never accept plain password on server-side, so to specify user's password you have to correctly encrypt it on your side.

Steps to encrypt password:

1. Hash the email using SHA-256.
2. Concatenate this hash with the password.
3. Hash this concatenated string again using SHA-256.
4. Encode the final hash in Base64.

Here is example Java code to encrypt user's password:

```java
String userEmail = "john@example.com";
String userPassword = "mySuperSecretPassword";

byte[] salt = MessageDigest.getInstance("SHA-256")
        .digest(userEmail.toLowerCase().getBytes(StandardCharsets.UTF_8));

MessageDigest md = MessageDigest.getInstance("SHA-256");
md.update(userPassword.getBytes(StandardCharsets.UTF_8));        
byte[] byteData = md.digest(salt);
String sha256Password = Base64.getEncoder().encodeToString(byteData);
// Pass 'sha256Password' to Blynk
```

Example bash command to encrypt a user's password (please make sure you enter your email address in lowercase letters and use unix-like OS to execute this command):

<pre class="language-bash"><code class="lang-bash"><strong>$ (echo -n "mySuperSecretPassword"; echo -n "email@example.com" | openssl dgst -sha256 -binary) | openssl dgst -sha256 -binary | openssl base64
</strong></code></pre>
